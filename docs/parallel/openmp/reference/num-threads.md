---
title: num_threads | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- num_threads
dev_langs:
- C++
helpviewer_keywords:
- num_threads OpenMP clause
ms.assetid: 09a56fc8-25c7-43e4-bbb5-71cb955d0b93
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3b9d12b8216033b5ffe6499290f1c2b5742152b2
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="numthreads"></a>num_threads
Define o número de segmentos em uma equipe de thread.  
  
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
  
 `num_threads` aplica-se para as seguintes diretivas:  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [sections](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.3 construto parallel](../../../parallel/openmp/2-3-parallel-construct.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [paralela](../../../parallel/openmp/reference/parallel.md) para obter um exemplo do uso de `num_threads` cláusula.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)