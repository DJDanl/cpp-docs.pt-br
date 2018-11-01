---
title: 'Mensagens WM_: P - R'
ms.date: 11/04/2016
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
helpviewer_keywords:
- ON_WM_RENDERFORMAT [MFC]
- ON_WM_QUERYOPEN [MFC]
- ON_WM_RBUTTONDOWN [MFC]
- ON_WM_PAINTCLIPBOARD [MFC]
- ON_WM_QUERYNEWPALETTE [MFC]
- ON_WM_RBUTTONUP [MFC]
- ON_WM_PARENTNOTIFY [MFC]
- ON_WM_RBUTTONDBLCLK [MFC]
- ON_WM_PALETTECHANGED [MFC]
- ON_WM_PALETTEISCHANGING [MFC]
- ON_WM_QUERYDRAGICON [MFC]
- ON_WM_PAINT [MFC]
- ON_WM_RENDERALLFORMATS [MFC]
- ON_WM_QUERYENDSESSION [MFC]
- WM_ messages
ms.assetid: f46962e5-8329-4f1f-9b4d-fdad2a5ce1f8
ms.openlocfilehash: ff34f8d25a48cffd75bed6b13c5811a6cabd9c53
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50636612"
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
|ON_WM_POWERBROADCAST()|afx_msg UINT [onpowerbroadcast foi](../../mfc/reference/cwnd-class.md#onpowerbroadcast)(UINT, UINT);|
|ON_WM_QUERYDRAGICON()|afx_msg HCURSOR [OnQueryDragIcon](../../mfc/reference/cwnd-class.md#onquerydragicon)(de) ();|
|ON_WM_QUERYENDSESSION()|afx_msg BOOL [OnQueryEndSession](../../mfc/reference/cwnd-class.md#onqueryendsession)(de) ();|
|ON_WM_QUERYNEWPALETTE()|afx_msg BOOL [OnQueryNewPalette](../../mfc/reference/cwnd-class.md#onquerynewpalette)(de) ();|
|ON_WM_QUERYOPEN()|afx_msg BOOL [OnQueryOpen](../../mfc/reference/cwnd-class.md#onqueryopen)(de) ();|
|ON_WM_RBUTTONDBLCLK()|void afx_msg [OnRButtonDblClk](../../mfc/reference/cwnd-class.md#onrbuttondblclk)(UINT, CPoint);|
|ON_WM_RBUTTONDOWN()|void afx_msg [OnRButtonDown](../../mfc/reference/cwnd-class.md#onrbuttondown)(UINT, CPoint);|
|ON_WM_RBUTTONUP()|void afx_msg [OnRButtonUp](../../mfc/reference/cwnd-class.md#onrbuttonup)(UINT, CPoint);|
|ON_WM_RENDERALLFORMATS()|void afx_msg [OnRenderAllFormats](../../mfc/reference/cwnd-class.md#onrenderallformats)();|
|ON_WM_RENDERFORMAT()|void afx_msg [OnRenderFormat](../../mfc/reference/cwnd-class.md#onrenderformat)(UINT);|

## <a name="see-also"></a>Consulte também

[Mapas de mensagens](../../mfc/reference/message-maps-mfc.md)<br/>
[Manipuladores para mensagens WM_](../../mfc/reference/handlers-for-wm-messages.md)

