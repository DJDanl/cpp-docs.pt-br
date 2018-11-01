---
title: A.1   Executando um loop simples em paralelo
ms.date: 11/04/2016
ms.assetid: b8aaacae-b20d-4b16-a540-54ccbf09582b
ms.openlocfilehash: 5bd9a9c8b1d226c67f7e9031a547e551fae3407b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50558928"
---
# <a name="a1---executing-a-simple-loop-in-parallel"></a>A.1   Executando um loop simples em paralelo

O exemplo a seguir demonstra como paralelizar um loop simples usando o `parallel for` diretiva ([seção 2.5.1](../../parallel/openmp/2-5-1-parallel-for-construct.md) na página 16). A variável de iteração do loop é privada por padrão, portanto, não é necessário especificá-lo explicitamente em uma cláusula privada.

```
#pragma omp parallel for
    for (i=1; i<n; i++)
        b[i] = (a[i] + a[i-1]) / 2.0;
```