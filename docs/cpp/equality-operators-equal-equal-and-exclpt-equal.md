---
title: 'Operadores de igualdade: == e !='
ms.date: 11/04/2016
f1_keywords:
- not_eq
- '!='
- ==
helpviewer_keywords:
- '!= operator'
- equality operator
- not equal to comparison operator
- equality operator [C++], syntax
- == operator
- not_eq operator
- equal to operator
ms.assetid: ba4e9659-2392-4fb4-be5a-910a2a6df45a
ms.openlocfilehash: d6248d4a31c478b62e5fbe304d9bde9b51b7cb06
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62392161"
---
# <a name="equality-operators--and-"></a>Operadores de igualdade: == e !=

## <a name="syntax"></a>Sintaxe

```
expression == expression
expression != expression
```

## <a name="remarks"></a>Comentários

Operadores de igualdade binários comparam seus operandos em buscar de igualdades ou desigualdades estritas.

Os operadores de igualdade, igual a (`==`) e diferente de (`!=`), têm precedência mais baixa do que os operadores relacionais, mas se comportam de maneira semelhante. É o tipo de resultado desses operadores **bool**.

O operador igual a (`==`) retorna **verdadeira** (1) se os dois operandos tiverem o mesmo valor; caso contrário, retornará **falso** (0). O operador de não-igual a (`!=`) retorna **verdadeira** se os operandos não tiverem o mesmo valor; caso contrário, retornará **false**.

## <a name="operator-keyword-for-"></a>Palavra-chave do operador para !=

O operador `not_eq` é o equivalente de texto de `!=`. Há duas maneiras para acessar o `not_eq` operador em seus programas: incluir o arquivo de cabeçalho `iso646.h`, ou compilando com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção do compilador (desabilitar extensões de linguagem).

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

Os operadores de igualdade podem comparar ponteiros a membros do mesmo tipo. Em comparação, conversões de ponteiro para membro são executadas. Os ponteiros para membros também podem ser comparados a uma expressão constante que é avaliada como 0.

## <a name="see-also"></a>Consulte também

[Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores relacionais e de igualdade C](../c-language/c-relational-and-equality-operators.md)