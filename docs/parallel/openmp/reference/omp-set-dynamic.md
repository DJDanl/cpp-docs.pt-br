---
title: omp_set_dynamic | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- omp_set_dynamic
dev_langs:
- C++
helpviewer_keywords:
- omp_set_dynamic OpenMP function
ms.assetid: 3845faf2-a0ca-45a5-ae70-2a7a6164f1e8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 00ee1ad4c42e0d2f1303854cbd050e5601d0c3cd
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
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