---
title: "C3024 de erro do compilador | Microsoft Docs"
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
  - "C3024"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3024"
ms.assetid: 1c031c28-ce37-4de3-aead-cfe76b261856
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3024 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'schedule\(runtime\)': expressão chunk\_size não é permitida  
  
 Um valor não pode ser passado para o parâmetro de tempo de execução da cláusula de agendamento.  
  
 O exemplo a seguir gera C3024:  
  
```  
// C3024.cpp // compile with: /openmp /link vcomps.lib #include <stdio.h> #include "omp.h" int main() { int i; #pragma omp parallel for schedule(runtime, 10)   // C3024 for (i = 0; i < 10; ++i) ; #pragma omp parallel for schedule(runtime)   // OK for (i = 0; i < 10; ++i) ; }  
```