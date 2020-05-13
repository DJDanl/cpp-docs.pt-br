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
ms.openlocfilehash: 9205facb5ec4e2491308020d9667a27ab8deb96b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371791"
---
# <a name="receiving-notification-from-common-controls"></a>Recebendo notificação de controles comuns

Controles comuns são janelas de crianças que enviam mensagens de notificação para a janela pai quando eventos, como entrada do usuário, ocorrem no controle.

O aplicativo conta com essas mensagens de notificação para determinar que ação o usuário quer que ele tome. Os controles mais comuns enviam mensagens de notificação como WM_NOTIFY mensagens. Os controles do Windows enviam a maioria das mensagens de notificação como WM_COMMAND mensagens. [CWnd::OnNotificar](../mfc/reference/cwnd-class.md#onnotify) é o manipulador da mensagem WM_NOTIFY. Como `CWnd::OnCommand`acontece, a `OnNotify` implementação de `OnCmdMsg` despachos da mensagem de notificação para o manuseio em mapas de mensagens. A entrada do mapa de mensagem para o tratamento de notificações é ON_NOTIFY. Para obter mais informações, consulte [Nota Técnica 61: mensagens ON_NOTIFY e WM_NOTIFY](../mfc/tn061-on-notify-and-wm-notify-messages.md).

Alternativamente, uma classe derivada pode lidar com suas próprias mensagens de notificação usando "reflexão de mensagem". Para obter mais informações, consulte [Nota Técnica 62: Reflexão de mensagens para controles do Windows](../mfc/tn062-message-reflection-for-windows-controls.md).

## <a name="retrieving-the-cursor-position-in-a-notification-message"></a>Recuperando a posição do cursor em uma mensagem de notificação

Na ocasião, é útil determinar a posição atual do cursor quando determinadas mensagens de notificação são recebidas por um controle comum. Por exemplo, seria útil determinar o local atual do cursor quando um controle comum recebe uma mensagem de notificação NM_RCLICK.

Há uma maneira simples de `CWnd::GetCurrentMessage`conseguir isso chamando. No entanto, este método só recupera a posição do cursor no momento em que a mensagem foi enviada. Como o cursor pode ter sido movido desde `CWnd::GetCursorPos` que a mensagem foi enviada, você deve ligar para obter a posição atual do cursor.

> [!NOTE]
> `CWnd::GetCurrentMessage`só deve ser chamado dentro de um manipulador de mensagens.

Adicione o seguinte código ao corpo do manipulador de mensagens de notificação (neste exemplo, NM_RCLICK):

[!code-cpp[NVC_MFCControlLadenDialog#4](../mfc/codesnippet/cpp/receiving-notification-from-common-controls_1.cpp)]

Neste ponto, a localização do cursor `cursorPos` do mouse é armazenada no objeto.

## <a name="see-also"></a>Confira também

[Criando e usando controles](../mfc/making-and-using-controls.md)<br/>
[Controles](../mfc/controls-mfc.md)
