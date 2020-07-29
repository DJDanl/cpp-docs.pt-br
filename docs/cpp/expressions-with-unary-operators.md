---
title: Expressões com operadores unários
ms.date: 11/04/2016
helpviewer_keywords:
- expressions [C++], unary operators
- unary operators [C++], expressions with
- expressions [C++], operators
ms.assetid: 1217685b-b85d-4b48-9ff4-d90f56a26c1b
ms.openlocfilehash: 032ebd99041de9308d16710b2a27e0db3cddd4df
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233750"
---
# <a name="expressions-with-unary-operators"></a>Expressões com operadores unários

Os operadores unários atuam somente em um operando em uma expressão. Os operadores unários são os seguintes:

- [Operador de indireção (*)](../cpp/indirection-operator-star.md)

- [Operador de endereço (&)](../cpp/address-of-operator-amp.md)

- [Operador unário de adição (+)](../cpp/unary-plus-and-negation-operators-plus-and.md)

- [Operador de negação unário (-)](../cpp/unary-plus-and-negation-operators-plus-and.md)

- [Operador de negação lógica (!)](../cpp/logical-negation-operator-exclpt.md)

- [Operador de complemento de um (~)](../cpp/one-s-complement-operator-tilde.md)

- [Operador de incremento de prefixo (++)](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)

- [Operador de diminuição de prefixo (--)](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)

- [Operador cast ()](../cpp/cast-operator-parens.md)

- [`sizeof`operador](../cpp/sizeof-operator.md)

- [`__uuidof`operador](../cpp/uuidof-operator.md)

- [`alignof`operador](../cpp/alignof-operator.md)

- [`new`operador](../cpp/new-operator-cpp.md)

- [`delete`operador](../cpp/delete-operator-cpp.md)

Esses operadores binários possuem associatividade da direita para a esquerda. As expressões unárias geralmente envolvem a sintaxe que precede uma expressão de sufixo ou primária.

As formas possíveis de expressões unárias são estas:

- *postfix-expression*

- `++` *expressão-unária*

- `--` *expressão-unária*

- *expressão de conversão* de *operador unário*

- **`sizeof`***expressão unário*

- `sizeof(`*nome do tipo*`)`

- `decltype(`*expressão* de`)`

- *expressão de alocação*

- *expressão de desalocação*

Qualquer *expressão de sufixo* é considerada uma *expressão unário*e, como qualquer expressão primária é considerada uma *expressão de sufixo*, todas as expressões primárias também são consideradas uma *expressão unário* . Para obter mais informações, consulte [expressões de sufixo](../cpp/postfix-expressions.md) e [expressões primárias](../cpp/primary-expressions.md).

Um *operador unário* consiste em um ou mais dos seguintes símbolos:`* & + - ! ~`

A *expressão CAST* é uma expressão unário com uma conversão opcional para alterar o tipo. Para obter mais informações, consulte [operador de conversão: ()](../cpp/cast-operator-parens.md).

Uma *expressão* pode ser qualquer expressão. Para obter mais informações, consulte [expressões](../cpp/expressions-cpp.md).

A *expressão de alocação* refere-se ao **`new`** operador. A *expressão de desalocação* se refere ao **`delete`** operador. Para obter mais informações, consulte os links anteriores deste tópico.

## <a name="see-also"></a>Confira também

[Tipos de expressões](../cpp/types-of-expressions.md)
