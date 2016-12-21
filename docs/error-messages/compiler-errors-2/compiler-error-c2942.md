---
title: "C2942 de erro do compilador | Microsoft Docs"
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
  - "C2942"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2942"
ms.assetid: 13abf744-8fa1-450d-886d-e5717c04956e
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2942 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'class': id de classe de tipo é redefinida como um argumento formal de uma função  
  
 Você não pode usar uma classe genérica ou um modelo como um argumento formal. Você não pode passar um argumento diretamente para o construtor de um genérico ou classe de modelo.  
  
 O exemplo a seguir gera C2942:  
  
```  
  
// C2942.cpp // compile with: /c template<class T> struct TC {}; void f(int TC<int>) {}   // C2942 // OK struct TC2 {}; void f(TC2 i) {}  
```  
  
 C2942 também pode ocorrer ao usar genéricos:  
  
```  
// C2942b.cpp // compile with: /clr /c generic<class T> ref struct GC {}; void f(int GC<int>) {}   // C2942 ref struct GC2 { }; void f(int GC2) {}  
```