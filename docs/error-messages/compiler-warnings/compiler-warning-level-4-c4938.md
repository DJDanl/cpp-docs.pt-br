---
title: "Compilador aviso (nível 4) C4938 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4938
dev_langs:
- C++
helpviewer_keywords:
- C4938
ms.assetid: 6acac81a-9d23-465e-b700-ed4b6e8edcd0
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 00290d0b0298bf6717109c02235d6b74652536ad
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4938"></a>Compilador C4938 de aviso (nível 4)
'var': variável de redução de ponto flutuante pode causar resultados inconsistentes em /fp: strict ou #pragma fenv_access  
  
 Você não deve usar [/fp: strict](../../build/reference/fp-specify-floating-point-behavior.md) ou [fenv_access](../../preprocessor/fenv-access.md) com OpenMP reduções de ponto flutuantes, porque a soma é calculada em uma ordem diferente. Portanto, os resultados podem diferir dos resultados sem /openmp.  
  
 O exemplo a seguir gera C4938:  
  
```  
// C4938.cpp  
// compile with: /openmp /W4 /fp:strict /c  
// #pragma fenv_access(on)  
extern double *a;   
  
double test(int first, int last) {   
   double sum = 0.0;   
   #pragma omp parallel for reduction(+: sum)   // C4938  
   for (int i = first ; i <= last ; ++i)   
      sum += a[i];   
   return sum;   
}  
```  
  
 Sem paralelização explícita, a soma é calculada da seguinte maneira:  
  
```  
sum = a[first] + a[first + 1] + ... + a[last];   
```  
  
 Paralelização explícita (e dois threads), a soma é calculada da seguinte maneira:  
  
```  
sum1 = a[first] + ... a[first + last / 2];   
sum2 = a[(first + last / 2) + 1] + ... a[last];   
sum = sum1 + sum2;  
```
