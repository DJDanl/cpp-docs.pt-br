---
title: 'Operador&#39;de complemento One s: ~'
ms.date: 11/04/2016
f1_keywords:
- "~"
helpviewer_keywords:
- tilde (~) one's complement operator
- one's complement operator
- bitwise-complement operator
- compl operator
- ~ operator [C++], syntax
ms.assetid: 4bf81967-34f7-4b4b-aade-fd03d5da0174
ms.openlocfilehash: 777f253925caf38647863bdaa93fde8d5a03e3f9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80177710"
---
# <a name="one39s-complement-operator-"></a>Operador&#39;de complemento One s: ~

## <a name="syntax"></a>Sintaxe

```
~ cast-expression
```

## <a name="remarks"></a>Comentários

O operador de complemento de um (`~`), às vezes chamado de operador de “complemento bit a bit”, gera um complemento bit a bit de seu operando. Ou seja, cada bit que é 1 no operando, é 0 no resultado. De forma análoga, cada bit que é 0 no operando, é 1 no resultado. O operando para o operador de complemento de um deve ser um tipo integral.

## <a name="operator-keyword-for-"></a>Palavra-chave do operador para ~

O operador **Compal** é o texto equivalente de `~`. Há duas maneiras de acessar o operador **Compal** em seus programas: inclua o arquivo de cabeçalho `iso646.h`ou compile com [/za](../build/reference/za-ze-disable-language-extensions.md).

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

A promoção de integral é executada em operandos integrais, e o tipo resultante é o tipo para o qual o operando é promovido. Consulte [conversões padrão](standard-conversions.md) para obter mais informações sobre como a promoção é feita.

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores aritméticos unários](../c-language/unary-arithmetic-operators.md)
