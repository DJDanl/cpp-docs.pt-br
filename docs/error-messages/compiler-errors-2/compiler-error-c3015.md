---
title: Erro do compilador C3015
ms.date: 11/04/2016
f1_keywords:
- C3015
helpviewer_keywords:
- C3015
ms.assetid: d5e8e50b-7542-4b2d-8665-1b22072a5bc6
ms.openlocfilehash: 97ad6b51b9444e03f17511e26be75f5a783a5f07
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50464457"
---
# <a name="compiler-error-c3015"></a>Erro do compilador C3015

inicialização em OpenMP 'instrução for' possui forma inadequada

Um `for` loop em uma instrução de OpenMP deve ser totalmente e explicitamente especificado.

O exemplo a seguir gera C3015:

```
// C3015.cpp
// compile with: /openmp
int main()
{
   int i = 0, j = 10;

   #pragma omp parallel
   {
      #pragma omp for
      for (; i < 0; i += j)   // C3015
      // Try the following line instead:
      // for (i = 0; i < 0; i++)
         --j;
   }
}
```