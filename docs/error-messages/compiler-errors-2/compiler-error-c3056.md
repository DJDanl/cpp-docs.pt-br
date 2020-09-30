---
title: Erro do compilador C3056
ms.date: 11/04/2016
f1_keywords:
- C3056
helpviewer_keywords:
- C3056
ms.assetid: 9500173d-870b-49b3-8e88-0ee93586d19a
ms.openlocfilehash: dd000e56d5fc24929e4d06e1bf0100ad9647610a
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91501591"
---
# <a name="compiler-error-c3056"></a>Erro do compilador C3056

' Symbol ': símbolo não está no mesmo escopo com a diretiva ' threadprivate '

Um símbolo usado em uma cláusula [threadprivate](../../parallel/openmp/reference/openmp-directives.md#threadprivate) deve estar no mesmo escopo que a `threadprivate` cláusula.

O exemplo a seguir gera C3056:

```cpp
// C3056.cpp
// compile with: /openmp
int x, y;
void test() {
   #pragma omp threadprivate(x, y)   // C3056
   #pragma omp parallel copyin(x, y)
   {
      x = y;
   }
}
```

Resolução possível:

```cpp
// C3056b.cpp
// compile with: /openmp /LD
int x, y;
#pragma omp threadprivate(x, y)
void test() {
   #pragma omp parallel copyin(x, y)
   {
      x = y;
   }
}
```
