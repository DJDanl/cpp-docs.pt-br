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
ms.openlocfilehash: fc0bb475a95450c281c92b500083c9502df50931
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64346138"
---
# <a name="processing-notification-messages-in-month-calendar-controls"></a>Processando mensagens de notificação em controles de calendário mensal

Conforme os usuários interagem com o controle de calendário mensal (seleção das datas e/ou exibir um mês diferente), o controle (`CMonthCalCtrl`) envia mensagens de notificação à sua janela pai, normalmente, um objeto de exibição ou a caixa de diálogo. Se você quiser fazer algo em resposta, lidar com essas mensagens. Por exemplo, quando o usuário seleciona um novo mês para exibir, você pode fornecer um conjunto de datas que devem ser enfatizados.

Use a janela Propriedades para adicionar manipuladores de notificação para a classe pai para essas mensagens que você deseja implementar.

A lista a seguir descreve as várias notificações enviadas pelo controle de calendário mensal.

- Informações de solicitações de MCN_GETDAYSTATE sobre quais dias devem ser exibidos em negrito. Para obter informações sobre como manipular essa notificação, consulte [definindo o estado do dia de um controle de calendário mensal](../mfc/setting-the-day-state-of-a-month-calendar-control.md).

- MCN_SELCHANGE notifica o pai que a data selecionada ou intervalo de data foi alterada.

- MCN_SELECT notifica o pai que foi feita uma seleção de data explícita.

## <a name="see-also"></a>Consulte também

[Usando CMonthCalCtrl](../mfc/using-cmonthcalctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
