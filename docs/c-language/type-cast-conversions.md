---
title: Conversões de conversão de tipo
ms.date: 11/04/2016
helpviewer_keywords:
- data type conversion [C++], type-cast conversions
- conversions [C++], type-cast
- type casts
- explicit type conversions
- type casts [C++], about type-cast conversion
- type-cast conversions [C++]
ms.assetid: 57ab5902-f12f-4326-a2f6-6282f1d4025a
ms.openlocfilehash: cc2b6d87d6fedf8d36373c901cdb6a6ba8b5f0e7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231449"
---
# <a name="type-cast-conversions"></a>Conversões de conversão de tipo

Você pode usar conversões de tipos em estilo "cast" para converter tipos explicitamente.

**Sintaxe**

*expressão CAST*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão unário*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão CAST* **(***nome-do-tipo***)**      

*nome do tipo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*specifier-qualifier-list* *abstract-declarator*<sub>opt</sub>

O *type-name* é um tipo e *cast-expression* é um valor para ser convertido para esse tipo. Uma expressão com uma conversão de tipo ("cast") não é um l- value. A *cast-expression* é convertida como se tivesse sido atribuída a uma variável do tipo *type-name*. As regras de conversão para atribuições (descritas em [Conversões de atribuição](../c-language/assignment-conversions.md)) também se aplicam às conversões de tipos. A tabela a seguir mostra os tipos que podem ser convertidos em qualquer tipo indicado.

### <a name="legal-type-casts"></a>Conversões de tipos válidas

|Tipos de destino|Possíveis fontes|
|-----------------------|-----------------------|
|Tipos integrais|Qualquer tipo de inteiro ou tipo de ponto flutuante, ou ponteiro para um objeto|
|Ponto flutuante|Qualquer tipo aritmético|
|Um ponteiro para um objeto ou ( **`void`** <strong>\*</strong> )|Qualquer tipo inteiro, ( **`void`** <strong>\*</strong> ), um ponteiro para um objeto ou um ponteiro de função|
|Ponteiro de função|Qualquer tipo integral, um ponteiro para um objeto ou um ponteiro de função|
|Uma estrutura, união ou matriz|Nenhum|
|Tipo void|Qualquer tipo|

Qualquer identificador pode ser convertido para o **`void`** tipo. No entanto, se o tipo especificado em uma expressão de conversão de tipo não for **`void`** , o identificador que está sendo convertido para esse tipo não pode ser uma **`void`** expressão. Qualquer expressão pode ser convertida **`void`** , mas uma expressão do tipo **`void`** não pode ser convertida em nenhum outro tipo. Por exemplo, uma função com **`void`** tipo de retorno não pode ter sua conversão de retorno para outro tipo.

Observe que uma **`void`** <strong>\*</strong> expressão tem um ponteiro de tipo para **`void`** , não tipo **`void`** . Se um objeto for convertido para **`void`** o tipo, a expressão resultante não poderá ser atribuída a nenhum item. Do mesmo modo, um objeto de conversão de tipo não é um l-value aceitável; portanto, nenhuma atribuição pode ser feita a um objeto de conversão de tipo.

**Específico da Microsoft**

Uma conversão de tipo pode ser uma expressão l-value, desde que o tamanho do identificador não se altere. Para obter informações sobre expressões l-value, consulte [Expressões L-Value e R-Value](../c-language/l-value-and-r-value-expressions.md).

**FINAL específico da Microsoft**

Você pode converter uma expressão para tipo **`void`** com uma conversão, mas a expressão resultante só pode ser usada quando um valor não é necessário. Um ponteiro de objeto convertido para **`void`** <strong>\*</strong> e retornado para o tipo original retornará ao seu valor original.

## <a name="see-also"></a>Confira também

[Conversões de tipo](../c-language/type-conversions-c.md)
