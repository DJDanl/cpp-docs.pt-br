---
title: 'Operadores de incremento e de decremento pré-fixados: ++ e --'
ms.date: 11/04/2016
f1_keywords:
- --
- ++
helpviewer_keywords:
- increment operators [C++], syntax
- ++ operator [C++], prefix increment operators
- operators [C++], decrement
- -- operator [C++], prefix decrement operators [C++]
- operators [C++], increment
- decrement operators [C++], syntax
- decrement operators [C++]
ms.assetid: 45ea7fc7-f279-4be9-a216-1d9a0ef9eb7b
ms.openlocfilehash: 0b84360f41c665707a03ad453909c054ac741405
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231150"
---
# <a name="prefix-increment-and-decrement-operators--and---"></a>Operadores de incremento e de decremento pré-fixados: ++ e --

## <a name="syntax"></a>Sintaxe

```
++ unary-expression
-- unary-expression
```

## <a name="remarks"></a>Comentários

O operador de incremento de prefixo ( **++** ) adiciona um ao seu operando; esse valor incrementado é o resultado da expressão. O operando deve ser um l-Value que não seja do tipo **`const`** . O resultado é um valor l do mesmo tipo do operando.

O prefixo decrementar ( **--** ) é análogo ao operador de incremento de prefixo, exceto que o operando é decrementado por um e o resultado é esse valor diminuído.

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)): o operando de um incremento ou um operador de decréscimo não pode ser do tipo **`bool`** .

Os operadores de incremento e decremento de prefixo e sufixo afetam seus operandos. A principal diferença entre eles é a ordem em que o incremento ou decremento ocorre na avaliação de uma expressão. (Para obter mais informações, consulte [incremento de sufixo e diminuir operadores](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md).) No formulário de prefixo, o incremento ou o decréscimo ocorre antes de o valor ser usado na avaliação da expressão, portanto, o valor da expressão é diferente do valor do operando. Na forma de sufixo, o incremento ou decremento ocorre após que o valor é usado na avaliação da expressão, assim o valor da expressão é igual ao valor do operando. Por exemplo, o programa seguir imprime "`++i = 6`":

```cpp
// expre_Increment_and_Decrement_Operators.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;

int main() {
   int i = 5;
   cout << "++i = " << ++i << endl;
}
```

Um operando tipo integral ou flutuante é incrementado ou decrementado pelo valor inteiro 1. O tipo do resultado é igual ao tipo do operando. Um operando do tipo ponteiro é incrementado ou decrementado pelo tamanho do objeto pertinente. Um ponteiro incrementado aponta para o próximo objeto;um ponteiro decrementado aponta para o objeto anterior.

Como os operadores de incremento e decremento têm efeitos colaterais, o uso de expressões com operadores de incremento ou decréscimo em uma [macro de pré-processador](../preprocessor/macros-c-cpp.md) pode ter resultados indesejáveis. Considere este exemplo:

```cpp
// expre_Increment_and_Decrement_Operators2.cpp
#define max(a,b) ((a)<(b))?(b):(a)

int main()
{
   int i = 0, j = 0, k;
   k = max( ++i, j );
}
```

A macro se expande para:

```cpp
k = ((++i)<(j))?(j):(++i);
```

Se `i` for maior ou igual a `j` ou menor que `j` por 1, será incrementado duas vezes.

> [!NOTE]
> As funções embutidas C++ são preferíveis para macros em muitos casos, pois eliminam efeitos colaterais como os descritas aqui, e permitem que a linguagem faça uma verificação de tipo mais completa.

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Operadores internos C++, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores de incremento e decréscimo de prefixo](../c-language/prefix-increment-and-decrement-operators.md)
