---
title: 3.1.3 função omp_get_max_threads
ms.date: 11/04/2016
ms.assetid: 5548897c-546e-4d19-b37b-a76f6b30a0a9
ms.openlocfilehash: 3f954b5ad75b4bdb4a74323f2ab4e819850269ed
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50546555"
---
# <a name="313-ompgetmaxthreads-function"></a>3.1.3 função omp_get_max_threads

O **omp_get_max_threads** função retorna um inteiro que é garantido que seja pelo menos tão grande quanto o número de threads que seriam usadas para formar uma equipe se uma região parallel sem uma **num_threads** cláusula eram de serem encontradas nesse ponto no código. O formato é o seguinte:

```
#include <omp.h>
int omp_get_max_threads(void);
```

A seguir expressa um limite inferior no valor de **omp_get_max_threads**:

```

threads-used-for-next-team
<= omp_get_max_threads

```

Observe que, se uma região parallel subsequente usa o **num_threads** cláusula para solicitar um número específico de segmentos, a garantia sobre o limite inferior do resultado da **omp_get_max_threads** nenhuma retenção de longo.

O **omp_get_max_threads** o valor de retorno da função pode ser usado para alocar dinamicamente um armazenamento suficiente para todos os threads da equipe formada na região paralela subsequente.

## <a name="cross-references"></a>Entre as referências:

- **omp_get_num_threads** , consulte [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37.

- **omp_set_num_threads** , consulte [seção 3.1.1](../../parallel/openmp/3-1-1-omp-set-num-threads-function.md) na página de 36.

- **omp_set_dynamic** , consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.

- **num_threads** cláusula, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.