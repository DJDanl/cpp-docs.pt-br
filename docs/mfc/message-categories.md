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
ms.openlocfilehash: 3875a6931b4380f0531e4c1786de6dddfccb76ca
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625462"
---
# <a name="message-categories"></a>Categorias de mensagem

Para que tipos de mensagens você escreve manipuladores há três categorias principais:

1. mensagens do Windows

   Isso inclui principalmente as mensagens que começam com o prefixo **WM_** , exceto para WM_COMMAND. As mensagens do Windows são manipuladas por janelas e exibições. Essas mensagens geralmente têm parâmetros que são usados para determinar como tratar a mensagem.

1. Notificações de controle

   Isso inclui WM_COMMAND mensagens de notificação de controles e outras janelas filhas para suas janelas pai. Por exemplo, um controle de edição envia seu pai um WM_COMMAND mensagem contendo o código de notificação de controle de EN_CHANGE quando o usuário executou uma ação que pode ter alterado o texto no controle de edição. O manipulador da janela para a mensagem responde à mensagem de notificação de alguma forma apropriada, como recuperar o texto no controle.

   A estrutura roteia mensagens de notificação de controle como outras mensagens de **WM_** . No entanto, uma exceção é a BN_CLICKED mensagem de notificação de controle enviada por botões quando o usuário clica neles. Essa mensagem é tratada especialmente como uma mensagem de comando e roteada como outros comandos.

1. Mensagens de comando

   Isso inclui WM_COMMAND mensagens de notificação de objetos de interface do usuário: menus, botões da barra de ferramentas e teclas de aceleração. A estrutura processa comandos de forma diferente de outras mensagens, e elas podem ser tratadas por mais tipos de objetos, conforme explicado em [destinos de comando](command-targets.md).

## <a name="windows-messages-and-control-notification-messages"></a><a name="_core_windows_messages_and_control.2d.notification_messages"></a>Mensagens do Windows e mensagens de notificação de controle

Mensagens nas categorias 1 e 2 — mensagens do Windows e notificações de controle — são tratadas pelo Windows: objetos de classes derivadas da classe `CWnd` . Isso inclui `CFrameWnd` , `CMDIFrameWnd` , `CMDIChildWnd` , `CView` , `CDialog` e suas próprias classes derivadas dessas classes base. Esses objetos encapsulam um `HWND` , um identificador para uma janela do Windows.

## <a name="command-messages"></a><a name="_core_command_messages"></a>Mensagens de comando

As mensagens na categoria 3 — comandos — podem ser tratadas por uma variedade maior de objetos: documentos, modelos de documentos e o próprio objeto de aplicativo, além de janelas e exibições. Quando um comando afeta diretamente algum objeto específico, faz sentido que o objeto manipule o comando. Por exemplo, o comando abrir no menu arquivo está logicamente associado ao aplicativo: o aplicativo abre um documento especificado após o recebimento do comando. Portanto, o manipulador para o comando Open é uma função membro da classe Application. Para obter mais informações sobre comandos e como eles são roteados para objetos, consulte [como a estrutura chama um manipulador](how-the-framework-calls-a-handler.md).

## <a name="see-also"></a>Consulte também

[Mensagens e comandos no Framework](messages-and-commands-in-the-framework.md)
