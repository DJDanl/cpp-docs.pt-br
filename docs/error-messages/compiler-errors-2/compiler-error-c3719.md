---
title: Erro do compilador C3719
ms.date: 11/04/2016
f1_keywords:
- C3719
helpviewer_keywords:
- C3719
ms.assetid: d0d59d4e-babb-4480-9ef7-70cf1a28165c
ms.openlocfilehash: 4fca5bfd944514bf2658a8af5cbbd58efe5b39fc
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74753179"
---
# <a name="compiler-error-c3719"></a>Erro do compilador C3719

' interface ': uma fonte de eventos baseada em interface só pode ser usada para eventos COM

Você declarou uma interface em um contexto não COM.

O exemplo a seguir gera C3719:

```cpp
// C3719a.cpp
#define _ATL_ATTRIBUTES 1
#include "atlbase.h"
#include "atlcom.h"

[module(name="MyLibrary", version="1.2", helpfile="MyHelpFile")];

[object]
__interface I {
   HRESULT func1();
};

[event_source(native), coclass]
struct A {
   __event __interface I;   // C3719

   // try the following line instead
   // __event func2();
};

int main() {
}
```

Para corrigir esse erro, aplique os atributos [Object](../../windows/object-cpp.md), [coclass](../../windows/coclass.md), [EVENT_SOURCE](../../windows/event-source.md)e [event_receiver](../../windows/event-receiver.md) adequadamente para tornar as classes nas quais você está usando as classes com de interface. Por exemplo:

```cpp
// C3719b.cpp
#define _ATL_ATTRIBUTES 1
#include <atlbase.h>
#include <atlcom.h>

[module(name="xx")];
[object, uuid("00000000-0000-0000-0000-000000000001")]
__interface I {
   HRESULT f();
};

[coclass, event_source(com) , uuid("00000000-0000-0000-0000-000000000002")]
struct MyStruct {
   __event __interface I;
};

[event_receiver(com)]
struct MyStruct2 {
   void f() {
   }
   MyStruct2(I* pB) {
      __hook(&I::f, pB, &MyStruct2::f);
   }
};

int main()
{
}
```
