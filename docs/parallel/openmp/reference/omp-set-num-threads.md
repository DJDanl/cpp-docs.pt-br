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
ms.openlocfilehash: 5ae9dbe52dba47208844b73175f20edcc591a3ae
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46444938"
---
# <a name="ompsetnumthreads"></a>omp_set_num_threads

Define o número de threads em regiões subsequente em paralelo, a menos que substituído por um [num_threads](../../../parallel/openmp/reference/num-threads.md) cláusula.

## <a name="syntax"></a>Sintaxe

```
void omp_set_num_threads(
   int num_threads
);
```

### <a name="parameters"></a>Parâmetros

*num_threads*<br/>
O número de threads na região paralela.

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [3.1.1 função omp_set_num_threads](../../../parallel/openmp/3-1-1-omp-set-num-threads-function.md).

## <a name="example"></a>Exemplo

Ver [omp_get_num_threads](../../../parallel/openmp/reference/omp-get-num-threads.md) para obter um exemplo de como usar `omp_set_num_threads`.

## <a name="see-also"></a>Consulte também

[Funções](../../../parallel/openmp/reference/openmp-functions.md)