---
title: 'Operador OR inclusivo bit a bit: |'
ms.date: 06/14/2018
f1_keywords:
- '|'
helpviewer_keywords:
- OR operator [C++], bitwise inclusive
- bitwise operators [C++], OR operator
- inclusive OR operator
- '| operator'
ms.assetid: 4c8a6a68-d828-447d-875a-aedb4ce3aa9a
ms.openlocfilehash: 0df3493930206d655c0d9bca8a2468151aa3c2c6
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79445516"
---
# <a name="bitwise-inclusive-or-operator-"></a>Operador OR inclusivo bit a bit: |

## <a name="syntax"></a>Sintaxe

> *expression1* **|** *expression2*

## <a name="remarks"></a>Comentários

O bit inclusivo OR ( **&#124;** ) é comparado cada bit de seu primeiro operando com o bit correspondente de seu segundo operando. Se um bit for 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.

Ambos os operandos para o operador OR inclusivo bit a bit devem ser do tipo integral. As conversões aritméticas usuais abordadas nas [conversões padrão](standard-conversions.md) são aplicadas aos operandos.

## <a name="operator-keyword-for-124"></a>Palavra-chave Operator para&#124;

O operador **BITOR** é o texto equivalente de **&#124;** . Há duas maneiras de acessar o operador **BITOR** em seus programas: inclua o arquivo de cabeçalho \<iso646. h > ou compile com a opção de compilador [/za](../build/reference/za-ze-disable-language-extensions.md) (desabilitar extensões de linguagem).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// expre_Bitwise_Inclusive_OR_Operator.cpp
// compile with: /EHsc
// Demonstrate bitwise inclusive OR
#include <iostream>
using namespace std;

int main() {
   unsigned short a = 0x5555;      // pattern 0101 ...
   unsigned short b = 0xAAAA;      // pattern 1010 ...

   cout  << hex << ( a | b ) << endl;   // prints "ffff" pattern 1111 ...
}
```

## <a name="see-also"></a>Consulte também

[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores bit a bit C](../c-language/c-bitwise-operators.md)