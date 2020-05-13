---
title: Operadores lógicos C
ms.date: 06/14/2018
helpviewer_keywords:
- logical operators, expression sequence points
- logical operators, C
- logical AND operator
- '|| operator'
- operators [C], logical
- short-circuit evaluation
- '&& operator'
- logical OR operator
ms.assetid: c0a4e766-ad56-4300-bf76-b28dc0e19b43
ms.openlocfilehash: 5df0c0f16bdf298c47a6a0699ec10c7392ab84ca
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62326580"
---
# <a name="c-logical-operators"></a>Operadores lógicos C

Os operadores lógicos executam operações lógicas-AND (**&&**) e**||** or ().

## <a name="syntax"></a>Sintaxe

*expressão and lógica*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*inclusivo-ou-expressão*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de lógica e de expressão*  **&&**  *inclusiva*

*expressão or lógica*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão AND lógica*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;expressão or *lógica* **&#124;&#124;** *lógica e expressão*    

## <a name="remarks"></a>Comentários

Os operadores lógicos não executam as conversões aritméticas comuns. Em vez disso, eles avaliam cada operando em termos de sua equivalência a 0. O resultado de uma operação lógica é 0 ou 1. O tipo do resultado é **int**.

Os operadores lógicos de C são descritos abaixo:

|Operador|Descrição|
|--------------|-----------------|
|**&&**|O operador lógico AND produz o valor 1 se os dois operandos tiverem valores diferentes de zero. Se qualquer um dos operandos for igual a 0, o resultado será 0. Se o primeiro operando de uma operação AND lógica for igual a 0, o segundo operando não será avaliado.|
|**&#124;&#124;**|O operador OR lógico executa uma operação OR inclusiva em seus operandos. O resultado é 0 se os dois operandos tiverem valores 0. Se qualquer um dos operando tiver um valor diferente de zero, o resultado será 1. Se o primeiro operando de uma operação OR lógica tiver um valor diferente de 0, o segundo operando não será avaliado.|

Os operandos de expressões AND lógica e OR lógica são avaliados da esquerda para a direita. Se o valor do primeiro operando for suficiente para determinar o resultado da operação, o segundo operando não será avaliado. Isso é chamado “avaliação pelo caminho mais curto”. Há um ponto de sequência depois do primeiro operando. Consulte [Pontos de sequência](../c-language/c-sequence-points.md) para obter mais informações.

## <a name="examples"></a>Exemplos

Os exemplos a seguir ilustram os operadores lógicos:

```C
int w, x, y, z;

if ( x < y && y < z )
    printf( "x is less than z\n" );
```

Neste exemplo, a função **printf** é chamada para imprimir uma mensagem se `x` for menor que `y` e `y` for menor que `z`. Se `x` for maior que `y`, o segundo operando (`y < z`) não será avaliado e nada será impresso. Observe que isso pode causar problemas nos casos em que o segundo operando tiver efeitos colaterais que sejam usados por algum outro motivo.

```C
printf( "%d" , (x == w || x == y || x == z) );
```

Nesse exemplo, se `x` for igual a `w`, `y` ou `z`, o segundo argumento para a função **printf** é avaliado como verdadeiro e o valor 1 é impresso. Caso contrário, será avaliado como false, e o valor 0 será impresso. Assim que uma das condições for avaliada como true, a avaliação é encerrada.

## <a name="see-also"></a>Confira também

- [Operador AND lógico: &&](../cpp/logical-and-operator-amp-amp.md)
- [Operador OR lógico: &#124;&#124;](../cpp/logical-or-operator-pipe-pipe.md)
