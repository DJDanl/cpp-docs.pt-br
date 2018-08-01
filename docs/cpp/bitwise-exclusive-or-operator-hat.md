---
title: 'Operador OR exclusivo bit a bit: ^ | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], bitwise
- exclusive OR operator
- XOR operator
- bitwise operators [C++], OR operator
- ^ operator
- OR operator [C++], bitwise exclusive
- operators [C++], logical
ms.assetid: f9185d85-65d5-4f64-a6d6-679758d52217
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fe2f64c20c0d741608dfb2631c2e36026a31e8bb
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39406670"
---
# <a name="bitwise-exclusive-or-operator-"></a>Operador OR exclusivo bit a bit: ^
## <a name="syntax"></a>Sintaxe  
  
```  
expression ^ expression  
```  
  
## <a name="remarks"></a>Comentários  
O operador OR exclusivo bit a bit (**^**) compara cada bit do primeiro operando ao bit correspondente de seu segundo operando. Se um bit for 0 e o outro bit for 1, o bit resultante correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.  
  
Ambos os operandos para o operador OR exclusivo bit a bit devem ser do tipo integral. As conversões aritméticas usuais abordadas [conversões padrão](standard-conversions.md) são aplicadas aos operandos.  
  
## <a name="operator-keyword-for-"></a>Palavra-chave do operador para ^  
O **xor** operador é o equivalente de texto de **^**. Há duas maneiras para acessar o **xor** operador em seus programas: incluir o arquivo de cabeçalho `iso646.h`, ou compilando com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção do compilador (desabilitar extensões de linguagem).  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// expre_Bitwise_Exclusive_OR_Operator.cpp  
// compile with: /EHsc  
// Demonstrate bitwise exclusive OR  
#include <iostream>  
using namespace std;  
int main() {  
   unsigned short a = 0x5555;      // pattern 0101 ...  
   unsigned short b = 0xFFFF;      // pattern 1111 ...  
  
   cout  << hex << ( a ^ b ) << endl;   // prints "aaaa" pattern 1010 ...  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   