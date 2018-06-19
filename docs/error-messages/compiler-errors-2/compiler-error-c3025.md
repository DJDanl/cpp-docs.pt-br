---
title: C3025 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3025
dev_langs:
- C++
helpviewer_keywords:
- C3025
ms.assetid: 4442f5a3-d9ea-4873-b1fb-e7e5bd3cbe5e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4a74229ab5b40f1f432283d2b2b150ee14edcfec
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33244274"
---
# <a name="compiler-error-c3025"></a>C3025 de erro do compilador
'cláusula': expressão integral esperada  
  
 Uma cláusula requer uma expressão de inteiro, mas recebeu uma expressão fracionários.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3025.  
  
```  
// C3025.cpp  
// compile with: /openmp /link vcomps.lib  
#include <stdio.h>  
#include "omp.h"  
  
float f = 2.0F;  
  
int main()   
{  
    int i = 0;  
  
    // OK  
    puts("Test with int");  
    #pragma omp parallel for num_threads(i)  
    for (i = 1; i <= 2; ++i)  
        printf_s("Hello World - thread %d - iteration %d\n",  
                 omp_get_thread_num(), i);  
  
    puts("Test with float");  
    #pragma omp parallel for num_threads(f)   // C3025  
    for (i = 1; i <= 2; ++i)  
        printf_s("Hello World - thread %d - iteration %d\n",  
                 omp_get_thread_num(), i);  
}  
```