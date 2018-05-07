---
title: C3615 de erro do compilador | Microsoft Docs
ms.date: 10/24/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3615
dev_langs:
- C++
helpviewer_keywords:
- C3615
ms.assetid: 5ce96ba9-3d31-49f3-9aa8-24e5cdf6dcfc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ce1ab43f8e15535614cedf43dba42fef882bf87a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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