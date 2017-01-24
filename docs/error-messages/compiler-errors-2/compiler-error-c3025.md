---
title: "C3025 de erro do compilador | Microsoft Docs"
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
  - "C3025"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3025"
ms.assetid: 4442f5a3-d9ea-4873-b1fb-e7e5bd3cbe5e
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3025 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'cláusula': expressão integral esperado  
  
 Uma cláusula requer uma expressão de inteiro, mas recebeu uma expressão não inteiras.  
  
## Exemplo  
 O exemplo a seguir gera C3025.  
  
```  
// C3025.cpp // compile with: /openmp /link vcomps.lib #include <stdio.h> #include "omp.h" float f = 2.0F; int main() { int i = 0; // OK puts("Test with int"); #pragma omp parallel for num_threads(i) for (i = 1; i <= 2; ++i) printf_s("Hello World - thread %d - iteration %d\n", omp_get_thread_num(), i); puts("Test with float"); #pragma omp parallel for num_threads(f)   // C3025 for (i = 1; i <= 2; ++i) printf_s("Hello World - thread %d - iteration %d\n", omp_get_thread_num(), i); }  
```