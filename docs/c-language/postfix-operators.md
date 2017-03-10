---
title: "Operadores pós-fixados | Microsoft Docs"
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
- operators [C], postfix
- postfix operators
ms.assetid: 76260011-1624-484e-8bef-72ae7ab556cc
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
ms.openlocfilehash: c33233bb7a45a1180f50c7a3d109fd2cd70e8318
ms.lasthandoff: 02/25/2017

---
# <a name="postfix-operators"></a>Operadores pós-fixados
Os operadores pós-fixados tem a precedência mais alta (a associação mais estreita) na avaliação da expressão.  
  
## <a name="syntax"></a>Sintaxe  
 *postfix-expression*:  
 *primary-expression*  
  
 *postfix-expression*  **[**  *expression*  **]**  
  
 *postfix-expression*  **(**  *argument-expression-list* opt**)**  
  
 *postfix-expression*  **.**  *identifier*  
  
 *postfix-expression*  **–>**  *identifier*  
  
 *postfix-expression*  **++**  
  
 *postfix-expression*  **––**  
  
 Os operadores nesse nível de precedência são: subscritos de matriz, chamadas de função, membros de estrutura e união, e operadores de incremento e decremento pós-fixados.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores C](../c-language/c-operators.md)
