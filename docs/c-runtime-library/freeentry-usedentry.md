---
title: "_FREEENTRY, _USEDENTRY | Microsoft Docs"
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
  - "USEDENTRY"
  - "_USEDENTRY"
  - "_FREEENTRY"
  - "FREEENTRY"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _FREEENTRY"
  - "Constante _USEDENTRY"
  - "Constante FREEENTRY"
  - "Constante USEDENTRY"
ms.assetid: 26f658e6-6846-4a4e-9984-262cfe392770
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _FREEENTRY, _USEDENTRY
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
#include <malloc.h>  
```  
  
## Comentários  
 Essas constantes representam os valores atribuídos por rotinas de `_heapwalk` ao elemento de **\_useflag** da estrutura de **\_HEAPINFO** .  Indica o status de entrada do heap.  
  
## Consulte também  
 [\_heapwalk](../Topic/_heapwalk.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)