---
title: Especialização explícita de modelos de função
ms.date: 11/04/2016
helpviewer_keywords:
- overriding, functions
- function templates, specialization
- explicit specialization of function templates
- declaring functions [C++], specialization of function template
- specialization of function templates
ms.assetid: eb0fcb73-eaed-42a1-9b83-14b055a34bf8
ms.openlocfilehash: 638b5dbca1b3c0c9b9c9c946418ea70354ff6266
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220555"
---
# <a name="explicit-specialization-of-function-templates"></a>Especialização explícita de modelos de função

Com um modelo de função, você pode definir o comportamento especial para um tipo específico fornecendo uma especialização explícita (substituição) do modelo da função para esse tipo. Por exemplo:

```cpp
template<> void MySwap(double a, double b);
```

Essa declaração permite que você defina uma função diferente para **`double`** variáveis. Como funções que não são de modelo, as conversões de tipo padrão (como promover uma variável do tipo **`float`** para **`double`** ) são aplicadas.

## <a name="example"></a>Exemplo

```cpp
// explicit_specialization.cpp
template<class T> void f(T t)
{
};

// Explicit specialization of f with 'char' with the
// template argument explicitly specified:
//
template<> void f<char>(char c)
{
}

// Explicit specialization of f with 'double' with the
// template argument deduced:
//
template<> void f(double d)
{
}
int main()
{
}
```

## <a name="see-also"></a>Confira também

[Modelos de função](../cpp/function-templates.md)
