---
title: 'Operador OR lógico: ||'
ms.date: 06/14/2018
f1_keywords:
- '||'
helpviewer_keywords:
- OR operator [C++], logical
- '|| operator'
- OR operator
- logical OR operator
ms.assetid: 31837c99-2655-4bf3-8ded-f13b7a9dc533
ms.openlocfilehash: 94b2bc024dd7223ac7adacc72924f5ee289bab37
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80178074"
---
# <a name="logical-or-operator-"></a>Operador OR lógico: ||

## <a name="syntax"></a>Sintaxe

> expressão or *lógica* **||** *lógica e expressão*

## <a name="remarks"></a>Comentários

O operador OR lógico ( **||** ) retornará o valor booliano true se um ou ambos os operandos forem true e retornará false caso contrário. Os operandos são convertidos implicitamente no tipo **bool** antes da avaliação, e o resultado é do tipo **bool**. O OR lógico tem associatividade da esquerda para a direita.

Os operandos para o operador OR lógico não precisam ser do mesmo tipo, mas devem ser de tipo integral ou ponteiro. Os operandos são geralmente expressões relacionais ou de igualdade.

O primeiro operando é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar a avaliação da expressão OR lógica.

O segundo operando é avaliado somente se o primeiro operando for avaliado como false (0). Isso elimina a avaliação desnecessária do segundo operando quando a expressão OR lógica for true.

```cpp
printf( "%d" , (x == w || x == y || x == z) );
```

No exemplo acima, se `x` for igual a `w`, `y` ou `z`, o segundo argumento para a função `printf` será avaliado como true e o valor 1 será impresso. Caso contrário, será avaliado como false, e o valor 0 será impresso. Assim que uma das condições for avaliada como true, a avaliação é encerrada.

## <a name="operator-keyword-for-124124"></a>Palavra-chave Operator para&#124;&#124;

O operador **or** é o texto equivalente de **||** . Há duas maneiras de acessar o operador **or** em seus programas: inclua o arquivo de cabeçalho \<iso646. h > ou compile com a opção de compilador [/za](../build/reference/za-ze-disable-language-extensions.md) (desabilitar extensões de linguagem).

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

[C++Precedência e Associação de operadores internos](cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores lógicos C](../c-language/c-logical-operators.md)
