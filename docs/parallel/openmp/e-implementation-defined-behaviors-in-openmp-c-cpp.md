---
title: E. Comportamentos definidos por implementação no OpenMP C/C++
ms.date: 01/22/2019
ms.assetid: b8d660ca-9bb3-4b6b-87af-45c67d43a731
ms.openlocfilehash: e866eee9c6d85e93388f9f1d086badf948e2600e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80215040"
---
# <a name="e-implementation-defined-behaviors-in-openmp-cc"></a>E. Comportamentos definidos por implementação no OpenMP C/C++

Este apêndice resume os comportamentos descritos como "definido pela implementação" nessa API.  Cada comportamento é referenciado de volta para sua descrição na Especificação principal.

## <a name="remarks"></a>Comentários

Uma implementação é necessária para definir e documentar seu comportamento nesses casos, mas essa lista pode estar incompleta.

- **Número de threads:** Se uma região paralela for encontrada enquanto o ajuste dinâmico do número de threads estiver desabilitado e o número de threads solicitados para a região paralela for maior que o número que o sistema de tempo de execução pode fornecer, o comportamento do programa será definido pela implementação (consulte a página 9).

   No Visual C++, para uma região paralela não aninhada, 64 threads (o máximo) serão fornecidos.

- **Número de processadores:** O número de processadores físicos que hospedam os threads em um determinado momento é definido pela implementação (consulte a página 10).

   No Visual C++, esse número não é constante e é controlado pelo sistema operacional.

- **Criando equipes de threads:** O número de threads em uma equipe que executa uma região paralela aninhada é definido pela implementação (consulte a página 10).

   No Visual C++, esse número é determinado pelo sistema operacional.

- **agenda (tempo de execução):** A decisão sobre o agendamento é adiada até o tempo de execução. O tipo de agendamento e o tamanho da parte podem ser escolhidos em tempo de execução, definindo a variável de ambiente `OMP_SCHEDULE`. Se essa variável de ambiente não estiver definida, a agenda resultante será definida pela implementação (consulte a página 13).

   No Visual C++, o tipo de agendamento é `static` sem tamanho de parte.

- **Agendamento padrão:** Na ausência da cláusula Schedule, o agendamento padrão é definido pela implementação (consulte a página 13).

   No Visual C++, o tipo de agendamento padrão é `static` sem nenhum tamanho de bloco.

- **Atômico:** É definido pela implementação se uma implementação substitui todas as diretivas de `atomic` com `critical` diretivas que têm o mesmo nome exclusivo (consulte a página 20).

   No Visual C++, se os dados modificados pelo [Atomic](reference/openmp-directives.md#atomic) não estiverem em um alinhamento natural ou se forem um ou dois bytes, todas as operações atômicas que atendem a essa propriedade usarão uma seção crítica. Caso contrário, as seções críticas não serão usadas.

- **[omp_get_num_threads](3-run-time-library-functions.md#312-omp_get_num_threads-function):** Se o número de threads não tiver sido explicitamente definido pelo usuário, o padrão será definido pela implementação (consulte a página 9).

   No Visual C++, o número padrão de threads é igual ao número de processadores.

- **[omp_set_dynamic](3-run-time-library-functions.md#317-omp_set_dynamic-function):** O padrão para o ajuste de thread dinâmico é definido pela implementação.

   No Visual C++, o padrão é `FALSE`.

- **[omp_set_nested](3-run-time-library-functions.md#319-omp_set_nested-function):** Quando o paralelismo aninhado está habilitado, o número de threads usados para executar regiões paralelas aninhadas é definido pela implementação.

   No Visual C++, o número de threads é determinado pelo sistema operacional.

- [OMP_SCHEDULE](4-environment-variables.md#41-omp_schedule) variável de ambiente: o valor padrão para essa variável de ambiente é definido pela implementação.

   No Visual C++, o tipo de agendamento é `static` sem tamanho de parte.

- [OMP_NUM_THREADS](4-environment-variables.md#42-omp_num_threads) variável de ambiente: se nenhum valor for especificado para a variável de ambiente `OMP_NUM_THREADS`, ou se o valor especificado não for um inteiro positivo ou se o valor for maior que o número máximo de threads que o sistema pode dar suporte, o número de threads a serem usados será definido pela implementação.

   No Visual C++, se o valor especificado for zero ou menos, o número de threads será igual ao número de processadores.  Se o valor for maior que 64, o número de threads será 64.

- [OMP_DYNAMIC](4-environment-variables.md#43-omp_dynamic) variável de ambiente: o valor padrão é definido pela implementação.

   No Visual C++, o padrão é `FALSE`.
