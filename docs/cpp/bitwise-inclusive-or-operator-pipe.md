---
title: 'Bit a bit operador OR inclusivo: | | Microsoft Docs'
ms.custom: ''
ms.date: 06/14/2018
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- bitor
- '|'
dev_langs:
- C++
helpviewer_keywords:
- OR operator [C++], bitwise inclusive
- bitwise operators [C++], OR operator
- inclusive OR operator
- '| operator'
ms.assetid: 4c8a6a68-d828-447d-875a-aedb4ce3aa9a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 75cb922f2bd5cc6da2666a59bd0827b7ec013bf2
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39409431"
---
# <a name="bitwise-inclusive-or-operator-"></a>Bit a bit operador OR inclusivo: |

## <a name="syntax"></a>Sintaxe

> *Expression1* **|** *expression2*

## <a name="remarks"></a>Comentários

O operador OR inclusivo bit a bit (**&#124;**) compara cada bit do primeiro operando ao bit correspondente de seu segundo operando. Se um bit for 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.

Ambos os operandos para o operador OR inclusivo bit a bit devem ser do tipo integral. As conversões aritméticas usuais abordadas [conversões padrão](standard-conversions.md) são aplicadas aos operandos.

## <a name="operator-keyword-for-124"></a>Palavra-chave de operador para&#124;

O **bitor** operador é o equivalente de texto de **&#124;**. Há duas maneiras para acessar o **bitor** operador em seus programas: incluir o arquivo de cabeçalho \<lt;iso646.h&gt >, ou compilando com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção do compilador (desabilitar extensões de linguagem).

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

## <a name="see-also"></a>Consulte também
 [Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)  
 [Operadores bit a bit C](../c-language/c-bitwise-operators.md)  