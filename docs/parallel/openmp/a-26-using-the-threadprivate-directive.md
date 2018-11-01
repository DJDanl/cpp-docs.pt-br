---
title: A.26   Usando a diretiva threadprivate
ms.date: 11/04/2016
ms.assetid: 6eda76c2-c4f1-4208-a900-e0ea98a53eca
ms.openlocfilehash: 8ea810f8fbf8076b28464faafb72f5797d4a1a66
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50465423"
---
# <a name="a26---using-the-threadprivate-directive"></a>A.26   Usando a diretiva threadprivate

Os exemplos a seguir demonstram como usar o `threadprivate` diretiva ([seção 2.7.1](../../parallel/openmp/2-7-1-threadprivate-directive.md) na página 23) para dar a cada thread um contador separado.

**Exemplo 1:**

```
int counter = 0;
#pragma omp threadprivate(counter)

int sub()
{
    counter++;
    return(counter);
}
```

**Exemplo 2:**

```
int sub()
{
    static int counter = 0;
    #pragma omp threadprivate(counter)
    counter++;
    return(counter);
}
```