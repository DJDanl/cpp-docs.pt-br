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
ms.openlocfilehash: e8ada96daaec249a05882aceae9b7d9e86b92065
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168793"
---
# <a name="c-assignment-operators"></a>Operadores de atribuição C

Uma operação de atribuição atribui o valor do operando à direita para o local de armazenamento nomeado pelo operando à esquerda. Portanto, o operando à esquerda de uma operação de atribuição deve ser um valor l modificável. Após a atribuição, uma expressão de atribuição tem o valor do operando à esquerda mas não é um valor l.

## <a name="syntax"></a>Sintaxe

*assignment-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*conditional-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;atribuição de *expressão unário* - *expressão de atribuição* de *operador*

*assignment-operator*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **=** **\*=** **/=** **%=** **+=** **-=** **\<\<=** **>>=** **&=^=** **|=** **|=**

Os operadores de atribuição em C podem transformar e atribuir valores em uma única operação. O C fornece os seguintes operadores de atribuição:

|Operator|Operação executada|
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

## <a name="see-also"></a>Veja também

- [Operadores de Atribuição](../cpp/assignment-operators.md)
