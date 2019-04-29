---
title: Erro do compilador C3736
ms.date: 11/04/2016
f1_keywords:
- C3736
helpviewer_keywords:
- C3736
ms.assetid: 579b773c-41e7-40ea-8382-2e3ce2667f4c
ms.openlocfilehash: e31d68a13ebd9c5267fd285d43ebc66ae8b53182
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62328010"
---
# <a name="compiler-error-c3736"></a>Erro do compilador C3736

'event': deve ser um método ou, no caso de eventos gerenciados, opcionalmente, um membro de dados

Eventos COM e nativos devem ser métodos. Eventos do .NET também podem ser membros de dados.

O exemplo a seguir gera C3736:

```
// C3736.cpp
struct A {
   __event int e();
};

struct B {
   int f;   // C3736
   // The following line resolves the error.
   // int f();
   B(A* a) {
      __hook(&A::e, a, &B::f);
   }
};

int main() {
}
```