---
title: 'Operador condicional: &quest;:'
ms.date: 11/04/2016
f1_keywords:
- '?:'
- '?'
helpviewer_keywords:
- conditional operators [C++]
- '? : operator'
ms.assetid: 88643ee8-7100-4f86-880a-705ec22b6271
ms.openlocfilehash: 8c00db06ed5c0347cb9c720e35bd3e517df2a13c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80189567"
---
# <a name="conditional-operator-quest-"></a>Operador condicional: &quest;:

## <a name="syntax"></a>Sintaxe

```
expression ? expression : expression
```

## <a name="remarks"></a>Comentários

O operador condicional ( **?:** ) é um operador ternário (ele usa três operandos). O operador condicional funciona desta forma:

- O primeiro operando é implicitamente convertido em **bool**. É avaliado e todos os efeitos colaterais são concluídos antes de continuar.

- Se o primeiro operando for avaliado como **true** (1), o segundo operando será avaliado.

- Se o primeiro operando for avaliado como **false** (0), o terceiro operando será avaliado.

O resultado do operador condicional é o resultado de qualquer operando avaliado — o segundo ou o terceiro. Somente um dos dois operandos dos dois mais recentes é avaliado em uma expressão condicional.

As expressões condicionais têm a capacidade da direita para a esquerda. O primeiro operando deve ser do tipo integral ou ponteiro. As regras a seguir se aplicam ao segundo e ao terceiro operando:

- Se ambos os operandos forem do mesmo tipo, o resultado será desse tipo.

- Se ambos os operandos forem de tipos aritméticos ou de enumeração, as conversões aritméticas usuais (cobertas em [conversões padrão](standard-conversions.md)) serão executadas para convertê-los em um tipo comum.

- Se ambos os operandos forem de tipos de ponteiro ou se um for um tipo de ponteiro e o outro for uma expressão constante que é avaliada como 0, as conversões de ponteiro serão executadas para convertê-las em um tipo comum.

- Se ambos os operandos forem de tipos de referência, as conversões de referência serão executadas para convertê-los em um tipo comum.

- Se ambos os operandos forem do tipo void, o tipo comum será de tipo void.

- Se ambos os operandos forem do mesmo tipo definido pelo usuário, o tipo comum será esse tipo.

- Se os operandos tiverem tipos diferentes e pelo menos um dos operandos tiver o tipo definido pelo usuário, as regras de idioma serão usadas para determinar o tipo comum. (Consulte o aviso abaixo.)

Todas as combinações do segundo e do terceiro operando que não estiverem na lista anterior são ilegais. O tipo de resultado é o tipo comum, e é um l-value se o segundo e o terceiro operandos forem do mesmo tipo e ambos forem l-values.

> [!WARNING]
>  Se os tipos do segundo e do terceiro operandos não forem idênticos, as regras de conversão de tipo complexo, conforme C++ especificado no padrão, serão invocadas. Essas conversões podem levar a um comportamento inesperado, incluindo a construção e a destruição de objetos temporários. Por esse motivo, Aconselhamos enfaticamente que você (1) Evite usar tipos definidos pelo usuário como operandos com o operador condicional ou (2) se você usar tipos definidos pelo usuário e, em seguida, converter explicitamente cada operando em um tipo comum.

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

[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operador de expressão condicional](../c-language/conditional-expression-operator.md)
