---
title: "C2317 de erro do compilador | Microsoft Docs"
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
  - "C2317"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2317"
ms.assetid: e44d129b-8d3e-4ce9-9d79-6791ee77f25e
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2317 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

bloco 'try' começando na linha 'number' não tem nenhum manipuladores catch  
  
 Um `try` bloco deve ter pelo menos um manipulador catch.  
  
 O exemplo a seguir gera C2317:  
  
```  
// C2317.cpp // compile with: /EHsc #include <eh.h> int main() { try { throw "throw an exception"; } // C2317, no catch handler }  
```  
  
 Resolução possível:  
  
```  
// C2317b.cpp // compile with: /EHsc #include <eh.h> int main() { try { throw "throw an exception"; } catch(char*) {} }  
```