---
title: parâmetros
ms.date: 11/04/2016
helpviewer_keywords:
- arguments [C++], function
- function parameters
- parameters [C++]
- function arguments, vs. parameters
- parameters [C++], function
- functions [C], parameters
- function parameters, syntax
- ellipsis (...), parameters
- '... ellipsis'
ms.assetid: 8f2b8026-78b5-4e21-86a3-bf0f91f05689
ms.openlocfilehash: 57648747bbb50ffe46b199a03563757c331f088a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229565"
---
# <a name="parameters"></a>parâmetros

Os argumentos são nomes de valores transmitidos a uma função por uma chamada de função. Os parâmetros são os valores que a função espera receber. Em um protótipo de função, os parênteses posteriores ao nome da função contêm uma lista completa dos parâmetros da função e seus tipos. As declarações de parâmetro especificam os tipos, os tamanhos e os identificadores dos valores armazenados nos parâmetros.

## <a name="syntax"></a>Sintaxe

*`function-definition`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declaration-specifiers`*<sub>aceitar</sub> *`attribute-seq`* <sub>aceitar</sub> *`declarator`* *`declaration-list`* <sub>aceitar</sub>*`compound-statement`*

/\**`attribute-seq`* é específico da Microsoft\*/

*`declarator`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`pointer`*<sub>aceitar</sub>*`direct-declarator`*

*`direct-declarator`*:/ \* Um Declarador de função\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`direct-declarator`*  **`(`**  *`parameter-type-list`*  **`)`** /\*Declarador de novo estilo\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`direct-declarator`*  **`(`**  *`identifier-list`*<sub>opt</sub> **`)`**  / aceitar \* Declarador de estilo obsoleto\*/

*`parameter-type-list`*:/ \* A lista de parâmetros\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`parameter-list`* <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`parameter-list`* **`, ...`**

*`parameter-list`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`parameter-declaration`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`parameter-list`* **`,`**  *`parameter-declaration`*

*`parameter-declaration`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declaration-specifiers`* *`declarator`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declaration-specifiers`**`abstract-declarator`* <sub>aceitar</sub>

O *`parameter-type-list`* é uma sequência de declarações de parâmetro separadas por vírgulas. O formulário de cada parâmetro em uma lista de parâmetros tem esta aparência:

> **`register`**<sub>aceitar</sub> *`type-specifier`* *`declarator`* <sub>aceitar</sub>

Parâmetros de função declarados com o **`auto`** atributo geram erros. Os identificadores dos parâmetros são usados no corpo da função para fazer referência aos valores transmitidos à função. Você pode nomear os parâmetros em um protótipo, mas os nomes saem do escopo no final da declaração. Isso significa que os nomes de parâmetros podem ser atribuídos da mesma maneira ou de forma diferente na definição da função. Esses identificadores não podem ser redefinidos no bloco mais externo do corpo da função, mas podem ser redefinidos em blocos internos e aninhados como se a lista de parâmetros fosse um bloco delimitador.

Cada identificador em *`parameter-type-list`* deve ser precedido por seu especificador de tipo apropriado, conforme mostrado neste exemplo:

```C
void new( double x, double y, double z )
{
    /* Function body here */
}
```

Se pelo menos um parâmetro ocorrer na lista de parâmetros, a lista poderá terminar com uma vírgula seguida de três pontos ( **`, ...`** ). Essa construção, chamada "notação de reticências", indica um número variável de argumentos para a função. (Para obter mais informações, consulte [chamadas com um número variável de argumentos](../c-language/calls-with-a-variable-number-of-arguments.md).) No entanto, uma chamada para a função deve ter pelo menos tantos argumentos quantos houver parâmetros antes da última vírgula.

Se nenhum argumento for passado para a função, a lista de parâmetros será substituída pela palavra-chave **`void`** . Esse uso de **`void`** é diferente de seu uso como um especificador de tipo.

A ordem e o tipo de parâmetros, inclusive qualquer uso da notação de reticências, devem ser iguais em todas as declarações de função (se houver) e na definição da função. Os tipos de argumentos depois das conversões aritméticas comuns devem ter atribuições compatíveis com os tipos dos parâmetros correspondentes. (Consulte [conversões aritméticas usuais](../c-language/usual-arithmetic-conversions.md) para obter informações sobre conversões aritméticas.) Os argumentos após as reticências não são verificados. Um parâmetro pode ter qualquer tipo fundamental, de estrutura, união, ponteiro ou matriz.

O compilador executa as conversões aritméticas comuns independentemente em cada parâmetro e em cada argumento, se necessário. Após a conversão, nenhum parâmetro é menor que um **`int`** , e nenhum parâmetro tem **`float`** o tipo, a menos que o tipo de parâmetro seja explicitamente especificado como **`float`** no protótipo. Isso significa, por exemplo, que declarar um parâmetro como um **`char`** tem o mesmo efeito que declará-lo como um **`int`** .

## <a name="see-also"></a>Confira também

[Definições de função C](../c-language/c-function-definitions.md)
