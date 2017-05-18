---
title: 'Mensagens WM _: S | Documentos do Microsoft'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ON_WM_SYSDEADCHAR
- ON_WM_SYSKEYDOWN
- ON_WM_STYLECHANGING
- ON_WM_STYLECHANGED
- ON_WM_SPOOLERSTATUS
- ON_WM_SYSCHAR
- ON_WM_SETFOCUS
- ON_WM_SIZE
- ON_WM_SIZING
- ON_WM_SETCURSOR
- ON_WM_SYSCOMMAND
- ON_WM_SETTINGCHANGE
- ON_WM_SHOWWINDOW
- ON_WM_SYSKEYUP
- ON_WM_SIZECLIPBOARD
- ON_WM_SYSCOLORCHANGE
dev_langs:
- C++
helpviewer_keywords:
- ON_WM_SIZE
- ON_WM_SETFOCUS
- ON_WM_SIZING
- ON_WM_SYSCHAR
- ON_WM_SETTINGCHANGE
- ON_WM_SYSDEADCHAR
- ON_WM_SHOWWINDOW
- ON_WM_STYLECHANGING
- ON_WM_SYSCOMMAND
- ON_WM_STYLECHANGED
- ON_WM_SPOOLERSTATUS
- ON_WM_SYSCOLORCHANGE
- ON_WM_SETCURSOR
- ON_WM_SIZECLIPBOARD
- ON_WM_SYSKEYUP
- ON_WM_SYSKEYDOWN
- WM_ messages
ms.assetid: 4b9aec79-a98f-4aa0-a3d9-110941b6dcbc
caps.latest.revision: 14
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
ms.openlocfilehash: 339b03be41187ad0249ae38d36d4640401247a83
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="wm-messages-s"></a>Mensagens WM_: S
As seguintes entradas de mapa correspondem aos protótipos de função.  
  
|Entrada de mapa|Protótipo da função|  
|---------------|------------------------|  
|(ON_WM_SETCURSOR)|BOOL afx_msg [OnSetCursor](../../mfc/reference/cwnd-class.md#onsetcursor)(CWnd *, UINT, UINT);|  
|(ON_WM_SETFOCUS)|void afx_msg [OnSetFocus](../../mfc/reference/cwnd-class.md#onsetfocus)(CWnd *);|  
|(ON_WM_SETTINGCHANGE)|void afx_msg [OnSettingChange](../../mfc/reference/cwnd-class.md#onsettingchange)(UINT uFlags, LPCTSTR lpszSection);|  
|(ON_WM_SHOWWINDOW)|void afx_msg [OnShowWindow](../../mfc/reference/cwnd-class.md#onshowwindow)(BOOL, UINT);|  
|(ON_WM_SIZE)|void afx_msg [OnSize](../../mfc/reference/cwnd-class.md#onsize)(UINT, int, int);|  
|(ON_WM_SIZECLIPBOARD)|void afx_msg [OnSizeClipboard](../../mfc/reference/cwnd-class.md#onsizeclipboard)(CWnd *, identificador);|  
|(ON_WM_SIZING)|void afx_msg [OnSizing](../../mfc/reference/cwnd-class.md#onsizing)(UINT, LPRECT);|  
|(ON_WM_SPOOLERSTATUS)|void afx_msg [OnSpoolerStatus](../../mfc/reference/cwnd-class.md#onspoolerstatus)(UINT, UINT);|  
|(ON_WM_STYLECHANGED)|void afx_msg [OnStyleChanged](../../mfc/reference/cwnd-class.md#onstylechanged)(int, LPSTYLESTRUCT);|  
|(ON_WM_STYLECHANGING)|void afx_msg [OnStyleChanging](../../mfc/reference/cwnd-class.md#onstylechanging)(int, LPSTYLESTRUCT);|  
|(ON_WM_SYSCHAR)|void afx_msg [OnSysChar](../../mfc/reference/cwnd-class.md#onsyschar)(UINT, UINT, UINT);|  
|(ON_WM_SYSCOLORCHANGE)|void afx_msg [OnSysColorChange](../../mfc/reference/cwnd-class.md#onsyscolorchange)();|  
|(ON_WM_SYSCOMMAND)|void afx_msg [OnSysCommand](../../mfc/reference/cwnd-class.md#onsyscommand)(UINT, LONG);|  
|(ON_WM_SYSDEADCHAR)|void afx_msg [OnSysDeadChar](../../mfc/reference/cwnd-class.md#onsysdeadchar)(UINT, UINT, UINT);|  
|(ON_WM_SYSKEYDOWN)|void afx_msg [OnSysKeyDown](../../mfc/reference/cwnd-class.md#onsyskeydown)(UINT, UINT, UINT);|  
|(ON_WM_SYSKEYUP)|void afx_msg [OnSysKeyUp](../../mfc/reference/cwnd-class.md#onsyskeyup)(UINT, UINT, UINT);|  
  
## <a name="see-also"></a>Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM _](../../mfc/reference/handlers-for-wm-messages.md)


