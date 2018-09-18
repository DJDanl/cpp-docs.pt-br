---
title: Compilador aviso (nível 2) C4250 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4250
dev_langs:
- C++
helpviewer_keywords:
- C4250
ms.assetid: d47f7249-6b5a-414b-b2d4-56e5d246a782
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f5797782691385111f0be22854643315f4e596fb
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46031425"
---
# <a name="compiler-warning-level-2-c4250"></a>Compilador aviso (nível 2) C4250

'class1': herda 'class2::member' via domínio

Dois ou mais membros têm o mesmo nome. No `class2` é herdada porque é uma classe base para as outras classes que contidos neste membro.

Para suprimir C4250, use o [aviso](../../preprocessor/warning.md) pragma.

Como uma classe base virtual é compartilhada entre várias classes derivadas, um nome em uma classe derivada domina um nome em uma classe base. Por exemplo, dada a hierarquia de classe a seguir, há duas definições de fun herdada no losango: a instância de vbc::func() por meio da classe fraca e o dominante:: func() por meio da classe dominante. Uma chamada não-qualificada de func() por meio de um objeto de classe de losango, sempre chama a instância de dominate:: func().  Se a classe fraca introduzir uma instância de func(), nem seria dominam a definição e a chamada será sinalizada como ambígua.

```
// C4250.cpp
// compile with: /c /W2
#include <stdio.h>
struct vbc {
   virtual void func() { printf("vbc::func\n"); }
};

struct weak : public virtual vbc {};

struct dominant : public virtual vbc {
   void func() { printf("dominant::func\n"); }
};

struct diamond : public weak, public dominant {};

int main() {
   diamond d;
   d.func();   // C4250
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4250.

```
// C4250_b.cpp
// compile with: /W2 /EHsc
#include <iostream>
using namespace std;
class A {
public:
   virtual operator int () {
      return 2;
   }
};

class B : virtual public A {
public:
   virtual operator int () {
      return 3;
   }
};

class C : virtual public A {};

class E : public B, public C {};   // C4250

int main() {
   E eObject;
   cout << eObject.operator int() << endl;
}
```

## <a name="example"></a>Exemplo

Este exemplo mostra uma situação mais complexa. O exemplo a seguir gera C4250.

```
// C4250_c.cpp
// compile with: /W2 /EHsc
#include <iostream>
using namespace std;

class V {
public:
   virtual int f() {
      return 1024;
   }
};

class B : virtual public V {
public:
   int b() {
      return f(); // B::b() calls V::f()
   }
};

class M : virtual public V {
public:
   int f() {
      return 7;
   }
};

// because of dominance, f() is M::f() inside D,
// changing the meaning of B::b's f() call inside a D
class D : public B, public M {};   // C4250

int main() {
   D d;
   cout << "value is: " << d.b();   // invokes M::f()
}
```