---
title: "3.1.3 função omp_get_max_threads | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 5548897c-546e-4d19-b37b-a76f6b30a0a9
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 13aee27dc04afb8414a89bb8f30a98c8e73fb694
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="313-ompgetmaxthreads-function"></a>3.1.3 função omp_get_max_threads
O **omp_get_max_threads** função retorna um inteiro que é garantido para ser pelo menos tão grande quanto o número de threads que será usada para formar uma equipe se uma região parallel sem um **num_threads** cláusula foram será encontrada nesse ponto no código. O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_get_max_threads(void);  
```  
  
 O seguinte expressa um limite inferior no valor de **omp_get_max_threads**:  
  
```  
  
threads-used-for-next-team  
 <= omp_get_max_threads  
  
```  
  
 Observe que, se uma região parallel subsequente usa o **num_threads** cláusula para solicitar um número específico de threads, a garantia sobre o limite inferior do resultado de **omp_get_max_threads** nenhuma espera longa.  
  
 O **omp_get_max_threads** o valor de retorno da função pode ser usado para alocar dinamicamente armazenamento suficiente para todos os threads na equipe formada na região parallel subsequente.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **omp_get_num_threads** funcionam, consulte [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37.  
  
-   **omp_set_num_threads** funcionam, consulte [seção 3.1.1](../../parallel/openmp/3-1-1-omp-set-num-threads-function.md) na página 36.  
  
-   **omp_set_dynamic** funcionam, consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.  
  
-   **num_threads** cláusula, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.