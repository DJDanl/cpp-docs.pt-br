---
title: Erro do compilador C3020
ms.date: 11/04/2016
f1_keywords:
- C3020
helpviewer_keywords:
- C3020
ms.assetid: f625c7a3-afaa-4bd8-9c1b-51891b832f36
ms.openlocfilehash: 0e2d8e70dcc9b23c56a321487cd4b933a1086387
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386675"
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