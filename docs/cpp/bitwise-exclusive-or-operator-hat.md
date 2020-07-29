---
title: 'Operador OR exclusivo bit a bit: ^'
description: A sintaxe de operador ou a linguagem padrão do C++, exclusiva ou usada.
ms.date: 07/23/2020
f1_keywords:
- xor_cpp
helpviewer_keywords:
- operators [C++], bitwise
- exclusive OR operator
- XOR operator
- bitwise operators [C++], OR operator
- ^ operator
- OR operator [C++], bitwise exclusive
- operators [C++], logical
ms.assetid: f9185d85-65d5-4f64-a6d6-679758d52217
ms.openlocfilehash: 0f64b9f90b70756d29fcabb361cc07abe58e0a54
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229097"
---
# <a name="bitwise-exclusive-or-operator-"></a>Operador OR exclusivo bit a bit: ^

## <a name="syntax"></a>Sintaxe

> *expressão* **`^`** de *expressão* de

## <a name="remarks"></a>Comentários

O operador OR exclusivo OR bit ( **`^`** ) compara cada bit de seu primeiro operando com o bit correspondente de seu segundo operando. Se o bit no primeiro operando for 0 e o outro bit for 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente é definido como zero (0).

Ambos os operandos para o operador devem ter tipos integrais. As conversões aritméticas usuais abordadas nas [conversões padrão](standard-conversions.md) são aplicadas aos operandos.

## <a name="operator-keyword-for-"></a>Palavra-chave Operator para ^

O C++ especifica **`xor`** como uma grafia alternativa para **`^`** . Em C, a grafia alternativa é fornecida como uma macro no \<iso646.h> cabeçalho. Em C++, a grafia alternativa é uma palavra-chave; o uso do \<iso646.h> ou o equivalente em C++ \<ciso646> é preterido. No Microsoft C++, a [`/permissive-`](../build/reference/permissive-standards-conformance.md) opção ou do [`/Za`](../build/reference/za-ze-disable-language-extensions.md) compilador é necessária para habilitar a grafia alternativa.


## <a name="example"></a>Exemplo

```cpp
// expre_Bitwise_Exclusive_OR_Operator.cpp
// compile with: /EHsc
// Demonstrate bitwise exclusive OR
#include <iostream>
using namespace std;
int main() {
   unsigned short a = 0x5555;      // pattern 0101 ...
   unsigned short b = 0xFFFF;      // pattern 1111 ...

   cout  << hex << ( a ^ b ) << endl;   // prints "aaaa" pattern 1010 ...
}
```

## <a name="see-also"></a>Confira também

[Operadores, precedência e Associação internos do C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)
