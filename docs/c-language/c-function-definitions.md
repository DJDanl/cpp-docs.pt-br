---
title: Definições de função C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cbfc7e7bd6a3f2ef727a0cc259f222afad0ab555
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46055228"
---
# <a name="c-function-definitions"></a>Definições de função C

Uma definição de função especifica o nome da função, os tipos e o número de parâmetros que espera receber, além de seu tipo de retorno. Uma definição de função também inclui um corpo de função com as declarações de suas variáveis locais, e as instruções que determinam o que a função faz.

## <a name="syntax"></a>Sintaxe

*translation-unit*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*external-declaration* <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*translation-unit* *external-declaration*

*external-declaration*: /\* Permitida apenas no escopo externo (do arquivo) \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*function-definition*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration*

*function-definition*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers*<sub>opt</sub> *attribute-seq*<sub>opt</sub> *declarator* *declaration-list*<sub>opt</sub> *compound-statement*

/\* *attribute-seq* é Específico da Microsoft \*/

Os parâmetros de protótipo são:

*declaration-specifiers*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*storage-class-specifier* *declaration-specifiers*<sub>opt</sub> <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier* *declaration-specifiers*<sub>opt</sub>

*declaration-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-list* *declaration*

*declarator*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pointer*<sub>opt</sub> *direct-declarator*

*direct-declarator*: /\* Um declarador de função \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*direct-declarator*  **(**  *parameter-type-list*  **)** /\* Declarador de novo estilo \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*direct-declarator*  **(**  *identifier-list*<sub>opt</sub> **)** /\* Declarador de estilo obsoleto \*/

A lista de parâmetros em uma definição usa esta sintaxe:

*parameter-type-list*: /\* A lista de parâmetros \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parameter-list* <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parameter-list* **, ...**

*parameter-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parameter-declaration*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parameter-list* **,**  *parameter-declaration*

*parameter-declaration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers* *declarator*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers* *abstract-declarator*<sub>opt</sub>

A lista de parâmetros em uma definição de função antiga usa esta sintaxe:

*identifier-list*: /\* Usada em declarações e definições de função de estilo obsoleto \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier-list* **,**  *identifier*

A sintaxe para o corpo da função é:

*compound-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**{** *declaration-list*<sub>opt</sub> *statement-list*<sub>opt</sub> **}**

Os únicos especificadores de classe de armazenamento que podem alterar uma declaração de função são **extern** e **static**. O especificador **extern** significa que a função pode ser referenciada de outros arquivos; ou seja, o nome da função é exportado para o vinculador. O especificador **static** significa que a função não pode ser referenciada de outros arquivos; ou seja, o nome não é exportado pelo vinculador. Se nenhuma classe de armazenamento for exibida em uma definição de função, **extern** será assumido. Em qualquer caso, a função sempre é visível do ponto de definição ao final do arquivo.

Juntos, os *declaration-specifiers* opcionais e *declarator* obrigatórios especificam o nome e tipo de retorno da função. O *declarator* é uma combinação de identificador que nomeia a função e os parênteses depois do nome da função. O *attribute-seq* não terminal opcional é um recurso específico da Microsoft definido em [Atributos de função](../c-language/function-attributes.md).

O *direct-declarator* (na sintaxe *declarator*) especifica o nome da função sendo definida e os identificadores dos seus parâmetros. Se o *direct-declarator* incluir uma *parameter-type-list*, a lista especifica os tipos de todos os parâmetros. Esse declarador também serve como um protótipo da função para chamadas posteriores para a função.

Uma *declaration* na *declaration-list* nas definições da função não pode conter um *storage-class-specifier* diferente de **register**. O *type-specifier* na sintaxe *declaration-specifiers* poderá ser omitido apenas se a classe de armazenamento **register** for especificada para um valor do tipo **int**.

A *compound-statement* é o corpo da função que contém declarações de variável local, referências a itens declarados externamente e instruções.

As seções [Atributos de função](../c-language/function-attributes.md), [Classe de armazenamento](../c-language/storage-class.md), [Tipo de retorno](../c-language/return-type.md), [Parâmetros](../c-language/parameters.md) e [Corpo da função](../c-language/function-body.md) descrevem os componentes da definição de função detalhadamente.

## <a name="see-also"></a>Consulte também

[Funções](../c-language/functions-c.md)