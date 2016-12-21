---
title: "omp_unset_nest_lock | Microsoft Docs"
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
  - "omp_unset_nest_lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "omp_unset_nest_lock OpenMP function"
ms.assetid: 1721d061-3f9c-45d7-b479-a665cd0a121d
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# omp_unset_nest_lock
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Libera um bloqueio de nestable.  
  
## Sintaxe  
  
```  
void omp_unset_nest_lock(   
   omp_nest_lock_t *lock   
);  
```  
  
## Comentários  
 onde,  
  
 `lock`  
 Uma variável do tipo [omp\_nest\_lock\_t](../Topic/omp_nest_lock_t.md) que foi inicializado com [omp\_init\_nest\_lock](../Topic/omp_init_nest_lock.md), controlada pelo thread e em execução na função.  
  
## Comentários  
 Para obter mais informações, consulte [3.2.4 omp\_unset\_lock and omp\_unset\_nest\_lock Functions](../Topic/3.2.4%20omp_unset_lock%20and%20omp_unset_nest_lock%20Functions.md).  
  
## Exemplo  
 Consulte [omp\_init\_nest\_lock](../Topic/omp_init_nest_lock.md) para obter um exemplo do uso de `omp_unset_nest_lock`.  
  
## Consulte também  
 [Functions](../../../parallel/openmp/reference/openmp-functions.md)