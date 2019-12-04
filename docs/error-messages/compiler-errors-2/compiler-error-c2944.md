---
title: Erro do compilador C2944
ms.date: 11/04/2016
f1_keywords:
- C2944
helpviewer_keywords:
- C2944
ms.assetid: f209e668-e72f-442a-a438-8c4ff43a404a
ms.openlocfilehash: 542f7def550632a29fcb7ae28825b32b8c26f17d
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755376"
---
# <a name="compiler-error-c2944"></a>Erro do compilador C2944

' class ': tipo-classe-ID redefinido como um argumento de valor de um modelo

Você não pode usar uma classe genérica ou de modelo, em vez de um símbolo, como um argumento de valor de modelo.

O exemplo a seguir gera C2944:

```cpp
// C2944.cpp
// compile with: /c
template<class T>
class TC { };

template <int TC<int> > struct X1 { };   // C2944

template <class T > struct X2 {};
```

C2944 também pode ocorrer ao usar genéricos:

```cpp
// C2944b.cpp
// compile with: /clr /c
generic<class T>
ref class GC {};

template <int GC<int> > struct X2 { };   // C2944
template <class T> struct X3 {};   // OK
```
