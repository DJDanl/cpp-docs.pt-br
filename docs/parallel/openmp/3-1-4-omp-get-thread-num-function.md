---
title: 3.1.4 função omp_get_thread_num
ms.date: 11/04/2016
ms.assetid: 5220402b-c109-4b1f-ba79-002e93d08617
ms.openlocfilehash: eca8522aeab4702be390d98faaf8920f2d732244
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50480919"
---
# <a name="314-ompgetthreadnum-function"></a>3.1.4 função omp_get_thread_num

O `omp_get_thread_num` função retorna o número de threads, dentro de sua equipe do thread executando a função. O reside número de threads entre 0 e **omp_get_num_threads()**-1, inclusivo. O thread mestre da equipe é 0.

O formato é o seguinte:

```
#include <omp.h>
int omp_get_thread_num(void);
```

Se for chamado de uma região serial, `omp_get_thread_num` retornará 0. Se chamado de dentro de uma região paralela aninhada que é serializada, essa função retorna 0.

## <a name="cross-references"></a>Entre as referências:

- `omp_get_num_threads` função, consulte [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37.