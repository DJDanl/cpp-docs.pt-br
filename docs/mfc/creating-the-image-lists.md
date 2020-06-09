---
title: Criando as listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- CListCtrl class [MFC], creating image lists for
- image lists [MFC], creating for CListCtrl
- lists [MFC], image
ms.assetid: c2768515-deba-49e8-a6f3-5be6482afb19
ms.openlocfilehash: bbba01a6a8e08ea53e164656733aa06e03dd87a7
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625943"
---
# <a name="creating-the-image-lists"></a>Criando as listas de imagens

A criação de listas de imagens é a mesma se você usa [CListView](reference/clistview-class.md) ou [CListCtrl](reference/clistctrl-class.md).

> [!NOTE]
> Você só precisa de listas de imagens se o controle de lista incluir o `LVS_ICON` estilo.

Use `CImageList` a classe para criar uma ou mais listas de imagens (para ícones de tamanho completo, ícones pequenos e Estados). Consulte [CImageList](reference/cimagelist-class.md)e veja [lista de imagens de exibição](/windows/win32/Controls/using-list-view-controls) de listas no SDK do Windows.

Chamar [CListCtrl:: SetImageList](reference/clistctrl-class.md#setimagelist) para cada lista de imagens; Passe um ponteiro para o `CImageList` objeto apropriado.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](using-clistctrl.md)<br/>
[Controles](controls-mfc.md)
