---
title: "C3013 de erro do compilador | Microsoft Docs"
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
  - "C3013"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3013"
ms.assetid: f896777d-27e6-4b6d-baab-1567317f3374
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3013 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'cláusula': cláusula pode aparecer apenas uma vez na diretiva de 'diretiva' OpenMP  
  
 Uma cláusula apareceu duas vezes na mesma diretiva. Exclua uma ocorrência da cláusula.  
  
 O exemplo a seguir gera C3013:  
  
```  
// C3013.cpp // compile with: /openmp int main() { int a, b, c, x, y, z; #pragma omp parallel shared(a,b,c) private(x) #pragma omp for nowait private(x) nowait   // C3013 // The previous line generates C3013, with two nowait clauses // try the following line instead: // #pragma omp for nowait private(x) for (a = 0 ; a < 10 ; ++a) { } }  
```