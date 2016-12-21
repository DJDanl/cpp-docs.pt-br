---
title: "Mensagens WM_: T - Z | Microsoft Docs"
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
  - "ON_WM_TCARD"
  - "ON_WM_WININICHANGE"
  - "ON_WM_VSCROLLCLIPBOARD"
  - "ON_WM_VSCROLL"
  - "ON_WM_WINDOWPOSCHANGED"
  - "ON_WM_TIMECHANGE"
  - "ON_WM_TIMER"
  - "ON_WM_VKEYTOITEM"
  - "ON_WM_WINDOWPOSCHANGING"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ON_WM_TCARD"
  - "ON_WM_TIMECHANGE"
  - "ON_WM_TIMER"
  - "ON_WM_VKEYTOITEM"
  - "ON_WM_VSCROLL"
  - "ON_WM_VSCROLLCLIPBOARD"
  - "ON_WM_WINDOWPOSCHANGED"
  - "ON_WM_WINDOWPOSCHANGING"
  - "ON_WM_WININICHANGE"
  - "Mensagens WM_"
ms.assetid: c528bb2e-ddb5-4da6-b652-432a387408b8
caps.latest.revision: 16
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mensagens WM_: T - Z
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As entradas de mapa correspondem a seguir protótipos de função:  
  
|Entrada do mapa|Protótipo de função|  
|---------------------|-------------------------|  
|ON\_WM\_TCARD\(\)|afx\_msg [OnTCard](../Topic/CWnd::OnTCard.md)nulo \(UINT, DWORD\);|  
|ON\_WM\_TIMECHANGE\(\)|afx\_msg [OnTimeChange](../Topic/CWnd::OnTimeChange.md)nulo \(\);|  
|ON\_WM\_TIMER\(\)|afx\_msg [OnTimer](../Topic/CWnd::OnTimer.md)nulo \(UINT\_PTR\);|  
|ON\_WM\_UNICHAR\(\)|afx\_msg [OnUniChar](../Topic/CWnd::OnUniChar.md)nulo \(UINT, UINT, UINT\);|  
|ON\_WM\_UNINITMENUPOPUP\(\)|afx\_msg [OnUnInitMenuPopup](../Topic/CWnd::OnUnInitMenuPopup.md)nulo \(CMenu\*, UINT\);|  
|ON\_WM\_USERCHANGED\(\)|afx\_msg [OnUserChanged](../Topic/CWnd::OnUserChanged.md)nulo \(\);|  
|ON\_WM\_VKEYTOITEM\(\)|afx\_msg int [OnVKeyToItem](../Topic/CWnd::OnVKeyToItem.md)\(UINT, CWnd\*, UINT\);|  
|ON\_WM\_VSCROLL\(\)|afx\_msg [OnVScroll](../Topic/CWnd::OnVScroll.md)nulo \(UINT, UINT, CWnd\*\);|  
|ON\_WM\_VSCROLLCLIPBOARD\(\)|afx\_msg [OnVScrollClipboard](../Topic/CWnd::OnVScrollClipboard.md)nulo \(CWnd\*, UINT, UINT\);|  
|ON\_WM\_WINDOWPOSCHANGED\(\)|afx\_msg [OnWindowPosChanged](../Topic/CWnd::OnWindowPosChanged.md)nulo \(WINDOWPOS\*\);|  
|ON\_WM\_WINDOWPOSCHANGING\(\)|afx\_msg [OnWindowPosChanging](../Topic/CWnd::OnWindowPosChanging.md)nulo \(WINDOWPOS\*\);|  
|ON\_WM\_WININICHANGE\(\)|afx\_msg [OnWinIniChange](../Topic/CWnd::OnWinIniChange.md)nulo \(LPSTR\);|  
|ON\_WM\_WTSSESSION\_CHANGE\(\)|afx\_msg [OnSessionChange](../Topic/CWnd::OnSessionChange.md)nulo \(UINT, UINT\);|  
|ON\_WM\_XBUTTONDBLCLK\(\)|afx\_msg [OnXButtonDblClk](../Topic/CWnd::OnXButtonDblClk.md)nulo \(UINT, UINT, CPoint\);|  
|ON\_WM\_XBUTTONDOWN\(\)|afx\_msg [OnXButtonDown](../Topic/CWnd::OnXButtonDown.md)nulo \(UINT, UINT, CPoint\);|  
|ON\_WM\_XBUTTONUP\(\)|afx\_msg [OnXButtonUp](../Topic/CWnd::OnXButtonUp.md)nulo \(UINT, UINT, CPoint\);|  
  
## Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM\_](../../mfc/reference/handlers-for-wm-messages.md)