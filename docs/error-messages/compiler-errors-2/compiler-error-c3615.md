---
title: Erro do compilador C3615
ms.date: 10/24/2017
f1_keywords:
- C3615
helpviewer_keywords:
- C3615
ms.assetid: 5ce96ba9-3d31-49f3-9aa8-24e5cdf6dcfc
ms.openlocfilehash: 17a210e2a514af1ffd62bf38651c4d17bd1fe32b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230786"
---
# <a name="compiler-error-c3615"></a>Erro do compilador C3615

> a função constexpr '*Function*' não pode resultar em uma expressão constante

A *função* Function não pôde ser avaliada como **`constexpr`** no momento da compilação. Para ser **`constexpr`** , uma função só pode chamar outras **`constexpr`** funções.

## <a name="example"></a>Exemplo

O Visual Studio 2017 gera um erro corretamente quando o operando à esquerda de uma operação de avaliação condicional não é válido em um **`constexpr`** contexto. O código a seguir é compilado no Visual Studio 2015, mas não no Visual Studio 2017.

```cpp
// C3615.cpp
// Compile with: /c

template<int N>
struct myarray
{
    int size() const { return N; }
};

constexpr bool f(const myarray<1> &arr)
{
    return arr.size() == 10 || arr.size() == 11; // C3615 starting in Visual Studio 2017
}
```

Para corrigir esse problema, declare a `array::size()` função como **`constexpr`** ou remova o **`constexpr`** qualificador de `f` .
