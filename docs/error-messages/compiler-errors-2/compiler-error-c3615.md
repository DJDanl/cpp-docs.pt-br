---
title: Erro do compilador C3615
ms.date: 10/24/2017
f1_keywords:
- C3615
helpviewer_keywords:
- C3615
ms.assetid: 5ce96ba9-3d31-49f3-9aa8-24e5cdf6dcfc
ms.openlocfilehash: c1a5b6edbc87e14de267cf962dc2b1a71dd6be12
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200532"
---
# <a name="compiler-error-c3615"></a>Erro do compilador C3615

> a função constexpr '*Function*' não pode resultar em uma expressão constante

A *função* Function não pôde ser avaliada como `constexpr` no tempo de compilação. Para ser `constexpr`, uma função só pode chamar outras funções de `constexpr`.

## <a name="example"></a>Exemplo

O Visual Studio 2017 gera um erro corretamente quando o operando à esquerda de uma operação de avaliação condicional não é válido em um contexto de `constexpr`. O código a seguir é compilado no Visual Studio 2015, mas não no Visual Studio 2017.

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

Para corrigir esse problema, declare a função `array::size()` como `constexpr` ou remova o qualificador `constexpr` de `f`.
