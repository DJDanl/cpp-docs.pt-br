---
title: Erro do compilador C3046
ms.date: 11/04/2016
f1_keywords:
- C3046
helpviewer_keywords:
- C3046
ms.assetid: 2e53d835-faa1-4ec0-9807-41f3dc552635
ms.openlocfilehash: 56fffc0e9aab19f8ad8510ad886ec255a327249d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62404254"
---
# <a name="compiler-error-c3046"></a>Erro do compilador C3046

Faltando bloco estruturado em uma região de OpenMP '#pragma omp sections'

Um [seções](../../parallel/openmp/reference/sections-openmp.md) diretiva tem um bloco de código vazio.

O exemplo a seguir gera C3046:

```
// C3046.cpp
// compile with: /openmp /c
#include "omp.h"

int main() {
   int n2 = 2, n3 = 3;

   #pragma omp parallel
   {
      ++n2;

      #pragma omp sections
      {
/*
         ++n2;

         #pragma omp section
         {
            ++n3;
         }
*/
       }   // C3046 uncomment code to resolve this C3046
   }
}
```