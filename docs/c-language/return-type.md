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
ms.openlocfilehash: 18d90604ccaebab2d3ed7812835c711d4d56995a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="return-type"></a>Tipo de retorno
O tipo de retorno de uma função estabelece o tamanho e o tipo do valor retornado pela função e corresponde ao elemento type-specifier na sintaxe abaixo:  
  
## <a name="syntax"></a>Sintaxe  
 *function-definition*:  
 *declaration-specifiers* opt*attribute-seq* opt*declarator declaration-list* opt*compound-statement*  
  
 /\* *attribute-seq* é específico da Microsoft */  
  
 *declaration-specifiers*:  
 *storage-class-specifier declaration-specifiers* opt  
  
 *type-specifier declaration-specifiers* opt  
  
 *type-qualifier declaration-specifiers* opt  
  
 *type-specifier*:  
 **void**  
  
 **char**  
  
 **short**  
  
 **int**  
  
 **long**  
  
 **float**  
  
 **double**  
  
 **signed**  
  
 **unsigned**  
  
 *struct-or-union-specifier*  
  
 *enum-specifier*  
  
 *typedef-name*  
  
 *type-specifier* pode especificar qualquer tipo de fundamental, de estrutura ou união. Se você não incluir o *type-specifier*, o tipo de retorno `int` será presumido.  
  
 O tipo de retorno especificado na definição de função deve corresponder ao tipo de retorno em declarações da função em outros lugares no programa. Uma função retorna um valor quando uma instrução `return` que contém uma expressão é executada. A expressão é avaliada, convertida no tipo de valor de retorno, se necessário, e retornada ao ponto em que a função foi chamada. Se uma função é declarada com o tipo de retorno `void`, uma instrução return que contém uma expressão gera um aviso e a expressão não é avaliada.  
  
 Os exemplos a seguir ilustram valores de retorno da função.  
  
```  
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
>  A eficiência seria aprimorada passando ponteiros para a estrutura, em vez da estrutura inteira.  
  
```  
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