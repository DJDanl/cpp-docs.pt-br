---
title: Erro do compilador C3731
ms.date: 11/04/2016
f1_keywords:
- C3731
helpviewer_keywords:
- C3731
ms.assetid: 45f89fcd-464c-4bc8-8a42-edcb5416d26c
ms.openlocfilehash: 9acf80eec0d36db64fa070d691533e7085754ac0
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74752945"
---
# <a name="compiler-error-c3731"></a>Erro do compilador C3731

evento ' function1 ' e manipulador ' function2 ' incompatíveis; a origem do evento e o manipulador de eventos devem ser do mesmo tipo

A origem do evento e o receptor do evento devem ter o mesmo tipo (por exemplo `native` tipos vs. `com`). Para corrigir esse erro, faça com que os tipos da origem do evento e do manipulador de eventos correspondam.

O exemplo a seguir gera C3731:

```cpp
// C3731.cpp
// compile with: /clr
#using <mscorlib.dll>
[event_source(native)]
struct A {
   __event void MyEvent();
};

[event_receiver(managed)]
// try the following line instead
// [event_receiver(native)]
struct B {
   void func();
   B(A a) {
      __hook(&A::MyEvent, &a, &B::func);   // C3731
   }
};

int main() {
}
```
