---
title: Erro do compilador C3049
ms.date: 11/04/2016
f1_keywords:
- C3049
helpviewer_keywords:
- C3049
ms.assetid: 6ddf54f6-2c30-4d04-b637-98c6c922c533
ms.openlocfilehash: ca8481eb06a7ec679b27a446bf738f2ad018f79d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50526296"
---
# <a name="compiler-error-c3049"></a>Erro do compilador C3049

'arg': argumento inválido em cláusula 'default' de OpenMP

Um valor incorreto foi passado para um [padrão](../../parallel/openmp/reference/default-openmp.md) cláusula.

O exemplo a seguir gera C3049:

```
// C3049.cpp
// compile with: /openmp /c
int main() {
   int n1 = 1;

   #pragma omp parallel default(private)   // C3049
   // try the following line instead
   // #pragma omp parallel default(shared)
   {
      ++n1;
   }
}
```