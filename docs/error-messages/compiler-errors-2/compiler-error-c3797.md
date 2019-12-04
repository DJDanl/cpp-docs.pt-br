---
title: Erro do compilador C3797
ms.date: 11/04/2016
f1_keywords:
- C3797
helpviewer_keywords:
- C3797
ms.assetid: ab27ff34-8c1d-4297-b004-9e39bd3a4f25
ms.openlocfilehash: 7236cb75aef4250440a1e992415df07fb5b7da3f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757170"
---
# <a name="compiler-error-c3797"></a>Erro do compilador C3797

' override ': a declaração de evento não pode ter um especificador de substituição (deve ser colocado nos métodos Add/Remove/raise do evento)

Você não pode substituir um evento trivial (um evento sem métodos de acessador explicitamente definidos) com outro evento trivial. O evento de substituição deve definir seu comportamento com funções de acessador.

Para obter mais informações, consulte [evento](../../extensions/event-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3797.

```cpp
// C3797.cpp
// compile with: /clr /c
delegate void MyDel();

ref class Class1 {
public:
   virtual event MyDel ^ E;
};

ref class Class2 : public Class1 {
public:
   virtual event MyDel ^ E override;   // C3797
};

// OK
ref class Class3 : public Class1 {
public:
   virtual event MyDel ^ E {
      void add(MyDel ^ d) override {}
      void remove(MyDel ^ d) override {}
   }
};
```
