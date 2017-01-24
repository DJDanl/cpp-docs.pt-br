---
title: "Categorias de mensagem | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "mensagens de comando [C++]"
  - "mensagens de notificação de controle"
  - "controles [MFC], notificações"
  - "tratamento de mensagens [C++], tipos de mensagem"
  - "mensagens [C++], categorias"
  - "mensagens [C++], Janelas"
  - "mensagens do Windows [C++], categorias"
ms.assetid: 68e1db75-9da6-4a4d-b2c2-dc4d59f8d87b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Categorias de mensagem
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Que tipos de mensagens você grava manipuladores para?  Há três categorias principais:  
  
1.  Mensagens do windows  
  
     Isso inclui primeiro essas mensagens que começam com o prefixo de **WM\_** , com exceção de **WM\_COMMAND**.  As mensagens do windows são tratadas pelo windows e por exibições.  Essas mensagens frequentemente têm os parâmetros usados para determinar como tratar a mensagem.  
  
2.  Controle notificações  
  
     Isso inclui notificações de **WM\_COMMAND** de controles e outras janelas filho para as janelas pai.  Por exemplo, um controle de edição seu pai envia uma mensagem de **WM\_COMMAND** que contém o código de controle\- notificação de **EN\_CHANGE** quando o usuário executou uma ação que pode ter modificado o texto no controle de edição.  O manipulador da janela para a mensagem responde à notificação em alguma maneira apropriada, como recuperar o texto no controle.  
  
     A estrutura roteia mensagens de notificação controle\- como outras mensagens de **WM\_** .  Uma exceção, porém, é a mensagem de controle\- notificação de **BN\_CLICKED** enviada pelos botões quando o usuário clica neles.  Essa mensagem é especialmente tratada como uma mensagem de comando e roteada como outros comandos.  
  
3.  Mensagens de comando  
  
     Isso inclui notificações de **WM\_COMMAND** de objetos da interface do usuário: menus, botões da barra de ferramentas, e teclas de aceleração.  A estrutura processa comandos diferentemente de outras mensagens, e podem ser tratados por mais tipos de objetos, como explicado em [Destinos de comando](../Topic/Command%20Targets.md).  
  
##  <a name="_core_windows_messages_and_control.2d.notification_messages"></a> Mensagens do windows e mensagens de notificação Controle\-  
 As mensagens em categorias 1 e 2 — mensagens do windows e notificações de controle — são tratadas pelo windows: objetos das classes derivadas da classe `CWnd`.  Isso inclui `CFrameWnd`, `CMDIFrameWnd`, `CMDIChildWnd`, `CView`, `CDialog`, e suas próprias classes derivadas dessas classes base.  Esses objetos `HWND`encapsulam, um identificador para uma janela do windows.  
  
##  <a name="_core_command_messages"></a> Mensagens de comando  
 As mensagens na categoria 3 — — comandos podem ser manipuladas por uma variedade mais ampla de objetos: documentos, modelos do documento, e o próprio objeto de aplicativos além do windows e exibições.  Quando um comando afeta diretamente qualquer objeto específico, faz sentido ter aquele identificador de objeto do comando.  Por exemplo, o comando aberto no menu arquivo associado é logicamente com o aplicativo: o aplicativo abrir um documento especificado no recebimento do comando.  Para o manipulador para o comando é aberto uma função de membro da classe do aplicativo.  Para obter mais informações sobre comandos e como são roteados para objetos, consulte [Como a estrutura chama um manipulador](../mfc/how-the-framework-calls-a-handler.md).  
  
## Consulte também  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)