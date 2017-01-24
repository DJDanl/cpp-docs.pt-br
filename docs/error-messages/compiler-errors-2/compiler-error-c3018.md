---
title: "C3018 de erro do compilador | Microsoft Docs"
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
  - "C3018"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3018"
ms.assetid: 685be45f-f116-43a8-a88d-05ab6616e2f1
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3018 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'var1': OpenMP 'para' teste ou o incremento deve usar índice variável 'var2'  
  
 Um `for` loop em uma instrução OpenMP deve usar a mesma variável de seu teste e incremento como ele usa para seu índice.  
  
 O exemplo a seguir gera C3018:  
  
```  
// C3018.cpp // compile with: /openmp int main() { int i = 0, j = 5; #pragma omp parallel { #pragma omp for for (i = 0; j < 10; ++i)   // C3018 // try the the following line instead // for (i = 0; i < 10; ++i) j *= 2; #pragma omp for for (i = 0; i < 10; j = j + i)   // C3018 // try the the following line instead // for (i = 0; i < 10; i = j + i) j *= 2; } }  
```