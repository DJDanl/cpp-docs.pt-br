---
title: C3037 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3037
dev_langs:
- C++
helpviewer_keywords:
- C3037
ms.assetid: 9ba8a890-d3c7-4cce-93c5-d358e2bfad28
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 7fc59984a3fb47d9dd00d479e771fd11f6bab242
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3037"></a>C3037 de erro do compilador
'var': variável em cláusula 'reduction' deve ser shared em contexto delimitador  
  
 Uma variável especificada em uma [redução](../../parallel/openmp/reference/reduction.md) cláusula não pode ser particular para cada thread no contexto.  
  
 O exemplo a seguir gera C3037:  
  
```  
// C3037.cpp  
// compile with: /openmp /c  
int g_i;  
  
int main() {  
   int i;  
  
   #pragma omp parallel private(g_i)  
   // try the following line instead  
   // #pragma omp parallel   
   {  
      #pragma omp for reduction(+:g_i)   // C3037  
      for (i = 0 ; i < 10 ; ++i) {  
         g_i += i;  
      }  
   }  
}  
```
