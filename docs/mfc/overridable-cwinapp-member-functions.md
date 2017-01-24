---
title: "Fun&#231;&#245;es de membro CWinApp substitu&#237;veis | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CWinApp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classe do aplicativo"
  - "Classe CWinApp, substituíveis"
  - "substituição, funções substituíveis em CWinApp"
ms.assetid: 07183d5e-734b-45d9-a8b6-9dde4adac0b4
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es de membro CWinApp substitu&#237;veis
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[CWinApp](../mfc/reference/cwinapp-class.md) fornece várias funções de membro substituível chaves \(`CWinApp` substituirá esses membros da classe [CWinThread](../mfc/reference/cwinthread-class.md), que `CWinApp` se deriva\):  
  
-   [InitInstance](../mfc/initinstance-member-function.md)  
  
-   [Executar](../Topic/Run%20Member%20Function.md)  
  
-   [ExitInstance](../mfc/exitinstance-member-function.md)  
  
-   [OnIdle](../mfc/onidle-member-function.md)  
  
 A única função de membro de `CWinApp` que você deve substituir é `InitInstance`.  
  
## Consulte também  
 [CWinApp: a classe do aplicativo](../Topic/CWinApp:%20The%20Application%20Class.md)