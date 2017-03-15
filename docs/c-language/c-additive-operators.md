---
title: Operadores aditivos C | Microsoft Docs
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
- usual arithmetic conversions
- operators [C], addition
- + operator, additive operators
- additive operators
- arithmetic operators [C++], additive operators
ms.assetid: bb8ac205-b061-41fc-8dd4-dab87c8b900c
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 84982ec6364a47182a54752ae50bad12bb84232a
ms.lasthandoff: 02/25/2017

---
# <a name="c-additive-operators"></a>Operadores aditivos C
Os operadores aditivos executam adição (**+**) e subtração (**–**).  
  
## <a name="syntax"></a>Sintaxe  
 *additive-expression*:  
 *multiplicative-expression*  
  
 *additive-expression*  **+**  *multiplicative-expression*  
  
 *additive-expression*  **–**  *multiplicative-expression*  
  
> [!NOTE]
>  Embora a sintaxe de *additive-expression* inclua *multiplicative-expression*, isso não significa que expressões que usam multiplicação sejam necessárias. Consulte a sintaxe em [Resumo de sintaxe da linguagem C](../c-language/c-language-syntax-summary.md), para *multiplicative-expression*, *cast-expression* e *unary-expression*.  
  
 Os operandos podem ser valores integrais ou flutuantes. Algumas operações aditivas também podem ser executadas em valores de ponteiro, como descrito na discussão de cada operador.  
  
 Os operadores aditivos executam as conversões aritméticas comuns em operandos do tipo integral ou flutuantes. O tipo do resultado é o tipo dos operandos após conversão. Como as conversões executadas pelos operadores aditivos não fornecem condições de estouro ou de estouro negativo, as informações podem ser perdidas se o resultado de uma operação aditiva não puder ser representado no tipo dos operandos após a conversão.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores aditivos: + e -](../cpp/additive-operators-plus-and.md)
