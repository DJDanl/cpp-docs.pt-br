---
title: IDs de mensagem da janela refletida
ms.date: 11/04/2016
f1_keywords:
- OCM_CTLCOLORBTN
- OCM_PARENTNOTIFY
- OCM_VKEYTOITEM
- OCM_CTLCOLORSTATIC
- OCM_HSCROLL
- OCM_CHARTOITEM
- OCM_DRAWITEM
- OCM_MEASUREITEM
- OCM_COMPAREITEM
- OCM_COMMAND
- OCM_NOTIFY
- OCM_CTLCOLORMSGBOX
- OCM_DELETEITEM
- OCM_CTLCOLORLISTBOX
- OCM_CTLCOLORDLG
- OCM_CTLCOLOREDIT
- OCM_CTLCOLORSCROLLBAR
- OCM_VSCROLL
- OCM_CTLCOLOR
helpviewer_keywords:
- OCM_HSCROLL message [MFC]
- OCM_PARENTNOTIFY message [MFC]
- messages, reflected
- reflected messages, window message Ids
- OCM_CTLCOLORDLG message [MFC]
- OCM_COMMAND message [MFC]
- OCM_CTLCOLORMSGBOX message [MFC]
- OCM_COMPAREITEM message [MFC]
- OCM_DRAWITEM message [MFC]
- OCM_VSCROLL message [MFC]
- OCM_CTLCOLOREDIT message [MFC]
- OCM_VKEYTOITEM message [MFC]
- OCM_CHARTOITEM message [MFC]
- OCM_CTLCOLORBTN message [MFC]
- OCM_CTLCOLORSTATIC message [MFC]
- OCM_MEASUREITEM message [MFC]
- OCM_CTLCOLOR message [MFC]
- OCM_CTLCOLORSCROLLBAR message [MFC]
- OCM_ messages
- OCM_DELETEITEM message [MFC]
- OCM_CTLCOLORLISTBOX message [MFC]
- OCM_NOTIFY message [MFC]
- reflected messages
ms.assetid: 3417ff51-ff9f-458c-bff4-17c200f00d96
ms.openlocfilehash: 5b44a1b4e96d92d9ddd150a5b5f68cf83863f8db
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372847"
---
# <a name="reflected-window-message-ids"></a>IDs de mensagem da janela refletida

Uma maneira rápida de criar um controle ActiveX, ou outro controle especializado, é subclasse uma janela. Para obter mais informações, consulte [Controles MFC ActiveX: Subclassificação de um controle do Windows](../mfc/mfc-activex-controls-subclassing-a-windows-control.md).

Para evitar que o contêiner do controle receba as mensagens de janela enviadas por um controle do Windows subclassificado, [o COleControl](../mfc/reference/colecontrol-class.md) cria uma janela "refletor" para interceptar determinadas mensagens de janela e enviá-las de volta ao controle. O controle, em seu procedimento de janela, pode então processar essas mensagens refletidas, tomando ações apropriadas para um controle ActiveX.

A tabela a seguir mostra as mensagens interceptadas e as mensagens correspondentes que a janela do refletor envia.

|Mensagem enviada pelo controle|Mensagem refletida para o controle|
|---------------------------------|--------------------------------------|
|[WM_COMMAND](/windows/win32/menurc/wm-command)|OCM_COMMAND|
|[WM_CTLCOLORBTN](/windows/win32/Controls/wm-ctlcolorbtn)|OCM_CTLCOLORBTN|
|[WM_CTLCOLOREDIT](/windows/win32/Controls/wm-ctlcoloredit)|OCM_CTLCOLOREDIT|
|[WM_CTLCOLORDLG](/windows/win32/dlgbox/wm-ctlcolordlg)|OCM_CTLCOLORDLG|
|[WM_CTLCOLORLISTBOX](/windows/win32/Controls/wm-ctlcolorlistbox)|OCM_CTLCOLORLISTBOX|
|[WM_CTLCOLORSCROLLBAR](/windows/win32/Controls/wm-ctlcolorscrollbar)|OCM_CTLCOLORSCROLLBAR|
|[WM_CTLCOLORSTATIC](/windows/win32/Controls/wm-ctlcolorstatic)|OCM_CTLCOLORSTATIC|
|[Wm_drawitem](/windows/win32/Controls/wm-drawitem)|OCM_DRAWITEM|
|[Wm_measureitem](/windows/win32/Controls/wm-measureitem)|OCM_MEASUREITEM|
|[Wm_deleteitem](/windows/win32/Controls/wm-deleteitem)|OCM_DELETEITEM|
|[Wm_vkeytoitem](/windows/win32/Controls/wm-vkeytoitem)|OCM_VKEYTOITEM|
|[Wm_chartoitem](/windows/win32/Controls/wm-chartoitem)|OCM_CHARTOITEM|
|[WM_COMPAREITEM](/windows/win32/Controls/wm-compareitem)|OCM_COMPAREITEM|
|[Wm_hscroll](/windows/win32/Controls/wm-hscroll)|OCM_HSCROLL|
|[Wm_vscroll](/windows/win32/Controls/wm-vscroll)|OCM_VSCROLL|
|[Wm_parentnotify](/previous-versions/windows/desktop/inputmsg/wm-parentnotify)|OCM_PARENTNOTIFY|
|[Wm_notify](/windows/win32/controls/wm-notify)|OCM_NOTIFY|

> [!NOTE]
> Se o controle for executado em um sistema Win32, existem vários tipos de mensagens WM_CTLCOLOR\* que ele pode receber. Para mais informações, consulte WM_CTLCOLORBTN, WM_CTLCOLORDLG, WM_CTLCOLOREDIT, WM_CTLCOLORLISTBOX, WM_CTLCOLORMSGBOX, WM_CTLCOLORSCROLLBAR, WM_CTLCOLORSTATIC.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC: subclasses de um controle do Windows](../mfc/mfc-activex-controls-subclassing-a-windows-control.md)<br/>
[TN062: reflexão de mensagem para controles do Windows](../mfc/tn062-message-reflection-for-windows-controls.md)
