---
title: 'Objetos e origens de dados: manipulação'
ms.date: 11/04/2016
helpviewer_keywords:
- data objects [MFC], manipulating
- data sources [MFC], data operations
- data sources [MFC], inserting data
- Clipboard [MFC], determining available formats
- OLE [MFC], data objects
- Clipboard [MFC], passing format information
- data sources [MFC], determining available formats
- delayed rendering [MFC]
- OLE [MFC], data sources
ms.assetid: f7f27e77-bb5d-4131-b819-d71bf929ebaf
ms.openlocfilehash: a08b6ff274c73d301c156d65aa56fbecca49128c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370547"
---
# <a name="data-objects-and-data-sources-manipulation"></a>Objetos e origens de dados: manipulação

Depois que um objeto de dados ou fonte de dados for criado, você pode executar uma série de operações comuns nos dados, como inserir e remover dados, enumerar os formatos em que os dados estão e muito mais. Este artigo descreve as técnicas necessárias para concluir as operações mais comuns. Os tópicos incluem:

- [Inserindo dados em uma fonte de dados](#_core_inserting_data_into_a_data_source)

- [Determinando os formatos disponíveis em um objeto de dados](#_core_determining_the_formats_available_in_a_data_object)

- [Recuperando dados de um objeto de dados](#_core_retrieving_data_from_a_data_object)

## <a name="inserting-data-into-a-data-source"></a><a name="_core_inserting_data_into_a_data_source"></a>Inserindo dados em uma fonte de dados

A forma como os dados são inseridos em uma fonte de dados depende se os dados são fornecidos imediatamente ou sob demanda, e em que meio são fornecidos. As possibilidades são as seguintes.

### <a name="supplying-data-immediately-immediate-rendering"></a>Fornecimento de dados imediatamente (renderização imediata)

- Ligue `COleDataSource::CacheGlobalData` repetidamente para cada formato de área de transferência em que você está fornecendo dados. Passe o formato da Área de Transferência a ser usado, uma alça para a memória contendo os dados e, opcionalmente, uma estrutura **FORMATETC** descrevendo os dados.

     -ou-

- Se você quiser trabalhar diretamente com estruturas `COleDataSource::CacheData` **STGMEDIUM,** você chamará em vez de `COleDataSource::CacheGlobalData` na opção acima.

### <a name="supplying-data-on-demand-delayed-rendering"></a>Fornecimento de dados sob demanda (renderização atrasada)

Este é um tópico avançado.

- Ligue `COleDataSource::DelayRenderData` repetidamente para cada formato de área de transferência em que você está fornecendo dados. Passe o formato da Área de Transferência para ser usado e, opcionalmente, uma estrutura **FORMATETC** descrevendo os dados. Quando os dados são solicitados, `COleDataSource::OnRenderData`a estrutura será chamada , o que você deve substituir.

     -ou-

- Se você `CFile` usar um objeto para `COleDataSource::DelayRenderFileData` fornecer `COleDataSource::DelayRenderData` os dados, ligue em vez de na opção anterior. Quando os dados são solicitados, `COleDataSource::OnRenderFileData`a estrutura será chamada , o que você deve substituir.

## <a name="determining-the-formats-available-in-a-data-object"></a><a name="_core_determining_the_formats_available_in_a_data_object"></a>Determinando os formatos disponíveis em um objeto de dados

Antes que um aplicativo permita que o usuário cole dados nele, ele precisa saber se há formatos na Área de Transferência que ele pode lidar. Para fazer isso, sua aplicação deve fazer o seguinte:

1. Crie `COleDataObject` um objeto e uma estrutura **FORMATETC.**

1. Ligue para a `AttachClipboard` função de membro do objeto de dados para associar o objeto de dados aos dados na Área de Transferência.

1. Realize um dos seguintes procedimentos:

   - Chame a função `IsDataAvailable` de membro do objeto de dados se houver apenas um ou dois formatos necessários. Isso poupará tempo nos casos em que os dados da Área de Transferência suportam significativamente mais formatos do que o seu aplicativo.

     \-ou-

   - Ligue para a `BeginEnumFormats` função membro do objeto de dados para começar a enumerar os formatos disponíveis na Área de Transferência. Em `GetNextFormat` seguida, ligue até que a Área de Transferência retorne um formato que seu aplicativo suporta ou não há mais formatos.

Se você estiver usando **ON_UPDATE_COMMAND_UI,** agora você pode ativar a Pasta e, possivelmente, colar itens especiais no menu Editar. Para fazer isso, `CMenu::EnableMenuItem` `CCmdUI::Enable`ligue para um ou. Para obter mais informações sobre o que os aplicativos de contêiner devem fazer com os itens do menu e quando, consulte [Menus e Recursos: Adições de contêiner](../mfc/menus-and-resources-container-additions.md).

## <a name="retrieving-data-from-a-data-object"></a><a name="_core_retrieving_data_from_a_data_object"></a>Recuperando dados de um objeto de dados

Uma vez decidido um formato de dados, tudo o que resta é recuperar os dados do objeto de dados. Para isso, o usuário decide onde colocar os dados, e o aplicativo chama a função apropriada. Os dados estarão disponíveis em um dos seguintes meios:

|Médio|Função para chamar|
|------------|----------------------|
|Memória Global`HGLOBAL`( )|`COleDataObject::GetGlobalData`|
|Arquivo`CFile`( )|`COleDataObject::GetFileData`|
|**Estrutura STGMEDIUM** (`IStorage`)|`COleDataObject::GetData`|

Comumente, o meio será especificado juntamente com o formato da área de transferência. Por exemplo, um **objeto** CF_EMBEDDEDSTRUCT `IStorage` está sempre em um meio que requer uma estrutura **STGMEDIUM.** Portanto, você usaria `GetData` porque é a única dessas funções que pode aceitar uma estrutura **STGMEDIUM.**

Para os casos em que `IStream` o `HGLOBAL` formato da Área `CFile` de Transferência está em um ou meio, a estrutura pode fornecer um ponteiro que faz referência aos dados. O aplicativo pode, então, usar a leitura de arquivo para obter os dados da mesma forma que pode importar dados de um arquivo. Essencialmente, esta é a interface `OnRenderData` lado `OnRenderFileData` cliente para as rotinas na fonte de dados.

O usuário agora pode inserir dados no documento, assim como para qualquer outro dado no mesmo formato.

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Arraste e solte](../mfc/drag-and-drop-ole.md)

- [Área de transferência](../mfc/clipboard.md)

## <a name="see-also"></a>Confira também

[Objetos e origens de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md)<br/>
[Classe COleDataObject](../mfc/reference/coledataobject-class.md)<br/>
[Classe COleDataSource](../mfc/reference/coledatasource-class.md)
