---
title: __restrict
ms.date: 10/10/2018
f1_keywords:
- __restrict_cpp
- __restrict
- _restrict
helpviewer_keywords:
- __restrict keyword [C++]
ms.assetid: 2d151b4d-f930-49df-bd16-d8757ec7fa83
ms.openlocfilehash: 27ac76251456d9a0bf5908ad6d1fc2bee7534e9f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360813"
---
# <a name="__restrict"></a>__restrict

Como o modificador **__declspec [(restringir),](../cpp/restrict.md) ** a **palavra-chave __restrict** indica que um símbolo não está aliased no escopo atual. A **palavra-chave __restrict** `__declspec ( restrict )` difere do modificador das seguintes maneiras:

- A **palavra-chave __restrict** é válida `__declspec ( restrict )` apenas em variáveis, e só é válida em declarações e definições de função.

- **__restrict** é semelhante à **restrição** da especificação C99, mas **__restrict** pode ser usado em programas C++ ou C.

- Quando **__restrict** é usado, o compilador não propagará a propriedade sem alias de uma variável. Ou seja, se você atribuir uma variável **__restrict** a uma variável não **__restrict,** o compilador ainda permitirá que a variável não __restrict seja aliasada. Isto é diferente do comportamento da palavra-chave **restringir** da especificação C99.

Geralmente, se você afeta o comportamento de uma função `__declspec ( restrict )` inteira, é melhor usar do que a palavra-chave.

Para compatibilidade com as versões anteriores, **_restrict** é um sinônimo para **__restrict** a menos que a opção de compilador [/Za \(Disable extensões de idioma)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

No Visual Studio 2015 e posterior, **__restrict** pode ser usado em referências C++.

> [!NOTE]
> Quando usado em uma variável que também tem a palavra-chave [volátil,](../cpp/volatile-cpp.md) **volátil** terá precedência.

## <a name="example"></a>Exemplo

```cpp
// __restrict_keyword.c
// compile with: /LD
// In the following function, declare a and b as disjoint arrays
// but do not have same assurance for c and d.
void sum2(int n, int * __restrict a, int * __restrict b,
          int * c, int * d) {
   int i;
   for (i = 0; i < n; i++) {
      a[i] = b[i] + c[i];
      c[i] = b[i] + d[i];
    }
}

// By marking union members as __restrict, tell compiler that
// only z.x or z.y will be accessed in any given scope.
union z {
   int * __restrict x;
   double * __restrict y;
};
```

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)
