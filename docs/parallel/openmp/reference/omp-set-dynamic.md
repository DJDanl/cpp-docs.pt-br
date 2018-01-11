---
title: omp_set_dynamic | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: omp_set_dynamic
dev_langs: C++
helpviewer_keywords: omp_set_dynamic OpenMP function
ms.assetid: 3845faf2-a0ca-45a5-ae70-2a7a6164f1e8
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 13cb098170e46b8459821156aeb8be369bbc1ffa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ompsetdynamic"></a>omp_set_dynamic
Indica que o número de threads disponíveis na região parallel subsequente pode ser ajustado por tempo de execução.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void omp_set_dynamic(  
   int val  
);  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `val`  
 Um valor que indica se o número de threads disponíveis na região parallel subsequente pode ser ajustado pelo tempo de execução.  Se for diferente de zero, que o tempo de execução pode ajustar o número de threads, se for zero, o tempo de execução não dinamicamente ajustará o número de threads.  
  
## <a name="remarks"></a>Comentários  
 O número de threads nunca excederá o valor definido por [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) ou [OMP_NUM_THREADS](../../../parallel/openmp/reference/omp-num-threads.md).  
  
 Use [omp_get_dynamic](../../../parallel/openmp/reference/omp-get-dynamic.md) para exibir a configuração atual de `omp_set_dynamic`.  
  
 A configuração de `omp_set_dynamic` substituirá a configuração do [OMP_DYNAMIC](../../../parallel/openmp/reference/omp-dynamic.md) variável de ambiente.  
  
 Para obter mais informações, consulte [3.1.7 função omp_set_dynamic](../../../parallel/openmp/3-1-7-omp-set-dynamic-function.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// omp_set_dynamic.cpp  
// compile with: /openmp  
#include <stdio.h>  
#include <omp.h>  
  
int main()   
{  
    omp_set_dynamic(9);  
    omp_set_num_threads(4);  
    printf_s("%d\n", omp_get_dynamic( ));  
    #pragma omp parallel  
        #pragma omp master  
        {  
            printf_s("%d\n", omp_get_dynamic( ));  
        }  
}  
```  
  
```Output  
1  
1  
```  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)