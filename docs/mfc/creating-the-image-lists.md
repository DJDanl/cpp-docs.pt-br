---
title: Criando as listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- CListCtrl class [MFC], creating image lists for
- image lists [MFC], creating for CListCtrl
- lists [MFC], image
ms.assetid: c2768515-deba-49e8-a6f3-5be6482afb19
ms.openlocfilehash: 844bfe71f7b03f299f57b0fd4558b7e9eacf67c2
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57265776"
---
# <a name="creating-the-image-lists"></a>Criando as listas de imagens

Criando listas de imagens é o mesmo se você usar [CListView](../mfc/reference/clistview-class.md) ou [CListCtrl](../mfc/reference/clistctrl-class.md).

> [!NOTE]
>  Você só precisa imagem listas se seu controle lista inclui o `LVS_ICON` estilo.

Use a classe `CImageList` para criar um ou mais listas de imagens (para os ícones em tamanho normal, ícones pequenos e estados). Ver [CImageList](../mfc/reference/cimagelist-class.md)e veja [listas de imagens do modo de exibição de lista](/windows/desktop/Controls/using-list-view-controls) no SDK do Windows.

Chame [CListCtrl::SetImageList](../mfc/reference/clistctrl-class.md#setimagelist) para cada lista de imagem; passar um ponteiro para o apropriada `CImageList` objeto.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
