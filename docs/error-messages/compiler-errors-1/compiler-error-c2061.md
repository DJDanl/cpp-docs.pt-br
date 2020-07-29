---
title: Erro do compilador C2061
ms.date: 11/04/2016
f1_keywords:
- C2061
helpviewer_keywords:
- C2061
ms.assetid: b0e61c0c-a205-4820-b9aa-301d6c6fe6eb
ms.openlocfilehash: 1e1b13960c84d4e03c6316c451c690f8b5a6236e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212859"
---
# <a name="compiler-error-c2061"></a>Erro do compilador C2061

erro de sintaxe: identificador ' identificador '

O compilador encontrou um identificador onde ele não era esperado. Certifique-se de que `identifier` é declarado antes de usá-lo.

Um inicializador pode ser colocado entre parênteses. Para evitar esse problema, coloque o declarador entre parênteses ou transforme-o **`typedef`** .

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
