---
title: 'Operador de negação lógico: !'
description: A sintaxe e o uso do operador de negação lógica de linguagem padrão C++.
ms.date: 07/23/2020
f1_keywords:
- '!'
helpviewer_keywords:
- '! operator'
- NOT operator
- logical negation
ms.assetid: 650add9f-a7bc-426c-b01d-5fc6a81c8b62
ms.openlocfilehash: fdd2e7a71b791375f898372d058a5eeb2afc59f1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223675"
---
# <a name="logical-negation-operator-"></a>Operador de negação lógico: !

## <a name="syntax"></a>Sintaxe

> **`!`***expressão CAST*

## <a name="remarks"></a>Comentários

O operador lógico de negação ( **`!`** ) inverte o significado de seu operando. O operando deve ser do tipo aritmético ou ponteiro (ou uma expressão que é avaliada para o tipo aritmético ou ponteiro). O operando é implicitamente convertido para o tipo **`bool`** . O resultado será **`true`** se o operando convertido for **`false`** ; o resultado será **`false`** se o operando convertido for **`true`** . O resultado é do tipo **`bool`** .

Para uma expressão `e` , a expressão unário `!e` é equivalente à expressão `(e == 0)` , exceto onde operadores sobrecarregados estão envolvidos.

## <a name="operator-keyword-for-"></a>Palavra-chave Operator para!

O C++ especifica **`not`** como uma grafia alternativa para **`!`** . Em C, a grafia alternativa é fornecida como uma macro no \<iso646.h> cabeçalho. Em C++, a grafia alternativa é uma palavra-chave; o uso do \<iso646.h> ou o equivalente em C++ \<ciso646> é preterido. No Microsoft C++, a [`/permissive-`](../build/reference/permissive-standards-conformance.md) opção ou do [`/Za`](../build/reference/za-ze-disable-language-extensions.md) compilador é necessária para habilitar a grafia alternativa.

## <a name="example"></a>Exemplo

```cpp
// expre_Logical_NOT_Operator.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    if (!i)
        cout << "i is zero" << endl;
}
```

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Operadores, precedência e Associação internos do C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores aritméticos unários](../c-language/unary-arithmetic-operators.md)<br/>
