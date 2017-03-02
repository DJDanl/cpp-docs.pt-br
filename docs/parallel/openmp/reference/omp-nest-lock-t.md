---
title: omp_nest_lock_t () | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- omp_nest_lock_t
dev_langs:
- C++
helpviewer_keywords:
- omp_nest_lock_t OpenMP data type
ms.assetid: fceac9fb-96d2-42b0-af19-c9b078380618
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
ms.openlocfilehash: a6331cac637b409051eac5a239606a041afed8dc
ms.lasthandoff: 02/25/2017

---
# <a name="ompnestlockt"></a>omp_nest_lock_t
Um tipo que contém as seguintes informações sobre um bloqueio: se o bloqueio está disponível e a identidade do thread que possui o bloqueio e uma contagem de aninhamento.  
  
 As seguintes funções usam **omp_nest_lock_t ()**:  
  
-   [omp_init_nest_lock](../../../parallel/openmp/reference/omp-init-nest-lock.md)  
  
-   [omp_destroy_nest_lock](../../../parallel/openmp/reference/omp-destroy-nest-lock.md)  
  
-   [omp_set_nest_lock](../../../parallel/openmp/reference/omp-set-nest-lock.md)  
  
-   [omp_unset_nest_lock](../../../parallel/openmp/reference/omp-unset-nest-lock.md)  
  
-   [omp_test_nest_lock](../../../parallel/openmp/reference/omp-test-nest-lock.md)  
  
 Para obter mais informações, consulte [3.2 funções Lock](../../../parallel/openmp/3-2-lock-functions.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [omp_init_nest_lock](../../../parallel/openmp/reference/omp-init-nest-lock.md) para obter um exemplo de uso **omp_nest_lock_t ()**.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de Dados](../../../parallel/openmp/reference/openmp-data-types.md)
