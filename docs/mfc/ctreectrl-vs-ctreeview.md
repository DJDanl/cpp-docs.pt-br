---
title: "CTreeCtrl vs. CTreeView | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CTreeCtrl"
  - "CTreeView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CTreeCtrl, vs. classe CTreeView"
  - "Classe CTreeView, vs. classe CTreeCtrl"
  - "controles em árvore, e exibição de árvore"
  - "controles de exibição de árvore"
ms.assetid: bba5af25-103f-4b53-84d3-071bc9bd6494
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CTreeCtrl vs. CTreeView
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC O fornece duas classes que encapsulam controles de árvore: [CTreeCtrl](../mfc/reference/ctreectrl-class.md) e [CTreeView](../mfc/reference/ctreeview-class.md).  Cada classe é útil em situações diferentes.  
  
 Use `CTreeCtrl` quando precisar de um controle simples de janela filho; por exemplo, em uma caixa de diálogo.  Você precisará especialmente para usar `CTreeCtrl` se haverá outros controles filho na janela, como em uma caixa de diálogo comum.  
  
 Use `CTreeView` quando o controle de árvore para atuar como uma janela de exibição na arquitetura do documento\/exibição assim como um controle de árvore.  `CTreeView` ocupará a área do cliente de uma janela do quadro ou da janela do separador.  Será redimensionado automaticamente quando a janela pai é redimensionada, e pode processar mensagens do comando de menus, as teclas de aceleração, e as barras de ferramentas.  Desde que um controle de árvore contém os dados necessários para exibir a árvore, o objeto correspondente de documento não tem que ser complicado — você pode usar [CDocument](../Topic/CDocument%20Class.md) mesmo como o documento em seu modelo de documento.  
  
## Consulte também  
 [Usando CTreeCtrl](../Topic/Using%20CTreeCtrl.md)   
 [Controles](../mfc/controls-mfc.md)