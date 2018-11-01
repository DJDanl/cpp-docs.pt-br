---
title: A.18   Aninhado para diretivas
ms.date: 11/04/2016
ms.assetid: ae2b2e0b-ec94-43f8-928c-6d621b51f0df
ms.openlocfilehash: dbebcd88489c6fdb00011531e7b74b27ee154b4e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50554280"
---
# <a name="a18---nested-for-directives"></a>A.18   Aninhado para diretivas

O exemplo a seguir do `for` aninhamento de diretiva ([seção 2.9](../../parallel/openmp/2-9-directive-nesting.md) na página 33) está em conformidade porque internas e externas `for` diretivas associar a diferente regiões em paralelo:

```
#pragma omp parallel default(shared)
{
    #pragma omp for
        for (i=0; i<n; i++)
        {
            #pragma omp parallel shared(i, n)
            {
                #pragma omp for
                    for (j=0; j<n; j++)
                        work(i, j);
            }
        }
}
```

Uma variação seguir do exemplo anterior também é compatível com:

```
#pragma omp parallel default(shared)
{
    #pragma omp for
        for (i=0; i<n; i++)
            work1(i, n);
}

void work1(int i, int n)
{
    int j;
    #pragma omp parallel default(shared)
    {
        #pragma omp for
            for (j=0; j<n; j++)
                work2(i, j);
    }
    return;
}
```