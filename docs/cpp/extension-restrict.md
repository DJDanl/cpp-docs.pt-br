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
ms.openlocfilehash: cb340554bc20516175400c4d14a5d0dba934a313
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188955"
---
# <a name="__restrict"></a>__restrict

Como o modificador de **__declspec ( [restrict](../cpp/restrict.md) )** , a palavra-chave **__restrict** indica que um símbolo não tem um alias no escopo atual. A palavra-chave **__restrict** difere do modificador `__declspec ( restrict )` das seguintes maneiras:

- A palavra-chave **__restrict** é válida somente em variáveis e `__declspec ( restrict )` só é válida em declarações de função e definições.

- **__restrict** é semelhante a **restringir** da especificação de C99, mas **__restrict** pode ser usada em C++ programas ou C.

- Quando **__restrict** for usado, o compilador não propagará a propriedade sem alias de uma variável. Ou seja, se você atribuir uma variável **__restrict** a uma variável não **__restrict** , o compilador ainda permitirá que a variável não __restrict seja alias. Isso é diferente do comportamento da palavra-chave **restrict** da especificação C99.

Em geral, se você afetar o comportamento de uma função inteira, será melhor usar `__declspec ( restrict )` do que a palavra-chave.

Para compatibilidade com versões anteriores, **_restrict** é um sinônimo para **__restrict** , a menos que a opção de compilador [/za \(desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

No Visual Studio 2015 e posterior, **__restrict** pode ser usado em C++ referências.

> [!NOTE]
>  Quando usado em uma variável que também tem a palavra-chave [volátil](../cpp/volatile-cpp.md) , **volatile** terá precedência.

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
