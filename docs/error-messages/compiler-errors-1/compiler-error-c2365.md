---
title: "C2365 de erro do compilador | Microsoft Docs"
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
  - "C2365"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2365"
ms.assetid: 35839b0b-4055-4b79-8957-b3a0871bdd02
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2365 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'membro da classe ': redefinição; definição anterior foi 'membro da classe '  
  
 Tentativa de redefinir um membro de classe.  
  
 O exemplo a seguir gera C2365.  
  
```  
// C2365.cpp // compile with: /c class C1 { int CFunc(); char *CFunc;   // C2365, already exists as a member function int CMem; char *CMem();   // C2365, already exists as a data member };  
```