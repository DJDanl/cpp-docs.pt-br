---
title: Erro do compilador C3042
ms.date: 11/04/2016
f1_keywords:
- C3042
helpviewer_keywords:
- C3042
ms.assetid: bf73f61e-5bd2-40a8-9b06-6244e6a15a41
ms.openlocfilehash: 8cd27f492a72277c383afa5ca335a073b1a0519c
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91506393"
---
# <a name="compiler-error-c3042"></a>Erro do compilador C3042

as cláusulas ' copyprivate ' e ' nowait ' não podem aparecer juntas na diretiva de OpenMP ' diretivo '

As cláusulas [copyprivate](../../parallel/openmp/reference/openmp-clauses.md#copyprivate) e [nowait](../../parallel/openmp/reference/openmp-clauses.md#nowait) são mutuamente exclusivas na diretiva especificada. Para corrigir esse erro, remova uma ou ambas as `copyprivate` `nowait` cláusulas ou.

O exemplo a seguir gera C3042:

```cpp
// C3042.cpp
// compile with: /openmp /c
#include <stdio.h>
#include "omp.h"

double d;

int main() {
    #pragma omp parallel private(d)
   {
      #pragma omp single copyprivate(d) nowait   // C3042
      {
      }
   }
}
```
