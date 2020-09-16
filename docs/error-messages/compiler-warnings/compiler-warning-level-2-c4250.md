---
title: Aviso do compilador (nível 2) C4250
ms.date: 11/04/2016
f1_keywords:
- C4250
helpviewer_keywords:
- C4250
ms.assetid: d47f7249-6b5a-414b-b2d4-56e5d246a782
ms.openlocfilehash: 10064784e1124ac365475f00b3577d22f5e7f3f1
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686516"
---
# <a name="compiler-warning-level-2-c4250"></a>Aviso do compilador (nível 2) C4250

' class1 ': herda ' class2:: member ' via predominância

Dois ou mais membros têm o mesmo nome. O no `class2` é herdado porque é uma classe base para as outras classes que continham esse membro.

Para suprimir C4250, use o pragma de [aviso](../../preprocessor/warning.md) .

Como uma classe base virtual é compartilhada entre várias classes derivadas, um nome em uma classe derivada domina um nome em uma classe base. Por exemplo, considerando a seguinte hierarquia de classe, há duas definições de Func herdadas dentro de Diamond: a instância vbc:: Func () por meio da classe fraca e a dominante:: Func () por meio da classe dominante. Uma chamada não qualificada de Func () por meio de um objeto de classe Diamond, sempre chama a instância dominable:: Func ().  Se a classe fraca fosse introduzir uma instância de Func (), nenhuma definição dominaria e a chamada seria sinalizada como ambígua.

## <a name="examples"></a>Exemplos

```cpp
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

O exemplo a seguir gera C4250.

```cpp
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

Este exemplo mostra uma situação mais complexa. O exemplo a seguir gera C4250.

```cpp
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
