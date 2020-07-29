---
title: Operadores, precedência e Associação internos do C++
ms.date: 07/23/2020
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
ms.openlocfilehash: 10c9e5db569ba211ed8d42386816b4f6bb71ee29
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221764"
---
# <a name="c-built-in-operators-precedence-and-associativity"></a>Operadores, precedência e Associação internos do C++

A linguagem C++ inclui todos os operadores C e adiciona vários operadores novos. Os operadores especificam uma avaliação a ser executada em um ou mais operandos.

## <a name="precedence-and-associativity"></a>Precedência e Associação

*Precedência* de operador especifica a ordem das operações em expressões que contêm mais de um operador. A *Associação* de operador especifica se, em uma expressão que contém vários operadores com a mesma precedência, um operando é agrupado com aquele à esquerda ou aquele à direita.

## <a name="alternative-spellings"></a>Ortografias alternativas

O C++ especifica grafias alternativas para alguns operadores. Em C, as grafias alternativas são fornecidas como macros no \<iso646.h> cabeçalho. Em C++, essas alternativas são palavras-chave e o uso do \<iso646.h> ou do equivalente em C++ \<ciso646> é preterido. No Microsoft C++, a [`/permissive-`](../build/reference/permissive-standards-conformance.md) opção ou do [`/Za`](../build/reference/za-ze-disable-language-extensions.md) compilador é necessária para habilitar as grafias alternativas.

## <a name="c-operator-precedence-and-associativity-table"></a>Tabela de precedência de operador C++ e Associação

A tabela a seguir mostra a precedência e a associatividade dos operadores C++ (da precedência mais alta a mais baixa). Os operadores com o mesmo número de precedência têm igual precedência, a menos que outra relação seja explicitamente forçada por parênteses.

| Descrição do operador | Operador | Alternativa |
|--|--|--|
| **Precedência de grupo 1, sem Associação** |
| [Resolução de escopo](../cpp/scope-resolution-operator.md) | [`::`](../cpp/scope-resolution-operator.md) |
| **Prioridade do grupo 2, associação da esquerda para a direita** |
| [Seleção de membro (objeto ou ponteiro)](../cpp/member-access-operators-dot-and.md) | [`.`or`->`](../cpp/member-access-operators-dot-and.md) |
| [Subscrito de matriz](../cpp/subscript-operator.md) | [`[]`](../cpp/subscript-operator.md) |
| [Chamada de função](../cpp/function-call-operator-parens.md) | [`()`](../cpp/function-call-operator-parens.md) |
| [Incremento de sufixo](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md) | [`++`](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md) |
| [Decremento de sufixo](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md) | [`--`](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md) |
| [Nome do tipo](../cpp/typeid-operator.md) | [`typeid`](../cpp/typeid-operator.md) |
| [Conversão de tipo constante](../cpp/const-cast-operator.md) | [`const_cast`](../cpp/const-cast-operator.md) |
| [Conversão de tipo dinâmico](../cpp/dynamic-cast-operator.md) | [`dynamic_cast`](../cpp/dynamic-cast-operator.md) |
| [Conversão de tipo reinterpretado](../cpp/reinterpret-cast-operator.md) | [`reinterpret_cast`](../cpp/reinterpret-cast-operator.md) |
| [Conversão de tipo estático](../cpp/static-cast-operator.md) | [`static_cast`](../cpp/static-cast-operator.md) |
| **Prioridade do grupo 3, associação direita à esquerda** |
| [Tamanho do objeto ou tipo](../cpp/sizeof-operator.md) | [`sizeof`](../cpp/sizeof-operator.md) |
| [Incremento de prefixo](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md) | [`++`](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md) |
| [Decremento de prefixo](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md) | [`--`](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md) |
| [Complemento de um](../cpp/one-s-complement-operator-tilde.md) | [`~`](../cpp/one-s-complement-operator-tilde.md) | **`compl`** |
| [Não lógico](../cpp/logical-negation-operator-exclpt.md) | [`!`](../cpp/logical-negation-operator-exclpt.md) | **`not`** |
| [Negação unária](../cpp/unary-plus-and-negation-operators-plus-and.md) | [`-`](../cpp/unary-plus-and-negation-operators-plus-and.md) |
| [Adição de unário](../cpp/unary-plus-and-negation-operators-plus-and.md) | [`+`](../cpp/unary-plus-and-negation-operators-plus-and.md) |
| [Address-of](../cpp/address-of-operator-amp.md) | [`&`](../cpp/address-of-operator-amp.md) |
| [Indireção](../cpp/indirection-operator-star.md) | [`*`](../cpp/indirection-operator-star.md) |
| [Criar objeto](../cpp/new-operator-cpp.md) | [`new`](../cpp/new-operator-cpp.md) |
| [Objeto Destroy](../cpp/delete-operator-cpp.md) | [`delete`](../cpp/delete-operator-cpp.md) |
| [Vertida](../cpp/cast-operator-parens.md) | [`()`](../cpp/cast-operator-parens.md) |
| **Prioridade do grupo 4, associação da esquerda para a direita** |
| [Ponteiro para membro (objetos ou ponteiros)](../cpp/pointer-to-member-operators-dot-star-and-star.md) | [`.*`or`->*`](../cpp/pointer-to-member-operators-dot-star-and-star.md) |
| **Prioridade do grupo 5, associação da esquerda para a direita** |
| [Multiplicação](../cpp/multiplicative-operators-and-the-modulus-operator.md) | [`*`](../cpp/multiplicative-operators-and-the-modulus-operator.md) |
| [Divisão](../cpp/multiplicative-operators-and-the-modulus-operator.md) | [`/`](../cpp/multiplicative-operators-and-the-modulus-operator.md) |
| [Modulus](../cpp/multiplicative-operators-and-the-modulus-operator.md) | [`%`](../cpp/multiplicative-operators-and-the-modulus-operator.md) |
| **Prioridade do grupo 6, associação da esquerda para a direita** |
| [Adição](../cpp/additive-operators-plus-and.md) | [`+`](../cpp/additive-operators-plus-and.md) |
| [Subtração](../cpp/additive-operators-plus-and.md) | [`-`](../cpp/additive-operators-plus-and.md) |
| **Prioridade do grupo 7, associação da esquerda para a direita** |
| [Deslocamento à esquerda](../cpp/left-shift-and-right-shift-operators-input-and-output.md) | [`<<`](../cpp/left-shift-and-right-shift-operators-input-and-output.md) |
| [Deslocamento à direita](../cpp/left-shift-and-right-shift-operators-input-and-output.md) | [`>>`](../cpp/left-shift-and-right-shift-operators-input-and-output.md) |
| **Prioridade do grupo 8, associação da esquerda para a direita** |
| [Menor que](../cpp/relational-operators-equal-and-equal.md) | [`<`](../cpp/relational-operators-equal-and-equal.md) |
| [Maior que](../cpp/relational-operators-equal-and-equal.md) | [`>`](../cpp/relational-operators-equal-and-equal.md) |
| [Menor ou igual a](../cpp/relational-operators-equal-and-equal.md) | [`<=`](../cpp/relational-operators-equal-and-equal.md) |
| [Maior ou igual a](../cpp/relational-operators-equal-and-equal.md) | [`>=`](../cpp/relational-operators-equal-and-equal.md) |
| **Prioridade do grupo 9, associação da esquerda para a direita** |
| [Igualitário](../cpp/equality-operators-equal-equal-and-exclpt-equal.md) | [`==`](../cpp/equality-operators-equal-equal-and-exclpt-equal.md) |
| [Desigualdade](../cpp/equality-operators-equal-equal-and-exclpt-equal.md) | [`!=`](../cpp/equality-operators-equal-equal-and-exclpt-equal.md) | **`not_eq`** |
| **Prioridade do grupo 10 esquerda para direita** |
| [AND bit a bit](../cpp/bitwise-and-operator-amp.md) | [`&`](../cpp/bitwise-and-operator-amp.md) | **`bitand`** |
| **Prioridade do grupo 11, associação da esquerda para a direita** |
| [OR exclusivo bit a bit](../cpp/bitwise-exclusive-or-operator-hat.md) | [`^`](../cpp/bitwise-exclusive-or-operator-hat.md) | **`xor`** |
| **Prioridade do grupo 12, da esquerda para a direita** |
| [OR inclusivo bit a bit](../cpp/bitwise-inclusive-or-operator-pipe.md) | [`|`](../cpp/bitwise-inclusive-or-operator-pipe.md) | **`bitor`** |
| **Prioridade do grupo 13, da esquerda para a direita** |
| [AND lógico](../cpp/logical-and-operator-amp-amp.md) | [`&&`](../cpp/logical-and-operator-amp-amp.md) | **`and`** |
| **Prioridade do grupo 14, associação da esquerda para a direita** |
| [OR lógico](../cpp/logical-or-operator-pipe-pipe.md) | [`||`](../cpp/logical-or-operator-pipe-pipe.md) | **`or`** |
| **Prioridade do grupo 15, associação direita à esquerda** |
| [Condicional](../cpp/conditional-operator-q.md) | [`? :`](../cpp/conditional-operator-q.md) |
| **Associação de grupo 16, prioridade direita para esquerda** |
| [Atribuição](../cpp/assignment-operators.md) | [`=`](../cpp/assignment-operators.md) |
| [Atribuição de multiplicação](../cpp/assignment-operators.md) | [`*=`](../cpp/assignment-operators.md) |
| [Atribuição de divisão](../cpp/assignment-operators.md) | [`/=`](../cpp/assignment-operators.md) |
| [Atribuição de módulo](../cpp/assignment-operators.md) | [`%=`](../cpp/assignment-operators.md) |
| [Atribuição de adição](../cpp/assignment-operators.md) | [`+=`](../cpp/assignment-operators.md) |
| [Atribuição de subtração](../cpp/assignment-operators.md) | [`-=`](../cpp/assignment-operators.md) |
| [Atribuição de shift esquerda](../cpp/assignment-operators.md) | [`<<=`](../cpp/assignment-operators.md) |
| [Atribuição de shift direita](../cpp/assignment-operators.md) | [`>>=`](../cpp/assignment-operators.md) |
| [Atribuição AND de bit a bit](../cpp/assignment-operators.md) | [`&=`](../cpp/assignment-operators.md) | **`and_eq`** |
| [Atribuição OR inclusivo de bit a bit](../cpp/assignment-operators.md) | [`|=`](../cpp/assignment-operators.md) | **`or_eq`** |
| [Atribuição OR exclusivo de bit a bit](../cpp/assignment-operators.md) | [`^=`](../cpp/assignment-operators.md) | **`xor_eq`** |
| **Prioridade de grupo 17, associação direita para esquerda** |
| [expressão de lançamento](../cpp/try-throw-and-catch-statements-cpp.md) | [`throw`](../cpp/try-throw-and-catch-statements-cpp.md) |
| **Prioridade de grupo 18, associação da esquerda para a direita** |
| [Pontos](../cpp/comma-operator.md) | [,](../cpp/comma-operator.md) |

## <a name="see-also"></a>Confira também

[Sobrecarga de operador](operator-overloading.md)
