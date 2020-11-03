---
title: Operadores de atribuição C
description: Os operadores de atribuição de linguagem C padrão, sua sintaxe e significado.
ms.date: 10/30/2020
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
ms.openlocfilehash: 460e18772689de0d28fcfda3295a49b2f8a3c0d7
ms.sourcegitcommit: 4abc6c4c9694f91685cfd77940987e29a51e3143
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/03/2020
ms.locfileid: "93238506"
---
# <a name="c-assignment-operators"></a>Operadores de atribuição C

Uma operação de atribuição atribui o valor do operando à direita para o local de armazenamento nomeado pelo operando à esquerda. Portanto, o operando à esquerda de uma operação de atribuição deve ser um valor l modificável. Após a atribuição, uma expressão de atribuição tem o valor do operando à esquerda mas não é um valor l.

## <a name="syntax"></a>Syntax

*`assignment-expression`* :\
&emsp;*`conditional-expression`*\
&emsp;*`unary-expression`* *`assignment-operator`* *`assignment-expression`*

*`assignment-operator`* : um dos<br/>
&emsp;**`=`** **`*=`** **`/=`** **`%=`** **`+=`** **`-=`** **`<<=`** **`>>=`** **`&=`** **`^=`** **`|=`**

Os operadores de atribuição em C podem transformar e atribuir valores em uma única operação. O C fornece os seguintes operadores de atribuição:

|Operador|Operação executada|
|--------------|-------------------------|
|**`=`**|Atribuição simples|
|**`*=`**|Atribuição de multiplicação|
|**`/=`**|Atribuição de divisão|
|**`%=`**|Atribuição restante|
|**`+=`**|Atribuição de adição|
|**`-=`**|Atribuição de subtração|
|**`<<=`**|Atribuição de shift esquerda|
|**`>>=`**|Atribuição de shift direita|
|**`&=`**|Atribuição AND bit a bit|
|**`^=`**|Atribuição OR exclusivo bit a bit|
|**`|=`**|Atribuição OR inclusivo bit a bit|

Na atribuição, o tipo do valor à direita é convertido no tipo do valor à esquerda, e o valor é armazenado no operando à esquerda depois que a atribuição ocorreu. O operando à esquerda não deve ser uma matriz, uma função ou uma constante. O caminho específico de conversão, que depende dos dois tipos, é descrito em detalhes em [Conversões de tipos](../c-language/type-conversions-c.md).

## <a name="see-also"></a>Confira também

- [Operadores de atribuição](../cpp/assignment-operators.md)
