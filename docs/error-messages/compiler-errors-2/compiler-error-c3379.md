---
title: Erro do compilador C3379
ms.date: 11/04/2016
f1_keywords:
- C3379
helpviewer_keywords:
- C3379
ms.assetid: a66c2c4e-091c-4426-9cde-7c4cfb2ffce1
ms.openlocfilehash: 9d99214f3ad7e7db1edc215d94c98e9cf9ec4ca2
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74742893"
---
# <a name="compiler-error-c3379"></a>Erro do compilador C3379

' class ': uma classe aninhada não pode ter um especificador de acesso de assembly como parte de sua declaração

Quando aplicado a um tipo gerenciado, como Class ou struct, as palavras-chave [Public](../../cpp/public-cpp.md) e [Private](../../cpp/private-cpp.md) indicam se a classe será exposta por meio de metadados do assembly. `public` ou `private` não podem ser aplicadas a uma classe aninhada, que herdará o acesso ao assembly da classe de circunscrição.

Quando usado com [/CLR](../../build/reference/clr-common-language-runtime-compilation.md), as palavras-chave `ref` e `value` indicam que uma classe é gerenciada (consulte [classes e structs](../../extensions/classes-and-structs-cpp-component-extensions.md)).

O exemplo a seguir gera C3379:

```cpp
// C3379a.cpp
// compile with: /clr
using namespace System;

public ref class A {
public:
   static int i = 9;

   public ref class BA {   // C3379
   // try the following line instead
   // ref class BA {
   public:
      static int ii = 8;
   };
};

int main() {

   A^ myA = gcnew A;
   Console::WriteLine(myA->i);

   A::BA^ myBA = gcnew A::BA;
   Console::WriteLine(myBA->ii);
}
```
