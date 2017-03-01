---
title: 'Manipuladores de mensagens WM _: N - O | Documentos do Microsoft'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ON_WM_NCHITTEST
- ON_WM_NCLBUTTONDOWN
- ON_WM_NCCALCSIZE
- ON_WM_NCLBUTTONUP
- ON_WM_NCPAINT
- ON_WM_NCMBUTTONUP
- ON_WM_NCCREATE
- ON_WM_NCACTIVATE
- ON_WM_NCMOUSEMOVE
- ON_WM_NCRBUTTONDBLCLK
- ON_WM_NCLBUTTONDBLCLK
- ON_WM_NCDESTROY
- ON_WM_NCMBUTTONDBLCLK
- ON_WM_NCRBUTTONDOWN
- ON_WM_NCRBUTTONUP
- ON_WM_NCMBUTTONDOWN
dev_langs:
- C++
helpviewer_keywords:
- ON_WM_NCCALCSIZE
- ON_WM_NCMBUTTONDOWN
- ON_WM_NCRBUTTONDBLCLK
- ON_WM_NCMBUTTONDBLCLK
- ON_WM_NCLBUTTONDBLCLK
- ON_WM_NCDESTROY
- ON_WM_NCRBUTTONDOWN
- ON_WM_NCLBUTTONDOWN
- ON_WM_NCCREATE
- ON_WM_NCRBUTTONUP
- ON_WM_NCLBUTTONUP
- ON_WM_NCPAINT
- ON_WM_NCACTIVATE
- ON_WM_NCHITTEST
- ON_WM_NCMOUSEMOVE
- ON_WM_NCMBUTTONUP
- WM_ messages
ms.assetid: 4efd1cda-b642-4e8b-89e8-73255fa70d77
caps.latest.revision: 17
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
ms.openlocfilehash: f1e2a3a42c105e5f0e6d0fca714c5cd4d1216f2f
ms.lasthandoff: 02/25/2017

---
# <a name="wm-message-handlers-n---o"></a>Manipuladores de mensagens WM_: N - O
As seguintes entradas de mapa à esquerda correspondem aos protótipos de função à direita:  
  
|Entrada de mapa|Protótipo da função|  
|---------------|------------------------|  
|ON_WM_NCACTIVATE()|BOOL afx_msg [OnNcActivate](../../mfc/reference/cwnd-class.md#onncactivate)(BOOL);|  
|ON_WM_NCCALCSIZE()|void afx_msg [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize)(BOOL, NCCALCSIZE_PARAMS EXTREMO *);|  
|ON_WM_NCCREATE()|BOOL afx_msg [OnNcCreate](../../mfc/reference/cwnd-class.md#onnccreate)(LPCREATESTRUCT);|  
|ON_WM_NCDESTROY()|void afx_msg [OnNcDestroy](../../mfc/reference/cwnd-class.md#onncdestroy)();|  
|ON_WM_NCHITTEST()|afx_msg LRESULT [OnNcHitTest](../../mfc/reference/cwnd-class.md#onnchittest)(CPoint);|  
|ON_WM_NCLBUTTONDBLCLK()|void afx_msg [OnNcLButtonDblClk](../../mfc/reference/cwnd-class.md#onnclbuttondblclk)(UINT, CPoint);|  
|ON_WM_NCLBUTTONDOWN()|void afx_msg [OnNcLButtonDown](../../mfc/reference/cwnd-class.md#onnclbuttondown)(UINT, CPoint);|  
|ON_WM_NCLBUTTONUP()|void afx_msg [OnNcLButtonUp](../../mfc/reference/cwnd-class.md#onnclbuttonup)(UINT, CPoint);|  
|ON_WM_NCMBUTTONDBLCLK()|void afx_msg [OnNcMButtonDblClk](../../mfc/reference/cwnd-class.md#onncmbuttondblclk)(UINT, CPoint);|  
|ON_WM_NCMBUTTONDOWN()|void afx_msg [OnNcMButtonDown](../../mfc/reference/cwnd-class.md#onncmbuttondown)(UINT, CPoint);|  
|ON_WM_NCMBUTTONUP()|void afx_msg [OnNcMButtonUp](../../mfc/reference/cwnd-class.md#onncmbuttonup)(UINT, CPoint);|  
|ON_WM_NCMOUSEHOVER()|void afx_msg [OnNcMouseHover](../../mfc/reference/cwnd-class.md#onncmousehover)(UINT, CPoint);|  
|ON_WM_NCMOUSELEAVE()|void afx_msg [OnNcMouseLeave](../../mfc/reference/cwnd-class.md#onncmouseleave)();|  
|ON_WM_NCMOUSEMOVE()|void afx_msg [OnNcMouseMove](../../mfc/reference/cwnd-class.md#onncmousemove)(UINT, CPoint);|  
|ON_WM_NCPAINT()|void afx_msg [OnNcPaint](../../mfc/reference/cwnd-class.md#onncpaint)();|  
|ON_WM_NCRBUTTONDBLCLK()|void afx_msg [OnNcRButtonDblClk](../../mfc/reference/cwnd-class.md#onncrbuttondblclk)(UINT, CPoint);|  
|ON_WM_NCRBUTTONDOWN()|void afx_msg [OnNcRButtonDown](../../mfc/reference/cwnd-class.md#onncrbuttondown)(UINT, CPoint);|  
|ON_WM_NCRBUTTONUP()|void afx_msg [OnNcRButtonUp](../../mfc/reference/cwnd-class.md#onncrbuttonup)(UINT, CPoint);|  
|ON_WM_NCXBUTTONDBLCLK()|void [OnNcXButtonDblClk](../../mfc/reference/cwnd-class.md#onncxbuttondblclk)(curto, UINT, CPoint);|  
|ON_WM_NCXBUTTONDOWN()|void afx_msg [OnNcXButtonDown](../../mfc/reference/cwnd-class.md#onncxbuttondown)(curto, UINT, CPoint);|  
|ON_WM_NCXBUTTONUP()|void afx_msg [OnNcXButtonUp](../../mfc/reference/cwnd-class.md#onncxbuttonup)(curto, UINT, CPoint);|  
|ON_WM_NEXTMENU()|void afx_msg [OnNextMenu](../../mfc/reference/cwnd-class.md#onnextmenu)(UINT, LPMDINEXTMENU);|  
|ON_WM_NOTIFYFORMAT()|UINT afx_msg [OnNotifyFormat](../../mfc/reference/cwnd-class.md#onnotifyformat)(CWnd *, UINT);|  
  
## <a name="see-also"></a>Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM _](../../mfc/reference/handlers-for-wm-messages.md)


