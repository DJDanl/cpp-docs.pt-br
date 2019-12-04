---
title: Erro do compilador C2247
ms.date: 11/04/2016
f1_keywords:
- C2247
helpviewer_keywords:
- C2247
ms.assetid: 72efa03e-615e-4ef9-aede-0a98654b20fd
ms.openlocfilehash: e82b406b20d77a824b62207b1766fec55ac65c5c
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758899"
---
# <a name="compiler-error-c2247"></a>Erro do compilador C2247

' identifier ' não acessível porque ' class ' usa ' especificador ' para herdar de ' class '

`identifier` é herdada de uma classe declarada com acesso privado ou protegido.

O exemplo a seguir gera C2247:

```cpp
// C2247.cpp
class A {
public:
   int i;
};
class B : private A {};    // B inherits a private A
class C : public B {} c;   // so even though C's B is public
int j = c.i;               // C2247, i not accessible
```

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: controle de acesso com membros protegidos. Um membro protegido (n) só pode ser acessado por meio de uma função membro de uma classe (B) que herda da classe (A) da qual ele (n) é um membro.

Para o código que é válido nas versões do Visual Studio .NET 2003 e do Visual Studio .NET do C++Visual, declare o membro como um amigo do tipo. A herança pública também pode ser usada.

```cpp
// C2247b.cpp
// compile with: /c
// C2247 expected
class A {
public:
   void f();
   int n;
};

class B: protected A {
   // Uncomment the following line to resolve.
   // friend void A::f();
};

void A::f() {
   B b;
   b.n;
}
```

O C2247 também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: as classes base privadas agora estão inacessíveis. Uma classe (A) que é uma classe base privada para um tipo (B) não deve ser acessível a um tipo (C) que usa B como uma classe base.

Para o código que é válido nas versões do Visual Studio .NET 2003 e do Visual Studio .NET do C++Visual, use o operador de escopo.

```cpp
// C2247c.cpp
// compile with: /c
struct A {};

struct B: private A {};

struct C : B {
   void f() {
      A *p1 = (A*) this;   // C2247
      // try the following line instead
      // ::A *p2 = (::A*) this;
   }
};
```
