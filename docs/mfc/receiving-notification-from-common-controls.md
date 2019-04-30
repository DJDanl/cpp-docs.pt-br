---
title: Recebendo notificação de controles comuns
ms.date: 11/04/2016
f1_keywords:
- ON_NOTIFY
- WM_NOTIFY
helpviewer_keywords:
- OnNotify method [MFC]
- common controls [MFC], notifications
- ON_NOTIFY macro [MFC]
- controls [MFC], notifications
- receiving notifications from common controls
- notifications [MFC], common controls
- Windows common controls [MFC], notifications
- WM_NOTIFY message
ms.assetid: 50194592-d60d-44d0-8ab3-338a2a2c63e7
ms.openlocfilehash: fb923374866aa8348f9b895c9b97915817564883
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399857"
---
# <a name="receiving-notification-from-common-controls"></a>Recebendo notificação de controles comuns

Controles comuns são janelas filho que enviam mensagens de notificação para a janela pai quando ocorrem eventos, como a entrada do usuário, no controle.

O aplicativo depende dessas mensagens de notificação para determinar a ação que o usuário deseja que ele entrar. Controles mais comuns enviar mensagens de notificação como mensagens WM_NOTIFY. Controles do Windows enviar a maioria das mensagens de notificação como mensagens WM_COMMAND. [CWnd::OnNotify](../mfc/reference/cwnd-class.md#onnotify) é o manipulador para a mensagem WM_NOTIFY. Assim como acontece com `CWnd::OnCommand`, a implementação de `OnNotify` expede a mensagem de notificação para `OnCmdMsg` para manipulação em mapas de mensagem. A entrada de mapa de mensagem para manipular notificações é ON_NOTIFY. Para obter mais informações, consulte [61 de observação técnica: Mensagens ON_NOTIFY e WM_NOTIFY](../mfc/tn061-on-notify-and-wm-notify-messages.md).

Como alternativa, uma classe derivada pode lidar com suas próprias mensagens de notificação usando a "reflexão de mensagem." Para obter mais informações, consulte [62 de observação técnica: Mensagem de reflexão para controles do Windows](../mfc/tn062-message-reflection-for-windows-controls.md).

## <a name="retrieving-the-cursor-position-in-a-notification-message"></a>Recuperando a posição do Cursor em uma mensagem de notificação

Às vezes, é útil para determinar a posição atual do cursor quando determinadas mensagens de notificação são recebidas por um controle comum. Por exemplo, seria útil determinar o local do cursor atual quando um controle comum recebe uma mensagem de notificação NM_RCLICK.

Há uma maneira simples de fazer isso chamando `CWnd::GetCurrentMessage`. No entanto, esse método recupera somente a posição do cursor no momento em que a mensagem foi enviada. Porque o cursor pode ter sido movido, pois a mensagem foi enviada, você deve chamar `CWnd::GetCursorPos` para obter a posição atual do cursor.

> [!NOTE]
>  `CWnd::GetCurrentMessage` só deve ser chamado dentro de um manipulador de mensagens.

Adicione o seguinte código ao corpo do manipulador de mensagem de notificação (no exemplo, NM_RCLICK):

[!code-cpp[NVC_MFCControlLadenDialog#4](../mfc/codesnippet/cpp/receiving-notification-from-common-controls_1.cpp)]

Neste ponto, o local do cursor do mouse é armazenado no `cursorPos` objeto.

## <a name="see-also"></a>Consulte também

[Criando e usando controles](../mfc/making-and-using-controls.md)<br/>
[Controles](../mfc/controls-mfc.md)
