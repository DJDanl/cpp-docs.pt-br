---
title: 3.2.2 funções omp_destroy_lock e omp_destroy_nest_lock
ms.date: 11/04/2016
ms.assetid: d334907d-94f7-4bbf-b20e-41d53484cbff
ms.openlocfilehash: 02f739ab2834db7eca9b051e6659644c39b51e84
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50666173"
---
# <a name="322-ompdestroylock-and-ompdestroynestlock-functions"></a>3.2.2 funções omp_destroy_lock e omp_destroy_nest_lock

Essas funções Certifique-se de que o indicado a variável de bloqueio *bloqueio* não foi inicializada. O formato é o seguinte:

```
#include <omp.h>
void omp_destroy_lock(omp_lock_t *lock);
void omp_destroy_nest_lock(omp_nest_lock_t *lock);
```

Ele está em conformidade para chamar qualquer uma dessas rotinas com uma variável de bloqueio que é não inicializado ou desbloqueada.