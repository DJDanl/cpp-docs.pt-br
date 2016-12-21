---
title: "CLOCKS_PER_SEC, CLK_TCK | Microsoft Docs"
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
  - "CLOCKS_PER_SEC"
  - "CLK_TCK"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante CLK_TCK"
  - "CLOCKS_PER_SEC"
ms.assetid: bc285106-383d-44cb-91bf-276ad7de57bf
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# CLOCKS_PER_SEC, CLK_TCK
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <time.h>  
```  
  
## Comentários  
 O tempo em segundos são o valor retornado pela função de `clock` , dividida por `CLOCKS_PER_SEC`.  `CLK_TCK` é equivalente, mas considerado obsoleto.  
  
## Consulte também  
 [clock](../c-runtime-library/reference/clock.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)