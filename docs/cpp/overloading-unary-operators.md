---
title: Operadores unários de sobrecarga
ms.date: 11/04/2016
helpviewer_keywords:
- unary operators [C++], plus
- increment operators [C++], overloaded
- unary operators [C++], minus
- operators [C++], unary
- redefinable unary operators [C++]
- unary operators [C++]
- pointer dereference operator overloading
- plus operator
ms.assetid: 7683ef08-42a4-4283-928f-d3dd4f3ab4c0
ms.openlocfilehash: a21c62549f02dddda951c79a06617671ccfe2526
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227212"
---
# <a name="overloading-unary-operators"></a>Operadores unários de sobrecarga

Os operadores unários que podem ser sobrecarregados são os seguintes:

1. `!`([não lógico](../cpp/logical-negation-operator-exclpt.md))

1. `&`([endereço](../cpp/address-of-operator-amp.md))

1. `~`([complemento de um](../cpp/one-s-complement-operator-tilde.md))

1. `*`([desreferência do ponteiro](../cpp/indirection-operator-star.md))

1. `+`([mais unário](../cpp/additive-operators-plus-and.md))

1. `-`([negação unário](../cpp/additive-operators-plus-and.md))

1. `++`([incremento](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md))

1. `--`([decrementar](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md))

1. operadores de conversão

Os operadores de incremento e decréscimo de sufixo ( `++` e `--` ) são tratados separadamente em [incrementos e decremento](../cpp/increment-and-decrement-operator-overloading-cpp.md).

Os operadores de conversão também são discutidos em um tópico separado; Confira [conversões de tipo definidas pelo usuário](../cpp/user-defined-type-conversions-cpp.md).

As regras a seguir são verdadeiras para todos os outros operadores unários. Para declarar uma função de operador unário como um membro não estático, você deve declará-la na forma:

> *RET-tipo* **`operator`** *op* **()**

em que *RET-Type* é o tipo de retorno e *op* é um dos operadores listados na tabela anterior.

Para declarar uma função de operador unário como uma função global, você deve declará-la na forma:

> *RET-tipo* **`operator`** *op* **(** *ARG* **)**

em que *RET-Type* e *op* são os descritos para as funções de operador de membro e o *ARG* é um argumento do tipo de classe no qual operar.

> [!NOTE]
> Não há nenhuma restrição quanto aos tipos de retorno dos operadores unários. Por exemplo, faz sentido para NOT lógico (`!`) retornar um valor integral, mas isso não é imposto.

## <a name="see-also"></a>Confira também

[Sobrecarga de operador](../cpp/operator-overloading.md)
