---
title: "C3551 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C3551"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3551"
ms.assetid: c8ee23da-6568-40db-93a6-3ddb7ac47712
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3551 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

"esperado que um final de tipo de retorno especificado"  
  
 Se você usar o `auto` palavra\-chave como um espaço reservado para o tipo de retorno de uma função, você deve fornecer um tipo de retorno especificado tardia. No exemplo a seguir, a especificação tardia tipo de retorno da função `myFunction` é um ponteiro para uma matriz de quatro elementos do tipo `int`.  
  
```  
auto myFunction()->int(*)[4];   
```  
  
## Consulte também  
 [auto](../../cpp/auto-cpp.md)