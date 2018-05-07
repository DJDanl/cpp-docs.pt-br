---
title: 'TN002: Formato de dados do objeto persistente | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.data
dev_langs:
- C++
helpviewer_keywords:
- VERSIONABLE_SCHEMA macro [MFC]
- persistent object data
- CArchive class [MFC], support for persistent data
- persistent C++ objects [MFC]
- TN002
ms.assetid: 553fe01d-c587-4c8d-a181-3244a15c2be9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ca145ff871e1c5ccff27bdebe473c6cb6f39073a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="tn002-persistent-object-data-format"></a>TN002: formato de dados do objeto persistente
Esta anotação descreve as rotinas MFC que oferecem suporte a objetos C++ persistentes e o formato de dados do objeto quando ele é armazenado em um arquivo. Isso se aplica apenas às classes com o [DECLARE_SERIAL](../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../mfc/reference/run-time-object-model-services.md#implement_serial) macros.  
  
## <a name="the-problem"></a>O problema  
 A implementação do MFC para dados persistentes armazena dados para vários objetos em uma única parte de contígua de um arquivo. O objeto `Serialize` método converte os dados do objeto em um formato binário compacto.  
  
 A implementação garante que todos os dados são salvas no mesmo formato, usando o [classe CArchive](../mfc/reference/carchive-class.md). Ele usa um `CArchive` objeto como um conversor. Esse objeto persiste desde o momento em que ele é criado até que você chame [CArchive::Close](../mfc/reference/carchive-class.md#close). Esse método pode ser chamado explicitamente pelo programador ou implicitamente, o destruidor quando o programa sai do escopo que contém o `CArchive`.  
  
 Esta anotação descreve a implementação do `CArchive` membros [CArchive::ReadObject](../mfc/reference/carchive-class.md#readobject) e [CArchive::WriteObject](../mfc/reference/carchive-class.md#writeobject). Você encontrará o código para essas funções em Arcobj.cpp e a implementação do principal para `CArchive` em Arccore.cpp. Código do usuário não pode ser chamado `ReadObject` e `WriteObject` diretamente. Em vez disso, esses objetos são usados por específicas de classe fortemente tipado inserção e extração de operadores que são geradas automaticamente pelo `DECLARE_SERIAL` e `IMPLEMENT_SERIAL` macros. O código a seguir mostra como `WriteObject` e `ReadObject` são implicitamente chamado:  
  
```  
class CMyObject : public CObject  
{  
    DECLARE_SERIAL(CMyObject) 
};  
 
IMPLEMENT_SERIAL(CMyObj, CObject, 1)  
 
// example usage (ar is a CArchive&)  
CMyObject* pObj;  
CArchive& ar;  
ar <<pObj;        // calls ar.WriteObject(pObj)  
ar>> pObj;        // calls ar.ReadObject(RUNTIME_CLASS(CObj))  
```  
  
## <a name="saving-objects-to-the-store-carchivewriteobject"></a>Salvando objetos para o armazenamento (CArchive::WriteObject)  
 O método `CArchive::WriteObject` grava os dados de cabeçalho que são usados para recriar o objeto. Esses dados consistem em duas partes: o tipo do objeto e o estado do objeto. Esse método também é responsável por manter a identidade do objeto que está sendo gravada, para que apenas uma única cópia é salvo, independentemente do número de ponteiros para o objeto (inclusive ponteiros circulares).  
  
 Salvar (inserir) e a restauração de objetos (autoextraível) depende de vários "constantes manifestos". Estes são valores que são armazenados em binário e fornecem informações importantes para o arquivamento (Observe que o prefixo "w" indica as quantidades de 16 bits):  
  
|Marca|Descrição|  
|---------|-----------------|  
|wNullTag|Usado para ponteiros de objeto nulo (0).|  
|wNewClassTag|Indica a descrição da classe que segue é nova para este contexto de arquivo (-1).|  
|wOldClassTag|Indica a classe do objeto que está sendo lido foi visto neste contexto (0x8000).|  
  
 Ao armazenar os objetos, o arquivamento mantém um [CMapPtrToPtr](../mfc/reference/cmapptrtoptr-class.md) (o `m_pStoreMap`) que é um mapeamento de um objeto armazenado em um identificador persistente de 32 bits (PID). Um PID é atribuído a cada objeto exclusivo e cada nome de classe exclusivo que é salvo no contexto do arquivo. Essas IDs são distribuídos em sequência, começando em 1. Esses PIDs não têm significado fora do escopo do arquivo e, em particular, não são deve ser confundido com números de registro ou outros itens de identidade.  
  
 No `CArchive` classe PIDs são de 32 bits, mas eles são gravados como 16 bits, a menos que são maiores do que 0x7FFE. PIDs grandes são gravados como 0x7FFF seguido o PID de 32 bits. Isso mantém a compatibilidade com projetos que foram criados em versões anteriores.  
  
 Quando é feita uma solicitação para salvar um objeto em um arquivo morto (geralmente usando o operador de inserção global), uma verificação é feita por um NULL [CObject](../mfc/reference/cobject-class.md) ponteiro. Se o ponteiro for NULL, o `wNullTag` são inseridos no fluxo de arquivo morto.  
  
 Se o ponteiro não for NULL e pode ser serializado (a classe é um `DECLARE_SERIAL` classe), o código verifica o `m_pStoreMap` para ver se o objeto já foi salvo. Em caso afirmativo, o código insere o PID de 32 bits associado a esse objeto no fluxo de arquivo morto.  
  
 Se o objeto não tiver sido salvo antes, há duas possibilidades a serem considerados: o objeto e o tipo exato (ou seja, classe) do objeto são novos para este contexto de arquivo ou o objeto é de um tipo exato já visto. Para determinar se o tipo foi observado, as consultas de código a `m_pStoreMap` para um [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) objeto corresponde a `CRuntimeClass` objeto associado ao objeto que está sendo salvo. Se houver uma correspondência, `WriteObject` insere uma marca que é o bit a bit `OR` de `wOldClassTag` e esse índice. Se o `CRuntimeClass` é novo para este contexto de arquivamento, `WriteObject` atribui um novo PID a classe e o insere no arquivo morto, precedido pelo `wNewClassTag` valor.  
  
 O descritor para essa classe é inserido no arquivo morto usando a `CRuntimeClass::Store` método. `CRuntimeClass::Store` Insere o número de esquema da classe (veja abaixo) e o nome de texto ASCII da classe. Observe que o uso do nome de texto ASCII não garante a exclusividade do arquivo em todos os aplicativos. Portanto, você deve marcar os arquivos de dados para evitar a corrupção. Após a inserção de informações de classe, o arquivo morto coloca o objeto de `m_pStoreMap` e, em seguida, chama o `Serialize` método para inserir dados de classe específica. Colocando o objeto para o `m_pStoreMap` antes de chamar `Serialize` impede que várias cópias do objeto que está sendo salvo no repositório.  
  
 Ao retornar para o chamador inicial (geralmente a raiz da rede de objetos), você deve chamar [CArchive::Close](../mfc/reference/carchive-class.md#close). Se você planeja realizar outras [CFile](../mfc/reference/cfile-class.md)operações, você deve chamar o `CArchive` método [liberar](../mfc/reference/carchive-class.md#flush) para evitar a corrupção do arquivo.  
  
> [!NOTE]
>  Essa implementação impõe um limite rígido de índices 0x3FFFFFFE por contexto de arquivamento. Esse número representa o número máximo de objetos exclusivos e classes que podem ser salvas em um único arquivo, mas um arquivo de disco único pode ter um número ilimitado de contextos de arquivamento.  
  
## <a name="loading-objects-from-the-store-carchivereadobject"></a>Carregando objetos do repositório (CArchive::ReadObject)  
 Carregar (extraindo) objetos usa o `CArchive::ReadObject` método e é o oposto de `WriteObject`. Assim como acontece com `WriteObject`, `ReadObject` não é chamado diretamente pelo código do usuário; código de usuário deve chamar o operador de extração de tipo seguro que chama `ReadObject` com esperado `CRuntimeClass`. Isso assegura a integridade do tipo da operação de extração.  
  
 Como o `WriteObject` implementação atribuído PIDs crescentes, começando com 1 (0 é predefinida que o objeto NULL), o `ReadObject` implementação pode usar uma matriz para manter o estado do contexto do arquivo morto. Quando um PID é lido a partir do repositório, o PID é maior do que o limite atual do `m_pLoadArray`, `ReadObject` sabe que segue um novo objeto (ou a descrição da classe).  
  
## <a name="schema-numbers"></a>Números de esquema  
 O número de esquema, que é atribuído à classe quando o `IMPLEMENT_SERIAL` método da classe for encontrada, é a "versão" a implementação da classe. O esquema refere-se a implementação da classe, não para o número de vezes que um determinado objeto tenha se tornado persistente (normalmente conhecido como a versão do objeto).  
  
 Se você pretende manter várias implementações diferentes da mesma classe ao longo do tempo, incrementando o esquema durante a revisão do objeto `Serialize` implementação do método permitirá que você escrever código que pode carregar objetos armazenados usando versões mais antigas do a implementação.  
  
 O `CArchive::ReadObject` método lançará um [CArchiveException](../mfc/reference/carchiveexception-class.md) quando encontrar um número de esquema no armazenamento persistente que difere do número de esquema da descrição da classe na memória. Não é fácil recuperar dessa exceção.  
  
 Você pode usar `VERSIONABLE_SCHEMA` combinado com (bit a bit `OR`) a versão de esquema para manter essa exceção de que está sendo gerada. Usando `VERSIONABLE_SCHEMA`, seu código pode tomar a ação apropriada seu `Serialize` função verificando o valor de retorno [CArchive::GetObjectSchema](../mfc/reference/carchive-class.md#getobjectschema).  
  
## <a name="calling-serialize-directly"></a>Chamando diretamente serializar  
 Em muitos casos, a sobrecarga do esquema de arquivo de objeto geral de `WriteObject` e `ReadObject` não é necessário. Esse é o caso comum de serializar os dados em um [CDocument](../mfc/reference/cdocument-class.md). Nesse caso, o `Serialize` método o `CDocument` é chamado diretamente, não com os operadores de extração e inserção. O conteúdo do documento por sua vez pode usar o esquema de arquivo de objeto mais geral.  
  
 Chamando `Serialize` diretamente tem as seguintes vantagens e desvantagens:  
  
-   Nenhum bytes adicionais são adicionados ao arquivo morto antes ou depois que o objeto é serializado. Isso não só torna os dados salvos menor, mas permite que você implemente `Serialize` rotinas que podem lidar com qualquer formatos de arquivo.  
  
-   O MFC é ajustado para que o `WriteObject` e `ReadObject` implementações e coleções relacionadas não serão vinculadas ao seu aplicativo, a menos que você precisa o esquema de arquivo de objeto mais geral para algum outro propósito.  
  
-   Seu código não precisa recuperar de números de esquema antigo. Isso faz com que o código de serialização do documento responsável por números de esquema de codificação, números de versão do formato de arquivo ou qualquer identificação de números que você use no início dos seus arquivos de dados.  
  
-   Qualquer objeto que é serializado com uma chamada direta para `Serialize` não devem usar `CArchive::GetObjectSchema` ou deve o identificador de um valor de retorno (UINT) -1 indicando que a versão era desconhecida.  
  
 Porque `Serialize` é chamado diretamente no documento, não é possível para os objetos de subgrupos do documento para arquivar as referências para o documento pai. Esses objetos devem ser fornecidos um ponteiro a seu documento contêiner explicitamente ou você deve usar [CArchive::MapObject](../mfc/reference/carchive-class.md#mapobject) função para mapear o `CDocument` ponteiro para um PID antes que essas backup ponteiros são arquivados.  
  
 Conforme observado anteriormente, você deve codificar a versão e informações de classe você mesmo quando você chamar `Serialize` diretamente, permitindo que você alterar o formato mais tarde e ainda manter a compatibilidade com os arquivos mais antigos. O `CArchive::SerializeClass` função pode ser chamada explicitamente antes de serializar diretamente um objeto ou antes de chamar uma classe base.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

