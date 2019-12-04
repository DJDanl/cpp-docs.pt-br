---
title: Erro do compilador C3860
ms.date: 11/04/2016
f1_keywords:
- C3860
helpviewer_keywords:
- C3860
ms.assetid: 1fb5110d-594e-4f1c-8773-888233af1313
ms.openlocfilehash: 38113ba9c75ab3e3e9b0ea058cb96e733a484f13
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757781"
---
# <a name="compiler-error-c3860"></a>Erro do compilador C3860

lista de argumentos de tipo o nome do tipo de classe a seguir deve listar parâmetros na ordem usada na lista de parâmetros de tipo

Uma lista de argumentos de modelo ou genérico estava mal formada.

O exemplo a seguir gera C3860:

```cpp
// C3860.cpp
// compile with: /LD
template <class T1, class T2>
struct A {
   void f();
};

template <class T2, class T1>
void A<T1, T2>::f() {}   // C3860
```

Resolução possível:

```cpp
// C3860b.cpp
// compile with: /c
template <class T1, class T2>
struct A {
   void f();
};

template <class T2, class T1>
void A<T2, T1>::f() {}
```

C3860 também pode ocorrer ao usar genéricos:

```cpp
// C3860c.cpp
// compile with: /clr
generic<class T,class U>
ref struct GC {
   void f();
};

generic<class T, class U>
void GC<T,T>::f() {}   // C3860
```

Resolução possível:

```cpp
// C3860d.cpp
// compile with: /clr /c
generic<class T,class U>
ref struct GC {
   void f();
};

generic<class T, class U>
void GC<T,U>::f() {}
```
