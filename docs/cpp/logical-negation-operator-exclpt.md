---
title: 'Operador de negação lógica: ! | Microsoft Docs'
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- '!'
- Not
dev_langs:
- C++
helpviewer_keywords:
- '! operator'
- NOT operator
- logical negation
ms.assetid: 650add9f-a7bc-426c-b01d-5fc6a81c8b62
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4594a8b1a881b6fa92909e7c7014087ff6240de8
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43211812"
---
# <a name="logical-negation-operator-"></a>Operador de negação lógica: !

## <a name="syntax"></a>Sintaxe

```
! cast-expression
```

## <a name="remarks"></a>Comentários

O operador de negação lógica (**!**) inverte o significado do respectivo operando. O operando deve ser do tipo aritmético ou ponteiro (ou uma expressão que é avaliada para o tipo aritmético ou ponteiro). O operando é convertido implicitamente no tipo **bool**. O resultado será TRUE se o operando convertido for FALSE; o resultado será FALSE se o operando convertido for TRUE. O resultado é do tipo **bool**.

Para uma expressão *eletrônico*, a expressão unária `!e` é equivalente à expressão `(e == 0)`, exceto onde operadores sobrecarregados estão envolvidos.

## <a name="operator-keyword-for-"></a>Palavra-chave de operador para !

O **não** operador é uma ortografia alternativa de **!**. Há duas maneiras para acessar o **não** operador em seus programas: incluir o arquivo de cabeçalho \<lt;iso646.h&gt >, ou compilando com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção do compilador (desabilitar extensões de linguagem).

## <a name="example"></a>Exemplo

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
