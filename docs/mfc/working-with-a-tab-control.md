---
title: "Trabalhando com um controle de guia | Microsoft Docs"
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
  - "Classe CTabCtrl, usando"
  - "controles de guia, usando"
  - "controles de guia, trabalhando com"
ms.assetid: 819488e3-4944-44b7-9483-195edb8e0aed
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Trabalhando com um controle de guia
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maneira mais fácil de usar um controle da guia \([CTabCtrl](../Topic/CTabCtrl%20Class.md)\) é adicionar o a um recurso do modelo da caixa de diálogo com o publicador da caixa de diálogo.  Você também pode usar um controle da guia por si só.  O **InitCommonControls** MFC chama para você.  As tarefas principais são os seguintes:  
  
-   [Criando o controle da guia](../mfc/creating-the-tab-control.md)  
  
-   [Adicionando guias a um controle da guia](../mfc/adding-tabs-to-a-tab-control.md)  
  
-   [Processando notificações de controle da guia](../mfc/processing-tab-control-notification-messages.md)  
  
 Se o objeto de controle da guia é inserido em uma exibição ou uma classe pai da caixa de diálogo, o controle é destruído no pai é destruído.  
  
## Consulte também  
 [Usando CTabCtrl](../mfc/using-ctabctrl.md)   
 [Controles](../mfc/controls-mfc.md)