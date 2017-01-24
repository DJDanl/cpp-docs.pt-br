---
title: "Operador OR exclusivo bit a bit: ^ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador ^"
  - "operadores bit a bit, Operador OR"
  - "Operador OR exclusivo"
  - "operadores [C++], bit a bit"
  - "operadores [C++], lógico"
  - "Operador OR, exclusivo bit a bit"
  - "Operador XOR"
ms.assetid: f9185d85-65d5-4f64-a6d6-679758d52217
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador OR exclusivo bit a bit: ^
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
expression ^ expression  
```  
  
## Comentários  
 O operador OR exclusivo bit a bit \(**^**\) compara cada bit do primeiro operando ao bit correspondente do seu segundo operando.  Se um bit for 0 e o outro bit for 1, o bit resultante correspondente será definido como 1.  Caso contrário, o bit de resultado correspondente será definido como 0.  
  
 Ambos os operandos para o operador OR exclusivo bit a bit devem ser do tipo integral.  As conversões aritméticas usuais abordadas em [Conversões aritméticas](../misc/arithmetic-conversions.md) são aplicadas aos operandos.  
  
## Palavra\-chave do operador para ^  
 O operador **xor** é o equivalente em texto de **^**.  Há duas maneiras de acessar o operador **xor** em seus programas: incluindo o arquivo de cabeçalho `iso646.h` ou compilando com a opção do compilador [\/Za](../build/reference/za-ze-disable-language-extensions.md) \(Desativar extensões de linguagem\).  
  
## Exemplo  
  
```  
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
  
## Consulte também  
 [Operadores bit a bit C\+\+](../Topic/C++%20Bitwise%20Operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores bit a bit C](../c-language/c-bitwise-operators.md)