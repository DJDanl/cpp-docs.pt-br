---
title: 3.1.8 função omp_get_dynamic
ms.date: 11/04/2016
ms.assetid: c03e2daf-29c9-49e3-9b67-b980ad1ab195
ms.openlocfilehash: d9476894e5aff4cc7bb9c67fbbeb14d185b65f5e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50566420"
---
# <a name="318-ompgetdynamic-function"></a>3.1.8 função omp_get_dynamic

O **omp_get_dynamic** função retorna um valor diferente de zero se o ajuste dinâmico de threads está habilitado e, caso contrário, retornará 0. O formato é o seguinte:

```
#include <omp.h>
int omp_get_dynamic(void);
```

Se a implementação não implementar ajuste dinâmico do número de threads, essa função sempre retorna 0.

## <a name="cross-references"></a>Entre as referências:

- Para obter uma descrição de ajuste dinâmico de thread, consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.