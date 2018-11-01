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
ms.openlocfilehash: ee5cb320cb07a656675bd6735d6761cb69573d0f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50636144"
---
# <a name="data-objects-and-data-sources-manipulation"></a>Objetos e origens de dados: manipulação

Depois que um objeto de dados ou fonte de dados tiver sido criado, você pode executar um número de operações comuns em dados, como inserção e remoção de dados, enumerando os formatos de que dados se encontra e muito mais. Este artigo descreve as técnicas necessárias para concluir as operações mais comuns. Os tópicos incluem:

- [Inserindo dados em uma fonte de dados](#_core_inserting_data_into_a_data_source)

- [Determinando os formatos disponíveis em um objeto de dados](#_core_determining_the_formats_available_in_a_data_object)

- [Recuperando dados de um objeto de dados](#_core_retrieving_data_from_a_data_object)

##  <a name="_core_inserting_data_into_a_data_source"></a> Inserindo dados em uma fonte de dados

Como os dados são inseridos em uma fonte de dados depende se os dados são fornecidos imediatamente ou sob demanda e em qual mídia for fornecido. As possibilidades são da seguinte maneira.

### <a name="supplying-data-immediately-immediate-rendering"></a>Fornecendo dados imediatamente (renderização imediata)

- Chamar `COleDataSource::CacheGlobalData` repetidamente para cada formato de área de transferência na qual você está fornecendo dados. Passe o formato de área de transferência a ser usado, um identificador para a memória que contém os dados e, opcionalmente, uma **FORMATETC** estrutura que descreve os dados.

     -ou-

- Se você quiser trabalhar diretamente com **STGMEDIUM** estruturas, chame `COleDataSource::CacheData` em vez de `COleDataSource::CacheGlobalData` na opção acima.

### <a name="supplying-data-on-demand-delayed-rendering"></a>Fornecendo dados sob demanda (renderização atrasada)

Este é um tópico avançado.

- Chamar `COleDataSource::DelayRenderData` repetidamente para cada formato de área de transferência na qual você está fornecendo dados. Passe o formato de área de transferência a ser usado e, opcionalmente, uma **FORMATETC** estrutura que descreve os dados. Quando os dados são solicitados, a estrutura chamará `COleDataSource::OnRenderData`, que deve ser substituído.

     -ou-

- Se você usar um `CFile` objeto para fornecer os dados, chame `COleDataSource::DelayRenderFileData` em vez de `COleDataSource::DelayRenderData` na opção anterior. Quando os dados são solicitados, a estrutura chamará `COleDataSource::OnRenderFileData`, que deve ser substituído.

##  <a name="_core_determining_the_formats_available_in_a_data_object"></a> Determinando os formatos disponíveis em um objeto de dados

Antes de um aplicativo permite que o usuário cole dados nele, ele precisa saber se há formatos na área de transferência que pode manipular. Para fazer isso, seu aplicativo deve fazer o seguinte:

1. Criar uma `COleDataObject` objeto e uma **FORMATETC** estrutura.

1. Chamar o objeto de dados `AttachClipboard` a função de membro para associar o objeto de dados com os dados na área de transferência.

1. Realize um dos seguintes procedimentos:

   - Chamar o objeto de dados `IsDataAvailable` função de membro, se houver apenas um ou dois formatos que você precisa. Este lhe poupará tempo em casos em que os dados na área de transferência dá suporte a formatos de significativamente mais que seu aplicativo.

         -or-

   - Chamar o objeto de dados `BeginEnumFormats` a função de membro para enumerar os formatos disponíveis na área de transferência. Em seguida, chame `GetNextFormat` até que a área de transferência retorna um formato que o aplicativo tiver suporte ou não há nenhum formato mais.

Se você estiver usando **ON_UPDATE_COMMAND_UI**, agora você pode habilitar a colar e, possivelmente, Colar especial itens no menu Editar. Para fazer isso, chame `CMenu::EnableMenuItem` ou `CCmdUI::Enable`. Para obter mais informações sobre quais contêiner os aplicativos devem fazer com itens de menu e quando, consulte [Menus e recursos: adições de contêiner](../mfc/menus-and-resources-container-additions.md).

##  <a name="_core_retrieving_data_from_a_data_object"></a> Recuperando dados de um objeto de dados

Depois de decidir sobre um formato de dados, tudo o que resta é recuperar os dados do objeto de dados. Para fazer isso, o usuário decide onde colocar os dados e o aplicativo chama a função apropriada. Os dados estarão disponíveis em um dos meios de seguir:

|Médio|Função a ser chamada|
|------------|----------------------|
|Memória global (`HGLOBAL`)|`COleDataObject::GetGlobalData`|
|Arquivo (`CFile`)|`COleDataObject::GetFileData`|
|**STGMEDIUM** estrutura (`IStorage`)|`COleDataObject::GetData`|

Normalmente, a mídia será especificada junto com seu formato de área de transferência. Por exemplo, uma **CF_EMBEDDEDSTRUCT** objeto estará sempre em uma `IStorage` médio que requer uma **STGMEDIUM** estrutura. Portanto, você usaria `GetData` porque ele é a única dessas funções que pode aceitar uma **STGMEDIUM** estrutura.

Para casos em que o formato de área de transferência está em um `IStream` ou `HGLOBAL` média, o framework pode fornecer um `CFile` ponteiro que faz referência aos dados. O aplicativo pode usar para obter os dados em grande parte da mesma forma como ele pode importar dados de um arquivo de leitura de arquivo. Essencialmente, essa é a interface de cliente para o `OnRenderData` e `OnRenderFileData` rotinas na fonte de dados.

O usuário pode agora inserir dados no documento, assim como em quaisquer outros dados no mesmo formato.

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Arrastar e soltar](../mfc/drag-and-drop-ole.md)

- [Área de transferência](../mfc/clipboard.md)

## <a name="see-also"></a>Consulte também

[Objetos e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md)<br/>
[Classe COleDataObject](../mfc/reference/coledataobject-class.md)<br/>
[Classe COleDataSource](../mfc/reference/coledatasource-class.md)
