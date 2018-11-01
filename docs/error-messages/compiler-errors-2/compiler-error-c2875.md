---
title: Erro do compilador C2875
ms.date: 11/04/2016
f1_keywords:
- C2875
helpviewer_keywords:
- C2875
ms.assetid: d589fc0c-08b2-4a79-bc0e-dca5eb80bdd5
ms.openlocfilehash: 59df226e2740dbda3a67e0c3c49d688a3e564fee
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50622853"
---
# <a name="compiler-error-c2875"></a>Erro do compilador C2875

declaração de Using causa uma declaração múltipla de 'class::identifier'

A declaração faz com que o mesmo item seja definido duas vezes.

O exemplo a seguir gera C2875:

```
// C2875.cpp
struct A {
   void f(int*);
};

struct B {
   void f(double*);
};

struct AB : A, B {
   using A::f;
   using A::f;   // C2875
   using B::f;
};
```