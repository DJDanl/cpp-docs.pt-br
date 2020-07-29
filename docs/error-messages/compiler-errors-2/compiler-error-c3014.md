---
title: Erro do compilador C3014
ms.date: 11/04/2016
f1_keywords:
- C3014
helpviewer_keywords:
- C3014
ms.assetid: af1c5b0c-dbf9-4274-b06a-c6c2cdcf2a52
ms.openlocfilehash: e62b5028f13b6a3e35a1cf75f38935cae5a43f81
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232086"
---
# <a name="compiler-error-c3014"></a>Erro do compilador C3014

esperado um loop for após a diretiva de OpenMP ' diretivo '

É um erro para qualquer coisa que não seja um **`for`** loop para seguir imediatamente uma `#pragma omp for` diretiva.

O exemplo a seguir gera C3014:

```cpp
// C3014.cpp
// compile with: /openmp
int main()
{
   int i = 0;

   #pragma omp parallel
   {
      #pragma omp for
      for (i = 0; i < 10; ++i)   // OK
      {
      }
   }

   #pragma omp parallel for
   for (i = 0; i < 10; ++i)   // OK
   {
   }

   #pragma omp parallel
   {
      #pragma omp for
      {   // C3014
         for (i = 0; i < 10; ++i)
         {
         }
      }
   }

   #pragma omp parallel for
   {   // C3014
      for (i = 0; i < 10; ++i)
      {
      }
   }

   #pragma omp parallel
   {
      #pragma omp for
      i *= 2;   // C3014
      for (i = 0; i < 10; ++i)
      {
      }
   }

   #pragma omp parallel for
   i *= 2;   // C3014
   for (i = 0; i < 10; ++i)
   {
   }
}
```
