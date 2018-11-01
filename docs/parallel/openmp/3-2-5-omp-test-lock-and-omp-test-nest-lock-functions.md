---
title: 3.2.5 funções omp_test_lock e omp_test_nest_lock
ms.date: 11/04/2016
ms.assetid: 36818945-c22c-4c24-b754-4e73eba6f3f8
ms.openlocfilehash: e8e03699f807f23f139075560592d8846467f2c5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50512743"
---
# <a name="325-omptestlock-and-omptestnestlock-functions"></a>3.2.5 funções omp_test_lock e omp_test_nest_lock

Essas funções tentam de definir um bloqueio, mas não bloquearão a execução do thread. O formato é o seguinte:

```
#include <omp.h>
int omp_test_lock(omp_lock_t *lock);
int omp_test_nest_lock(omp_nest_lock_t *lock);
```

O argumento deve apontar para uma variável inicializada de bloqueio. Essas funções tentam definir um bloqueio da mesma maneira como `omp_set_lock` e `omp_set_nest_lock`, exceto que eles não bloqueiam a execução do thread.

Para obter um bloqueio simple, o `omp_test_lock` função retorna um valor diferente de zero se o bloqueio é definido com êxito; caso contrário, retornará zero.

Para obter um bloqueio empilhável, o `omp_test_nest_lock` função retorna a nova contagem de aninhamento se o bloqueio é definido com êxito; caso contrário, retornará zero.