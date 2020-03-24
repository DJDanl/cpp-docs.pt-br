---
title: C++Operadores internos, precedência e Associação
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
ms.openlocfilehash: 36e7ce77e24366be10b75f5bb4f8830363594301
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180401"
---
# <a name="c-built-in-operators-precedence-and-associativity"></a>C++Operadores internos, precedência e Associação

A linguagem C++ inclui todos os operadores C e adiciona vários operadores novos. Os operadores especificam uma avaliação a ser executada em um ou mais operandos.

*Precedência* de operador especifica a ordem das operações em expressões que contêm mais de um operador. A *Associação* de operador especifica se, em uma expressão que contém vários operadores com a mesma precedência, um operando é agrupado com aquele à esquerda ou aquele à direita. A tabela a seguir mostra a precedência e a associatividade dos operadores C++ (da precedência mais alta a mais baixa). Os operadores com o mesmo número de precedência têm igual precedência, a menos que outra relação seja explicitamente forçada por parênteses.

### <a name="c-operator-precedence-and-associativity"></a>Associatividade e precedência do operador C++

|Descrição do operador|Operador|
|--------------------------|--------------|
|**Precedência de grupo 1, sem Associação**|
|[Resolução de escopo](../cpp/scope-resolution-operator.md)|[::](../cpp/scope-resolution-operator.md)|
|**Prioridade do grupo 2, associação da esquerda para a direita**|
|[Seleção de membro (objeto ou ponteiro)](../cpp/member-access-operators-dot-and.md)|[. ou->](../cpp/member-access-operators-dot-and.md)|
|[Subscrito de matriz](../cpp/subscript-operator.md)|[&#91;&#93;](../cpp/subscript-operator.md)|
|[Chamada de função](../cpp/function-call-operator-parens.md)|[()](../cpp/function-call-operator-parens.md)|
|[Incremento de sufixo](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|[++](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|
|[Decrementar sufixo](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|[--](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|
|[Nome do tipo](../cpp/typeid-operator.md)|[typeid](../cpp/typeid-operator.md)|
|[Conversão de tipo constante](../cpp/const-cast-operator.md)|[const_cast](../cpp/const-cast-operator.md)|
|[Conversão de tipo dinâmico](../cpp/dynamic-cast-operator.md)|[dynamic_cast](../cpp/dynamic-cast-operator.md)|
|[Conversão de tipo reinterpretad](../cpp/reinterpret-cast-operator.md)|[reinterpret_cast](../cpp/reinterpret-cast-operator.md)|
|[Conversão de tipo estático](../cpp/static-cast-operator.md)|[static_cast](../cpp/static-cast-operator.md)|
|**Prioridade do grupo 3, associação direita à esquerda**|
|[Tamanho do objeto ou tipo](../cpp/sizeof-operator.md)|[sizeof](../cpp/sizeof-operator.md)|
|[Incremento de prefixo](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|[++](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|
|[Diminuir prefixo](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|[--](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)|
|[Complemento de um](../cpp/one-s-complement-operator-tilde.md)|[~](../cpp/one-s-complement-operator-tilde.md)|
|[Não lógico](../cpp/logical-negation-operator-exclpt.md)|[!](../cpp/logical-negation-operator-exclpt.md)|
|[Negação unária](../cpp/unary-plus-and-negation-operators-plus-and.md)|[-](../cpp/unary-plus-and-negation-operators-plus-and.md)|
|[Adição de unário](../cpp/unary-plus-and-negation-operators-plus-and.md)|[+](../cpp/unary-plus-and-negation-operators-plus-and.md)|
|[Endereço-de](../cpp/address-of-operator-amp.md)|[&amp;](../cpp/address-of-operator-amp.md)|
|[Indireção](../cpp/indirection-operator-star.md)|[&#42;](../cpp/indirection-operator-star.md)|
|[Criar objeto](../cpp/new-operator-cpp.md)|[novo](../cpp/new-operator-cpp.md)|
|[Destruir objeto](../cpp/delete-operator-cpp.md)|[delete](../cpp/delete-operator-cpp.md)|
|[Converter](../cpp/cast-operator-parens.md)|[()](../cpp/cast-operator-parens.md)|
|**Prioridade do grupo 4, associação da esquerda para a direita**|
|[Ponteiro para membro (objetos ou ponteiros)](../cpp/pointer-to-member-operators-dot-star-and-star.md)|[. &#42; ou->&#42;](../cpp/pointer-to-member-operators-dot-star-and-star.md)|
|**Prioridade do grupo 5, associação da esquerda para a direita**|
|[Multiplicação](../cpp/multiplicative-operators-and-the-modulus-operator.md)|[&#42;](../cpp/multiplicative-operators-and-the-modulus-operator.md)|
|[Divisão](../cpp/multiplicative-operators-and-the-modulus-operator.md)|[/](../cpp/multiplicative-operators-and-the-modulus-operator.md)|
|[Igual](../cpp/multiplicative-operators-and-the-modulus-operator.md)|[%](../cpp/multiplicative-operators-and-the-modulus-operator.md)|
|**Prioridade do grupo 6, associação da esquerda para a direita**|
|[Adição](../cpp/additive-operators-plus-and.md)|[+](../cpp/additive-operators-plus-and.md)|
|[Subtração](../cpp/additive-operators-plus-and.md)|[-](../cpp/additive-operators-plus-and.md)|
|**Prioridade do grupo 7, associação da esquerda para a direita**|
|[Deslocamento à esquerda](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|[<<](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|
|[Deslocamento à direita](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|[>>](../cpp/left-shift-and-right-shift-operators-input-and-output.md)|
|**Prioridade do grupo 8, associação da esquerda para a direita**|
|[Menor que](../cpp/relational-operators-equal-and-equal.md)|[<](../cpp/relational-operators-equal-and-equal.md)|
|[Maior que](../cpp/relational-operators-equal-and-equal.md)|[>](../cpp/relational-operators-equal-and-equal.md)|
|[Menor ou igual a](../cpp/relational-operators-equal-and-equal.md)|[<=](../cpp/relational-operators-equal-and-equal.md)|
|[Maior ou igual a](../cpp/relational-operators-equal-and-equal.md)|[>=](../cpp/relational-operators-equal-and-equal.md)|
|**Prioridade do grupo 9, associação da esquerda para a direita**|
|[Igualdade](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|[==](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|
|[Desigualdade](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|[!=](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)|
|**Prioridade do grupo 10 esquerda para direita**|
|[AND bit a bit](../cpp/bitwise-and-operator-amp.md)|[&amp;](../cpp/bitwise-and-operator-amp.md)|
|**Prioridade do grupo 11, associação da esquerda para a direita**|
|[Or exclusivo de or](../cpp/bitwise-exclusive-or-operator-hat.md)|[^](../cpp/bitwise-exclusive-or-operator-hat.md)|
|**Prioridade do grupo 12, da esquerda para a direita**|
|[Bit inclusivo ou](../cpp/bitwise-inclusive-or-operator-pipe.md)|[&#124;](../cpp/bitwise-inclusive-or-operator-pipe.md)|
|**Prioridade do grupo 13, da esquerda para a direita**|
|[AND lógico](../cpp/logical-and-operator-amp-amp.md)|[&amp;&amp;](../cpp/logical-and-operator-amp-amp.md)|
|**Prioridade do grupo 14, associação da esquerda para a direita**|
|[OR lógico](../cpp/logical-or-operator-pipe-pipe.md)|[&#124;&#124;](../cpp/logical-or-operator-pipe-pipe.md)|
|**Prioridade do grupo 15, associação direita à esquerda**|
|[Condiciona](../cpp/conditional-operator-q.md)|[? :](../cpp/conditional-operator-q.md)|
|**Associação de grupo 16, prioridade direita para esquerda**|
|[Atribuição](../cpp/assignment-operators.md)|[=](../cpp/assignment-operators.md)|
|[Atribuição de multiplicação](../cpp/assignment-operators.md)|[&#42;=](../cpp/assignment-operators.md)|
|[Atribuição de divisão](../cpp/assignment-operators.md)|[/=](../cpp/assignment-operators.md)|
|[Atribuição de módulo](../cpp/assignment-operators.md)|[%=](../cpp/assignment-operators.md)|
|[Atribuição de adição](../cpp/assignment-operators.md)|[+=](../cpp/assignment-operators.md)|
|[Atribuição de subtração](../cpp/assignment-operators.md)|[-=](../cpp/assignment-operators.md)|
|[Atribuição de deslocamento para a esquerda](../cpp/assignment-operators.md)|[<<=](../cpp/assignment-operators.md)|
|[Atribuição de SHIFT direita](../cpp/assignment-operators.md)|[>>=](../cpp/assignment-operators.md)|
|[Atribuição de e/bit](../cpp/assignment-operators.md)|[&amp;=](../cpp/assignment-operators.md)|
|[Atribuição ou inclusão de bits](../cpp/assignment-operators.md)|[&#124;=](../cpp/assignment-operators.md)|
|[Atribuição or exclusiva](../cpp/assignment-operators.md)|[^=](../cpp/assignment-operators.md)|
|**Prioridade de grupo 17, associação direita para esquerda**|
|[expressão throw](../cpp/try-throw-and-catch-statements-cpp.md)|[throw](../cpp/try-throw-and-catch-statements-cpp.md)|
|**Prioridade de grupo 18, associação da esquerda para a direita**|
|[Vírgula](../cpp/comma-operator.md)|[,](../cpp/comma-operator.md)|

## <a name="see-also"></a>Confira também

[Sobrecarga de Operador](operator-overloading.md)
