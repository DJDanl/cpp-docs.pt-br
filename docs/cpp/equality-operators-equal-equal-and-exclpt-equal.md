---
title: 'Operadores de igualdade: == e !='
ms.date: 11/04/2016
f1_keywords:
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
ms.openlocfilehash: 7e42b66438579bc9be6274863366762b8b4ffbe9
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79444403"
---
# <a name="equality-operators--and-"></a>Operadores de igualdade: == e !=

## <a name="syntax"></a>Sintaxe

```
expression == expression
expression != expression
```

## <a name="remarks"></a>Comentários

Operadores de igualdade binários comparam seus operandos em buscar de igualdades ou desigualdades estritas.

Os operadores de igualdade, igual a (`==`) e diferente de (`!=`), têm precedência mais baixa do que os operadores relacionais, mas se comportam de maneira semelhante. O tipo de resultado para esses operadores é **bool**.

O operador equal-to (`==`) retornará **true** (1) se ambos os operandos tiverem o mesmo valor; caso contrário, retornará **false** (0). O operador NOT-equal-to (`!=`) retornará **true** se os operandos não tiverem o mesmo valor; caso contrário, retornará **false**.

## <a name="operator-keyword-for-"></a>Palavra-chave do operador para !=

O operador `not_eq` é o equivalente de texto de `!=`. Há duas maneiras de acessar o operador de `not_eq` em seus programas: inclua o arquivo de cabeçalho `iso646.h`ou compile com a opção de compilador [/za](../build/reference/za-ze-disable-language-extensions.md) (desabilitar extensões de linguagem).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

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

## <a name="see-also"></a>Consulte também

[Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores relacionais e de igualdade C](../c-language/c-relational-and-equality-operators.md)