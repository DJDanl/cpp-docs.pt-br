---
title: Definições de função C
ms.date: 11/04/2016
helpviewer_keywords:
- function declarators
- function definitions
- declaring functions, about function declarations
- declaring functions, declarators
- functions [C], parameters
- declarators, functions
- function parameters, function definitions
- function body
- declaring functions, variables
ms.assetid: ebab23c8-6eb8-46f3-b21d-570cd8457a80
ms.openlocfilehash: a26f95f8fef2b52dac36dd5d33f826c73fd84eee
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228005"
---
# <a name="c-function-definitions"></a>Definições de função C

Uma definição de função especifica o nome da função, os tipos e o número de parâmetros que espera receber, além de seu tipo de retorno. Uma definição de função também inclui um corpo de função com as declarações de suas variáveis locais, e as instruções que determinam o que a função faz.

## <a name="syntax"></a>Sintaxe

*translation-unit*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração externa* <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*translation-unit* *external-declaration*

*declaração externa*:/ \* permitida somente em escopo externo (arquivo)\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*função-definição*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*mesma*

*função-definição*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers*<sub>opt</sub> *attribute-seq*<sub>opt</sub> *declarator* *declaration-list*<sub>opt</sub> *compound-statement*

/\**Attribute-Seq* é específico da Microsoft\*/

Os parâmetros de protótipo são:

*declaration-specifiers*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*storage-class-specifier* *declaration-specifiers*<sub>opt</sub> <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier* *declaration-specifiers*<sub>opt</sub>

*declaration-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*mesma*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-list* *declaration*

*Declarador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pointer*<sub>opt</sub> *direct-declarator*

*Declarador direto*:/ \* um Declarador de função\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Declarador *direto***(***tipo de parâmetro-lista***)**  / \* Declarador de novo estilo      \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto***(***opção identificador-lista*<sub>opt</sub> **)**  / \* Declarador de estilo obsoleto    \*/

A lista de parâmetros em uma definição usa esta sintaxe:

*tipo de parâmetro-lista*:/ \* a lista de parâmetros\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*lista de parâmetros* <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*lista de parâmetros* **,...**

*lista de parâmetros*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração de parâmetro*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parâmetro-List* **,**  *declaração de parâmetro*

*parameter-declaration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers* *declarator*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers* *abstract-declarator*<sub>opt</sub>

A lista de parâmetros em uma definição de função antiga usa esta sintaxe:

*identificador-lista*:/ \* usado em definições e declarações de função de estilo obsoleto\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*ID*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identificador-lista* **,**  *identificador*

A sintaxe para o corpo da função é:

*instrução composta*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**{** *declaração-lista*de instruções<sub>opt</sub> *-lista*<sub>opt</sub> **}**

Os únicos especificadores de classe de armazenamento que podem modificar uma declaração de função são **`extern`** e **`static`** . O **`extern`** especificador significa que a função pode ser referenciada de outros arquivos; ou seja, o nome da função é exportado para o vinculador. O **`static`** especificador significa que a função não pode ser referenciada de outros arquivos; ou seja, o nome não é exportado pelo vinculador. Se nenhuma classe de armazenamento aparecer em uma definição de função, **`extern`** será assumida. Em qualquer caso, a função sempre é visível do ponto de definição ao final do arquivo.

Juntos, os *declaration-specifiers* opcionais e *declarator* obrigatórios especificam o nome e tipo de retorno da função. O *declarator* é uma combinação de identificador que nomeia a função e os parênteses depois do nome da função. O *attribute-seq* não terminal opcional é um recurso específico da Microsoft definido em [Atributos de função](../c-language/function-attributes.md).

O *direct-declarator* (na sintaxe *declarator*) especifica o nome da função sendo definida e os identificadores dos seus parâmetros. Se o *direct-declarator* incluir uma *parameter-type-list*, a lista especifica os tipos de todos os parâmetros. Esse declarador também serve como um protótipo da função para chamadas posteriores para a função.

Uma *declaração* na *lista de declarações* nas definições de função não pode conter um *especificador de classe de armazenamento* diferente de **`register`** . O *especificador de tipo* na sintaxe de *especificadores de declaração* pode ser omitido somente se a **`register`** classe de armazenamento for especificada para um valor do **`int`** tipo.

A *compound-statement* é o corpo da função que contém declarações de variável local, referências a itens declarados externamente e instruções.

As seções [Atributos de função](../c-language/function-attributes.md), [Classe de armazenamento](../c-language/storage-class.md), [Tipo de retorno](../c-language/return-type.md), [Parâmetros](../c-language/parameters.md) e [Corpo da função](../c-language/function-body.md) descrevem os componentes da definição de função detalhadamente.

## <a name="see-also"></a>Confira também

[Funções](../c-language/functions-c.md)
