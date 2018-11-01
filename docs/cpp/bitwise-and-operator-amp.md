---
title: 'Operador AND bit a bit: &amp;'
ms.date: 11/04/2016
f1_keywords:
- bitand
helpviewer_keywords:
- AND operator
- bitwise operators [C++], AND operator
- '& operator [C++], bitwise operators'
ms.assetid: 76f40de3-c417-47b9-8a77-532f3fc990a5
ms.openlocfilehash: b7d0d73802a5af7ab71e980d73eaff5c5b3c4bb8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50575351"
---
# <a name="bitwise-and-operator-amp"></a>Operador AND bit a bit: &amp;

## <a name="syntax"></a>Sintaxe

```
expression & expression
```

## <a name="remarks"></a>Comentários

As expressões podem ser outras expressões E, ou (sujeito às restrições de tipo mencionadas abaixo) expressões de igualdade, expressões relacionais, expressões aditivas, expressões multiplicativas, expressões de ponteiro para membro, expressões de conversão, expressões unárias, expressões pós-fixadas ou expressões primárias.

O operador AND bit a bit (**&**) compara cada bit do primeiro operando ao bit correspondente do segundo operando. Se os dois bits forem 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.

Os dois operandos do operador AND bit a bit devem ser de tipos integrais. As conversões aritméticas usuais abordadas [conversões padrão](standard-conversions.md), são aplicadas aos operandos.

## <a name="operator-keyword-for-"></a>Palavra-chave de operador para &

O **bitand** operador é o equivalente de texto de **&**. Há duas maneiras para acessar o **bitand** operador em seus programas: incluir o arquivo de cabeçalho `iso646.h`, ou compilando com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção do compilador (desabilitar extensões de linguagem).

## <a name="example"></a>Exemplo

```cpp
// expre_Bitwise_AND_Operator.cpp
// compile with: /EHsc
// Demonstrate bitwise AND
#include <iostream>
using namespace std;
int main() {
   unsigned short a = 0xFFFF;      // pattern 1111 ...
   unsigned short b = 0xAAAA;      // pattern 1010 ...

   cout  << hex << ( a & b ) << endl;   // prints "aaaa", pattern 1010 ...
}
```

## <a name="see-also"></a>Consulte também

[Operadores internos, precedência e associatividade C++](cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores bit a bit C](../c-language/c-bitwise-operators.md)