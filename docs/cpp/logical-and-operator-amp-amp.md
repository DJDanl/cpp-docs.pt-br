---
title: 'Operador lógico AND: &amp;&amp;'
ms.date: 11/04/2016
f1_keywords:
- '&&'
helpviewer_keywords:
- logical AND operator
- AND operator
- '&& operator'
ms.assetid: 50cfa664-a8c4-4b31-9bab-2f80d7cd2d1f
ms.openlocfilehash: b21d91009c455b67af6fae88fceafeeaf8043301
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179426"
---
# <a name="logical-and-operator-ampamp"></a>Operador lógico AND: &amp;&amp;

## <a name="syntax"></a>Sintaxe

```
expression && expression
```

## <a name="remarks"></a>Comentários

O operador AND lógico ( **&&** ) retornará o valor booliano true se ambos os operandos forem true e retornará false caso contrário. Os operandos são convertidos implicitamente no tipo **bool** antes da avaliação, e o resultado é do tipo **bool**. O AND lógico tem associatividade da esquerda para a direita.

Os operandos para o operador AND lógico não precisam ser do mesmo tipo, mas devem ser de tipo integral ou ponteiro. Os operandos são geralmente expressões relacionais ou de igualdade.

O primeiro operando é completamente avaliado e todos os efeitos colaterais são concluídos antes de continuar a avaliação da expressão AND lógica.

O segundo operando é avaliado somente se o primeiro operando for avaliado como true (diferente de zero). Essa avaliação elimina a avaliação desnecessária do segundo operando quando a expressão AND lógica for false. Você pode usar a avaliação de curto-circuito para evitar a remoção de referência do ponteiro nulo, conforme mostrado no seguinte exemplo:

```cpp
char *pch = 0;
...
(pch) && (*pch = 'a');
```

Se `pch` for nulo (0), o lado direito da expressão nunca será avaliado. Portanto, a atribuição por meio de um ponteiro nulo é impossível.

## <a name="operator-keyword-for-"></a>Palavra-chave Operator para & &

O operador **and** é o texto equivalente de **&&** . Há duas maneiras de acessar o operador **and** em seus programas: inclua o arquivo de cabeçalho `iso646.h`ou compile com a opção de compilador [/za](../build/reference/za-ze-disable-language-extensions.md) (desabilitar extensões de linguagem).

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

[C++Precedência e Associação de operadores internos](cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores lógicos C](../c-language/c-logical-operators.md)
