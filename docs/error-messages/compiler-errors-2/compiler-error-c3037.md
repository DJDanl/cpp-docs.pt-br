---
title: "C3037 de erro do compilador | Microsoft Docs"
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
  - "C3037"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3037"
ms.assetid: 9ba8a890-d3c7-4cce-93c5-d358e2bfad28
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3037 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'var': variável na cláusula 'redução' deve ser compartilhada no contexto de circunscrição  
  
 Uma variável especificada em uma [redução](../../parallel/openmp/reference/reduction.md) cláusula não pode ser particular para cada thread no contexto.  
  
 O exemplo a seguir gera C3037:  
  
```  
// C3037.cpp // compile with: /openmp /c int g_i; int main() { int i; #pragma omp parallel private(g_i) // try the following line instead // #pragma omp parallel { #pragma omp for reduction(+:g_i)   // C3037 for (i = 0 ; i < 10 ; ++i) { g_i += i; } } }  
```