---
title: Erro do compilador C2993
ms.date: 11/04/2016
f1_keywords:
- C2993
helpviewer_keywords:
- C2993
ms.assetid: 4ffd2b78-654b-46aa-95a6-b62101cf91c8
ms.openlocfilehash: 5aa0d27b2d469f53ec521f587172398b7d4c2d1b
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761225"
---
# <a name="compiler-error-c2993"></a>Erro do compilador C2993

' identifier ': tipo inválido para parâmetro de modelo não tipo ' Parameter '

Você não pode declarar um modelo com um argumento de estrutura ou de União. Use ponteiros para passar estruturas e uniões como parâmetros de modelo.

O exemplo a seguir gera C2993:

```cpp
// C2993.cpp
// compile with: /c
// C2993 expected
struct MyStruct {
   int a;char b;
};

template <class T, struct MyStruct S>   // C2993

// try the following line instead
// template <class T, struct MyStruct * S>
class CMyClass {};
```

Esse erro também será gerado como resultado do trabalho de conformidade do compilador que foi feito no Visual Studio .NET 2003: os parâmetros de modelo não tipo de ponto flutuante não são mais permitidos. O C++ padrão não permite parâmetros de modelo sem tipo de ponto flutuante.

Se for um modelo de função, use um argumento de função para passar o parâmetro de modelo sem tipo de ponto flutuante (esse código será válido nas versões do Visual Studio .NET 2003 e Visual Studio .NET do Visual C++). Se for um modelo de classe, não há uma solução fácil.

```cpp
// C2993b.cpp
// compile with: /c
template<class T, float f> void func(T) {}   // C2993

// OK
template<class T>   void func2(T, float) {}
```
