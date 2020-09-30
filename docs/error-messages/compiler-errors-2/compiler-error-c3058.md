---
title: Erro do compilador C3058
ms.date: 11/04/2016
f1_keywords:
- C3058
helpviewer_keywords:
- C3058
ms.assetid: 669d08c8-0b58-4351-88aa-c6e6e1af481c
ms.openlocfilehash: 2c0615f78bf9068311ec691f70c4c1a60ef728b0
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91501476"
---
# <a name="compiler-error-c3058"></a>Erro do compilador C3058

' Symbol ': símbolo não declarado como ' threadprivate ' antes de ser usado na cláusula ' copyem '

Um símbolo deve primeiro ser declarado [threadprivate](../../parallel/openmp/reference/openmp-directives.md#threadprivate) antes que possa ser usado em uma cláusula de [cópia](../../parallel/openmp/reference/openmp-clauses.md#copyin) .

O exemplo a seguir gera C3058:

```cpp
// C3058.cpp
// compile with: /openmp
int x, y, z;
#pragma omp threadprivate(x, z)

void test() {
   #pragma omp parallel copyin(x, y)   // C3058
   {
   }
}
```

Resolução possível:

```cpp
// C3058b.cpp
// compile with: /openmp /LD
int x, y, z;
#pragma omp threadprivate(x, y)

void test() {
   #pragma omp parallel copyin(x, y)
   {
   }
}
```
