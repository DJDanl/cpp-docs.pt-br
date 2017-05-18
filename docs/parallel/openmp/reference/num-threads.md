---
title: num_threads | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- num_threads
dev_langs:
- C++
helpviewer_keywords:
- num_threads OpenMP clause
ms.assetid: 09a56fc8-25c7-43e4-bbb5-71cb955d0b93
caps.latest.revision: 7
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ae50d220bc6727d32ff813984ff05a490e548322
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="numthreads"></a>num_threads
Define o número de threads em uma equipe de thread.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
num_threads(num)  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `num`  
 O número de threads  
  
## <a name="remarks"></a>Comentários  
 O `num_threads` cláusula tem a mesma funcionalidade que o [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) função.  
  
 `num_threads`aplica-se para as seguintes diretivas:  
  
-   [paralelo](../../../parallel/openmp/reference/parallel.md)  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.3 construto parallel](../../../parallel/openmp/2-3-parallel-construct.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [paralela](../../../parallel/openmp/reference/parallel.md) para obter um exemplo do uso de `num_threads` cláusula.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)
