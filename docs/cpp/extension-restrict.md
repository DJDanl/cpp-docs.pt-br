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
ms.openlocfilehash: 76cdf9424e6eab33a3a92b3f98d9c2b0b04ff667
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50454538"
---
# <a name="restrict"></a>__restrict

Como o **declspec ( [restringir](../cpp/restrict.md) )** modificador, o **Restrict** palavra-chave indica que um símbolo não é um alias no escopo atual. O **Restrict** difere de palavra-chave a `__declspec ( restrict )` modificador das seguintes maneiras:

- O **Restrict** palavra-chave só é válida em variáveis, e `__declspec ( restrict )` só é válido em declarações de função e definições.

- **Restrict** é semelhante ao **restringir** das especificações C99, mas **Restrict** pode ser usado em programas C ou C++.

- Quando **Restrict** é usado, o compilador não propaga a propriedade de alias não de uma variável. Ou seja, se você atribuir uma **Restrict** variável para um**Restrict** variável, o compilador ainda permitirá que o não- Restrict variável para receber um alias. Isso é diferente do comportamento do **restringir** palavra-chave da especificação C99.

Em geral, se você afeta o comportamento de uma função inteira, é melhor usar `__declspec ( restrict )` que a palavra-chave.

Para compatibilidade com versões anteriores, **_restrict** é um sinônimo de **Restrict** , a menos que a opção de compilador [/Za \(desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) é especificado.

No Visual Studio 2015 e versões posteriores, **Restrict** pode ser usado em referências C++.

> [!NOTE]
>  Quando usado em uma variável que também tem o [volátil](../cpp/volatile-cpp.md) palavra-chave **volátil** terá precedência.

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

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)