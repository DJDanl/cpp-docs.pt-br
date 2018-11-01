---
title: Erro do compilador C3290
ms.date: 11/04/2016
f1_keywords:
- C3290
helpviewer_keywords:
- C3290
ms.assetid: 0baf684b-1143-4953-ac99-a2fa267d8017
ms.openlocfilehash: d82d3272563f7a5af5de399a2f7fff621500e612
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50490474"
---
# <a name="compiler-error-c3290"></a>Erro do compilador C3290

'type': uma propriedade trivial não pode ter o tipo de referência

Uma propriedade foi declarada incorretamente. Quando você declarar uma propriedade trivial, o compilador cria uma variável que atualizará a propriedade e não é possível ter uma referência de acompanhamento de variável em uma classe.

Ver [propriedade](../../windows/property-cpp-component-extensions.md) e [operador de referência de acompanhamento](../../windows/tracking-reference-operator-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3290.

```
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