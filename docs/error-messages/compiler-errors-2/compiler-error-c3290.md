---
title: Erro do compilador C3290
ms.date: 11/04/2016
f1_keywords:
- C3290
helpviewer_keywords:
- C3290
ms.assetid: 0baf684b-1143-4953-ac99-a2fa267d8017
ms.openlocfilehash: f2a346354d8da7d78c5517b01b4438bfb8af50ad
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59776324"
---
# <a name="compiler-error-c3290"></a>Erro do compilador C3290

'type': uma propriedade trivial não pode ter o tipo de referência

Uma propriedade foi declarada incorretamente. Quando você declarar uma propriedade trivial, o compilador cria uma variável que atualizará a propriedade e não é possível ter uma referência de acompanhamento de variável em uma classe.

Ver [propriedade](../../extensions/property-cpp-component-extensions.md) e [operador de referência de acompanhamento](../../extensions/tracking-reference-operator-cpp-component-extensions.md) para obter mais informações.

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