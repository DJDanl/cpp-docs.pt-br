---
title: "Recebendo notificação de controles comuns | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ON_NOTIFY
- WM_NOTIFY
dev_langs: C++
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
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 19c75abb6c01f16433bb4f48a81b257e05dbf83e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="receiving-notification-from-common-controls"></a>Recebendo notificação de controles comuns
Controles comuns são janelas filho que enviam mensagens de notificação para a janela pai quando ocorrem os eventos, como a entrada do usuário, no controle.  
  
 O aplicativo depende dessas mensagens de notificação para determinar a ação que o usuário deseja que leve. Controles comuns mais enviam mensagens de notificação como **WM_NOTIFY** mensagens. Controles de Windows enviam mais mensagens de notificação como **WM_COMMAND** mensagens. [CWnd::OnNotify](../mfc/reference/cwnd-class.md#onnotify) é o manipulador para o **WM_NOTIFY** mensagem. Assim como acontece com `CWnd::OnCommand`, a implementação de `OnNotify` envia a mensagem de notificação para `OnCmdMsg` para manipulação de mapas de mensagem. A entrada de mapa de mensagem para tratar notificações é `ON_NOTIFY`. Para obter mais informações, consulte [61 de observação técnica: mensagens ON_NOTIFY e WM_NOTIFY](../mfc/tn061-on-notify-and-wm-notify-messages.md).  
  
 Como alternativa, uma classe derivada pode lidar com suas próprias mensagens de notificação usando "reflexão de mensagem". Para obter mais informações, consulte [62 de observação técnica: reflexão de mensagem para controles de Windows](../mfc/tn062-message-reflection-for-windows-controls.md).  
  
## <a name="retrieving-the-cursor-position-in-a-notification-message"></a>Recuperando a posição do Cursor em uma mensagem de notificação  
 Ocasionalmente, é útil determinar a posição atual do cursor quando determinadas mensagens de notificação são recebidas por um controle comum. Por exemplo, seria útil determinar o local atual do cursor quando um controle comum recebe um **NM_RCLICK** mensagem de notificação.  
  
 Há uma maneira simples de fazer isso chamando `CWnd::GetCurrentMessage`. No entanto, esse método recupera somente a posição do cursor no momento em que a mensagem foi enviada. Porque o cursor pode ter sido movido desde que a mensagem foi enviada, você deve chamar **CWnd::GetCursorPos** para obter a posição atual do cursor.  
  
> [!NOTE]
>  `CWnd::GetCurrentMessage`só deve ser chamado dentro de um manipulador de mensagens.  
  
 Adicione o seguinte código ao corpo do manipulador de mensagem de notificação (neste exemplo, **NM_RCLICK**):  
  
 [!code-cpp[NVC_MFCControlLadenDialog#4](../mfc/codesnippet/cpp/receiving-notification-from-common-controls_1.cpp)]  
  
 Neste ponto, o local do cursor do mouse é armazenado no `cursorPos` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Criando e usando controles](../mfc/making-and-using-controls.md)   
 [Controles](../mfc/controls-mfc.md)

