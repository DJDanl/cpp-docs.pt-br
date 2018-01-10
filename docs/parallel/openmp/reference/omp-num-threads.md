---
title: OMP_NUM_THREADS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: OMP_NUM_THREADS
dev_langs: C++
helpviewer_keywords: OMP_NUM_THREADS OpenMP environment variable
ms.assetid: 4b558124-1387-4c30-a6a5-ff5345a9ced6
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a5f6af2ff547ddb95b6d4ef6b9c6d353399c17c5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ompnumthreads"></a>OMP_NUM_THREADS
Define o número máximo de threads na região paralela, a menos que substituído por [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) ou [num_threads](../../../parallel/openmp/reference/num-threads.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
set OMP_NUM_THREADS[=num]  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `num`  
 O número máximo de threads que você deseja na região paralela, até 64 na implementação do Visual C++.  
  
## <a name="remarks"></a>Comentários  
 O **OMP_NUM_THREADS** variável de ambiente pode ser substituída pelo [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) função ou [num_threads](../../../parallel/openmp/reference/num-threads.md).  
  
 O valor padrão de `num` no Visual C++ a implementação do padrão OpenMP é o número de processadores virtuais, incluindo o hyperthreading CPUs.  
  
 Para obter mais informações, consulte [4.2 OMP_NUM_THREADS](../../../parallel/openmp/4-2-omp-num-threads.md).  
  
## <a name="example"></a>Exemplo  
 O comando a seguir define o **OMP_NUM_THREADS** variável de ambiente para 16:  
  
```  
set OMP_NUM_THREADS=16  
```  
  
 O comando a seguir exibe a configuração atual de **OMP_NUM_THREADS** variável de ambiente:  
  
```  
set OMP_NUM_THREADS  
```  
  
## <a name="see-also"></a>Consulte também  
 [Variáveis de ambiente](../../../parallel/openmp/reference/openmp-environment-variables.md)