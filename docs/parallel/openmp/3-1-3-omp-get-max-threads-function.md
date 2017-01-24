---
title: "3.1.3 omp_get_max_threads Function | Microsoft Docs"
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
ms.assetid: 5548897c-546e-4d19-b37b-a76f6b30a0a9
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 3.1.3 omp_get_max_threads Function
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **omp\_get\_max\_threads** função retorna um número inteiro que é garantido que ser pelo menos, tão grande quanto o número de segmentos que seria usado para formar uma equipe se uma região paralela sem um  **num\_threads** cláusula foram será encontrada nesse ponto no código.  O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_get_max_threads(void);  
```  
  
 A seguir expressa um limite inferior no valor de  **omp\_get\_max\_threads**:  
  
```  
  
threads-used-for-next-team  
 <= omp_get_max_threads  
  
```  
  
 Observe que, se uma região paralela subseqüente usa a  **num\_threads** cláusula para solicitar um número específico de segmentos, a garantia do limite inferior do resultado da  **omp\_get\_max\_threads** nenhum suspensões longos.  
  
 O  **omp\_get\_max\_threads** o valor de retorno da função pode ser usado para alocar dinamicamente o armazenamento suficiente para todos os segmentos na equipe formada na região das paralela subseqüente.  
  
## Entre as referências:  
  
-   **omp\_get\_num\_threads** funcionam, consulte  [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37.  
  
-   **omp\_set\_num\_threads** funcionam, consulte  [seção 3.1.1](../../parallel/openmp/3-1-1-omp-set-num-threads-function.md) na página 36.  
  
-   **omp\_set\_dynamic** funcionam, consulte  [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.  
  
-   **num\_threads** cláusula, consulte  [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8.