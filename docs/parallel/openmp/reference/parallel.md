---
title: paralelo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- parallel
dev_langs:
- C++
helpviewer_keywords:
- parallel OpenMP directive
ms.assetid: b8e90073-e85b-4d39-8ed8-0364441794fb
caps.latest.revision: 12
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
ms.openlocfilehash: 74bad2cbe60e7f03c39d243e380db5dea7430c28
ms.lasthandoff: 02/25/2017

---
# <a name="parallel"></a>parallel
Define uma região paralela, que é o código que será executado por vários threads em paralelo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma omp parallel [clauses]  
{  
   code_block  
}  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `clause` (opcional)  
 Zero ou mais cláusulas.  Consulte a seção de comentários para obter uma lista das cláusulas de suporte **paralela**.  
  
## <a name="remarks"></a>Comentários  
 O **paralela** diretiva suporta as seguintes cláusulas OpenMP:  
  
-   [copyin](../../../parallel/openmp/reference/copyin.md)  
  
-   [default](../../../parallel/openmp/reference/default-openmp.md)  
  
-   [firstprivate](../../../parallel/openmp/reference/firstprivate.md)  
  
-   [Se](../../../parallel/openmp/reference/if-openmp.md)  
  
-   [num_threads](../../../parallel/openmp/reference/num-threads.md)  
  
-   [private](../../../parallel/openmp/reference/private-openmp.md)  
  
-   [redução](../../../parallel/openmp/reference/reduction.md)  
  
-   [compartilhado](../../../parallel/openmp/reference/shared-openmp.md)  
  
 **paralelo** também pode ser usado com o [seções](../../../parallel/openmp/reference/sections-openmp.md) e [para](../../../parallel/openmp/reference/for-openmp.md) diretivas.  
  
 Para obter mais informações, consulte [2.3 construto parallel](../../../parallel/openmp/2-3-parallel-construct.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como definir o número de threads e uma região paralela. Por padrão, o número de threads é igual ao número de processadores lógicos no computador. Por exemplo, se você tiver uma máquina com um processador físico com hyperthreading habilitado, ele terá dois processadores lógicos e, portanto, dois threads.  
  
```  
// omp_parallel.cpp  
// compile with: /openmp   
#include <stdio.h>  
#include <omp.h>  
  
int main() {  
   #pragma omp parallel num_threads(4)  
   {  
      int i = omp_get_thread_num();  
      printf_s("Hello from thread %d\n", i);  
   }  
}  
```  
  
```Output  
Hello from thread 0  
Hello from thread 1  
Hello from thread 2  
Hello from thread 3  
```  
  
## <a name="comment"></a>Comentário  
 Observe que a ordem de saída pode variar em máquinas diferentes.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas](../../../parallel/openmp/reference/openmp-directives.md)
