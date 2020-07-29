---
title: Erro do compilador C2883
ms.date: 11/04/2016
f1_keywords:
- C2883
helpviewer_keywords:
- C2883
ms.assetid: 5c6d689d-ed42-41ad-b5c0-e9c2e0b8c356
ms.openlocfilehash: fcd97a2f362e50ec856e53da2603c29e07595670
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233464"
---
# <a name="compiler-error-c2883"></a>Erro do compilador C2883

' name ': a declaração da função está em conflito com ' identifier ' introduzido pela declaração using

Você tentou definir uma função mais de uma vez. A primeira definição foi feita de um namespace com uma **`using`** declaração. A segunda era uma definição local.

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
