---
title: '`__restrict`'
description: Descreve a `__restrict` palavra-chave Microsoft Visual C++.
ms.date: 11/6/2020
f1_keywords:
- __restrict_cpp
- __restrict
- _restrict
helpviewer_keywords:
- __restrict keyword [C++]
ms.openlocfilehash: f23574f49712928e0095f29a3b88b0c05b185eab
ms.sourcegitcommit: 3f0c1dcdcce25865d1a1022bcc5b9eec79f69025
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2020
ms.locfileid: "94381565"
---
# `__restrict`

Como o modificador **`__declspec` ( [`restrict`](../cpp/restrict.md) )** , a **`__restrict`** palavra-chave (dois sublinhados à esquerda ' _ ') indica que um símbolo não tem um alias no escopo atual. A **`__restrict`** palavra-chave é diferente do `__declspec (restrict)` modificador das seguintes maneiras:

- A **`__restrict`** palavra-chave é válida somente em variáveis e `__declspec (restrict)` só é válida em declarações de função e definições.

- **`__restrict`** é semelhante a [`restrict`](../c-language/type-qualifiers.md#restrict) para C começando em C99, mas **`__restrict`** pode ser usado em programas C++ e C.

- Quando **`__restrict`** é usado, o compilador não propaga a propriedade sem alias de uma variável. Ou seja, se você atribuir uma **`__restrict`** variável a uma não **`__restrict`** variável, o compilador ainda permitirá que a variável não __restrict seja alias. Isso é diferente do comportamento da **`restrict`** palavra-chave C99 C Language.

Em geral, se você quiser afetar o comportamento de uma função inteira, use **`__declspec (restrict)`** em vez da palavra-chave.

Para compatibilidade com versões anteriores, **`_restrict`** é um sinônimo para **`__restrict`** a menos que a opção do compilador [ `/Za` \( desabilite extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

No Visual Studio 2015 e posterior, o **`__restrict`** pode ser usado em referências do C++.

> [!NOTE]
> Quando usado em uma variável que também tenha a [`volatile`](../cpp/volatile-cpp.md) palavra-chave, **`volatile`** terá precedência.

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
