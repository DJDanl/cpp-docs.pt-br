---
title: "nowait | Microsoft Docs"
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
  - "nowait"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "nowait OpenMP clause"
ms.assetid: 8a74265d-879c-46cf-8071-a1084f24f16e
caps.latest.revision: 9
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# nowait
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Substitui a barreira implícita em uma diretiva.  
  
## Sintaxe  
  
```  
nowait  
```  
  
## Comentários  
 `nowait`aplica as diretivas a seguir:  
  
-   [for](../Topic/for%20\(OpenMP\).md)  
  
-   [sections](../../../parallel/openmp/reference/sections-openmp.md)  
  
-   [single](../Topic/single.md)  
  
 Para obter mais informações, consulte [2.4.1 for Construct](../../../parallel/openmp/2-4-1-for-construct.md),  [2.4.2 sections Construct](../../../parallel/openmp/2-4-2-sections-construct.md) e [2.4.3 single Construct](../../../parallel/openmp/2-4-3-single-construct.md).  
  
## Exemplo  
  
```  
// omp_nowait.cpp  
// compile with: /openmp /c  
#include <stdio.h>  
  
#define SIZE 5  
  
void test(int *a, int *b, int *c, int size)   
{  
    int i;  
    #pragma omp parallel  
    {  
        #pragma omp for nowait  
        for (i = 0; i < size; i++)  
            b[i] = a[i] * a[i];  
  
        #pragma omp for nowait  
        for (i = 0; i < size; i++)  
            c[i] = a[i]/2;  
    }  
}  
  
int main( )   
{  
    int a[SIZE], b[SIZE], c[SIZE];  
    int i;  
  
    for (i=0; i<SIZE; i++)  
        a[i] = i;  
  
    test(a,b,c, SIZE);  
  
    for (i=0; i<SIZE; i++)  
        printf_s("%d, %d, %d\n", a[i], b[i], c[i]);  
}  
```  
  
  **0, 0, 0**  
**1, 1, 0**  
**2, 4, 1**  
**3, 9, 1**  
**4, 16, 2**   
## Consulte também  
 [Clauses](../../../parallel/openmp/reference/openmp-clauses.md)