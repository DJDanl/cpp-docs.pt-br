---
title: "Manipuladores de mensagens WM_: A - C | Microsoft Docs"
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
  - "ON_WM_CREATE"
  - "ON_WM_COMPACTING"
  - "ON_WM_CHARTOITEM"
  - "ON_WM_ASKCBFORMATNAME"
  - "ON_WM_CTLCOLOR"
  - "ON_WM_COMPAREITEM"
  - "ON_WM_CHILDACTIVATE"
  - "ON_WM_CONTEXTMENU"
  - "ON_WM_ACTIVATE"
  - "ON_WM_CANCELMODE"
  - "ON_WM_CLOSE"
  - "ON_WM_CAPTURECHANGED"
  - "ON_WM_ACTIVATEAPP"
  - "ON_WM_CHAR"
  - "ON_WM_CHANGECBCHAIN"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ON_WM_ACTIVATE"
  - "ON_WM_ACTIVATEAPP"
  - "ON_WM_ASKCBFORMATNAME"
  - "ON_WM_CANCELMODE"
  - "ON_WM_CAPTURECHANGED"
  - "ON_WM_CHANGECBCHAIN"
  - "ON_WM_CHAR"
  - "ON_WM_CHARTOITEM"
  - "ON_WM_CHILDACTIVATE"
  - "ON_WM_CLOSE"
  - "ON_WM_COMPACTING"
  - "ON_WM_COMPAREITEM"
  - "ON_WM_CONTEXTMENU"
  - "ON_WM_CREATE"
  - "ON_WM_CTLCOLOR"
  - "Mensagens WM_"
ms.assetid: 4e315896-d646-4b87-b0ab-41a4a753b045
caps.latest.revision: 16
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores de mensagens WM_: A - C
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As entradas de mapa seguinte à esquerda correspondem a protótipos de função à direita:  
  
|Entrada do mapa|Protótipo de função|  
|---------------------|-------------------------|  
|ON\_WM\_ACTIVATE\(\)|afx\_msg [OnActivate](../Topic/CWnd::OnActivate.md)nulo \(UINT, CWnd\*, BOOL\);|  
|ON\_WM\_ACTIVATEAPP\(\)|afx\_msg [OnActivateApp](../Topic/CWnd::OnActivateApp.md)nulo \(BOOL, DWORD\);|  
|ON\_WM\_APPCOMMAND\(\)|afx\_msg [OnAppCommand](../Topic/CWnd::OnAppCommand.md)nulo \(CWnd\*, UINT, UINT, UINT\);|  
|ON\_WM\_ASKCBFORMATNAME\(\)|afx\_msg [OnAskCbFormatName](../Topic/CWnd::OnAskCbFormatName.md)nulo \(UINT, LPSTR\);|  
|ON\_WM\_CANCELMODE\(\)|afx\_msg [OnCancelMode](../Topic/CWnd::OnCancelMode.md)nulo \(\);|  
|ON\_WM\_CAPTURECHANGED\(\)|afx\_msg [OnCaptureChanged](../Topic/CWnd::OnCaptureChanged.md)nulo \(CWnd\*\);|  
|ON\_WM\_CHANGECBCHAIN\(\)|afx\_msg [OnChangeCbChain](../Topic/CWnd::OnChangeCbChain.md)nulo \(HWND, HWND\);|  
|ON\_WM\_CHAR\(\)|afx\_msg [OnChar](../Topic/CWnd::OnChar.md)nulo \(UINT, UINT, UINT\);|  
|ON\_WM\_CHARTOITEM\(\)|afx\_msg int [OnCharToItem](../Topic/CWnd::OnCharToItem.md)\(UINT, CWnd\*, UINT\);|  
|ON\_WM\_CHILDACTIVATE\(\)|afx\_msg [OnChildActivate](../Topic/CWnd::OnChildActivate.md)nulo \(\);|  
|ON\_WM\_CLIPBOARDUPDATE\(\)|afx\_msg [OnClipboardUpdate](../Topic/CWnd::OnClipboardUpdate.md)nulo \(\);|  
|ON\_WM\_CLOSE\(\)|afx\_msg [OnClose](../Topic/CWnd::OnClose.md)nulo \(\);|  
|ON\_WM\_COMPACTING\(\)|afx\_msg [OnCompacting](../Topic/CWnd::OnCompacting.md)nulo \(UINT\);|  
|ON\_WM\_COMPAREITEM\(\)|afx\_msg int [OnCompareItem](../Topic/CWnd::OnCompareItem.md)\(LPCOMPAREITEMSTRUCT\);|  
|ON\_WM\_CONTEXTMENU\(\)|afx\_msg [OnContextMenu](../Topic/CWnd::OnContextMenu.md)nulo \(CWnd\*, CPoint\);|  
|ON\_WM\_COPYDATA\(\)|afx\_msg BOOL [OnCopyData](../Topic/CWnd::OnCopyData.md)\(pWnd de CWnd\*, pCopyDataStruct de COPYDATASTRUCT\*\);|  
|ON\_WM\_CREATE\(\)|afx\_msg int [OnCreate](../Topic/CWnd::OnCreate.md)\(LPCREATESTRUCT\);|  
|ON\_WM\_CTLCOLOR\(\)|afx\_msg HBRUSH [OnCtlColor](../Topic/CWnd::OnCtlColor.md)\(CDC\*, CWnd\*, UINT\);|  
  
## Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM\_](../../mfc/reference/handlers-for-wm-messages.md)