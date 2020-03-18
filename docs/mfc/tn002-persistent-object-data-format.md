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
ms.openlocfilehash: 1880d5d43055966dea8ab16dc4f26bd4e4602ec5
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447134"
---
# <a name="tn002-persistent-object-data-format"></a>TN002: formato de dados do objeto persistente

Esta observação descreve as rotinas do MFC que C++ dão suporte a objetos persistentes e o formato dos dados do objeto quando eles são armazenados em um arquivo. Isso se aplica somente a classes com as macros [DECLARE_SERIAL](../mfc/reference/run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](../mfc/reference/run-time-object-model-services.md#implement_serial) .

## <a name="the-problem"></a>O problema

A implementação do MFC para dados persistentes armazena dados para muitos objetos em uma única parte contígua de um arquivo. O método de `Serialize` do objeto traduz os dados do objeto em um formato binário compacto.

A implementação garante que todos os dados sejam salvos no mesmo formato usando a [classe CArchive](../mfc/reference/carchive-class.md). Ele usa um objeto `CArchive` como um tradutor. Esse objeto persiste desde o momento em que é criado até que você chame [CArchive:: Close](../mfc/reference/carchive-class.md#close). Esse método pode ser chamado explicitamente pelo programador ou implicitamente pelo destruidor quando o programa sai do escopo que contém o `CArchive`.

Esta observação descreve a implementação do `CArchive` Members [CArchive:: ReadObject](../mfc/reference/carchive-class.md#readobject) e [CArchive:: WriteObject](../mfc/reference/carchive-class.md#writeobject). Você encontrará o código para essas funções em Arcobj. cpp e a implementação principal para `CArchive` em Arccore. cpp. O código do usuário não chama `ReadObject` e `WriteObject` diretamente. Em vez disso, esses objetos são usados por operadores de extração e inserção com segurança de tipo específico de classe que são gerados automaticamente pelo DECLARE_SERIAL e IMPLEMENT_SERIAL macros. O código a seguir mostra como `WriteObject` e `ReadObject` são chamados implicitamente:

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

## <a name="saving-objects-to-the-store-carchivewriteobject"></a>Salvando objetos no repositório (CArchive:: WriteObject)

O método `CArchive::WriteObject` grava dados de cabeçalho que são usados para reconstruir o objeto. Esses dados consistem em duas partes: o tipo do objeto e o estado do objeto. Esse método também é responsável por manter a identidade do objeto que está sendo gravado, para que apenas uma única cópia seja salva, independentemente do número de ponteiros para esse objeto (incluindo ponteiros circulares).

Salvar (inserir) e restaurar (extrair) objetos depende de várias "constantes de manifesto". Esses são os valores que são armazenados em binário e fornecem informações importantes para o arquivo morto (Observe que o prefixo "w" indica quantidades de 16 bits):

|Marca|Descrição|
|---------|-----------------|
|wNullTag|Usado para ponteiros de objeto nulo (0).|
|wNewClassTag|Indica a descrição da classe a seguir é nova neste contexto de arquivo (-1).|
|wOldClassTag|Indica que a classe do objeto que está sendo lido foi vista neste contexto (0x8000).|

Ao armazenar objetos, o arquivo mantém um [CMapPtrToPtr](../mfc/reference/cmapptrtoptr-class.md) (o *m_pStoreMap*), que é um mapeamento de um objeto armazenado para um identificador persistente de 32 bits (PID). Um PID é atribuído a cada objeto exclusivo e a cada nome de classe exclusivo que é salvo no contexto do arquivo morto. Esses PIDs são distribuídos sequencialmente a partir de 1. Esses PIDs não têm significado fora do escopo do arquivo e, em particular, não devem ser confundidos com números de registro ou outros itens de identidade.

Na classe `CArchive`, os PIDs são de 32 bits, mas são gravados como 16 bits, a menos que sejam maiores que 0x7FFE. PIDs grandes são gravados como 0x7FFF seguidos pelo PID de 32 bits. Isso mantém a compatibilidade com projetos que foram criados em versões anteriores.

Quando é feita uma solicitação para salvar um objeto em um arquivo morto (geralmente usando o operador de inserção global), é feita uma verificação para um ponteiro [COBJECT](../mfc/reference/cobject-class.md) nulo. Se o ponteiro for nulo, o *wNullTag* será inserido no fluxo de arquivo morto.

Se o ponteiro não for nulo e puder ser serializado (a classe é uma classe `DECLARE_SERIAL`), o código verificará a *m_pStoreMap* para ver se o objeto já foi salvo. Se tiver, o código inserirá o PID de 32 bits associado a esse objeto no fluxo de arquivo morto.

Se o objeto não tiver sido salvo antes, há duas possibilidades a serem consideradas: tanto o objeto quanto o tipo exato (ou seja, a classe) do objeto são novos nesse contexto de arquivo ou o objeto é de um tipo exato já visto. Para determinar se o tipo foi visto, o código consulta o *m_pStoreMap* de um objeto [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) que corresponde ao objeto `CRuntimeClass` associado ao objeto que está sendo salvo. Se houver uma correspondência, `WriteObject` inserirá uma marca que seja o `OR` de bits de *wOldClassTag* e esse índice. Se o `CRuntimeClass` for novo nesse contexto de arquivo, `WriteObject` atribuirá um novo PID a essa classe e o inserirá no arquivo morto, precedido pelo valor *wNewClassTag* .

Em seguida, o descritor dessa classe é inserido no arquivo morto usando o método `CRuntimeClass::Store`. `CRuntimeClass::Store` insere o número de esquema da classe (veja abaixo) e o nome de texto ASCII da classe. Observe que o uso do nome de texto ASCII não garante a exclusividade do arquivo morto entre aplicativos. Portanto, você deve marcar seus arquivos de dados para evitar danos. Após a inserção das informações de classe, o arquivo morto coloca o objeto na *m_pStoreMap* e, em seguida, chama o método `Serialize` para inserir dados específicos da classe. Colocar o objeto na *m_pStoreMap* antes de chamar `Serialize` impede que várias cópias do objeto sejam salvas no repositório.

Ao retornar ao chamador inicial (geralmente a raiz da rede de objetos), você deve chamar [CArchive:: Close](../mfc/reference/carchive-class.md#close). Se você planeja [executar outras operações](../mfc/reference/cfile-class.md)de arquivo de refazer, você deve chamar a `CArchive` do método de [liberação](../mfc/reference/carchive-class.md#flush) para evitar a corrupção do arquivo morto.

> [!NOTE]
>  Essa implementação impõe um limite rígido de índices de 0x3FFFFFFE por contexto de arquivo. Esse número representa o número máximo de objetos e classes exclusivos que podem ser salvos em um único arquivo morto, mas um único arquivo de disco pode ter um número ilimitado de contextos de arquivo.

## <a name="loading-objects-from-the-store-carchivereadobject"></a>Carregando objetos do repositório (CArchive:: ReadObject)

Carregar (extrair) objetos usa o método `CArchive::ReadObject` e é o converso de `WriteObject`. Assim como ocorre com `WriteObject`, `ReadObject` não é chamado diretamente pelo código do usuário; o código do usuário deve chamar o operador de extração de tipo seguro que chama `ReadObject` com o `CRuntimeClass`esperado. Isso garante a integridade do tipo da operação de extração.

Uma vez que a implementação de `WriteObject` atribuída ao aumento de PIDs, a partir de 1 (0 é predefinida como o objeto nulo), a implementação de `ReadObject` pode usar uma matriz para manter o estado do contexto de arquivo. Quando um PID é lido do repositório, se o PID for maior que o limite superior atual do *m_pLoadArray*, `ReadObject` saberá que um novo objeto (ou descrição de classe) segue.

## <a name="schema-numbers"></a>Números de esquema

O número do esquema, que é atribuído à classe quando o método de `IMPLEMENT_SERIAL` da classe é encontrado, é a "versão" da implementação da classe. O esquema refere-se à implementação da classe, não ao número de vezes que um determinado objeto foi tornado persistente (geralmente conhecido como a versão do objeto).

Se você pretende manter várias implementações diferentes da mesma classe ao longo do tempo, incrementar o esquema ao revisar a implementação do método de `Serialize` do seu objeto permitirá que você escreva um código que possa carregar objetos armazenados usando versões mais antigas da implementação.

O método `CArchive::ReadObject` gerará um [CArchiveException](../mfc/reference/carchiveexception-class.md) quando encontrar um número de esquema no repositório persistente que difere do número de esquema da descrição da classe na memória. Não é fácil recuperar a partir dessa exceção.

Você pode usar `VERSIONABLE_SCHEMA` combinadas com ( **or) de**sua versão de esquema para impedir que essa exceção seja gerada. Usando `VERSIONABLE_SCHEMA`, seu código pode executar a ação apropriada em sua função `Serialize` verificando o valor de retorno de [CArchive:: GetObjectSchema](../mfc/reference/carchive-class.md#getobjectschema).

## <a name="calling-serialize-directly"></a>Chamando Serialize diretamente

Em muitos casos, a sobrecarga do esquema de arquivo de objeto geral de `WriteObject` e `ReadObject` não é necessária. Esse é o caso comum de serializar os dados em um [CDocument](../mfc/reference/cdocument-class.md). Nesse caso, o método `Serialize` da `CDocument` é chamado diretamente, não com os operadores Extract ou INSERT. O conteúdo do documento pode, por sua vez, usar o esquema de arquivo de objeto mais geral.

Chamar `Serialize` diretamente tem as seguintes vantagens e desvantagens:

- Nenhum byte extra é adicionado ao arquivo antes ou depois que o objeto é serializado. Isso não apenas torna os dados salvos menores, mas permite que você implemente `Serialize` rotinas que podem lidar com qualquer formato de arquivo.

- O MFC é ajustado para que as implementações de `WriteObject` e `ReadObject` e coleções relacionadas não sejam vinculadas ao seu aplicativo, a menos que você precise do esquema de arquivo de objeto mais geral para alguma outra finalidade.

- Seu código não precisa se recuperar de números de esquema antigos. Isso torna o código de serialização do documento responsável por codificar números de esquema, números de versão de formato de arquivo ou qualquer número de identificação que você use no início dos seus arquivos de dados.

- Qualquer objeto serializado com uma chamada direta para `Serialize` não deve usar `CArchive::GetObjectSchema` ou deve tratar um valor de retorno de (UINT)-1 indicando que a versão era desconhecida.

Como `Serialize` é chamado diretamente no seu documento, geralmente não é possível que os subobjetos do documento arquivem referências a seu documento pai. Esses objetos devem receber um ponteiro para seu documento de contêiner explicitamente ou você deve usar a função [CArchive:: MapObject](../mfc/reference/carchive-class.md#mapobject) para mapear o ponteiro de `CDocument` para um PID antes que esses ponteiros de volta sejam arquivados.

Conforme observado anteriormente, você deve codificar a versão e as informações de classe por conta própria ao chamar `Serialize` diretamente, permitindo que você altere o formato mais tarde, mantendo a compatibilidade com versões anteriores com arquivos mais antigos. A função `CArchive::SerializeClass` pode ser chamada explicitamente antes de serializar um objeto diretamente ou antes de chamar uma classe base.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
