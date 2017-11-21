---
title: omp_in_parallel | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: omp_in_parallel
dev_langs: C++
helpviewer_keywords: omp_in_parallel OpenMP function
ms.assetid: 1f01a1b4-78c5-496a-afb7-a43ecdad83d6
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 808efbaf0d59850550d5c47d64bd7aa8594e90eb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ompinparallel"></a>omp_in_parallel
Retorna nulo se chamado de dentro de uma região parallel.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int omp_in_parallel( );  
```  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [3.1.6 função omp_in_parallel](../../../parallel/openmp/3-1-6-omp-in-parallel-function.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// omp_in_parallel.cpp  
// compile with: /openmp  
#include <stdio.h>  
#include <omp.h>  
  
int main( )   
{  
    omp_set_num_threads(4);  
    printf_s("%d\n", omp_in_parallel( ));  
  
    #pragma omp parallel  
        #pragma omp master  
        {  
            printf_s("%d\n", omp_in_parallel( ));  
        }  
}  
```  
  
```Output  
0  
1  
```  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)