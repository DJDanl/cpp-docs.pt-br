---
title: "Instrução de expressão (C) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- statements, expression
- expression statements
ms.assetid: 1085982b-dc16-4c1e-9ddd-0cd85c8fe2e3
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 75bad42ddff5f20d14d627e3f036659f030bb3f5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="expression-statement-c"></a>Instrução de expressão (C)
Quando uma instrução de expressão é executada, ela é avaliada de acordo com as regras descritas em [Expressões e atribuições](../c-language/expressions-and-assignments.md).  
  
## <a name="syntax"></a>Sintaxe  
 *expression-statement*:  
 *expression* opt**;**  
  
 Todos os efeitos colaterais de avaliação da expressão são concluídos antes de a próxima instrução ser executada. Uma instrução expression vazia é chamada de instrução null. Consulte [A instrução null](../c-language/null-statement-c.md) para obter mais informações.  
  
 Estes exemplos demonstram instruções expression.  
  
```  
x = ( y + 3 );            /* x is assigned the value of y + 3  */  
x++;                      /* x is incremented                  */  
x = y = 0;                /* Both x and y are initialized to 0 */  
proc( arg1, arg2 );       /* Function call returning void      */  
y = z = ( f( x ) + 3 );   /* A function-call expression        */  
```  
  
 Na última instrução, a expressão de chamada de função, o valor da expressão, que inclui os valores retornados pela função, é aumentada em 3 e atribuída às duas variáveis `y` e `z`.  
  
## <a name="see-also"></a>Consulte também  
 [Instruções](../c-language/statements-c.md)