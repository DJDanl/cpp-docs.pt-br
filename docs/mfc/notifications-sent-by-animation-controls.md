---
title: "Notifica&#231;&#245;es enviadas por controles de anima&#231;&#227;o | Microsoft Docs"
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
  - "controles de animação [C++], notificações"
  - "Classe CAnimateCtrl, notificações"
  - "controles [MFC], animação"
  - "notificações, controles de animação"
ms.assetid: 584f5824-446b-4a1a-85f7-ef61842c8186
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Notifica&#231;&#245;es enviadas por controles de anima&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um controle de animação \([CAnimateCtrl](../mfc/reference/canimatectrl-class.md)\) envia dois tipos diferentes de notificações.  As notificações são enviadas na forma de mensagens de [WM\_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) .  
  
 A mensagem de [ACN\_START](http://msdn.microsoft.com/library/windows/desktop/bb761891) é enviado quando o controle de animação início da execução de um recortar.  A mensagem de [ACN\_STOP](http://msdn.microsoft.com/library/windows/desktop/bb761893) é enviado quando o controle de animação foi concluída ou parado executar um recortar.  
  
## Consulte também  
 [Usando CAnimateCtrl](../Topic/Using%20CAnimateCtrl.md)   
 [Controles](../mfc/controls-mfc.md)