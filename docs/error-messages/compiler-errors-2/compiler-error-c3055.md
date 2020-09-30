---
title: Erro do compilador C3055
ms.date: 11/04/2016
f1_keywords:
- C3055
helpviewer_keywords:
- C3055
ms.assetid: 60446ee0-18dd-48fc-9059-f0a14229dce8
ms.openlocfilehash: ed0f031fcd0ff0c621556bf73572d720fc2c1352
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91501623"
---
# <a name="compiler-error-c3055"></a>Erro do compilador C3055

' Symbol ': símbolo não pode ser referenciado antes de ser usado na diretiva ' threadprivate '

Um símbolo foi referenciado e, em seguida, usado em uma cláusula [threadprivate](../../parallel/openmp/reference/openmp-directives.md#threadprivate) , que não é permitida.

O exemplo a seguir gera C3055:

```cpp
// C3055.cpp
// compile with: /openmp
int x, y;
int z = x;
#pragma omp threadprivate(x, y)   // C3055

void test() {
   #pragma omp parallel copyin(x, y)
   {
      x = y;
   }
}
```

Resolução possível:

```cpp
// C3055b.cpp
// compile with: /openmp /LD
int x, y, z;
#pragma omp threadprivate(x, y)

void test() {
   #pragma omp parallel copyin(x, y)
   {
      x = y;
   }
}
```
