---
title: "Operadores C++ internos, precedência e associatividade | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- operators (C++), hierarchy
- operator precedence
- precedence, operators
- operators (C++), associativity
- multiple operators
- associativity of operators
- operators [C++], precedence
- evaluation order
- hierarchy, operator
ms.assetid: 95c1f0ba-dad8-4034-b039-f79a904f112f
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 6c45b0d3ff2aaee6763b73949727dcde5ee744bc
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="c-built-in-operators-precedence-and-associativity"></a>Operadores C++ internos, precedência e capacidade de associação
A linguagem C++ inclui todos os operadores C e adiciona vários operadores novos. Os operadores especificam uma avaliação a ser executada em um ou mais operandos.  
  
 A precedência do operador especifica a ordem das operações em expressões que contêm mais de um operador. A associatividade do operador especifica se, em uma expressão que contém vários operadores com a mesma precedência, um operando é agrupado com aquela à sua esquerda ou com aquela à sua direita. A tabela a seguir mostra a precedência e a associatividade dos operadores C++ (da precedência mais alta a mais baixa). Os operadores com o mesmo número de precedência têm igual precedência, a menos que outra relação seja explicitamente forçada por parênteses.  
  
### <a name="c-operator-precedence-and-associativity"></a>Associatividade e precedência do operador C++  
  
|Descrição do operador|Operador|  
|--------------------------|--------------|  
|`Group 1 precedence, no associativity`|  
|[Resolução do escopo](../cpp/scope-resolution-operator.md)|`::`|  
|`Group 2 precedence, left to right associativity`|  
|[Seleção de membro (objeto ou ponteiro)](../cpp/member-access-operators-dot-and.md)|`. or ->`|  
|[Subscrito da matriz](../cpp/subscript-operator.md)|`[ ]`|  
|[Chamada de função](../cpp/function-call-operator-parens.md)|`( )`|  
|[Operadores de incremento](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|`++`|  
|[Operadores de decremento](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|`--`|  
|[Nome do tipo](../cpp/typeid-operator.md)|`typeid( )`|  
|[Conversão de tipo de constante](../cpp/const-cast-operator.md)|`const_cast`|  
|[Conversão de tipo dinâmico](../cpp/dynamic-cast-operator.md)|`dynamic_cast`|  
|[Conversão de tipo reinterpretados](../cpp/reinterpret-cast-operator.md)|`reinterpret_cast`|  
|[Conversão de tipo estático](../cpp/static-cast-operator.md)|`static_cast`|  
|`Group 3 precedence, right to left associativity`|  
|[Tamanho do objeto ou tipo](../cpp/sizeof-operator.md)|`sizeof`|  
|[Incremento de prefixo](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|`++`|  
|[Decremento de prefixo](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|`--`|  
|[Complemento de um](../cpp/one-s-complement-operator-tilde.md)|`~`|  
|[Não lógico](../cpp/logical-negation-operator-exclpt.md)|`!`|  
|[Negação unária](../cpp/unary-plus-and-negation-operators-plus-and.md)|`-`|  
|[Adição unária](../cpp/unary-plus-and-negation-operators-plus-and.md)|`+`|  
|[Endereço de rede](../cpp/lvalue-reference-declarator-amp.md)|`&`|  
|[Inversão de controle](../cpp/indirection-operator-star.md)|`*`|  
|[Criar objeto](../cpp/new-operator-cpp.md)|`new`|  
|[Destruir o objeto](../cpp/delete-operator-cpp.md)|`delete`|  
|[Conversão](../cpp/cast-operator-parens.md)|`Cast: ()`|  
|`Group 4 precedence, left to right associativity`|  
|[Ponteiro para membro (objetos ou ponteiros)](../cpp/pointer-to-member-operators-dot-star-and-star.md)|`.* or ->*`|  
|`Group 5 precedence, left to right associativity`|  
|[Multiplicação](../cpp/multiplicative-operators-and-the-modulus-operator.md)|`*`|  
|[Divisão](../cpp/multiplicative-operators-and-the-modulus-operator.md)|`/`|  
|[Módulo](../cpp/multiplicative-operators-and-the-modulus-operator.md)|`%`|  
|`Group 6 precedence, left to right associativity`|  
|[Adição](../cpp/additive-operators-plus-and.md)|`+`|  
|[Subtração](../cpp/additive-operators-plus-and.md)|`-`|  
|`Group 7 precedence, left to right associativity`|  
|[Deslocamento para a esquerda](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|`<<`|  
|[Deslocamento para a direita](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|`>>`|  
|`Group 8 precedence, left to right associativity`|  
|[Menor que](../cpp/relational-operators-equal-and-equal.md)|`<`|  
|[Maior que](../cpp/relational-operators-equal-and-equal.md)|`>`|  
|[Menor ou igual a](../cpp/relational-operators-equal-and-equal.md)|`<=`|  
|[Maior ou igual a](../cpp/relational-operators-equal-and-equal.md)|`>=`|  
|`Group 9 precedence, left to right associativity`|  
|[Igualdade](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|`==`|  
|[Desigualdade](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|`!=`|  
|`Group 10 precedence left to right associativity`|  
|[AND bit a bit](../cpp/bitwise-and-operator-amp.md)|`&`|  
|`Group 11 precedence, left to right associativity`|  
|[Bit a bit OR exclusivo](../cpp/bitwise-exclusive-or-operator-hat.md)|`^`|  
|`Group 12 precedence, left to right associativity`|  
|[Bit a bit OR inclusivo](../cpp/bitwise-inclusive-or-operator-pipe.md)|`&#124;`|  
|`Group 13 precedence, left to right associativity`|  
|[AND lógico](../cpp/logical-and-operator-amp-amp.md)|`&&`|  
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
|[Atribuição de subtração](../cpp/assignment-operators.md)|`-=`|  
|[Atribuição Left shift](../cpp/assignment-operators.md)|`<<=`|  
|[Atribuição Right-shift](../cpp/assignment-operators.md)|`>>=`|  
|[Atribuição AND bit a bit](../cpp/assignment-operators.md)|`&=`|  
|[Bit a bit a atribuição OR inclusiva](../cpp/assignment-operators.md)|`&#124;=`|  
|[Bit a bit a atribuição OR exclusiva](../cpp/assignment-operators.md)|`^=`|  
|`Group 17 precedence, right to left associativity`|  
|[gerar a expressão](../cpp/try-throw-and-catch-statements-cpp.md)|`throw`|  
|`Group 18 precedence, left to right associativity`|  
|[Vírgula](../cpp/comma-operator.md)|`,`|  
  
## <a name="see-also"></a>Consulte também  
[Sobrecarga de Operador](operator-overloading.md)



