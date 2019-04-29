---
title: F. Novos recursos e esclarecimentos na versão 2.0
ms.date: 01/22/2019
ms.assetid: 0d4beb66-f2d5-468c-8cd3-4b00dcbab061
ms.openlocfilehash: 2e186bbc82f4f43e831dd05cdded2a9e946d1dd2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62362706"
---
# <a name="f-new-features-and-clarifications-in-version-20"></a>F. Novos recursos e esclarecimentos na versão 2.0

Este apêndice resume as principais alterações feitas à especificação de OpenMP C/C++ na movimentação da versão 1.0 para a versão 2.0. Os seguintes itens são novos recursos adicionados à especificação de:

- Vírgulas são permitidas em OpenMP [diretivas](2-directives.md#21-directive-format).

- Adição do `num_threads` cláusula. Essa cláusula permite que um usuário solicitar um número específico de segmentos de uma [constructo paralelo](2-directives.md#23-parallel-construct).

- O [threadprivate](2-directives.md#271-threadprivate-directive) diretiva foi estendida para aceitar as variáveis de escopo de bloco estático.

- Matrizes de comprimento variável C99 são tipos completos e pode ser especificados de qualquer lugar tipos completos são permitidos, como as listas de `private`, `firstprivate`, e `lastprivate` cláusulas (consulte [seção 2.7.2](2-directives.md#272-data-sharing-attribute-clauses)).

- Uma variável privada em uma região paralela pode ser marcada [privada](2-directives.md#2721-private) novamente em uma diretiva aninhada.

- O `copyprivate` cláusula foi adicionada. Ele fornece um mecanismo para usar uma variável particular para transmitir um valor de um membro de uma equipe para os outros membros. É uma alternativa ao uso de uma variável compartilhada para o valor ao fornecimento de uma variável compartilhada como seria difícil (por exemplo, em uma necessidade de uma variável diferente em cada nível de recursão). O [copyprivate](2-directives.md#2728-copyprivate) cláusula só pode aparecer no `single` diretiva.

- Adição de rotinas de tempo [omp_get_wtick](3-run-time-library-functions.md#332-omp_get_wtick-function) e [omp_get_wtime](3-run-time-library-functions.md#331-omp_get_wtime-function) semelhante para as rotinas MPI. Essas funções são necessárias para os intervalos de relógio de parede.

- Um apêndice com uma lista de [comportamentos definidos por implementação](e-implementation-defined-behaviors-in-openmp-c-cpp.md) foi adicionado no OpenMP C/C++. Uma implementação é necessária para definir e documentar seu comportamento nesses casos.

- As alterações a seguir servem para esclarecer ou corrigir recursos na especificação da API OpenMP anterior para C/C++:

  - Esclareceu que o comportamento de [omp_set_nested](3-run-time-library-functions.md#319-omp_set_nested-function) e [omp_set_dynamic](3-run-time-library-functions.md#317-omp_set_dynamic-function) quando `omp_in_parallel` retorna diferente de zero é indefinido.

  - Esclareceu [aninhamento de diretiva](2-directives.md#29-directive-nesting) quando aninhado paralelo é usado.

  - O [inicialização de bloqueio](3-run-time-library-functions.md#321-omp_init_lock-and-omp_init_nest_lock-functions) e [bloquear destruição](3-run-time-library-functions.md#322-omp_destroy_lock-and-omp_destroy_nest_lock-functions) funções podem ser chamadas em uma região paralela.

  - Novos exemplos foram adicionados ao [Apêndice A](a-examples.md).