---
title: CTreeCtrl vs. CTreeView
ms.date: 11/04/2016
f1_keywords:
- CTreeCtrl
- CTreeView
helpviewer_keywords:
- tree view controls
- CTreeCtrl class [MFC], vs. CTreeView class [MFC]
- CTreeView class [MFC], vs. CTreeCtrl class [MFC]
- tree controls [MFC], and tree view
ms.assetid: bba5af25-103f-4b53-84d3-071bc9bd6494
ms.openlocfilehash: 29349e169e5ad8475001235d9b355da52156d683
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62241824"
---
# <a name="ctreectrl-vs-ctreeview"></a>CTreeCtrl vs. CTreeView

MFC fornece classes que encapsulam os controles de árvore: [CTreeCtrl](../mfc/reference/ctreectrl-class.md) e [CTreeView](../mfc/reference/ctreeview-class.md). Cada classe é útil em situações diferentes.

Use `CTreeCtrl` quando precisar de um controle de janela filho simples; por exemplo, em uma caixa de diálogo. Especialmente iria querer usar `CTreeCtrl` se haverá outros controles filho na janela, como em uma caixa de diálogo comum.

Use `CTreeView` quando deseja que o controle de árvore para atuar como uma janela de exibição na arquitetura de documento/exibição, bem como um controle de árvore. Um `CTreeView` ocupará toda a área cliente de uma janela de quadro ou janela separadora. Ele será redimensionado automaticamente quando sua janela pai for redimensionada, e ele pode processar mensagens de comando de menus, teclas de aceleração e barras de ferramentas. Como um controle de árvore contém os dados necessários para exibir a árvore, o objeto de documento correspondente não precisa ser complicado — você pode até usar [CDocument](../mfc/reference/cdocument-class.md) como o tipo de documento em seu modelo de documento.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
