---
title: "omp_set_lock | Microsoft Docs"
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
  - "omp_set_lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "omp_set_lock OpenMP function"
ms.assetid: ded839cb-ca19-403f-8622-eb52ce512d31
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# omp_set_lock
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Blocos de thread de execução até que um bloqueio está disponível.  
  
## Sintaxe  
  
```  
void omp_set_lock(  
   omp_lock_t *lock  
);  
```  
  
## Comentários  
 onde,  
  
 `lock`  
 Uma variável do tipo [omp\_lock\_t](../../../parallel/openmp/reference/omp-lock-t.md) que foi inicializado com [omp\_init\_lock](../../../parallel/openmp/reference/omp-init-lock.md).  
  
## Comentários  
 Para obter mais informações, consulte [3.2.3 omp\_set\_lock and omp\_set\_nest\_lock Functions](../Topic/3.2.3%20omp_set_lock%20and%20omp_set_nest_lock%20Functions.md).  
  
## Exemplos  
 Consulte [omp\_init\_lock](../../../parallel/openmp/reference/omp-init-lock.md) para obter um exemplo do uso de `omp_set_lock`.  
  
## Consulte também  
 [Functions](../../../parallel/openmp/reference/openmp-functions.md)