---
title: Erro do compilador C3637
ms.date: 11/04/2016
f1_keywords:
- C3637
helpviewer_keywords:
- C3637
ms.assetid: 72391377-8519-43d9-870a-73a6423deb74
ms.openlocfilehash: c79a4113e20e3798877ccda8f1392b276dee19fa
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50574454"
---
# <a name="compiler-error-c3637"></a>Erro do compilador C3637

'function': uma definição de função friend não pode ser uma especialização de um tipo de função

Uma função friend estava definida incorretamente de um modelo ou genérico.

O exemplo a seguir gera C3637:

```
// C3637.cpp
template <class T>
void f();

struct S {
   friend void f<int>() {}   // C3637
};
```

Solução possível:

```
// C3637b.cpp
// compile with: /c
template <class T>
void f();

struct S {
   friend void f() {}
};
```

C3637 também podem ocorrer ao usar genéricos:

```
// C3637c.cpp
// compile with: /clr

generic <class T>
void gf();

struct S {
   friend void gf<int>() {}   // C3637
};
```

Solução possível:

```
// C3637d.cpp
// compile with: /clr /c
generic <class T>
void gf();

struct S {
   friend void gf() {}
};
```