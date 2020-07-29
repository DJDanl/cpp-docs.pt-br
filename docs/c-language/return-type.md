---
title: Tipo de retorno
ms.date: 11/04/2016
helpviewer_keywords:
- function return types
- return values [C++], function procedures
- function return types, syntax
- return values [C++]
- data types [C++], function return types
- return keyword [C++], function return types
- functions [C++], return types
ms.assetid: 3e5b8a97-b341-48c5-8be8-8986980ef586
ms.openlocfilehash: 1d905e02be02784b562b9d1a8f72a9bfa4057b9b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226321"
---
# <a name="return-type"></a>Tipo de retorno

O tipo de retorno de uma função estabelece o tamanho e o tipo do valor retornado pela função e corresponde ao elemento type-specifier na sintaxe abaixo:

## <a name="syntax"></a>Sintaxe

*função-definição*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers*<sub>opt</sub> *attribute-seq*<sub>opt</sub> *declarator* *declaration-list*<sub>opt</sub> *compound-statement*

/\**Attribute-Seq* é específico da Microsoft\*/

*declaration-specifiers*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*storage-class-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier* *declaration-specifiers*<sub>opt</sub>

*type-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`void`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`char`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`short`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`int`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__int8`** /\*Específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__int16`** /\*Específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__int32`** /\*Específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__int64`** /\*Específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`long`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`float`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`double`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`signed`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`unsigned`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*especificador struct-ou-Union-*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*especificador de enumeração*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*typedef-Name*

*type-specifier* pode especificar qualquer tipo de fundamental, de estrutura ou união. Se você não incluir o *especificador de tipo*, o tipo de retorno **`int`** será assumido.

O tipo de retorno especificado na definição de função deve corresponder ao tipo de retorno em declarações da função em outros lugares no programa. Uma função retorna um valor quando uma **`return`** instrução que contém uma expressão é executada. A expressão é avaliada, convertida no tipo de valor de retorno, se necessário, e retornada ao ponto em que a função foi chamada. Se uma função for declarada com o tipo de retorno **`void`** , uma instrução de retorno contendo uma expressão gerará um aviso e a expressão não será avaliada.

Os exemplos a seguir ilustram valores de retorno da função.

```C
typedef struct
{
    char name[20];
    int id;
    long class;
} STUDENT;

/* Return type is STUDENT: */

STUDENT sortstu( STUDENT a, STUDENT b )
{
    return ( (a.id < b.id) ? a : b );
}
```

Este exemplo define o `STUDENT` tipo com uma **`typedef`** declaração e define a função `sortstu` para ter o `STUDENT` tipo de retorno. A função seleciona e retorna um de seus dois argumentos de estrutura. Em chamadas subsequentes à função, o compilador verifica se os tipos de argumento são `STUDENT`.

> [!NOTE]
> A eficiência seria aprimorada passando ponteiros para a estrutura, em vez da estrutura inteira.

```C
char *smallstr( char s1[], char s2[] )
{
    int i;

    i = 0;
    while ( s1[i] != '\0' && s2[i] != '\0' )
        i++;
    if ( s1[i] == '\0' )
        return ( s1 );
    else
        return ( s2 );
}
```

O exemplo define uma função que retorna um ponteiro para uma matriz de caracteres. A função usa duas matrizes de caracteres (cadeias de caracteres) como argumentos e retorna um ponteiro para a mais curta das duas cadeias de caracteres. Um ponteiro para uma matriz aponta para o primeiro dos elementos da matriz e tem seu tipo; assim, o tipo de retorno da função é um ponteiro a ser digitado **`char`** .

Você não precisa declarar funções com **`int`** tipo de retorno antes de chamá-las, embora os protótipos sejam recomendados para que a verificação de tipo correta para argumentos e valores de retorno esteja habilitada.

## <a name="see-also"></a>Confira também

[Definições de função C](../c-language/c-function-definitions.md)
