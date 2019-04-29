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
ms.openlocfilehash: 934b54de3266138225087d5519af2be51972cf9d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62240069"
---
# <a name="header-control-and-list-control"></a>Controle de cabeçalho e de lista

Na maioria dos casos, você irá usar o controle de cabeçalho que é inserido em uma [CListCtrl](../mfc/reference/clistctrl-class.md) ou [CListView](../mfc/reference/clistview-class.md) objeto. No entanto, há casos em que um objeto de controle de cabeçalho separado é desejável, como a manipulação de dados, organizados em colunas ou linhas, em uma [CView](../mfc/reference/cview-class.md)-objeto derivado. Nesses casos, você precisa ter maior controle sobre a aparência e o comportamento padrão de um controle de cabeçalho incorporado.

No caso comum que você deseja que um controle de cabeçalho para oferecer padrão, comportamento padrão, você talvez queira usar [CListCtrl](../mfc/reference/clistctrl-class.md) ou [CListView](../mfc/reference/clistview-class.md) em vez disso. Use `CListCtrl` quando deseja que a funcionalidade de um controle de cabeçalho padrão, inserido em um controle comum de exibição de lista. Use [CListView](../mfc/reference/clistview-class.md) quando deseja que a funcionalidade de um controle de cabeçalho padrão, inserido em um objeto de exibição.

> [!NOTE]
>  Esses controles incluem um controle de cabeçalho internas somente se o controle de exibição de lista é criado usando o **LVS_REPORT** estilo.

Na maioria dos casos, a aparência do controle de cabeçalho incorporado pode ser modificada ao alterar os estilos de controle de exibição de lista que contém. Além disso, as informações sobre o controle de cabeçalho podem ser obtidas por meio de funções de membro de controle de exibição de lista pai. No entanto, para o controle completo e acesso para os atributos e estilos de controle de cabeçalho incorporado, é recomendável que um ponteiro para o objeto de controle de cabeçalho ser obtido.

O objeto de controle de cabeçalho inseridos pode ser acessado de qualquer uma `CListCtrl` ou `CListView` com uma chamada para a classe respectiva `GetHeaderCtrl` função de membro. O código a seguir demonstra isso:

[!code-cpp[NVC_MFCControlLadenDialog#14](../mfc/codesnippet/cpp/header-control-and-list-control_1.cpp)]

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Usando listas de imagens com controles de cabeçalho](../mfc/using-image-lists-with-header-controls.md)

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
