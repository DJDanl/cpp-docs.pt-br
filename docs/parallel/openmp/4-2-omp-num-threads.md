---
title: 4.2 OMP_NUM_THREADS
ms.date: 11/04/2016
ms.assetid: 49dd55dd-25d5-4a5a-a998-cc7f47b2dae2
ms.openlocfilehash: 88ddfc226b8ae905e026e2f0979e07581d1ae83b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50668202"
---
# <a name="42-ompnumthreads"></a>4.2 OMP_NUM_THREADS

O **OMP_NUM_THREADS** variável de ambiente define o número padrão de threads a serem usados durante a execução, a menos que esse número seja explicitamente alterado por meio da chamada a **omp_set_num_threads** rotina de biblioteca ou por um explícito **num_threads** cláusula em uma **paralela** diretiva.

O valor de **OMP_NUM_THREADS** variável de ambiente deve ser um inteiro positivo. Seu efeito depende se o ajuste dinâmico do número de threads está habilitado. Para um conjunto abrangente de regras sobre a interação entre o **OMP_NUM_THREADS** ambiente ajuste dinâmico e variável de threads, consulte a seção 2.3 na página de 8.

Se nenhum valor for especificado para o **OMP_NUM_THREADS** variável de ambiente, ou se o valor especificado não é um inteiro positivo, ou se o valor for maior que o número máximo de threads do sistema pode dar suporte, o número de threads a serem usados é definido pela implementação.

Exemplo:

```
setenv OMP_NUM_THREADS 16
```

## <a name="cross-references"></a>Entre as referências:

- **num_threads** cláusula, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.

- **omp_set_num_threads** , consulte [seção 3.1.1](../../parallel/openmp/3-1-1-omp-set-num-threads-function.md) na página de 36.

- **omp_set_dynamic** , consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.