---
title: Processando mensagens de notificação no seletor de data e hora controles | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- DTN_CLOSEUP
- DTN_DATETIMECHANGE
- DTN_DROPDOWN
dev_langs:
- C++
helpviewer_keywords:
- DTN_DROPDOWN notification [MFC]
- DTN_DATETIMECHANGE notification [MFC]
- DTN_CLOSEUP notification [MFC]
- DateTimePicker control [MFC], handling notifications
- CDateTimeCtrl class [MFC], handling notifications
- DTN_FORMAT notification [MFC]
- DateTimePicker control [MFC]
ms.assetid: ffbe29ab-ff80-4609-89f7-260b404439c4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 630792eb4bdd89cbe8081894c4ee026437568f3b
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36930758"
---
# <a name="processing-notification-messages-in-date-and-time-picker-controls"></a>Processando mensagens de notificação em controles de seletor de data e hora
Como os usuários interagem com a data e o controle de seletor de tempo, o controle (`CDateTimeCtrl`) envia mensagens de notificação para sua janela pai, geralmente um objeto de exibição ou a caixa de diálogo. Se você quiser fazer algo em resposta, lidar com essas mensagens. Por exemplo, quando o usuário abre o seletor de data e hora para exibir o controle de calendário mensal inserido, a notificação de DTN_DROPDOWN é enviada.  
  
 Use a janela Propriedades para adicionar manipuladores de notificação para a classe pai para as mensagens que você deseja implementar.  
  
 A lista a seguir descreve as várias notificações enviadas pelo controle de seletor de data e hora.  
  
-   DTN_DROPDOWN notifica o pai que o controle de calendário do mês inserido está prestes a ser exibido. Essa notificação é enviada somente quando o estilo DTS_UPDOWN não foi definido. Para obter mais informações sobre essa notificação, consulte [acessando o controle de calendário mensal inserido](../mfc/accessing-the-embedded-month-calendar-control.md).  
  
-   DTN_CLOSEUP notifica o pai que o controle de calendário do mês inserido está prestes a ser fechado. Essa notificação é enviada somente quando o estilo DTS_UPDOWN não foi definido.  
  
-   DTN_DATETIMECHANGE emite pai que ocorreu uma alteração no controle.  
  
-   DTN_FORMAT notifica o pai que o texto é necessário a ser exibido em um campo de retorno de chamada. Para obter mais informações sobre esta notificação e campos de retorno de chamada, consulte [usando campos de retorno de chamada em uma data e o controle seletor de hora](../mfc/using-callback-fields-in-a-date-and-time-picker-control.md).  
  
-   DTN_FORMATQUERY solicita o pai para fornecer o tamanho máximo permitido da cadeia de caracteres que será exibido em um campo de retorno de chamada. Manipulando essa notificação permite que o controle à saída de vídeo corretamente em todos os momentos, reduzindo a cintilação na exibição do controle. Para obter mais informações sobre essa notificação, consulte [usando campos de retorno de chamada em uma data e o controle seletor de hora](../mfc/using-callback-fields-in-a-date-and-time-picker-control.md).  
  
-   Notifica de DTN_USERSTRING controle pai que o usuário termina de editar o conteúdo do seletor de data e hora. Essa notificação é enviada somente quando o estilo DTS_APPCANPARSE tiver sido definido.  
  
-   DTN_WMKEYDOWN notifica o pai quando o usuário digita em um campo de retorno de chamada. Lidar com essa notificação para emular a mesma resposta teclado suportada para campos de retorno de chamada não em um controle de seletor de data e hora. Para obter mais informações sobre essa notificação, consulte [dando suporte a campos de retorno de chamada em um controle DTP](http://msdn.microsoft.com/library/windows/desktop/bb761726) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)   
 [Controles](../mfc/controls-mfc.md)

