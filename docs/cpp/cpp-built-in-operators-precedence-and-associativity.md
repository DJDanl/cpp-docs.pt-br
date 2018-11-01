---
title: Operadores C++ internos, precedência e associatividade
ms.date: 11/04/2016
helpviewer_keywords:
- operators (C++), hierarchy
- operator precedence
- precedence, operators
- operators (C++), associativity
- multiple operators [C++]
- associativity of operators [C++]
- operators [C++], precedence
- evaluation order
- hierarchy, operator
ms.assetid: 95c1f0ba-dad8-4034-b039-f79a904f112f
ms.openlocfilehash: 0b560913deb57393a8547f0831e0d987eed41ab7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50574051"
---
# <a name="c-built-in-operators-precedence-and-associativity"></a>Operadores C++ internos, precedência e associatividade

A linguagem C++ inclui todos os operadores C e adiciona vários operadores novos. Os operadores especificam uma avaliação a ser executada em um ou mais operandos.

Operador *precedência* Especifica a ordem das operações em expressões que contêm mais de um operador. Operador *associatividade* Especifica se, em uma expressão que contém vários operadores com a mesma precedência, um operando é agrupado com aquela à sua esquerda ou a aquela à sua direita. A tabela a seguir mostra a precedência e a associatividade dos operadores C++ (da precedência mais alta a mais baixa). Os operadores com o mesmo número de precedência têm igual precedência, a menos que outra relação seja explicitamente forçada por parênteses.

### <a name="c-operator-precedence-and-associativity"></a>Associatividade e precedência do operador C++

|Descrição do operador|Operador|
|--------------------------|--------------|
|**Precedência de 1, nenhuma associação de grupo**|
|[Resolução de escopo](../cpp/scope-resolution-operator.md)|[::](../cpp/scope-resolution-operator.md)|
|**Precedência do grupo 2, da esquerda para direita associatividade**|
|[Seleção de membro (objeto ou ponteiro)](../cpp/member-access-operators-dot-and.md)|[. ou ->](../cpp/member-access-operators-dot-and.md)|
|[Subscrito de matriz](../cpp/subscript-operator.md)|[&#91;&#93;](../cpp/subscript-operator.md)|
|[Chamada de função](../cpp/function-call-operator-parens.md)|[()](../cpp/function-call-operator-parens.md)|
|[Incremento de sufixo](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|[++](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|
|[Decremento de sufixo](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|[--](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|
|[Nome do tipo](../cpp/typeid-operator.md)|[TypeId](../cpp/typeid-operator.md)|
|[Conversão de tipo de constante](../cpp/const-cast-operator.md)|[const_cast](../cpp/const-cast-operator.md)|
|[Conversão de tipo dinâmico](../cpp/dynamic-cast-operator.md)|[dynamic_cast](../cpp/dynamic-cast-operator.md)|
|[Conversão de tipo reinterpretado](../cpp/reinterpret-cast-operator.md)|[reinterpret_cast](../cpp/reinterpret-cast-operator.md)|
|[Conversão de tipo estático](../cpp/static-cast-operator.md)|[static_cast](../cpp/static-cast-operator.md)|
|**Precedência do grupo 3, da direita para esquerda associatividade**|
|[Tamanho do objeto ou tipo](../cpp/sizeof-operator.md)|[sizeof](../cpp/sizeof-operator.md)|
|[Incremento de prefixo](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|[++](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|
|[Decremento de prefixo](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|[--](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|
|[Complemento de um](../cpp/one-s-complement-operator-tilde.md)|[~](../cpp/one-s-complement-operator-tilde.md)|
|[Not lógico](../cpp/logical-negation-operator-exclpt.md)|[\!](../cpp/logical-negation-operator-exclpt.md)|
|[Negação unária](../cpp/unary-plus-and-negation-operators-plus-and.md)|[-](../cpp/unary-plus-and-negation-operators-plus-and.md)|
|[Adição unária](../cpp/unary-plus-and-negation-operators-plus-and.md)|[+](../cpp/unary-plus-and-negation-operators-plus-and.md)|
|[Endereço de](../cpp/address-of-operator-amp.md)|[&amp;](../cpp/address-of-operator-amp.md)|
|[Indireção](../cpp/indirection-operator-star.md)|[&#42;](../cpp/indirection-operator-star.md)|
|[Criar objeto](../cpp/new-operator-cpp.md)|[new](../cpp/new-operator-cpp.md)|
|[Destruir o objeto](../cpp/delete-operator-cpp.md)|[delete](../cpp/delete-operator-cpp.md)|
|[Conversão](../cpp/cast-operator-parens.md)|[()](../cpp/cast-operator-parens.md)|
|**Precedência de grupo 4, da esquerda para direita associatividade**|
|[Ponteiro para membro (objetos ou ponteiros)](../cpp/pointer-to-member-operators-dot-star-and-star.md)|[. &#42; ou ->&#42;](../cpp/pointer-to-member-operators-dot-star-and-star.md)|
|**Precedência do grupo de 5, da esquerda para direita associatividade**|
|[Multiplicação](../cpp/multiplicative-operators-and-the-modulus-operator.md)|[&#42;](../cpp/multiplicative-operators-and-the-modulus-operator.md)|
|[Divisão](../cpp/multiplicative-operators-and-the-modulus-operator.md)|[/](../cpp/multiplicative-operators-and-the-modulus-operator.md)|
|[módulo](../cpp/multiplicative-operators-and-the-modulus-operator.md)|[%](../cpp/multiplicative-operators-and-the-modulus-operator.md)|
|**Precedência do grupo de 6, da esquerda para direita associatividade**|
|[Adição](../cpp/additive-operators-plus-and.md)|[+](../cpp/additive-operators-plus-and.md)|
|[Subtração](../cpp/additive-operators-plus-and.md)|[-](../cpp/additive-operators-plus-and.md)|
|**Precedência do grupo de 7, da esquerda para direita associatividade**|
|[Deslocamento para a esquerda](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|[<<](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|
|[Deslocamento para a direita](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|[>>](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|
|**Precedência do grupo de 8, da esquerda para direita associatividade**|
|[Menor que](../cpp/relational-operators-equal-and-equal.md)|[<](../cpp/relational-operators-equal-and-equal.md)|
|[Maior que](../cpp/relational-operators-equal-and-equal.md)|[>](../cpp/relational-operators-equal-and-equal.md)|
|[Menor ou igual a](../cpp/relational-operators-equal-and-equal.md)|[<=](../cpp/relational-operators-equal-and-equal.md)|
|[Maior ou igual a](../cpp/relational-operators-equal-and-equal.md)|[>=](../cpp/relational-operators-equal-and-equal.md)|
|**Precedência do grupo de 9, da esquerda para direita associatividade**|
|[Igualdade](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|[==](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|
|[Desigualdade](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|[\!=](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|
|**Precedência de grupo 10 da esquerda para direita associatividade**|
|[AND bit a bit](../cpp/bitwise-and-operator-amp.md)|[&amp;](../cpp/bitwise-and-operator-amp.md)|
|**Precedência do grupo de 11, da esquerda para direita associatividade**|
|[Bit a bit OR exclusivo](../cpp/bitwise-exclusive-or-operator-hat.md)|[^](../cpp/bitwise-exclusive-or-operator-hat.md)|
|**Precedência do grupo de 12, da esquerda para direita associatividade**|
|[Bit a bit OR inclusivo](../cpp/bitwise-inclusive-or-operator-pipe.md)|[&#124;](../cpp/bitwise-inclusive-or-operator-pipe.md)|
|**Prioridade de 13, da esquerda para direita associatividade de grupo**|
|[AND lógico](../cpp/logical-and-operator-amp-amp.md)|[&amp;&amp;](../cpp/logical-and-operator-amp-amp.md)|
|**Precedência de grupo 14, da esquerda para direita associatividade**|
|[OR lógico](../cpp/logical-or-operator-pipe-pipe.md)|[&#124;&#124;](../cpp/logical-or-operator-pipe-pipe.md)|
|**Precedência do grupo de 15, da direita para esquerda associatividade**|
|[condicional](../cpp/conditional-operator-q.md)|[? :](../cpp/conditional-operator-q.md)|
|**Precedência do grupo de 16, da direita para esquerda associatividade**|
|[Atribuição](../cpp/assignment-operators.md)|[=](../cpp/assignment-operators.md)|
|[Atribuição de multiplicação](../cpp/assignment-operators.md)|[&#42;=](../cpp/assignment-operators.md)|
|[Atribuição de divisão](../cpp/assignment-operators.md)|[/=](../cpp/assignment-operators.md)|
|[Atribuição de módulo](../cpp/assignment-operators.md)|[%=](../cpp/assignment-operators.md)|
|[Atribuição de adição](../cpp/assignment-operators.md)|[+=](../cpp/assignment-operators.md)|
|[Atribuição de subtração](../cpp/assignment-operators.md)|[-=](../cpp/assignment-operators.md)|
|[Atribuição de shift esquerda](../cpp/assignment-operators.md)|[<<=](../cpp/assignment-operators.md)|
|[Atribuição de deslocamento à direita](../cpp/assignment-operators.md)|[>>=](../cpp/assignment-operators.md)|
|[Atribuição de AND bit a bit](../cpp/assignment-operators.md)|[&amp;=](../cpp/assignment-operators.md)|
|[Bit a bit atribuição OR inclusivo](../cpp/assignment-operators.md)|[&#124;=](../cpp/assignment-operators.md)|
|[Bit a bit atribuição OR exclusivo](../cpp/assignment-operators.md)|[^=](../cpp/assignment-operators.md)|
|**Precedência do grupo de 17, da direita para esquerda associatividade**|
|[expressão Throw](../cpp/try-throw-and-catch-statements-cpp.md)|[throw](../cpp/try-throw-and-catch-statements-cpp.md)|
|**Precedência do grupo de 18, da esquerda para direita associatividade**|
|[Vírgula](../cpp/comma-operator.md)|[,](../cpp/comma-operator.md)|

## <a name="see-also"></a>Consulte também

[Sobrecarga de Operador](operator-overloading.md)