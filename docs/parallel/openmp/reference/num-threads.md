---
title: num_threads | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- num_threads
dev_langs:
- C++
helpviewer_keywords:
- num_threads OpenMP clause
ms.assetid: 09a56fc8-25c7-43e4-bbb5-71cb955d0b93
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d3485d534cf279863b241abcd26195cdde7fea19
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46016280"
---
# <a name="numthreads"></a>num_threads
Define o número de threads em uma equipe de thread.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
num_threads(num)  
```  
  
### <a name="parameters"></a>Parâmetros
  
*num*<br/>
O número de threads  
  
## <a name="remarks"></a>Comentários  
 O `num_threads` cláusula tem a mesma funcionalidade que o [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) função.  
  
 `num_threads` aplica-se para as seguintes diretivas:  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [Seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.3 construto parallel](../../../parallel/openmp/2-3-parallel-construct.md).  
  
## <a name="example"></a>Exemplo  
 Ver [paralelas](../../../parallel/openmp/reference/parallel.md) para obter um exemplo de como usar `num_threads` cláusula.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)