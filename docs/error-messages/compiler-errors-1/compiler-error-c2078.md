---
title: Erro do compilador C2078
ms.date: 11/04/2016
f1_keywords:
- C2078
helpviewer_keywords:
- C2078
ms.assetid: 9bead850-4123-46cf-a634-5c77ba974b2b
ms.openlocfilehash: 514776c0feb12c46dea56dd8e85043345754a229
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756442"
---
# <a name="compiler-error-c2078"></a>Erro do compilador C2078

muitos inicializadores

O número de inicializadores excede o número de objetos a serem inicializados.

O compilador pode deduzir a atribuição correta de inicializadores a objetos e objetos internos quando chaves internas são omitido da lista de inicializadores. O braçadeiras completo também elimina ambigüidade e resulta na atribuição correta. Braçadeiras parciais podem causar C2078 devido à ambiguidade na atribuição de inicializadores a objetos.

O exemplo a seguir gera C2078 e mostra como corrigi-lo:

```cpp
// C2078.cpp
// Compile by using: cl /c /W4 C2078.cpp
struct S {
   struct {
      int x, y;
   } z[2];
};

int main() {
   int d[2] = {1, 2, 3};   // C2078
   int e[2] = {1, 2};      // OK

   char a[] = {"a", "b"};  // C2078
   char *b[] = {"a", "b"}; // OK
   char c[] = {'a', 'b'};  // OK

   S s1{1, 2, 3, 4};       // OK
   S s2{{1, 2}, {3, 4}};   // C2078
   S s3{{1, 2, 3, 4}};     // OK
   S s4{{{1, 2}, {3, 4}}}; // OK
}
```
