---
title: Erro do compilador C2229
ms.date: 11/04/2016
f1_keywords:
- C2229
helpviewer_keywords:
- C2229
ms.assetid: 933c7cf2-a463-4e74-b0b4-59dedad987fb
ms.openlocfilehash: 2d974c4f0630a592daad956448bf21cea21efb7c
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759263"
---
# <a name="compiler-error-c2229"></a>Erro do compilador C2229

o tipo ' identifier ' tem uma matriz de tamanho zero inválida

Um membro de um campo de estrutura ou de bits contém uma matriz de tamanho zero que não é o último membro.

Como você pode ter uma matriz de tamanho zero como o último membro da estrutura, você deve especificar seu tamanho ao alocar a estrutura.

Se a matriz de tamanho zero não for o último membro da estrutura, o compilador não poderá calcular o deslocamento dos campos restantes.

O exemplo a seguir gera C2229:

```cpp
// C2229.cpp
struct S {
   int a[0];  // C2229  zero-sized array
   int b[1];
};

struct S2 {
   int a;
   int b[0];
};

int main() {
   // allocate 7 elements for b field
   S2* s2 = (S2*)new int[sizeof(S2) + 7*sizeof(int)];
   s2->b[6] = 100;
}
```
