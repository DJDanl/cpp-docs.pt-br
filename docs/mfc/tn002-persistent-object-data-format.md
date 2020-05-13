---
title: 'TN002: formato de dados do objeto persistente'
ms.date: 11/04/2016
helpviewer_keywords:
- VERSIONABLE_SCHEMA macro [MFC]
- persistent object data
- CArchive class [MFC], support for persistent data
- persistent C++ objects [MFC]
- TN002
ms.assetid: 553fe01d-c587-4c8d-a181-3244a15c2be9
ms.openlocfilehash: f65a7b7afcf6bd832c9c23560bb29374038fae1b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370450"
---
# <a name="tn002-persistent-object-data-format"></a>TN002: formato de dados do objeto persistente

Esta nota descreve as rotinas de MFC que suportam objetos C++ persistentes e o formato dos dados do objeto quando ele é armazenado em um arquivo. Isso se aplica apenas às classes com as [macros DECLARE_SERIAL](../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL.](../mfc/reference/run-time-object-model-services.md#implement_serial)

## <a name="the-problem"></a>O problema

A implementação do MFC para dados persistentes armazena dados para muitos objetos em uma única parte contígua de um arquivo. O método `Serialize` do objeto traduz os dados do objeto em um formato binário compacto.

A implementação garante que todos os dados sejam salvos no mesmo formato usando a [Classe CArchive](../mfc/reference/carchive-class.md). Ele usa `CArchive` um objeto como tradutor. Esse objeto persiste desde o momento em que é criado até que você chame [CArchive:::Close](../mfc/reference/carchive-class.md#close). Este método pode ser chamado explicitamente pelo programador ou implicitamente pelo destruidor quando o programa `CArchive`sai do escopo que contém o .

Esta nota descreve a `CArchive` implementação dos membros [CArchive::ReadObject](../mfc/reference/carchive-class.md#readobject) e [CArchive::WriteObject](../mfc/reference/carchive-class.md#writeobject). Você encontrará o código para essas funções em Arcobj.cpp, e a implementação principal para `CArchive` em Arccore.cpp. O código do `ReadObject` `WriteObject` usuário não liga e diretamente. Em vez disso, esses objetos são usados por operadores de inserção e extração de tipo específicos de classe que são gerados automaticamente pelas macros DECLARE_SERIAL e IMPLEMENT_SERIAL. O código a `WriteObject` `ReadObject` seguir mostra como e são implicitamente chamados:

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

## <a name="saving-objects-to-the-store-carchivewriteobject"></a>Salvando objetos na loja (CArchive::WriteObject)

O `CArchive::WriteObject` método escreve dados de cabeçalho que são usados para reconstruir o objeto. Esses dados consistem em duas partes: o tipo do objeto e o estado do objeto. Este método também é responsável por manter a identidade do objeto sendo escrito, de modo que apenas uma única cópia seja salva, independentemente do número de ponteiros para esse objeto (incluindo ponteiros circulares).

Salvar (inserir) e restaurar (extrair) objetos depende de várias "constantes manifestas". Estes são valores armazenados em binário e fornecem informações importantes ao arquivo (note que o prefixo "w" indica quantidades de 16 bits):

|Marca|Descrição|
|---------|-----------------|
|wNullTag|Usado para ponteiros de objeto NULL (0).|
|wNewClassTag|Indica a descrição da classe a seguir é novo neste contexto de arquivo (-1).|
|wOldClassTag|Indica que a classe do objeto que está sendo lido foi vista neste contexto (0x8000).|

Ao armazenar objetos, o arquivo mantém um [CMapPtrToPtr](../mfc/reference/cmapptrtoptr-class.md) (o *m_pStoreMap*) que é um mapeamento de um objeto armazenado para um identificador persistente de 32 bits (PID). Um PID é atribuído a cada objeto único e a cada nome de classe único que é salvo no contexto do arquivo. Estes PIDs são distribuídos sequencialmente a partir de 1. Esses PIDs não têm significado fora do escopo do arquivo e, em particular, não devem ser confundidos com números de registro ou outros itens de identidade.

Na `CArchive` classe, os PIDs são de 32 bits, mas são escritos como 16 bits, a menos que sejam maiores que 0x7FFE. Os PIDs grandes são escritos como 0x7FFF seguidos pelo PID de 32 bits. Isso mantém a compatibilidade com projetos que foram criados em versões anteriores.

Quando uma solicitação é feita para salvar um objeto em um arquivo (geralmente usando o operador de inserção global), uma verificação é feita para um ponteiro NULL [CObject.](../mfc/reference/cobject-class.md) Se o ponteiro for NULO, o *wNullTag* será inserido no fluxo de arquivos.

Se o ponteiro não for NULO e puder `DECLARE_SERIAL` ser serializado (a classe é uma classe), o código verifica o *m_pStoreMap* para ver se o objeto já foi salvo. Se tiver, o código insere o PID de 32 bits associado a esse objeto no fluxo de arquivos.

Se o objeto não foi salvo antes, há duas possibilidades a considerar: tanto o objeto quanto o tipo exato (ou seja, classe) do objeto são novos neste contexto de arquivo, ou o objeto é de um tipo exato já visto. Para determinar se o tipo foi visto, o código consulta o *m_pStoreMap* `CRuntimeClass` para um objeto [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) que corresponde ao objeto associado ao objeto que está sendo salvo. Se houver uma `WriteObject` correspondência, insira uma tag `OR` que seja o bit-wise de *wOldClassTag* e este índice. Se `CRuntimeClass` o novo contexto de `WriteObject` arquivamento for novo, atribua um novo PID a essa classe e o insere no arquivo, precedido pelo valor *wNewClassTag.*

O descritor para esta classe é então inserido `CRuntimeClass::Store` no arquivo usando o método. `CRuntimeClass::Store`insere o número do esquema da classe (veja abaixo) e o nome de texto ASCII da classe. Observe que o uso do nome de texto ASCII não garante a exclusividade do arquivo entre aplicativos. Portanto, você deve marcar seus arquivos de dados para evitar a corrupção. Após a inserção das informações de classe, o arquivo `Serialize` coloca o objeto no *m_pStoreMap* e, em seguida, chama o método para inserir dados específicos da classe. Colocar o objeto *m_pStoreMap* no `Serialize` m_pStoreMap antes de chamar impede que várias cópias do objeto sejam salvas na loja.

Ao retornar ao chamador inicial (geralmente a raiz da rede de objetos), você deve chamar [CArchive:::Close](../mfc/reference/carchive-class.md#close). Se você planeja executar outras operações `CArchive` [cFile,](../mfc/reference/cfile-class.md)você deve chamar o método [Flush](../mfc/reference/carchive-class.md#flush) para evitar a corrupção do arquivo.

> [!NOTE]
> Esta implementação impõe um limite rígido de índices 0x3FFFFFFFfE por contexto de arquivo. Esse número representa o número máximo de objetos e classes únicos que podem ser salvos em um único arquivo, mas um único arquivo de disco pode ter um número ilimitado de contextos de arquivamento.

## <a name="loading-objects-from-the-store-carchivereadobject"></a>Carregando objetos da loja (CArchive::ReadObject)

Carregar (extrair) objetos `CArchive::ReadObject` usa o método `WriteObject`e é o inverso de . Como `WriteObject`acontece, `ReadObject` não é chamado diretamente pelo código do usuário; o código do usuário deve chamar `ReadObject` o operador `CRuntimeClass`de extração seguro de tipo que chama com o esperado . Isso garante a integridade do tipo da operação de extração.

Uma `WriteObject` vez que a implementação atribuída ao aumento de PIDs, `ReadObject` começando com 1 (0 é predefinido como objeto NULL), a implementação pode usar uma matriz para manter o estado do contexto do arquivo. Quando um PID é lido na loja, se o PID for `ReadObject` maior que o limite superior atual do *m_pLoadArray,* saiba que um novo objeto (ou descrição da classe) segue.

## <a name="schema-numbers"></a>Números de Esquemas

O número do esquema, que é atribuído `IMPLEMENT_SERIAL` à classe quando o método da classe é encontrado, é a "versão" da implementação da classe. O esquema refere-se à implementação da classe, não ao número de vezes que um determinado objeto foi feito persistente (geralmente referido como a versão do objeto).

Se você pretende manter várias implementações diferentes da mesma classe ao longo do tempo, incrementar o esquema à medida que você revisar a implementação do método do `Serialize` objeto permitirá que você escreva código saqueado usando versões mais antigas da implementação.

O `CArchive::ReadObject` método lançará um [CArchiveException](../mfc/reference/carchiveexception-class.md) quando encontrar um número de esquema na loja persistente que difere do número de esquema da descrição da classe na memória. Não é fácil recuperar-se dessa exceção.

Você pode `VERSIONABLE_SCHEMA` usar combinado com (bitwise **OR**) sua versão de esquema para evitar que essa exceção seja lançada. Ao `VERSIONABLE_SCHEMA`usar, seu código pode tomar `Serialize` as medidas apropriadas em sua função verificando o valor de retorno de [CArchive::GetObjectSchema](../mfc/reference/carchive-class.md#getobjectschema).

## <a name="calling-serialize-directly"></a>Chamando Serialize diretamente

Em muitos casos, a sobrecarga do `WriteObject` `ReadObject` esquema de arquivamento de objetos gerais e não é necessária. Este é o caso comum de serializar os dados em um [CDocument](../mfc/reference/cdocument-class.md). Neste caso, `Serialize` o método `CDocument` do é chamado diretamente, não com os operadores de extrato ou inserção. O conteúdo do documento, por sua vez, pode usar o esquema de arquivamento de objetos mais geral.

Ligar `Serialize` diretamente tem as seguintes vantagens e desvantagens:

- Nenhum byteextra é adicionado ao arquivo antes ou depois de o objeto ser serializado. Isso não só torna os dados salvos `Serialize` menores, mas permite que você implemente rotinas que possam lidar com qualquer formato de arquivo.

- O MFC está sintonizado para que as `WriteObject` implementações e `ReadObject` coleções relacionadas não sejam vinculadas ao seu aplicativo, a menos que você precise do esquema de arquivamento de objetos mais geral para algum outro propósito.

- Seu código não precisa se recuperar de números antigos de esquema. Isso torna o código de serialização do documento responsável pela codificação de números de esquemas, números de versão do formato de arquivo ou quaisquer números de identificação que você usa no início de seus arquivos de dados.

- Qualquer objeto serializado com uma `Serialize` chamada direta `CArchive::GetObjectSchema` não deve ser usado ou deve lidar com um valor de retorno de (UINT)-1 indicando que a versão era desconhecida.

Como `Serialize` é chamado diretamente em seu documento, geralmente não é possível que os subobjetos do documento arquivem referências ao documento pai. Esses objetos devem receber um ponteiro no documento do contêiner explicitamente ou você `CDocument` deve usar a função [CArchive::MapObject](../mfc/reference/carchive-class.md#mapobject) para mapear o ponteiro para um PID antes que esses ponteiros traseiros sejam arquivados.

Como observado anteriormente, você deve codificar as `Serialize` informações de versão e classe você mesmo quando você ligar diretamente, permitindo que você altere o formato mais tarde e ainda mantenha a compatibilidade retrógrada com arquivos mais antigos. A `CArchive::SerializeClass` função pode ser chamada explicitamente antes de serializar diretamente um objeto ou antes de chamar uma classe base.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
