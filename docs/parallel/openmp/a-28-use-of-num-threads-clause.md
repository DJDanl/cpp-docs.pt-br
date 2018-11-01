---
title: A.28   Uso da cláusula num_threads
ms.date: 11/04/2016
ms.assetid: 26238da1-902c-49b4-9559-0fbc9eaf7f36
ms.openlocfilehash: 99dd327d0a97f561107ffaa6a6ed1435e3772a41
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50492260"
---
# <a name="a28---use-of-numthreads-clause"></a>A.28   Uso da cláusula num_threads

O exemplo a seguir demonstra a `num_threads` cláusula ([seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8). A região paralela é executado com um máximo de 10 threads.

```
#include <omp.h>
main()
{
    omp_set_dynamic(1);
    ...
    #pragma omp parallel num_threads(10)
    {
        ... parallel region ...
    }
}
```