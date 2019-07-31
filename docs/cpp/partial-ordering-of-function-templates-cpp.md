---
title: Ordenação parcial de modelos de função (C++)
ms.date: 07/30/2019
helpviewer_keywords:
- partial ordering of function templates
ms.assetid: 0c17347d-0e80-47ad-b5ac-046462d9dc73
ms.openlocfilehash: 0c4f11b4b3e02504c4786ea34441362b542959d6
ms.sourcegitcommit: 725e86dabe2901175ecc63261c3bf05802dddff4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/31/2019
ms.locfileid: "68682420"
---
# <a name="partial-ordering-of-function-templates-c"></a>Ordenação parcial de modelos de função (C++)

Vários modelos de função que correspondem à lista de argumentos de uma chamada de função podem estar disponíveis. O C++ define a ordenação parcial dos modelos de função para especificar que função deve ser chamada. A ordenação é parcial, pois pode haver alguns modelos que são considerados igualmente especializados.

O compilador escolhe a função de modelo mais especializada disponível nas correspondências possíveis. Por exemplo, se um modelo de função usa um `T` tipo e outro modelo de função `T*` que usa está disponível `T*` , a versão é considerada mais especializada. Ele é preferencial sobre a versão `T` genérica sempre que o argumento é um tipo de ponteiro, mesmo que ambos possam ser correspondências permitidas.

Use o seguinte processo para determinar se um candidato a modelo de função é mais especializado:

1. Considere dois modelos de função, T1 e T2.

1. Substitua os parâmetros em T1 por um tipo hipotético exclusivo X.

1. Com a lista de parâmetros em T1, veja se T2 é um modelo válido para essa lista de parâmetros. Ignore as conversões implícitas.

1. Repita o mesmo processo com T1 e T2 invertidos.

1. Se um modelo for uma lista de argumentos de modelo válida para o outro modelo, mas o converso não for verdadeiro, esse modelo será considerado menos especializado do que o outro modelo. Se, usando a etapa anterior, os dois modelos formarem argumentos válidos para um ao outro, eles serão considerados igualmente especializados e uma chamada ambígua resultará quando você tentar usá-los.

1. Usando estas regras:

   1. Uma especialização de modelo para um tipo específico é mais especializada do que a que usa um argumento de tipo genérico.

   1. Um modelo que assume `T*` apenas o é mais especializado que apenas `T`um, pois um tipo `X*` hipotético é um argumento válido para um `T` argumento de modelo, `X` mas não é um argumento válido para um `T*`argumento de modelo.

   1. `const T`é mais especializado do `T`que, `const X` porque é um argumento válido para `T` um argumento de modelo `X` , mas não é um argumento válido `const T` para um argumento de modelo.

   1. `const T*`é mais especializado do `T*`que, `const X*` porque é um argumento válido para `T*` um argumento de modelo `X*` , mas não é um argumento válido `const T*` para um argumento de modelo.

## <a name="example"></a>Exemplo

O exemplo a seguir funciona conforme especificado no padrão:

```cpp
// partial_ordering_of_function_templates.cpp
// compile with: /EHsc
#include <iostream>

template <class T> void f(T) {
   printf_s("Less specialized function called\n");
}

template <class T> void f(T*) {
   printf_s("More specialized function called\n");
}

template <class T> void f(const T*) {
   printf_s("Even more specialized function for const T*\n");
}

int main() {
   int i =0;
   const int j = 0;
   int *pi = &i;
   const int *cpi = &j;

   f(i);   // Calls less specialized function.
   f(pi);  // Calls more specialized function.
   f(cpi); // Calls even more specialized function.
   // Without partial ordering, these calls would be ambiguous.
}
```

### <a name="output"></a>Saída

```Output
Less specialized function called
More specialized function called
Even more specialized function for const T*
```

## <a name="see-also"></a>Consulte também

[Modelos de função](../cpp/function-templates.md)
