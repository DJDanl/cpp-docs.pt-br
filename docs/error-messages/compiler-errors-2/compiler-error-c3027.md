---
title: C3027 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3027
dev_langs:
- C++
helpviewer_keywords:
- C3027
ms.assetid: 6562a5c2-2f28-4b36-91ca-2a64c0f0501a
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: f5d1302b5572d145a30efcde0ed4bf12babd671d
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3027"></a>C3027 de erro do compilador
'cláusula': expressão aritmética ou de ponteiro esperada  
  
 Uma cláusula que requer uma expressão aritmética ou ponteiro foi passada a outro tipo de expressão.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3027:  
  
```  
// C3027.cpp  
// compile with: /openmp /link vcomps.lib  
#include <stdio.h>  
#include "omp.h"  
  
struct MyStruct   
{  
    int x;  
} m_MyStruct;  
  
int main()   
{  
    int i;  
  
    puts("Test with class MyStruct:\n");  
    #pragma omp parallel for if(m_MyStruct)   // C3027  
    for (i = 1; i <= 2; ++i)  
        printf_s("Hello World - thread %d - iteration %d\n",  
                 omp_get_thread_num(), i);  
  
    puts("Test with int:\n");  
    #pragma omp parallel for if(9)   // OK  
    for (i = 1; i <= 2; ++i)  
        printf_s("Hello World - thread %d - iteration %d\n",  
                 omp_get_thread_num(), i);  
}  
```
