---
title: 3.1.10 função omp_get_nested
ms.date: 11/04/2016
ms.assetid: 48736a25-5c6e-4e2d-aad0-421087663a3c
ms.openlocfilehash: a4db1e21f344f5cc58e2027b0816f9c8fb40b3bc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519898"
---
# <a name="3110-ompgetnested-function"></a>3.1.10 função omp_get_nested

O `omp_get_nested` função retorna um valor diferente de zero se o paralelismo aninhado estiver habilitado e 0 se ele estiver desabilitado. Para obter mais informações sobre o paralelismo aninhada, consulte a seção 3.1.9 na página de 40. O formato é o seguinte:

```
#include <omp.h>
int omp_get_nested(void);
```

Se uma implementação não implementar paralelismo aninhado, essa função sempre retorna 0.