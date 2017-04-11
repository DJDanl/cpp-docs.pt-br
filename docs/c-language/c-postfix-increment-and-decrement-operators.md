---
title: "Operadores de incremento e de decremento pós-fixados C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- increment operators, syntax
- scalar operators
- types [C], scalar
ms.assetid: 56ba218d-65f9-405f-8684-caccc0ca33aa
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: a67e01fe0555a628c8b2178cc580bcaa8f84cd83
ms.lasthandoff: 04/01/2017

---
# <a name="c-postfix-increment-and-decrement-operators"></a>Operadores de incremento e de decremento pós-fixados C
Os operandos dos operadores de incremento e decremento pós-fixados são tipos escalares que são l-values modificáveis.  
  
## <a name="syntax"></a>Sintaxe  
 *postfix-expression*:  
 *postfix-expression*  **++**  
  
 *postfix-expression*  **--**  
  
 O resultado da operação de incremento ou decremento pós-fixada é o valor do operando. Depois que o resultado é obtido, o valor do operando é incrementado (ou decrementado). O código a seguir ilustra o operador de incremento pós-fixado.  
  
```  
if( var++ > 0 )  
    *p++ = *q++;  
```  
  
 Nesse exemplo, a variável `var` é comparada a 0 e depois incrementada. Se `var` era positiva antes de ser incrementada, a próxima instrução é executada. Primeiro, o valor do objeto para o qual `q` aponta é atribuído ao objeto para o qual `p` aponta. Em seguida, `q` e `p` são incrementados.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores de incremento e de decremento pós-fixados: ++ e --](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)
