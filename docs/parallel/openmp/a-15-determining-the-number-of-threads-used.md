---
title: "A.15   Determining the Number of Threads Used | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 026bb59a-f668-40db-a7cb-69a1bae83d2d
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# A.15   Determining the Number of Threads Used
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Considere o seguinte exemplo incorreto \(para  [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37\):  
  
```  
np = omp_get_num_threads(); // misplaced   
#pragma omp parallel for schedule(static)  
    for (i=0; i<np; i++)  
        work(i);  
```  
  
 O `omp_get_num_threads()` chamar retorna 1 na seção serial do código, então,  *np* será sempre igual a 1, no exemplo anterior.  Para determinar o número de threads que serão implantados para a região paralela, a chamada deve ser dentro da região paralela.  
  
 O exemplo a seguir mostra como reconfigurar este programa sem incluir uma consulta para o número de segmentos:  
  
```  
#pragma omp parallel private(i)  
{  
    i = omp_get_thread_num();  
    work(i);  
}  
```