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
ms.openlocfilehash: 6318e6d78f6c4c4bb6827a79d26bca028dfe3f3f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233737"
---
# <a name="__restrict"></a>__restrict

Assim como o modificador **__declspec ( [restrict](../cpp/restrict.md) )** , a **`__restrict`** palavra-chave indica que um símbolo não tem um alias no escopo atual. A **`__restrict`** palavra-chave é diferente do `__declspec ( restrict )` modificador das seguintes maneiras:

- A **`__restrict`** palavra-chave é válida somente em variáveis e `__declspec ( restrict )` só é válida em declarações de função e definições.

- **`__restrict`** é semelhante à **`restrict`** da especificação C99, mas **`__restrict`** pode ser usado em programas C++ ou C.

- Quando **`__restrict`** for usado, o compilador não propagará a propriedade sem alias de uma variável. Ou seja, se você atribuir uma **`__restrict`** variável a uma não **`__restrict`** variável, o compilador ainda permitirá que a variável não __restrict seja alias. Isso é diferente do comportamento da **`restrict`** palavra-chave da especificação C99.

Em geral, se você afetar o comportamento de uma função inteira, será melhor usar `__declspec ( restrict )` do que a palavra-chave.

Para compatibilidade com versões anteriores, **_restrict** é um sinônimo para **`__restrict`** a menos que a opção do compilador [/za \( desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

No Visual Studio 2015 e posterior, o **`__restrict`** pode ser usado em referências do C++.

> [!NOTE]
> Quando usado em uma variável que também tem a palavra-chave [volatile](../cpp/volatile-cpp.md) , **`volatile`** terá precedência.

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
