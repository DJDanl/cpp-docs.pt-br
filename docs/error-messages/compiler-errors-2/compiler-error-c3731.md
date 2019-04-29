---
title: Erro do compilador C3731
ms.date: 11/04/2016
f1_keywords:
- C3731
helpviewer_keywords:
- C3731
ms.assetid: 45f89fcd-464c-4bc8-8a42-edcb5416d26c
ms.openlocfilehash: 5acc33869648f83cd44bc557128c685f521ddf88
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62328062"
---
# <a name="compiler-error-c3731"></a>Erro do compilador C3731

evento incompatível 'function1' e o manipulador 'function2'; origem do evento e o manipulador de eventos devem ser do mesmo tipo

A origem do evento e o receptor de evento devem ter o mesmo tipo (por exemplo `native` versus `com` tipos). Para corrigir esse erro, verifique os tipos de origem do evento e a correspondência de manipulador de eventos.

O exemplo a seguir gera C3731:

```
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