---
title: 'Operadores de incremento e decremento de sufixo: + + e -| Microsoft Docs'
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
- member-selection operators [C++]
- -- operator [C++], postfix decrement operators
- postfix operators [C++]
- ++ operator [C++], postfix increment operators
- decrement operators [C++], syntax
- operators [C++], postfix
- decrement operators [C++]
ms.assetid: 0204d5c8-51b0-4108-b8a1-074c5754d89c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4591f9f4fed8b3b8dd1c24b8200b3365d87194b8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46044659"
---
# <a name="postfix-increment-and-decrement-operators--and---"></a>Operadores de incremento e de decremento pós-fixados: ++ e --

## <a name="syntax"></a>Sintaxe

```
postfix-expression ++
postfix-expression --
```

## <a name="remarks"></a>Comentários

O C++ fornece operadores de incremento e decremento de prefixo e sufixo; esta seção descreve somente os operadores de incremento e decremento de sufixo. (Para obter mais informações, consulte [prefixo operadores de incremento e decremento](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md).) A diferença entre os dois é que, na notação do sufixo, o operador aparece depois *postfix-expression*, enquanto na notação de prefixo, o operador aparece antes *expressão.* O exemplo a seguir mostra um operador de incremento de sufixo:

```cpp
i++;
```

O efeito de aplicar o operador de incremento de sufixo (**++**) é que o valor do operando é gerado por uma unidade do tipo apropriado. Da mesma forma, o efeito de aplicar o operador de decremento de sufixo (**--**) é que o valor do operando é diminuído em uma unidade do tipo apropriado.

É importante observar que um sufixo incremento ou decremento expressão é avaliada como o valor da expressão *anteriores ao* aplicação do respectivo operador. A operação de incremento ou decremento ocorre *depois de* o operando é avaliado. Esse problema surge apenas quando a operação de incremento ou decremento de sufixo ocorre no contexto de uma expressão maior.

Quando um operador de sufixo é aplicado a um argumento de função, o valor do argumento não tem garantia de incremento ou decremento antes de ser passada para a função.  Consulte a seção 1.9.17 no padrão C++ para obter mais informações.

Aplicar o operador de incremento de sufixo em um ponteiro para uma matriz de objetos do tipo **longo** adiciona quatro à representação interna do ponteiro. Esse comportamento faz com que o ponteiro, referido anteriormente como o *n*º elemento da matriz, para referir-se a (*n*+ 1) º elemento.

Os operandos de incremento e decremento de sufixo devem ser modificáveis (não **const**) l-values do tipo aritmético ou ponteiro. O tipo do resultado é o mesmo que o *postfix-expression*, mas não é um l-value.

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): O operando de um incremento ou decremento pós-fixada operador não pode ser do tipo **bool**.

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

## <a name="see-also"></a>Consulte também

[Expressões pós-fixadas](../cpp/postfix-expressions.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores de incremento e decremento pós-fixados C](../c-language/c-postfix-increment-and-decrement-operators.md)