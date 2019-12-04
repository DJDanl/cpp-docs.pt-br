---
title: Erro do compilador C3254
ms.date: 11/04/2016
f1_keywords:
- C3254
helpviewer_keywords:
- C3254
ms.assetid: 93427b10-fa72-4e43-80d1-1a6e122f9f40
ms.openlocfilehash: 6b9ff41fb4f45d9570869ca90e3c6091cc03a58a
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754245"
---
# <a name="compiler-error-c3254"></a>Erro do compilador C3254

"substituição explícita": classe contém substituição explícita "override" mas não deriva de uma interface que contém a declaração da função

Quando você [substitui explicitamente](../../cpp/explicit-overrides-cpp.md) um método, a classe que contém a substituição deve derivar, direta ou indiretamente, do tipo que contém a função que você está substituindo.

O exemplo a seguir gera C3254:

```cpp
// C3254.cpp
__interface I
{
   void f();
};

__interface I1 : I
{
};

struct A /* : I1 */
{
   void I1::f()
   {   // C3254, uncomment : I1 to resolve this C3254
   }
};

int main()
{
}
```
