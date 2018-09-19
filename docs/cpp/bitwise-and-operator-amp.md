---
title: 'Operador AND bit a bit: &amp; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- bitand
dev_langs:
- C++
helpviewer_keywords:
- AND operator
- bitwise operators [C++], AND operator
- '& operator [C++], bitwise operators'
ms.assetid: 76f40de3-c417-47b9-8a77-532f3fc990a5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a8967861ab6ac4e6b6fafd11eea22e67de339ea8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46111375"
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