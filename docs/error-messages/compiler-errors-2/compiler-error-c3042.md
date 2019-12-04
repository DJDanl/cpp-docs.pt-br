---
title: Erro do compilador C3042
ms.date: 11/04/2016
f1_keywords:
- C3042
helpviewer_keywords:
- C3042
ms.assetid: bf73f61e-5bd2-40a8-9b06-6244e6a15a41
ms.openlocfilehash: 4347e5ee0e61ada700082b4954b616ce894e57b9
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761384"
---
# <a name="compiler-error-c3042"></a>Erro do compilador C3042

as cláusulas ' copyprivate ' e ' nowait ' não podem aparecer juntas na diretiva de OpenMP ' diretivo '

As cláusulas [copyprivate](../../parallel/openmp/reference/copyprivate.md) e [nowait](../../parallel/openmp/reference/nowait.md) são mutuamente exclusivas na diretiva especificada. Para corrigir esse erro, remova uma ou ambas as cláusulas `copyprivate` ou `nowait`.

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
