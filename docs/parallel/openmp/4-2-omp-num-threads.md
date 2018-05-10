---
title: 4.2 OMP_NUM_THREADS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 49dd55dd-25d5-4a5a-a998-cc7f47b2dae2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b6b4208d7fe7d453dd1f701d820a85fce5cd68ba
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="42-ompnumthreads"></a>4.2 OMP_NUM_THREADS
O **OMP_NUM_THREADS** variável de ambiente define o número padrão de threads a serem usados durante a execução, a menos que esse número seja explicitamente alterado chamando o **omp_set_num_threads** rotina de biblioteca ou por explícito **num_threads** cláusula em uma **paralela** diretiva.  
  
 O valor de **OMP_NUM_THREADS** variável de ambiente deve ser um inteiro positivo. Seu efeito depende se o ajuste dinâmico do número de threads está habilitado. Para um conjunto abrangente de regras sobre a interação entre o **OMP_NUM_THREADS** ambiente ajuste dinâmico e variável de threads, consulte a seção 2.3 na página 8.  
  
 Se nenhum valor for especificado para o **OMP_NUM_THREADS** variável de ambiente, ou se o valor especificado não é um inteiro positivo, ou se o valor for maior que o número máximo de threads do sistema pode oferecer suporte, o número de threads a ser usado é definido pela implementação.  
  
 Exemplo:  
  
```  
setenv OMP_NUM_THREADS 16  
```  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **num_threads** cláusula, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.  
  
-   **omp_set_num_threads** funcionam, consulte [seção 3.1.1](../../parallel/openmp/3-1-1-omp-set-num-threads-function.md) na página 36.  
  
-   **omp_set_dynamic** funcionam, consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.