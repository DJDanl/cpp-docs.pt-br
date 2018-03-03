---
title: CTreeCtrl vs. CTreeView | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bb0c1b7a7bf73ab70bbccca6f2a9ccc2ab385516
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ctreectrl-vs-ctreeview"></a>CTreeCtrl vs. CTreeView
MFC fornece duas classes que encapsulam os controles em árvore: [CTreeCtrl](../mfc/reference/ctreectrl-class.md) e [CTreeView](../mfc/reference/ctreeview-class.md). Cada classe é útil em situações diferentes.  
  
 Use `CTreeCtrl` quando você precisa de um controle de janela filho simples; por exemplo, em uma caixa de diálogo. Especialmente iria querer usar `CTreeCtrl` se houver outros controles filho na janela, como uma caixa de diálogo típico.  
  
 Use `CTreeView` quando você quiser que o controle de árvore para atuar como uma janela de exibição na arquitetura de documento/exibição, bem como um controle de árvore. Um `CTreeView` ocupará toda a área cliente de uma janela do quadro ou janela separadora. Ele será automaticamente redimensionado quando sua janela pai for redimensionada e que pode processar mensagens de comando de barras de ferramentas, menus e teclas de aceleração. Como um controle de árvore contém os dados necessários para exibir a árvore, o objeto de documento correspondente não precisa ser complicado — você pode até usar [CDocument](../mfc/reference/cdocument-class.md) como o tipo de documento em seu modelo de documento.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

