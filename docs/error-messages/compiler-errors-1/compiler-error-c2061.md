---
title: Erro do compilador C2061
ms.date: 11/04/2016
f1_keywords:
- C2061
helpviewer_keywords:
- C2061
ms.assetid: b0e61c0c-a205-4820-b9aa-301d6c6fe6eb
ms.openlocfilehash: dc64852523b6b56bc506260576e3c79164628340
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74735925"
---
# <a name="compiler-error-c2061"></a>Erro do compilador C2061

erro de sintaxe: identificador ' identificador '

O compilador encontrou um identificador onde ele não era esperado. Verifique se `identifier` está declarado antes de usá-lo.

Um inicializador pode ser colocado entre parênteses. Para evitar esse problema, coloque o declarador entre parênteses ou torne-o um `typedef`.

Esse erro também pode ser causado quando o compilador detecta uma expressão como um argumento de modelo de classe; Use [TypeName](../../cpp/typename.md) para informar ao compilador que é um tipo.

O exemplo a seguir gera C2061:

```cpp
// C2061.cpp
// compile with: /c
template < A a >   // C2061
// try the following line instead
// template < typename b >
class c{};
```

C2061 pode ocorrer se você passar um nome de instância para [typeid](../../extensions/typeid-cpp-component-extensions.md):

```cpp
// C2061b.cpp
// compile with: /clr
ref struct G {
   int i;
};

int main() {
   G ^ pG = gcnew G;
   System::Type ^ pType = typeid<pG>;   // C2061
   System::Type ^ pType2 = typeid<G>;   // OK
}
```
