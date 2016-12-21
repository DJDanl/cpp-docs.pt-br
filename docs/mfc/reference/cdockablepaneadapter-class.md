---
title: "Classe de CDockablePaneAdapter | Microsoft Docs"
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
  - "CDockablePaneAdapter"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDockablePaneAdapter"
ms.assetid: 6ed6cf82-f39c-4d0c-bf7c-8641495cf8f3
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDockablePaneAdapter
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Oferece suporte de encaixe para `CWnd`\-derivada painéis.  
  
## Sintaxe  
  
```  
class CDockablePaneAdapter : public CDockablePane  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDockablePaneAdapter::GetWrappedWnd](../Topic/CDockablePaneAdapter::GetWrappedWnd.md)|Retorna a janela encapsulada.|  
|[CDockablePaneAdapter::LoadState](../Topic/CDockablePaneAdapter::LoadState.md)|\(Substitui [CDockablePane::LoadState](http://msdn.microsoft.com/pt-br/96110136-4f46-4764-8a76-3b4abaf77917).\)|  
|[CDockablePaneAdapter::SaveState](../Topic/CDockablePaneAdapter::SaveState.md)|\(Substitui [CDockablePane::SaveState](http://msdn.microsoft.com/pt-br/c5c24249-8d0d-46cb-96d9-9f5c6dc191db).\)|  
|[CDockablePaneAdapter::SetWrappedWnd](../Topic/CDockablePaneAdapter::SetWrappedWnd.md)||  
  
## Comentários  
 Normalmente, o framework cria objetos dessa classe quando você usa o [CMFCBaseTabCtrl::AddTab](../Topic/CMFCBaseTabCtrl::AddTab.md) ou [CMFCBaseTabCtrl::InsertTab](../Topic/CMFCBaseTabCtrl::InsertTab.md) métodos.  
  
 Se você deseja personalizar o `CDockablePaneAdapter` comportamento, basta derivar uma nova classe dela e definir as informações de classe de tempo de execução para uma janela com guias usando [CMFCBaseTabCtrl::SetDockingBarWrapperRTC](../Topic/CMFCBaseTabCtrl::SetDockingBarWrapperRTC.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md) [CCmdTarget](../Topic/CCmdTarget%20Class.md) [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md) [CPane](../../mfc/reference/cpane-class.md) [CDockablePane](../Topic/CDockablePane%20Class.md)  
  
 [CDockablePaneAdapter](../../mfc/reference/cdockablepaneadapter-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxDockablePaneAdapter.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CDockablePane](../Topic/CDockablePane%20Class.md)