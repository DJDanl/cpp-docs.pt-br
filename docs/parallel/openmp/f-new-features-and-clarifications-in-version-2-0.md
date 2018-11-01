---
title: F. Novos recursos e esclarecimentos na versão 2.0
ms.date: 11/04/2016
ms.assetid: 0d4beb66-f2d5-468c-8cd3-4b00dcbab061
ms.openlocfilehash: c8a597c6af397bd162d92a945d96409b1839e2a3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50657124"
---
# <a name="f-new-features-and-clarifications-in-version-20"></a>F. Novos recursos e esclarecimentos na versão 2.0

Este apêndice resume as principais alterações feitas à especificação de OpenMP C/C++ na movimentação da versão 1.0 para a versão 2.0. Os seguintes itens são novos recursos adicionados à especificação de:

- Vírgulas são permitidas em diretivas OpenMP ([seção 2.1](../../parallel/openmp/2-1-directive-format.md) na página 7).

- Adição do `num_threads` cláusula. Essa cláusula permite que um usuário solicitar um número específico de segmentos de uma construção paralela ([seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8).

- O `threadprivate` diretiva foi estendida para aceitar as variáveis de escopo de bloco estático ([seção 2.7.1](../../parallel/openmp/2-7-1-threadprivate-directive.md) na página 23).

- Matrizes de comprimento variável C99 são tipos completos e, portanto, podem ser especificados em qualquer lugar tipos completos são permitidos, por exemplo na lista de `private`, `firstprivate`, e `lastprivate` cláusulas ([seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25).

- Uma variável privada em uma região paralela pode ser marcado como privada novamente em uma diretiva aninhada ([seção 2.7.2.1](../../parallel/openmp/2-7-2-1-private.md) na página 25).

- O `copyprivate` cláusula foi adicionada. Ele fornece um mecanismo para usar uma variável particular para transmitir um valor de um membro de uma equipe para os outros membros. É uma alternativa ao uso de uma variável compartilhada para o valor ao fornecimento de uma variável compartilhada como seria difícil (por exemplo, em uma necessidade de uma variável diferente em cada nível de recursão). O `copyprivate` cláusula só pode aparecer na **única** diretiva ([seção 2.7.2.8](../../parallel/openmp/2-7-2-8-copyprivate.md) na página 32).

- Adição de rotinas de tempo `omp_get_wtick` e `omp_get_wtime` semelhante para as rotinas MPI. Essas funções são necessárias para executar a intervalos de relógio de parede ([seção 3.3.1](../../parallel/openmp/3-3-1-omp-get-wtime-function.md) na página 44 e [seção 3.3.2](../../parallel/openmp/3-3-2-omp-get-wtick-function.md) na página 45).

- Foi adicionado um apêndice com uma lista de comportamentos definidos por implementação no OpenMP C/C++. Uma implementação é necessária para definir e documentar seu comportamento nesses casos ([Apêndice E](../../parallel/openmp/e-implementation-defined-behaviors-in-openmp-c-cpp.md) na página 97).

- As alterações a seguir servem para esclarecer ou corrigir recursos na especificação da API OpenMP anterior para C/C++:

   - Esclareceu que o comportamento de `omp_set_nested` e `omp_set_dynamic` quando `omp_in_parallel` retorna diferente de zero é indefinido ([seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39, e [seção 3.1.9](../../parallel/openmp/3-1-9-omp-set-nested-function.md) na página 40).

   - Esclareceu o aninhamento de diretiva quando aninhado paralelo é usado ([seção 2.9](../../parallel/openmp/2-9-directive-nesting.md) na página 33).

   - As funções de destruição de inicialização e bloqueio de bloqueio podem ser chamadas em uma região paralela ([seção 3.2.1](../../parallel/openmp/3-2-1-omp-init-lock-and-omp-init-nest-lock-functions.md) na página 42 e [seção 3.2.2](../../parallel/openmp/3-2-2-omp-destroy-lock-and-omp-destroy-nest-lock-functions.md) na página 42).

   - Foram adicionados novos exemplos ([Apêndice A](../../parallel/openmp/a-examples.md) na página 51).