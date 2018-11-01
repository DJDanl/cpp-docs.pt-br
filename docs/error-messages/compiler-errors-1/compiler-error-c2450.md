---
title: Erro do compilador C2450
ms.date: 11/04/2016
f1_keywords:
- C2450
helpviewer_keywords:
- C2450
ms.assetid: 929f1c06-8774-468b-be2a-f428757875a2
ms.openlocfilehash: 3cbab274f8f7cd04d5fb86db69572e0b7fc1c04e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50621793"
---
# <a name="compiler-error-c2450"></a>Erro do compilador C2450

expressão de switch de tipo 'type' é inválida

O `switch` expressão é avaliada como um tipo inválido. Ele deve ser avaliada como um tipo de inteiro ou um tipo de classe com conversão inequívoca para um tipo inteiro. Se for avaliada como um tipo definido pelo usuário, você deve fornecer um operador de conversão.

O exemplo a seguir gera C2450:

```
// C2450.cpp
class X {
public:
   int i;
} x;

class Y {
public:
   int i;
   operator int() { return i; }   // conversion operator
} y;

int main() {
   int j = 1;
   switch ( x ) {   // C2450, x is not type int
   // try the following line instead
   // switch ( y ) {
      default:  ;
   }
}
```