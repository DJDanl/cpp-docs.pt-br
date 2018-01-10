---
title: 'Bit a bit inclusivo ou operador: | | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- bitor
- '|'
dev_langs: C++
helpviewer_keywords:
- OR operator [C++], bitwise inclusive
- bitwise operators [C++], OR operator
- inclusive OR operator
- '| operator'
ms.assetid: 4c8a6a68-d828-447d-875a-aedb4ce3aa9a
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: eaef650cc747cdb9e628ae3b786bc1c1e21b5bdf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="bitwise-inclusive-or-operator-"></a>Operador OR inclusivo bit a bit: |
## <a name="syntax"></a>Sintaxe  
  
```  
  
expression   
|  
 expression  
  
```  
  
## <a name="remarks"></a>Comentários  
 O operador OR inclusivo bit a bit (**&#124;**) compara cada bit de seu primeiro operando com o bit correspondente de seu segundo operando. Se um bit for 1, o bit de resultado correspondente será definido como 1. Caso contrário, o bit de resultado correspondente será definido como 0.  
  
 Ambos os operandos para o operador OR inclusivo bit a bit devem ser do tipo integral. Conversões aritméticas usuais abordados [conversões padrão](standard-conversions.md) são aplicadas para os operandos.  
  
## <a name="operator-keyword-for-124"></a>Palavra-chave de operador para &#124;  
 O `bitor` operador é equivalente a texto **&#124;**. Há duas maneiras para acessar o `bitor` operador em seus programas: incluem o arquivo de cabeçalho `iso646.h`, ou de compilação com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção de compilador (desabilitar extensões de linguagem).  
  
## <a name="example"></a>Exemplo  
  
```  
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
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores bit a bit C](../c-language/c-bitwise-operators.md)

