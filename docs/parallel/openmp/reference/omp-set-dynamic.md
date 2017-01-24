---
title: "omp_set_dynamic | Microsoft Docs"
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
  - "omp_set_dynamic"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "omp_set_dynamic OpenMP function"
ms.assetid: 3845faf2-a0ca-45a5-ae70-2a7a6164f1e8
caps.latest.revision: 12
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# omp_set_dynamic
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Indica que o número de threads disponíveis na região paralela subseqüente pode ser ajustado pelo tempo de execução.  
  
## Sintaxe  
  
```  
void omp_set_dynamic(  
   int val  
);  
```  
  
## Comentários  
 onde,  
  
 `val`  
 Um valor que indica se o número de threads disponíveis na região paralela subseqüente pode ser ajustado pelo tempo de execução.  Se for diferente de zero, que o runtime pode ajustar o número de segmentos, se for zero, o runtime não irá ajustar dinamicamente o número de segmentos.  
  
## Comentários  
 O número de segmentos nunca excederá o valor definido pelo [omp\_set\_num\_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) ou por [OMP\_NUM\_THREADS](../Topic/OMP_NUM_THREADS.md).  
  
 Use [omp\_get\_dynamic](../../../parallel/openmp/reference/omp-get-dynamic.md) para exibir a configuração atual da `omp_set_dynamic`.  
  
 A configuração para `omp_set_dynamic` cancelará a definição da [OMP\_DYNAMIC](../../../parallel/openmp/reference/omp-dynamic.md) variável de ambiente.  
  
 Para obter mais informações, consulte [3.1.7 omp\_set\_dynamic Function](../../../parallel/openmp/3-1-7-omp-set-dynamic-function.md).  
  
## Exemplo  
  
```  
// omp_set_dynamic.cpp  
// compile with: /openmp  
#include <stdio.h>  
#include <omp.h>  
  
int main()   
{  
    omp_set_dynamic(9);  
    omp_set_num_threads(4);  
    printf_s("%d\n", omp_get_dynamic( ));  
    #pragma omp parallel  
        #pragma omp master  
        {  
            printf_s("%d\n", omp_get_dynamic( ));  
        }  
}  
```  
  
  **1**  
**1**   
## Consulte também  
 [Functions](../../../parallel/openmp/reference/openmp-functions.md)