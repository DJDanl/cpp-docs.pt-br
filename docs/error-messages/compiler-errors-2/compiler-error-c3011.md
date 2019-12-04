---
title: Erro do compilador C3011
ms.date: 11/04/2016
f1_keywords:
- C3011
helpviewer_keywords:
- C3011
ms.assetid: 24c3a917-ebff-4deb-9155-23adf6468531
ms.openlocfilehash: b5c9ffffaf934815912bcf103bbe75869f84ce1f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756169"
---
# <a name="compiler-error-c3011"></a>Erro do compilador C3011

assembly embutido não permitido diretamente em uma região paralela

Uma região paralela `omp` não pode conter instruções de assembly embutidas.

O exemplo a seguir gera C3011:

```cpp
// C3011.cpp
// compile with: /openmp
// processor: /x86
int main() {
   int   n = 0;

   #pragma omp parallel
   {
      _asm mov eax, n   // Delete this line to resolve this error.
   }   // C3011
}
```
