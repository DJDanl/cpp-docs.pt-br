---
title: "Constantes (_locking) | Microsoft Docs"
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
  - "_LK_RLCK"
  - "_LK_NBLCK"
  - "_LK_LOCK"
  - "_LK_NBRLCK"
  - "_LK_UNLCK"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _LK_LOCK"
  - "Constante _LK_NBLCK"
  - "Constante _LK_NBRLCK"
  - "Constante _LK_RLCK"
  - "Constante _LK_UNLCK"
  - "Constante LK_LOCK"
  - "Constante LK_NBLCK"
  - "Constante LK_NBRLCK"
  - "Constante LK_RLCK"
  - "Constante LK_UNLCK"
ms.assetid: c3dc92c8-60e3-4d29-9f50-5d217627c8ad
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes (_locking)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <sys/locking.h>  
  
```  
  
## Comentários  
 O argumento *do modo* na chamada à função de `_locking` especifica a ação de bloqueio ser executado.  
  
 O argumento *de modo* deve ser uma das seguintes constantes manifestas.  
  
 `_LK_LOCK`  
 Bloqueia os bytes especificados.  Se os bytes não podem ser bloqueadas, a função tentará novamente depois de 1 segundos.  Se, depois de 10 tentativas, os bytes não podem ser bloqueadas, a função retornará um erro.  
  
 `_LK_RLCK`  
 Mesmo que `_LK_LOCK`.  
  
 `_LK_NBLCK`  
 Bloqueia os bytes especificados.  Se os bytes não podem ser bloqueadas, a função retornará um erro.  
  
 `_LK_NBRLCK`  
 Mesmo que `_LK_NBLCK`.  
  
 `_LK_UNLCK`  
 Desbloqueia os bytes especificados. \(Os bytes devem ter sido previamente bloqueada.\)  
  
## Consulte também  
 [\_locking](../Topic/_locking.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)