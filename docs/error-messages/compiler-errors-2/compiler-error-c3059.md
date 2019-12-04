---
title: Erro do compilador C3059
ms.date: 11/04/2016
f1_keywords:
- C3059
helpviewer_keywords:
- C3059
ms.assetid: 57220324-8286-4cab-a1ab-45385eb1eae0
ms.openlocfilehash: 897ed2beb7634cec787f0776616d9a60596a979f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756455"
---
# <a name="compiler-error-c3059"></a>Erro do compilador C3059

' var ': símbolo ' threadprivate ' não pode ser usado na cláusula ' Clause '

Um símbolo [threadprivate](../../parallel/openmp/reference/threadprivate.md) foi usado em uma cláusula.

O exemplo a seguir gera C3059:

```cpp
// C3059.cpp
// compile with: /openmp
#include "omp.h"
int x, y;
#pragma omp threadprivate(x, y)

int main() {
   #pragma omp parallel private(x, y)   // C3059
   {
      x = y;
   }
}
```

Resolução possível:

```cpp
// C3059b.cpp
// compile with: /openmp
#include "omp.h"
int x = 0, y = 0;

int main() {
   #pragma omp parallel firstprivate(y) private(x)
   {
      x = y;
   }
}
```
