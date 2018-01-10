---
title: C3615 de erro do compilador | Microsoft Docs
ms.date: 10/24/2017
ms.technology: cpp-tools
ms.topic: error-reference
f1_keywords: C3615
dev_langs: C++
helpviewer_keywords: C3615
ms.assetid: 5ce96ba9-3d31-49f3-9aa8-24e5cdf6dcfc
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ea5502ee6e66cf3add4a4ff97e4922a66712ed70
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3615"></a>C3615 de erro do compilador

> função constexpr '*função*' não pode resultar em uma expressão constante

A função *função* não pôde ser avaliada como `constexpr` em tempo de compilação. Para ser `constexpr`, uma função só pode chamar outro `constexpr` funções.

## <a name="example"></a>Exemplo

2017 do Visual Studio gera um erro corretamente quando o operando esquerdo de uma operação de avaliar condicionalmente não é válido em um `constexpr` contexto. O código a seguir é compilado no Visual Studio 2015, mas não no Visual Studio de 2017.

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

Para corrigir esse problema, a declarar a `array::size()` funcionar como `constexpr` ou remover o `constexpr` qualificador de `f`.