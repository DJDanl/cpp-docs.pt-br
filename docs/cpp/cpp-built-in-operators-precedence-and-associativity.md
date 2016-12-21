---
title: "Operadores, preced&#234;ncia e associatividade C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "associatividade dos operadores"
  - "ordem de avaliação"
  - "hierarquia, operator"
  - "vários operadores"
  - "precedência do Operador"
  - "operadores (C++), associatividade"
  - "operadores (C++), hierarquia"
  - "operadores [C++], precedência"
  - "precedência, operadores"
ms.assetid: 95c1f0ba-dad8-4034-b039-f79a904f112f
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores, preced&#234;ncia e associatividade C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A linguagem C\+\+ inclui todos os operadores C e adiciona vários operadores novos.  Os operadores especificam uma avaliação a ser executada em um ou mais operandos.  
  
 A precedência do operador especifica a ordem das operações em expressões que contêm mais de um operador.  A associatividade do operador especifica se, em uma expressão que contém vários operadores com a mesma precedência, um operando é agrupado com aquela à sua esquerda ou com aquela à sua direita.  A tabela a seguir mostra a precedência e a associatividade dos operadores C\+\+ \(da precedência mais alta a mais baixa\).  Os operadores com o mesmo número de precedência têm igual precedência, a menos que outra relação seja explicitamente forçada por parênteses.  
  
### Associatividade e precedência do operador C\+\+  
  
|Descrição do operador|Operador|  
|---------------------------|--------------|  
|`Group 1 precedence, no associativity`|  
|[Resolução do escopo](../cpp/scope-resolution-operator.md)|`::`|  
|`Group 2 precedence, left to right associativity`|  
|[Seleção de membro \(objeto ou ponteiro\)](../Topic/Member%20Access%20Operators:%20.%20and%20-%3E.md)|`. or –>`|  
|[Subscrito de matriz](../Topic/Subscript%20Operator:.md)|`[ ]`|  
|[Chamada de função](../cpp/function-call-operator-parens.md)|`( )`|  
|[Incremento de sufixo](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|`++`|  
|[Decremento de sufixo](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|`––`|  
|[Nome de tipo](../cpp/typeid-operator.md)|`typeid( )`|  
|[Conversão de tipo constante](../Topic/const_cast%20Operator.md)|`const_cast`|  
|[Conversão de tipo dinâmico](../cpp/dynamic-cast-operator.md)|`dynamic_cast`|  
|[Conversão de tipo reinterpretado](../cpp/reinterpret-cast-operator.md)|`reinterpret_cast`|  
|[Conversão de tipo estático](../cpp/static-cast-operator.md)|`static_cast`|  
|`Group 3 precedence, right to left associativity`|  
|[Tamanho do objeto ou tipo](../cpp/sizeof-operator.md)|`sizeof`|  
|[Incremento de prefixo](../Topic/Prefix%20Increment%20and%20Decrement%20Operators:%20++%20and%20--.md)|`++`|  
|[Decremento de prefixo](../Topic/Prefix%20Increment%20and%20Decrement%20Operators:%20++%20and%20--.md)|`––`|  
|[Complemento de um](../cpp/one-s-complement-operator-tilde.md)|`~`|  
|[Não lógico](../cpp/logical-negation-operator-exclpt.md)|`!`|  
|[Negação unária](../misc/unary-negation-operator.md)|`-`|  
|[Adição unária](../cpp/unary-plus-and-negation-operators-plus-and.md)|`+`|  
|[Address\-of](../Topic/Lvalue%20Reference%20Declarator:%20&.md)|`&`|  
|[Indireção](../cpp/indirection-operator-star.md)|`*`|  
|[Objeto Create](../cpp/new-operator-cpp.md)|`new`|  
|[Objeto Destroy](../cpp/delete-operator-cpp.md)|`delete`|  
|[Conversão](../Topic/Cast%20Operator:%20\(\).md)|`Cast: ()`|  
|`Group 4 precedence, left to right associativity`|  
|[Ponteiro para membro \(objetos ou ponteiros\)](../cpp/pointer-to-member-operators-dot-star-and-star.md)|`.* or –>*`|  
|`Group 5 precedence, left to right associativity`|  
|[Multiplicação](../cpp/multiplicative-operators-and-the-modulus-operator.md)|`*`|  
|[Divisão](../cpp/multiplicative-operators-and-the-modulus-operator.md)|`/`|  
|[Módulo](../cpp/multiplicative-operators-and-the-modulus-operator.md)|`%`|  
|`Group 6 precedence, left to right associativity`|  
|[Adição](../cpp/additive-operators-plus-and.md)|`+`|  
|[Subtração](../cpp/additive-operators-plus-and.md)|`–`|  
|`Group 7 precedence, left to right associativity`|  
|[Shift esquerda](../Topic/Left%20Shift%20and%20Right%20Shift%20Operators%20\(%3E%3E%20and%20%3C%3C\).md)|`<<`|  
|[Shift direita](../Topic/Left%20Shift%20and%20Right%20Shift%20Operators%20\(%3E%3E%20and%20%3C%3C\).md)|`>>`|  
|`Group 8 precedence, left to right associativity`|  
|[Menor que](../cpp/relational-operators-equal-and-equal.md)|`<`|  
|[Maior que](../cpp/relational-operators-equal-and-equal.md)|`>`|  
|[Menor que ou igual a](../cpp/relational-operators-equal-and-equal.md)|`<=`|  
|[Maior que ou igual a](../cpp/relational-operators-equal-and-equal.md)|`>=`|  
|`Group 9 precedence, left to right associativity`|  
|[Igualdade](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|`==`|  
|[Desigualdade](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|`!=`|  
|`Group 10 precedence left to right associativity`|  
|[AND bit a bit](../cpp/bitwise-and-operator-amp.md)|`&`|  
|`Group 11 precedence, left to right associativity`|  
|[OR exclusivo de bit a bit](../cpp/bitwise-exclusive-or-operator-hat.md)|`^`|  
|`Group 12 precedence, left to right associativity`|  
|[OR inclusivo de bit a bit](../cpp/bitwise-inclusive-or-operator-pipe.md)|`&#124;`|  
|`Group 13 precedence, left to right associativity`|  
|[AND lógico](../Topic/Logical%20AND%20Operator:%20&&.md)|`&&`|  
|`Group 14 precedence, left to right associativity`|  
|[OR lógico](../cpp/logical-or-operator-pipe-pipe.md)|`&#124;&#124;`|  
|`Group 15 precedence, right to left associativity`|  
|[Condicional](../cpp/conditional-operator-q.md)|`? :`|  
|`Group 16 precedence, right to left associativity`|  
|[Atribuição](../cpp/assignment-operators.md)|`=`|  
|[Atribuição de multiplicação](../cpp/assignment-operators.md)|`*=`|  
|[Atribuição de divisão](../cpp/assignment-operators.md)|`/=`|  
|[Atribuição de módulo](../cpp/assignment-operators.md)|`%=`|  
|[Atribuição de adição](../cpp/assignment-operators.md)|`+=`|  
|[Atribuição de subtração](../cpp/assignment-operators.md)|`–=`|  
|[Atribuição de shift esquerda](../cpp/assignment-operators.md)|`<<=`|  
|[Atribuição de shift direita](../cpp/assignment-operators.md)|`>>=`|  
|[Atribuição AND de bit a bit](../cpp/assignment-operators.md)|`&=`|  
|[Atribuição OR inclusivo de bit a bit](../cpp/assignment-operators.md)|`&#124;=`|  
|[Atribuição OR exclusivo de bit a bit](../cpp/assignment-operators.md)|`^=`|  
|`Group 17 precedence, right to left associativity`|  
|[expressão de lançamento](../cpp/try-throw-and-catch-statements-cpp.md)|`throw`|  
|`Group 18 precedence, left to right associativity`|  
|[Vírgula](../cpp/comma-operator.md)|`,`|  
  
## Consulte também  
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Sobrecarga de operador](../cpp/operator-overloading.md)