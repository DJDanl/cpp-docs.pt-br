---
title: Criando as listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- CListCtrl class [MFC], creating image lists for
- image lists [MFC], creating for CListCtrl
- lists [MFC], image
ms.assetid: c2768515-deba-49e8-a6f3-5be6482afb19
ms.openlocfilehash: 440ab6fdfe7663557f6c6a6607e617c793d26674
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371583"
---
# <a name="creating-the-image-lists"></a>Criando as listas de imagens

Criar listas de imagens é o mesmo se você usar [CListView](../mfc/reference/clistview-class.md) ou [CListCtrl](../mfc/reference/clistctrl-class.md).

> [!NOTE]
> Você só precisa de listas de `LVS_ICON` imagens se o controle da lista incluir o estilo.

Use `CImageList` classe para criar uma ou mais listas de imagens (para ícones de tamanho real, pequenos ícones e estados). Consulte [CImageList](../mfc/reference/cimagelist-class.md)e consulte [Listas de imagens](/windows/win32/Controls/using-list-view-controls) de exibição de listas no SDK do Windows.

Chamada [CListCtrl::SetImageList](../mfc/reference/clistctrl-class.md#setimagelist) para cada lista de imagens; passar um ponteiro `CImageList` para o objeto apropriado.

## <a name="see-also"></a>Confira também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
