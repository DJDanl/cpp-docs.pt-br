---
title: Erro do compilador C3020
ms.date: 11/04/2016
f1_keywords:
- C3020
helpviewer_keywords:
- C3020
ms.assetid: f625c7a3-afaa-4bd8-9c1b-51891b832f36
ms.openlocfilehash: 89b28ae396322859596b99ba56a28375e9c9d6d5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232021"
---
# <a name="compiler-error-c3020"></a>Erro do compilador C3020

' var ': a variável de índice do loop de OpenMP ' for ' não pode ser modificada no corpo do loop

Um loop de OpenMP **`for`** pode não modificar o índice (contador de loop) no corpo do **`for`** loop.

O exemplo a seguir gera C3020:

```cpp
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

Uma variável declarada com [lastprivate](../../parallel/openmp/reference/lastprivate.md) não pode ser usada como o índice dentro de um loop paralelizado.

O exemplo a seguir fornecerá C3020 para o segundo lastprivate porque esse lastprivate disparará uma gravação para idx_a dentro do loop for mais externo. O primeiro lastprivate não dá um erro porque o lastprivate dispara uma gravação para idx_a fora do loop for mais externo (tecnicamente, no final da última iteração). O exemplo a seguir gera C3020.

```cpp
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

```cpp
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
