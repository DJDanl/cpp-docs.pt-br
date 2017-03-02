---
title: "seções (OpenMP) | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- section
- SECTIONS
dev_langs:
- C++
helpviewer_keywords:
- sections OpenMP directive
ms.assetid: 4cd1d776-e198-470e-930a-01fb0ab0a0bd
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 3c73d498796be69e1cea31c25755fcd5f64e744e
ms.lasthandoff: 02/25/2017

---
# <a name="sections-openmp"></a>sections (OpenMP)
Identifica as seções de código para ser dividida entre todos os threads.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma omp [parallel] sections [clauses]  
{  
   #pragma omp section  
   {  
      code_block   
   }   
}  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `clause` (opcional)  
 Zero ou mais cláusulas. Consulte a seção de comentários para obter uma lista das cláusulas de suporte **seções**.  
  
## <a name="remarks"></a>Comentários  
 O **seções** diretiva pode conter zero ou mais **seção** diretivas.  
  
 O **seções** diretiva suporta as seguintes cláusulas OpenMP:  
  
-   [firstprivate](../../../parallel/openmp/reference/firstprivate.md)  
  
-   [lastprivate](../../../parallel/openmp/reference/lastprivate.md)  
  
-   [nowait](../../../parallel/openmp/reference/nowait.md)  
  
-   [private](../../../parallel/openmp/reference/private-openmp.md)  
  
-   [redução](../../../parallel/openmp/reference/reduction.md)  
  
 Se **paralela** também for especificado, `clause` pode ser qualquer cláusula aceitos pela **paralela** ou **seções** diretivas, exceto `nowait`.  
  
 Para obter mais informações, consulte [2.4.2 constructo sections](../../../parallel/openmp/2-4-2-sections-construct.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// omp_sections.cpp  
// compile with: /openmp   
#include <stdio.h>  
#include <omp.h>  
  
int main() {  
    #pragma omp parallel sections num_threads(4)  
    {  
        printf_s("Hello from thread %d\n", omp_get_thread_num());  
        #pragma omp section  
        printf_s("Hello from thread %d\n", omp_get_thread_num());  
    }  
}  
```  
  
```Output  
Hello from thread 0  
Hello from thread 0  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas](../../../parallel/openmp/reference/openmp-directives.md)
