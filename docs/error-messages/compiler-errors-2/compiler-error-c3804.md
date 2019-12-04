---
title: Erro do compilador C3804
ms.date: 11/04/2016
f1_keywords:
- C3804
helpviewer_keywords:
- C3804
ms.assetid: 7c4cda28-ec96-4d04-937b-36dbd9944722
ms.openlocfilehash: 3bccfc723a9d62b794fa657e399bd94549448490
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755285"
---
# <a name="compiler-error-c3804"></a>Erro do compilador C3804

' property_accessor ': os métodos de acessador para uma propriedade devem ser todos estáticos ou todos não estáticos

Ao definir uma propriedade não trivial, as funções de acessador podem ser estáticas ou de instância, mas não ambas.

Consulte a [Propriedade](../../extensions/property-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3804.

```cpp
// C3804.cpp
// compile with: /c /clr
ref struct A {

   property int i {
      static int get() {}
      void set(int i) {}
   }   // C3804 error

   // OK
   property int j {
      int get() { return 0; }
      void set(int i) {}
   }

   property int k {
      static int get() { return 0; }
      static void set(int i) {}
   }
};
```
