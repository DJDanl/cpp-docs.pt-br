---
title: "C2903 de erro do compilador | Microsoft Docs"
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
  - "C2903"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2903"
ms.assetid: bf6b223f-4921-48c7-82b9-ff318b42c801
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2903 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'identifier': símbolo não é um modelo de classe nem um modelo de função  
  
 Código de tentativas de instanciação explícita de algo que não é um modelo.  
  
 O exemplo a seguir gera C2903:  
  
```  
// C2903.cpp // compile with: /c namespace N { template<class T> class X {}; class Y {}; } void g() { N::template Y y;   // C2903 N::X<N::Y> y;   // OK }  
```  
  
 C2903 também pode ocorrer ao usar genéricos:  
  
```  
// C2903b.cpp // compile with: /clr /c namespace N { class Y {}; generic<class T> ref class Z {}; } void f() { N::generic Y y;   // C2903 N:: generic Z<int>^ z;   // OK }  
```