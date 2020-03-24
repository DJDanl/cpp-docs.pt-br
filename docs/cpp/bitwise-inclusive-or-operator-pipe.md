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
ms.openlocfilehash: 38def2b1ac585c751699227d2a065b45145d290d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190749"
---
# <a name="bitwise-inclusive-or-operator-"></a>Operador OR inclusivo bit a bit: |

## <a name="syntax"></a>Sintaxe

> *expression1* **|** *expression2*

## <a name="remarks"></a>Comentários

O bit inclusivo OR ( **&#124;** ) é comparado cada bit de seu primeiro operando com o bit correspondente de seu segundo operando. Se qualquer bit for 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente é definido como zero (0).

Ambos os operandos para o operador OR inclusivo bit a bit devem ser do tipo integral. As conversões aritméticas usuais abordadas nas [conversões padrão](standard-conversions.md) são aplicadas aos operandos.

## <a name="operator-keyword-for-124"></a>Palavra-chave Operator para&#124;

O operador **BITOR** é o texto equivalente de **&#124;** . Há duas maneiras de acessar o operador **BITOR** em seus programas: inclua o arquivo de cabeçalho \<iso646. h > ou compile com a opção de compilador [/za](../build/reference/za-ze-disable-language-extensions.md) (desabilitar extensões de linguagem).

## <a name="example"></a>Exemplo

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

## <a name="see-also"></a>Confira também

[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores bit a bit C](../c-language/c-bitwise-operators.md)
