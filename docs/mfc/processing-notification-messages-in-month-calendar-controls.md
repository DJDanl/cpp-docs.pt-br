---
title: Processando mensagens de notificação em controles de calendário mensal
ms.date: 11/04/2016
helpviewer_keywords:
- CMonthCalCtrl class [MFC], notifications
- CMonthCalCtrl class [MFC], day states
- month calendar controls [MFC], notification messages
- notifications [MFC], for CMonthCalCtrl
- notifications [MFC], month calendar control
ms.assetid: 607c3e90-0756-493b-9503-ce835a50c7ab
ms.openlocfilehash: 452d24bf1ffd157366f357a510e8c8cfaad28d91
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70908077"
---
# <a name="processing-notification-messages-in-month-calendar-controls"></a>Processando mensagens de notificação em controles de calendário mensal

À medida que os usuários interagem com o controle de calendário mensal (selecionando datas e/ou exibindo um`CMonthCalCtrl`mês diferente), o controle () envia mensagens de notificação para sua janela pai, geralmente uma exibição ou objeto de caixa de diálogo. Manipule essas mensagens se desejar fazer algo em resposta. Por exemplo, quando o usuário seleciona um novo mês para exibição, você pode fornecer um conjunto de datas que devem ser enfatizadas.

Use o [Assistente de classe](reference/mfc-class-wizard.md) para adicionar manipuladores de notificação à classe pai para as mensagens que você deseja implementar.

A lista a seguir descreve as várias notificações enviadas pelo controle de calendário mensal.

- MCN_GETDAYSTATE solicita informações sobre quais dias devem ser exibidos em negrito. Para obter informações sobre como lidar com essa notificação, consulte [definindo o estado do dia de um controle de calendário mensal](../mfc/setting-the-day-state-of-a-month-calendar-control.md).

- MCN_SELCHANGE notifica o pai de que a data ou o intervalo selecionado da data foi alterado.

- MCN_SELECT notifica o pai de que uma seleção de data explícita foi feita.

## <a name="see-also"></a>Consulte também

[Usando CMonthCalCtrl](../mfc/using-cmonthcalctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
