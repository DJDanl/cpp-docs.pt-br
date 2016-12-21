---
title: "Manipuladores de mensagens WM_: L - M | Microsoft Docs"
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
  - "ON_WM_MENUSELECT"
  - "ON_WM_MBUTTONDBLCLK"
  - "ON_WM_MOUSEACTIVATE"
  - "ON_WM_MOUSEMOVE"
  - "ON_WM_MOVING"
  - "ON_WM_LBUTTONUP"
  - "ON_WM_LBUTTONDBLCLK"
  - "ON_WM_MEASUREITEM"
  - "ON_WM_MDIACTIVATE"
  - "ON_WM_MOVE"
  - "ON_WM_LBUTTONDOWN"
  - "ON_WM_MBUTTONDOWN"
  - "ON_WM_MENUCHAR"
  - "ON_WM_MBUTTONUP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ON_WM_LBUTTONDBLCLK"
  - "ON_WM_LBUTTONDOWN"
  - "ON_WM_LBUTTONUP"
  - "ON_WM_MBUTTONDBLCLK"
  - "ON_WM_MBUTTONDOWN"
  - "ON_WM_MBUTTONUP"
  - "ON_WM_MDIACTIVATE"
  - "ON_WM_MEASUREITEM"
  - "ON_WM_MENUCHAR"
  - "ON_WM_MENUSELECT"
  - "ON_WM_MOUSEACTIVATE"
  - "ON_WM_MOUSEMOVE"
  - "ON_WM_MOVE"
  - "ON_WM_MOVING"
  - "Mensagens WM_"
ms.assetid: 96ecaaf1-6d13-4e12-a454-535635967489
caps.latest.revision: 15
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores de mensagens WM_: L - M
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As entradas de mapa seguinte à esquerda correspondem a protótipos de função à direita:  
  
|Entrada do mapa|Protótipo de função|  
|---------------------|-------------------------|  
|ON\_WM\_LBUTTONDBLCLK\(\)|afx\_msg [OnLButtonDblClk](../Topic/CWnd::OnLButtonDblClk.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_LBUTTONDOWN\(\)|afx\_msg [OnLButtonDown](../Topic/CWnd::OnLButtonDown.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_LBUTTONUP\(\)|afx\_msg [OnLButtonUp](../Topic/CWnd::OnLButtonUp.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_MBUTTONDBLCLK\(\)|afx\_msg [OnMButtonDblClk](../Topic/CWnd::OnMButtonDblClk.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_MBUTTONDOWN\(\)|afx\_msg [OnMButtonDown](../Topic/CWnd::OnMButtonDown.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_MBUTTONUP\(\)|afx\_msg [OnMButtonUp](../Topic/CWnd::OnMButtonUp.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_MDIACTIVATE\(\)|afx\_msg [OnMDIActivate](../Topic/CWnd::OnMDIActivate.md)nulo \(BOOL, CWnd\*, CWnd\*\);|  
|ON\_WM\_MEASUREITEM\(\)|afx\_msg [OnMeasureItem](../Topic/CWnd::OnMeasureItem.md)nulo \(LPMEASUREITEMSTRUCT\);|  
|ON\_WM\_MENUCHAR\(\)|afx\_msg [OnMenuChar](../Topic/CWnd::OnMenuChar.md)LONG \(UINT, UINT, CMenu\*\);|  
|ON\_WM\_MENUDRAG\(\)|afx\_msg UINT [OnMenuDrag](../Topic/CWnd::OnMenuDrag.md)\(UINT, CMenu\*\);|  
|ON\_WM\_MENUGETOBJECT\(\)|afx\_msg UINT [OnMenuGetObject](../Topic/CWnd::OnMenuGetObject.md)\(MENUGETOBJECTINFO\*\);|  
|ON\_WM\_MENURBUTTONUP\(\)|afx\_msg [OnMenuRButtonUp](../Topic/CWnd::OnMenuRButtonUp.md)nulo \(UINT, CMenu\*\);|  
|ON\_WM\_MENUSELECT\(\)|afx\_msg [OnMenuSelect](../Topic/CWnd::OnMenuSelect.md)nulo \(UINT, UINT, HMENU\);|  
|ON\_WM\_MOUSEACTIVATE\(\)|afx\_msg int [OnMouseActivate](../Topic/CWnd::OnMouseActivate.md)\(CWnd\*, UINT, UINT\);|  
|ON\_WM\_MOUSEHOVER\(\)|afx\_msg [OnMouseHover](../Topic/CWnd::OnMouseHover.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_MOUSEHWHEEL\(\)|afx\_msg [OnMouseHWheel](../Topic/CWnd::OnMouseHWheel.md)nulo \(UINT, curto, CPoint\);|  
|ON\_WM\_MOUSELEAVE\(\)|afx\_msg [OnMouseLeave](../Topic/CWnd::OnMouseLeave.md)nulo \(\);|  
|ON\_WM\_MOUSEMOVE\(\)|afx\_msg [OnMouseMove](../Topic/CWnd::OnMouseMove.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_MOUSEWHEEL\(\)|afx\_msg BOOL [OnMouseWheel](../Topic/CWnd::OnMouseWheel.md)\(UINT, curto, CPoint\);|  
|ON\_WM\_MOVE\(\)|afx\_msg [OnMove](../Topic/CWnd::OnMove.md)nulo \(int, int\);|  
|ON\_WM\_MOVING\(\)|afx\_msg [OnMoving](../Topic/CWnd::OnMoving.md)nulo \(UINT, LPRECT\);|  
  
## Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM\_](../../mfc/reference/handlers-for-wm-messages.md)