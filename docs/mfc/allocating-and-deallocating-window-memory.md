---
title: "Alocando e desalocando a mem&#243;ria da janela | Microsoft Docs"
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
  - "alocação de memória, objetos de janela"
  - "desalocação de memória"
  - "desalocação de memória, memória de janela"
  - "armazenamento para objetos de janela"
  - "armazenamento para objetos de janela, alocando"
  - "objetos de janela, desalocando memória para"
ms.assetid: 7c962539-8461-4846-b5ca-fe3b15c313dc
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Alocando e desalocando a mem&#243;ria da janela
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Não use o operador C\+\+ **delete** para destruição uma janela ou exibição do quadro.  Em vez disso, chame a função de membro `DestroyWindow`de `CWnd` .  Peça o windows, consequentemente, deve ser atribuído no heap com o operador **new**.  Tenha cuidado ao atribuir o windows do quadro no quadro de pilhas ou global.  Outras janelas devem ser atribuídas no quadro de pilhas sempre que possível.  
  
## Que você deseja saber mais?  
  
-   [Criando o windows](../Topic/Creating%20Windows.md)  
  
-   [Sequência de destruição da janela](../mfc/window-destruction-sequence.md)  
  
-   [Desanexando um CWnd do HWND](../Topic/Detaching%20a%20CWnd%20from%20Its%20HWND.md)  
  
## Consulte também  
 [Destruindo objetos de janela](../mfc/destroying-window-objects.md)