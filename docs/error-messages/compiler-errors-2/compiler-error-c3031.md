---
title: Erro do compilador C3031
ms.date: 11/04/2016
f1_keywords:
- C3031
helpviewer_keywords:
- C3031
ms.assetid: 7e621e7e-eda7-45b5-8836-29599cd05255
ms.openlocfilehash: 848577239d24df3f6af38438fb42c372ef34b1ce
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62265848"
---
# <a name="compiler-error-c3031"></a>Erro do compilador C3031

'var': variável em cláusula 'reduction' deve ter tipo aritmético escalar

Uma variável do tipo incorreto foi passada para uma cláusula de redução.

O exemplo a seguir gera C3031:

```
// C3031.cpp
// compile with: /openmp /link vcomps.lib
#include <stdio.h>
#include "omp.h"

typedef struct {
   int n;
} Incomplete;

extern Incomplete inc;
int i = 9;

int main() {
   #pragma omp parallel reduction(+: inc)   // C3031
      ;

   #pragma omp parallel reduction(+: i)     // OK
      ;
}
```