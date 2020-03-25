---
title: F. Novos recursos e esclarecimentos na versão 2.0
ms.date: 01/22/2019
ms.assetid: 0d4beb66-f2d5-468c-8cd3-4b00dcbab061
ms.openlocfilehash: 8cd82000992ab957bf2c41f11deccd65e2e6ea8f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80215027"
---
# <a name="f-new-features-and-clarifications-in-version-20"></a>F. Novos recursos e esclarecimentos na versão 2.0

Este apêndice resume as principais alterações feitas na especificação de OpenMP C/C++ em migrando da versão 1,0 para a versão 2,0. Os seguintes itens são novos recursos adicionados à especificação:

- As vírgulas são permitidas em [diretivas](2-directives.md#21-directive-format)de OpenMP.

- Adição da cláusula `num_threads`. Essa cláusula permite que um usuário solicite um número específico de threads para uma [construção paralela](2-directives.md#23-parallel-construct).

- A diretiva [threadprivate](2-directives.md#271-threadprivate-directive) foi estendida para aceitar variáveis de escopo de bloco estáticas.

- As matrizes de comprimento variável C99 são tipos completos e podem ser especificadas em qualquer lugar que os tipos completos são permitidos, como nas listas de cláusulas `private`, `firstprivate`e `lastprivate` (consulte a [seção 2.7.2](2-directives.md#272-data-sharing-attribute-clauses)).

- Uma variável privada em uma região paralela pode ser marcada como [particular](2-directives.md#2721-private) novamente em uma diretiva aninhada.

- A cláusula `copyprivate` foi adicionada. Ele fornece um mecanismo para usar uma variável privada para transmitir um valor de um membro de uma equipe para os outros membros. É uma alternativa ao uso de uma variável compartilhada para o valor ao fornecer uma variável compartilhada como essa seria difícil (por exemplo, em uma recursão que requer uma variável diferente em cada nível). A cláusula [copyprivate](2-directives.md#2728-copyprivate) só pode aparecer na diretiva `single`.

- Adição de rotinas de tempo [omp_get_wtick](3-run-time-library-functions.md#332-omp_get_wtick-function) e [omp_get_wtime](3-run-time-library-functions.md#331-omp_get_wtime-function) semelhante às rotinas MPI. Essas funções são necessárias para fazer intervalos de relógio de parede.

- Um apêndice com uma lista de [comportamentos definidos pela implementação](e-implementation-defined-behaviors-in-openmp-c-cpp.md) em OpenMP C/C++ foi adicionado. Uma implementação é necessária para definir e documentar seu comportamento nesses casos.

- As alterações a seguir servem para esclarecer ou corrigir os recursos na especificação de API de OpenMP anteriorC++para C/:

  - Esclareceu que o comportamento de [omp_set_nested](3-run-time-library-functions.md#319-omp_set_nested-function) e [omp_set_dynamic](3-run-time-library-functions.md#317-omp_set_dynamic-function) quando `omp_in_parallel` retorna zero é indefinido.

  - [Aninhamento de diretiva](2-directives.md#29-directive-nesting) esclarecido quando paralelo aninhado é usado.

  - A [inicialização de bloqueio](3-run-time-library-functions.md#321-omp_init_lock-and-omp_init_nest_lock-functions) e as funções de [destruição de bloqueio](3-run-time-library-functions.md#322-omp_destroy_lock-and-omp_destroy_nest_lock-functions) podem ser chamadas em uma região paralela.

  - Novos exemplos foram adicionados ao [Apêndice a](a-examples.md).
