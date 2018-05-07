---
title: Processando mensagens de notificação no mês de controles de calendário | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CMonthCalCtrl class [MFC], notifications
- CMonthCalCtrl class [MFC], day states
- month calendar controls [MFC], notification messages
- notifications [MFC], for CMonthCalCtrl
- notifications [MFC], month calendar control
ms.assetid: 607c3e90-0756-493b-9503-ce835a50c7ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 26b4d73284b0cff362ba16248e0906b76c7f52a1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="processing-notification-messages-in-month-calendar-controls"></a>Processando mensagens de notificação em controles de calendário mensal
Como os usuários interagem com o controle de calendário mensal (seleção das datas e/ou exibir um mês diferente), o controle (`CMonthCalCtrl`) envia mensagens de notificação para sua janela pai, geralmente um objeto de exibição ou a caixa de diálogo. Se você quiser fazer algo em resposta, lidar com essas mensagens. Por exemplo, quando o usuário seleciona um novo mês para exibir, você pode fornecer um conjunto de datas que deve ser enfatizado.  
  
 Use a janela Propriedades para adicionar manipuladores de notificação para a classe pai para as mensagens que você deseja implementar.  
  
 A lista a seguir descreve as várias notificações enviadas pelo controle de calendário mensal.  
  
-   **MCN_GETDAYSTATE** solicita informações sobre quais dias devem ser exibidos em negrito. Para obter informações sobre como tratar essa notificação, consulte [definindo o estado do dia de um controle de calendário mensal](../mfc/setting-the-day-state-of-a-month-calendar-control.md).  
  
-   **MCN_SELCHANGE** notifica o pai que o intervalo de data ou data selecionada foi alterada.  
  
-   **MCN_SELECT** notifica o pai que foi feita uma seleção de data explícita.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CMonthCalCtrl](../mfc/using-cmonthcalctrl.md)   
 [Controles](../mfc/controls-mfc.md)

