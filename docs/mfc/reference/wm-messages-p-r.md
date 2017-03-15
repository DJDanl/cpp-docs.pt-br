---
title: 'Mensagens WM _: P - R | Documentos do Microsoft'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ON_WM_RBUTTONUP
- ON_WM_PALETTECHANGED
- ON_WM_RBUTTONDBLCLK
- ON_WM_QUERYENDSESSION
- ON_WM_PARENTNOTIFY
- ON_WM_PALETTEISCHANGING
- ON_WM_QUERYOPEN
- ON_WM_PAINT
- ON_WM_QUERYNEWPALETTE
- ON_WM_RBUTTONDOWN
- ON_WM_RENDERALLFORMATS
- ON_WM_PAINTCLIPBOARD
- ON_WM_RENDERFORMAT
- ON_WM_QUERYDRAGICON
dev_langs:
- C++
helpviewer_keywords:
- ON_WM_RENDERFORMAT
- ON_WM_QUERYOPEN
- ON_WM_RBUTTONDOWN
- ON_WM_PAINTCLIPBOARD
- ON_WM_QUERYNEWPALETTE
- ON_WM_RBUTTONUP
- ON_WM_PARENTNOTIFY
- ON_WM_RBUTTONDBLCLK
- ON_WM_PALETTECHANGED
- ON_WM_PALETTEISCHANGING
- ON_WM_QUERYDRAGICON
- ON_WM_PAINT
- ON_WM_RENDERALLFORMATS
- ON_WM_QUERYENDSESSION
- WM_ messages
ms.assetid: f46962e5-8329-4f1f-9b4d-fdad2a5ce1f8
caps.latest.revision: 15
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
ms.openlocfilehash: c849c360902980d90587398ff4b035d11e6fa68e
ms.lasthandoff: 02/25/2017

---
# <a name="wm-messages-p---r"></a>Mensagens WM_: P - R
As seguintes entradas de mapa correspondem aos protótipos de função:  
  
|Entrada de mapa|Protótipo da função|  
|---------------|------------------------|  
|ON_WM_PAINT()|void afx_msg [OnPaint](../../mfc/reference/cwnd-class.md#onpaint)();|  
|ON_WM_PAINTCLIPBOARD()|void afx_msg [OnPaintClipboard](../../mfc/reference/cwnd-class.md#onpaintclipboard)(CWnd *, identificador);|  
|ON_WM_PALETTECHANGED()|void afx_msg [OnPaletteChanged](../../mfc/reference/cwnd-class.md#onpalettechanged)(CWnd *);|  
|ON_WM_PALETTEISCHANGING()|void afx_msg [OnPaletteIsChanging](../../mfc/reference/cwnd-class.md#onpaletteischanging)(CWnd *);|  
|ON_WM_PARENTNOTIFY()|void afx_msg [OnParentNotify](../../mfc/reference/cwnd-class.md#onparentnotify)(UINT, LONG);|  
|ON_WM_POWERBROADCAST()|UINT afx_msg [OnPowerBroadcast](../../mfc/reference/cwnd-class.md#onpowerbroadcast)(UINT, UINT);|  
|ON_WM_QUERYDRAGICON()|afx_msg: HCURSOR [OnQueryDragIcon](../../mfc/reference/cwnd-class.md#onquerydragicon)() ();|  
|ON_WM_QUERYENDSESSION()|BOOL afx_msg [OnQueryEndSession](../../mfc/reference/cwnd-class.md#onqueryendsession)() ();|  
|ON_WM_QUERYNEWPALETTE()|BOOL afx_msg [OnQueryNewPalette](../../mfc/reference/cwnd-class.md#onquerynewpalette)() ();|  
|ON_WM_QUERYOPEN()|BOOL afx_msg [OnQueryOpen](../../mfc/reference/cwnd-class.md#onqueryopen)() ();|  
|ON_WM_RBUTTONDBLCLK()|void afx_msg [OnRButtonDblClk](../../mfc/reference/cwnd-class.md#onrbuttondblclk)(UINT, CPoint);|  
|ON_WM_RBUTTONDOWN()|void afx_msg [OnRButtonDown](../../mfc/reference/cwnd-class.md#onrbuttondown)(UINT, CPoint);|  
|ON_WM_RBUTTONUP()|void afx_msg [OnRButtonUp](../../mfc/reference/cwnd-class.md#onrbuttonup)(UINT, CPoint);|  
|ON_WM_RENDERALLFORMATS()|void afx_msg [OnRenderAllFormats](../../mfc/reference/cwnd-class.md#onrenderallformats)();|  
|ON_WM_RENDERFORMAT()|void afx_msg [OnRenderFormat](../../mfc/reference/cwnd-class.md#onrenderformat)(UINT);|  
  
## <a name="see-also"></a>Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM _](../../mfc/reference/handlers-for-wm-messages.md)


