---
title: Operador AND lógico:&amp;&amp;
description: A sintaxe e o uso da linguagem padrão do C++ e do operador.
ms.date: 07/23/2020
f1_keywords:
- '&&'
- and_cpp
helpviewer_keywords:
- logical AND operator
- AND operator
- '&& operator'
ms.assetid: 50cfa664-a8c4-4b31-9bab-2f80d7cd2d1f
ms.openlocfilehash: 431e76a2943c2373d6191f1fbe9f14c54cfaa6c1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223688"
---
# <a name="logical-and-operator-ampamp"></a>Operador AND lógico:&amp;&amp;

## <a name="syntax"></a>Sintaxe

> *expressão* **`&&`** de *expressão* de

## <a name="remarks"></a>Comentários

O operador AND lógico ( **&&** ) retorna **`true`** se ambos os operandos são **`true`** e retorna de **`false`** outra forma. Os operandos são convertidos implicitamente em tipo **`bool`** antes da avaliação e o resultado é do tipo **`bool`** . O AND lógico tem associatividade da esquerda para a direita.

Os operandos para o operador AND lógico não precisam ter o mesmo tipo, mas devem ter o tipo booliano, integral ou de ponteiro. Os operandos são geralmente expressões relacionais ou de igualdade.

O primeiro operando é completamente avaliado e todos os efeitos colaterais são concluídos antes de a avaliação da expressão AND lógica continuar.

O segundo operando será avaliado somente se o primeiro operando for avaliado como **`true`** (diferente de zero). Essa avaliação elimina a avaliação desnecessária do segundo operando quando a expressão AND lógica é **`false`** . Você pode usar a avaliação de curto-circuito para evitar a remoção de referência do ponteiro nulo, conforme mostrado no seguinte exemplo:

```cpp
char *pch = 0;
// ...
(pch) && (*pch = 'a');
```

Se `pch` for nulo (0), o lado direito da expressão nunca será avaliado. Essa avaliação de curto-circuito torna impossível a atribuição por meio de um ponteiro nulo.

## <a name="operator-keyword-for-"></a>Palavra-chave Operator para &&

O C++ especifica **`and`** como uma grafia alternativa para **`&&`** . Em C, a grafia alternativa é fornecida como uma macro no \<iso646.h> cabeçalho. Em C++, a grafia alternativa é uma palavra-chave; o uso do \<iso646.h> ou o equivalente em C++ \<ciso646> é preterido. No Microsoft C++, a [`/permissive-`](../build/reference/permissive-standards-conformance.md) opção ou do [`/Za`](../build/reference/za-ze-disable-language-extensions.md) compilador é necessária para habilitar a grafia alternativa.

## <a name="example"></a>Exemplo

```cpp
// expre_Logical_AND_Operator.cpp
// compile with: /EHsc
// Demonstrate logical AND
#include <iostream>

using namespace std;

int main() {
   int a = 5, b = 10, c = 15;
   cout  << boolalpha
         << "The true expression "
         << "a < b && b < c yields "
         << (a < b && b < c) << endl
         << "The false expression "
         << "a > b && b < c yields "
         << (a > b && b < c) << endl;
}
```

## <a name="see-also"></a>Confira também

[Operadores, precedência e Associação internos do C++](cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores lógicos C](../c-language/c-logical-operators.md)
