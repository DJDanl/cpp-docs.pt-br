---
title: "Processando mensagens de notifica&#231;&#227;o em controles de calend&#225;rio mensal | Microsoft Docs"
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
  - "Classe CMonthCalCtrl, estados do dia"
  - "Classe CMonthCalCtrl, notificações"
  - "controles de calendário mensal, mensagens de notificação"
  - "notificações, para CMonthCalCtrl"
  - "notificações, controle de calendário mensal"
ms.assetid: 607c3e90-0756-493b-9503-ce835a50c7ab
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Processando mensagens de notifica&#231;&#227;o em controles de calend&#225;rio mensal
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Conforme os usuários interagem com o controle de calendário do mês \(que seleciona datas e\/ou que exibe um mês diferente\), o controle`CMonthCalCtrl`\(\) envia notificações à janela pai, geralmente um objeto da exibição ou na caixa de diálogo.  Tratar essas mensagens se você deseja fazer algo na resposta.  Por exemplo, quando o usuário selecionar um novo mês para exibir, você pode fornecer um conjunto de datas que devem ser sublinhadas.  
  
 Use a janela Propriedades para adicionar manipuladores de notificação para a classe pai para essas mensagens que você deseja implementar.  
  
 A lista a seguir descreve as várias notificações enviadas pelo controle de calendário do mês.  
  
-   **MCN\_GETDAYSTATE** solicita informações sobre os dias que devem ser exibidos em negrito.  Para obter mais informações sobre como lidar com essa notificação, consulte [Definindo o estado de dia de um controle de calendário do mês](../mfc/setting-the-day-state-of-a-month-calendar-control.md).  
  
-   **MCN\_SELCHANGE** notifica o pai que a data ou o intervalo selecionado de data são alterados.  
  
-   **MCN\_SELECT** notifica o pai que uma seleção explícita de data esteve feita.  
  
## Consulte também  
 [Usando CMonthCalCtrl](../Topic/Using%20CMonthCalCtrl.md)   
 [Controles](../mfc/controls-mfc.md)