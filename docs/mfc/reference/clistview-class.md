---
title: "Classe de CListView | Microsoft Docs"
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
  - "CListView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CListView"
  - "modos de exibição, e controles comuns"
ms.assetid: 7626bdb2-a1b8-4eab-b631-6743710a8432
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CListView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Simplifica o uso do controle de lista e de [CListCtrl](../Topic/CListCtrl%20Class.md), a classe que encapsula funcionalidade de lista\- controle, com a arquitetura de exibição MFC.  
  
## Sintaxe  
  
```  
class CListView : public CCtrlView  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CListView::CListView](../Topic/CListView::CListView.md)|Constrói um objeto de `CListView` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CListView::GetListCtrl](../Topic/CListView::GetListCtrl.md)|Retorna o controle de lista associado com a exibição.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CListView::RemoveImageList](../Topic/CListView::RemoveImageList.md)|Remove a lista de imagem especificada de exibição de lista.|  
  
## Comentários  
 Para obter mais informações sobre essa arquitetura, consulte a visão geral para a classe de [CView](../Topic/CView%20Class.md) e referências cruzadas mencionadas lá.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CView](../Topic/CView%20Class.md)  
  
 [CCtrlView](../../mfc/reference/cctrlview-class.md)  
  
 `CListView`  
  
## Requisitos  
 **Cabeçalho:** afxcview.h  
  
## Consulte também  
 [Exemplo ROWLIST MFC](../../top/visual-cpp-samples.md)   
 [Classe de CCtrlView](../../mfc/reference/cctrlview-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CCtrlView](../../mfc/reference/cctrlview-class.md)