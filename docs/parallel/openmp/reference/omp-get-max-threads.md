---
title: omp_get_max_threads | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: omp_get_max_threads
dev_langs: C++
helpviewer_keywords: omp_get_max_threads OpenMP function
ms.assetid: f47c3725-3e40-469f-8bc8-a1e47f264cc3
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0308d18647805b058c7c75ed268418bec50caba7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ompgetmaxthreads"></a>omp_get_max_threads
Retorna um inteiro que é igual ou maior que o número de threads que estariam disponíveis se uma região parallel sem [num_threads](../../../parallel/openmp/reference/num-threads.md) foram definidas nesse ponto no código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int omp_get_max_threads( )  
```  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [3.1.3 função omp_get_max_threads](../../../parallel/openmp/3-1-3-omp-get-max-threads-function.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// omp_get_max_threads.cpp  
// compile with: /openmp  
#include <stdio.h>  
#include <omp.h>  
  
int main( )   
{  
    omp_set_num_threads(8);  
    printf_s("%d\n", omp_get_max_threads( ));  
    #pragma omp parallel  
        #pragma omp master  
        {  
            printf_s("%d\n", omp_get_max_threads( ));  
        }  
  
    printf_s("%d\n", omp_get_max_threads( ));  
  
    #pragma omp parallel num_threads(3)  
        #pragma omp master  
        {  
            printf_s("%d\n", omp_get_max_threads( ));  
        }  
  
    printf_s("%d\n", omp_get_max_threads( ));  
}  
```  
  
```Output  
8  
8  
8  
8  
8  
```  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)