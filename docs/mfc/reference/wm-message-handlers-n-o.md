---
title: "Manipuladores de mensagens WM_: N - O | Microsoft Docs"
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
  - "ON_WM_NCHITTEST"
  - "ON_WM_NCLBUTTONDOWN"
  - "ON_WM_NCCALCSIZE"
  - "ON_WM_NCLBUTTONUP"
  - "ON_WM_NCPAINT"
  - "ON_WM_NCMBUTTONUP"
  - "ON_WM_NCCREATE"
  - "ON_WM_NCACTIVATE"
  - "ON_WM_NCMOUSEMOVE"
  - "ON_WM_NCRBUTTONDBLCLK"
  - "ON_WM_NCLBUTTONDBLCLK"
  - "ON_WM_NCDESTROY"
  - "ON_WM_NCMBUTTONDBLCLK"
  - "ON_WM_NCRBUTTONDOWN"
  - "ON_WM_NCRBUTTONUP"
  - "ON_WM_NCMBUTTONDOWN"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ON_WM_NCACTIVATE"
  - "ON_WM_NCCALCSIZE"
  - "ON_WM_NCCREATE"
  - "ON_WM_NCDESTROY"
  - "ON_WM_NCHITTEST"
  - "ON_WM_NCLBUTTONDBLCLK"
  - "ON_WM_NCLBUTTONDOWN"
  - "ON_WM_NCLBUTTONUP"
  - "ON_WM_NCMBUTTONDBLCLK"
  - "ON_WM_NCMBUTTONDOWN"
  - "ON_WM_NCMBUTTONUP"
  - "ON_WM_NCMOUSEMOVE"
  - "ON_WM_NCPAINT"
  - "ON_WM_NCRBUTTONDBLCLK"
  - "ON_WM_NCRBUTTONDOWN"
  - "ON_WM_NCRBUTTONUP"
  - "Mensagens WM_"
ms.assetid: 4efd1cda-b642-4e8b-89e8-73255fa70d77
caps.latest.revision: 17
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores de mensagens WM_: N - O
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As entradas de mapa seguinte à esquerda correspondem a protótipos de função à direita:  
  
|Entrada do mapa|Protótipo de função|  
|---------------------|-------------------------|  
|ON\_WM\_NCACTIVATE\(\)|afx\_msg BOOL [OnNcActivate](../Topic/CWnd::OnNcActivate.md)\(BOOL\);|  
|ON\_WM\_NCCALCSIZE\(\)|afx\_msg [OnNcCalcSize](../Topic/CWnd::OnNcCalcSize.md)nulo \(BOOL, NCCALCSIZE\_PARAMS FAR\*\);|  
|ON\_WM\_NCCREATE\(\)|afx\_msg BOOL [OnNcCreate](../Topic/CWnd::OnNcCreate.md)\(LPCREATESTRUCT\);|  
|ON\_WM\_NCDESTROY\(\)|afx\_msg [OnNcDestroy](../Topic/CWnd::OnNcDestroy.md)nulo \(\);|  
|ON\_WM\_NCHITTEST\(\)|afx\_msg LRESULT [OnNcHitTest](../Topic/CWnd::OnNcHitTest.md)\(CPoint\);|  
|ON\_WM\_NCLBUTTONDBLCLK\(\)|afx\_msg [OnNcLButtonDblClk](../Topic/CWnd::OnNcLButtonDblClk.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_NCLBUTTONDOWN\(\)|afx\_msg [OnNcLButtonDown](../Topic/CWnd::OnNcLButtonDown.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_NCLBUTTONUP\(\)|afx\_msg [OnNcLButtonUp](../Topic/CWnd::OnNcLButtonUp.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_NCMBUTTONDBLCLK\(\)|afx\_msg [OnNcMButtonDblClk](../Topic/CWnd::OnNcMButtonDblClk.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_NCMBUTTONDOWN\(\)|afx\_msg [OnNcMButtonDown](../Topic/CWnd::OnNcMButtonDown.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_NCMBUTTONUP\(\)|afx\_msg [OnNcMButtonUp](../Topic/CWnd::OnNcMButtonUp.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_NCMOUSEHOVER\(\)|afx\_msg [OnNcMouseHover](../Topic/CWnd::OnNcMouseHover.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_NCMOUSELEAVE\(\)|afx\_msg [OnNcMouseLeave](../Topic/CWnd::OnNcMouseLeave.md)nulo \(\);|  
|ON\_WM\_NCMOUSEMOVE\(\)|afx\_msg [OnNcMouseMove](../Topic/CWnd::OnNcMouseMove.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_NCPAINT\(\)|afx\_msg [OnNcPaint](../Topic/CWnd::OnNcPaint.md)nulo \(\);|  
|ON\_WM\_NCRBUTTONDBLCLK\(\)|afx\_msg [OnNcRButtonDblClk](../Topic/CWnd::OnNcRButtonDblClk.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_NCRBUTTONDOWN\(\)|afx\_msg [OnNcRButtonDown](../Topic/CWnd::OnNcRButtonDown.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_NCRBUTTONUP\(\)|afx\_msg [OnNcRButtonUp](../Topic/CWnd::OnNcRButtonUp.md)nulo \(UINT, CPoint\);|  
|ON\_WM\_NCXBUTTONDBLCLK\(\)|[OnNcXButtonDblClk](../Topic/CWnd::OnNcXButtonDblClk.md)nulo \(curto, UINT, CPoint\);|  
|ON\_WM\_NCXBUTTONDOWN\(\)|afx\_msg [OnNcXButtonDown](../Topic/CWnd::OnNcXButtonDown.md)nulo \(curto, UINT, CPoint\);|  
|ON\_WM\_NCXBUTTONUP\(\)|afx\_msg [OnNcXButtonUp](../Topic/CWnd::OnNcXButtonUp.md)nulo \(curto, UINT, CPoint\);|  
|ON\_WM\_NEXTMENU\(\)|afx\_msg [OnNextMenu](../Topic/CWnd::OnNextMenu.md)nulo \(UINT, LPMDINEXTMENU\);|  
|ON\_WM\_NOTIFYFORMAT\(\)|afx\_msg UINT [OnNotifyFormat](../Topic/CWnd::OnNotifyFormat.md)\(CWnd\*, UINT\);|  
  
## Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM\_](../../mfc/reference/handlers-for-wm-messages.md)