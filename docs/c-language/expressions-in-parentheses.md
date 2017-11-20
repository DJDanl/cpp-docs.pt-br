---
title: "Expressões em parênteses | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- parentheses
- expression evaluation, evaluation order
- expressions [C++], evaluating
- parentheses, expressions
ms.assetid: b8636147-6982-408c-9e64-29e40678ee43
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: dd05385c8753414403116704f15e26bf9486cf14
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="expressions-in-parentheses"></a>Expressões em parênteses
É possível colocar qualquer operando entre parênteses sem alterar o tipo ou o valor da expressão dentro deles. Por exemplo, na expressão:  
  
```  
( 10 + 5 ) / 5  
```  
  
 os parênteses que delimitam `10 + 5` significam que o valor de `10 + 5` é avaliado primeiro e se torna o operando à esquerda do operador de divisão (**/**). O resultado de `( 10 + 5 ) / 5` será 3. Sem os parênteses, `10 + 5 / 5` seria avaliado como 11.  
  
 Embora os parênteses afetem a maneira como os operandos são agrupados em uma expressão, eles não podem assegurar uma determinada ordem de avaliação em todos os casos. Por exemplo, nem os parênteses ou o agrupamento da esquerda para a direita da seguinte expressão assegura que o valor de `i` esteja em qualquer uma das subexpressões:  
  
```  
( i++ +1 ) * ( 2 + i )  
```  
  
 O compilador é livre para avaliar os dois lados da multiplicação em qualquer ordem. Se o valor inicial de `i` for zero, toda a expressão pode ser avaliada como qualquer uma destas duas instruções:  
  
```  
( 0 + 1 + 1 ) * ( 2 + 1 )   
( 0 + 1 + 1 ) * ( 2 + 0 )  
```  
  
 As exceções que resultam dos efeitos colaterais são discutidas em [Efeitos colaterais](../c-language/side-effects.md).  
  
## <a name="see-also"></a>Consulte também  
 [Expressões primárias C](../c-language/c-primary-expressions.md)