---
title: "Operadores aritm&#233;ticos un&#225;rios | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Operador !, operadores aritméticos unários"
  - "Operador ~, Operador de complemento de um"
  - "Operador +, operadores unários"
  - "operadores aritméticos [C++], unário"
  - "Operador de complemento bit a bit"
  - "pontos de exclamação"
  - "negação lógica"
  - "operadores [C], unário"
  - "Operador de complemento de um til (~)"
  - "operadores unários"
ms.assetid: 78c91415-d469-499e-9dfe-4435350fd333
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores aritm&#233;ticos un&#225;rios
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Vários operadores do C – unário de adição, de negação aritmética, de complemento e de negação lógica – são discutidos na lista a seguir:  
  
|Operador|Descrição|  
|--------------|---------------|  
|**\+**|O operador unário de adição que precede uma expressão entre parênteses força o agrupamento das operações incluídas.  É usado com expressões que envolvem mais de um operador binário associativo ou comutativo.  O operando deve ser do tipo aritmético.  O resultado é o valor do operando.  Um operando de integral passa por uma promoção de integral.  O tipo do resultado é o tipo do operando promovido.|  
|**–**|O operador de negação aritmética produz o negativo \(complemento de dois\) do respectivo operando.  O operando deve ser um valor de integral ou flutuante.  Este operador executa as conversões aritméticas comuns.|  
|`~`|O operador de complemento bit a bit \(ou NOT bit a bit\) produz o complemento bit a bit do respectivo operando.  O operando deve ser do tipo integral.  Este operador executa as conversões aritméticas comuns; o resultado tem o tipo do operando após a conversão.|  
|**\!**|O operador de negação lógica \(NOT lógico\) produz o valor 0 se o operando é verdadeiro \(diferente de zero\) e o valor 1 se o operando é falso \(0\).  O resultado tem o tipo `int`.  O operando deve ser um valor de ponteiro, integral ou flutuante.|  
  
 Operações aritméticas unárias em ponteiros não são válidas.  
  
## Exemplos  
 Os exemplos a seguir ilustram os operadores aritméticos unários:  
  
```  
short x = 987;  
    x = -x;  
```  
  
 No exemplo acima, o novo valor de `x` é o negativo de 987, ou seja, –987.  
  
```  
unsigned short y = 0xAAAA;  
    y = ~y;  
```  
  
 Nesse exemplo, o novo valor atribuído a `y` é o complemento de um do valor sem sinal 0xAAAA, ou 0x5555.  
  
```  
if( !(x < y) )  
```  
  
 Se `x` é maior ou igual a `y`, o resultado da expressão é 1 \(verdadeiro\).  Se `x` é menor que `y`, o resultado é 0 \(falso\).  
  
## Consulte também  
 [Expressões com operadores unários](../Topic/Expressions%20with%20Unary%20Operators.md)