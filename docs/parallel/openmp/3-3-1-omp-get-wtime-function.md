---
title: 3.3.1 função omp_get_wtime
ms.date: 11/04/2016
ms.assetid: 90188bd2-c53e-4398-8946-d3ecc92fa0f6
ms.openlocfilehash: 544a1bc9a613a2888cb7c5e68e54fdfae1b1c333
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50460561"
---
# <a name="331-ompgetwtime-function"></a>3.3.1 função omp_get_wtime

O `omp_get_wtime` função retorna um valor de ponto flutuante de precisão dupla igual para o tempo do relógio decorrido em segundos desde alguma "hora no passado".  O "tempo no passado" real é arbitrário, mas é garantido que ele não seja alterado durante a execução do programa aplicativo. O formato é o seguinte:

```
#include <omp.h>
double omp_get_wtime(void);
```

Espera-se que a função será usada para medir o tempo decorrido conforme mostrado no exemplo a seguir:

```
double start;
double end;
start = omp_get_wtime();
... work to be timed ...
end = omp_get_wtime();
printf_s("Work took %f sec. time.\n", end-start);
```

Os tempos retornados são "vezes por thread" por que é destinado a que eles não são necessários para ser consistente globalmente em todos os threads que estejam participando de um aplicativo.