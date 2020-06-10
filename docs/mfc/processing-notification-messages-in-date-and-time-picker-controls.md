---
title: Processando mensagens de notificação em controles de seletor de data e hora
ms.date: 11/04/2016
f1_keywords:
- DTN_CLOSEUP
- DTN_DATETIMECHANGE
- DTN_DROPDOWN
helpviewer_keywords:
- DTN_DROPDOWN notification [MFC]
- DTN_DATETIMECHANGE notification [MFC]
- DTN_CLOSEUP notification [MFC]
- DateTimePicker control [MFC], handling notifications
- CDateTimeCtrl class [MFC], handling notifications
- DTN_FORMAT notification [MFC]
- DateTimePicker control [MFC]
ms.assetid: ffbe29ab-ff80-4609-89f7-260b404439c4
ms.openlocfilehash: 3c568d231cc02b2529a4d97ab7faed51c1737b19
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620997"
---
# <a name="processing-notification-messages-in-date-and-time-picker-controls"></a>Processando mensagens de notificação em controles de seletor de data e hora

Como os usuários interagem com o controle seletor de data e hora, o controle ( `CDateTimeCtrl` ) envia mensagens de notificação para sua janela pai, geralmente um objeto View ou Dialog. Manipule essas mensagens se desejar fazer algo em resposta. Por exemplo, quando o usuário abre o seletor de data e hora para exibir o controle de calendário mensal inserido, a notificação de DTN_DROPDOWN é enviada.

Use o [Assistente de classe](reference/mfc-class-wizard.md) para adicionar manipuladores de notificação à classe pai para as mensagens que você deseja implementar.

A lista a seguir descreve as várias notificações enviadas pelo controle seletor de data e hora.

- DTN_DROPDOWN Notifica o pai que o controle de calendário mensal inserido está prestes a ser exibido. Esta notificação é enviada somente quando o estilo de DTS_UPDOWN não foi definido. Para obter mais informações sobre essa notificação, consulte [acessando o controle de calendário mensal inserido](accessing-the-embedded-month-calendar-control.md).

- DTN_CLOSEUP notifica o pai que o controle de calendário mensal inserido está prestes a ser fechado. Esta notificação é enviada somente quando o estilo de DTS_UPDOWN não foi definido.

- DTN_DATETIMECHANGE notifica o pai de que ocorreu uma alteração no controle.

- DTN_FORMAT Notifica o pai de que o texto é necessário para ser exibido em um campo de retorno de chamada. Para obter mais informações sobre esta notificação e os campos de retorno de chamada, consulte [usando campos de retorno de chamada em um controle seletor de data e hora](using-callback-fields-in-a-date-and-time-picker-control.md).

- DTN_FORMATQUERY solicita que o pai forneça o tamanho máximo permitido da cadeia de caracteres que será exibida em um campo de retorno de chamada. Manipular essa notificação permite que o controle exiba corretamente a saída em todos os momentos, reduzindo a cintilação dentro da exibição do controle. Para obter mais informações sobre essa notificação, consulte [usando campos de retorno de chamada em um controle seletor de data e hora](using-callback-fields-in-a-date-and-time-picker-control.md).

- DTN_USERSTRING notifica o pai de que o usuário concluiu a edição do conteúdo do controle seletor de data e hora. Esta notificação é enviada somente quando o estilo de DTS_APPCANPARSE foi definido.

- DTN_WMKEYDOWN notifica o pai quando o usuário digita em um campo de retorno de chamada. Manipule essa notificação para emular a mesma resposta de teclado com suporte para campos que não são de retorno de chamada em um controle de seletor de data e hora. Para obter mais informações sobre essa notificação, consulte [suporte a campos de retorno de chamada em um controle DTP](/windows/win32/Controls/date-and-time-picker-controls) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CDateTimeCtrl](using-cdatetimectrl.md)<br/>
[Controles](controls-mfc.md)
