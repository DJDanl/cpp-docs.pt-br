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
ms.openlocfilehash: 802380bad59534e8402020142e394b3948032476
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62377216"
---
# <a name="overloading-unary-operators"></a>Operadores unários de sobrecarga

Os operadores unários que podem ser sobrecarregados são os seguintes:

1. `!` ([NOT lógico](../cpp/logical-negation-operator-exclpt.md))

1. `&` ([address-of](../cpp/address-of-operator-amp.md))

1. `~` ([2&gt;complemento de um&lt;2](../cpp/one-s-complement-operator-tilde.md))

1. `*` ([desreferência de ponteiro](../cpp/indirection-operator-star.md))

1. `+` ([adição unária](../cpp/additive-operators-plus-and.md))

1. `-` ([negação unária](../cpp/additive-operators-plus-and.md))

1. `++` ([increment](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md))

1. `--` ([decrement](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md))

9. operadores de conversão

O incremento de sufixo e operadores de decremento (`++` e `--`) são tratados separadamente em [incremento e decréscimo](../cpp/increment-and-decrement-operator-overloading-cpp.md).

Operadores de conversão também são abordados em um tópico separado; ver [conversões de tipo definidas pelo usuário](../cpp/user-defined-type-conversions-cpp.md).

As regras a seguir são verdadeiras para todos os outros operadores unários. Para declarar uma função de operador unário como um membro não estático, você deve declará-la na forma:

> *ret-type* **operator** *op* **()**

em que *ret-type* é o tipo de retorno e *op* é um dos operadores listado na tabela anterior.

Para declarar uma função de operador unário como uma função global, você deve declará-la na forma:

> *ret-type* **operator** *op* **(** *arg* **)**

em que *ret-type* e *op* são descritos para funções de operador de membro e o *arg* é um argumento de tipo de classe no qual operar.

> [!NOTE]
>  Não há nenhuma restrição quanto aos tipos de retorno dos operadores unários. Por exemplo, faz sentido para NOT lógico (`!`) retornar um valor integral, mas isso não é imposto.

## <a name="see-also"></a>Consulte também

[Sobrecarga de Operador](../cpp/operator-overloading.md)