---
title: CTreeCtrl vs. CTreeView
ms.date: 11/04/2016
helpviewer_keywords:
- tree view controls
- CTreeCtrl class [MFC], vs. CTreeView class [MFC]
- CTreeView class [MFC], vs. CTreeCtrl class [MFC]
- tree controls [MFC], and tree view
ms.assetid: bba5af25-103f-4b53-84d3-071bc9bd6494
ms.openlocfilehash: 83e07c75b9eab6df05dbcd0f52cfbe8b90e1d768
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620476"
---
# <a name="ctreectrl-vs-ctreeview"></a>CTreeCtrl vs. CTreeView

O MFC fornece duas classes que encapsulam controles de árvore: [CTreeCtrl](reference/ctreectrl-class.md) e [CTreeView](reference/ctreeview-class.md). Cada classe é útil em situações diferentes.

Use `CTreeCtrl` quando você precisar de um controle de janela filho simples; por exemplo, em uma caixa de diálogo. Você deve querer usar, especialmente `CTreeCtrl` , se haverá outros controles filho na janela, como em uma caixa de diálogo típica.

Use `CTreeView` quando desejar que o controle de árvore atue como uma janela de exibição na arquitetura de documento/exibição, bem como um controle de árvore. Um `CTreeView` ocupará toda a área do cliente de uma janela de quadro ou janela separadora. Ele será redimensionado automaticamente quando a janela pai for redimensionada e poderá processar mensagens de comando de menus, teclas de aceleração e barras de ferramentas. Como um controle de árvore contém os dados necessários para exibir a árvore, o objeto de documento correspondente não precisa ser complicado — você pode até mesmo usar [CDocument](reference/cdocument-class.md) como o tipo de documento no modelo de documento.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](using-ctreectrl.md)<br/>
[Controles](controls-mfc.md)
