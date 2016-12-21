---
title: "atomic | Microsoft Docs"
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
  - "atomic"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "atomic OpenMP directive"
ms.assetid: 275e0338-cf2f-4525-97b5-696250000df7
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# atomic
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Especifica que um local de memória que será atualizado atomicamente.  
  
## Sintaxe  
  
```  
#pragma omp atomic  
   expression  
```  
  
#### Parâmetros  
 `expression`  
 A instrução que contém o lvalue cuja localização de memória que você deseja proteger contra várias gravações.  Para obter mais informações sobre formulários de expressão legal, consulte a especificação do OpenMP.  
  
## Comentários  
 O `atomic` diretiva oferece suporte a cláusulas sem OpenMP.  
  
 Para obter mais informações, consulte [2.6.4 atomic Construct](../../../parallel/openmp/2-6-4-atomic-construct.md).  
  
## Exemplo  
  
```  
// omp_atomic.cpp  
// compile with: /openmp   
#include <stdio.h>  
#include <omp.h>  
  
#define MAX 10  
  
int main() {  
   int count = 0;  
   #pragma omp parallel num_threads(MAX)  
   {  
      #pragma omp atomic  
      count++;  
   }  
   printf_s("Number of threads: %d\n", count);  
}  
```  
  
  **Número de segmentos: 10**   
## Consulte também  
 [OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)