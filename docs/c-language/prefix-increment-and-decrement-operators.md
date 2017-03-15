---
title: "Operadores de incremento e de decremento pré-fixados | Microsoft Docs"
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
- increment operators, types of
- decrement operators, syntax
- decrement operators
ms.assetid: 9a441bb9-d94a-4b6a-9db2-0d0d76bc480d
caps.latest.revision: 6
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 21a1a92e3554e207a00ceaf583d3dd63ffda0c7f
ms.lasthandoff: 02/25/2017

---
# <a name="prefix-increment-and-decrement-operators"></a>Operadores de incremento e de decremento pré-fixados
Os operadores unários (`++` e **––**) são chamados de operadores de incremento ou decremento "pré-fixados" quando os operadores de incremento ou decremento aparecem antes do operando. O incremento e a diminuição de pós-fixação têm precedência maior que o incremento e a diminuição de prefixo. O operando deve ter tipo integral, flutuante ou de ponteiro e deve ser uma expressão I-value modificável (uma expressão sem o atributo **const**). O resultado é um l-value.  
  
 Quando o operador aparecer antes de seu operando, o operando será incrementado ou diminuído, e seu novo valor será o resultado da expressão.  
  
 Um operando tipo integral ou flutuante é incrementado ou decrementado pelo valor inteiro 1. O tipo do resultado é igual ao tipo do operando. Um operando do tipo ponteiro é incrementado ou decrementado pelo tamanho do objeto pertinente. Um ponteiro incrementado aponta para o próximo objeto;um ponteiro decrementado aponta para o objeto anterior.  
  
## <a name="example"></a>Exemplo  
 Este exemplo ilustra o operador unário de diminuição de prefixo:  
  
```  
if( line[--i] != '\n' )  
    return;  
```  
  
 Neste exemplo, a variável `i` é diminuída antes de ser usada como um subscrito para `line`.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores unários C](../c-language/c-unary-operators.md)
