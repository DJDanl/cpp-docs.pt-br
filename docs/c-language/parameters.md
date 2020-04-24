---
title: Parâmetros
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
ms.openlocfilehash: 78ad91ea86d81a3b6d888335ba7b78399a1d2aea
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82032064"
---
# <a name="parameters"></a>parâmetros

Os argumentos são nomes de valores transmitidos a uma função por uma chamada de função. Os parâmetros são os valores que a função espera receber. Em um protótipo de função, os parênteses posteriores ao nome da função contêm uma lista completa dos parâmetros da função e seus tipos. As declarações de parâmetro especificam os tipos, os tamanhos e os identificadores dos valores armazenados nos parâmetros.

## <a name="syntax"></a>Sintaxe

*definição de função:*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers*<sub>opt</sub> *attribute-seq*<sub>opt</sub> *declarator* *declaration-list*<sub>opt</sub> *compound-statement*

/\**atributo-seq* é específico da Microsoft\*/

*declarador:*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pointer*<sub>opt</sub> *direct-declarator*

*declarador direto*:\* / Um declarador de função\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declarador direto***(lista***de parâmetros- tipo)***)**  / \* Declarador de novo estilo      \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declarador direto*<sub>(opção</sub> de lista de **(***identificadores* **)**  / \* Declarador estilo obsoleto    \*/

*tipo de parâmetro:*/\* A lista de parâmetros\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*lista de parâmetros* <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*lista de parâmetros,* **...**

*lista de parâmetros:*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parâmetro-declaração*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*lista de parâmetros,* **,***declaração de parâmetros*  

*parameter-declaration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers* *declarator*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers* *abstract-declarator*<sub>opt</sub>

A *parameter-type-list* é uma sequência de declarações de parâmetro separadas por vírgulas. O formulário de cada parâmetro em uma lista de parâmetros tem esta aparência:

```C
[register]  type-specifier [declarator]
```

Os parâmetros de função declarados com o atributo **auto** geram erros. Os identificadores dos parâmetros são usados no corpo da função para fazer referência aos valores transmitidos à função. Você pode nomear os parâmetros em um protótipo, mas os nomes saem do escopo no final da declaração. Portanto, os nomes dos parâmetros podem ser atribuídos da mesma maneira ou de maneira diferente na definição da função. Esses identificadores não podem ser redefinidos no bloco externo do corpo da função, mas podem ser redefinidos em blocos internos e aninhados, como se a lista de parâmetros fosse um bloco delimitador.

Cada identificador em *parameter-type-list* deve ser precedido pelo especificador de tipo apropriado, conforme mostrado neste exemplo:

```C
void new( double x, double y, double z )
{
    /* Function body here */
}
```

Se ocorrer pelo menos um parâmetro na lista de parâmetros, a lista pode terminar com uma tura seguida por três períodos (**... ).** Essa construção, chamada de "notação ellipsis", indica um número variável de argumentos para a função. (Consulte [Chamadas com um número variável de argumentos](../c-language/calls-with-a-variable-number-of-arguments.md) para obter mais informações.) No entanto, uma chamada para a função deve ter pelo menos tantos argumentos quanto há parâmetros antes da última comuma.

Se nenhum argumento for transmitido à função, a lista de parâmetros será substituída pela palavra-chave `void`. Esse uso de `void` é diferente do seu uso como um especificador de tipo.

A ordem e o tipo de parâmetros, inclusive qualquer uso da notação de reticências, devem ser iguais em todas as declarações de função (se houver) e na definição da função. Os tipos de argumentos depois das conversões aritméticas comuns devem ter atribuições compatíveis com os tipos dos parâmetros correspondentes. (Consulte [Conversões Aritméticas Usuais](../c-language/usual-arithmetic-conversions.md) para obter informações sobre conversões aritméticas.) Os argumentos que seguem as elipses não são verificados. Um parâmetro pode ter qualquer tipo fundamental, de estrutura, união, ponteiro ou matriz.

O compilador executa as conversões aritméticas comuns independentemente em cada parâmetro e em cada argumento, se necessário. Após a conversão, nenhum parâmetro é menor que `int` e nenhum parâmetro tem o tipo **float**, a menos que o tipo de parâmetro seja especificado explicitamente como **float** no protótipo. Isso significa, por exemplo, que declarar um parâmetro como `char` tem o mesmo efeito que declará-lo o como `int`.

## <a name="see-also"></a>Confira também

[Definições de função C](../c-language/c-function-definitions.md)
