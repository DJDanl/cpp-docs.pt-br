---
title: F. Novos recursos e esclarecimentos na versão 2.0 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 0d4beb66-f2d5-468c-8cd3-4b00dcbab061
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8e48f299e66ed1b4c075757a9cd143d0afe897db
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33693137"
---
# <a name="f-new-features-and-clarifications-in-version-20"></a>F. Novos recursos e esclarecimentos na versão 2.0
Este apêndice resume as principais alterações feitas com a especificação do OpenMP C/C++ na movimentação da versão 1.0 para a versão 2.0. Os seguintes itens são novos recursos adicionados a especificação de:  
  
-   Vírgulas são permitidas em diretivas OpenMP ([seção 2.1](../../parallel/openmp/2-1-directive-format.md) na página 7).  
  
-   Adição de `num_threads` cláusula. Essa cláusula permite que um usuário solicitar um número específico de segmentos de uma construção paralela ([seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8).  
  
-   O `threadprivate` diretiva foi estendida para aceitar as variáveis de escopo de bloco estático ([seção 2.7.1](../../parallel/openmp/2-7-1-threadprivate-directive.md) na página 23).  
  
-   Matrizes de comprimento variável C99 são tipos completos e, portanto, podem ser especificados em qualquer lugar tipos completos são permitidos, para a instância na lista de `private`, `firstprivate`, e `lastprivate` cláusulas ([seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25).  
  
-   Uma variável privada em uma região parallel pode ser marcada como particular novamente em uma diretiva aninhada ([seção 2.7.2.1](../../parallel/openmp/2-7-2-1-private.md) na página 25).  
  
-   O `copyprivate` cláusula foi adicionada. Ele fornece um mecanismo para usar uma variável privada para transmitir um valor de um membro de uma equipe para os outros membros. É uma alternativa ao uso de uma variável compartilhada para o valor ao fornecer essa variável compartilhada seria difícil (por exemplo, em uma recursão de necessidade de uma variável diferente em cada nível). O `copyprivate` cláusula só pode aparecer no **único** diretiva ([seção 2.7.2.8](../../parallel/openmp/2-7-2-8-copyprivate.md) na página 32).  
  
-   Adição de rotinas de tempo `omp_get_wtick` e `omp_get_wtime` semelhante às rotinas MPI. Essas funções são necessárias para executar os intervalos de relógio de parede ([seção 3.3.1](../../parallel/openmp/3-3-1-omp-get-wtime-function.md) na página 44 e [seção 3.3.2](../../parallel/openmp/3-3-2-omp-get-wtick-function.md) na página 45).  
  
-   Foi adicionado um apêndice com uma lista de comportamentos definidos na implementação OpenMP C/C++. Uma implementação é necessária para definir e documentar seu comportamento nesses casos ([Apêndice E](../../parallel/openmp/e-implementation-defined-behaviors-in-openmp-c-cpp.md) na página 97).  
  
-   As seguintes alterações servem para esclarecer ou corrigir recursos na especificação da API do OpenMP anterior para C/C++:  
  
    -   Esclareceu que o comportamento de `omp_set_nested` e `omp_set_dynamic` quando `omp_in_parallel` retorna zero é indefinido ([seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39, e [seção 3.1.9](../../parallel/openmp/3-1-9-omp-set-nested-function.md) na página 40).  
  
    -   Esclareceu aninhamento de diretiva quando paralelo aninhado é usado ([seção 2.9](../../parallel/openmp/2-9-directive-nesting.md) na página 33).  
  
    -   As funções de destruição de inicialização e bloqueio de bloqueio podem ser chamadas em uma região parallel ([seção 3.2.1](../../parallel/openmp/3-2-1-omp-init-lock-and-omp-init-nest-lock-functions.md) na página 42 e [seção 3.2.2](../../parallel/openmp/3-2-2-omp-destroy-lock-and-omp-destroy-nest-lock-functions.md) na página 42).  
  
    -   Foram adicionados novos exemplos ([Apêndice A](../../parallel/openmp/a-examples.md) na página 51).