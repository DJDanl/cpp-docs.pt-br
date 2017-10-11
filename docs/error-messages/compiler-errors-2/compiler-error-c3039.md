---
title: C3039 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3039
dev_langs:
- C++
helpviewer_keywords:
- C3039
ms.assetid: 02776f16-f57a-4ffd-b7f7-9c696b633e08
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: f3162ab8241781cda521fa4fc9dc51f14fa42897
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3039"></a>C3039 de erro do compilador
'var': variável de índice em OpenMP 'instrução for' não pode ser uma variável de redução  
  
 Uma variável de índice é implicitamente particular, para que a variável não pode ser usada em uma [redução](../../parallel/openmp/reference/reduction.md) cláusula de circunscrição [paralela](../../parallel/openmp/reference/parallel.md) diretiva.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3039:  
  
```  
// C3039.cpp  
// compile with: /openmp /c  
int g_i;  
  
int main() {  
   int i;  
  
   #pragma omp parallel reduction(+: i)  
   {  
      #pragma omp for  
      for (i = 0; i < 10; ++i)   // C3039  
         g_i += i;  
   }  
}  
```
