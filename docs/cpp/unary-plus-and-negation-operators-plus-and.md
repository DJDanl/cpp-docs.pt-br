---
title: 'Operadores unários de adição e de negação: + e -'
ms.date: 11/04/2016
f1_keywords:
- +
- '-'
helpviewer_keywords:
- unary operators [C++], plus
- '- operator'
- negation operator
- + operator [C++], unary operators
- + operator
ms.assetid: 2c58c4f4-0d92-4ae3-9d0c-1a6157875cc1
ms.openlocfilehash: de90cd2068f9b701167a340fe0b335e2a6c93102
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225794"
---
# <a name="unary-plus-and-negation-operators--and--"></a>Operadores unários de adição e de negação: + e -

## <a name="syntax"></a>Sintaxe

```
+ cast-expression
- cast-expression
```

## <a name="-operator"></a>Operador +

O resultado do operador unário ( **+** ) é o valor de seu operando. O operando para o operador de adição unário deve ser de um tipo aritmético.

A promoção integral é executada em operandos integrais. O tipo resultante é o tipo para o qual o operando é promovido. Portanto, a expressão `+ch` , em que `ch` é do tipo **`char`** , resulta em tipo **`int`** ; o valor não é modificado. Consulte [conversões padrão](standard-conversions.md) para obter mais informações sobre como a promoção é feita.

## <a name="--operator"></a>Operador -

O operador de negação unário ( **-** ) produz o negativo de seu operando. O operando para o operador de negação unário deve ser um tipo aritmético.

A promoção de integral é executada em operandos integrais, e o tipo resultante é o tipo para o qual o operando é promovido. Consulte [conversões padrão](standard-conversions.md) para obter mais informações sobre como a promoção é executada.

**Específico da Microsoft**

A negação unária de quantidades não assinadas é executada subtraindo o valor do operando de 2^n, onde n é o número de bits em um objeto de um determinado tipo sem assinatura.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Operadores internos C++, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)
