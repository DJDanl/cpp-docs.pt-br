---
title: Erro do compilador C3723
ms.date: 11/04/2016
f1_keywords:
- C3723
helpviewer_keywords:
- C3723
ms.assetid: ef0fb1ff-3f9a-4093-a6b6-894d1ab0c4b9
ms.openlocfilehash: 2948b9af50179082e61a222484053bcf3858f454
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220165"
---
# <a name="compiler-error-c3723"></a>Erro do compilador C3723

> ' function ': não foi possível resolver o evento

`function`Não foi possível resolver o evento a ser chamado.

O exemplo a seguir gera C3723:

```cpp
// C3723.cpp
struct A {
   // To resolve, comment void f(int); and uncomment the __event function
   void f(int);
   // __event void f(int);
   void f(float);

};

struct B {
   void g(int);
   B(A* a) {
   __hook(&A::f, a, &B::g);   // C3723
   }
};

int main() {
}
```

**`__hook`** e **`__unhook`** não são compatíveis com **`/clr`** programação.  Em vez disso, use os operadores + = e-=.

O exemplo a seguir gera C3723:

```cpp
// C3723b.cpp
// compile with: /clr
using namespace System;

public delegate void delegate1();

public ref class CPSource {
public:
   event delegate1^ event1;
};

public ref class CReceiver {
public:
   void Handler1() {
   }

   void UnhookAll(CPSource^ pSrc) {
      __unhook(&CPSource::event1, pSrc, &CReceiver::Handler1); // C3723
      // Try the following line instead.
      // pSrc->event1 -= gcnew delegate1(this, &CReceiver::Handler1);
   }
};

int main() {
}
```
