---
title: "ordered (OpenMP Directives) | Microsoft Docs"
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
  - "ordered"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ordered OpenMP directive"
ms.assetid: e1aa703e-d07d-4f6a-9b2a-f4f25203d850
caps.latest.revision: 9
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ordered (OpenMP Directives)
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Especifica que o código em um paralelo loop deve ser executado como um loop seqüencial.  
  
## Sintaxe  
  
```  
#pragma omp ordered  
   structured-block  
```  
  
## Comentários  
 O  **ordenada** diretiva deve estar dentro da extensão dinâmica um [for](../Topic/for%20\(OpenMP\).md) ou  **paralela para** construir com um  **ordenados** cláusula.  
  
 O  **ordenada** diretiva oferece suporte a cláusulas sem OpenMP.  
  
 Para obter mais informações, consulte [2.6.6 ordered Construct](../../../parallel/openmp/2-6-6-ordered-construct.md).  
  
## Exemplo  
  
```  
// omp_ordered.cpp  
// compile with: /openmp   
#include <stdio.h>  
#include <omp.h>  
  
static float a[1000], b[1000], c[1000];  
  
void test(int first, int last)   
{  
    #pragma omp for schedule(static) ordered  
    for (int i = first; i <= last; ++i) {  
        // Do something here.  
        if (i % 2)   
        {  
            #pragma omp ordered   
            printf_s("test() iteration %d\n", i);  
        }  
    }  
}  
  
void test2(int iter)   
{  
    #pragma omp ordered  
    printf_s("test2() iteration %d\n", iter);  
}  
  
int main( )   
{  
    int i;  
    #pragma omp parallel  
    {  
        test(1, 8);  
        #pragma omp for ordered  
        for (i = 0 ; i < 5 ; i++)  
            test2(i);  
    }  
}  
```  
  
  **iteração de Test \(\) 1**  
**iteração de Test \(\) 3**  
**iteração de Test \(\) 5**  
**iteração de Test \(\) 7**  
**iteração de Test2\(\) 0**  
**iteração de Test2\(\) 1**  
**iteração de Test2\(\) 2**  
**iteração de Test2\(\) 3**  
**iteração de Test2\(\) 4**   
## Consulte também  
 [Directives](../../../parallel/openmp/reference/openmp-directives.md)