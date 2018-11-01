---
title: 3.3.2 função omp_get_wtick
ms.date: 11/04/2016
ms.assetid: 1ad08500-bcb0-40d9-a81f-f131819006c9
ms.openlocfilehash: af1e5cf8ef40621342a5162f90cf8c883a59c6a2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50617952"
---
# <a name="332-ompgetwtick-function"></a>3.3.2 função omp_get_wtick

O `omp_get_wtick` função retorna um valor de ponto flutuante de precisão dupla igual ao número de segundos entre os tiques do relógio sucessivas. O formato é o seguinte:

```
#include <omp.h>
double omp_get_wtick(void);
```