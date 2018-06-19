---
title: Instrução de expressão (C) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- statements, expression
- expression statements
ms.assetid: 1085982b-dc16-4c1e-9ddd-0cd85c8fe2e3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 18d28cdc695ae600616d63575328eeaf171bc28c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32385891"
---
# <a name="expression-statement-c"></a>Instrução de expressão (C)
Quando uma instrução de expressão é executada, ela é avaliada de acordo com as regras descritas em [Expressões e atribuições](../c-language/expressions-and-assignments.md).  
  
## <a name="syntax"></a>Sintaxe  
 *expression-statement*:  
 *expression* opt **;**  
  
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