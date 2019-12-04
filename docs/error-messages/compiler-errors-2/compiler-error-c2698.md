---
title: Erro do compilador C2698
ms.date: 11/04/2016
f1_keywords:
- C2698
helpviewer_keywords:
- C2698
ms.assetid: 3ebfe395-c20b-4c56-9980-ca9ed8653382
ms.openlocfilehash: 6129ff691f804b31fdb8cb487ac4609e4bca6ef2
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755181"
---
# <a name="compiler-error-c2698"></a>Erro do compilador C2698

a declaração using para ' Declaração 1 ' não pode coexistir com a declaração using existente para ' Declaração 2 '

Depois que você tiver uma [declaração using](../../cpp/using-declaration.md) para um membro de dados, qualquer declaração usando o mesmo escopo que usa o mesmo nome não será permitida, pois apenas as funções podem ser sobrecarregadas.

O exemplo a seguir gera C2698:

```cpp
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
