---
title: Recebendo notificação de controles comuns
ms.date: 11/04/2016
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
ms.openlocfilehash: 73315d4a1107204bc6adc885729fdeeaeb7f98d0
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75298968"
---
# <a name="receiving-notification-from-common-controls"></a>Recebendo notificação de controles comuns

Os controles comuns são janelas filhas que enviam mensagens de notificação para a janela pai quando eventos, como entrada do usuário, ocorrem no controle.

O aplicativo depende dessas mensagens de notificação para determinar a ação que o usuário deseja executar. Os controles mais comuns enviam mensagens de notificação como WM_NOTIFY mensagens. Os controles do Windows enviam a maioria das mensagens de notificação como WM_COMMAND mensagens. [CWnd:: OnNotify](../mfc/reference/cwnd-class.md#onnotify) é o manipulador para a mensagem de WM_NOTIFY. Assim como ocorre com `CWnd::OnCommand`, a implementação de `OnNotify` despacha a mensagem de notificação para `OnCmdMsg` para tratamento em mapas de mensagens. A entrada do mapa de mensagens para lidar com notificações é ON_NOTIFY. Para obter mais informações, consulte a [Observação técnica 61: mensagens de ON_NOTIFY e WM_NOTIFY](../mfc/tn061-on-notify-and-wm-notify-messages.md).

Como alternativa, uma classe derivada pode manipular suas próprias mensagens de notificação usando "reflexão de mensagem". Para obter mais informações, consulte [a observação técnica 62: reflexão de mensagem para controles do Windows](../mfc/tn062-message-reflection-for-windows-controls.md).

## <a name="retrieving-the-cursor-position-in-a-notification-message"></a>Recuperando a posição do cursor em uma mensagem de notificação

Na ocasião, é útil determinar a posição atual do cursor quando determinadas mensagens de notificação são recebidas por um controle comum. Por exemplo, seria útil determinar o local atual do cursor quando um controle comum recebe uma mensagem de notificação NM_RCLICK.

Há uma maneira simples de fazer isso chamando `CWnd::GetCurrentMessage`. No entanto, esse método recupera apenas a posição do cursor no momento em que a mensagem foi enviada. Como o cursor pode ter sido movido desde que a mensagem foi enviada, você deve chamar `CWnd::GetCursorPos` para obter a posição atual do cursor.

> [!NOTE]
>  `CWnd::GetCurrentMessage` só deve ser chamado dentro de um manipulador de mensagens.

Adicione o código a seguir ao corpo do manipulador de mensagens de notificação (neste exemplo, NM_RCLICK):

[!code-cpp[NVC_MFCControlLadenDialog#4](../mfc/codesnippet/cpp/receiving-notification-from-common-controls_1.cpp)]

Neste ponto, o local do cursor do mouse é armazenado no objeto `cursorPos`.

## <a name="see-also"></a>Veja também

[Criando e usando controles](../mfc/making-and-using-controls.md)<br/>
[Controles](../mfc/controls-mfc.md)
