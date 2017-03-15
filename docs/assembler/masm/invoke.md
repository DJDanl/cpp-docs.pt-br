---
title: "INVOKE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "Invoke"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "INVOKE directive"
ms.assetid: 12d9bb40-33b9-411e-b801-45a1d675967e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# INVOKE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chama o procedimento no endereço dado por  *expressão*, passando os argumentos na pilha ou em registros de acordo com as convenções de chamada padrão do tipo de idioma.  
  
## Sintaxe  
  
```  
  
INVOKE   
expression [[, arguments]]  
```  
  
## Comentários  
 Cada argumento passado para o procedimento pode ser uma expressão, um par de registro ou uma expressão de endereço \(precedido de uma expressão `ADDR`\).  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)