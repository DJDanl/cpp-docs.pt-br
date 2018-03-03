---
title: "3.1.2 função omp_get_num_threads | Microsoft Docs"
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
ms.assetid: bcdd76e2-d96b-4884-ac8f-e55fc0c42801
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d595fd47b87bbc3fd7701fc847821c73169a23e2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="312-ompgetnumthreads-function"></a>3.1.2 função omp_get_num_threads
O **omp_get_num_threads** função retorna o número de threads atualmente na equipe executando a região paralela do qual ele é chamado. O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_get_num_threads(void);  
```  
  
 O **num_threads** cláusula, o **omp_set_num_threads** função e o **OMP_NUM_THREADS** variável de ambiente controlar o número de segmentos em uma equipe.  
  
 Se o número de threads não foi explicitamente definido pelo usuário, o padrão é definido pela implementação. Essa função associa a circunscrição mais próximo **paralela** diretiva. Se chamado de uma série parte de um programa ou de uma região parallel aninhada é serializado, esta função retornará 1.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **OMP_NUM_THREADS** consulte de variável de ambiente [seção 4.2](../../parallel/openmp/4-2-omp-num-threads.md) na página 48.  
  
-   **num_threads** cláusula, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.  
  
-   **paralelo** construir, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.