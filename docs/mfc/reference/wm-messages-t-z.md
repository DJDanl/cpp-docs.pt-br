---
title: 'Mensagens WM _: T - Z | Documentos do Microsoft'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ON_WM_TCARD
- ON_WM_WININICHANGE
- ON_WM_VSCROLLCLIPBOARD
- ON_WM_VSCROLL
- ON_WM_WINDOWPOSCHANGED
- ON_WM_TIMECHANGE
- ON_WM_TIMER
- ON_WM_VKEYTOITEM
- ON_WM_WINDOWPOSCHANGING
dev_langs:
- C++
helpviewer_keywords:
- ON_WM_VSCROLLCLIPBOARD
- ON_WM_WININICHANGE
- ON_WM_WINDOWPOSCHANGED
- ON_WM_TCARD
- ON_WM_TIMECHANGE
- ON_WM_TIMER
- WM_ messages
- ON_WM_WINDOWPOSCHANGING
- ON_WM_VKEYTOITEM
- ON_WM_VSCROLL
ms.assetid: c528bb2e-ddb5-4da6-b652-432a387408b8
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: ff57d827dbb00afbe962385c74d7c2144335a073
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="wm-messages-t---z"></a>Mensagens WM_: T - Z
As seguintes entradas de mapa correspondem aos protótipos de função:  
  
|Entrada de mapa|Protótipo da função|  
|---------------|------------------------|  
|ON_WM_TCARD()|void afx_msg [OnTCard](../../mfc/reference/cwnd-class.md#ontcard)(UINT, DWORD);|  
|ON_WM_TIMECHANGE()|void afx_msg [OnTimeChange](../../mfc/reference/cwnd-class.md#ontimechange)();|  
|ON_WM_TIMER()|void afx_msg [OnTimer](../../mfc/reference/cwnd-class.md#ontimer)(UINT_PTR);|  
|ON_WM_UNICHAR()|void afx_msg [OnUniChar](../../mfc/reference/cwnd-class.md#onunichar)(UINT, UINT, UINT);|  
|ON_WM_UNINITMENUPOPUP()|void afx_msg [OnUnInitMenuPopup](../../mfc/reference/cwnd-class.md#onuninitmenupopup)(CMenu *, UINT);|  
|ON_WM_USERCHANGED()|void afx_msg [OnUserChanged](../../mfc/reference/cwnd-class.md#onuserchanged)();|  
|ON_WM_VKEYTOITEM()|int afx_msg [OnVKeyToItem](../../mfc/reference/cwnd-class.md#onvkeytoitem)(UINT, CWnd *, UINT);|  
|ON_WM_VSCROLL()|void afx_msg [OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll)(UINT, UINT, CWnd *);|  
|ON_WM_VSCROLLCLIPBOARD()|void afx_msg [OnVScrollClipboard](../../mfc/reference/cwnd-class.md#onvscrollclipboard)(CWnd *, UINT, UINT);|  
|ON_WM_WINDOWPOSCHANGED()|void afx_msg [OnWindowPosChanged](../../mfc/reference/cwnd-class.md#onwindowposchanged)(WINDOWPOS *);|  
|ON_WM_WINDOWPOSCHANGING()|void afx_msg [OnWindowPosChanging](../../mfc/reference/cwnd-class.md#onwindowposchanging)(WINDOWPOS *);|  
|ON_WM_WININICHANGE()|void afx_msg [OnWinIniChange](../../mfc/reference/cwnd-class.md#onwininichange)(LPSTR);|  
|ON_WM_WTSSESSION_CHANGE()|void afx_msg [OnSessionChange](../../mfc/reference/cwnd-class.md#onsessionchange)(UINT, UINT);|  
|ON_WM_XBUTTONDBLCLK()|void afx_msg [OnXButtonDblClk](../../mfc/reference/cwnd-class.md#onxbuttondblclk)(UINT, UINT, CPoint);|  
|ON_WM_XBUTTONDOWN()|void afx_msg [OnXButtonDown](../../mfc/reference/cwnd-class.md#onxbuttondown)(UINT, UINT, CPoint);|  
|ON_WM_XBUTTONUP()|void afx_msg [OnXButtonUp](../../mfc/reference/cwnd-class.md#onxbuttonup)(UINT, UINT, CPoint);|  
  
## <a name="see-also"></a>Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM _](../../mfc/reference/handlers-for-wm-messages.md)


