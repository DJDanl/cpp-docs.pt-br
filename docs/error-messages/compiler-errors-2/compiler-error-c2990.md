---
title: Erro do compilador C2990
ms.date: 11/04/2016
f1_keywords:
- C2990
helpviewer_keywords:
- C2990
ms.assetid: 674e9f6a-6743-4af0-a7ed-cbe11103a2f8
ms.openlocfilehash: 1c58c2d5da0049ec670e11c930b397caec3cbbee
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74751515"
---
# <a name="compiler-error-c2990"></a>Erro do compilador C2990

' class ': tipo diferente de classe como já foi declarado como um tipo de classe

A classe não genérica ou de modelo redefine uma classe genérica ou de modelo. Verifique se há conflitos nos arquivos de cabeçalho.

O exemplo a seguir gera C2990:

```cpp
// C2990.cpp
// compile with: /c
template <class T>
class C{};
class C{};   // C2990
```

C2990 também pode ocorrer ao usar genéricos:

```cpp
// C2990b.cpp
// compile with: /clr /c
generic <class T>
ref struct GC;

ref struct GC {};   // C2990
```

O C2990 também pode ocorrer devido a uma alteração significativa no compilador C++ da Microsoft para Visual Studio 2005; o compilador agora requer que várias declarações para o mesmo tipo sejam idênticas em relação à especificação de modelo.

O exemplo a seguir gera C2990:

```cpp
// C2990c.cpp
// compile with: /c
template<class T>
class A;

template<class T>
struct A2 {
   friend class A;   // C2990
};

// OK
template<class T>
struct B {
   template<class T>
   friend class A;
};
```
