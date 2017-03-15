---
title: OMP_NUM_THREADS | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- OMP_NUM_THREADS
dev_langs:
- C++
helpviewer_keywords:
- OMP_NUM_THREADS OpenMP environment variable
ms.assetid: 4b558124-1387-4c30-a6a5-ff5345a9ced6
caps.latest.revision: 8
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
ms.openlocfilehash: 9fc343fd41bf0661099aee2cb4f890a215a64fed
ms.lasthandoff: 02/25/2017

---
# <a name="ompnumthreads"></a>OMP_NUM_THREADS
Define o número máximo de threads na região paralela, a menos que substituída por [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) ou [num_threads](../../../parallel/openmp/reference/num-threads.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
set OMP_NUM_THREADS[=num]  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `num`  
 O número máximo de threads desejado na região paralela, até 64 na implementação do Visual C++.  
  
## <a name="remarks"></a>Comentários  
 O **OMP_NUM_THREADS** variável de ambiente pode ser substituída do [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) função ou por [num_threads](../../../parallel/openmp/reference/num-threads.md).  
  
 O valor padrão de `num` no Visual C++ a implementação do padrão OpenMP é o número de processadores virtuais, incluindo CPUs hyperthreading.  
  
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
