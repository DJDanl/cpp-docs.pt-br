---
title: Erro do compilador C3379 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3379
dev_langs:
- C++
helpviewer_keywords:
- C3379
ms.assetid: a66c2c4e-091c-4426-9cde-7c4cfb2ffce1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f90a4ccc17e63c21d4b6fb26e607450849f27b48
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46109321"
---
# <a name="compiler-error-c3379"></a>Erro do compilador C3379

'class': uma classe aninhada não pode ter um especificador de acesso de assembly como parte de sua declaração

Quando aplicado a um tipo gerenciado, como a classe ou struct, o [pública](../../cpp/public-cpp.md) e [privada](../../cpp/private-cpp.md) palavras-chave que indicam se a classe será exposta por meio de metadados do assembly. `public` ou `private` não pode ser aplicado a uma classe aninhada, que herda o acesso de assembly da classe delimitadora.

Quando usado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md), o `ref` e `value` palavras-chave que indicam que uma classe é gerenciada (consulte [Classes e Structs](../../windows/classes-and-structs-cpp-component-extensions.md)).

O exemplo a seguir gera C3379:

```
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
