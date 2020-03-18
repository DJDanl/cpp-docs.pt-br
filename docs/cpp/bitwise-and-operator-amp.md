---
title: 'Operador AND bit a bit: &amp;'
ms.date: 11/04/2016
helpviewer_keywords:
- AND operator
- bitwise operators [C++], AND operator
- '& operator [C++], bitwise operators'
ms.assetid: 76f40de3-c417-47b9-8a77-532f3fc990a5
ms.openlocfilehash: ba17c9a633b7b18cad2881dfef90fde7c2074319
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446144"
---
# <a name="bitwise-and-operator-amp"></a>Operador AND bit a bit: &amp;

## <a name="syntax"></a>Sintaxe

```
expression & expression
```

## <a name="remarks"></a>Comentários

As expressões podem ser outras expressões E, ou (sujeito às restrições de tipo mencionadas abaixo) expressões de igualdade, expressões relacionais, expressões aditivas, expressões multiplicativas, expressões de ponteiro para membro, expressões de conversão, expressões unárias, expressões pós-fixadas ou expressões primárias.

O operador AND e AND de bit ( **&** ) é comparado cada bit do primeiro operando com o bit correspondente do segundo operando. Se os dois bits forem 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.

Os dois operandos do operador AND bit a bit devem ser de tipos integrais. As conversões aritméticas usuais abordadas nas [conversões padrão](standard-conversions.md)são aplicadas aos operandos.

## <a name="operator-keyword-for-"></a>Palavra-chave Operator para &

O operador **bitand** é o texto equivalente de **&** . Há duas maneiras de acessar o operador **bitand** em seus programas: inclua o arquivo de cabeçalho `iso646.h`ou compile com a opção de compilador [/za](../build/reference/za-ze-disable-language-extensions.md) (desabilitar extensões de linguagem).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

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