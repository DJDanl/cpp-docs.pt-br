---
title: Operadores de atribuição C
ms.date: 06/14/2018
helpviewer_keywords:
- remainder assignment operator (%=)
- '&= operator'
- bitwise-AND assignment operator
- operators [C], assignment
- operators [C], shift
- ^= operator, assignment operators
- += operator
- '>>= operator'
- '|= operator'
- division assignment operator
- subtraction operator
- right shift operators
- subtraction operator, C assignment operators
- = operator, assignment operators
- '*= operator'
- '>> operator'
- '%= operator'
- assignment operators, C
- = operator
- assignment operators
- assignment conversions
- -= operator
- multiplication assignment operator (*=)
- shift operators, right
- /= operator
- operator >>=, C assignment operators
- <<= operator
ms.assetid: 11688dcb-c941-44e7-a636-3fc98e7dac40
ms.openlocfilehash: 5080f390d302840e9e7b349cf1c21ab618ae48db
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50657022"
---
# <a name="c-assignment-operators"></a>Operadores de atribuição C

Uma operação de atribuição atribui o valor do operando à direita para o local de armazenamento nomeado pelo operando à esquerda. Portanto, o operando à esquerda de uma operação de atribuição deve ser um valor l modificável. Após a atribuição, uma expressão de atribuição tem o valor do operando à esquerda mas não é um valor l.

## <a name="syntax"></a>Sintaxe

*assignment-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*conditional-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*unary-expression* *assignment-operator* *assignment-expression*

*assignment-operator*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**=** **\*=** **/=** **%=** **+=** **-=** **\<\<=** **>>=** **&=** **^=** **|=**

Os operadores de atribuição em C podem transformar e atribuir valores em uma única operação. O C fornece os seguintes operadores de atribuição:

|Operador|Operação executada|
|--------------|-------------------------|
|**=**|Atribuição simples|
|**&#42;=**|Atribuição de multiplicação|
|**/=**|Atribuição de divisão|
|**%=**|Atribuição restante|
|**+=**|Atribuição de adição|
|**-=**|Atribuição de subtração|
|**<\<=**|Atribuição de shift esquerda|
|**>>=**|Atribuição de shift direita|
|**&=**|Atribuição AND bit a bit|
|**^=**|Atribuição OR exclusivo bit a bit|
|**&#124;=**|Atribuição OR inclusivo bit a bit|

Na atribuição, o tipo do valor à direita é convertido no tipo do valor à esquerda, e o valor é armazenado no operando à esquerda depois que a atribuição ocorreu. O operando à esquerda não deve ser uma matriz, uma função ou uma constante. O caminho específico de conversão, que depende dos dois tipos, é descrito em detalhes em [Conversões de tipos](../c-language/type-conversions-c.md).

## <a name="see-also"></a>Consulte também

- [Operadores de Atribuição](../cpp/assignment-operators.md)