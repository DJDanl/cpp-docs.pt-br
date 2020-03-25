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
ms.openlocfilehash: c9d77cef790bdd0a65651ffb7246e685175482b1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179985"
---
# <a name="explicit-specialization-of-function-templates"></a>Especialização explícita de modelos de função

Com um modelo de função, você pode definir o comportamento especial para um tipo específico fornecendo uma especialização explícita (substituição) do modelo da função para esse tipo. Por exemplo:

```cpp
template<> void MySwap(double a, double b);
```

Essa declaração permite que você defina uma função diferente para variáveis **duplas** . Como as funções que não são de modelo, as conversões de tipo padrão (como promover uma variável do tipo **float** para **Double**) são aplicadas.

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
