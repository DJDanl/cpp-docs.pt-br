---
title: "Definições de função C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a58adfefc5e2b3b5085a44c38dd392d3369421c8
ms.sourcegitcommit: 9239c52c05e5cd19b6a72005372179587a47a8e4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2018
---
# <a name="c-function-definitions"></a>Definições de função C
Uma definição de função especifica o nome da função, os tipos e o número de parâmetros que espera receber, além de seu tipo de retorno. Uma definição de função também inclui um corpo de função com as declarações de suas variáveis locais, e as instruções que determinam o que a função faz.  
  
## <a name="syntax"></a>Sintaxe  
 *translation-unit*:  
 *external-declaration*  
  
 *translation-unit external-declaration*  
  
 *external-declaration*: /\* Permitida apenas no escopo externo (do arquivo) \*/  
 *function-definition*  
  
 `declaration`  
  
 *function-definition*: /\* Aqui, o declarador é o declarador de função \*/  
 *declaration-specifiers* opt*attribute-seq* opt*declarator declaration-list* opt*compound-statement*  
  
 /\* *attribute-seq* é específico da Microsoft */  
  
 Os parâmetros de protótipo são:  
  
 *declaration-specifiers*:  
 *storage-class-specifier declaration-specifiers* opt  
  
 *type-specifier declaration-specifiers* opt  
  
 *type-qualifier declaration-specifiers* opt  
  
 *declaration-list*:  
 *declaration*  
  
 *declaration-list declaration*  
  
 `declarator`:  
 *pointer* opt*direct-declarator*  
  
 *direct-declarator*: /\* Um declarador de função \*/  
 *direct-declarator*  **(**  *parameter-type-list*  **)** /* Declarador de novo estilo \*/  
  
 *direct-declarator*  **(**  *identifier-list* opt**)** /* Declarador de estilo obsoleto \*/  
  
 A lista de parâmetros em uma definição usa esta sintaxe:  
  
 *parameter-type-list*: /\* A lista de parâmetros \*/  
 *parameter-list*  
  
 *parameter-list* **, ...**  
  
 *parameter-list*:  
 *parameter-declaration*  
  
 *parameter-list* **,**  *parameter-declaration*  
  
 *parameter-declaration*:  
 *declaration-specifiers declarator*  
  
 *declaration-specifiers abstract declarator* opt  
  
 A lista de parâmetros em uma definição de função antiga usa esta sintaxe:  
  
 *identifier-list*: /\* Usada em declarações e definições de função de estilo obsoleto \*/  
 *identifier*  
  
 *identifier-list* **,**  *identifier*  
  
 A sintaxe para o corpo da função é:  
  
 *compound-statement*: /\* O corpo da função \*/  
 **{**  `declaration`-*list* opt*statement-list* opt**}**  
  
 Os únicos especificadores de classe de armazenamento que podem alterar uma declaração de função são `extern` e **static**. O especificador `extern` significa que a função pode ser referenciada de outros arquivos; ou seja, o nome da função é exportado para o vinculador. O especificador **static** significa que a função não pode ser referenciada de outros arquivos; ou seja, o nome não é exportado pelo vinculador. Se nenhuma classe de armazenamento dor exibida em uma definição de função, `extern` será assumido. Em qualquer caso, a função sempre é visível do ponto de definição ao final do arquivo.  
  
 Juntos, os *declaration-specifiers* opcionais e `declarator` obrigatórios especificam o nome e tipo de retorno da função. 
          `declarator` é uma combinação de identificador que nomeia a função e os parênteses depois do nome da função. O *attribute-seq* não terminal opcional é um recurso específico da Microsoft definido em [Atributos de função](../c-language/function-attributes.md).  
  
 O *direct-declarator* (na sintaxe `declarator`) especifica o nome da função sendo definida e os identificadores dos seus parâmetros. Se o *direct-declarator* incluir uma *parameter-type-list*, a lista especifica os tipos de todos os parâmetros. Esse declarador também serve como um protótipo da função para chamadas posteriores para a função.  
  
 Uma `declaration` na *declaration-list* nas definições da função não pode conter um *storage-class-specifier* diferente de **register**. O *type-specifier* na sintaxe *declaration-specifiers* pode ser omitido apenas se a classe de armazenamento **register** for especificada para um valor do tipo `int`.  
  
 A *compound-statement* é o corpo da função que contém declarações de variável local, referências a itens declarados externamente e instruções.  
  
 As seções [Atributos de função](../c-language/function-attributes.md), [Classe de armazenamento](../c-language/storage-class.md), [Tipo de retorno](../c-language/return-type.md), [Parâmetros](../c-language/parameters.md) e [Corpo da função](../c-language/function-body.md) descrevem os componentes da definição de função detalhadamente.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../c-language/functions-c.md)