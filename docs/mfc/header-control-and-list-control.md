---
title: Controle de cabeçalho e de lista
ms.date: 11/04/2016
helpviewer_keywords:
- CListCtrl class [MFC], with CHeaderCtrl
- CListCtrl class [MFC], header controls
- CHeaderCtrl class [MFC], with CListCtrl
- controls [MFC], header
- header controls [MFC]
- header controls [MFC], list controls used with
ms.assetid: b20194b1-1a6b-4e2f-b890-1b3cca6650bc
ms.openlocfilehash: f9dd34b27ddbdc0b99fafbb23ad1cf9782d98605
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626414"
---
# <a name="header-control-and-list-control"></a>Controle de cabeçalho e de lista

Na maioria dos casos, você usará o controle de cabeçalho que é inserido em um objeto [CListCtrl](reference/clistctrl-class.md) ou [CListView](reference/clistview-class.md) . No entanto, há casos em que um objeto de controle de cabeçalho separado é desejável, como a manipulação de dados, organizados em colunas ou linhas, em um objeto derivado de [cvisualização](reference/cview-class.md). Nesses casos, você precisa de maior controle sobre a aparência e o comportamento padrão de um controle de cabeçalho incorporado.

No caso comum que você deseja que um controle de cabeçalho forneça o comportamento padrão padrão, convém usar [CListCtrl](reference/clistctrl-class.md) ou [CListView](reference/clistview-class.md) em vez disso. Use `CListCtrl` quando você quiser a funcionalidade de um controle de cabeçalho padrão, inserido em um controle comum de exibição de lista. Use [CListView](reference/clistview-class.md) quando desejar a funcionalidade de um controle de cabeçalho padrão, inserido em um objeto View.

> [!NOTE]
> Esses controles incluem apenas um controle de cabeçalho interno se o controle de exibição de lista for criado usando o estilo de **LVS_REPORT** .

Na maioria dos casos, a aparência do controle de cabeçalho incorporado pode ser modificada alterando os estilos do controle de exibição de lista que o contém. Além disso, as informações sobre o controle de cabeçalho podem ser obtidas por meio de funções de membro do controle de exibição de lista pai. No entanto, para controle total e acesso aos atributos e estilos do controle de cabeçalho incorporado, é recomendável que um ponteiro para o objeto de controle de cabeçalho seja obtido.

O objeto de controle de cabeçalho incorporado pode ser acessado de um `CListCtrl` ou `CListView` com uma chamada para a função de membro da respectiva classe `GetHeaderCtrl` . O código a seguir demonstra isso:

[!code-cpp[NVC_MFCControlLadenDialog#14](codesnippet/cpp/header-control-and-list-control_1.cpp)]

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Usando listas de imagens com controles de cabeçalho](using-image-lists-with-header-controls.md)

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](using-cheaderctrl.md)<br/>
[Controles](controls-mfc.md)
