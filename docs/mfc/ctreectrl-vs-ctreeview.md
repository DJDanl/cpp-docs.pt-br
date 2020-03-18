---
title: CTreeCtrl vs. CTreeView
ms.date: 11/04/2016
helpviewer_keywords:
- tree view controls
- CTreeCtrl class [MFC], vs. CTreeView class [MFC]
- CTreeView class [MFC], vs. CTreeCtrl class [MFC]
- tree controls [MFC], and tree view
ms.assetid: bba5af25-103f-4b53-84d3-071bc9bd6494
ms.openlocfilehash: 7c78dfa9920c913fdbedb009c5a6f275a3e3e273
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79445222"
---
# <a name="ctreectrl-vs-ctreeview"></a>CTreeCtrl vs. CTreeView

O MFC fornece duas classes que encapsulam controles de árvore: [CTreeCtrl](../mfc/reference/ctreectrl-class.md) e [CTreeView](../mfc/reference/ctreeview-class.md). Cada classe é útil em situações diferentes.

Use `CTreeCtrl` quando você precisar de um controle de janela filho simples; por exemplo, em uma caixa de diálogo. Especificamente, você desejaria usar `CTreeCtrl` se houver outros controles filho na janela, como em uma caixa de diálogo típica.

Use `CTreeView` quando você quiser que o controle de árvore atue como uma janela de exibição na arquitetura de documento/exibição, bem como um controle de árvore. Uma `CTreeView` ocupará toda a área de cliente de uma janela de quadro ou janela separadora. Ele será redimensionado automaticamente quando a janela pai for redimensionada e poderá processar mensagens de comando de menus, teclas de aceleração e barras de ferramentas. Como um controle de árvore contém os dados necessários para exibir a árvore, o objeto de documento correspondente não precisa ser complicado — você pode até mesmo usar [CDocument](../mfc/reference/cdocument-class.md) como o tipo de documento no modelo de documento.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
