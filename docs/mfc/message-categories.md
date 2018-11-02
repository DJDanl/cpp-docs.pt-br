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
ms.openlocfilehash: e8b7385a233c2074fe9bfc491d89de7629c730c0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50619850"
---
# <a name="message-categories"></a>Categorias de mensagem

Que tipos de mensagem escrever manipuladores para há três categorias principais:

1. mensagens do Windows

   Isso inclui principalmente essas mensagens começando com o **WM _** prefixo, exceto para WM_COMMAND. Mensagens do Windows são manipuladas pelo windows e modos de exibição. Essas mensagens geralmente têm parâmetros que são usados na determinação de como lidar com a mensagem.

1. Notificações de controle

   Isso inclui mensagens de notificação de WM_COMMAND de controles e outras janelas filho para as janelas pai. Por exemplo, um controle de edição envia seu pai com uma mensagem WM_COMMAND que contém o código de controle-notificação de evento EN_CHANGE quando o usuário executou uma ação que pode ter alterado o texto no controle de edição. Manipulador da janela para a mensagem responde à mensagem de notificação de alguma forma apropriada, como recuperar o texto no controle.

   O framework encaminha mensagens de notificação do controle como qualquer outra **WM _** mensagens. Uma exceção, no entanto, é a mensagem de notificação de controle BN_CLICKED enviada pelos botões quando o usuário clica neles. Essa mensagem é tratada de forma especial, como uma mensagem de comando e roteada como outros comandos.

1. Mensagens de comando

   Isso inclui mensagens de notificação de WM_COMMAND dos objetos de interface do usuário: menus, botões de barra de ferramentas e teclas de aceleração. O framework processa comandos de maneira diferente de outras mensagens e pode ser tratados por mais tipos de objetos, conforme explicado em [destinos de comando](../mfc/command-targets.md).

##  <a name="_core_windows_messages_and_control.2d.notification_messages"></a> Mensagens do Windows e mensagens de notificação de controle

As mensagens nas categorias 1 e 2 — as mensagens do Windows e notificações de controle — são tratadas pelo windows: objetos das classes derivam da classe `CWnd`. Isso inclui `CFrameWnd`, `CMDIFrameWnd`, `CMDIChildWnd`, `CView`, `CDialog`, e suas próprias classes derivadas dessas classes base. Esses objetos encapsulam um `HWND`, um identificador para uma janela do Windows.

##  <a name="_core_command_messages"></a> Mensagens de comando

As mensagens de categoria 3 — comandos — pode ser tratado por uma variedade maior de objetos: o próprio objeto de aplicativo, além de janelas e exibições, modelos de documento e documentos. Quando um comando afeta diretamente um objeto específico, faz sentido ter esse objeto lidar com o comando. Por exemplo, o comando Abrir no menu arquivo é logicamente associado com o aplicativo: o aplicativo abre um documento especificado ao receber o comando. Portanto, o manipulador para o comando Open é uma função de membro da classe de aplicativo. Para obter mais informações sobre comandos e como elas são roteadas para objetos, consulte [como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md).

## <a name="see-also"></a>Consulte também

[Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

