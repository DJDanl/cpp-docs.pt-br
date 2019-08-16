---
title: Criando as listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- CListCtrl class [MFC], creating image lists for
- image lists [MFC], creating for CListCtrl
- lists [MFC], image
ms.assetid: c2768515-deba-49e8-a6f3-5be6482afb19
ms.openlocfilehash: 6687b62b70103894d957a21019008e8781385feb
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508787"
---
# <a name="creating-the-image-lists"></a>Criando as listas de imagens

A criação de listas de imagens é a mesma se você usa [CListView](../mfc/reference/clistview-class.md) ou [CListCtrl](../mfc/reference/clistctrl-class.md).

> [!NOTE]
>  Você só precisa de listas de imagens se o controle de `LVS_ICON` lista incluir o estilo.

Use a `CImageList` classe para criar uma ou mais listas de imagens (para ícones de tamanho completo, ícones pequenos e Estados). Consulte [CImageList](../mfc/reference/cimagelist-class.md)e veja [lista de imagens de exibição](/windows/win32/Controls/using-list-view-controls) de listas no SDK do Windows.

Chamar [CListCtrl::](../mfc/reference/clistctrl-class.md#setimagelist) SetImageList para cada lista de imagens; Passe um ponteiro para o objeto `CImageList` apropriado.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
