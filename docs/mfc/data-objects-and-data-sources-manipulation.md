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
ms.openlocfilehash: f1a83511edbf240d9a05d6d489f6cda9453ccea9
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620408"
---
# <a name="data-objects-and-data-sources-manipulation"></a>Objetos e origens de dados: manipulação

Depois de criar um objeto de dados ou uma fonte de dados, você pode executar várias operações comuns nos dados, como inserir e remover dados, enumerar os formatos nos quais os dados estão e muito mais. Este artigo descreve as técnicas necessárias para concluir as operações mais comuns. Os tópicos incluem:

- [Inserindo dados em uma fonte de dados](#_core_inserting_data_into_a_data_source)

- [Determinando os formatos disponíveis em um objeto de dados](#_core_determining_the_formats_available_in_a_data_object)

- [Recuperando dados de um objeto de dados](#_core_retrieving_data_from_a_data_object)

## <a name="inserting-data-into-a-data-source"></a><a name="_core_inserting_data_into_a_data_source"></a>Inserindo dados em uma fonte de dados

A maneira como os dados são inseridos em uma fonte de dados depende se os dados são fornecidos imediatamente ou sob demanda e em que mídia é fornecida. As possibilidades são as seguintes.

### <a name="supplying-data-immediately-immediate-rendering"></a>Fornecendo dados imediatamente (renderização imediata)

- Chame `COleDataSource::CacheGlobalData` repetidamente para cada formato de área de transferência no qual você está fornecendo dados. Passe o formato da área de transferência a ser usado, um identificador para a memória que contém os dados e, opcionalmente, uma estrutura **FORMATETC** que descreve os dados.

     -ou-

- Se você quiser trabalhar diretamente com estruturas **STGMEDIUM** , chame `COleDataSource::CacheData` em vez de `COleDataSource::CacheGlobalData` na opção acima.

### <a name="supplying-data-on-demand-delayed-rendering"></a>Fornecendo dados sob demanda (renderização atrasada)

Este é um tópico avançado.

- Chame `COleDataSource::DelayRenderData` repetidamente para cada formato de área de transferência no qual você está fornecendo dados. Passe o formato da área de transferência para ser usado e, opcionalmente, uma estrutura **FORMATETC** que descreva os dados. Quando os dados forem solicitados, a estrutura chamará `COleDataSource::OnRenderData` , que deve ser substituída.

     -ou-

- Se você usar um `CFile` objeto para fornecer os dados, chame em `COleDataSource::DelayRenderFileData` vez de `COleDataSource::DelayRenderData` na opção anterior. Quando os dados forem solicitados, a estrutura chamará `COleDataSource::OnRenderFileData` , que deve ser substituída.

## <a name="determining-the-formats-available-in-a-data-object"></a><a name="_core_determining_the_formats_available_in_a_data_object"></a>Determinando os formatos disponíveis em um objeto de dados

Antes que um aplicativo permita que o usuário Cole dados nele, ele precisa saber se há formatos na área de transferência que ele pode manipular. Para fazer isso, seu aplicativo deve fazer o seguinte:

1. Crie um `COleDataObject` objeto e uma estrutura **FORMATETC** .

1. Chame a função de membro do objeto de dados `AttachClipboard` para associar o objeto de dados aos dados na área de transferência.

1. Realize um dos seguintes procedimentos:

   - Chame a função de membro do objeto de dados `IsDataAvailable` se houver apenas um ou dois formatos necessários. Isso economizará tempo nos casos em que os dados na área de transferência oferecerem suporte a formatos significativamente mais do que o seu aplicativo.

     \-ou-

   - Chame a função de membro do objeto de dados `BeginEnumFormats` para começar a enumerar os formatos disponíveis na área de transferência. Em seguida, chame `GetNextFormat` até que a área de transferência retorne um formato que seu aplicativo dê suporte ou não haja mais formatos.

Se estiver usando **ON_UPDATE_COMMAND_UI**, agora você poderá habilitar colar e, possivelmente, colar itens especiais no menu Editar. Para fazer isso, chame um `CMenu::EnableMenuItem` ou `CCmdUI::Enable` . Para obter mais informações sobre o que os aplicativos de contêiner devem fazer com itens de menu e quando, consulte [menus e recursos: adições de contêiner](menus-and-resources-container-additions.md).

## <a name="retrieving-data-from-a-data-object"></a><a name="_core_retrieving_data_from_a_data_object"></a>Recuperando dados de um objeto de dados

Depois de decidir sobre um formato de dados, tudo o que resta é recuperar os dados do objeto de dados. Para fazer isso, o usuário decide onde colocar os dados e o aplicativo chama a função apropriada. Os dados estarão disponíveis em um dos meios a seguir:

|Médio|Função a ser chamada|
|------------|----------------------|
|Memória global ( `HGLOBAL` )|`COleDataObject::GetGlobalData`|
|Arquivo ( `CFile` )|`COleDataObject::GetFileData`|
|Estrutura **STGMEDIUM** ( `IStorage` )|`COleDataObject::GetData`|

Normalmente, a mídia será especificada junto com seu formato de área de transferência. Por exemplo, um objeto **CF_EMBEDDEDSTRUCT** sempre está em um `IStorage` meio que requer uma estrutura **STGMEDIUM** . Portanto, você usaria `GetData` porque é a única dessas funções que pode aceitar uma estrutura **STGMEDIUM** .

Para casos em que o formato da área de transferência está em um `IStream` ou `HGLOBAL` médio, a estrutura pode fornecer um `CFile` ponteiro que referencie os dados. O aplicativo pode, então, usar a leitura de arquivo para obter os dados da mesma maneira que pode importar dados de um arquivo. Essencialmente, essa é a interface do lado do cliente para `OnRenderData` as `OnRenderFileData` rotinas e na fonte de dados.

Agora, o usuário pode inserir dados no documento, assim como para todos os outros dados no mesmo formato.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Arrastar e soltar](drag-and-drop-ole.md)

- [Área de transferência](clipboard.md)

## <a name="see-also"></a>Consulte também

[Objetos e origens de dados (OLE)](data-objects-and-data-sources-ole.md)<br/>
[Classe COleDataObject](reference/coledataobject-class.md)<br/>
[Classe COleDataSource](reference/coledatasource-class.md)
