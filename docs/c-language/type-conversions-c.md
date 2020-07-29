---
title: Conversões de tipo (C)
ms.date: 11/04/2016
helpviewer_keywords:
- conversions, type
- type conversion
- converting types
- integral promotions
- type casts, when performed
ms.assetid: d130ee7c-03c3-48f4-af7b-1fdba0d3b086
ms.openlocfilehash: 7d7c55c15a8f3e2a53e350da947cf524ae064a09
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231423"
---
# <a name="type-conversions-c"></a>Conversões de tipo (C)

As conversões de tipos dependem do operador especificado e do tipo de operando ou dos operadores. As conversões de tipo são executadas nos seguintes casos:

- Quando um valor de um tipo é atribuído a uma variável de um tipo diferente ou um operador converte o tipo do seu operando ou operandos antes de executar uma operação

- Quando um valor de um tipo é explicitamente convertido em um tipo diferente

- Quando um valor é passado como um argumento para uma função ou quando um tipo é retornado de uma função

Um caractere, inteiro curto ou campo de bit de inteiro, todos assinados ou não, ou um objeto de tipo de enumeração, podem ser usados em uma expressão sempre que um inteiro puder ser usado. Se um **`int`** puder representar todos os valores do tipo original, o valor será convertido em **`int`** ; caso contrário, será convertido em **`unsigned int`** . Esse processo é chamado de “promoção de integral”. As promoções de integral preservam os valores. Ou seja, o valor após a promoção tem a garantia de ser o mesmo que antes de promoção. Consulte [Conversões aritméticas usuais](../c-language/usual-arithmetic-conversions.md) para obter mais informações.

## <a name="see-also"></a>Confira também

[Expressões e atribuições](../c-language/expressions-and-assignments.md)
