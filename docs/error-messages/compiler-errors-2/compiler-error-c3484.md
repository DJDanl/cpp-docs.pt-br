---
title: "C3484 de erro do compilador | Microsoft Docs"
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
  - "C3484"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3484"
ms.assetid: 2fe847fa-f6ee-4978-bc1d-b6dc6ae906ac
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3484 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

esperado '\-\>' antes do tipo de retorno  
  
 Você deve fornecer `->` antes do tipo de retorno de uma expressão lambda.  
  
### Para corrigir este erro  
  
-   Fornecer `->` antes do tipo de retorno.  
  
## Exemplo  
 O exemplo a seguir gera C3484:  
  
```  
// C3484a.cpp int main() { return []() . int { return 42; }(); // C3484 }  
```  
  
## Exemplo  
 O exemplo a seguir resolve C3484 fornecendo `->` antes do tipo de retorno da expressão lambda:  
  
```  
// C3484b.cpp int main() { return []() -> int { return 42; }(); }  
```  
  
## Consulte também  
 [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)