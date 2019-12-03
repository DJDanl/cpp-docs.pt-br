---
title: Aviso do compilador (nível 4) C4487
ms.date: 11/04/2016
f1_keywords:
- C4487
helpviewer_keywords:
- C4487
ms.assetid: 796144cf-cd3c-4edc-b6a4-96192b7eb4f0
ms.openlocfilehash: 1583da44368225eabd8181be970f69f6582111e1
ms.sourcegitcommit: d0504e2337bb671e78ec6dd1c7b05d89e7adf6a7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/02/2019
ms.locfileid: "74682975"
---
# <a name="compiler-warning-level-4-c4487"></a>Aviso do compilador (nível 4) C4487

' derived_class_function ': corresponde ao método não virtual herdado ' base_class_function ', mas não está marcado explicitamente como ' New '

Uma função em uma classe derivada tem a mesma assinatura que uma função de classe base não virtual. C4487 lembra que a função de classe derivada não substitui a função de classe base. Marque explicitamente a função derivada da classe como `new` para resolver esse aviso.

Para obter mais informações, consulte [novo (novo slot em vtable)](../../extensions/new-new-slot-in-vtable-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4487.

```cpp
// C4487.cpp
// compile with: /W4 /clr
using namespace System;
public ref struct B {
   void f() { Console::WriteLine("in B::f"); }
   void g() { Console::WriteLine("in B::g"); }
};

public ref struct D : B {
   void f() { Console::WriteLine("in D::f"); }   // C4487
   void g() new { Console::WriteLine("in D::g"); }   // OK
};

int main() {
   B ^ a = gcnew D;
   // will call base class functions
   a->f();
   a->g();
}
```