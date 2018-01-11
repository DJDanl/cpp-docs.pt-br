---
title: Categorias de mensagem | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- messages [MFC], categories
- control-notification messages [MFC]
- Windows messages [MFC], categories
- controls [MFC], notifications
- command messages [MFC]
- messages [MFC], Windows
- message handling [MFC], message types
ms.assetid: 68e1db75-9da6-4a4d-b2c2-dc4d59f8d87b
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: be3bc617c0f3a9915c7ae0314b0e3889ecc561f9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="message-categories"></a>Categorias de mensagem
Que tipos de mensagens escrever manipuladores para há três categorias principais:  
  
1.  mensagens do Windows  
  
     Isso inclui principalmente essas mensagens começando com o **WM _** prefixo, exceto para **WM_COMMAND**. Mensagens do Windows são manipuladas pelo windows e modos de exibição. Essas mensagens geralmente têm parâmetros que são usados para determinar como tratar a mensagem.  
  
2.  Notificações de controle  
  
     Isso inclui **WM_COMMAND** mensagens de notificação de controles e outras janelas filho para as janelas de pai. Por exemplo, um controle de edição envia seu pai um **WM_COMMAND** de mensagem que contém o **EN_CHANGE** código de notificação de controle quando o usuário executou uma ação que pode ter alterado o texto no controle de edição. Manipulador da janela para a mensagem responde à mensagem de notificação de forma apropriada, como recuperar o texto no controle.  
  
     A estrutura roteia as mensagens de notificação de controle como outro **WM _** mensagens. No entanto, é uma exceção, o **BN_CLICKED** mensagem de notificação de controle enviada por botões quando o usuário clica neles. Essa mensagem é tratada de forma especial, como uma mensagem de comando e roteada como outros comandos.  
  
3.  Mensagens de comando  
  
     Isso inclui **WM_COMMAND** mensagens de notificação de objetos de interface do usuário: menus, botões da barra de ferramentas e teclas de aceleração. A estrutura processa comandos de forma diferente de outras mensagens, e podem ser tratados por mais tipos de objetos, conforme explicado em [destinos de comando](../mfc/command-targets.md).  
  
##  <a name="_core_windows_messages_and_control.2d.notification_messages"></a>Mensagens do Windows e mensagens de notificação de controle  
 Mensagens em categorias 1 e 2 — mensagens do Windows e notificações de controle — são manipuladas pelo windows: objetos das classes derivam da classe `CWnd`. Isso inclui `CFrameWnd`, `CMDIFrameWnd`, `CMDIChildWnd`, `CView`, `CDialog`, e suas próprias classes derivadas dessas classes base. Esses objetos encapsulam um `HWND`, um identificador para uma janela do Windows.  
  
##  <a name="_core_command_messages"></a>Mensagens de comando  
 Mensagens na categoria 3 – comandos — podem ser tratados por uma variedade maior de objetos: documentos, modelos de documento e o próprio objeto de aplicativo além de janelas e exibições. Quando um comando afeta diretamente um objeto específico, faz sentido ter esse objeto lidar com o comando. Por exemplo, o comando Abrir no menu arquivo é logicamente associado com o aplicativo: o aplicativo abre um documento especificado ao receber o comando. Portanto, o manipulador para o comando Abrir é uma função de membro de classe do aplicativo. Para obter mais informações sobre comandos e como eles são roteados para objetos, consulte [como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md).  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

