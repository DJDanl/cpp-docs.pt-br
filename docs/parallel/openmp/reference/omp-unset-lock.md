---
title: "omp_unset_lock | Microsoft Docs"
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
  - "omp_unset_lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "omp_unset_lock OpenMP function"
ms.assetid: 68fcb728-040b-4bad-979e-aaecb9097a4e
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# omp_unset_lock
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Libera um bloqueio.  
  
## Sintaxe  
  
```  
void omp_unset_lock(  
   omp_lock_t *lock  
);  
```  
  
## Comentários  
 onde,  
  
 `lock`  
 Uma variável do tipo [omp\_lock\_t](../../../parallel/openmp/reference/omp-lock-t.md) que foi inicializado com [omp\_init\_lock](../../../parallel/openmp/reference/omp-init-lock.md), controlada pelo thread e em execução na função.  
  
## Comentários  
 Para obter mais informações, consulte [3.2.4 omp\_unset\_lock and omp\_unset\_nest\_lock Functions](../Topic/3.2.4%20omp_unset_lock%20and%20omp_unset_nest_lock%20Functions.md).  
  
## Exemplo  
 Consulte [omp\_init\_lock](../../../parallel/openmp/reference/omp-init-lock.md) para obter um exemplo do uso de `omp_unset_lock`.  
  
## Consulte também  
 [Functions](../../../parallel/openmp/reference/openmp-functions.md)