---
title: "omp_set_nested | Microsoft Docs"
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
  - "omp_set_nested"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "omp_set_nested OpenMP function"
ms.assetid: fa1cb08c-7b8b-42c9-8654-2c33dcffb5b6
caps.latest.revision: 13
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# omp_set_nested
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Habilita o paralelismo aninhado.  
  
## Sintaxe  
  
```  
void omp_set_nested(  
   int val  
);  
```  
  
## Comentários  
 onde,  
  
 `val`  
 Se for diferente de zero, permite o paralelismo aninhado.  Se for zero, desativa o paralelismo aninhado.  
  
## Comentários  
 OMP aninhado paralelismo pode ser ativado com `omp_set_nested`, ou definindo a [OMP\_NESTED](../../../parallel/openmp/reference/omp-nested.md) variável de ambiente.  
  
 A configuração para `omp_set_nested` cancelará a definição da `OMP_NESTED` variável de ambiente.  
  
 Quando ativada, a variável de ambiente pode quebrar um programa de outra forma operacional porque o número de threads aumenta exponencialmente quando regiões paralelas de aninhamento.  Por exemplo, uma função que recurses 6 vezes com o número de segmentos do OMP definido como 4 requer 4.096 \(4 à potência de 6\) segmentos em geral, degrada o desempenho do seu aplicativo se o número de segmento excede o número de processadores.  Uma exceção a isso seria que aplicativos ligados de i\/O.  
  
 Use [omp\_get\_nested](../../../parallel/openmp/reference/omp-get-nested.md) para exibir a configuração atual da `omp_set_nested`.  
  
 Para obter mais informações, consulte [3.1.9 omp\_set\_nested Function](../../../parallel/openmp/3-1-9-omp-set-nested-function.md).  
  
## Exemplo  
  
```  
// omp_set_nested.cpp  
// compile with: /openmp  
#include <stdio.h>  
#include <omp.h>  
  
int main( )   
{  
    omp_set_nested(1);  
    omp_set_num_threads(4);  
    printf_s("%d\n", omp_get_nested( ));  
    #pragma omp parallel  
        #pragma omp master  
        {  
            printf_s("%d\n", omp_get_nested( ));  
        }  
}  
```  
  
  **1**  
**1**   
## Consulte também  
 [Functions](../../../parallel/openmp/reference/openmp-functions.md)