---
title: 'Operador de negação lógica: !'
ms.date: 08/27/2018
f1_keywords:
- '!'
helpviewer_keywords:
- '! operator'
- NOT operator
- logical negation
ms.assetid: 650add9f-a7bc-426c-b01d-5fc6a81c8b62
ms.openlocfilehash: 06142ef15fcdbafdbae4b892772a04b117c087f6
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446543"
---
# <a name="logical-negation-operator-"></a>Operador de negação lógica: !

## <a name="syntax"></a>Sintaxe

```
! cast-expression
```

## <a name="remarks"></a>Comentários

O operador lógico de negação ( **!** ) reverte o significado de seu operando. O operando deve ser do tipo aritmético ou ponteiro (ou uma expressão que é avaliada para o tipo aritmético ou ponteiro). O operando é convertido implicitamente no tipo **bool**. O resultado será TRUE se o operando convertido for FALSE; o resultado será FALSE se o operando convertido for TRUE. O resultado é do tipo **bool**.

Para uma expressão *e*, a expressão unário `!e` é equivalente à expressão `(e == 0)`, exceto onde operadores sobrecarregados estão envolvidos.

## <a name="operator-keyword-for-"></a>Palavra-chave de operador para !

O operador **not** é uma grafia alternativa de **!** . Há duas maneiras de acessar o operador **not** em seus programas: inclua o arquivo de cabeçalho \<iso646. h > ou compile com a opção de compilador [/za](../build/reference/za-ze-disable-language-extensions.md) (desabilitar extensões de linguagem).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

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

## <a name="see-also"></a>Consulte também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores aritméticos unários](../c-language/unary-arithmetic-operators.md)<br/>
