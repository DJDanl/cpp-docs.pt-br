---
title: omp_lock_t | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- omp_lock_t
dev_langs:
- C++
helpviewer_keywords:
- omp_lock_t OpenMP data type
ms.assetid: 51b80629-4ffc-4b8a-95c7-1af048f1f286
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5f07ff7c9a0590bee90783c2f06dcb6ffdbcb42e
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33691256"
---
# <a name="omplockt"></a>omp_lock_t
Um tipo que contém o status de um bloqueio, se o bloqueio está disponível ou se um thread possui um bloqueio.  
  
 As funções a seguir use **omp_lock_t**:  
  
-   [omp_init_lock](../../../parallel/openmp/reference/omp-init-lock.md)  
  
-   [omp_destroy_lock](../../../parallel/openmp/reference/omp-destroy-lock.md)  
  
-   [omp_set_lock](../../../parallel/openmp/reference/omp-set-lock.md)  
  
-   [omp_unset_lock](../../../parallel/openmp/reference/omp-unset-lock.md)  
  
-   [omp_test_lock](../../../parallel/openmp/reference/omp-test-lock.md)  
  
 Para obter mais informações, consulte [3.2 funções de bloqueio](../../../parallel/openmp/3-2-lock-functions.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [omp_init_lock](../../../parallel/openmp/reference/omp-init-lock.md) para obter um exemplo do uso de **omp_lock_t**.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de Dados](../../../parallel/openmp/reference/openmp-data-types.md)