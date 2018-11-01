---
title: Erro do compilador C2078
ms.date: 11/04/2016
f1_keywords:
- C2078
helpviewer_keywords:
- C2078
ms.assetid: 9bead850-4123-46cf-a634-5c77ba974b2b
ms.openlocfilehash: 413d1215b7d69af738b5b4ad99206e4d6135980e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50569761"
---
# <a name="compiler-error-c2078"></a>Erro do compilador C2078

Muitos inicializadores

O número de inicializadores excede o número de objetos sejam inicializados.

O compilador pode deduzir a atribuição correta de inicializadores de objetos e objetos internos quando chaves internas estiverem omitidas da lista de inicializadores. Braçadeiras completa também elimina a ambiguidade e resulta na atribuição correta. Braçadeiras parcial podem causar C2078 devido à ambiguidade na atribuição de inicializadores de objetos.

O exemplo a seguir gera C2078 e mostra como corrigi-lo:

```
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