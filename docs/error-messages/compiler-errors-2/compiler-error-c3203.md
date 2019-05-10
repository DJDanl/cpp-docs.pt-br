---
title: Erro do compilador C3203
ms.date: 11/04/2016
f1_keywords:
- C3203
helpviewer_keywords:
- C3203
ms.assetid: 6356770e-22c1-434c-91fe-f60b0aa23b91
ms.openlocfilehash: c55160c855a6188a616f957acee43e409b751b62
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65447802"
---
# <a name="compiler-error-c3203"></a>Erro do compilador C3203

'type': modelo de classe não especializada ou genérico não pode ser usado como um modelo ou um argumento genérico para o modelo ou parâmetro genérico 'param', esperado um tipo real

Você passou um argumento inválido para um modelo de classe ou genérico. O modelo de classe ou genérico espera um tipo como um parâmetro.

Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: um modelo de classe não especializada não pode ser usado como um argumento de modelo em uma lista de classes base. Para resolver C3203, adicione explicitamente os parâmetros de tipo de modelo para o nome de classe de modelo quando usá-lo como um parâmetro de modelo em uma lista de classes base.

```
// C3203.cpp
template< typename T >
struct X {
   void f(X) {}
};

template< typename T >
struct Y : public X<Y> {   // C3203
// try the following line instead
// struct Y : public X<Y<T> > {
   void f(Y) {}
};

int main() {
   Y<int> y;
}
```

O exemplo a seguir gera C3203 e mostra como corrigi-lo:

```
// C3203_b.cpp
// compile with: /c
template <class T>
struct S1 {};

template <class T>
class C1 {};

typedef C1<S1> MyC1;   // C3203

// OK
template <template <class> class T>
class C2 {};

typedef C2<S1> MyC1;

template <class T>
class C3 {};

typedef C3<S1<int> > MyC12;
```

C3203 também podem ocorrer ao usar genéricos:

```
// C3203_c.cpp
// compile with: /clr /c
generic <class T>
value struct GS1 {};

generic <class T>
value struct GC1 {};

typedef GC1<GS1> MyGC1;   // C3203
typedef GC1<GS1<int> > MyGC2;   // OK
```