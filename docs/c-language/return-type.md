---
title: Tipo de Retorno | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- function return types
- return values [C++], function procedures
- function return types, syntax
- return values [C++]
- data types [C++], function return types
- return keyword [C++], function return types
- functions [C++], return types
ms.assetid: 3e5b8a97-b341-48c5-8be8-8986980ef586
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 08c81333d599411b180ebf5f0a00e1ab61536903
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46076840"
---
# <a name="return-type"></a>Tipo de retorno

O tipo de retorno de uma função estabelece o tamanho e o tipo do valor retornado pela função e corresponde ao elemento type-specifier na sintaxe abaixo:

## <a name="syntax"></a>Sintaxe

*function-definition*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers*<sub>opt</sub> *attribute-seq*<sub>opt</sub> *declarator* *declaration-list*<sub>opt</sub> *compound-statement*

/\* *attribute-seq* é Específico da Microsoft \*/

*declaration-specifiers*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*storage-class-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier* *declaration-specifiers*<sub>opt</sub>

*type-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**void**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**char**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**short**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**int**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__int8** /\* Específico da Microsoft \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__int16** /\* Específico da Microsoft \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__int32** /\* Específico da Microsoft \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__int64** /\* Específico da Microsoft \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**long**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**float**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**double**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**signed**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**unsigned**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*struct-or-union-specifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*enum-specifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*typedef-name*

*type-specifier* pode especificar qualquer tipo de fundamental, de estrutura ou união. Se você não incluir o *type-specifier*, o tipo de retorno `int` será presumido.

O tipo de retorno especificado na definição de função deve corresponder ao tipo de retorno em declarações da função em outros lugares no programa. Uma função retorna um valor quando uma instrução `return` que contém uma expressão é executada. A expressão é avaliada, convertida no tipo de valor de retorno, se necessário, e retornada ao ponto em que a função foi chamada. Se uma função é declarada com o tipo de retorno `void`, uma instrução return que contém uma expressão gera um aviso e a expressão não é avaliada.

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

Este exemplo define o tipo `STUDENT` com uma declaração `typedef` e define a função `sortstu` para ter o tipo de retorno `STUDENT`. A função seleciona e retorna um de seus dois argumentos de estrutura. Em chamadas subsequentes à função, o compilador verifica se os tipos de argumento são `STUDENT`.

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

O exemplo define uma função que retorna um ponteiro para uma matriz de caracteres. A função usa duas matrizes de caracteres (cadeias de caracteres) como argumentos e retorna um ponteiro para a mais curta das duas cadeias de caracteres. Um ponteiro para os pontos de uma matriz para o primeiro dos elementos da matriz e tem seu tipo; assim, o tipo de retorno da função é um ponteiro para o tipo `char`.

Você não precisa declarar funções com o tipo de retorno `int` antes de chamá-las, embora protótipos sejam recomendados de forma que a verificação de tipo correto de argumentos e valores de retorno seja habilitada.

## <a name="see-also"></a>Consulte também

[Definições de função C](../c-language/c-function-definitions.md)