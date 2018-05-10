---
title: Funções (OpenMP) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
dev_langs:
- C++
ms.assetid: a55a2e5c-a260-44ee-bbd6-de7e2351b384
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a39fe44ff053a2e49a1067d0af071353e0a50ece
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="openmp-functions"></a>Funções (OpenMP)
Fornece links para funções usadas na API do OpenMP.  
  
 A implementação do Visual C++ do OpenMP padrão inclui as seguintes funções.  
  
|Função|Descrição|  
|--------------|-----------------|  
|[omp_destroy_lock](../../../parallel/openmp/reference/omp-destroy-lock.md)|Uninitializes um bloqueio.|  
|[omp_destroy_nest_lock](../../../parallel/openmp/reference/omp-destroy-nest-lock.md)|Uninitializes um bloqueio empilhável.|  
|[omp_get_dynamic](../../../parallel/openmp/reference/omp-get-dynamic.md)|Retorna um valor que indica se o número de threads disponíveis na região parallel subsequente pode ser ajustado por tempo de execução.|  
|[omp_get_max_threads](../../../parallel/openmp/reference/omp-get-max-threads.md)|Retorna um inteiro que é igual ou maior que o número de threads que estariam disponíveis se uma região parallel sem [num_threads](../../../parallel/openmp/reference/num-threads.md) foram definidas nesse ponto no código.|  
|[omp_get_nested](../../../parallel/openmp/reference/omp-get-nested.md)|Retorna um valor que indica se o paralelismo aninhado está habilitado.|  
|[omp_get_num_procs](../../../parallel/openmp/reference/omp-get-num-procs.md)|Retorna o número de processadores que estão disponíveis quando a função é chamada.|  
|[omp_get_num_threads](../../../parallel/openmp/reference/omp-get-num-threads.md)|Retorna o número de threads na região paralela.|  
|[omp_get_thread_num](../../../parallel/openmp/reference/omp-get-thread-num.md)|Retorna o número de threads de execução de thread dentro de sua equipe de thread.|  
|[omp_get_wtick](../../../parallel/openmp/reference/omp-get-wtick.md)|Retorna o número de segundos entre tiques do relógio de processador.|  
|[omp_get_wtime](../../../parallel/openmp/reference/omp-get-wtime.md)|Retorna que um valor em segundos do tempo decorrido de algum momento.|  
|[omp_in_parallel](../../../parallel/openmp/reference/omp-in-parallel.md)|Retorna nulo se chamado de dentro de uma região parallel.|  
|[omp_init_lock](../../../parallel/openmp/reference/omp-init-lock.md)|Inicializa um bloqueio simple.|  
|[omp_init_nest_lock](../../../parallel/openmp/reference/omp-init-nest-lock.md)|Inicializa um bloqueio.|  
|[omp_set_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md)|Indica que o número de threads disponíveis na região parallel subsequente pode ser ajustado por tempo de execução.|  
|[omp_set_lock](../../../parallel/openmp/reference/omp-set-lock.md)|Blocos de thread de execução até que um bloqueio esteja disponível.|  
|[omp_set_nest_lock](../../../parallel/openmp/reference/omp-set-nest-lock.md)|Blocos de thread de execução até que um bloqueio esteja disponível.|  
|[omp_set_nested](../../../parallel/openmp/reference/omp-set-nested.md)|Permitir o paralelismo aninhado.|  
|[omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md)|Define o número de threads em regiões paralelas subsequentes, a menos que substituído por um [num_threads](../../../parallel/openmp/reference/num-threads.md) cláusula.|  
|[omp_test_lock](../../../parallel/openmp/reference/omp-test-lock.md)|As tentativas de definir um bloqueio, mas não bloqueia a execução de thread.|  
|[omp_test_nest_lock](../../../parallel/openmp/reference/omp-test-nest-lock.md)|As tentativas de definir um bloqueio empilhável mas não bloqueia a execução de thread.|  
|[omp_unset_lock](../../../parallel/openmp/reference/omp-unset-lock.md)|Libera um bloqueio.|  
|[omp_unset_nest_lock](../../../parallel/openmp/reference/omp-unset-nest-lock.md)|Libera um bloqueio empilhável.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca](../../../parallel/openmp/reference/openmp-library-reference.md)