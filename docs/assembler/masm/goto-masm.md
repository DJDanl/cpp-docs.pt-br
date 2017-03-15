---
title: "GOTO (MASM) | Microsoft Docs"
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
  - "goto"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "GOTO directive"
ms.assetid: 6a5f73e7-6784-4eae-ac52-4fc77a7f369f
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# GOTO (MASM)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Transfere o assembly para a linha marcada como  **:***macrolabel*.  
  
## Sintaxe  
  
```  
  
GOTO   
macrolabel  
  
```  
  
## Comentários  
 **Ir para** é permitido apenas dentro de  [MACRO](../Topic/MACRO.md),  [para](../../assembler/masm/for-masm.md),  [FORC](../Topic/FORC.md),  [REPITA](../../assembler/masm/repeat.md), e  **ENQUANTO** blocos.  O rótulo deve ser a única diretiva na linha e deve ser precedido por dois pontos principal.  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)