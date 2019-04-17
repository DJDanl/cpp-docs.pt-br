---
title: Erro do compilador C2061
ms.date: 11/04/2016
f1_keywords:
- C2061
helpviewer_keywords:
- C2061
ms.assetid: b0e61c0c-a205-4820-b9aa-301d6c6fe6eb
ms.openlocfilehash: 85357d94c7bc2d709e852daa60caf269949ad1b8
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58771455"
---
# <a name="compiler-error-c2061"></a>Erro do compilador C2061

Erro de sintaxe: identificador 'identifier'

O compilador encontrar um identificador em que ele não era esperado. Certifique-se de que `identifier` é declarada antes de você usá-lo.

Um inicializador pode ser delimitado por parênteses. Para evitar esse problema, coloque o declarador entre parênteses ou torná-lo um `typedef`.

Esse erro também pode ser causado quando o compilador detecta uma expressão como um argumento de modelo de classe; Use [typename](../../cpp/typename.md) para dizer ao compilador é um tipo.

O exemplo a seguir gera C2061:

```
// C2061.cpp
// compile with: /c
template < A a >   // C2061
// try the following line instead
// template < typename b >
class c{};
```

C2061 pode ocorrer se você passar um nome de instância para [typeid](../../extensions/typeid-cpp-component-extensions.md):

```
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