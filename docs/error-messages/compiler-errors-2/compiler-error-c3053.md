---
title: "C3053 de erro do compilador | Microsoft Docs"
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
  - "C3053"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3053"
ms.assetid: ab9a25f3-e341-4f6e-8e69-069b4a963a64
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3053 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'symbol': 'threadprivate' só é válida para itens de dados globais ou estáticos  
  
 Símbolos passado para [threadprivate](../Topic/threadprivate.md) deve ser global ou estática.  
  
 O exemplo a seguir gera C3053:  
  
```  
// C3053.cpp // compile with: /openmp void Test() { int x, y; #pragma omp threadprivate(x, y)   // C3053 #pragma omp parallel copyin(x, y) { x = y; } }  
```  
  
 Resolução possível:  
  
```  
// C3053b.cpp // compile with: /openmp /LD int x, y; #pragma omp threadprivate(x, y) void Test() { #pragma omp parallel copyin(x, y) { x = y; } }  
```