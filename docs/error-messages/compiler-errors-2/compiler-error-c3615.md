---
title: Erro do compilador C3615
ms.date: 10/24/2017
f1_keywords:
- C3615
helpviewer_keywords:
- C3615
ms.assetid: 5ce96ba9-3d31-49f3-9aa8-24e5cdf6dcfc
ms.openlocfilehash: e966295b5ab63350828ddb73d6791a9e30bb5c59
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50652212"
---
# <a name="compiler-error-c3615"></a>Erro do compilador C3615

> função constexpr '*função*' não pode resultar em uma expressão constante

A função *função* não pode ser avaliada como `constexpr` em tempo de compilação. Para ser `constexpr`, uma função só pode chamar outro `constexpr` funções.

## <a name="example"></a>Exemplo

Visual Studio 2017 gera corretamente um erro quando o operando esquerdo de uma operação de avaliação condicional não é válido em um `constexpr` contexto. O código a seguir é compilado no Visual Studio 2015, mas não no Visual Studio 2017.

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

Para corrigir esse problema, declare a `array::size()` funcionar como `constexpr` ou remova o `constexpr` qualificador de `f`.