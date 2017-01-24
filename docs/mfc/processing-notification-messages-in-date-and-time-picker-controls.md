---
title: "Processando mensagens de notifica&#231;&#227;o em controles de seletor de data e hora | Microsoft Docs"
ms.custom: ""
ms.date: "12/13/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "DTN_CLOSEUP"
  - "DTN_DATETIMECHANGE"
  - "DTN_DROPDOWN"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CDateTimeCtrl, manipulando notificações"
  - "Controle DateTimePicker [MFC]"
  - "Controle DateTimePicker [MFC], manipulando notificações"
  - "DTN_CLOSEUP (notificação)"
  - "DTN_DATETIMECHANGE (notificação)"
  - "DTN_DROPDOWN (notificação)"
  - "DTN_FORMAT (notificação)"
ms.assetid: ffbe29ab-ff80-4609-89f7-260b404439c4
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Processando mensagens de notifica&#231;&#227;o em controles de seletor de data e hora
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Conforme os usuários interagem com o controle de seletor de data e hora, o controle`CDateTimeCtrl`\(\) envia notificações à janela pai, geralmente um objeto da exibição ou na caixa de diálogo.  Tratar essas mensagens se você deseja fazer algo na resposta.  Por exemplo, quando o usuário abre a seletor de data e hora para exibir o controle inserido month calendar, a notificação de **DTN\_DROPDOWN** é enviada.  
  
 Use a janela Propriedades para adicionar manipuladores de notificação para a classe pai para essas mensagens que você deseja implementar.  
  
 A lista a seguir descreve as várias notificações enviadas pelo controle de seletor de data e hora.  
  
-   **DTN\_DROPDOWN** notifica o pai que o controle inserido month calendar está prestes a ser exibido.  Essa notificação é enviada somente quando o estilo de **DTS\_UPDOWN** não foi definido.  Para obter mais informações sobre essa notificação, consulte [Acessando o controle inserido month calendar](../mfc/accessing-the-embedded-month-calendar-control.md).  
  
-   **DTN\_CLOSEUP** notifica o pai que o controle inserido month calendar está prestes a ser fechado.  Essa notificação é enviada somente quando o estilo de **DTS\_UPDOWN** não foi definido.  
  
-   **DTN\_DATETIMECHANGE** notifica o pai que uma alteração ocorreu no controle.  
  
-   **DTN\_FORMAT** notifica o pai que o texto é necessário para ser exibido em um campo de retorno de chamada.  Para obter mais informações sobre esses campos de notificação e de retorno de chamada, consulte [Usando campos de retorno de chamada em um controle de seletor de data e hora](../mfc/using-callback-fields-in-a-date-and-time-picker-control.md).  
  
-   **DTN\_FORMATQUERY** solicita o pai fornecer o tamanho máximo permitido de cadeia de caracteres que será exibida em um campo de retorno de chamada.  Para controlar essa notificação permite que o controle seja exibido corretamente saída em todas as vezes, reduzindo a cintilação na exibição do controle.  Para obter mais informações sobre essa notificação, consulte [Usando campos de retorno de chamada em um controle de seletor de data e hora](../mfc/using-callback-fields-in-a-date-and-time-picker-control.md).  
  
-   **DTN\_USERSTRING** notifica o pai que o usuário foi concluída edite o conteúdo do controle de seletor de data e hora.  Essa notificação é enviada somente quando o estilo de **DTS\_APPCANPARSE** foi definido.  
  
-   **DTN\_WMKEYDOWN** notifica o pai quando o usuário em um campo de retorno de chamada.  Para controlar essa notificação para emular a mesma resposta de teclado suporte para campos de não retorno de chamada em um controle de seletor de data e hora.  Para obter mais informações sobre essa notificação, consulte [Campos de suporte de retorno de chamada em um controle de DTP](http://msdn.microsoft.com/library/windows/desktop/bb761726) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Consulte também  
 [Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)   
 [Controles](../mfc/controls-mfc.md)