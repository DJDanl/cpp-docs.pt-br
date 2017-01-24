---
title: "C3036 de erro do compilador | Microsoft Docs"
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
  - "C3036"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3036"
ms.assetid: 10c6993e-bc42-4a07-85c7-cdc34ac30906
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3036 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'operator': token operador inválido na cláusula 'Redução' OpenMP  
  
 Um [redução](../../parallel/openmp/reference/reduction.md) cláusula não foi especificada corretamente.  
  
 O exemplo a seguir gera C3036:  
  
```  
// C3036.cpp // compile with: /openmp static float a[1000], b[1000], c[1000]; void test1(int first, int last) { static float dp = 0.0f; #pragma omp for nowait reduction(.:dp)   // C3036 // try the following line instead // #pragma omp for nowait reduction(+: dp) for (int i = first ; i <= last ; ++i) dp += a[i] * b[i]; }  
```