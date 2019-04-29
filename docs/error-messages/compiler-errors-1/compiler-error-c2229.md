---
title: Erro do compilador C2229
ms.date: 11/04/2016
f1_keywords:
- C2229
helpviewer_keywords:
- C2229
ms.assetid: 933c7cf2-a463-4e74-b0b4-59dedad987fb
ms.openlocfilehash: 998067e9af178c1898c3443c4e84da965c22fa81
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62301728"
---
# <a name="compiler-error-c2229"></a>Erro do compilador C2229

o tipo 'identifier' tem uma matriz de tamanho zero ilegal

Um membro de um campo de bits ou de estrutura contém uma matriz de tamanho zero não é o último membro.

Como você pode ter uma matriz de tamanho zero como o último membro de struct, você deve especificar seu tamanho ao alocar o struct.

Se a matriz de tamanho zero não é o último membro de struct, o compilador não pode calcular o deslocamento para os campos restantes.

O exemplo a seguir gera C2229:

```
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