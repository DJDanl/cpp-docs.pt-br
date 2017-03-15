---
title: "3.2 Lock Functions | Microsoft Docs"
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
ms.assetid: 0ec855c6-55a9-49d7-bee4-5edae6e86a1b
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 3.2 Lock Functions
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As funções descritas nesta seção manipulam bloqueios usados para sincronização.  
  
 Para as seguintes funções, a variável de bloqueio deve ser do tipo  **omp\_lock\_t**.  Essa variável só deve ser acessada através dessas funções.  Todas as funções de bloqueio exigem um argumento que tem um ponteiro para  **omp\_lock\_t** tipo.  
  
-   O `omp_init_lock` função inicializa um bloqueio simple.  
  
-   O `omp_destroy_lock` função remove um bloqueio simple.  
  
-   O `omp_set_lock` função aguarda até que um bloqueio simple esteja disponível.  
  
-   O `omp_unset_lock` função libera um bloqueio simple.  
  
-   O `omp_test_lock` função testa um bloqueio simple.  
  
 Para as seguintes funções, a variável de bloqueio deve ser do tipo  **omp\_nest\_lock\_t**.  Essa variável só deve ser acessada através dessas funções.  Todas as funções de bloqueio nestable requerem um argumento que tem um ponteiro para  **omp\_nest\_lock\_t** tipo.  
  
-   O `omp_init_nest_lock` função inicializa um bloqueio de nestable.  
  
-   O `omp_destroy_nest_lock` função remove um bloqueio de nestable.  
  
-   O `omp_set_nest_lock` função aguarda até que um bloqueio de nestable esteja disponível.  
  
-   O `omp_unset_nest_lock` função libera um bloqueio de nestable.  
  
-   O `omp_test_nest_lock` função testa um bloqueio de nestable.  
  
 As funções de bloqueio do OpenMP acessar a variável de bloqueio de tal forma que eles sempre ler e atualizar o valor mais atual da variável de bloqueio.  Portanto, não é necessário para que um programa OpenMP incluem explícita  **liberar** diretivas para garantir que o valor da variável de bloqueio seja consistente entre diferentes segmentos.  \(Pode haver a necessidade de  **liberar** diretivas para tornar os valores de outras variáveis consistente.\)