---
title: 'Incremento e decremento pré-fixados: + + e -| Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- --
- ++
dev_langs:
- C++
helpviewer_keywords:
- increment operators [C++], syntax
- ++ operator [C++], prefix increment operators
- operators [C++], decrement
- -- operator [C++], prefix decrement operators [C++]
- operators [C++], increment
- decrement operators [C++], syntax
- decrement operators [C++]
ms.assetid: 45ea7fc7-f279-4be9-a216-1d9a0ef9eb7b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cc5ef28f7119316f0c42302d4fd1583a53e53140
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46069723"
---
# <a name="prefix-increment-and-decrement-operators--and---"></a>Operadores de incremento e de decremento pré-fixados: ++ e --

## <a name="syntax"></a>Sintaxe

```
++ unary-expression
-- unary-expression
```

## <a name="remarks"></a>Comentários

O operador de incremento de prefixo (**++**) adiciona um ao operando; esse valor incrementado é o resultado da expressão. O operando deve ser um l-value não é do tipo **const**. O resultado é um valor l do mesmo tipo do operando.

O operador de decremento de prefixo (**--**) é análogo ao operador de incremento de prefixo, exceto que o operando é decrementado por um e o resultado é esse valor decrementado.

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): O operando de um operador de incremento ou decremento não pode ser do tipo **bool**.

Os operadores de incremento e decremento de prefixo e sufixo afetam seus operandos. A principal diferença entre eles é a ordem em que o incremento ou decremento ocorre na avaliação de uma expressão. (Para obter mais informações, consulte [incremento de sufixo e operadores de decremento](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md).) Na forma de prefixo, o incremento ou decremento ocorre antes de o valor ser usado na avaliação da expressão, assim o valor da expressão é diferente do valor do operando. Na forma de sufixo, o incremento ou decremento ocorre após que o valor é usado na avaliação da expressão, assim o valor da expressão é igual ao valor do operando. Por exemplo, o programa seguir imprime "`++i = 6`":

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

Porque os operadores de incremento e decremento têm efeitos colaterais, usando expressões com operadores de incremento ou decremento em uma [macro do pré-processador](../preprocessor/macros-c-cpp.md) pode ter resultados indesejados. Considere este exemplo:

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
>  As funções embutidas C++ são preferíveis para macros em muitos casos, pois eliminam efeitos colaterais como os descritas aqui, e permitem que a linguagem faça uma verificação de tipo mais completa.

## <a name="see-also"></a>Consulte também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores de incremento e decremento pré-fixados](../c-language/prefix-increment-and-decrement-operators.md)