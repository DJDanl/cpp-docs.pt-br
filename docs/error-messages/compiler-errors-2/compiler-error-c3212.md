---
title: "C3212 de erro do compilador | Microsoft Docs"
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
  - "C3212"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3212"
ms.assetid: 9e271bb6-a51f-4b96-b26b-9f4ca28fca0a
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3212 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'especialização': uma especialização explícita de um membro de modelo deve ser um membro de uma especialização explícita  
  
 Uma especialização explícita ill foi formada.  
  
 O exemplo a seguir gera C3212:  
  
```  
// C3212.cpp // compile with: /LD template <class T> struct S { template <class T1> struct S1; }; template <class T>   // C3212 template <> struct S<T>::S1<int> {}; /* // try the following instead template <> template <> struct S<int>::S1<int> {}; */ /* // or, the following template <> struct S<int> { template <class T1> struct S1; }; template <> struct S<int>::S1<int> { }; */  
```