---
title: "3.1.2 omp_get_num_threads Function | Microsoft Docs"
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
ms.assetid: bcdd76e2-d96b-4884-ac8f-e55fc0c42801
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 3.1.2 omp_get_num_threads Function
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **omp\_get\_num\_threads** função retorna o número de segmentos atualmente na equipe executando a região paralela do qual ele é chamado.  O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_get_num_threads(void);  
```  
  
 O  **num\_threads** cláusula, o  **omp\_set\_num\_threads** função e o  **OMP\_NUM\_THREADS** variável de ambiente controlar o número de threads em uma equipe.  
  
 Se o número de segmentos não foi explicitamente definido pelo usuário, o padrão é definido para implementação.  Esta função é ligado a mais próxima circunscrito  **paralela** diretiva.  Se chamado a partir de uma parte serial de um programa ou uma região paralela aninhada que for serializada, esta função retorna 1.  
  
## Entre as referências:  
  
-   **OMP\_NUM\_THREADS** consulte variável, do ambiente  [seção 4.2](../../parallel/openmp/4-2-omp-num-threads.md) na página 48.  
  
-   **num\_threads** cláusula, consulte  [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8.  
  
-   **paralela** construir, consulte  [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8.