---
title: omp_set_num_threads | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- omp_set_num_threads
dev_langs:
- C++
helpviewer_keywords:
- omp_set_num_threads OpenMP function
ms.assetid: dae0bf3f-cd7a-4413-89de-6149ac1f4fa7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 335cb283026a019d6c6a03565c5dbec541140db3
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33691307"
---
# <a name="ompsetnumthreads"></a>omp_set_num_threads
Define o número de threads em regiões paralelas subsequentes, a menos que substituído por um [num_threads](../../../parallel/openmp/reference/num-threads.md) cláusula.  
  
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