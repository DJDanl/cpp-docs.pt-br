---
title: Erro do compilador C2477
ms.date: 11/04/2016
f1_keywords:
- C2477
helpviewer_keywords:
- C2477
ms.assetid: 60bc324b-6605-4833-8099-a291efc712e7
ms.openlocfilehash: aa276ea839f11574609b183d78b46e08581a1b51
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74743647"
---
# <a name="compiler-error-c2477"></a>Erro do compilador C2477

' member ': membro de dados static não pode ser inicializado via classe derivada

Um membro de dados estáticos de uma classe de modelo foi inicializado incorretamente. Essa é uma alteração significativa com versões do compilador da C++ Microsoft antes do Visual Studio .NET 2003, a fim de estar de acordo com C++ o padrão ISO.

O exemplo a seguir gera C2477:

```cpp
// C2477.cpp
// compile with: /Za /c
template <class T>
struct S {
   static int n;
};

struct X {};
struct A: S<X> {};

int A::n = 0;   // C2477

template<>
int S<X>::n = 0;
```
