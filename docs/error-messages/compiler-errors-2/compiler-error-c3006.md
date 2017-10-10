---
title: C3006 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3006
dev_langs:
- C++
helpviewer_keywords:
- C3006
ms.assetid: 449082ec-fd45-4c47-8ab3-ba6a719e4dc4
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: e1ea6ba0757da761aa8c431730f5bd7886270ccf
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3006"></a>C3006 de erro do compilador
'cláusula': cláusula de OpenMP 'diretiva' diretiva não tem um argumento esperado  
  
 Uma diretiva de OpenMP não tinha um argumento esperado.  
  
 O exemplo a seguir gera C3006:  
  
```  
// C3006.c  
// compile with: /openmp  
int main()  
{  
   #pragma omp parallel shared   // C3006  
   // Try the following line instead:  
   // #pragma omp parallel shared(x) {}  
  
}  
```
