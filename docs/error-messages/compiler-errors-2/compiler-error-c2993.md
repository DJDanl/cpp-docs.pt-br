---
title: Erro do compilador C2993
ms.date: 11/04/2016
f1_keywords:
- C2993
helpviewer_keywords:
- C2993
ms.assetid: 4ffd2b78-654b-46aa-95a6-b62101cf91c8
ms.openlocfilehash: 5be4836332f67f2064f60a3b058db159a18ca1e0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160881"
---
# <a name="compiler-error-c2993"></a>Erro do compilador C2993

'identifier': tipo inválido para parâmetro de modelo sem tipo 'parameter'

Você não pode declarar um modelo com uma estrutura ou união argumento. Use ponteiros para passar estruturas e uniões como parâmetros de modelo.

O exemplo a seguir gera C2993:

```
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

Esse erro também será gerado como resultado do trabalho de conformidade do compilador que foi feito no Visual Studio .NET 2003: parâmetros de modelo sem tipo não é mais permitidos de ponto flutuante. O padrão C++ não permite parâmetros de modelo sem tipo do ponto flutuante.

Se for um modelo de função, use um argumento de função para passar o flutuante ponto de parâmetro de modelo sem tipo (esse código será válido nas versões do Visual Studio .NET 2003 e o Visual Studio .NET do Visual C++). Se for um modelo de classe, não há nenhuma solução alternativa mais simples.

```
// C2993b.cpp
// compile with: /c
template<class T, float f> void func(T) {}   // C2993

// OK
template<class T>   void func2(T, float) {}
```