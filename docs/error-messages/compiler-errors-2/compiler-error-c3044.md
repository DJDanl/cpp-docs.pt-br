---
title: Erro do compilador C3044
ms.date: 11/04/2016
f1_keywords:
- C3044
helpviewer_keywords:
- C3044
ms.assetid: 9f3e25b2-4676-49ab-97bf-6c88cd0fa377
ms.openlocfilehash: 74e931d8110c1104125b977e45ad0c6fd3ffd5f0
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761358"
---
# <a name="compiler-error-c3044"></a>Erro do compilador C3044

' section ': permitida apenas aninhada diretamente sob uma diretiva de OpenMP ' Sections '

O compilador encontrou uma diretiva de `section` foi usada incorretamente. Para obter mais informações, consulte [seções](../../parallel/openmp/reference/sections-openmp.md).

O exemplo a seguir gera C3044:

```cpp
// C3044.cpp
// compile with: /openmp /c
#include "omp.h"
int main() {
   int n2 = 2, n3 = 3;

   #pragma omp parallel
   {
      ++n2;

      #pragma omp sections
      {
         ++n2;
      }

      #pragma omp section   // C3044
      {
         ++n3;
      }
   }

   #pragma omp parallel
   {
      ++n2;

      #pragma omp sections
      {
         #pragma omp section   // OK
         {
            ++n3;
         }
      }
   }
}
```
