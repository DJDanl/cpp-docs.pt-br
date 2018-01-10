---
title: omp_get_num_procs | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: omp_get_num_procs
dev_langs: C++
helpviewer_keywords: omp_get_num_procs OpenMP function
ms.assetid: 14a10b8f-e59b-4211-a292-687648c9f760
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e9870659ef399f53394fd1002c0f5ea4bc946752
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ompgetnumprocs"></a>omp_get_num_procs
Retorna o número de processadores que estão disponíveis quando a função é chamada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int omp_get_num_procs();  
```  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [3.1.5 função omp_get_num_procs](../../../parallel/openmp/3-1-5-omp-get-num-procs-function.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// omp_get_num_procs.cpp  
// compile with: /openmp  
#include <stdio.h>  
#include <omp.h>  
  
int main( )   
{  
    printf_s("%d\n", omp_get_num_procs( ));  
    #pragma omp parallel  
        #pragma omp master  
        {  
            printf_s("%d\n", omp_get_num_procs( ));  
        }  
}  
```  
  
```Output  
// Expect the following output when the example is run on a two-processor machine:  
2  
2  
```  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)