---
title: "sections (OpenMP) | Microsoft Docs"
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
  - "section"
  - "SECTIONS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "sections OpenMP directive"
ms.assetid: 4cd1d776-e198-470e-930a-01fb0ab0a0bd
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# sections (OpenMP)
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Identifica as seções de código seja dividido entre todos os threads.  
  
## Sintaxe  
  
```  
#pragma omp [parallel] sections [clauses]  
{  
   #pragma omp section  
   {  
      code_block   
   }   
}  
```  
  
## Comentários  
 onde,  
  
 `clause`\(opcional\)  
 Zero ou mais cláusulas.  Consulte a seção de comentários para obter uma lista das cláusulas suportados pelo  **seções**.  
  
## Comentários  
 O  **seções** diretiva pode conter zero ou mais  **seção** diretivas.  
  
 O  **seções** diretiva suporta as seguintes cláusulas de OpenMP:  
  
-   [firstprivate](../Topic/firstprivate.md)  
  
-   [lastprivate](../../../parallel/openmp/reference/lastprivate.md)  
  
-   [nowait](../../../parallel/openmp/reference/nowait.md)  
  
-   [private](../../../parallel/openmp/reference/private-openmp.md)  
  
-   [reduction](../../../parallel/openmp/reference/reduction.md)  
  
 Se  **paralela** também for especificado, `clause` pode ser qualquer cláusula aceita pela  **paralela** ou  **seções** diretivas, exceto `nowait`.  
  
 Para obter mais informações, consulte [2.4.2 sections Construct](../../../parallel/openmp/2-4-2-sections-construct.md).  
  
## Exemplo  
  
```  
// omp_sections.cpp  
// compile with: /openmp   
#include <stdio.h>  
#include <omp.h>  
  
int main() {  
    #pragma omp parallel sections num_threads(4)  
    {  
        printf_s("Hello from thread %d\n", omp_get_thread_num());  
        #pragma omp section  
        printf_s("Hello from thread %d\n", omp_get_thread_num());  
    }  
}  
```  
  
  **Olá do segmento 0**  
**Olá do segmento 0**   
## Consulte também  
 [Directives](../../../parallel/openmp/reference/openmp-directives.md)