---
title: "Funções (OpenMP) | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: a55a2e5c-a260-44ee-bbd6-de7e2351b384
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 5cfa92648ff899b4900e632854e80b5cfbb3bdb1
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="openmp-functions"></a>Funções (OpenMP)
Fornece links para funções usadas na API do OpenMP.  
  
 A implementação do Visual C++ do OpenMP padrão inclui as seguintes funções.  
  
|Função|Descrição|  
|--------------|-----------------|  
|[omp_destroy_lock](../../../parallel/openmp/reference/omp-destroy-lock.md)|Cancela a inicialização de um bloqueio.|  
|[omp_destroy_nest_lock](../../../parallel/openmp/reference/omp-destroy-nest-lock.md)|Cancela a inicialização de um bloqueio de aninháveis.|  
|[omp_get_dynamic](../../../parallel/openmp/reference/omp-get-dynamic.md)|Retorna um valor que indica se o número de threads disponíveis na região paralela subsequente pode ser ajustado pelo tempo de execução.|  
|[omp_get_max_threads](../../../parallel/openmp/reference/omp-get-max-threads.md)|Retorna um inteiro que é igual ou maior que o número de threads que estariam disponíveis se uma região paralela sem [num_threads](../../../parallel/openmp/reference/num-threads.md) foram definidas nesse ponto no código.|  
|[omp_get_nested](../../../parallel/openmp/reference/omp-get-nested.md)|Retorna um valor que indica se o paralelismo aninhado está habilitado.|  
|[omp_get_num_procs](../../../parallel/openmp/reference/omp-get-num-procs.md)|Retorna o número de processadores que estão disponíveis quando a função for chamada.|  
|[omp_get_num_threads](../../../parallel/openmp/reference/omp-get-num-threads.md)|Retorna o número de threads na região paralela.|  
|[omp_get_thread_num](../../../parallel/openmp/reference/omp-get-thread-num.md)|Retorna o número de threads do thread em execução dentro de sua equipe de thread.|  
|[omp_get_wtick](../../../parallel/openmp/reference/omp-get-wtick.md)|Retorna o número de segundos entre tiques do relógio de processador.|  
|[omp_get_wtime](../../../parallel/openmp/reference/omp-get-wtime.md)|Retorna que um valor em segundos do tempo decorrido desde algum ponto.|  
|[omp_in_parallel](../../../parallel/openmp/reference/omp-in-parallel.md)|Retorna zero se for chamado de dentro de uma região paralela.|  
|[omp_init_lock](../../../parallel/openmp/reference/omp-init-lock.md)|Inicializa um bloqueio simple.|  
|[omp_init_nest_lock](../../../parallel/openmp/reference/omp-init-nest-lock.md)|Inicializa um bloqueio.|  
|[omp_set_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md)|Indica que o número de threads disponíveis na região paralela subsequente pode ser ajustado pelo tempo de execução.|  
|[omp_set_lock](../../../parallel/openmp/reference/omp-set-lock.md)|Blocos de thread de execução até que um bloqueio está disponível.|  
|[omp_set_nest_lock](../../../parallel/openmp/reference/omp-set-nest-lock.md)|Blocos de thread de execução até que um bloqueio está disponível.|  
|[omp_set_nested](../../../parallel/openmp/reference/omp-set-nested.md)|Permitir o paralelismo aninhado.|  
|[omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md)|Define o número de threads em regiões subsequente em paralelo, a menos que substituída por uma [num_threads](../../../parallel/openmp/reference/num-threads.md) cláusula.|  
|[omp_test_lock](../../../parallel/openmp/reference/omp-test-lock.md)|As tentativas de definir um bloqueio, mas não bloqueia a execução de thread.|  
|[omp_test_nest_lock](../../../parallel/openmp/reference/omp-test-nest-lock.md)|As tentativas de definir um bloqueio aninháveis, mas não bloqueia a execução de thread.|  
|[omp_unset_lock](../../../parallel/openmp/reference/omp-unset-lock.md)|Libera um bloqueio.|  
|[omp_unset_nest_lock](../../../parallel/openmp/reference/omp-unset-nest-lock.md)|Libera um bloqueio aninháveis.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca](../../../parallel/openmp/reference/openmp-library-reference.md)
