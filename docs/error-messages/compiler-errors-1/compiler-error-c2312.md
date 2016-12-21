---
title: "C2312 de erro do compilador | Microsoft Docs"
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
  - "C2312"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2312"
ms.assetid: c8bcfd06-12c1-4323-bb53-ba392d36daa4
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2312 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'exception1': detectada pelo Licença2 no número de linha  
  
 Dois manipuladores catch do mesmo tipo de exceção.  
  
 O exemplo a seguir gera C2312:  
  
```  
// C2312.cpp // compile with: /EHsc #include <eh.h> int main() { try { throw "ooops!"; } catch( signed int ) {} catch( int ) {}   // C2312 }  
```