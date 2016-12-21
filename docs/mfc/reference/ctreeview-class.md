---
title: "Classe de CTreeView | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CTreeView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CTreeView"
  - "Classe de CTreeView, controles comuns"
  - "listas de diretório"
  - "arquivo lista [C++]"
  - "controles de exibição de árvore"
ms.assetid: 5df583a6-d69f-42ca-9d8d-57e04558afff
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CTreeView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Simplifica o uso de controle da árvore de e [CTreeCtrl](../../mfc/reference/ctreectrl-class.md), a classe que encapsula funcionalidade de árvore de controle, com a arquitetura de exibição MFC.  
  
## Sintaxe  
  
```  
class CTreeView : public CCtrlView  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTreeView::CTreeView](../Topic/CTreeView::CTreeView.md)|Constrói um objeto de `CTreeView` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTreeView::GetTreeCtrl](../Topic/CTreeView::GetTreeCtrl.md)|Retorna o controle da árvore associado com a exibição.|  
  
## Comentários  
 Para obter mais informações sobre essa arquitetura, consulte a visão geral para a classe de [CView](../Topic/CView%20Class.md) e referências cruzadas mencionadas lá.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CView](../Topic/CView%20Class.md)  
  
 [CCtrlView](../../mfc/reference/cctrlview-class.md)  
  
 `CTreeView`  
  
## Requisitos  
 **Cabeçalho:** afxcview.h  
  
## Consulte também  
 [Classe de CCtrlView](../../mfc/reference/cctrlview-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CView](../Topic/CView%20Class.md)   
 [Classe de CCtrlView](../../mfc/reference/cctrlview-class.md)   
 [Classe de CTreeCtrl](../../mfc/reference/ctreectrl-class.md)