---
title: 'Manipuladores de mensagens WM _: A - C | Documentos do Microsoft'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ON_WM_CREATE
- ON_WM_COMPACTING
- ON_WM_CHARTOITEM
- ON_WM_ASKCBFORMATNAME
- ON_WM_CTLCOLOR
- ON_WM_COMPAREITEM
- ON_WM_CHILDACTIVATE
- ON_WM_CONTEXTMENU
- ON_WM_ACTIVATE
- ON_WM_CANCELMODE
- ON_WM_CLOSE
- ON_WM_CAPTURECHANGED
- ON_WM_ACTIVATEAPP
- ON_WM_CHAR
- ON_WM_CHANGECBCHAIN
dev_langs:
- C++
helpviewer_keywords:
- ON_WM_COMPACTING
- ON_WM_COMPAREITEM
- ON_WM_CLOSE
- ON_WM_CTLCOLOR
- ON_WM_CHAR
- ON_WM_CAPTURECHANGED
- ON_WM_CHARTOITEM
- ON_WM_CREATE
- ON_WM_ACTIVATE
- ON_WM_CONTEXTMENU
- ON_WM_CANCELMODE
- ON_WM_ASKCBFORMATNAME
- ON_WM_CHILDACTIVATE
- WM_ messages
- ON_WM_ACTIVATEAPP
- ON_WM_CHANGECBCHAIN
ms.assetid: 4e315896-d646-4b87-b0ab-41a4a753b045
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 4b8a6b0527758e8eff8f2ab3ece4a69927176e2c
ms.lasthandoff: 02/25/2017

---
# <a name="wm-message-handlers-a---c"></a>Manipuladores de mensagens WM_: A - C
As seguintes entradas de mapa à esquerda correspondem aos protótipos de função à direita:  
  
|Entrada de mapa|Protótipo da função|  
|---------------|------------------------|  
|ON_WM_ACTIVATE()|void afx_msg [AoAtivar](../../mfc/reference/cwnd-class.md#onactivate)(UINT, CWnd *, BOOL);|  
|ON_WM_ACTIVATEAPP()|void afx_msg [OnActivateApp](../../mfc/reference/cwnd-class.md#onactivateapp)(BOOL, DWORD);|  
|ON_WM_APPCOMMAND()|void afx_msg [OnAppCommand](../../mfc/reference/cwnd-class.md#onappcommand)(CWnd *, UINT, UINT, UINT);|  
|ON_WM_ASKCBFORMATNAME()|void afx_msg [OnAskCbFormatName](../../mfc/reference/cwnd-class.md#onaskcbformatname)(UINT, LPSTR);|  
|ON_WM_CANCELMODE()|void afx_msg [OnCancelMode](../../mfc/reference/cwnd-class.md#oncancelmode)();|  
|ON_WM_CAPTURECHANGED()|void afx_msg [OnCaptureChanged](../../mfc/reference/cwnd-class.md#oncapturechanged)(CWnd *);|  
|ON_WM_CHANGECBCHAIN()|void afx_msg [OnChangeCbChain](../../mfc/reference/cwnd-class.md#onchangecbchain)(HWND, HWND);|  
|ON_WM_CHAR()|void afx_msg [OnChar](../../mfc/reference/cwnd-class.md#onchar)(UINT, UINT, UINT);|  
|ON_WM_CHARTOITEM()|int afx_msg [OnCharToItem](../../mfc/reference/cwnd-class.md#onchartoitem)(UINT, CWnd *, UINT);|  
|ON_WM_CHILDACTIVATE()|void afx_msg [OnChildActivate](../../mfc/reference/cwnd-class.md#onchildactivate)();|  
|ON_WM_CLIPBOARDUPDATE()|void afx_msg [OnClipboardUpdate](../../mfc/reference/cwnd-class.md#onclipboardupdate)();|  
|ON_WM_CLOSE()|void afx_msg [OnClose](../../mfc/reference/cwnd-class.md#onclose)();|  
|ON_WM_COMPACTING()|void afx_msg [OnCompacting](../../mfc/reference/cwnd-class.md#oncompacting)(UINT);|  
|ON_WM_COMPAREITEM()|int afx_msg [OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem)(LPCOMPAREITEMSTRUCT);|  
|ON_WM_CONTEXTMENU()|void afx_msg [OnContextMenu](../../mfc/reference/cwnd-class.md#oncontextmenu)(CWnd *, CPoint);|  
|ON_WM_COPYDATA()|BOOL afx_msg [OnCopyData](../../mfc/reference/cwnd-class.md#oncopydata)(CWnd * Apropriei, COPYDATASTRUCT\* pCopyDataStruct);|  
|ON_WM_CREATE()|int afx_msg [OnCreate](../../mfc/reference/cwnd-class.md#oncreate)(LPCREATESTRUCT);|  
|ON_WM_CTLCOLOR()|afx_msg HBRUSH [OnCtlColor](../../mfc/reference/cwnd-class.md#onctlcolor)(CDC *, CWnd\*, UINT);|  
  
## <a name="see-also"></a>Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM _](../../mfc/reference/handlers-for-wm-messages.md)


