---
title: A.3   Usando regiões em paralelo
ms.date: 11/04/2016
ms.assetid: 575216a1-960a-47f7-9c82-7f660291fcfe
ms.openlocfilehash: 573c4f7c47c90bc6d567c4640360aa6abee5a48c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50458980"
---
# <a name="a3---using-parallel-regions"></a>A.3   Usando regiões em paralelo

O `parallel` diretiva ([seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8) pode ser usado em programas paralelos de alta granularidade. No exemplo a seguir, cada thread na região paralela decide qual parte da matriz global `x` funcione, com base no número de threads:

```
#pragma omp parallel shared(x, npoints) private(iam, np, ipoints)
{
    iam = omp_get_thread_num();
    np =  omp_get_num_threads();
    ipoints = npoints / np;
    subdomain(x, iam, ipoints);
}
```