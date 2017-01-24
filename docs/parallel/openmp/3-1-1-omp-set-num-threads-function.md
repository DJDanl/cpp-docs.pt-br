---
title: "3.1.1 omp_set_num_threads Function | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: b94cf2b5-8011-4a3b-ba56-676982642857
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 3.1.1 omp_set_num_threads Function
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O `omp_set_num_threads` função define o número padrão de segmentos usados para regiões paralelas subseqüentes que não especificam uma `num_threads` cláusula.  O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_set_num_threads(int num_threads);  
```  
  
 O valor do parâmetro  *num\_threads* deve ser um inteiro positivo.  Seu efeito depende se o ajuste dinâmico do número de threads está habilitado.  Para um conjunto abrangente de regras sobre a interação entre o `omp_set_num_threads` função e o ajuste dinâmico de threads, consulte a seção 2.3 na página 8.  
  
 Esta função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa em que o `omp_in_parallel` função retorna zero.  Se ela é chamada a partir de uma parte do programa em que o `omp_in_parallel` função retorna um valor diferente de zero, o comportamento desta função é indefinido.  
  
 Essa chamada tem precedência sobre o `OMP_NUM_THREADS` variável de ambiente.  O valor padrão para o número de segmentos, que podem ser estabelecidas chamando `omp_set_num_threads` ou definindo a `OMP_NUM_THREADS` variável de ambiente, pode ser substituída explicitamente em um único  **paralela** diretiva especificando a `num_threads` cláusula.  
  
## Entre as referências:  
  
-   `omp_set_dynamic`função, consulte  [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.  
  
-   `omp_get_dynamic`função, consulte  [seção 3.1.8](../../parallel/openmp/3-1-8-omp-get-dynamic-function.md) na página 40.  
  
-   `OMP_NUM_THREADS`Consulte variável, do ambiente  [seção 4.2](../../parallel/openmp/4-2-omp-num-threads.md) na página 48 e seção 2.3 na página 8.  
  
-   `num_threads`cláusula, consulte  [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8