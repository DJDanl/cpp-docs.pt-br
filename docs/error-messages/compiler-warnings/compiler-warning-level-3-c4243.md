---
title: Aviso do compilador (nível 3) C4243
ms.date: 11/04/2016
f1_keywords:
- C4243
helpviewer_keywords:
- C4243
ms.assetid: ca72f9ad-ce0b-43a9-a68c-106e1f8b90ef
ms.openlocfilehash: 5900202a88eb7dc0575c5e97a58b20b0ef290a49
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80161549"
---
# <a name="compiler-warning-level-3-c4243"></a>Aviso do compilador (nível 3) C4243

a conversão de ' tipo de conversão ' existe de ' type1 ' para ' type2 ', mas está inacessível

Um ponteiro para uma classe derivada é convertido em um ponteiro para uma classe base, mas a classe derivada herda a classe base com acesso privado ou protegido.

O exemplo a seguir gera C4243:

```cpp
// C4243.cpp
// compile with: /W3
// C4243 expected
struct B {
   int f() {
      return 0;
   };
};

struct D : private B {};
struct E : public B {};

int main() {
   // Delete the following 2 lines to resolve.
   int (D::* d)() = (int(D::*)()) &B::f;
   d;

   int (E::* e)() = (int(E::*)()) &B::f; // OK
   e;
}
```
