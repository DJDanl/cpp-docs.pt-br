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
- ellipses (...), parameters
- '... ellipsis'
ms.assetid: 8f2b8026-78b5-4e21-86a3-bf0f91f05689
ms.openlocfilehash: 2b4b549ae6059cddf3ab868950cda215fb043d8e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50506932"
---
# <a name="parameters"></a>Parâmetros

Os argumentos são nomes de valores transmitidos a uma função por uma chamada de função. Os parâmetros são os valores que a função espera receber. Em um protótipo de função, os parênteses posteriores ao nome da função contêm uma lista completa dos parâmetros da função e seus tipos. As declarações de parâmetro especificam os tipos, os tamanhos e os identificadores dos valores armazenados nos parâmetros.

## <a name="syntax"></a>Sintaxe

*function-definition*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers*<sub>opt</sub> *attribute-seq*<sub>opt</sub> *declarator* *declaration-list*<sub>opt</sub> *compound-statement*

/\* *attribute-seq* é Específico da Microsoft \*/

*declarator*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pointer*<sub>opt</sub> *direct-declarator*

*direct-declarator*: /\* Um declarador de função \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*direct-declarator*  **(**  *parameter-type-list*  **)** /\* Declarador de novo estilo \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*direct-declarator*  **(**  *identifier-list*<sub>opt</sub> **)** /\* Declarador de estilo obsoleto \*/

*parameter-type-list*: /\* A lista de parâmetros \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parameter-list* <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parameter-list* **, ...**

*parameter-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parameter-declaration*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parameter-list* **,**  *parameter-declaration*

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

Se pelo menos um parâmetro ocorrer na lista de parâmetros, a lista poderá terminar com uma vírgula seguida de três pontos (**, ...**). Essa construção, chamada "notação de reticências", indica um número variável de argumentos para a função. (Consulte [Chamadas com um número variável de argumentos](../c-language/calls-with-a-variable-number-of-arguments.md) para obter mais informações.) No entanto, uma chamada para a função deve ter pelo menos o mesmo número de argumentos que os parâmetros antes da última vírgula.

Se nenhum argumento for transmitido à função, a lista de parâmetros será substituída pela palavra-chave `void`. Esse uso de `void` é diferente do seu uso como um especificador de tipo.

A ordem e o tipo de parâmetros, inclusive qualquer uso da notação de reticências, devem ser iguais em todas as declarações de função (se houver) e na definição da função. Os tipos de argumentos depois das conversões aritméticas comuns devem ter atribuições compatíveis com os tipos dos parâmetros correspondentes. (Consulte [Conversões aritméticas comuns](../c-language/usual-arithmetic-conversions.md) para obter informações sobre conversões aritméticas.) Os argumentos posteriores às reticências não são verificados. Um parâmetro pode ter qualquer tipo fundamental, de estrutura, união, ponteiro ou matriz.

O compilador executa as conversões aritméticas comuns independentemente em cada parâmetro e em cada argumento, se necessário. Após a conversão, nenhum parâmetro é menor que `int` e nenhum parâmetro tem o tipo **float**, a menos que o tipo de parâmetro seja especificado explicitamente como **float** no protótipo. Isso significa, por exemplo, que declarar um parâmetro como `char` tem o mesmo efeito que declará-lo o como `int`.

## <a name="see-also"></a>Consulte também

[Definições de função C](../c-language/c-function-definitions.md)