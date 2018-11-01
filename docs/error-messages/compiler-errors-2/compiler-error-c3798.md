---
title: Erro do compilador C3798
ms.date: 11/04/2016
f1_keywords:
- C3798
helpviewer_keywords:
- C3798
ms.assetid: b2f8b1d8-8812-49b8-a346-28e48f02ba5c
ms.openlocfilehash: 52900a662211609e1e7adeb7cb493cf2d72ab846
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50548259"
---
# <a name="compiler-error-c3798"></a>Erro do compilador C3798

'especificador de ': declaração de propriedade não pode possuir especificador de substituição (deve ser colocado na propriedade métodos get/set em vez disso)

Uma propriedade foi declarada incorretamente. Para saber mais, veja

- [propriedade](../../windows/property-cpp-component-extensions.md)

- [abstract](../../windows/abstract-cpp-component-extensions.md)

- [sealed](../../windows/sealed-cpp-component-extensions.md)

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3798

```
// C3798.cpp
// compile with: /clr /c
ref struct A {
   property int Prop_1 abstract;   // C3798
   property int Prop_2 sealed;   // C3798

   // OK
   property int Prop_3 {
      virtual int get() abstract;
      virtual void set(int i) abstract;
   }

   property int Prop_4 {
      virtual int get() sealed;
      virtual void set(int i) sealed;
   }
};
```