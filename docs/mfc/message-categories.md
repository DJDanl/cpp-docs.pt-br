---
title: Categorias de mensagem
ms.date: 11/04/2016
helpviewer_keywords:
- messages [MFC], categories
- control-notification messages [MFC]
- Windows messages [MFC], categories
- controls [MFC], notifications
- command messages [MFC]
- messages [MFC], Windows
- message handling [MFC], message types
ms.assetid: 68e1db75-9da6-4a4d-b2c2-dc4d59f8d87b
ms.openlocfilehash: 686d5eef4aaa67785aa56133d820b637fbf4bb86
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364750"
---
# <a name="message-categories"></a>Categorias de mensagem

Que tipo de mensagens você escreve manipuladores para Existem três categorias principais:

1. mensagens do Windows

   Isso inclui principalmente aquelas mensagens que começam com o prefixo **WM_,** exceto para WM_COMMAND. As mensagens do Windows são tratadas por janelas e visualizações. Essas mensagens geralmente têm parâmetros que são usados para determinar como lidar com a mensagem.

1. Notificações de controle

   Isso inclui mensagens de notificação WM_COMMAND de controles e outras janelas de crianças para as janelas de seus pais. Por exemplo, um controle de edição envia ao pai uma mensagem WM_COMMAND contendo o código de notificação de controle EN_CHANGE quando o usuário tomou uma ação que pode ter alterado o texto no controle de edição. O manipulador da janela para a mensagem responde à mensagem de notificação de alguma forma apropriada, como recuperar o texto no controle.

   O framework encaminha mensagens de notificação de controle como outras **mensagens WM_.** Uma exceção, no entanto, é a mensagem de notificação de controle BN_CLICKED enviada por botões quando o usuário clica neles. Esta mensagem é tratada especialmente como uma mensagem de comando e roteada como outros comandos.

1. Mensagens de comando

   Isso inclui mensagens de notificação WM_COMMAND de objetos de interface do usuário: menus, botões de barra de ferramentas e teclas do acelerador. Os processos-quadro são diferentes de outras mensagens, e podem ser manuseados por mais tipos de objetos, conforme explicado em [Command Targets](../mfc/command-targets.md).

## <a name="windows-messages-and-control-notification-messages"></a><a name="_core_windows_messages_and_control.2d.notification_messages"></a>Mensagens do Windows e mensagens de notificação de controle

As mensagens nas categorias 1 e 2 — mensagens do Windows e notificações `CWnd`de controle — são manuseadas por janelas: objetos de classes derivadas da classe . Isso inclui `CFrameWnd` `CMDIFrameWnd`, `CMDIChildWnd` `CView`, `CDialog`, , , , e suas próprias classes derivadas dessas classes de base. Tais objetos `HWND`encapsulam uma alça para uma janela do Windows.

## <a name="command-messages"></a><a name="_core_command_messages"></a>Mensagens de Comando

As mensagens na categoria 3 — comandos — podem ser manuseadas por uma variedade mais ampla de objetos: documentos, modelos de documentos e o próprio objeto do aplicativo, além de janelas e visualizações. Quando um comando afeta diretamente algum objeto em particular, faz sentido que esse objeto manuseie o comando. Por exemplo, o comando Abrir no menu Arquivo está logicamente associado ao aplicativo: o aplicativo abre um documento especificado ao receber o comando. Assim, o manipulador para o comando Open é uma função membro da classe de aplicativos. Para obter mais informações sobre comandos e como eles são encaminhados para objetos, consulte [Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md).

## <a name="see-also"></a>Confira também

[Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)
