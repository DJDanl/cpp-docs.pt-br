---
title: Erro do compilador C2146
ms.date: 11/04/2016
f1_keywords:
- C2146
helpviewer_keywords:
- C2146
ms.assetid: 6bfb7de6-6723-4486-9350-c66ef88d7a64
ms.openlocfilehash: 3a0fd9c49a71f6f53d1a109378e3a6894bb68723
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50658062"
---
# <a name="compiler-error-c2146"></a>Erro do compilador C2146

Erro de sintaxe: faltando 'token' antes do identificador 'identifier'

O compilador esperado `token` e encontrado `identifier` em vez disso.  Possíveis causas:

1. Erro de ortografia ou de maiusculas e minúsculas.

1. Faltando especificador de tipo na declaração do identificador.

Esse erro pode ser causado por um erro de digitação. Erro [C2065](../../error-messages/compiler-errors-1/compiler-error-c2065.md) precede normalmente, esse erro.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2146.

```
// C2146.cpp
class CDeclaredClass {};

class CMyClass {
   CUndeclared m_myClass;   // C2146
   CDeclaredClass m_myClass2;   // OK
};

int main() {
   int x;
   int t x;   // C2146 : missing semicolon before 'x'
}
```

## <a name="example"></a>Exemplo

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: faltando `typename` palavra-chave.

O exemplo a seguir é compilado no Visual Studio .NET 2002, mas haverá falha no Visual Studio .NET 2003:

```
// C2146b.cpp
// compile with: /c
template <typename T>
struct X {
   struct Y {
      int i;
   };
   Y memFunc();
};

template <typename T>
X<T>::Y func() { }   // C2146

// OK
template <typename T>
typename X<T>::Y func() { }
```

## <a name="example"></a>Exemplo

Você também verá esse erro como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: especializações explícitas não localizar os parâmetros de modelo do modelo primário.

O uso de `T` do modelo primário não é permitido em especialização explícita. Para o código seja válido nas versões do Visual Studio .NET 2003 e o Visual Studio .NET do Visual C++, substitua todas as instâncias do parâmetro de modelo na especialização com o tipo explicitamente especializado.

O exemplo a seguir é compilado no Visual Studio .NET, mas haverá falha no Visual Studio .NET 2003:

```
// C2146_c.cpp
// compile with: /c
template <class T>
struct S;

template <>
struct S<int> {
   T m_t;   // C2146
   int m_t2;   // OK
};
```