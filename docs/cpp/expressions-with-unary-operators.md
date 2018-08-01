---
title: Expressões com operadores unários | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- expressions [C++], unary operators
- unary operators [C++], expressions with
- expressions [C++], operators
ms.assetid: 1217685b-b85d-4b48-9ff4-d90f56a26c1b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 78808ba4ce8d54ecc8e88516ae5f9b2521f50979
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39403973"
---
# <a name="expressions-with-unary-operators"></a>Expressões com operadores unários
Os operadores unários atuam somente em um operando em uma expressão. Os operadores unários são os seguintes:  
  
-   [Operador de indireção (*)](../cpp/indirection-operator-star.md)  
  
-   [Operador address-of (&)](../cpp/address-of-operator-amp.md)  
  
-   [Operador (+) de mais unário](../cpp/unary-plus-and-negation-operators-plus-and.md)  
  
-   [Operador unário de negação (-)](../cpp/unary-plus-and-negation-operators-plus-and.md)  
  
-   [Operador de negação lógica (!)](../cpp/logical-negation-operator-exclpt.md)  
  
-   [Operador de complemento (~)](../cpp/one-s-complement-operator-tilde.md)  
  
-   [Operador de incremento de prefixo (+ +)](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)  
  
-   [Operador de decremento de prefixo (-)](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md)  
  
-   [Operador cast)](../cpp/cast-operator-parens.md)  
  
-   [operador sizeof](../cpp/sizeof-operator.md)  
  
-   [operador uuidof](../cpp/uuidof-operator.md)  
  
-   [operador alignof](../cpp/alignof-operator.md)  
  
-   [novo operador](../cpp/new-operator-cpp.md)  
  
-   [operador Delete](../cpp/delete-operator-cpp.md)  
  
 Esses operadores binários possuem associatividade da direita para a esquerda. As expressões unárias geralmente envolvem a sintaxe que precede uma expressão de sufixo ou primária.  
  
 As formas possíveis de expressões unárias são estas:  
  
-   *postfix-expression*  
  
-   `++` *expressão unária*  
  
-   `--` *expressão unária*  
  
-   *operador unário* *cast-expression*  
  
-   **sizeof** *expressão unária*  
  
-   `sizeof(` *nome do tipo* `)`  
  
-   `decltype(` *Expressão* `)`  
  
-   *expressão de alocação*  
  
-   *expressão de desalocação*  
  
 Qualquer *postfix-expression* é considerada uma *expressão unária*, e porque qualquer expressão primária é considerada uma *postfix-expression*, é de todas as expressões primárias considerado um *expressão unária* também. Para obter mais informações, consulte [expressões pós-fixadas](../cpp/postfix-expressions.md) e [expressões primárias](../cpp/primary-expressions.md).  
  
 Um *operador unário* consiste em um ou mais dos seguintes símbolos: `* & + - ! ~`  
  
 O *cast-expression* é uma expressão unária com uma conversão opcional para alterar o tipo. Para obter mais informações, consulte [operador Cast: ()](../cpp/cast-operator-parens.md).  
  
 Uma *expressão* pode ser qualquer expressão. Para obter mais informações, consulte [expressões](../cpp/expressions-cpp.md).  
  
 O *alocação-expression* refere-se para o **novos** operador. O *desalocação-expression* refere-se para o **excluir** operador. Para obter mais informações, consulte os links anteriores deste tópico.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de expressões](../cpp/types-of-expressions.md)