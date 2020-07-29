---
title: 'Operadores de incremento e de decremento pós-fixados: ++ e --'
ms.date: 11/04/2016
f1_keywords:
- --
- ++
helpviewer_keywords:
- increment operators [C++], syntax
- member-selection operators [C++]
- -- operator [C++], postfix decrement operators
- postfix operators [C++]
- ++ operator [C++], postfix increment operators
- decrement operators [C++], syntax
- operators [C++], postfix
- decrement operators [C++]
ms.assetid: 0204d5c8-51b0-4108-b8a1-074c5754d89c
ms.openlocfilehash: 8c3eeb47ec81f4073452c17f40eb2fec4911989f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213275"
---
# <a name="postfix-increment-and-decrement-operators--and---"></a>Operadores de incremento e de decremento pós-fixados: ++ e --

## <a name="syntax"></a>Sintaxe

```
postfix-expression ++
postfix-expression --
```

## <a name="remarks"></a>Comentários

O C++ fornece operadores de incremento e decremento de prefixo e sufixo; esta seção descreve somente os operadores de incremento e decremento de sufixo. (Para obter mais informações, consulte [incremento de prefixo e diminuir operadores](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md).) A diferença entre os dois é que, na notação de sufixo, o operador aparece após o *sufixo-expressão*, enquanto na notação de prefixo, o operador aparece antes da *expressão.* O exemplo a seguir mostra um operador de incremento de sufixo:

```cpp
i++;
```

O efeito de aplicar o operador de incremento de sufixo ( **++** ) é que o valor do operando é aumentado por uma unidade do tipo apropriado. Da mesma forma, o efeito da aplicação do operador decremento de sufixo ( **--** ) é que o valor do operando é diminuído por uma unidade do tipo apropriado.

É importante observar que uma expressão de incremento ou decréscimo de sufixo é avaliada como o valor da expressão *antes* do aplicativo do respectivo operador. A operação de aumento ou diminuição ocorre *depois* que o operando é avaliado. Esse problema surge apenas quando a operação de incremento ou decremento de sufixo ocorre no contexto de uma expressão maior.

Quando um operador de sufixo é aplicado a um argumento de função, o valor do argumento não tem garantia de incremento ou decremento antes de ser passada para a função.  Consulte a seção 1.9.17 no padrão C++ para obter mais informações.

Aplicar o operador de incremento de sufixo a um ponteiro para uma matriz de objetos do tipo **`long`** realmente adiciona quatro à representação interna do ponteiro. Esse comportamento faz com que o ponteiro, que anteriormente fazia referência ao elemento *n*th da matriz, refira-se ao elemento (*n*+ 1) th.

Os operandos dos operadores sufixo e aumento de sufixo devem ser modificadores (não **`const`** ) l-valores de tipo aritmético ou de ponteiro. O tipo do resultado é o mesmo da *expressão de sufixo*, mas não é mais um l-Value.

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)): o operando de um incremento de sufixo ou um operador de decréscimo não pode ser do tipo **`bool`** .

O código a seguir ilustra o operador de incremento de sufixo:

```cpp
// expre_Postfix_Increment_and_Decrement_Operators.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

int main() {
   int i = 10;
   cout << i++ << endl;
   cout << i << endl;
}
```

As operações postincrement e postdecrement em tipos enumerados não têm suporte:

```cpp
enum Compass { North, South, East, West );
Compass myCompass;
for( myCompass = North; myCompass != West; myCompass++ ) // Error
```

## <a name="see-also"></a>Confira também

[Expressões de sufixo](../cpp/postfix-expressions.md)<br/>
[Operadores internos C++, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores de aumento e diminuição de sufixo C](../c-language/c-postfix-increment-and-decrement-operators.md)
