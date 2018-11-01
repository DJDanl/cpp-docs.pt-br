---
title: A.15  Determinando o número de threads usados
ms.date: 11/04/2016
ms.assetid: 026bb59a-f668-40db-a7cb-69a1bae83d2d
ms.openlocfilehash: bd5e897eeab35ec73c061d2ae02a4b85772e1255
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50525810"
---
# <a name="a15---determining-the-number-of-threads-used"></a>A.15  Determinando o número de threads usados

Considere o seguinte exemplo incorreto (para [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37):

```
np = omp_get_num_threads(); // misplaced
#pragma omp parallel for schedule(static)
    for (i=0; i<np; i++)
        work(i);
```

O `omp_get_num_threads()` chamar retorna 1 na seção serial do código, então *np* sempre será igual a 1 no exemplo anterior. Para determinar o número de threads que serão implantados para a região paralela, a chamada deve ser dentro da região paralela.

O exemplo a seguir mostra como reescrever esse programa sem a inclusão de uma consulta para o número de threads:

```
#pragma omp parallel private(i)
{
    i = omp_get_thread_num();
    work(i);
}
```