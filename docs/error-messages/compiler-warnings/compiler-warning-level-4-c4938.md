---
title: "Compilador C4938 de aviso (n&#237;vel 4) | Microsoft Docs"
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
  - "C4938"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4938"
ms.assetid: 6acac81a-9d23-465e-b700-ed4b6e8edcd0
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4938 de aviso (n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'var': variável de redução de ponto flutuante pode causar resultados inconsistentes em \/fp: strict ou \#pragma fenv\_access  
  
 Você não deve usar [\/fp: strict](../../build/reference/fp-specify-floating-point-behavior.md) ou [fenv\_access](../../preprocessor/fenv-access.md) com OpenMP reduções de ponto flutuantes, porque a soma é calculada em uma ordem diferente. Portanto, os resultados podem diferir dos resultados sem \/openmp.  
  
 O exemplo a seguir gera C4938:  
  
```  
// C4938.cpp // compile with: /openmp /W4 /fp:strict /c // #pragma fenv_access(on) extern double *a; double test(int first, int last) { double sum = 0.0; #pragma omp parallel for reduction(+: sum)   // C4938 for (int i = first ; i <= last ; ++i) sum += a[i]; return sum; }  
```  
  
 Sem paralelização explícita, a soma é calculada da seguinte maneira:  
  
```  
sum = a[first] + a[first + 1] + ... + a[last];   
```  
  
 Paralelização explícita \(e dois threads\), a soma é calculada da seguinte maneira:  
  
```  
sum1 = a[first] + ... a[first + last / 2]; sum2 = a[(first + last / 2) + 1] + ... a[last]; sum = sum1 + sum2;  
```