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
ms.openlocfilehash: 83fedd9d3cc6cd7c08ba79d2ed83e9f62d919e29
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857236"
---
# <a name="unary-plus-and-negation-operators--and--"></a>Operadores unários de adição e de negação: + e -

## <a name="syntax"></a>Sintaxe

```
+ cast-expression
- cast-expression
```

## <a name="-operator"></a>Operador +

O resultado do operador de adição unário ( **+** ) é o valor de seu operando. O operando para o operador de adição unário deve ser de um tipo aritmético.

A promoção integral é executada em operandos integrais. O tipo resultante é o tipo para o qual o operando é promovido. Assim, a expressão `+ch`, em que `ch` é do tipo **Char**, resulta no tipo **int**; o valor não é modificado. Consulte [conversões padrão](standard-conversions.md) para obter mais informações sobre como a promoção é feita.

## <a name="--operator"></a>Operador -

O operador de negação unário ( **-** ) produz o negativo de seu operando. O operando para o operador de negação unário deve ser um tipo aritmético.

A promoção de integral é executada em operandos integrais, e o tipo resultante é o tipo para o qual o operando é promovido. Consulte [conversões padrão](standard-conversions.md) para obter mais informações sobre como a promoção é executada.

**Seção específica da Microsoft**

A negação unária de quantidades não assinadas é executada subtraindo o valor do operando de 2^n, onde n é o número de bits em um objeto de um determinado tipo sem assinatura.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)