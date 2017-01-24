---
title: "Erro fatal C1020 | Microsoft Docs"
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
  - "C1020"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1020"
ms.assetid: 42f429e2-5e3b-4086-a10d-b99e032e51c5
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1020
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

\#endif inesperado  
  
 A `#endif` diretiva não tem nenhuma correspondência `#if`, `#ifdef`, ou `#ifndef` diretiva. Ser\-se de que cada `#endif` tem uma diretiva correspondente.  
  
 O exemplo a seguir gera C1020:  
  
```  
// C1020.cpp #endif     // C1020  
```  
  
 Resolução possível:  
  
```  
// C1020b.cpp // compile with: /c #if 1 #endif  
```