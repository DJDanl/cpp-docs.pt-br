---
title: Erro do compilador C2698
ms.date: 11/04/2016
f1_keywords:
- C2698
helpviewer_keywords:
- C2698
ms.assetid: 3ebfe395-c20b-4c56-9980-ca9ed8653382
ms.openlocfilehash: f643b7d8c035b4d1d7d8806feb5b121cf76d7796
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50651900"
---
# <a name="compiler-error-c2698"></a>Erro do compilador C2698

a declaração de using para ' declaração 1' não pode coexistir com a declaração de using existente para ' declaração 2'

Uma vez que um [usando a declaração](../../cpp/using-declaration.md) para um membro de dados, uso de qualquer declaração no mesmo escopo que usa o mesmo nome não é permitida, pois apenas as funções podem ser sobrecarregadas.

O exemplo a seguir gera C2698:

```
// C2698.cpp
struct A {
   int x;
};

struct B {
   int x;
};

struct C : A, B {
   using A::x;
   using B::x;   // C2698
}
```