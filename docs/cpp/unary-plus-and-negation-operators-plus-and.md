---
title: "Operadores un&#225;rios de adi&#231;&#227;o e de nega&#231;&#227;o: + e - | Microsoft Docs"
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
  - "+"
  - "-"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador -"
  - "Operador +"
  - "Operador +, operadores unários"
  - "Operador de negação"
  - "operadores unários, plus"
ms.assetid: 2c58c4f4-0d92-4ae3-9d0c-1a6157875cc1
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores un&#225;rios de adi&#231;&#227;o e de nega&#231;&#227;o: + e -
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
+ cast-expression  
```  
  
```  
  
- cast-expression  
  
```  
  
## Operador \+  
 O resultado do operador de adição unário \(**\+**\) é o valor do operando.  O operando para o operador de adição unário deve ser de um tipo aritmético.  
  
 A promoção integral é executada em operandos integrais.  O tipo resultante é o tipo para o qual o operando é promovido.  Assim, a expressão `+ch`, onde `ch` é do tipo `char`, resulta no tipo `int`; o valor é inalterado.  Consulte [Promoções de integral](../misc/integral-promotions.md) para obter mais informações sobre como a promoção é feita.  
  
## Operador \-  
 O operador de negação unário \(**–**\) produz o negativo do seu operando.  O operando para o operador de negação unário deve ser um tipo aritmético.  
  
 A promoção de integral é executada em operandos integrais, e o tipo resultante é o tipo para o qual o operando é promovido.  Consulte [Promoções de integral](../misc/integral-promotions.md) para obter mais informações sobre como a promoção é realizada.  
  
## específica da Microsoft  
 A negação unária de quantidades não assinadas é executada subtraindo o valor do operando de 2^n, onde n é o número de bits em um objeto de um determinado tipo sem assinatura.  \(O Microsoft C\+\+ é executado em processadores que utilizam aritmética de complementos de dois.  Em outros processadores, o algoritmo para o operador pode ser diferente.\)  
  
## Consulte também  
 [Expressões com operadores unários](../Topic/Expressions%20with%20Unary%20Operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)