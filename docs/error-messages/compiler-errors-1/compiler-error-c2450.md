---
title: Erro do compilador C2450
ms.date: 11/04/2016
f1_keywords:
- C2450
helpviewer_keywords:
- C2450
ms.assetid: 929f1c06-8774-468b-be2a-f428757875a2
ms.openlocfilehash: 55c7f7ba8708e1475404a474f85df7dbe37fcec0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220347"
---
# <a name="compiler-error-c2450"></a>Erro do compilador C2450

expressão switch do tipo ' type ' é inválida

A **`switch`** expressão é avaliada como um tipo inválido. Ele deve ser avaliado como um tipo inteiro ou um tipo de classe com conversão não ambígua para um tipo inteiro. Se ele for avaliado como um tipo definido pelo usuário, você deverá fornecer um operador de conversão.

O exemplo a seguir gera C2450:

```cpp
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
