---
title: 'Operador condicional: &quest; :'
ms.date: 11/04/2016
f1_keywords:
- '?:'
- '?'
helpviewer_keywords:
- conditional operators [C++]
- '? : operator'
ms.assetid: 88643ee8-7100-4f86-880a-705ec22b6271
ms.openlocfilehash: 4ba4c80d40450fd5975b047a1a4fca63146c5773
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337256"
---
# <a name="conditional-operator-quest-"></a>Operador condicional: &quest; :

## <a name="syntax"></a>Sintaxe

```
expression ? expression : expression
```

## <a name="remarks"></a>Comentários

O operador condicional (**? :**) é um operador ternário (leva três operands). O operador condicional funciona desta forma:

- O primeiro operand é implicitamente convertido em **bool**. É avaliado e todos os efeitos colaterais são concluídos antes de continuar.

- Se o primeiro operand avalia a **verdade** (1), o segundo operand é avaliado.

- Se o primeiro operand avalia como **falso** (0), o terceiro operand é avaliado.

O resultado do operador condicional é o resultado de qualquer operando avaliado — o segundo ou o terceiro. Somente um dos dois operandos dos dois mais recentes é avaliado em uma expressão condicional.

As expressões condicionais têm a capacidade da direita para a esquerda. O primeiro operando deve ser do tipo integral ou ponteiro. As seguintes regras se aplicam ao segundo e terceiro operands:

- Se ambos os operands são do mesmo tipo, o resultado é desse tipo.

- Se ambos os operands forem de tipos aritméticos ou enumeração, as conversões aritméticas usuais (cobertas em [Conversões Padrão](standard-conversions.md)) são realizadas para convertê-las em um tipo comum.

- Se ambos os operands forem de tipos de ponteiro ou se um for um tipo de ponteiro e o outro for uma expressão constante que avalia para 0, as conversões de ponteiro são realizadas para convertê-las para um tipo comum.

- Se ambos os operands forem de tipos de referência, conversões de referência são realizadas para convertê-las para um tipo comum.

- Se ambos os operands são de tipo vazio, o tipo comum é o tipo vazio.

- Se ambos os operands são do mesmo tipo definido pelo usuário, o tipo comum é esse tipo.

- Se os operands têm tipos diferentes e pelo menos um dos operands tem o tipo definido pelo usuário, então as regras de idioma são usadas para determinar o tipo comum. (Veja o aviso abaixo.)

Todas as combinações do segundo e do terceiro operando que não estiverem na lista anterior são ilegais. O tipo de resultado é o tipo comum, e é um l-value se o segundo e o terceiro operandos forem do mesmo tipo e ambos forem l-values.

> [!WARNING]
> Se os tipos do segundo e terceiro operands não forem idênticos, então regras complexas de conversão de tipo, conforme especificado no C++ Standard, são invocadas. Essas conversões podem levar a comportamentos inesperados, incluindo construção e destruição de objetos temporários. Por essa razão, recomendamos fortemente que você evite usar os tipos definidos pelo usuário como operands com o operador condicional ou (2) se você usar tipos definidos pelo usuário, em seguida, explicitamente lançar cada operand para um tipo comum.

## <a name="example"></a>Exemplo

```cpp
// expre_Expressions_with_the_Conditional_Operator.cpp
// compile with: /EHsc
// Demonstrate conditional operator
#include <iostream>
using namespace std;
int main() {
   int i = 1, j = 2;
   cout << ( i > j ? i : j ) << " is greater." << endl;
}
```

## <a name="see-also"></a>Confira também

[Operadores internos C++, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operador de expressão condicional](../c-language/conditional-expression-operator.md)
