---
title: Expressões com operadores unários
ms.date: 11/04/2016
helpviewer_keywords:
- expressions [C++], unary operators
- unary operators [C++], expressions with
- expressions [C++], operators
ms.assetid: 1217685b-b85d-4b48-9ff4-d90f56a26c1b
ms.openlocfilehash: 26aad64e5b9c7a496c2e6bb131b82740c06abe07
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188968"
---
# <a name="expressions-with-unary-operators"></a>Expressões com operadores unários

Os operadores unários atuam somente em um operando em uma expressão. Os operadores unários são os seguintes:

- [Operador de indireção (*)](../cpp/indirection-operator-star.md)

- [Operador de endereço (&)](../cpp/address-of-operator-amp.md)

- [Operador de adição unário (+)](../cpp/unary-plus-and-negation-operators-plus-and.md)

- [Operador de negação unário (-)](../cpp/unary-plus-and-negation-operators-plus-and.md)

- [Operador de negação lógica (!)](../cpp/logical-negation-operator-exclpt.md)

- [Operador de complemento de um (~)](../cpp/one-s-complement-operator-tilde.md)

- [Operador de incremento de prefixo (+ +)](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)

- [Operador de diminuição de prefixo (--)](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)

- [Operador cast ()](../cpp/cast-operator-parens.md)

- [Operador sizeof](../cpp/sizeof-operator.md)

- [operador de __uuidof](../cpp/uuidof-operator.md)

- [operador de __alignof](../cpp/alignof-operator.md)

- [novo operador](../cpp/new-operator-cpp.md)

- [Excluir operador](../cpp/delete-operator-cpp.md)

Esses operadores binários possuem associatividade da direita para a esquerda. As expressões unárias geralmente envolvem a sintaxe que precede uma expressão de sufixo ou primária.

As formas possíveis de expressões unárias são estas:

- *postfix-expression*

- `++` *expressão unário*

- `--` *expressão unário*

- *expressão de conversão* de *operador unário*

- expressão **sizeof** *unário*

- *nome do tipo de* `sizeof(` `)`

- *expressão* de `decltype(` `)`

- *expressão de alocação*

- *expressão de desalocação*

Qualquer *expressão de sufixo* é considerada uma *expressão unário*e, como qualquer expressão primária é considerada uma *expressão de sufixo*, todas as expressões primárias também são consideradas uma *expressão unário* . Para obter mais informações, consulte [expressões de sufixo](../cpp/postfix-expressions.md) e [expressões primárias](../cpp/primary-expressions.md).

Um *operador unário* consiste em um ou mais dos seguintes símbolos: `* & + - ! ~`

A *expressão CAST* é uma expressão unário com uma conversão opcional para alterar o tipo. Para obter mais informações, consulte [operador de conversão: ()](../cpp/cast-operator-parens.md).

Uma *expressão* pode ser qualquer expressão. Para obter mais informações, consulte [expressões](../cpp/expressions-cpp.md).

A *expressão de alocação refere-* se ao operador **New** . A *expressão de desalocação* se refere ao operador **delete** . Para obter mais informações, consulte os links anteriores deste tópico.

## <a name="see-also"></a>Confira também

[Tipos de expressões](../cpp/types-of-expressions.md)
