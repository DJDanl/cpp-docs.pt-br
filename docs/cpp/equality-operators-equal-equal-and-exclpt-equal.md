---
title: 'Operadores de igualdade: == e !='
description: A sintaxe e o uso do operador de linguagem padrão C++ de igual para e não igual a.
ms.date: 07/23/2020
f1_keywords:
- '!='
- ==
- not_eq_cpp
helpviewer_keywords:
- '!= operator'
- equality operator
- not equal to comparison operator
- equality operator [C++], syntax
- == operator
- not_eq operator
- equal to operator
ms.assetid: ba4e9659-2392-4fb4-be5a-910a2a6df45a
ms.openlocfilehash: 567b83e99dce0354626f08a4788f1343314493b1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227537"
---
# <a name="equality-operators--and-"></a>Operadores de igualdade: == e !=

## <a name="syntax"></a>Sintaxe

> *expressão* **`==`** de *expressão* de\
> *expressão* **`!=`** de *expressão* de

## <a name="remarks"></a>Comentários

Operadores de igualdade binários comparam seus operandos em buscar de igualdades ou desigualdades estritas.

Os operadores de igualdade, igual a ( **`==`** ) e diferente de ( **`!=`** ), têm precedência mais baixa do que os operadores relacionais, mas se comportam de forma semelhante. O tipo de resultado para esses operadores é **`bool`** .

O operador equal-to ( **`==`** ) retornará **`true`** se ambos os operandos tiverem o mesmo valor; caso contrário, retornará **`false`** . O operador NOT-equal-to ( **`!=`** ) retorna **`true`** se os operandos não têm o mesmo valor; caso contrário, ele retorna **`false`** .

## <a name="operator-keyword-for-"></a>Palavra-chave Operator para! =

O C++ especifica **`not_eq`** como uma grafia alternativa para **`!=`** . (Não há nenhuma grafia alternativa para **`==`** .) Em C, a grafia alternativa é fornecida como uma macro no \<iso646.h> cabeçalho. Em C++, a grafia alternativa é uma palavra-chave; o uso do \<iso646.h> ou o equivalente em C++ \<ciso646> é preterido. No Microsoft C++, a [`/permissive-`](../build/reference/permissive-standards-conformance.md) opção ou do [`/Za`](../build/reference/za-ze-disable-language-extensions.md) compilador é necessária para habilitar a grafia alternativa.

## <a name="example"></a>Exemplo

```cpp
// expre_Equality_Operators.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;

int main() {
   cout  << boolalpha
         << "The true expression 3 != 2 yields: "
         << (3 != 2) << endl
         << "The false expression 20 == 10 yields: "
         << (20 == 10) << endl;
}
```

Os operadores de igualdade podem comparar ponteiros a membros do mesmo tipo. Nessa comparação, as conversões de ponteiro para membro são executadas. Os ponteiros para membros também podem ser comparados a uma expressão constante que é avaliada como 0.

## <a name="see-also"></a>Confira também

[Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)<br/>
[Operadores internos do C++, precedência; e Associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores relacionais e de igualdade C](../c-language/c-relational-and-equality-operators.md)
