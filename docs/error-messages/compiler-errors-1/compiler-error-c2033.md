---
title: "C2033 de erro do compilador | Microsoft Docs"
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
  - "C2033"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2033"
ms.assetid: fd5a1637-9db2-4c98-a7cc-b63b39737cd9
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2033 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'identifier': campo de bits não pode ter indireção  
  
 O campo de bit foi declarado como um ponteiro, o que não é permitido.  
  
 O exemplo a seguir gera C2033:  
  
```  
// C2033.cpp struct S { int *b : 1;  // C2033 };  
```  
  
 Resolução possível:  
  
```  
// C2033b.cpp // compile with: /c struct S { int b : 1; };  
```