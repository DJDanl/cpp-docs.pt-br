---
title: "Expressões com operadores unários | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- expressions [C++], unary operators
- unary operators [C++], expressions with
- expressions [C++], operators
ms.assetid: 1217685b-b85d-4b48-9ff4-d90f56a26c1b
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: adde5e6fdb20924b633de60eba07390edad57907
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="expressions-with-unary-operators"></a>Expressões com operadores unários
Os operadores unários atuam somente em um operando em uma expressão. Os operadores unários são os seguintes:  
  
-   [Operador de indireção (*)](../cpp/indirection-operator-star.md)  
  
-   [Operador address-of (&)](../cpp/address-of-operator-amp.md)  
  
-   [Operador (+) de adição unária](../cpp/unary-plus-and-negation-operators-plus-and.md)  
  
-   [Operador unário de negação (-)](../cpp/unary-plus-and-negation-operators-plus-and.md)  
  
-   [Operador de negação lógica (!)](../cpp/logical-negation-operator-exclpt.md)  
  
-   [Operador de complemento (~)](../cpp/one-s-complement-operator-tilde.md)  
  
-   [Prefixo de operador de incremento (+ +)](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)  
  
-   [Operador de decremento de prefixo (-)](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)  
  
-   [Operador de conversão)](../cpp/cast-operator-parens.md)  
  
-   [operador sizeof](../cpp/sizeof-operator.md)  
  
-   [operador de uuidof](../cpp/uuidof-operator.md)  
  
-   [operador alignof](../cpp/alignof-operator.md)  
  
-   [novo operador](../cpp/new-operator-cpp.md)  
  
-   [operador Delete](../cpp/delete-operator-cpp.md)  
  
 Esses operadores binários possuem associatividade da direita para a esquerda. As expressões unárias geralmente envolvem a sintaxe que precede uma expressão de sufixo ou primária.  
  
 As formas possíveis de expressões unárias são estas:  
  
-   *postfix-expression*  
  
-   `++`*expressão unária*  
  
-   `--`*expressão unária*  
  
-   *operador unário* *expressão de conversão*  
  
-   `sizeof`*expressão unária*  
  
-   `sizeof(`*nome do tipo*`)`  
  
-   `decltype(`*expressão*`)`  
  
-   *expressão de alocação*  
  
-   *expressão de desalocação*  
  
 Qualquer *sufixo expressão* é considerado um *expressão unária*, e porque qualquer expressão primário é considerado um *sufixo expressão*, é qualquer expressões primárias considerado um *expressão unária* também. Para obter mais informações, consulte [expressões de sufixo](../cpp/postfix-expressions.md) e [expressões primárias](../cpp/primary-expressions.md).  
  
 Um *operador unário* consiste em um ou mais dos seguintes símbolos:`* & + - ! ~`  
  
 O *expressão de conversão* é uma expressão unária com uma conversão opcional para alterar o tipo. Para obter mais informações, consulte [operador Cast: ()](../cpp/cast-operator-parens.md).  
  
 Um *expressão* pode ser qualquer expressão. Para obter mais informações, consulte [expressões](../cpp/expressions-cpp.md).  
  
 O *alocação expressão* refere-se para o `new` operador. O *desalocação expressão* refere-se para o `delete` operador. Para obter mais informações, consulte os links anteriores deste tópico.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de expressões](../cpp/types-of-expressions.md)
