---
title: "Instru&#231;&#227;o de express&#227;o (C) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "instruções de expressão"
  - "instruções, expressão"
ms.assetid: 1085982b-dc16-4c1e-9ddd-0cd85c8fe2e3
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o de express&#227;o (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando uma instrução de expressão é executada, a expressão é avaliada de acordo com as regras descritas em [Expressões e atribuições](../c-language/expressions-and-assignments.md).  
  
## Sintaxe  
 *expression\-statement*:  
 *expression*  opt **;**  
  
 Todos os efeitos colaterais de avaliação da expressão são concluídos antes de a próxima instrução ser executada.  Uma instrução expression vazia é chamada de instrução null.  Consulte [A instrução null](../c-language/null-statement-c.md) para obter mais informações.  
  
 Estes exemplos demonstram instruções expression.  
  
```  
x = ( y + 3 );            /* x is assigned the value of y + 3  */  
x++;                      /* x is incremented                  */  
x = y = 0;                /* Both x and y are initialized to 0 */  
proc( arg1, arg2 );       /* Function call returning void      */  
y = z = ( f( x ) + 3 );   /* A function-call expression        */  
```  
  
 Na última instrução, a expressão de chamada de função, o valor da expressão, que inclui os valores retornados pela função, é aumentada em 3 e atribuída às duas variáveis `y` e `z`.  
  
## Consulte também  
 [Instruções](../c-language/statements-c.md)