---
title: 'Objetos de dados e fontes de dados: Criação e destruição'
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
ms.openlocfilehash: 74119d7ea33eef68f0cb4a67c8419514cbb73c10
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57304425"
---
# <a name="data-objects-and-data-sources-creation-and-destruction"></a>Objetos de dados e fontes de dados: Criação e destruição

Conforme explicado no artigo [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md), objetos de dados e fontes de dados representam os dois lados de uma transferência de dados. Este artigo explica a quando criar e destruir a esses objetos e fontes para realizar suas transferências de dados corretamente, incluindo:

- [Criando objetos de dados](#_core_creating_data_objects)

- [Destruindo objetos de dados](#_core_destroying_data_objects)

- [Criando fontes de dados](#_core_creating_data_sources)

- [Destruição de fontes de dados](#_core_destroying_data_sources)

##  <a name="_core_creating_data_objects"></a> Criando objetos de dados

Objetos de dados são usados pelo aplicativo de destino — o cliente ou servidor. Um objeto de dados no aplicativo de destino é uma extremidade de uma conexão entre o aplicativo de origem e o aplicativo de destino. Um objeto de dados no aplicativo de destino é usado para acessar e interagir com os dados na fonte de dados.

Há duas situações comuns em que um objeto de dados é necessária. A situação a primeira é quando dados são soltos em seu aplicativo usando arrastar e soltar. A segunda situação é quando colar ou Colar especial é escolhido no menu Editar.

Em uma situação de arrastar e soltar, você não precisará criar um objeto de dados. Um ponteiro para um objeto de dados existente será passado para sua `OnDrop` função. Esse objeto de dados é criado pela estrutura como parte da operação de arrastar e soltar e também será destruído por ele. Isso nem sempre é o caso quando colá-lo é feita por outro método. Para obter mais informações, consulte [destruindo objetos de dados](#_core_destroying_data_objects).

Se o aplicativo está executando um colar ou a operação Colar especial, você deve criar uma `COleDataObject` objeto e chame seu `AttachClipboard` função de membro. Isso associa o objeto de dados com os dados na área de transferência. Em seguida, você pode usar esse objeto de dados em sua função de colar.

##  <a name="_core_destroying_data_objects"></a> Destruindo objetos de dados

Se você seguir o esquema descrito em [criando objetos de dados](#_core_creating_data_objects), destruindo objetos de dados é um aspecto trivial de transferências de dados. O objeto de dados que foi criado em sua função de colar será destruído pelo MFC quando a função colar retornar.

Se você seguir outro método de lidar com operações de colagem, certificar-se de que o objeto de dados é destruído depois que a operação de colagem for concluída. Até que o objeto de dados é destruído, será impossível para qualquer aplicativo com êxito copiar dados para a área de transferência.

##  <a name="_core_creating_data_sources"></a> Criando fontes de dados

Fontes de dados são usadas pela fonte da transferência de dados, que pode ser o cliente ou do servidor de transferência de dados. Uma fonte de dados no aplicativo de origem é uma extremidade de uma conexão entre o aplicativo de origem e o aplicativo de destino. Um objeto de dados no aplicativo de destino é usado para interagir com os dados na fonte de dados.

Fontes de dados são criadas quando um aplicativo precisa para copiar dados para a área de transferência. Um cenário típico é executado como esta:

1. O usuário seleciona alguns dados.

1. O usuário escolhe **cópia** (ou **Recortar**) da **editar** menu ou inicia uma operação de arrastar e soltar.

1. Dependendo do design do programa, o aplicativo cria um uma `COleDataSource` objeto ou um objeto de uma classe derivada de `COleDataSource`.

1. Os dados selecionados são inseridos na fonte de dados, chamando uma das funções na `COleDataSource::CacheData` ou `COleDataSource::DelayRenderData` grupos.

1. O aplicativo chama o `SetClipboard` função de membro (ou o `DoDragDrop` quando se trata de uma operação de arrastar e soltar de função de membro) que pertencem ao objeto criado na etapa 3.

1. Se esse for um **Recortar** operação ou `DoDragDrop` retorna **DROPEFFECT_MOVE**, os dados selecionados na etapa 1 são excluídos do documento.

Esse cenário é implementado pelos exemplos de OLE do MFC [OCLIENT](../visual-cpp-samples.md) e [HIERSVR](../visual-cpp-samples.md). Examinar o código-fonte para cada aplicativo `CView`-derivado da classe para tudo, exceto os `GetClipboardData` e `OnGetClipboardData` funções. Essas duas funções estão em um a `COleClientItem` ou `COleServerItem`-derivadas implementações de classe. Esses programas de exemplo fornecem um bom exemplo de como implementar esses conceitos.

Uma outra situação em que você talvez queira criar um `COleDataSource` objeto ocorre se você estiver modificando o comportamento padrão de uma operação de arrastar e soltar. Para obter mais informações, consulte o [arrastar e soltar: Personalizando](../mfc/drag-and-drop-customizing.md) artigo.

##  <a name="_core_destroying_data_sources"></a> Destruição de fontes de dados

Fontes de dados devem ser destruídas pelo aplicativo no momento, responsável por elas. Em situações onde você entrega a fonte de dados para OLE, como chamar [COleDataSource::DoDragDrop](../mfc/reference/coledatasource-class.md#dodragdrop), você precisará chamar `pDataSrc->InternalRelease`. Por exemplo:

[!code-cpp[NVC_MFCListView#1](../atl/reference/codesnippet/cpp/data-objects-and-data-sources-creation-and-destruction_1.cpp)]

Se você não entregou sua fonte de dados para OLE, em seguida, você é responsável por destruí-lo, assim como acontece com qualquer objeto de C++ típico.

Para obter mais informações, consulte [arrastar e soltar](../mfc/drag-and-drop-ole.md), [área de transferência](../mfc/clipboard.md), e [objetos de manipulação de dados e fontes de dados](../mfc/data-objects-and-data-sources-manipulation.md).

## <a name="see-also"></a>Consulte também

[Objetos e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md)<br/>
[Classe COleDataObject](../mfc/reference/coledataobject-class.md)<br/>
[Classe COleDataSource](../mfc/reference/coledatasource-class.md)
