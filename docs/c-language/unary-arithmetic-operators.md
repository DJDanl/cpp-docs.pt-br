---
title: Operadores aritméticos unários | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- operators [C], unary
- tilde (~) one's complement operator
- bitwise-complement operator
- arithmetic operators [C++], unary
- + operator, unary operators
- unary operators
- exclamation points
- ~ operator, one's complement operator
- logical negation
- '! operator, unary arithmetic operators'
ms.assetid: 78c91415-d469-499e-9dfe-4435350fd333
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b16d68b6a787dac8c55fcb68190195e66013f980
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46091836"
---
# <a name="unary-arithmetic-operators"></a>Operadores aritméticos unários

Vários operadores do C – unário de adição, de negação aritmética, de complemento e de negação lógica – são discutidos na lista a seguir:

|Operador|Descrição|
|--------------|-----------------|
|**+**|O operador unário de adição que precede uma expressão entre parênteses força o agrupamento das operações incluídas. É usado com expressões que envolvem mais de um operador binário associativo ou comutativo. O operando deve ser do tipo aritmético. O resultado é o valor do operando. Um operando de integral passa por uma promoção de integral. O tipo do resultado é o tipo do operando promovido.|
|**-**|O operador de negação aritmética produz o negativo (complemento de dois) do respectivo operando. O operando deve ser um valor de integral ou flutuante. Este operador executa as conversões aritméticas comuns.|
|`~`|O operador de complemento bit a bit (ou NOT bit a bit) produz o complemento bit a bit do respectivo operando. O operando deve ser do tipo integral. Este operador executa as conversões aritméticas comuns; o resultado tem o tipo do operando após a conversão.|
|**!**|O operador de negação lógica (NOT lógico) produz o valor 0 se o operando é verdadeiro (diferente de zero) e o valor 1 se o operando é falso (0). O resultado tem o tipo `int`. O operando deve ser um valor de ponteiro, integral ou flutuante.|

Operações aritméticas unárias em ponteiros não são válidas.

## <a name="examples"></a>Exemplos

Os exemplos a seguir ilustram os operadores aritméticos unários:

```
short x = 987;
    x = -x;
```

No exemplo acima, o novo valor de `x` é o negativo de 987, ou seja, -987.

```
unsigned short y = 0xAAAA;
    y = ~y;
```

Nesse exemplo, o novo valor atribuído a `y` é o complemento de um do valor sem sinal 0xAAAA, ou 0x5555.

```
if( !(x < y) )
```

Se `x` é maior ou igual a `y`, o resultado da expressão é 1 (verdadeiro). Se `x` é menor que `y`, o resultado é 0 (falso).

## <a name="see-also"></a>Consulte também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)