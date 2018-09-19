---
title: Erro do compilador C2993 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2993
dev_langs:
- C++
helpviewer_keywords:
- C2993
ms.assetid: 4ffd2b78-654b-46aa-95a6-b62101cf91c8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 09b3c789cc15d2e146f1c5031003fc74d783e827
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46081930"
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