---
title: Erro do compilador C3290
ms.date: 11/04/2016
f1_keywords:
- C3290
helpviewer_keywords:
- C3290
ms.assetid: 0baf684b-1143-4953-ac99-a2fa267d8017
ms.openlocfilehash: a7a73c13c28923761674294d8d6e601b95ffad96
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760147"
---
# <a name="compiler-error-c3290"></a>Erro do compilador C3290

' type ': uma propriedade trivial não pode possuir tipo de referência

Uma propriedade foi declarada incorretamente. Quando você declara uma propriedade trivial, o compilador cria uma variável que a propriedade atualizará e não é possível ter uma variável de referência de rastreamento em uma classe.

Consulte operador de [referência](../../extensions/tracking-reference-operator-cpp-component-extensions.md) de [Propriedade](../../extensions/property-cpp-component-extensions.md) e acompanhamento para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3290.

```cpp
// C3290.cpp
// compile with: /clr /c
ref struct R {};

ref struct X {
   R^ mr;

   property R % y;   // C3290
   property R ^ x;   // OK

   // OK
   property R% prop {
      R% get() {
         return *mr;
      }

      void set(R%) {}
   }
};

int main() {
   X x;
   R% xp = x.prop;
}
```
