---
title: Restrict | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __restrict_cpp
dev_langs:
- C++
helpviewer_keywords:
- __restrict keyword [C++]
ms.assetid: 2d151b4d-f930-49df-bd16-d8757ec7fa83
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3d9754f8b0b218fc4d627eb0e27504e8521bf776
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46076431"
---
# <a name="restrict"></a>__restrict

Como o **declspec ( [restringir](../cpp/restrict.md) )** modificador, o **Restrict** palavra-chave indica que um símbolo não é um alias no escopo atual. O **Restrict** difere de palavra-chave a `__declspec ( restrict )` modificador das seguintes maneiras:

- O **Restrict** palavra-chave só é válida em variáveis, e `__declspec ( restrict )` só é válido em declarações de função e definições.

- **Restrict** é semelhante ao **restringir** das especificações C99, mas **Restrict** pode ser usado em programas C ou C++.

- Quando **Restrict** é usado, o compilador não propaga a propriedade de alias não de uma variável. Ou seja, se você atribuir uma **Restrict** variável para um**Restrict** variável, o compilador ainda permitirá que o não- Restrict variável para receber um alias. Isso é diferente do comportamento do **restringir** palavra-chave da especificação C99.

Em geral, se você afeta o comportamento de uma função inteira, é melhor usar `__declspec ( restrict )` que a palavra-chave.

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