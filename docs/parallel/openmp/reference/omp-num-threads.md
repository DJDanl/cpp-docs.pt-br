---
title: OMP_NUM_THREADS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- OMP_NUM_THREADS
dev_langs:
- C++
helpviewer_keywords:
- OMP_NUM_THREADS OpenMP environment variable
ms.assetid: 4b558124-1387-4c30-a6a5-ff5345a9ced6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 39f45b9c81d5339b2b6afe4c77fdc9bac6b5d731
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46091160"
---
# <a name="ompnumthreads"></a>OMP_NUM_THREADS
Define o número máximo de threads na região paralela, a menos que substituído por [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) ou [num_threads](../../../parallel/openmp/reference/num-threads.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
set OMP_NUM_THREADS[=num]  
```  
  
### <a name="parameters"></a>Parâmetros
  
*num*<br/>
O número máximo de threads que você deseja na região paralela, até 64 na implementação do Visual C++.  
  
## <a name="remarks"></a>Comentários  
 O **OMP_NUM_THREADS** variável de ambiente pode ser substituída pelo [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) função ou pelo [num_threads](../../../parallel/openmp/reference/num-threads.md).  
  
 O valor padrão de `num` no Visual C++ a implementação do padrão OpenMP é o número de processadores virtuais, incluindo CPUs hyperthreading.  
  
 Para obter mais informações, consulte [4.2 OMP_NUM_THREADS](../../../parallel/openmp/4-2-omp-num-threads.md).  
  
## <a name="example"></a>Exemplo  
 O seguinte comando define a **OMP_NUM_THREADS** variável de ambiente para 16:  
  
```  
set OMP_NUM_THREADS=16  
```  
  
 O comando a seguir exibe a configuração atual de **OMP_NUM_THREADS** variável de ambiente:  
  
```  
set OMP_NUM_THREADS  
```  
  
## <a name="see-also"></a>Consulte também  
 [Variáveis de ambiente](../../../parallel/openmp/reference/openmp-environment-variables.md)