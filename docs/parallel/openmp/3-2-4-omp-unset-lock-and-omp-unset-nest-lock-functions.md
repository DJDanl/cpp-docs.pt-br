---
title: 3.2.4 funções omp_unset_lock e omp_unset_nest_lock
ms.date: 11/04/2016
ms.assetid: 5357e43e-a7c0-41d7-b529-3f7d15da8b11
ms.openlocfilehash: b0764e3590f8edb3a3e783d9b5493a64be154401
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50607853"
---
# <a name="324-ompunsetlock-and-ompunsetnestlock-functions"></a>3.2.4 funções omp_unset_lock e omp_unset_nest_lock

Essas funções fornecem os meios de propriedade de um bloqueio de liberação. O formato é o seguinte:

```
#include <omp.h>
void omp_unset_lock(omp_lock_t *lock);
void omp_unset_nest_lock(omp_nest_lock_t *lock);
```

O argumento para cada uma dessas funções deve apontar para uma variável de bloqueio inicializado pelo thread de execução da função de propriedade. O comportamento será indefinido se o thread possui o bloqueio.

Para obter um bloqueio simple, o `omp_unset_lock` função libera o thread de execução da função de propriedade do bloqueio.

Para obter um bloqueio empilhável, o `omp_unset_nest_lock` função diminui a contagem de aninhamento e versões, o thread de execução da função de propriedade do bloqueio, se a contagem resultante é zero.