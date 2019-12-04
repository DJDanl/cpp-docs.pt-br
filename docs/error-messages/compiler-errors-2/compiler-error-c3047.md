---
title: Erro do compilador C3047
ms.date: 11/04/2016
f1_keywords:
- C3047
helpviewer_keywords:
- C3047
ms.assetid: 91c14566-5958-433d-8549-0e8bc3196f76
ms.openlocfilehash: c6b8530aa1a1d5b8a0bfa735a9cc759a698ae841
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761319"
---
# <a name="compiler-error-c3047"></a>Erro do compilador C3047

O bloco estruturado em uma região de ' seções ' de OpenMP deve ser precedido por ' #pragma seção OMP '

Qualquer código em um bloco de código introduzido por uma diretiva [Sections](../../parallel/openmp/reference/sections-openmp.md) deve estar em um bloco de código introduzido por uma diretiva `section`.

O exemplo a seguir gera C3047:

```cpp
// C3047.cpp
// compile with: /openmp /c
#include "omp.h"

int main() {
   int n2 = 2, n3 = 3;

   #pragma omp parallel
   {
      ++n2;

      #pragma omp sections
      {

         #pragma omp section
         {
            ++n3;
         }

         ++n2;   // C3047 not enclosed in #pragma omp section
      }
   }
}
```
