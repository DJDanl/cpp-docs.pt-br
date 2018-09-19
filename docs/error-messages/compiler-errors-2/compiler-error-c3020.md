---
title: Erro do compilador C3020 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3020
dev_langs:
- C++
helpviewer_keywords:
- C3020
ms.assetid: f625c7a3-afaa-4bd8-9c1b-51891b832f36
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c7f86d116c1a830db54490f3e5231d837d4246c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46060636"
---
# <a name="compiler-error-c3020"></a>Erro do compilador C3020

'var': variável de índice do OpenMP 'loop for' não pode ser modificado no corpo do loop

Um OpenMP `for` loop não pode modificar o índice (contador de loop) no corpo do `for` loop.

O exemplo a seguir gera C3020:

```
// C3020.cpp
// compile with: /openmp
int main() {
   int i = 0, n = 3;

   #pragma omp parallel
   {
      #pragma omp for
      for (i = 0; i < 10; i += n)
         i *= 2;   // C3020
         // try the following line instead
         // n++;
   }
}
```

Uma variável declarada com [lastprivate](../../parallel/openmp/reference/lastprivate.md) não pode ser usado como o índice dentro de um loop em paralelo.

O exemplo a seguir fornecerá C3020 para a segunda lastprivate porque esse lastprivate disparará uma gravação em idx_a mais externa dentro do loop for. A primeira lastprivate não dá a um erro porque esse lastprivate dispara uma gravação em idx_a mais externo fora do loop for (tecnicamente, no final da última iteração). O exemplo a seguir gera C3020.

```
// C3020b.cpp
// compile with: /openmp /c
float a[100][100];
int idx_a, idx_b;
void test(int first, int last)
{
   #pragma omp parallel for lastprivate(idx_a)
   for (idx_a = first; idx_a <= last; ++idx_a) {
      #pragma omp parallel for lastprivate(idx_a)   // C3020
      for (idx_b = first; idx_b <= last; ++idx_b) {
         a[idx_a][idx_b] += 1.0f;
      }
   }
}
```

O exemplo a seguir demonstra uma possível resolução:

```
// C3020c.cpp
// compile with: /openmp /c
float a[100][100];
int idx_a, idx_b;
void test(int first, int last)
{
   #pragma omp parallel for lastprivate(idx_a)
   for (idx_a = first; idx_a <= last; ++idx_a) {
      #pragma omp parallel for lastprivate(idx_b)
      for (idx_b = first; idx_b <= last; ++idx_b) {
         a[idx_a][idx_b] += 1.0f;
      }
   }
}
```