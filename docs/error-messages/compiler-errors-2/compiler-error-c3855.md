---
title: Erro do compilador C3855
ms.date: 11/04/2016
f1_keywords:
- C3855
helpviewer_keywords:
- C3855
ms.assetid: ed90f8c0-4154-4243-b066-493913df5727
ms.openlocfilehash: 12ee1c6aa5f414a9cf3084831c956514593102c4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50478124"
---
# <a name="compiler-error-c3855"></a>Erro do compilador C3855

'class': parâmetro de tipo 'param' é incompatível com a declaração

O compilador encontrar o modelo sem tipo ou parâmetros genéricos com nomes diferentes. Isso pode ocorrer quando um parâmetro de modelo especificado na definição de uma especialização de modelo é incompatível com sua declaração.

O exemplo a seguir gera C3855:

```
// C3855.cpp
template <int N>
struct C {
   void f();
};

template <char N>
void C<N>::f() {}   // C3855
```

Solução possível:

```
// C3855b.cpp
// compile with: /c
template <int N>
struct C {
   void f();
};

template <int N>
void C<N>::f() {}
```

C3855 também podem ocorrer ao usar genéricos:

```
// C3855c.cpp
// compile with: /clr
generic <class T>
ref struct GC1 {
   generic <class U>
   ref struct GC2;
};

generic <class T>
generic <class U>
generic <class V>
ref struct GC1<T>::GC2 { };   // C3855
```

Solução possível:

```
// C3855d.cpp
// compile with: /clr /c
generic <class T>
ref struct GC1 {
   generic <class U>
   ref struct GC2;
};

generic <class T>
generic <class U>
ref struct GC1<T>::GC2 { };
```