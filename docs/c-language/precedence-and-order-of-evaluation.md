---
title: Precedência e ordem da avaliação
ms.date: 07/11/2019
helpviewer_keywords:
- associativity of operators [C++]
- precedence [C++], operators
- data binding [C++], operator precedence
- operators [C++], precedence
ms.assetid: 201f7864-0c51-4c55-9d6f-39c5d013bcb0
ms.openlocfilehash: 327a5a5344f17f1d84e0cebc1371d56426c95deb
ms.sourcegitcommit: 0e3da5cea44437c132b5c2ea522bd229ea000a10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/12/2019
ms.locfileid: "67861071"
---
# <a name="precedence-and-order-of-evaluation"></a>Precedência e ordem da avaliação

A precedência e a associatividade dos operadores C afetam o agrupamento e a avaliação dos operandos nas expressões. A precedência de um operador é significante somente quando outros operadores com precedência maior ou menor estão presentes. As expressões com operadores de maior precedência são avaliadas primeiro. A precedência também pode ser descrita pela palavra “associação”. Os operadores com maior precedência são ditos ter uma associação mais próxima.

A tabela a seguir resume a precedência e a associatividade (a ordem em que os operandos são avaliados) dos operadores C, listando-os em ordem decrescente de precedência. Onde vários operadores aparecem juntos, eles têm a mesma precedência e são avaliados de acordo com sua associatividade. Os operadores na tabela são descritos nas seções que começam com [Operadores de sufixo](../c-language/postfix-operators.md). O restante desta seção fornece informações gerais sobre a precedência e associatividade.

## <a name="precedence-and-associativity-of-c-operators"></a>Precedência e associatividade de operadores C

| Símbolo <sup>1</sup> | Tipo de operação | Capacidade de associação |
|-------------|-----------------------|-------------------|
| `[` `]` `(` `)` `.` `->`<br/>`++``--` (sufixo) | Expression | Da esquerda para a direita |
| **sizeof** `&` `*` `+` `-` `~` `!`<br/>`++``--` (prefixo) | Unário | Da direita para a esquerda |
| *typecasts* | Unário | Da direita para a esquerda |
| `*` `/` `%` | Multiplicativo | Da esquerda para a direita |
| `+` `-` | Aditiva | Da esquerda para a direita |
| `<<` `>>` | Deslocamento bit a bit | Da esquerda para a direita |
| `<` `>` `<=` `>=` | Relacional | Da esquerda para a direita |
| `==` `!=` | Igualitário | Da esquerda para a direita |
| `&` | Bitwise-AND | Da esquerda para a direita |
| `^` | Bitwise-exclusive-OR | Da esquerda para a direita |
| `|` | Bitwise-inclusive-OR | Da esquerda para a direita |
| `&&` | Logical-AND | Da esquerda para a direita |
| `||` | Logical-OR | Da esquerda para a direita |
| `? :` | Expressão condicional | Da direita para a esquerda |
| `=` `*=` `/=` `%=`<br/>`+=` `-=` `<<=` `>>=` `&=`<br/>`^=` `|=` | Atribuição simples e composta <sup>2</sup> | Da direita para a esquerda |
| `,` | Avaliação sequencial | Da esquerda para a direita |

<sup>1</sup> Os operadores são listados em ordem decrescente de precedência. Quando vários operadores aparecem na mesma linha ou em um grupo, eles têm a mesma precedência.

<sup>2</sup> Todos os operadores de atribuição simples e composta têm a mesma precedência.

Uma expressão pode conter vários operadores com a mesma precedência. Quando vários desses operadores aparecem no mesmo nível em uma expressão, a avaliação procede de acordo com a associatividade do operador, da direita para a esquerda ou da esquerda para a direita. A direção da avaliação não afeta os resultados das expressões que incluem mais de um operador de multiplicação (`*`), adição (`+`) ou binário bit a bit (`&`, `|` ou `^`) no mesmo nível. A ordem das operações não é definida pela linguagem. O compilador é livre para avaliar essas expressões em qualquer ordem, se ele puder garantir um resultado consistente.

Somente os operadores de avaliação sequencial (`,`), AND lógico (`&&`), OR lógico (`||`), de expressão condicional (`? :`) e de chamada de função constituem pontos de sequência e, portanto, garantem uma ordem específica de avaliação de seus operandos. O operador da chamada de função é o conjunto de parênteses depois do identificador da função. O operador de avaliação sequencial (`,`) é garantido para avaliar seus operandos da esquerda para a direita. (O operador de vírgula em uma chamada de função não é o mesmo que o operador de avaliação sequencial e não fornece nenhuma garantia.) Para obter mais informações, consulte [pontos de sequência](c-sequence-points.md).

Os operadores lógicos também garantem a avaliação de seus operandos da esquerda para a direita. No entanto, eles avaliam o menor número de operandos necessários para determinar o resultado da expressão. Isso é chamado de avaliação de" curto-circuito". Assim, alguns operandos da expressão não podem ser avaliados. Por exemplo, na expressão

`x && y++`

o segundo operando, `y++`, será avaliado somente se `x` for true (diferente de zero). Assim, `y` não será incrementado se `x` for false (0).

## <a name="examples"></a>Exemplos

A lista a seguir mostra como o compilador associa automaticamente várias expressões de exemplo:

| Expression | Associação automática |
|----------------|-----------------------|
| `a & b || c` | `(a & b) || c` |
| `a = b || c` | `a = (b || c)` |
| `q && r || s--` | `(q && r) || s--` |

Na primeira expressão, o operador AND bit a bit (`&`) tem uma maior precedência que o operador OR lógico (`||`), então `a & b` forma o primeiro operando da operação OR lógica.

Na segunda expressão, o operador OR lógico (`||`) tem maior precedência que o operador de atribuição simples (`=`), então `b || c` é agrupado como o operando à direita na atribuição. Observe que o valor atribuído a `a` é 0 ou 1.

A terceira expressão mostra uma expressão corretamente formada que pode gerar um resultado inesperado. O operador AND lógico (`&&`) tem maior precedência que o operador OR lógico (`||`), então `q && r` é agrupado como um operando. Como os operadores lógicos asseguram a avaliação dos operandos da esquerda para a direita, `q && r` é avaliado antes de `s--`. No entanto, se `q && r` for avaliado como um valor diferente de zero, `s--` não será avaliado e `s` não será diminuído. Se não diminuir `s` for causar um problema em seu programa, `s--` deverá aparecer como o primeiro operando da expressão ou `s` deverá ser diminuído em uma operação separada.

A expressão a seguir é ilegal e gera uma mensagem de diagnóstico no tempo de compilação:

| Expressão ilegal | Agrupamento padrão |
|------------------------|----------------------|
| `p == 0 ? p += 1: p += 2` | `( p == 0 ? p += 1 : p ) += 2` |

Nessa expressão, o operador de igualdade (`==`) tem a precedência mais alta, então `p == 0` é agrupado como um operando. O operador de expressão condicional (`? :`) tem a próxima precedência mais alta. Seu primeiro operando é `p == 0`, e o segundo operando é `p += 1`. No entanto, o último operando do operador de expressão condicional é considerado `p` em vez de `p += 2`, já que essa ocorrência de `p` se associa ainda mais ao operador de expressão condicional do que ao operador de atribuição composta. Um erro de sintaxe ocorre porque `+= 2` não tem um operando à esquerda. Você deve usar parênteses para evitar erros desse tipo e gerar um código mais legível. Por exemplo, você pode usar parênteses como mostrado abaixo para corrigir e esclarecer o exemplo anterior:

`( p == 0 ) ? ( p += 1 ) : ( p += 2 )`

## <a name="see-also"></a>Confira também

[Operadores de C](c-operators.md)
