---
title: A.23   Exemplos da diretiva ordered
ms.date: 11/04/2016
ms.assetid: f8fa761b-7fc5-4447-95f9-8571e9ca31bf
ms.openlocfilehash: 2868b771fd57613981f3c6458b48493a1b26eee4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50472264"
---
# <a name="a23---examples-of-the-ordered-directive"></a>A.23   Exemplos da diretiva ordered

É possível ter várias seções ordenadas com uma `for` especificado com o `ordered` cláusula. O primeiro exemplo é em não conformidade porque a API Especifica o seguinte:

"Uma iteração de um loop com um `for` constructo não deve executar a mesma `ordered` diretiva mais de uma vez e ele não devem executar mais de um `ordered` diretiva." (Consulte [seção 2.6.6](../../parallel/openmp/2-6-6-ordered-construct.md) na página 22)

Neste exemplo não compatíveis, todas as iterações execute seções ordenadas 2:

```
#pragma omp for ordered
for (i=0; i<n; i++)
{
    ...
    #pragma omp ordered
    { ... }
    ...
    #pragma omp ordered
    { ... }
    ...
}
```

A conformidade de exemplo a seguir mostra um `for` com mais de uma seção ordenada:

```
#pragma omp for ordered
for (i=0; i<n; i++)
{
    ...
    if (i <= 10)
    {
        ...
        #pragma omp ordered
        { ... }
    }
    ...
    (i > 10)
    {
        ...
        #pragma omp ordered
        { ... }
    }
    ...
}
```