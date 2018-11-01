---
title: Erro do compilador C2477
ms.date: 11/04/2016
f1_keywords:
- C2477
helpviewer_keywords:
- C2477
ms.assetid: 60bc324b-6605-4833-8099-a291efc712e7
ms.openlocfilehash: 27db194cb308d711a259127b628c60b4d10b94ff
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50458156"
---
# <a name="compiler-error-c2477"></a>Erro do compilador C2477

'member': membro de dados estático não pode ser inicializado via classe derivada

Um membro de dados estáticos de uma classe de modelo foi inicializado incorretamente. Isso é uma alteração significativa com as versões do compilador do Visual C++ antes do Visual Studio .NET 2003, para estar de acordo com o padrão ISO C++.

O exemplo a seguir gera C2477:

```
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