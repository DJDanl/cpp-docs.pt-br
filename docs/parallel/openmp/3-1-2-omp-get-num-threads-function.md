---
title: 3.1.2 função omp_get_num_threads
ms.date: 11/04/2016
ms.assetid: bcdd76e2-d96b-4884-ac8f-e55fc0c42801
ms.openlocfilehash: 587b49f70896bcfe8c1a805a4ebb13a11e9bb7d0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50465237"
---
# <a name="312-ompgetnumthreads-function"></a>3.1.2 função omp_get_num_threads

O **omp_get_num_threads** função retorna o número de threads atualmente na equipe que está executando a região paralela do qual ele é chamado. O formato é o seguinte:

```
#include <omp.h>
int omp_get_num_threads(void);
```

O **num_threads** cláusula, a **omp_set_num_threads** função e o **OMP_NUM_THREADS** variável de ambiente controla o número de threads em uma equipe.

Se o número de threads não foi explicitamente definido pelo usuário, o padrão é definido pela implementação. Essa função é associado a mais próxima circunscrição **paralela** diretiva. Se chamado de uma parte serial de um programa ou de uma região paralela aninhada que é serializada, essa função retorna 1.

## <a name="cross-references"></a>Entre as referências:

- **OMP_NUM_THREADS** consulte de variável de ambiente [seção 4.2](../../parallel/openmp/4-2-omp-num-threads.md) na página 48.

- **num_threads** cláusula, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.

- **Parallel** construir, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.