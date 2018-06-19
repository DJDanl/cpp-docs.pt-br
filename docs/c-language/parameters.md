---
title: Parâmetros | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 655cf3ac04385b055dfdf028261a2a61f3bb45f8
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32391685"
---
# <a name="parameters"></a>Parâmetros
Os argumentos são nomes de valores transmitidos a uma função por uma chamada de função. Os parâmetros são os valores que a função espera receber. Em um protótipo de função, os parênteses posteriores ao nome da função contêm uma lista completa dos parâmetros da função e seus tipos. As declarações de parâmetro especificam os tipos, os tamanhos e os identificadores dos valores armazenados nos parâmetros.  
  
## <a name="syntax"></a>Sintaxe  
 *function-definition*:  
 *declaration-specifiers* opt*attribute-seq* opt*declarator declaration-list* opt*compound-statement*  
  
 /\* *attribute-seq* é específico da Microsoft */  
  
 *declarator* :  
 *pointer* opt*direct-declarator*  
  
 *direct-declarator*:/\* Um declarador de função \*/  
 *direct-declarator*  **(**  *parameter-type-list*  **)** /* Declarador de novo estilo \*/  
  
 *parameter-type-list*: /\* Uma lista de parâmetros \*/  
 *parameter-list*  
  
 *parameter-list*  **,...**  
  
 *parameter-list*:  
 *parameter-declaration*  
  
 *parameter-list*  **,**  *parameter-declaration*  
  
 *parameter-declaration*:  
 *declaration-specifiers declarator*  
  
 *declaration-specifiers abstract-declarator* opt  
  
 A *parameter-type-list* é uma sequência de declarações de parâmetro separadas por vírgulas. O formulário de cada parâmetro em uma lista de parâmetros tem esta aparência:  
  
```  
[register]  type-specifier [declarator]   
```  
  
 Os parâmetros de função declarados com o atributo **auto** geram erros. Os identificadores dos parâmetros são usados no corpo da função para fazer referência aos valores transmitidos à função. Você pode nomear os parâmetros em um protótipo, mas os nomes saem do escopo no final da declaração. Portanto, os nomes dos parâmetros podem ser atribuídos da mesma maneira ou de maneira diferente na definição da função. Esses identificadores não podem ser redefinidos no bloco externo do corpo da função, mas podem ser redefinidos em blocos internos e aninhados, como se a lista de parâmetros fosse um bloco delimitador.  
  
 Cada identificador em *parameter-type-list* deve ser precedido pelo especificador de tipo apropriado, conforme mostrado neste exemplo:  
  
```  
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