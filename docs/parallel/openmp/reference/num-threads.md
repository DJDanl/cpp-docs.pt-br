---
title: "num_threads | Microsoft Docs"
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
  - "num_threads"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "num_threads OpenMP clause"
ms.assetid: 09a56fc8-25c7-43e4-bbb5-71cb955d0b93
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# num_threads
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Define o número de segmentos em uma equipe de thread.  
  
## Sintaxe  
  
```  
num_threads(num)  
```  
  
## Comentários  
 onde,  
  
 `num`  
 O número de segmentos  
  
## Comentários  
 O `num_threads` cláusula tem a mesma funcionalidade que o [omp\_set\_num\_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) função.  
  
 `num_threads`aplica as diretivas a seguir:  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [for](../Topic/for%20\(OpenMP\).md)  
  
-   [sections](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.3 parallel Construct](../../../parallel/openmp/2-3-parallel-construct.md).  
  
## Exemplo  
 Consulte [parallel](../../../parallel/openmp/reference/parallel.md) para obter um exemplo do uso de `num_threads` cláusula.  
  
## Consulte também  
 [Clauses](../../../parallel/openmp/reference/openmp-clauses.md)