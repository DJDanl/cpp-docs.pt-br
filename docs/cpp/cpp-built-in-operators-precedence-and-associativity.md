---
title: Operadores C++ internos, precedência e associatividade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
dev_langs:
- C++
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
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 95cbb68740fe43fa8a76624abb57284cb68e7805
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-built-in-operators-precedence-and-associativity"></a>Operadores C++ internos, precedência e capacidade de associação

A linguagem C++ inclui todos os operadores C e adiciona vários operadores novos. Os operadores especificam uma avaliação a ser executada em um ou mais operandos.

Operador *precedência* Especifica a ordem das operações em expressões que contêm mais de um operador. Operador *associatividade* Especifica se, em uma expressão que contém vários operadores com a mesma precedência, um operando é agrupado com a sua esquerda ou à direita. A tabela a seguir mostra a precedência e a associatividade dos operadores C++ (da precedência mais alta a mais baixa). Os operadores com o mesmo número de precedência têm igual precedência, a menos que outra relação seja explicitamente forçada por parênteses.

### <a name="c-operator-precedence-and-associativity"></a>Associatividade e precedência do operador C++

|Descrição do operador|Operador|
|--------------------------|--------------|
|**Precedência de 1, nenhuma associação de grupo**|
|[Resolução do escopo](../cpp/scope-resolution-operator.md)|[::](../cpp/scope-resolution-operator.md)|
|**Precedência de grupo 2, da esquerda para direita associatividade**|
|[Seleção de membro (objeto ou ponteiro)](../cpp/member-access-operators-dot-and.md)|[. ou ->](../cpp/member-access-operators-dot-and.md)|
|[Subscrito da matriz](../cpp/subscript-operator.md)|[&#91;&#93;](../cpp/subscript-operator.md)|
|[Chamada de função](../cpp/function-call-operator-parens.md)|[()](../cpp/function-call-operator-parens.md)|
|[Operadores de incremento](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|[++](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|
|[Operadores de decremento](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|[--](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|
|[Nome do tipo](../cpp/typeid-operator.md)|[TypeId](../cpp/typeid-operator.md)|
|[Conversão de tipo de constante](../cpp/const-cast-operator.md)|[const_cast](../cpp/const-cast-operator.md)|
|[Conversão de tipo dinâmico](../cpp/dynamic-cast-operator.md)|[dynamic_cast](../cpp/dynamic-cast-operator.md)|
|[Conversão de tipo reinterpretados](../cpp/reinterpret-cast-operator.md)|[reinterpret_cast](../cpp/reinterpret-cast-operator.md)|
|[Conversão de tipo estático](../cpp/static-cast-operator.md)|[static_cast](../cpp/static-cast-operator.md)|
|**Precedência de grupo 3, da direita para esquerda associatividade**|
|[Tamanho do objeto ou tipo](../cpp/sizeof-operator.md)|[sizeof](../cpp/sizeof-operator.md)|
|[Incremento de prefixo](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|[++](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|
|[Decremento de prefixo](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|[--](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|
|[Complemento de um](../cpp/one-s-complement-operator-tilde.md)|[~](../cpp/one-s-complement-operator-tilde.md)|
|[Não lógico](../cpp/logical-negation-operator-exclpt.md)|[!](../cpp/logical-negation-operator-exclpt.md)|
|[Negação unária](../cpp/unary-plus-and-negation-operators-plus-and.md)|[-](../cpp/unary-plus-and-negation-operators-plus-and.md)|
|[Adição unária](../cpp/unary-plus-and-negation-operators-plus-and.md)|[+](../cpp/unary-plus-and-negation-operators-plus-and.md)|
|[Endereço de rede](../cpp/address-of-operator-amp.md)|[&amp;](../cpp/address-of-operator-amp.md)|
|[Inversão de controle](../cpp/indirection-operator-star.md)|[&#42;](../cpp/indirection-operator-star.md)|
|[Criar objeto](../cpp/new-operator-cpp.md)|[new](../cpp/new-operator-cpp.md)|
|[Destruir o objeto](../cpp/delete-operator-cpp.md)|[delete](../cpp/delete-operator-cpp.md)|
|[Conversão](../cpp/cast-operator-parens.md)|[()](../cpp/cast-operator-parens.md)|
|**Precedência de grupo 4, da esquerda para direita associatividade**|
|[Ponteiro para membro (objetos ou ponteiros)](../cpp/pointer-to-member-operators-dot-star-and-star.md)|[. &#42; ou -> &#42;](../cpp/pointer-to-member-operators-dot-star-and-star.md)|
|**Precedência de grupo de 5, da esquerda para direita associatividade**|
|[Multiplicação](../cpp/multiplicative-operators-and-the-modulus-operator.md)|[&#42;](../cpp/multiplicative-operators-and-the-modulus-operator.md)|
|[Divisão](../cpp/multiplicative-operators-and-the-modulus-operator.md)|[/](../cpp/multiplicative-operators-and-the-modulus-operator.md)|
|[Módulo](../cpp/multiplicative-operators-and-the-modulus-operator.md)|[%](../cpp/multiplicative-operators-and-the-modulus-operator.md)|
|**6 prioridade, da esquerda para direita associação de grupo**|
|[Adição](../cpp/additive-operators-plus-and.md)|[+](../cpp/additive-operators-plus-and.md)|
|[Subtração](../cpp/additive-operators-plus-and.md)|[-](../cpp/additive-operators-plus-and.md)|
|**Prioridade de 7, da esquerda para direita associação de grupo**|
|[Deslocamento para a esquerda](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|[<<](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|
|[Deslocamento para a direita](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|[>>](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|
|**8 prioridade, da esquerda para direita associação de grupo**|
|[Menor que](../cpp/relational-operators-equal-and-equal.md)|[<](../cpp/relational-operators-equal-and-equal.md)|
|[Maior que](../cpp/relational-operators-equal-and-equal.md)|[>](../cpp/relational-operators-equal-and-equal.md)|
|[Menor ou igual a](../cpp/relational-operators-equal-and-equal.md)|[<=](../cpp/relational-operators-equal-and-equal.md)|
|[Maior ou igual a](../cpp/relational-operators-equal-and-equal.md)|[>=](../cpp/relational-operators-equal-and-equal.md)|
|**Prioridade 9, da esquerda para direita associação de grupo**|
|[Igualdade](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|[==](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|
|[Desigualdade](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|[!=](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|
|**Precedência de grupo 10 da esquerda para direita associatividade**|
|[AND bit a bit](../cpp/bitwise-and-operator-amp.md)|[&amp;](../cpp/bitwise-and-operator-amp.md)|
|**Prioridade de 11, da esquerda para direita associação de grupo**|
|[Bit a bit OR exclusivo](../cpp/bitwise-exclusive-or-operator-hat.md)|[^](../cpp/bitwise-exclusive-or-operator-hat.md)|
|**12 prioridade, da esquerda para direita associação de grupo**|
|[Bit a bit OR inclusivo](../cpp/bitwise-inclusive-or-operator-pipe.md)|[&#124;](../cpp/bitwise-inclusive-or-operator-pipe.md)|
|**Prioridade de 13, da esquerda para direita associação de grupo**|
|[AND lógico](../cpp/logical-and-operator-amp-amp.md)|[&amp;&amp;](../cpp/logical-and-operator-amp-amp.md)|
|**Precedência de grupo 14, da esquerda para direita associatividade**|
|[OR lógico](../cpp/logical-or-operator-pipe-pipe.md)|[&#124;&#124;](../cpp/logical-or-operator-pipe-pipe.md)|
|**Precedência de grupo 15, da direita para esquerda associatividade**|
|[Condicional](../cpp/conditional-operator-q.md)|[? :](../cpp/conditional-operator-q.md)|
|**16 prioridade, da direita para esquerda associação de grupo**|
|[Atribuição](../cpp/assignment-operators.md)|[=](../cpp/assignment-operators.md)|
|[Atribuição de multiplicação](../cpp/assignment-operators.md)|[&#42;=](../cpp/assignment-operators.md)|
|[Atribuição de divisão](../cpp/assignment-operators.md)|[/=](../cpp/assignment-operators.md)|
|[Atribuição de módulo](../cpp/assignment-operators.md)|[%=](../cpp/assignment-operators.md)|
|[Atribuição de adição](../cpp/assignment-operators.md)|[+=](../cpp/assignment-operators.md)|
|[Atribuição de subtração](../cpp/assignment-operators.md)|[-=](../cpp/assignment-operators.md)|
|[Atribuição Left shift](../cpp/assignment-operators.md)|[<<=](../cpp/assignment-operators.md)|
|[Atribuição Right-shift](../cpp/assignment-operators.md)|[>>=](../cpp/assignment-operators.md)|
|[Atribuição AND bit a bit](../cpp/assignment-operators.md)|[&amp;=](../cpp/assignment-operators.md)|
|[Bit a bit a atribuição OR inclusiva](../cpp/assignment-operators.md)|[&#124;=](../cpp/assignment-operators.md)|
|[Bit a bit a atribuição OR exclusiva](../cpp/assignment-operators.md)|[^=](../cpp/assignment-operators.md)|
|**17 prioridade, da direita para esquerda associação de grupo**|
|[gerar a expressão](../cpp/try-throw-and-catch-statements-cpp.md)|[throw](../cpp/try-throw-and-catch-statements-cpp.md)|
|**18 prioridade, da esquerda para direita associação de grupo**|
|[Vírgula](../cpp/comma-operator.md)|[,](../cpp/comma-operator.md)|

## <a name="see-also"></a>Consulte também

[Sobrecarga de Operador](operator-overloading.md)


