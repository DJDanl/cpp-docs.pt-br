---
title: Erro do compilador C3240
ms.date: 11/04/2016
f1_keywords:
- C3240
helpviewer_keywords:
- C3240
ms.assetid: 1a8dc213-b80c-47ae-ada0-e9554b635d1e
ms.openlocfilehash: a8334b4f95ccadcce73a79d787669cba9f911199
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62174159"
---
# <a name="compiler-error-c3240"></a>Erro do compilador C3240

'function': deve ser uma função de membro abstract não sobrecarregada de 'tipo'

Um tipo base continha uma função que foi definida. Função deve ser virtual.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3240.

```
// C3240.cpp
// compile with: /c
__interface I {
   void f();
};

struct A1 : I {
   void f() {}
};

struct A2 : I {
   void f() = 0;
};

template <class T>
struct A3 : T {
   void T::f() {}
};

template <class T>
struct A4 : T {
   void T::f() {}
};

A3<A1> x;   // C3240
A3<I> x2;
A4<A2> x3;
```