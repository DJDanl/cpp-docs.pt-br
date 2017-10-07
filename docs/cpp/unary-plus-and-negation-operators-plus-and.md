---
title: "Adição unária e operadores de negação: + e - | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- +
- '-'
dev_langs:
- C++
helpviewer_keywords:
- unary operators [C++], plus
- '- operator'
- negation operator
- + operator [C++], unary operators
- + operator
ms.assetid: 2c58c4f4-0d92-4ae3-9d0c-1a6157875cc1
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 9c664cd382685693da7ab12ba85891bc2ab0d7e8
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="unary-plus-and-negation-operators--and--"></a>Operadores unários de adição e de negação: + e -
## <a name="syntax"></a>Sintaxe  
  
```  
  
+ cast-expression  
```  
  
```  
  
- cast-expression  
```  
  
## <a name="-operator"></a>Operador +  
 O resultado do operador de adição unária (**+**) é o valor de seu operando. O operando para o operador de adição unário deve ser de um tipo aritmético.  
  
 A promoção integral é executada em operandos integrais. O tipo resultante é o tipo para o qual o operando é promovido. Assim, a expressão `+ch`, onde `ch` é do tipo `char`, resulta no tipo `int`; o valor é inalterado. Consulte [conversões padrão](standard-conversions.md) para obter mais informações sobre como a promoção é feita.  
  
## <a name="--operator"></a>Operador -  
 O operador de negação unário (**-**) produz o negativo do seu operando. O operando para o operador de negação unário deve ser um tipo aritmético.  
  
 A promoção de integral é executada em operandos integrais, e o tipo resultante é o tipo para o qual o operando é promovido. Consulte [conversões padrão](standard-conversions.md) para obter mais informações sobre como a promoção é executada.  
  
## <a name="microsoft-specific"></a>específica da Microsoft  
 A negação unária de quantidades não assinadas é executada subtraindo o valor do operando de 2^n, onde n é o número de bits em um objeto de um determinado tipo sem assinatura. (O Microsoft C++ é executado em processadores que utilizam aritmética de complementos de dois. Em outros processadores, o algoritmo para o operador pode ser diferente.)  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)   
 [Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)
