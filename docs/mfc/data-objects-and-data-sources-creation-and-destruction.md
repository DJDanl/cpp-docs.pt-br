---
title: 'Objetos e origens de dados: criação e destruição'
ms.date: 11/04/2016
helpviewer_keywords:
- destroying data objects [MFC]
- object creation [MFC], data source objects
- data sources [MFC], and data objects
- data source objects [MFC], creating
- destruction [MFC], data sources
- data source objects [MFC], destroying
- data objects [MFC], creating
- data objects [MFC], destroying
- data sources [MFC], role
- data sources [MFC], destroying
- destruction [MFC], data objects
- data sources [MFC], creating
ms.assetid: ac216d54-3ca5-4ce7-850d-cd1f6a90d4f1
ms.openlocfilehash: 8d4edc93594bf453c61e03dca7e3117aefaa6c42
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620492"
---
# <a name="data-objects-and-data-sources-creation-and-destruction"></a>Objetos e origens de dados: criação e destruição

Conforme explicado no artigo [objetos de dados e fontes de dados (OLE)](data-objects-and-data-sources-ole.md), os objetos de dados e as fontes de dados representam ambos os lados de uma transferência de dados. Este artigo explica quando criar e destruir esses objetos e fontes para executar suas transferências de dados corretamente, incluindo:

- [Criando objetos de dados](#_core_creating_data_objects)

- [Destruindo objetos de dados](#_core_destroying_data_objects)

- [Criando fontes de dados](#_core_creating_data_sources)

- [Destruindo fontes de dados](#_core_destroying_data_sources)

## <a name="creating-data-objects"></a><a name="_core_creating_data_objects"></a>Criando objetos de dados

Os objetos de dados são usados pelo aplicativo de destino — tanto o cliente quanto o servidor. Um objeto de dados no aplicativo de destino é uma extremidade de uma conexão entre o aplicativo de origem e o aplicativo de destino. Um objeto de dados no aplicativo de destino é usado para acessar e interagir com os dados na fonte de dados.

Há duas situações comuns em que um objeto de dados é necessário. A primeira situação é quando os dados são descartados em seu aplicativo usando o recurso de arrastar e soltar. A segunda situação é quando colar ou colar especial é escolhido no menu Editar.

Em uma situação de arrastar e soltar, você não precisa criar um objeto de dados. Um ponteiro para um objeto de dados existente será passado para sua `OnDrop` função. Esse objeto de dados é criado pela estrutura como parte da operação de arrastar e soltar e também será destruído por ele. Esse não é sempre o caso quando a colagem é feita por outro método. Para obter mais informações, consulte [destruindo objetos de dados](#_core_destroying_data_objects).

Se o aplicativo estiver executando uma operação de colar ou colar especial, você deverá criar um `COleDataObject` objeto e chamar sua `AttachClipboard` função de membro. Isso associa o objeto de dados aos dados na área de transferência. Você pode usar esse objeto de dados em sua função colar.

## <a name="destroying-data-objects"></a><a name="_core_destroying_data_objects"></a>Destruindo objetos de dados

Se você seguir o esquema descrito em [criando objetos de dados](#_core_creating_data_objects), destruir objetos de dados é um aspecto trivial de transferências de dados. O objeto de dados que foi criado na sua função colar será destruído pelo MFC quando a função Paste retornar.

Se você seguir outro método de tratamento de operações de colagem, verifique se o objeto de dados foi destruído após a conclusão da operação de colagem. Até que o objeto de dados seja destruído, será impossível para qualquer aplicativo copiar dados com êxito para a área de transferência.

## <a name="creating-data-sources"></a><a name="_core_creating_data_sources"></a>Criando fontes de dados

As fontes de dados são usadas pela origem da transferência de dados, que pode ser o cliente ou o lado do servidor da transferência de dados. Uma fonte de dados no aplicativo de origem é uma extremidade de uma conexão entre o aplicativo de origem e o aplicativo de destino. Um objeto de dados no aplicativo de destino é usado para interagir com os dados na fonte de dados.

As fontes de dados são criadas quando um aplicativo precisa copiar dados para a área de transferência. Um cenário típico é executado da seguinte maneira:

1. O usuário seleciona alguns dados.

1. O usuário escolhe **copiar** (ou **recortar**) no menu **Editar** ou começa uma operação de arrastar e soltar.

1. Dependendo do design do programa, o aplicativo cria um `COleDataSource` objeto ou um objeto de uma classe derivada de `COleDataSource` .

1. Os dados selecionados são inseridos na fonte de dados chamando uma das funções nos `COleDataSource::CacheData` `COleDataSource::DelayRenderData` grupos ou.

1. O aplicativo chamará a `SetClipboard` função de membro (ou a `DoDragDrop` função de membro se esta for uma operação de arrastar e soltar) que pertence ao objeto criado na etapa 3.

1. Se essa for uma operação de **recorte** ou `DoDragDrop` retornar **DROPEFFECT_MOVE**, os dados selecionados na etapa 1 serão excluídos do documento.

Esse cenário é implementado pelos exemplos de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) e [HIERSVR](../overview/visual-cpp-samples.md). Examine a origem da classe derivada de cada aplicativo `CView` para todas as funções, exceto `GetClipboardData` as `OnGetClipboardData` . Essas duas funções estão nas `COleClientItem` `COleServerItem` implementações de classe ou derivadas. Esses programas de exemplo fornecem um bom exemplo de como implementar esses conceitos.

Uma outra situação na qual você pode querer criar um `COleDataSource` objeto ocorre se você estiver modificando o comportamento padrão de uma operação de arrastar e soltar. Para obter mais informações, consulte o artigo [arrastar e soltar OLE: Personalizar arrastar e soltar](drag-and-drop-ole.md#customize-drag-and-drop) .

## <a name="destroying-data-sources"></a><a name="_core_destroying_data_sources"></a>Destruindo fontes de dados

As fontes de dados devem ser destruídas pelo aplicativo atualmente responsável por elas. Em situações em que você entrega a fonte de dados para OLE, como chamar [COleDataSource::D oDragDrop](reference/coledatasource-class.md#dodragdrop), você precisa chamar `pDataSrc->InternalRelease` . Por exemplo:

[!code-cpp[NVC_MFCListView#1](../atl/reference/codesnippet/cpp/data-objects-and-data-sources-creation-and-destruction_1.cpp)]

Se você não tiver enviado sua fonte de dados para OLE, será responsável por destruí-la, assim como acontece com qualquer objeto C++ típico.

Para obter mais informações, consulte [arrastar e soltar](drag-and-drop-ole.md), [área de transferência](clipboard.md)e [manipular objetos de dados e fontes de dados](data-objects-and-data-sources-manipulation.md).

## <a name="see-also"></a>Consulte também

[Objetos e origens de dados (OLE)](data-objects-and-data-sources-ole.md)<br/>
[Classe COleDataObject](reference/coledataobject-class.md)<br/>
[Classe COleDataSource](reference/coledatasource-class.md)
