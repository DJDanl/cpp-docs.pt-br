---
title: "omp_set_nest_lock | Microsoft Docs"
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
  - "omp_set_nest_lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "omp_set_nest_lock OpenMP function"
ms.assetid: b98ed889-ff8e-4217-a3e9-3993ed8699af
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# omp_set_nest_lock
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Blocos de thread de execução até que um bloqueio está disponível.  
  
## Sintaxe  
  
```  
void omp_set_nest_lock(  
   omp_nest_lock_t *lock  
);  
```  
  
## Comentários  
 onde,  
  
 `lock`  
 Uma variável do tipo [omp\_nest\_lock\_t](../Topic/omp_nest_lock_t.md) que foi inicializado com [omp\_init\_nest\_lock](../Topic/omp_init_nest_lock.md).  
  
## Comentários  
 Para obter mais informações, consulte [3.2.3 omp\_set\_lock and omp\_set\_nest\_lock Functions](../Topic/3.2.3%20omp_set_lock%20and%20omp_set_nest_lock%20Functions.md).  
  
## Exemplos  
 Consulte [omp\_init\_nest\_lock](../Topic/omp_init_nest_lock.md) para obter um exemplo do uso de `omp_set_nest_lock`.  
  
## Consulte também  
 [Functions](../../../parallel/openmp/reference/openmp-functions.md)