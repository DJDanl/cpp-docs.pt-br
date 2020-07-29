---
title: 'Operador de complemento individual: ~'
description: A sintaxe e o uso do operador de complemento da linguagem standard do C++.
ms.date: 07/23/2020
f1_keywords:
- "~"
- compl_cpp
helpviewer_keywords:
- tilde (~) one's complement operator
- one's complement operator
- bitwise-complement operator
- compl operator
- ~ operator [C++], syntax
ms.assetid: 4bf81967-34f7-4b4b-aade-fd03d5da0174
ms.openlocfilehash: 89c67855cd67df2af315cea941b487e7462889b2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227238"
---
# <a name="ones-complement-operator-"></a>Operador de complemento individual: ~

## <a name="syntax"></a>Sintaxe

```cpp
~ cast-expression
```

## <a name="remarks"></a>Comentários

O operador de complemento de um ( **`~`** ), às vezes chamado de operador de *complemento bit* -a-bit, produz um complemento de um bit que de seu operando. Ou seja, cada bit que é 1 no operando, é 0 no resultado. De forma análoga, cada bit que é 0 no operando, é 1 no resultado. O operando para o operador de complemento de um deve ser um tipo integral.

## <a name="operator-keyword-for-"></a>Palavra-chave Operator para ~

O C++ especifica **`compl`** como uma grafia alternativa para **`~`** . Em C, a grafia alternativa é fornecida como uma macro no \<iso646.h> cabeçalho. Em C++, a grafia alternativa é uma palavra-chave; o uso do \<iso646.h> ou o equivalente em C++ \<ciso646> é preterido. No Microsoft C++, a [`/permissive-`](../build/reference/permissive-standards-conformance.md) opção ou do [`/Za`](../build/reference/za-ze-disable-language-extensions.md) compilador é necessária para habilitar a grafia alternativa.

## <a name="example"></a>Exemplo

```cpp
// expre_One_Complement_Operator.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;

int main () {
   unsigned short y = 0xFFFF;
   cout << hex << y << endl;
   y = ~y;   // Take one's complement
   cout << hex << y << endl;
}
```

Nesse exemplo, o novo valor atribuído a `y` é o complemento de um do valor sem sinal 0xFFFF, ou 0x0000.

A promoção integral é executada em operandos integrais. O tipo do operando é promovido para é o tipo resultante. Para obter mais informações sobre a promoção integral, consulte [conversões padrão](standard-conversions.md).

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](expressions-with-unary-operators.md)<br/>
[Operadores, precedência e Associação internos do C++](cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores aritméticos unários](../c-language/unary-arithmetic-operators.md)
