---
title: C3024 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3024
dev_langs:
- C++
helpviewer_keywords:
- C3024
ms.assetid: 1c031c28-ce37-4de3-aead-cfe76b261856
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: a6d1512df35b7ac6042ee1aef05d15eb4392b9d9
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3024"></a>C3024 de erro do compilador
'Schedule (Runtime)': expressão de chunk_size não é permitido  
  
 Um valor não pode ser passado para o parâmetro de tempo de execução da cláusula de agenda.  
  
 O exemplo a seguir gera C3024:  
  
```  
// C3024.cpp  
// compile with: /openmp /link vcomps.lib  
#include <stdio.h>  
#include "omp.h"  
  
int main() {  
   int i;  
  
   #pragma omp parallel for schedule(runtime, 10)   // C3024  
   for (i = 0; i < 10; ++i) ;  
  
   #pragma omp parallel for schedule(runtime)   // OK  
   for (i = 0; i < 10; ++i) ;  
}  
```
