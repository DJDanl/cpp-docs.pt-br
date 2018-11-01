---
title: Compilador aviso (nível 4) C4487
ms.date: 11/04/2016
f1_keywords:
- C4487
helpviewer_keywords:
- C4487
ms.assetid: 796144cf-cd3c-4edc-b6a4-96192b7eb4f0
ms.openlocfilehash: 743069c0ed3103a2ed8d459def65083146b971e1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50496990"
---
# <a name="compiler-warning-level-4-c4487"></a>Compilador aviso (nível 4) C4487

'derived_class_function': corresponde ao método não virtual herdado 'base_class_function', mas não está explicitamente marcado como 'new'

Uma função em uma classe derivada tem a mesma assinatura como uma função de classe base não virtuais. C4487 lembra você de que a função de classe derivada substitui a função de classe base. Marcar explicitamente a função de classe derivada como `new` para resolver este aviso.

Para obter mais informações, consulte [novo (novo slot em vtable)](../../windows/new-new-slot-in-vtable-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4487.

```
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