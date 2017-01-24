---
title: "Operador de complemento individual: ~ | Microsoft Docs"
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
  - "~"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador ~, sintaxe"
  - "Operador de complemento bit a bit"
  - "Operador compl"
  - "Operador de complemento de um"
  - "Operador de complemento de um til (~)"
ms.assetid: 4bf81967-34f7-4b4b-aade-fd03d5da0174
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador de complemento individual: ~
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
~ cast-expression  
```  
  
## Comentários  
 O operador de complemento de um \(`~`\), às vezes chamado de operador de “complemento bit a bit”, gera um complemento bit a bit de seu operando.  Ou seja, cada bit que é 1 no operando, é 0 no resultado.  De forma análoga, cada bit que é 0 no operando, é 1 no resultado.  O operando para o operador de complemento de um deve ser um tipo integral.  
  
## Palavra\-chave do operador para ~  
 O operador `compl` é o equivalente de texto de `~`.  Há duas maneiras de acessar o operador `compl` nos programas: incluindo o arquivo de cabeçalho `iso646.h` ou compilando com [\/Za](../build/reference/za-ze-disable-language-extensions.md).  
  
## Exemplo  
  
```  
// expre_One_Complement_Operator.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
  
int main () {  
   unsigned short y = 0xFFFF;  
   cout << hex << y << endl;  
   y = ~y;   // Take one's complement  
   cout << hex << y << endl;  
}  
```  
  
 Nesse exemplo, o novo valor atribuído a `y` é o complemento de um do valor sem sinal 0xFFFF, ou 0x0000.  
  
 A promoção de integral é executada em operandos integrais, e o tipo resultante é o tipo para o qual o operando é promovido.  Consulte [Promoções de integral](../misc/integral-promotions.md) para obter mais informações sobre como a promoção é feita.  
  
## Consulte também  
 [Expressões com operadores unários](../Topic/Expressions%20with%20Unary%20Operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores aritméticos unários](../c-language/unary-arithmetic-operators.md)