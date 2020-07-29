---
title: Operadores de incremento e de decremento pré-fixados
ms.date: 11/04/2016
helpviewer_keywords:
- increment operators, types of
- decrement operators, syntax
- decrement operators
ms.assetid: 9a441bb9-d94a-4b6a-9db2-0d0d76bc480d
ms.openlocfilehash: dbbace9780ab96891ceb85f885335e42c577fda1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211717"
---
# <a name="prefix-increment-and-decrement-operators"></a>Operadores de incremento e de decremento pré-fixados

Os operadores unários ( `++` e **--** ) são chamados de incrementos de "prefixo" ou diminuição de operadores quando os operadores de aumento ou diminuição aparecem antes do operando. O incremento e a diminuição de pós-fixação têm precedência maior que o incremento e a diminuição de prefixo. O operando deve ter um tipo integral, flutuante ou de ponteiro e deve ser uma expressão l-Value modificável (uma expressão sem o **`const`** atributo). O resultado é um l-value.

Quando o operador aparecer antes de seu operando, o operando será incrementado ou diminuído, e seu novo valor será o resultado da expressão.

Um operando tipo integral ou flutuante é incrementado ou decrementado pelo valor inteiro 1. O tipo do resultado é igual ao tipo do operando. Um operando do tipo ponteiro é incrementado ou decrementado pelo tamanho do objeto pertinente. Um ponteiro incrementado aponta para o próximo objeto;um ponteiro decrementado aponta para o objeto anterior.

## <a name="example"></a>Exemplo

Este exemplo ilustra o operador unário de diminuição de prefixo:

```
if( line[--i] != '\n' )
    return;
```

Neste exemplo, a variável `i` é diminuída antes de ser usada como um subscrito para `line`.

## <a name="see-also"></a>Confira também

[Operadores unários C](../c-language/c-unary-operators.md)
