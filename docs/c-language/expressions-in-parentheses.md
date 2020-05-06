---
title: Expressões em parênteses
ms.date: 11/04/2016
helpviewer_keywords:
- parentheses
- expression evaluation, evaluation order
- expressions [C++], evaluating
- parentheses, expressions
ms.assetid: b8636147-6982-408c-9e64-29e40678ee43
ms.openlocfilehash: d0105556530161991b46c5ee25cd73f2f995063f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62233731"
---
# <a name="expressions-in-parentheses"></a>Expressões em parênteses

É possível colocar qualquer operando entre parênteses sem alterar o tipo ou o valor da expressão dentro deles. Por exemplo, na expressão:

```
( 10 + 5 ) / 5
```

os parênteses `10 + 5` significam que o valor de `10 + 5` é avaliado primeiro e torna-se o operando esquerdo do operador Division (**/**). O resultado de `( 10 + 5 ) / 5` será 3. Sem os parênteses, `10 + 5 / 5` seria avaliado como 11.

Embora os parênteses afetem a maneira como os operandos são agrupados em uma expressão, eles não podem assegurar uma determinada ordem de avaliação em todos os casos. Por exemplo, nem os parênteses ou o agrupamento da esquerda para a direita da seguinte expressão assegura que o valor de `i` esteja em qualquer uma das subexpressões:

```
( i++ +1 ) * ( 2 + i )
```

O compilador é livre para avaliar os dois lados da multiplicação em qualquer ordem. Se o valor inicial de `i` for zero, toda a expressão pode ser avaliada como qualquer uma destas duas instruções:

```
( 0 + 1 + 1 ) * ( 2 + 1 )
( 0 + 1 + 1 ) * ( 2 + 0 )
```

As exceções que resultam dos efeitos colaterais são discutidas em [Efeitos colaterais](../c-language/side-effects.md).

## <a name="see-also"></a>Confira também

[Expressões primárias C](../c-language/c-primary-expressions.md)
