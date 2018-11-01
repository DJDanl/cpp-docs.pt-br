---
title: 3.1.1 função omp_set_num_threads
ms.date: 11/04/2016
ms.assetid: b94cf2b5-8011-4a3b-ba56-676982642857
ms.openlocfilehash: 20b6b6ced2b4031696f1d019604842ae9b91bda2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50663275"
---
# <a name="311-ompsetnumthreads-function"></a>3.1.1 função omp_set_num_threads

O `omp_set_num_threads` função define o número padrão de threads a serem usados para regiões em paralelo subsequente que não especificam um `num_threads` cláusula. O formato é o seguinte:

```
#include <omp.h>
void omp_set_num_threads(int num_threads);
```

O valor do parâmetro *num_threads* deve ser um inteiro positivo. Seu efeito depende se o ajuste dinâmico do número de threads está habilitado. Para um conjunto abrangente de regras sobre a interação entre o `omp_set_num_threads` função e o ajuste dinâmico de threads, consulte a seção 2.3 na página de 8.

Essa função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa em que o `omp_in_parallel` função retorna zero. Se ele é chamado de uma parte do programa em que o `omp_in_parallel` função retorna um valor diferente de zero, o comportamento dessa função é indefinido.

Essa chamada tem precedência sobre o `OMP_NUM_THREADS` variável de ambiente. O valor padrão para o número de threads, o que pode ser estabelecida chamando `omp_set_num_threads` ou definindo o `OMP_NUM_THREADS` variável de ambiente podem ser substituídos explicitamente em uma única **paralela** diretiva especificando o `num_threads` cláusula.

## <a name="cross-references"></a>Entre as referências:

- `omp_set_dynamic` função, consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.

- `omp_get_dynamic` função, consulte [seção 3.1.8](../../parallel/openmp/3-1-8-omp-get-dynamic-function.md) na página de 40.

- `OMP_NUM_THREADS` Consulte de variável de ambiente [4.2 seção](../../parallel/openmp/4-2-omp-num-threads.md) página 48, e a seção 2.3 na página de 8.

- `num_threads` cláusula, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8