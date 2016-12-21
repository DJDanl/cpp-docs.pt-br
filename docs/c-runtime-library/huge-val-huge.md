---
title: "HUGE_VAL, _HUGE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_HUGE"
apilocation: 
  - "msvcrt.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_HUGE"
  - "HUGE_VAL"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _HUGE"
  - "Constante HUGE_VAL"
  - "valor duplo"
ms.assetid: 3f044b45-02cd-46b2-b1de-87fd0441dd6a
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# HUGE_VAL, _HUGE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <math.h>  
  
```  
  
## Comentários  
 `HUGE_VAL` é o valor duplo representable maior.  Este valor é retornado por muitas funções matemáticas de tempo de execução quando ocorre um erro.  Para algumas funções, –`HUGE_VAL` é retornado.  `HUGE_VAL` é definido como `_HUGE`, mas `HUGE_VAL`de retorno funções matemáticas de tempo de execução.  Você também deve usar `HUGE_VAL` em seu código para manter a consistência.  
  
## Consulte também  
 [Constantes globais](../c-runtime-library/global-constants.md)