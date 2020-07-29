---
title: 'Operador OR lógico:  &#124;&#124;'
description: A sintaxe e o uso da linguagem lógica ou operador do C++ Standard.
ms.date: 07/23/2020
f1_keywords:
- '||'
- or_cpp
helpviewer_keywords:
- OR operator [C++], logical
- '|| operator'
- OR operator
- logical OR operator
ms.assetid: 31837c99-2655-4bf3-8ded-f13b7a9dc533
ms.openlocfilehash: 1845aef59f88d5dd044cefedd21cb618e1102e13
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225989"
---
# <a name="logical-or-operator-124124"></a>Operador OR lógico:  &#124;&#124;

## <a name="syntax"></a>Sintaxe

> *expressão* **`||`** OR lógica *expressão and lógica*

## <a name="remarks"></a>Comentários

O operador OR lógico ( **`||`** ) retornará o valor booliano **`true`** se um ou ambos os operandos for **`true`** e retornar de **`false`** outra forma. Os operandos são convertidos implicitamente em tipo **`bool`** antes da avaliação e o resultado é do tipo **`bool`** . O OR lógico tem associatividade da esquerda para a direita.

Os operandos para o operador OR lógico não precisam ter o mesmo tipo, mas devem ser do tipo booliano, integral ou de ponteiro. Os operandos são geralmente expressões relacionais ou de igualdade.

O primeiro operando é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar a avaliação da expressão OR lógica.

O segundo operando será avaliado somente se o primeiro operando for avaliado como **`false`** , porque a avaliação não é necessária quando a expressão or lógica é **`true`** . Ele é conhecido como avaliação de *curto-circuito* .

```cpp
printf( "%d" , (x == w || x == y || x == z) );
```

No exemplo acima, se `x` é igual a ou, `w` `y` ou `z` , o segundo argumento para a função é `printf` avaliado como **`true`** , que é promovido para um número inteiro e o valor 1 é impresso. Caso contrário, ele é avaliado como **`false`** e o valor 0 é impresso. Assim que uma das condições for avaliada como **`true`** , a avaliação será interrompida.

## <a name="operator-keyword-for-124124"></a>Palavra-chave Operator para &#124;&#124;

O C++ especifica **`or`** como uma grafia alternativa para **`||`** . Em C, a grafia alternativa é fornecida como uma macro no \<iso646.h> cabeçalho. Em C++, a grafia alternativa é uma palavra-chave; o uso do \<iso646.h> ou o equivalente em C++ \<ciso646> é preterido. No Microsoft C++, a [`/permissive-`](../build/reference/permissive-standards-conformance.md) opção ou do [`/Za`](../build/reference/za-ze-disable-language-extensions.md) compilador é necessária para habilitar a grafia alternativa.

## <a name="example"></a>Exemplo

```cpp
// expre_Logical_OR_Operator.cpp
// compile with: /EHsc
// Demonstrate logical OR
#include <iostream>
using namespace std;
int main() {
   int a = 5, b = 10, c = 15;
   cout  << boolalpha
         << "The true expression "
         << "a < b || b > c yields "
         << (a < b || b > c) << endl
         << "The false expression "
         << "a > b || b > c yields "
         << (a > b || b > c) << endl;
}
```

## <a name="see-also"></a>Confira também

[Operadores, precedência e Associação internos do C++](cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores lógicos C](../c-language/c-logical-operators.md)
