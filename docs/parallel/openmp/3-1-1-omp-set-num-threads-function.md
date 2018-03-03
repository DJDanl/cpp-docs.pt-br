---
title: "3.1.1 função omp_set_num_threads | Microsoft Docs"
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
ms.assetid: b94cf2b5-8011-4a3b-ba56-676982642857
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2510c2ed49f7b46f2ca3d853c9b78ff3c09cb62a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="311-ompsetnumthreads-function"></a>3.1.1 função omp_set_num_threads
O `omp_set_num_threads` função define o número padrão de threads a serem usados para regiões paralelas subsequentes que não especificam um `num_threads` cláusula. O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_set_num_threads(int num_threads);  
```  
  
 O valor do parâmetro *num_threads* deve ser um inteiro positivo. Seu efeito depende se o ajuste dinâmico do número de threads está habilitado. Para um conjunto abrangente de regras sobre a interação entre o `omp_set_num_threads` função e ajuste dinâmico de threads, consulte a seção 2.3 na página 8.  
  
 Essa função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa de onde o `omp_in_parallel` função retornará zero. Se ele é chamado de uma parte do programa de onde o `omp_in_parallel` função retorna um valor diferente de zero, o comportamento dessa função é indefinido.  
  
 Essa chamada tem precedência sobre o `OMP_NUM_THREADS` variável de ambiente. O valor padrão para o número de threads, que podem ser estabelecidas chamando `omp_set_num_threads` ou definindo o `OMP_NUM_THREADS` variável de ambiente, pode ser substituído explicitamente em um único **paralela** diretiva especificando o `num_threads` cláusula.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   `omp_set_dynamic`função, consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.  
  
-   `omp_get_dynamic`função, consulte [seção 3.1.8](../../parallel/openmp/3-1-8-omp-get-dynamic-function.md) na página 40.  
  
-   `OMP_NUM_THREADS`Consulte de variável de ambiente [seção 4.2](../../parallel/openmp/4-2-omp-num-threads.md) na página 48 e seção 2.3 na página 8.  
  
-   `num_threads`cláusula, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8