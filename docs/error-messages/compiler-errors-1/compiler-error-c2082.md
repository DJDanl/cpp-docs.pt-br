---
title: "C2082 de erro do compilador | Microsoft Docs"
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
  - "C2082"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2082"
ms.assetid: 87a6d442-157c-46e8-9bff-8388f8338ae0
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2082 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

redefinição do parâmetro formal 'Identificador'  
  
 Um parâmetro formal para uma função é declarado novamente dentro do corpo da função. Para resolver o erro, remova a redefinição.  
  
 O exemplo a seguir gera C2082:  
  
```  
// C2082.cpp void func(int i) { int i;   // C2082 int ii;   // OK }  
```