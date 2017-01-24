---
title: "Operador AND bit a bit: &amp; | Microsoft Docs"
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
  - "bitand"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador &, operadores bit a bit"
  - "Operador AND"
  - "operadores bit a bit, Operador AND"
ms.assetid: 76f40de3-c417-47b9-8a77-532f3fc990a5
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador AND bit a bit: &amp;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
expression   
&  
 expression  
  
```  
  
## Comentários  
 As expressões podem ser outras expressões E, ou \(sujeito às restrições de tipo mencionadas abaixo\) expressões de igualdade, expressões relacionais, expressões aditivas, expressões multiplicativas, expressões de ponteiro para membro, expressões de conversão, expressões unárias, expressões pós\-fixadas ou expressões primárias.  
  
 O operador E bit a bit \(**&**\) compara cada bit do primeiro operando com o bit correspondente do segundo operando.  Se os dois bits forem 1, o bit de resultado correspondente será definido como 1.  Caso contrário, o bit de resultado correspondente será definido como 0.  
  
 Os dois operandos do operador AND bit a bit devem ser de tipos integrais.  As conversões aritméticas usuais abordadas em [Conversões aritméticas](../misc/arithmetic-conversions.md) são aplicadas aos operandos.  
  
## Palavra\-chave de operador para &  
 O operador `bitand` é o equivalente de texto a **&**.  Há duas maneiras de acessar o operador `bitand` nos programas: incluindo o arquivo de cabeçalho `iso646.h` ou compilando com a opção de compilador [\/Za](../build/reference/za-ze-disable-language-extensions.md) \(Desabilitar extensões de linguagem\).  
  
## Exemplo  
  
```  
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
  
## Consulte também  
 [Operadores bit a bit C\+\+](../Topic/C++%20Bitwise%20Operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores bit a bit C](../c-language/c-bitwise-operators.md)