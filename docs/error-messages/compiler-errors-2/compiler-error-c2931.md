---
title: "C2931 de erro do compilador | Microsoft Docs"
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
  - "C2931"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2931"
ms.assetid: 33430407-b149-4ba3-baf8-b0dae1ea3a5d
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2931 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'class': id de classe de tipo é redefinida como uma função de membro de 'Identificador'  
  
 Você não pode usar uma classe genérica ou modelo como uma função de membro de outra classe.  
  
 Esse erro pode ser causado se chaves serão comparados incorretamente.  
  
 O exemplo a seguir gera C2931:  
  
```  
// C2931.cpp // compile with: /c template<class T> struct TC { }; struct MyStruct { void TC<int>();   // C2931 }; struct TC2 { }; struct MyStruct2 { void TC2(); };  
```  
  
 C2931 também pode ocorrer ao usar genéricos:  
  
```  
// C2931b.cpp // compile with: /clr /c generic<class T> ref struct GC {}; struct MyStruct { void GC<int>();   // C2931 void GC2();   // OK };  
```