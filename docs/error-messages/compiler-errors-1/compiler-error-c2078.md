---
title: Erro do compilador C2078 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2078
dev_langs:
- C++
helpviewer_keywords:
- C2078
ms.assetid: 9bead850-4123-46cf-a634-5c77ba974b2b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8de17341bfb1ad5031be04e977ab68ae4ed1bcb5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46111505"
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