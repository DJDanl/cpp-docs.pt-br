---
title: "OpenMP Functions | Microsoft Docs"
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
ms.assetid: a55a2e5c-a260-44ee-bbd6-de7e2351b384
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# OpenMP Functions
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Fornece links para as funções usadas na API OpenMP.  
  
 A implementação do Visual C\+\+ do OpenMP padrão inclui as seguintes funções.  
  
|Função|Descrição|  
|------------|---------------|  
|[omp\_destroy\_lock](../../../parallel/openmp/reference/omp-destroy-lock.md)|Uninitializes um bloqueio.|  
|[omp\_destroy\_nest\_lock](../../../parallel/openmp/reference/omp-destroy-nest-lock.md)|Uninitializes um bloqueio de nestable.|  
|[omp\_get\_dynamic](../../../parallel/openmp/reference/omp-get-dynamic.md)|Retorna um valor que indica se o número de threads disponíveis na região paralela subseqüente pode ser ajustado pelo tempo de execução.|  
|[omp\_get\_max\_threads](../Topic/omp_get_max_threads.md)|Retorna um inteiro que é igual ou maior que o número de segmentos que estaria disponível se uma região paralela sem [num\_threads](../../../parallel/openmp/reference/num-threads.md) foram definidas nesse ponto no código.|  
|[omp\_get\_nested](../../../parallel/openmp/reference/omp-get-nested.md)|Retorna um valor que indica se o paralelismo aninhado está ativado.|  
|[omp\_get\_num\_procs](../../../parallel/openmp/reference/omp-get-num-procs.md)|Retorna o número de processadores que estão disponíveis quando a função é chamada.|  
|[omp\_get\_num\_threads](../Topic/omp_get_num_threads.md)|Retorna o número de segmentos na região paralela.|  
|[omp\_get\_thread\_num](../../../parallel/openmp/reference/omp-get-thread-num.md)|Retorna o número de threads do thread em execução dentro de sua equipe de thread.|  
|[omp\_get\_wtick](../Topic/omp_get_wtick.md)|Retorna o número de segundos entre marcações do clock de processador.|  
|[omp\_get\_wtime](../../../parallel/openmp/reference/omp-get-wtime.md)|Retorna que um valor em segundos do tempo decorrido desde algum ponto.|  
|[omp\_in\_parallel](../../../parallel/openmp/reference/omp-in-parallel.md)|Retorna um diferente de zero se for chamado de dentro de uma região paralela.|  
|[omp\_init\_lock](../../../parallel/openmp/reference/omp-init-lock.md)|Inicializa um bloqueio simple.|  
|[omp\_init\_nest\_lock](../Topic/omp_init_nest_lock.md)|Inicializa um bloqueio.|  
|[omp\_set\_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md)|Indica que o número de threads disponíveis na região paralela subseqüente pode ser ajustado pelo tempo de execução.|  
|[omp\_set\_lock](../../../parallel/openmp/reference/omp-set-lock.md)|Blocos de thread de execução até que um bloqueio está disponível.|  
|[omp\_set\_nest\_lock](../../../parallel/openmp/reference/omp-set-nest-lock.md)|Blocos de thread de execução até que um bloqueio está disponível.|  
|[omp\_set\_nested](../../../parallel/openmp/reference/omp-set-nested.md)|Habilita o paralelismo aninhado.|  
|[omp\_set\_num\_threads](../../../parallel/openmp/reference/omp-set-num-threads.md)|Define o número de segmentos subseqüentes regiões paralelas, a menos que substituída por uma [num\_threads](../../../parallel/openmp/reference/num-threads.md) cláusula.|  
|[omp\_test\_lock](../../../parallel/openmp/reference/omp-test-lock.md)|Tenta definir um bloqueio, mas não bloqueia a execução da thread.|  
|[omp\_test\_nest\_lock](../../../parallel/openmp/reference/omp-test-nest-lock.md)|Tenta definir um bloqueio de nestable, mas não bloqueia a execução da thread.|  
|[omp\_unset\_lock](../../../parallel/openmp/reference/omp-unset-lock.md)|Libera um bloqueio.|  
|[omp\_unset\_nest\_lock](../../../parallel/openmp/reference/omp-unset-nest-lock.md)|Libera um bloqueio de nestable.|  
  
## Consulte também  
 [Library Reference](../../../parallel/openmp/reference/openmp-library-reference.md)