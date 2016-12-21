---
title: "omp_destroy_lock | Microsoft Docs"
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
  - "omp_destroy_lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "omp_destroy_lock OpenMP function"
ms.assetid: b73ab036-b76f-4e42-82ff-c89db2edf7c0
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# omp_destroy_lock
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Uninitializes um bloqueio.  
  
## Sintaxe  
  
```  
void omp_destroy_lock(  
   omp_lock_t *lock  
);  
```  
  
## Comentários  
 onde,  
  
 `lock`  
 Uma variável do tipo [omp\_lock\_t](../../../parallel/openmp/reference/omp-lock-t.md) que foi inicializado com [omp\_init\_lock](../../../parallel/openmp/reference/omp-init-lock.md).  
  
## Comentários  
 Para obter mais informações, consulte [3.2.2 omp\_destroy\_lock and omp\_destroy\_nest\_lock Functions](../Topic/3.2.2%20omp_destroy_lock%20and%20omp_destroy_nest_lock%20Functions.md).  
  
## Exemplo  
 Consulte [omp\_init\_lock](../../../parallel/openmp/reference/omp-init-lock.md) para obter um exemplo do uso de `omp_destroy_lock`.  
  
## Consulte também  
 [Functions](../../../parallel/openmp/reference/openmp-functions.md)