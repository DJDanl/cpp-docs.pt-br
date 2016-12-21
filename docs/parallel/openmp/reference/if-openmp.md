---
title: "if (OpenMP) | Microsoft Docs"
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
  - "if"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "if OpenMP clause"
ms.assetid: db5940b6-2414-4bf8-934d-3edd8393c0f8
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# if (OpenMP)
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Especifica se deve ser executado um loop em paralelo ou serial.  
  
## Sintaxe  
  
```  
if(expression)  
```  
  
## Comentários  
 onde,  
  
 `expression`  
 Uma expressão integral que, se for avaliada como true \(diferente de zero\), faz com que o código na região paralela para executar em paralelo.  Se a expressão for avaliada como false \(zero\), a região paralela é executado na série \(por um único thread\).  
  
## Comentários  
 `if`aplica as diretivas a seguir:  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [for](../Topic/for%20\(OpenMP\).md)  
  
-   [sections](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.3 parallel Construct](../../../parallel/openmp/2-3-parallel-construct.md).  
  
## Exemplo  
  
```  
// omp_if.cpp  
// compile with: /openmp  
#include <stdio.h>  
#include <omp.h>  
  
void test(int val)  
{  
    #pragma omp parallel if (val)  
    if (omp_in_parallel())  
    {  
        #pragma omp single  
        printf_s("val = %d, parallelized with %d threads\n",  
                 val, omp_get_num_threads());  
    }  
    else  
    {  
        printf_s("val = %d, serialized\n", val);  
    }  
}  
  
int main( )  
{  
    omp_set_num_threads(2);  
    test(0);  
    test(2);  
}  
```  
  
  **Val \= 0, serializado**  
**Val \= 2, colocados em paralelo com 2 segmentos**   
## Consulte também  
 [Clauses](../../../parallel/openmp/reference/openmp-clauses.md)