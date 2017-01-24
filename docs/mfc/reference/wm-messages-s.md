---
title: "Mensagens WM_: S | Microsoft Docs"
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
  - "ON_WM_SYSDEADCHAR"
  - "ON_WM_SYSKEYDOWN"
  - "ON_WM_STYLECHANGING"
  - "ON_WM_STYLECHANGED"
  - "ON_WM_SPOOLERSTATUS"
  - "ON_WM_SYSCHAR"
  - "ON_WM_SETFOCUS"
  - "ON_WM_SIZE"
  - "ON_WM_SIZING"
  - "ON_WM_SETCURSOR"
  - "ON_WM_SYSCOMMAND"
  - "ON_WM_SETTINGCHANGE"
  - "ON_WM_SHOWWINDOW"
  - "ON_WM_SYSKEYUP"
  - "ON_WM_SIZECLIPBOARD"
  - "ON_WM_SYSCOLORCHANGE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ON_WM_SETCURSOR"
  - "ON_WM_SETFOCUS"
  - "ON_WM_SETTINGCHANGE"
  - "ON_WM_SHOWWINDOW"
  - "ON_WM_SIZE"
  - "ON_WM_SIZECLIPBOARD"
  - "ON_WM_SIZING"
  - "ON_WM_SPOOLERSTATUS"
  - "ON_WM_STYLECHANGED"
  - "ON_WM_STYLECHANGING"
  - "ON_WM_SYSCHAR"
  - "ON_WM_SYSCOLORCHANGE"
  - "ON_WM_SYSCOMMAND"
  - "ON_WM_SYSDEADCHAR"
  - "ON_WM_SYSKEYDOWN"
  - "ON_WM_SYSKEYUP"
  - "Mensagens WM_"
ms.assetid: 4b9aec79-a98f-4aa0-a3d9-110941b6dcbc
caps.latest.revision: 14
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mensagens WM_: S
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As entradas de mapa correspondem a seguir protótipos de função.  
  
|Entrada do mapa|Protótipo de função|  
|---------------------|-------------------------|  
|ON\_WM\_SETCURSOR \(\)|afx\_msg BOOL [OnSetCursor](../Topic/CWnd::OnSetCursor.md)\(CWnd\*, UINT, UINT\);|  
|ON\_WM\_SETFOCUS \(\)|afx\_msg [OnSetFocus](../Topic/CWnd::OnSetFocus.md)nulo \(CWnd\*\);|  
|ON\_WM\_SETTINGCHANGE \(\)|afx\_msg [OnSettingChange](../Topic/CWnd::OnSettingChange.md)nulo \(uFlags de UINT, lpszSection de LPCTSTR\);|  
|ON\_WM\_SHOWWINDOW \(\)|afx\_msg [OnShowWindow](../Topic/CWnd::OnShowWindow.md)nulo \(BOOL, UINT\);|  
|ON\_WM\_SIZE \(\)|afx\_msg [OnSize](../Topic/CWnd::OnSize.md)nulo \(UINT, int, int\);|  
|ON\_WM\_SIZECLIPBOARD \(\)|afx\_msg [OnSizeClipboard](../Topic/CWnd::OnSizeClipboard.md)nulo \(CWnd\*, ALÇA\);|  
|ON\_WM\_SIZING \(\)|afx\_msg [OnSizing](../Topic/CWnd::OnSizing.md)nulo \(UINT, LPRECT\);|  
|ON\_WM\_SPOOLERSTATUS \(\)|afx\_msg [OnSpoolerStatus](../Topic/CWnd::OnSpoolerStatus.md)nulo \(UINT, UINT\);|  
|ON\_WM\_STYLECHANGED \(\)|afx\_msg [OnStyleChanged](../Topic/CWnd::OnStyleChanged.md)nulo \(int, LPSTYLESTRUCT\);|  
|ON\_WM\_STYLECHANGING \(\)|afx\_msg [OnStyleChanging](../Topic/CWnd::OnStyleChanging.md)nulo \(int, LPSTYLESTRUCT\);|  
|ON\_WM\_SYSCHAR \(\)|afx\_msg [OnSysChar](../Topic/CWnd::OnSysChar.md)nulo \(UINT, UINT, UINT\);|  
|ON\_WM\_SYSCOLORCHANGE \(\)|afx\_msg [OnSysColorChange](../Topic/CWnd::OnSysColorChange.md)nulo \(\);|  
|ON\_WM\_SYSCOMMAND \(\)|afx\_msg [OnSysCommand](../Topic/CWnd::OnSysCommand.md)nulo \(UINT, LONG\);|  
|ON\_WM\_SYSDEADCHAR \(\)|afx\_msg [OnSysDeadChar](../Topic/CWnd::OnSysDeadChar.md)nulo \(UINT, UINT, UINT\);|  
|ON\_WM\_SYSKEYDOWN \(\)|afx\_msg [OnSysKeyDown](../Topic/CWnd::OnSysKeyDown.md)nulo \(UINT, UINT, UINT\);|  
|ON\_WM\_SYSKEYUP \(\)|afx\_msg [OnSysKeyUp](../Topic/CWnd::OnSysKeyUp.md)nulo \(UINT, UINT, UINT\);|  
  
## Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM\_](../../mfc/reference/handlers-for-wm-messages.md)