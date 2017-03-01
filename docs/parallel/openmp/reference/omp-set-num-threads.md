---
title: omp_set_num_threads | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- omp_set_num_threads
dev_langs:
- C++
helpviewer_keywords:
- omp_set_num_threads OpenMP function
ms.assetid: dae0bf3f-cd7a-4413-89de-6149ac1f4fa7
caps.latest.revision: 9
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
ms.openlocfilehash: f5199e229f1dfd5ebc6ef342239aab9bdeca58cc
ms.lasthandoff: 02/25/2017

---
# <a name="ompsetnumthreads"></a>omp_set_num_threads
Define o número de threads em regiões subsequente em paralelo, a menos que substituída por uma [num_threads](../../../parallel/openmp/reference/num-threads.md) cláusula.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void omp_set_num_threads(  
   int num_threads  
);  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `num_threads`  
 O número de threads na região paralela.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [3.1.1 função omp_set_num_threads](../../../parallel/openmp/3-1-1-omp-set-num-threads-function.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [omp_get_num_threads](../../../parallel/openmp/reference/omp-get-num-threads.md) para obter um exemplo de como usar `omp_set_num_threads`.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../../parallel/openmp/reference/openmp-functions.md)
