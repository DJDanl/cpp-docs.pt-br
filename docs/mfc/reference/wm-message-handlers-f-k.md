---
title: "Manipuladores de mensagens WM_: F - K | Microsoft Docs"
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
  - "ON_WM_FONTCHANGE"
  - "ON_WM_ICONERASEBKGND"
  - "ON_WM_KEYDOWN"
  - "ON_WM_GETMINMAXINFO"
  - "ON_WM_KEYUP"
  - "ON_WM_HSCROLL"
  - "ON_WM_KILLFOCUS"
  - "ON_WM_HSCROLLCLIPBOARD"
  - "ON_WM_GETDLGCODE"
  - "ON_WM_HELPINFO"
  - "ON_WM_INITMENUPOPUP"
  - "ON_WM_INITMENU"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ON_WM_FONTCHANGE"
  - "ON_WM_GETDLGCODE"
  - "ON_WM_GETMINMAXINFO"
  - "ON_WM_HELPINFO"
  - "ON_WM_HSCROLL"
  - "ON_WM_HSCROLLCLIPBOARD"
  - "ON_WM_ICONERASEBKGND"
  - "ON_WM_INITMENU"
  - "ON_WM_INITMENUPOPUP"
  - "ON_WM_KEYDOWN"
  - "ON_WM_KEYUP"
  - "ON_WM_KILLFOCUS"
  - "Mensagens WM_"
ms.assetid: 0e7de191-1499-499f-859c-62742797808e
caps.latest.revision: 15
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores de mensagens WM_: F - K
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As entradas de mapa seguinte à esquerda correspondem a protótipos de função à direita:  
  
|Entrada do mapa|Protótipo de função|  
|---------------------|-------------------------|  
|ON\_WM\_FONTCHANGE\(\)|afx\_msg [OnFontChange](../Topic/CWnd::OnFontChange.md)nulo \(\);|  
|ON\_WM\_GETDLGCODE\(\)|afx\_msg UINT [OnGetDlgCode](../Topic/CWnd::OnGetDlgCode.md)\(\);|  
|ON\_WM\_GETMINMAXINFO\(\)|afx\_msg [OnGetMinMaxInfo](../Topic/CWnd::OnGetMinMaxInfo.md)nulo \(LPPOINT\);|  
|ON\_WM\_HELPINFO\(\)|afx\_msg BOOL [OnHelpInfo](../Topic/CWnd::OnHelpInfo.md)\(HELPINFO\*\);|  
|ON\_WM\_HOTKEY\(\)|afx\_msg [OnHotKey](../Topic/CWnd::OnHotKey.md)nulo \(UINT, UINT, UINT\);|  
|ON\_WM\_HSCROLL\(\)|afx\_msg [OnHScroll](../Topic/CWnd::OnHScroll.md)nulo \(UINT, UINT, CWnd\*\);|  
|ON\_WM\_HSCROLLCLIPBOARD\(\)|afx\_msg [OnHScrollClipboard](../Topic/CWnd::OnHScrollClipboard.md)nulo \(CWnd\*, UINT, UINT\);|  
|ON\_WM\_ICONERASEBKGND\(\)|afx\_msg [OnIconEraseBkgnd](../Topic/CWnd::OnIconEraseBkgnd.md)nulo \(CDC\*\);|  
|ON\_WM\_INITMENU\(\)|afx\_msg [OnInitMenu](../Topic/CWnd::OnInitMenu.md)nulo \(CMenu\*\);|  
|ON\_WM\_INITMENUPOPUP\(\)|afx\_msg [OnInitMenuPopup](../Topic/CWnd::OnInitMenuPopup.md)nulo \(CMenu\*, UINT, BOOL\);|  
|ON\_WM\_INPUT\(\)|afx\_msg [OnRawInput](../Topic/CWnd::OnRawInput.md)nulo \(UINT, HRAWINPUT\);|  
|ON\_WM\_INPUT\_DEVICE\_CHANGE\(\)|afx\_msg [OnInputDeviceChange](../Topic/CWnd::OnInputDeviceChange.md)nulo \(unsigned short\);|  
|ON\_WM\_INPUTLANGCHANGE\(\)|afx\_msg [OnInputLangChange](../Topic/CWnd::OnInputLangChange.md)nulo \(BYTE, UINT\);|  
|ON\_WM\_INPUTLANGCHANGEREQUEST\(\)|afx\_msg [OnInputLangChangeRequest](../Topic/CWnd::OnInputLangChangeRequest.md)nulo \(UINT, HKL\);|  
|ON\_WM\_KEYDOWN\(\)|afx\_msg [OnKeyDown](../Topic/CWnd::OnKeyDown.md)nulo \(UINT, UINT, UINT\);|  
|ON\_WM\_KEYUP\(\)|afx\_msg [OnKeyUp](../Topic/CWnd::OnKeyUp.md)nulo \(UINT, UINT, UINT\);|  
|ON\_WM\_KILLFOCUS\(\)|afx\_msg [OnKillFocus](../Topic/CWnd::OnKillFocus.md)nulo \(CWnd\*\);|  
  
## Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM\_](../../mfc/reference/handlers-for-wm-messages.md)