---
title: "parallel | Microsoft Docs"
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
  - "parallel"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "parallel OpenMP directive"
ms.assetid: b8e90073-e85b-4d39-8ed8-0364441794fb
caps.latest.revision: 12
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# parallel
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Define uma região paralela, que é o código que será executado por vários threads em paralelo.  
  
## Sintaxe  
  
```  
#pragma omp parallel [clauses]  
{  
   code_block  
}  
```  
  
## Comentários  
 onde,  
  
 `clause`\(opcional\)  
 Zero ou mais cláusulas.  Consulte a seção de comentários para obter uma lista das cláusulas suportados pelo  **paralela**.  
  
## Comentários  
 O  **paralela** diretiva suporta as seguintes cláusulas de OpenMP:  
  
-   [copyin](../Topic/copyin.md)  
  
-   [default](../../../parallel/openmp/reference/default-openmp.md)  
  
-   [firstprivate](../Topic/firstprivate.md)  
  
-   [if](../../../parallel/openmp/reference/if-openmp.md)  
  
-   [num\_threads](../../../parallel/openmp/reference/num-threads.md)  
  
-   [private](../../../parallel/openmp/reference/private-openmp.md)  
  
-   [reduction](../../../parallel/openmp/reference/reduction.md)  
  
-   [shared](../../../parallel/openmp/reference/shared-openmp.md)  
  
 **paralela**  também podem ser usados com o [sections](../../../parallel/openmp/reference/sections-openmp.md) e [for](../Topic/for%20\(OpenMP\).md) diretivas.  
  
 Para obter mais informações, consulte [2.3 parallel Construct](../../../parallel/openmp/2-3-parallel-construct.md).  
  
## Exemplo  
 O exemplo a seguir mostra como definir o número de segmentos e definir uma região paralela.  Por padrão, o número de segmentos é igual ao número de processadores lógicos na máquina.  Por exemplo, se você tiver uma máquina com um processador físico que tem o hyperthreading ativado, ele terá dois processadores lógicos e, portanto, dois segmentos.  
  
```  
// omp_parallel.cpp  
// compile with: /openmp   
#include <stdio.h>  
#include <omp.h>  
  
int main() {  
   #pragma omp parallel num_threads(4)  
   {  
      int i = omp_get_thread_num();  
      printf_s("Hello from thread %d\n", i);  
   }  
}  
```  
  
  **Olá do segmento 0**  
**Olá do thread 1**  
**Olá do thread 2**  
**Olá do thread 3**   
## Comment  
 Observe que a ordem de saída pode variar em diferentes máquinas.  
  
## Consulte também  
 [Directives](../../../parallel/openmp/reference/openmp-directives.md)