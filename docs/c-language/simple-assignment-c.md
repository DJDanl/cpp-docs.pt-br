---
title: "Atribuição simples (C) | Microsoft Docs"
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
- type conversion [C++], simple assignment
- data type conversion [C++], simple assignment
- operators [C], simple assignment
- assignment operators [C++], simple
- simple assignment operator
- equal sign
ms.assetid: e7140a0a-7104-4b3a-b293-7adcc1fdd52b
caps.latest.revision: 7
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
ms.openlocfilehash: f409498b6b9bca171c3c25d8141e7f272db2844a
ms.lasthandoff: 02/25/2017

---
# <a name="simple-assignment-c"></a>Atribuição simples (C)
O operador de atribuição simples atribui o operando à direita ao operando à esquerda. O valor do operando à direita é convertido no tipo da expressão de atribuição e substituir o valor armazenado no objeto designado pelo operando à esquerda. As regras de conversão para a atribuição se aplicam (consulte [Conversões de atribuição](../c-language/assignment-conversions.md)).  
  
```  
double x;  
int y;  
  
x = y;  
```  
  
 Neste exemplo, o valor de `y` é convertido para o tipo **double** e é atribuído a `x`.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores de atribuição C](../c-language/c-assignment-operators.md)
