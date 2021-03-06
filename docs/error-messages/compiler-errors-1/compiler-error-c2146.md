---
title: Erro do compilador C2146
ms.date: 11/04/2016
f1_keywords:
- C2146
helpviewer_keywords:
- C2146
ms.assetid: 6bfb7de6-6723-4486-9350-c66ef88d7a64
ms.openlocfilehash: ff9dc9861643afa364db4b6364fa5e7bb33e8c8c
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90742613"
---
# <a name="compiler-error-c2146"></a>Erro do compilador C2146

erro de sintaxe: ' token ' ausente antes do identificador ' identifier '

O compilador esperava `token` e foi encontrado `identifier` em seu lugar.  Possíveis causas:

1. Erro de ortografia ou de maiúsculas e minúsculas.

1. Especificador de tipo ausente na declaração do identificador.

Esse erro pode ser causado por um erro tipográfico. O erro [C2065](../../error-messages/compiler-errors-1/compiler-error-c2065.md) geralmente precede esse erro.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2146.

```cpp
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

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: **`typename`** palavra-chave Missing.

O exemplo a seguir é compilado no Visual Studio .NET 2002, mas falhará no Visual Studio .NET 2003:

```cpp
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

Você também verá esse erro como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: especializações explícitas não localizam mais parâmetros de modelo do modelo primário.

O uso de `T` do modelo primário não é permitido na especialização explícita. Para que o código seja válido no Visual Studio .NET 2003 e no Visual Studio .NET, substitua todas as instâncias do parâmetro de modelo na especialização pelo tipo especializado explicitamente.

O exemplo a seguir é compilado no Visual Studio .NET, mas falhará no Visual Studio .NET 2003:

```cpp
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
