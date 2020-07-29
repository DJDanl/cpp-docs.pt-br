---
title: Operadores C
ms.date: 06/14/2018
helpviewer_keywords:
- ternary operators
- operators [C]
- symbols, operators
- binary operators
- associativity of operators
- binary data, binary expressions
ms.assetid: 13bc4c8e-2dc9-4b23-9f3a-25064e8777ed
ms.openlocfilehash: 7868073f4932e4b77329e6df4a3de374bcf41ec9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227966"
---
# <a name="c-operators"></a>Operadores C

Os operadores C são um subconjunto de [operadores embutidos de C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md).

Há três tipos de operadores. Uma expressão unário consiste em um operador unário que foi anexado a um operando ou à **`sizeof`** palavra-chave seguida por uma expressão. A expressão pode ser o nome de uma variável ou uma expressão de conversão. Se a expressão for uma expressão de conversão, ela deverá ser colocada entre parênteses. Uma expressão binária consiste em dois operandos unidos por um operador binário. Uma expressão ternária consiste em três operandos unidos pelo operador de expressão condicional.

O C inclui os seguintes operadores unários:

|Símbolo|Nome|
|------------|----------|
|**-** **~** **!**|Operadores de negação e de complemento|
|**&#42;****&**|Operadores de indireção e address-of|
|**`sizeof`**|Operador de tamanho|
|**+**|Operador de adição de unário|
|**++** **--**|Operadores unários de incremento e de decremento|

Operadores binários associados da esquerda para a direita. O C fornece os seguintes operadores binários:

|Símbolo|Nome|
|------------|----------|
|**&#42;** **/****%**|Operadores de multiplicação|
|**+** **-**|Operadores aditivos|
|**\<\<** **>>**|Operadores shift|
|**\<** **>****\<=** **>=** **==** **!=**|Operadores relacionais|
|**&****&#124;****^**|Operadores bit a bit|
|**&&****&#124;&#124;**|Operadores lógicos|
|**,**|Operador de avaliação sequencial|

O operador de base (**:>**), com suporte em versões anteriores do compilador de 16 bits do Microsoft C, é descrito em [Resumo da sintaxe da linguagem C](../c-language/c-language-syntax-summary.md).

O operador de expressão condicional tem uma precedência mais baixa do que as expressões binárias e difere delas por ser associado à direita.

As expressões com operadores também incluem as expressões de atribuição, que usam operadores de atribuição unários ou binários. Os operadores de atribuição unários são os operadores Increment ( **++** ) e Decrement ( **--** ); os operadores de atribuição Binary são o operador de atribuição simples ( **=** ) e os operadores de atribuição composta. Cada operador de atribuição composta é uma combinação de outro operador binário com o operador de atribuição simples.

## <a name="see-also"></a>Confira também

- [Expressões e atribuições](../c-language/expressions-and-assignments.md)
