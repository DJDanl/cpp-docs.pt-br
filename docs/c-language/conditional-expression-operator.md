---
title: Operador de expressão condicional
ms.date: 11/04/2016
helpviewer_keywords:
- conditional operators
- operators [C++], conditional
- expressions [C++], conditional
ms.assetid: c4f1a5ca-0844-44a7-a384-eca584d4e3dd
ms.openlocfilehash: 03f9673da109151bd2146daf7539841f1cac07c6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217123"
---
# <a name="conditional-expression-operator"></a>Operador de expressão condicional

C tem um operador ternário: o operador de expressão condicional (**?:**).

## <a name="syntax"></a>Sintaxe

*expressão condicional*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*logical-OR-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão logical-OR*  **?**  *expression*  **:**  *expressão condicional*

A *logical-OR-expression* deve ter um tipo integral, de flutuação ou ponteiro. Ela é avaliada em termos de sua equivalência a 0. Um ponto de sequência vem após a *logical-OR-expression*. A avaliação dos operandos acontece da seguinte maneira:

- Se a *logical-OR-expression* não for igual a 0, a *expression* será avaliada. O resultado da avaliação da expressão é determinado pela *expression* não terminal. (Isso significa que a *expression* será avaliada apenas se a *logical-OR-expression* for verdadeira.)

- Se a *logical-OR-expression* for igual a 0, a *conditional-expression* será avaliada. O resultado da expressão será o valor da *conditional-expression*. (Isso significa que a *conditional-expression* será avaliada apenas se a *logical-OR-expression* for falsa.)

Observe que apenas a *expression* ou a *conditional-expression* é avaliada, mas não ambas.

O tipo de resultado de uma operação condicional depende do tipo do operando da *expression* ou *conditional-expression*, da seguinte maneira:

- Se a *expression* ou *conditional-expression* tiver o tipo integral ou flutuante (seus tipos podem ser diferentes), o operador executa conversões aritméticas comuns. O tipo do resultado é o tipo dos operandos após conversão.

- Se a *expression* e a *conditional-expression* tiverem a mesma estrutura, união ou tipo de ponteiro, o tipo de resultado é a mesma estrutura, união ou tipo de ponteiro.

- Se ambos os operandos tiverem tipo **`void`** , o resultado terá tipo **`void`** .

- Se qualquer operando for um ponteiro para um objeto de qualquer tipo, e o outro operando for um ponteiro para **`void`** , o ponteiro para o objeto será convertido em um ponteiro para **`void`** e o resultado será um ponteiro para **`void`** .

- Se a *expression* ou *conditional-expression* for um ponteiro e o outro operando for uma expressão constante com o valor 0, o tipo de resultado será o tipo de ponteiro.

Na comparação de tipos para ponteiros, qualquer qualificador de tipo ( **`const`** ou **`volatile`** ) no tipo ao qual os pontos apontadores são insignificantes, mas o tipo de resultado herda os qualificadores de ambos os componentes do condicional.

## <a name="examples"></a>Exemplos

Os exemplos a seguir mostram o uso do operador condicional:

```
j = ( i < 0 ) ? ( -i ) : ( i );
```

Este exemplo atribui o valor absoluto de `i` a `j`. Se `i` for menor que 0, `-i` é atribuído a `j`. Se `i` for maior ou igual a 0, `i` é atribuído a `j`.

```cpp
void f1( void );
void f2( void );
int x;
int y;
    .
    .
    .
( x == y ) ? ( f1() ) : ( f2() );
```

Neste exemplo, duas funções, `f1` e `f2`, e duas variáveis, `x` e `y`, são declaradas. Posteriormente no programa, se as duas variáveis tiverem o mesmo valor, a função `f1` será chamada. Caso contrário, `f2` é chamada.

## <a name="see-also"></a>Confira também

[Operador condicional: ? :](../cpp/conditional-operator-q.md)
