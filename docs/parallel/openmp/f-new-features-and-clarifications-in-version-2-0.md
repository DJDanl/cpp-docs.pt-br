---
title: "F. New Features and Clarifications in Version 2.0 | Microsoft Docs"
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
ms.assetid: 0d4beb66-f2d5-468c-8cd3-4b00dcbab061
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# F. New Features and Clarifications in Version 2.0
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este apêndice resume as principais alterações feitas a especificação do OpenMP C\/C\+\+ na movimentação da versão 1.0 para a versão 2.0.  Os itens a seguir são os novos recursos adicionados a especificação:  
  
-   Vírgulas são permitidas as diretivas do OpenMP \([seção 2.1](../Topic/2.1%20Directive%20Format.md) na página 7\).  
  
-   Adição da `num_threads` cláusula.  Essa cláusula permite que um usuário solicitar um número específico de segmentos de uma construção paralela \([seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8\).  
  
-   O `threadprivate` diretiva foi estendida para aceitar variáveis estáticas de escopo de bloco \([seção 2.7.1](../../parallel/openmp/2-7-1-threadprivate-directive.md) na página 23\).  
  
-   Matrizes de comprimento variável de C99 são tipos completos e, portanto, podem ser especificados em qualquer lugar completos tipos são permitidos, por exemplo nas listas de `private`, `firstprivate`, e `lastprivate` cláusulas \([seção 2.7.2](../Topic/2.7.2%20Data-Sharing%20Attribute%20Clauses.md) na página 25\).  
  
-   Uma variável private em uma região paralela pode ser marcado como particular novamente em uma diretiva de aninhados \([seção 2.7.2.1](../../parallel/openmp/2-7-2-1-private.md) na página 25\).  
  
-   O `copyprivate` cláusula foi adicionada.  Ele fornece um mecanismo para usar uma variável particular para difundir um valor de um membro de uma equipe para os outros membros.  É uma alternativa ao uso de uma variável compartilhada para o valor ao fornecer uma variável compartilhada seria difícil \(por exemplo, em uma recursão exigindo uma variável diferente em cada nível\).  O `copyprivate` cláusula só pode aparecer à  **único** diretiva \([seção 2.7.2.8](../Topic/2.7.2.8%20copyprivate.md) na página 32\).  
  
-   Adição de rotinas de cronometragem `omp_get_wtick` e `omp_get_wtime` semelhante para as rotinas MPI.  Essas funções são necessárias para executar os intervalos de relógio de parede \([seção 3.3.1](../../parallel/openmp/3-3-1-omp-get-wtime-function.md) na página 44 e  [seção 3.3.2](../Topic/3.3.2%20omp_get_wtick%20Function.md) na página 45\).  
  
-   Foi adicionado um apêndice com uma lista de comportamentos definidos na implementação OpenMP C\/C\+\+.  Uma implementação é necessária para definir e documentar o seu comportamento nesses casos \([Apêndice E](../Topic/E.%20Implementation-Defined%20Behaviors%20in%20OpenMP%20C-C++.md) na página 97\).  
  
-   As alterações a seguir servem para esclarecer ou corrigir a recursos na especificação da API OpenMP anterior para C\/C\+\+:  
  
    -   Esclarecido que o comportamento de `omp_set_nested` e `omp_set_dynamic` quando `omp_in_parallel` retorna diferente de zero é indefinida \([seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39, e  [seção 3.1.9](../../parallel/openmp/3-1-9-omp-set-nested-function.md) na página 40\).  
  
    -   Esclarecida a diretriz aninhamento quando paralelo aninhado é usado \([seção 2,9](../../parallel/openmp/2-9-directive-nesting.md) na página 33\).  
  
    -   As funções de destruição de inicialização e o bloqueio do bloqueio podem ser chamadas em uma região paralela \([seção 3.2.1](../../parallel/openmp/3-2-1-omp-init-lock-and-omp-init-nest-lock-functions.md) na página 42 e  [seção 3.2.2](../Topic/3.2.2%20omp_destroy_lock%20and%20omp_destroy_nest_lock%20Functions.md) na página 42\).  
  
    -   Foram adicionados novos exemplos \([Apêndice A](../Topic/A.%20Examples.md) na página 51\).