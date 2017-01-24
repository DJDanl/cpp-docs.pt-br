---
title: "C2940 de erro do compilador | Microsoft Docs"
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
  - "C2940"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2940"
ms.assetid: af6bf2bf-8de6-4cfd-bbf0-4c6b32a30edf
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2940 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'class': id de classe de tipo é redefinida como um typedef local  
  
 Você não pode usar uma classe genérica ou um modelo como um local `typedef`.  
  
 O exemplo a seguir gera C2940:  
  
```  
// C2940.cpp template<class T> struct TC {}; int main() { typedef int TC<int>;   // C2940 typedef int TC;   // OK }  
```  
  
 C2940 também pode ocorrer ao usar genéricos:  
  
```  
// C2940b.cpp // compile with: /clr generic<class T> ref struct GC { }; int main() { typedef int GC<int>;   // C2940 typedef int GC; }  
```