---
title: para (OpenMP) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: for
dev_langs: C++
helpviewer_keywords: for OpenMP directive
ms.assetid: 8b54e034-9db2-4c1a-a2b1-72e14e930506
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 97c32bd93ca208d76fbcb418c6e851e3c50f49ec
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="for-openmp"></a>for (OpenMP)
Faz com que o trabalho feito um loop dentro de uma região parallel podem ser divididas entre threads.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma omp [parallel] for [clauses]  
   for_statement  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `clause` (opcional)  
 Zero ou mais cláusulas. Consulte a seção comentários para obter uma lista das cláusulas de suporte **para**.  
  
 `for_statement`  
 Um loop for. Um comportamento indefinido ocorrerá se o código de usuário na alterações de loop a variável de índice.  
  
## <a name="remarks"></a>Comentários  
 O **para** diretiva suporta as seguintes cláusulas OpenMP:  
  
-   [firstprivate](../../../parallel/openmp/reference/firstprivate.md)  
  
-   [lastprivate](../../../parallel/openmp/reference/lastprivate.md)  
  
-   [nowait](../../../parallel/openmp/reference/nowait.md)  
  
-   [ordenados](../../../parallel/openmp/reference/ordered-openmp-directives.md)  
  
-   [private](../../../parallel/openmp/reference/private-openmp.md)  
  
-   [reduction](../../../parallel/openmp/reference/reduction.md)  
  
-   [schedule](../../../parallel/openmp/reference/schedule.md)  
  
 Se **paralela** também for especificado, `clause` pode ser qualquer cláusula aceitos pela **paralela** ou **para** diretivas, exceto **nowait**.  
  
 Para obter mais informações, consulte [2.4.1 para construção de](../../../parallel/openmp/2-4-1-for-construct.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// omp_for.cpp  
// compile with: /openmp   
#include <stdio.h>  
#include <math.h>  
#include <omp.h>  
  
#define NUM_THREADS 4  
#define NUM_START 1  
#define NUM_END 10  
  
int main() {  
   int i, nRet = 0, nSum = 0, nStart = NUM_START, nEnd = NUM_END;  
   int nThreads = 0, nTmp = nStart + nEnd;  
   unsigned uTmp = (unsigned((abs(nStart - nEnd) + 1)) *   
                               unsigned(abs(nTmp))) / 2;  
   int nSumCalc = uTmp;  
  
   if (nTmp < 0)  
      nSumCalc = -nSumCalc;  
  
   omp_set_num_threads(NUM_THREADS);  
  
   #pragma omp parallel default(none) private(i) shared(nSum, nThreads, nStart, nEnd)  
   {  
      #pragma omp master  
      nThreads = omp_get_num_threads();  
  
      #pragma omp for  
      for (i=nStart; i<=nEnd; ++i) {  
            #pragma omp atomic  
            nSum += i;  
      }  
   }  
  
   if  (nThreads == NUM_THREADS) {  
      printf_s("%d OpenMP threads were used.\n", NUM_THREADS);  
      nRet = 0;  
   }  
   else {  
      printf_s("Expected %d OpenMP threads, but %d were used.\n",  
               NUM_THREADS, nThreads);  
      nRet = 1;  
   }  
  
   if (nSum != nSumCalc) {  
      printf_s("The sum of %d through %d should be %d, "  
               "but %d was reported!\n",  
               NUM_START, NUM_END, nSumCalc, nSum);  
      nRet = 1;  
   }  
   else  
      printf_s("The sum of %d through %d is %d\n",  
               NUM_START, NUM_END, nSum);  
}  
```  
  
```Output  
4 OpenMP threads were used.  
The sum of 1 through 10 is 55  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas](../../../parallel/openmp/reference/openmp-directives.md)