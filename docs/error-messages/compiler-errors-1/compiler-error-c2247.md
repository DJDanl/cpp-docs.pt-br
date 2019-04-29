---
title: Erro do compilador C2247
ms.date: 11/04/2016
f1_keywords:
- C2247
helpviewer_keywords:
- C2247
ms.assetid: 72efa03e-615e-4ef9-aede-0a98654b20fd
ms.openlocfilehash: ab1f83e2075128441cbffd2d939e3b99b45be4c3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62301364"
---
# <a name="compiler-error-c2247"></a>Erro do compilador C2247

'identifier' não está acessível porque 'class' usa 'especificador' para herdar de 'class'

`identifier` é herdado de uma classe declarada com acesso particular ou protegido.

O exemplo a seguir gera C2247:

```
// C2247.cpp
class A {
public:
   int i;
};
class B : private A {};    // B inherits a private A
class C : public B {} c;   // so even though C's B is public
int j = c.i;               // C2247, i not accessible
```

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: controle com membros protegidos de acesso. Um membro protegido (n) só pode ser acessado por meio de uma função de membro de uma classe (B) que herda da classe (A) do qual ele (n) é um membro.

Para o código que é válido no Visual Studio .NET 2003 e versões do Visual Studio .NET do Visual C++, declare o membro seja um amigo do tipo. Herança pública também pode ser usada.

```
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

C2247 também podem ser gerados como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: privada as classes base agora inacessível. Uma classe (A) que é uma classe base particular em um tipo não (B) deve estar acessível para um tipo (C) que usa B como uma classe base.

Para o código que é válido no Visual Studio .NET 2003 e versões do Visual Studio .NET do Visual C++, use o operador de escopo.

```
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