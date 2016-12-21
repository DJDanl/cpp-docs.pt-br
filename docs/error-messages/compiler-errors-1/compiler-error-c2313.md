---
title: "C2313 de erro do compilador | Microsoft Docs"
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
  - "C2313"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2313"
ms.assetid: f70eb19b-c0a3-4fb2-ade1-3890a589928d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2313 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type1': capturadas por referência \('type2'\) no número de linha  
  
 O tipo de exceção tem dois manipuladores. O tipo para o segundo problema é uma referência para o tipo do primeiro.  
  
 O exemplo a seguir gera C2313:  
  
```  
// C2313.cpp // compile with: /EHsc #include <eh.h> class C {}; int main() { try { throw "ooops!"; } catch( C& ) {} catch( C ) {}   // C2313 }  
```