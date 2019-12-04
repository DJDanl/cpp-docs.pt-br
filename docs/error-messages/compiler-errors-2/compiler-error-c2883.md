---
title: Erro do compilador C2883
ms.date: 11/04/2016
f1_keywords:
- C2883
helpviewer_keywords:
- C2883
ms.assetid: 5c6d689d-ed42-41ad-b5c0-e9c2e0b8c356
ms.openlocfilehash: cb6b1043d976cfeb8cb92c8780c5b84ea9700b8b
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760948"
---
# <a name="compiler-error-c2883"></a>Erro do compilador C2883

' name ': a declaração da função está em conflito com ' identifier ' introduzido pela declaração using

Você tentou definir uma função mais de uma vez. A primeira definição foi feita de um namespace com uma declaração de `using`. A segunda era uma definição local.

O exemplo a seguir gera C2883:

```cpp
// C2883.cpp
namespace A {
   void z(int);
}

int main() {
   using A::z;
   void z(int);   // C2883  z is already defined
}
```
