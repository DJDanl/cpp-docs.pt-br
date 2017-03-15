---
title: 'Manipuladores de mensagens WM _: D - E | Documentos do Microsoft'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ON_WM_ERASEBKGND
- ON_WM_DEVICECHANGE
- ON_WM_ENTERIDLE
- ON_WM_DESTROYCLIPBOARD
- ON_WM_DESTROY
- ON_WM_DEADCHAR
- ON_WM_DELETEITEM
- ON_WM_DROPFILES
- ON_WM_DEVMODECHANGE
- ON_WM_ENDSESSION
- ON_WM_ENABLE
- ON_WM_DRAWITEM
- ON_WM_DRAWCLIPBOARD
dev_langs:
- C++
helpviewer_keywords:
- ON_WM_ENTERIDLE
- ON_WM_DESTROYCLIPBOARD
- ON_WM_DEADCHAR
- ON_WM_DEVMODECHANGE
- ON_WM_ERASEBKGND
- ON_WM_DESTROY
- ON_WM_DRAWCLIPBOARD
- ON_WM_ENDSESSION
- ON_WM_DRAWITEM
- ON_WM_ENABLE
- ON_WM_DROPFILES
- ON_WM_DELETEITEM
- ON_WM_DEVICECHANGE
- WM_ messages
ms.assetid: 56fb89c8-68a8-4adf-883e-a9f63bf677e9
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
ms.openlocfilehash: 0dbd7e3649cddd353077b8364482ad98d55283a1
ms.lasthandoff: 02/25/2017

---
# <a name="wm-message-handlers-d---e"></a>Manipuladores de mensagens WM_: D - E
As seguintes entradas de mapa à esquerda correspondem aos protótipos de função à direita:  
  
|Entrada de mapa|Protótipo da função|  
|---------------|------------------------|  
|ON_WM_DEADCHAR()|void afx_msg [OnDeadChar](../../mfc/reference/cwnd-class.md#ondeadchar)(UINT, UINT, UINT);|  
|ON_WM_DELETEITEM()|void afx_msg [OnDeleteItem](../../mfc/reference/cwnd-class.md#ondeleteitem)(LPDELETEITEMSTRUCT);|  
|ON_WM_DESTROY()|void afx_msg [OnDestroy](../../mfc/reference/cwnd-class.md#ondestroy)();|  
|ON_WM_DESTROYCLIPBOARD()|void afx_msg [OnDestroyClipboard](../../mfc/reference/cwnd-class.md#ondestroyclipboard)();|  
|ON_WM_DEVICECHANGE()|void afx_msg [OnDeviceChange](../../mfc/reference/cwnd-class.md#ondevicechange)(UINT, DWORD);|  
|ON_WM_DEVMODECHANGE()|void afx_msg [OnDevModeChange](../../mfc/reference/cwnd-class.md#ondevmodechange)(LPSTR);|  
|ON_WM_DRAWCLIPBOARD()|void afx_msg [OnDrawClipboard](../../mfc/reference/cwnd-class.md#ondrawclipboard)();|  
|ON_WM_DRAWITEM()|void afx_msg [OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem)(LPDRAWITEMSTRUCT);|  
|ON_WM_DROPFILES()|void afx_msg [OnDropFiles](../../mfc/reference/cwnd-class.md#ondropfiles)(HDROP);|  
|ON_WM_DWMCOLORIZATIONCOLORCHANGED()|void afx_msg [OnColorizationColorChanged](../../mfc/reference/cwnd-class.md#oncolorizationcolorchanged)(DWORD, BOOL);|  
|ON_WM_DWMCOMPOSITIONCHANGED()|void afx_msg [OnCompositionChanged](../../mfc/reference/cwnd-class.md#oncompositionchanged)();|  
|ON_WM_DWMNCRENDERINGCHANGED()|void afx_msg [OnNcRenderingChanged](../../mfc/reference/cwnd-class.md#onncrenderingchanged)(BOOL);|  
|ON_WM_DWMWINDOWMAXIMIZEDCHANGE()|void afx_msg [OnWindowMaximizedChanged](../../mfc/reference/cwnd-class.md#onwindowmaximizedchanged)(BOOL);|  
|ON_WM_ENABLE()|void afx_msg [OnEnable](../../mfc/reference/cwnd-class.md#onenable)(BOOL);|  
|ON_WM_ENDSESSION()|void afx_msg [OnEndSession](../../mfc/reference/cwnd-class.md#onendsession)(BOOL);|  
|ON_WM_ENTERIDLE()|void afx_msg [OnEnterIdle](../../mfc/reference/cwnd-class.md#onenteridle)(UINT, CWnd *);|  
|ON_WM_ENTERSIZEMOVE()|void afx_msg [OnEnterSizeMove](../../mfc/reference/cwnd-class.md#onentersizemove)();|  
|ON_WM_ERASEBKGND()|BOOL afx_msg [OnEraseBkgnd](../../mfc/reference/cwnd-class.md#onerasebkgnd)(CDC *);|  
|ON_WM_EXITSIZEMOVE()|void afx_msg [OnExitSizeMove](../../mfc/reference/cwnd-class.md#onexitsizemove)();|  
  
## <a name="see-also"></a>Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)   
 [Manipuladores para mensagens WM _](../../mfc/reference/handlers-for-wm-messages.md)


