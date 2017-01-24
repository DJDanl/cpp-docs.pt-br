---
title: "4.2 OMP_NUM_THREADS | Microsoft Docs"
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
ms.assetid: 49dd55dd-25d5-4a5a-a998-cc7f47b2dae2
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 4.2 OMP_NUM_THREADS
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **OMP\_NUM\_THREADS** variável de ambiente define o número padrão de segmentos usados durante a execução, a menos que esse número seja explicitamente alterado chamando o  **omp\_set\_num\_threads** biblioteca de rotina ou por um explícito  **num\_threads** cláusula em um  **paralela** diretiva.  
  
 O valor da  **OMP\_NUM\_THREADS** variável de ambiente deve ser um inteiro positivo.  Seu efeito depende se o ajuste dinâmico do número de threads está habilitado.  Para um conjunto abrangente de regras sobre a interação entre o  **OMP\_NUM\_THREADS** ambiente variável e dinâmico de ajuste de segmentos, consulte a seção 2.3 na página 8.  
  
 Se nenhum valor for especificado para o  **OMP\_NUM\_THREADS** variável de ambiente, ou se o valor especificado não é um número inteiro positivo ou se o valor for maior que o número máximo de threads, o sistema pode suportar, o número de segmentos usados é definidos na implementação.  
  
 Exemplo:  
  
```  
setenv OMP_NUM_THREADS 16  
```  
  
## Entre as referências:  
  
-   **num\_threads** cláusula, consulte  [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8.  
  
-   **omp\_set\_num\_threads** funcionam, consulte  [seção 3.1.1](../../parallel/openmp/3-1-1-omp-set-num-threads-function.md) na página 36.  
  
-   **omp\_set\_dynamic** funcionam, consulte  [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.