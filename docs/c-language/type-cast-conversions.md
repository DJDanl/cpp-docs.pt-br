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
ms.openlocfilehash: d54e4c15f84ccecad629d48341e5d3ae26d8cecf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62344935"
---
# <a name="type-cast-conversions"></a>Conversões de conversão de tipo

Você pode usar conversões de tipos em estilo "cast" para converter tipos explicitamente.

**Sintaxe**

*expressão CAST*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*unary expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão CAST* **(***nome-do-tipo***)**      

*nome do tipo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*specifier-qualifier-list* *abstract-declarator*<sub>opt</sub>

O *type-name* é um tipo e *cast-expression* é um valor para ser convertido para esse tipo. Uma expressão com uma conversão de tipo ("cast") não é um l- value. A *cast-expression* é convertida como se tivesse sido atribuída a uma variável do tipo *type-name*. As regras de conversão para atribuições (descritas em [Conversões de atribuição](../c-language/assignment-conversions.md)) também se aplicam às conversões de tipos. A tabela a seguir mostra os tipos que podem ser convertidos em qualquer tipo indicado.

### <a name="legal-type-casts"></a>Conversões de tipos válidas

|Tipos de destino|Possíveis fontes|
|-----------------------|-----------------------|
|Tipos integrais|Qualquer tipo de inteiro ou tipo de ponto flutuante, ou ponteiro para um objeto|
|Ponto flutuante|Qualquer tipo aritmético|
|Um ponteiro para um objeto ou (**void** <strong>\*</strong>)|Qualquer tipo de inteiro, (**void** <strong>\*</strong>), um ponteiro para um objeto ou um ponteiro de função|
|Ponteiro de função|Qualquer tipo integral, um ponteiro para um objeto ou um ponteiro de função|
|Uma estrutura, união ou matriz|Nenhum|
|Tipo void|Qualquer tipo|

Qualquer identificador pode ser convertido no tipo `void`. No entanto, se o tipo especificado em uma expressão de conversão de tipo não é `void`, o identificador que está sendo convertido nesse tipo não pode ser uma expressão `void`. Qualquer expressão pode ser convertida em `void`, mas uma expressão do tipo `void` não pode ser convertida em nenhum outro tipo. Por exemplo, uma função com o tipo de retorno `void` não pode ter seu retorno convertido em outro tipo.

Observe que uma expressão **void** <strong>\*</strong> tem um ponteiro de tipo `void`para, não `void`tipo. Se um objeto é convertido no tipo `void`, a expressão resultante não pode ser atribuída a nenhum item. Do mesmo modo, um objeto de conversão de tipo não é um l-value aceitável; portanto, nenhuma atribuição pode ser feita a um objeto de conversão de tipo.

**Específico da Microsoft**

Uma conversão de tipo pode ser uma expressão l-value, desde que o tamanho do identificador não se altere. Para obter informações sobre expressões l-value, consulte [Expressões L-Value e R-Value](../c-language/l-value-and-r-value-expressions.md).

**FINAL específico da Microsoft**

Você pode converter uma expressão no tipo `void` com uma conversão em estilo "cast", mas a expressão resultante só pode ser usada onde um valor não seja necessário. Um ponteiro de objeto convertido para **void** <strong>\*</strong> e de volta para o tipo original retornará ao seu valor original.

## <a name="see-also"></a>Confira também

[Conversões de tipo](../c-language/type-conversions-c.md)
