---
title: "Par&#226;metros | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "reticências ..."
  - "argumentos [C++], Função "
  - "reticências (...), parâmetros"
  - "argumentos de função, vs. parâmetros"
  - "parâmetros de função"
  - "parâmetros de função, sintaxe"
  - "funções [C], parâmetros"
  - "parâmetros [C++]"
  - "parâmetros [C++], Função "
ms.assetid: 8f2b8026-78b5-4e21-86a3-bf0f91f05689
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Par&#226;metros
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os argumentos são nomes de valores transmitidos a uma função por uma chamada de função.  Os parâmetros são os valores que a função espera receber.  Em um protótipo de função, os parênteses posteriores ao nome da função contêm uma lista completa dos parâmetros da função e seus tipos.  As declarações de parâmetro especificam os tipos, os tamanhos e os identificadores dos valores armazenados nos parâmetros.  
  
## Sintaxe  
 *function\-definition*:  
 *declaration\-specifiers*  opt *attribute\-seq* opt *declarator declaration\-list* opt *compound\-statement*  
  
 \/\* *attribute\-seq* é específico da Microsoft \*\/  
  
 *declarator* :  
 *pointer*  opt *direct\-declarator*  
  
 *direct\-declarator*:\/\* Um declarador de função \*\/  
 *direct\-declarator*  **\(**  *parameter\-type\-list*  **\)** \/\* Declarador de novo estilo \*\/  
  
 *parameter\-type\-list*: \/\* Uma lista de parâmetros \*\/  
 *parameter\-list*  
  
 *parameter\-list*  **,...**  
  
 *parameter\-list*:  
 *parameter\-declaration*  
  
 *parameter\-list*  **,**  *parameter\-declaration*  
  
 *parameter\-declaration*:  
 *declaration\-specifiers declarator*  
  
 *declaration\-specifiers abstract\-declarator*  opt  
  
 A *parameter\-type\-list* é uma sequência de declarações de parâmetro separadas por vírgulas.  O formulário de cada parâmetro em uma lista de parâmetros tem esta aparência:  
  
```  
[register]  type-specifier [declarator]   
```  
  
 Os parâmetros de função declarados com o atributo **auto** geram erros.  Os identificadores dos parâmetros são usados no corpo da função para fazer referência aos valores transmitidos à função.  Você pode nomear os parâmetros em um protótipo, mas os nomes saem do escopo no final da declaração.  Portanto, os nomes dos parâmetros podem ser atribuídos da mesma maneira ou de maneira diferente na definição da função.  Esses identificadores não podem ser redefinidos no bloco externo do corpo da função, mas podem ser redefinidos em blocos internos e aninhados, como se a lista de parâmetros fosse um bloco delimitador.  
  
 Cada identificador em *parameter\-type\-list* deve ser precedido pelo especificador de tipo apropriado, conforme mostrado neste exemplo:  
  
```  
void new( double x, double y, double z )  
{  
    /* Function body here */  
}  
```  
  
 Se pelo menos um parâmetro ocorrer na lista de parâmetros, a lista poderá terminar com uma vírgula seguida de três pontos \(**, ...**\).  Essa construção, chamada "notação de reticências", indica um número variável de argumentos para a função. \(Consulte [Chamadas com um número variável de argumentos](../c-language/calls-with-a-variable-number-of-arguments.md) para obter mais informações.\) No entanto, uma chamada para a função deve ter pelo menos o mesmo número de argumentos que os parâmetros antes da última vírgula.  
  
 Se nenhum argumento for transmitido à função, a lista de parâmetros será substituída pela palavra\-chave `void`.  Esse uso de `void` é diferente do seu uso como um especificador de tipo.  
  
 A ordem e o tipo de parâmetros, inclusive qualquer uso da notação de reticências, devem ser iguais em todas as declarações de função \(se houver\) e na definição da função.  Os tipos de argumentos depois das conversões aritméticas comuns devem ter atribuições compatíveis com os tipos dos parâmetros correspondentes. \(Consulte [Conversões aritméticas comuns](../c-language/usual-arithmetic-conversions.md) para obter informações sobre conversões aritméticas.\) Os argumentos posteriores às reticências não são verificados.  Um parâmetro pode ter qualquer tipo fundamental, de estrutura, união, ponteiro ou matriz.  
  
 O compilador executa as conversões aritméticas comuns independentemente em cada parâmetro e em cada argumento, se necessário.  Após a conversão, nenhum parâmetro é menor que `int` e nenhum parâmetro tem o tipo **float**, a menos que o tipo de parâmetro seja especificado explicitamente como **float** no protótipo.  Isso significa, por exemplo, que declarar um parâmetro como `char` tem o mesmo efeito que declará\-lo o como `int`.  
  
## Consulte também  
 [Definições de função C](../c-language/c-function-definitions.md)