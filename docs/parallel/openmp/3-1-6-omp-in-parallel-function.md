---
title: 3.1.6 função omp_in_parallel
ms.date: 11/04/2016
ms.assetid: db6e3a63-2a0a-4b8e-8cc6-c6b49edca5fb
ms.openlocfilehash: 2f251cb994771278c7f4e3f50f01e02126f6f88d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50482037"
---
# <a name="316-ompinparallel-function"></a>3.1.6 função omp_in_parallel

O **omp_in_parallel** função retorna um valor diferente de zero se ele é chamado dentro de extensão dinâmica de uma região paralela em execução em paralelo; caso contrário, retornará 0. O formato é o seguinte:

```
#include <omp.h>
int omp_in_parallel(void);
```

Essa função retorna um valor diferente de zero quando chamado de dentro de uma região de execução em paralelo, incluindo as regiões aninhadas que são serializadas.