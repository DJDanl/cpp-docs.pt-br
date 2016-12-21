---
title: "Operador OR inclusivo bit a bit: | | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "bitor"
  - "|"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador |"
  - "operadores bit a bit, Operador OR"
  - "Operador OR inclusivo"
  - "Operador OR, inclusivo bit a bit"
ms.assetid: 4c8a6a68-d828-447d-875a-aedb4ce3aa9a
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador OR inclusivo bit a bit: |
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
expression   
|  
 expression  
  
```  
  
## Comentários  
 O operador OR inclusivo de bit a bit \(         **&#124;** \) compara cada bit do primeiro operando com o bit correspondente de seu segundo operando.  Se um bit for 1, o bit de resultado correspondente será definido como 1.  Caso contrário, o bit de resultado correspondente será definido como 0.  
  
 Ambos os operandos para o operador OR inclusivo bit a bit devem ser do tipo integral.  As conversões aritméticas usuais abordadas em [Conversões aritméticas](../misc/arithmetic-conversions.md) são aplicadas aos operandos.  
  
## Palavra\-chave do operador para &#124;  
 O operador `bitor` é o equivalente de texto de              **&#124;** .  Há duas maneiras de acessar o operador `bitor` nos programas: incluindo o arquivo de cabeçalho `iso646.h` ou compilando com a opção do compilador [\/Za](../build/reference/za-ze-disable-language-extensions.md) \(Desabilitar extensões de linguagem\).  
  
## Exemplo  
  
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
  
## Consulte também  
 [Operadores bit a bit C\+\+](../Topic/C++%20Bitwise%20Operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores bit a bit C](../c-language/c-bitwise-operators.md)