---
title: CTreeCtrl vs. CTreeView | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CTreeCtrl
- CTreeView
dev_langs:
- C++
helpviewer_keywords:
- tree view controls
- CTreeCtrl class [MFC], vs. CTreeView class [MFC]
- CTreeView class [MFC], vs. CTreeCtrl class [MFC]
- tree controls [MFC], and tree view
ms.assetid: bba5af25-103f-4b53-84d3-071bc9bd6494
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d71048b6f03f7f1b4400c0a88c178d1b97acdf2f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="ctreectrl-vs-ctreeview"></a>CTreeCtrl vs. CTreeView
MFC fornece duas classes que encapsulam os controles em árvore: [CTreeCtrl](../mfc/reference/ctreectrl-class.md) e [CTreeView](../mfc/reference/ctreeview-class.md). Cada classe é útil em situações diferentes.  
  
 Use `CTreeCtrl` quando você precisa de um controle de janela filho simples; por exemplo, em uma caixa de diálogo. Especialmente iria querer usar `CTreeCtrl` se houver outros controles filho na janela, como uma caixa de diálogo típico.  
  
 Use `CTreeView` quando você quiser que o controle de árvore para atuar como uma janela de exibição na arquitetura de documento/exibição, bem como um controle de árvore. Um `CTreeView` ocupará toda a área cliente de uma janela do quadro ou janela separadora. Ele será automaticamente redimensionado quando sua janela pai for redimensionada e que pode processar mensagens de comando de barras de ferramentas, menus e teclas de aceleração. Como um controle de árvore contém os dados necessários para exibir a árvore, o objeto de documento correspondente não precisa ser complicado — você pode até usar [CDocument](../mfc/reference/cdocument-class.md) como o tipo de documento em seu modelo de documento.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

