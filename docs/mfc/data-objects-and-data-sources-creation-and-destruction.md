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
ms.openlocfilehash: 58b68ca9597fd2a03cffb2bbab327dbc72d09599
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371210"
---
# <a name="data-objects-and-data-sources-creation-and-destruction"></a>Objetos e origens de dados: criação e destruição

Conforme explicado no artigo [Data Objects and Data Sources (OLE)](../mfc/data-objects-and-data-sources-ole.md), objetos de dados e fontes de dados representam ambos os lados de uma transferência de dados. Este artigo explica quando criar e destruir esses objetos e fontes para executar suas transferências de dados corretamente, incluindo:

- [Criando objetos de dados](#_core_creating_data_objects)

- [Destruindo objetos de dados](#_core_destroying_data_objects)

- [Criando fontes de dados](#_core_creating_data_sources)

- [Destruindo fontes de dados](#_core_destroying_data_sources)

## <a name="creating-data-objects"></a><a name="_core_creating_data_objects"></a>Criando objetos de dados

Os objetos de dados são usados pelo aplicativo de destino — seja o cliente ou o servidor. Um objeto de dados no aplicativo de destino é uma extremidade de uma conexão entre o aplicativo de origem e o aplicativo de destino. Um objeto de dados no aplicativo de destino é usado para acessar e interagir com os dados na fonte de dados.

Existem duas situações comuns em que um objeto de dados é necessário. A primeira situação é quando os dados são descartados em seu aplicativo usando arrastar e soltar. A segunda situação é quando Colar ou Colar Especial é escolhido no menu Editar.

Em uma situação de arrastar e soltar, você não precisa criar um objeto de dados. Um ponteiro para um objeto de dados `OnDrop` existente será passado para sua função. Esse objeto de dados é criado pela estrutura como parte da operação de arrastar e soltar e também será destruído por ele. Nem sempre é assim quando a colagem é feita por outro método. Para obter mais informações, consulte [Destroy Data Objects](#_core_destroying_data_objects).

Se o aplicativo estiver executando uma operação especial de colar `COleDataObject` ou colar, você deve criar um objeto e chamar sua `AttachClipboard` função de membro. Isso associa o objeto de dados com os dados da Área de Transferência. Em seguida, você pode usar este objeto de dados em sua função colar.

## <a name="destroying-data-objects"></a><a name="_core_destroying_data_objects"></a>Destruindo objetos de dados

Se você seguir o esquema descrito na [criação de objetos de dados,](#_core_creating_data_objects)destruir objetos de dados é um aspecto trivial das transferências de dados. O objeto de dados criado na função pasta será destruído pelo MFC quando a função de colar retornar.

Se você seguir outro método de lidar com as operações de colar, certifique-se de que o objeto de dados seja destruído após a conclusão da operação de colar. Até que o objeto de dados seja destruído, será impossível para qualquer aplicativo copiar com sucesso os dados para a Área de Transferência.

## <a name="creating-data-sources"></a><a name="_core_creating_data_sources"></a>Criando fontes de dados

As fontes de dados são usadas pela fonte da transferência de dados, que pode ser o cliente ou o lado do servidor da transferência de dados. Uma fonte de dados no aplicativo de origem é uma extremidade de uma conexão entre o aplicativo de origem e o aplicativo de destino. Um objeto de dados no aplicativo de destino é usado para interagir com os dados na fonte de dados.

As fontes de dados são criadas quando um aplicativo precisa copiar dados para a Área de Transferência. Um cenário típico funciona assim:

1. O usuário seleciona alguns dados.

1. O usuário escolhe **Copiar** (ou **Cortar)** no menu **Editar** ou inicia uma operação de arrastar e soltar.

1. Dependendo do design do programa, o `COleDataSource` aplicativo cria um objeto ou `COleDataSource`um objeto de uma classe derivada de .

1. Os dados selecionados são inseridos na fonte de dados `COleDataSource::CacheData` `COleDataSource::DelayRenderData` ligando para uma das funções no ou grupos.

1. O aplicativo `SetClipboard` chama a função `DoDragDrop` membro (ou a função membro se esta for uma operação de arrastar e soltar) pertencente ao objeto criado na etapa 3.

1. Se esta **Cut** for uma `DoDragDrop` operação Cortar ou retornar **DROPEFFECT_MOVE,** os dados selecionados na etapa 1 serão excluídos do documento.

Este cenário é implementado pelas amostras OLE MFC [OCLIENT](../overview/visual-cpp-samples.md) e [HIERSVR](../overview/visual-cpp-samples.md). Olhe para a fonte para `CView`a classe derivada `GetClipboardData` de `OnGetClipboardData` cada aplicativo para todos, exceto as funções. Essas duas funções estão `COleClientItem` `COleServerItem`nas implementações de classe ou derivadas. Esses programas de amostra fornecem um bom exemplo de como implementar esses conceitos.

Uma outra situação em que `COleDataSource` você pode querer criar um objeto ocorre se você estiver modificando o comportamento padrão de uma operação de arrastar e soltar. Para obter mais informações, consulte [o OLE Drag and drop: Personalize o](../mfc/drag-and-drop-ole.md#customize-drag-and-drop) artigo arrastar e soltar.

## <a name="destroying-data-sources"></a><a name="_core_destroying_data_sources"></a>Destruindo fontes de dados

As fontes de dados devem ser destruídas pelo aplicativo atualmente responsável por eles. Em situações em que você entrega a fonte de dados para o OLE, como `pDataSrc->InternalRelease`ligar para [COleDataSource::DoDragDrop](../mfc/reference/coledatasource-class.md#dodragdrop), você precisa ligar . Por exemplo:

[!code-cpp[NVC_MFCListView#1](../atl/reference/codesnippet/cpp/data-objects-and-data-sources-creation-and-destruction_1.cpp)]

Se você não entregou sua fonte de dados ao OLE, então você é responsável por destruí-la, como acontece com qualquer objeto C++ típico.

Para obter mais informações, consulte [Arrastar e soltar,](../mfc/drag-and-drop-ole.md) [área de transferência](../mfc/clipboard.md)e manipular [objetos de dados e fontes de dados.](../mfc/data-objects-and-data-sources-manipulation.md)

## <a name="see-also"></a>Confira também

[Objetos e origens de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md)<br/>
[Classe COleDataObject](../mfc/reference/coledataobject-class.md)<br/>
[Classe COleDataSource](../mfc/reference/coledatasource-class.md)
