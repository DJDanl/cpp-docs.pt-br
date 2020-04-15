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
ms.openlocfilehash: 971ef08c5e79f851c502ea872c541517065797c5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372030"
---
# <a name="overloading-unary-operators"></a>Operadores unários de sobrecarga

Os operadores unários que podem ser sobrecarregados são os seguintes:

1. `!`(lógico[NÃO)](../cpp/logical-negation-operator-exclpt.md)

1. `&`(endereço[de](../cpp/address-of-operator-amp.md))

1. `~`([complemento)](../cpp/one-s-complement-operator-tilde.md)

1. `*`[(dereferência do ponteiro)](../cpp/indirection-operator-star.md)

1. `+`[(unary plus)](../cpp/additive-operators-plus-and.md)

1. `-`[(negação unária)](../cpp/additive-operators-plus-and.md)

1. `++`[(incremento)](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)

1. `--`[(decremento)](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)

1. operadores de conversão

Os operadores de incremento e`++` `--`decrésia pós-fixação (e ) são tratados separadamente em [Incremento e Decrement](../cpp/increment-and-decrement-operator-overloading-cpp.md).

Os operadores de conversão também são discutidos em um tópico separado; consulte [conversões de tipo definidas pelo usuário](../cpp/user-defined-type-conversions-cpp.md).

As regras a seguir são verdadeiras para todos os outros operadores unários. Para declarar uma função de operador unário como um membro não estático, você deve declará-la na forma:

> *ret-type* **operador** *op* **()**

onde *ret-type* é o tipo de retorno e *op* é um dos operadores listados na tabela anterior.

Para declarar uma função de operador unário como uma função global, você deve declará-la na forma:

> *ret-type* **operador** *op* **(arg** *arg* **)**

onde *ret-type* e *op* são descritos para funções de operador membro e o *arg* é um argumento do tipo de classe sobre o qual operar.

> [!NOTE]
> Não há nenhuma restrição quanto aos tipos de retorno dos operadores unários. Por exemplo, faz sentido para NOT lógico (`!`) retornar um valor integral, mas isso não é imposto.

## <a name="see-also"></a>Confira também

[Sobrecarga do operador](../cpp/operator-overloading.md)
