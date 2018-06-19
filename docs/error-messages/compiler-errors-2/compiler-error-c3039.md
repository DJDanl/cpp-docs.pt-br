---
title: C3039 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3039
dev_langs:
- C++
helpviewer_keywords:
- C3039
ms.assetid: 02776f16-f57a-4ffd-b7f7-9c696b633e08
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2bdcfa36d270dc842eec0508969c650e7b30bee4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33243718"
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