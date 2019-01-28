---
title: E. Comportamentos definidos por implementação no OpenMP C/C++
ms.date: 01/22/2019
ms.assetid: b8d660ca-9bb3-4b6b-87af-45c67d43a731
ms.openlocfilehash: 3d8e9493cad1fce02e5d482cd5e612afb44bb37b
ms.sourcegitcommit: 382e247c0f1b4cb7c2dab837b8b6fdff24bff47a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/28/2019
ms.locfileid: "55087217"
---
# <a name="e-implementation-defined-behaviors-in-openmp-cc"></a>E. Comportamentos definidos por implementação no OpenMP C/C++

Este apêndice resume os comportamentos que são descritos como "definido pela implementação" nessa API.  Cada comportamento é referência cruzado a sua descrição na especificação do principal.

## <a name="remarks"></a>Comentários

Uma implementação é necessária para definir e documentar seu comportamento nesses casos, mas essa lista pode estar incompleta.

- **Número de threads:** Se uma região parallel for encontrada enquanto o ajuste dinâmico do número de threads está desabilitado e o número de threads solicitada para a região paralela é mais do que o número que o sistema de tempo de execução pode fornecer, o comportamento do programa é definido pela implementação (consulte a página 9).

   No Visual C++, para uma região paralela não aninhadas, 64 threads (o máximo) serão fornecidos.

- **Número de processadores:** O número de processadores físicos, hospedagem, na verdade, os threads em um determinado momento é definido pela implementação (consulte a página 10).

   No Visual C++, esse número não é constante e é controlado pelo sistema operacional.

- **Criando equipes de threads:** O número de threads que executam uma região paralela aninhada em uma equipe é definido pela implementação (consulte a página 10).

   No Visual C++, esse número é determinado pelo sistema operacional.

- **schedule(runtime):** A decisão sobre o agendamento é adiada até o tempo de execução. O tamanho de bloco e de tipo de agenda pode ser escolhido no tempo de execução, definindo o `OMP_SCHEDULE` variável de ambiente. Se essa variável de ambiente não for definido, o agendamento resultante é definido pela implementação (consulte a página 13).

   No Visual C++, o tipo de agenda é `static` com nenhum tamanho de bloco.

- **Padrão de agendamento:** Na ausência da cláusula de agendamento, o agendamento padrão é definido pela implementação (consulte a página 13).

   No Visual C++, o tipo de agendamento padrão é `static` com nenhum tamanho de bloco.

- **ATÔMICAS:** Ele é definido pela implementação se uma implementação substitui todos os `atomic` diretivas com `critical` diretivas que têm o mesmo nome exclusivo (consulte a página 20).

   No Visual C++, se os dados modificados por [atômica](reference/openmp-directives.md#atomic) não está em um alinhamento natural ou se for longa um ou dois bytes, todas as operações atômicas que atendem a essa propriedade serão usar uma seção crítica. Caso contrário, as seções críticas não serão usadas.

- **[omp_get_num_threads](3-run-time-library-functions.md#312-omp_get_num_threads-function):** Se o número de threads não foi explicitamente definido pelo usuário, o padrão é definido pela implementação (consulte a página 9).

   No Visual C++, o número padrão de threads é igual ao número de processadores.

- **[omp_set_dynamic](3-run-time-library-functions.md#317-omp_set_dynamic-function):** O padrão para o ajuste dinâmico de thread é definido pela implementação.

   No Visual C++, o padrão é `FALSE`.

- **[omp_set_nested](3-run-time-library-functions.md#319-omp_set_nested-function):** Quando o paralelismo aninhado é habilitado, o número de threads usados para executar as regiões aninhadas paralelas é definido pela implementação.

   No Visual C++, o número de threads é determinado pelo sistema operacional.

- [OMP_SCHEDULE](4-environment-variables.md#41-omp_schedule) variável de ambiente: O valor padrão para essa variável de ambiente é definido pela implementação.

   No Visual C++, o tipo de agenda é `static` com nenhum tamanho de bloco.

- [OMP_NUM_THREADS](4-environment-variables.md#42-omp_num_threads) variável de ambiente: Se nenhum valor for especificado para o `OMP_NUM_THREADS` variável de ambiente, ou se o valor especificado não é um inteiro positivo, ou se o valor for maior que o número máximo de threads que o sistema pode dar suporte, o número de threads a ser usado é definido pela implementação.

   No Visual C++, se o valor especificado for zero ou menos, o número de threads é igual ao número de processadores.  Se o valor for maior que 64, o número de threads é 64.

- [OMP_DYNAMIC](4-environment-variables.md#43-omp_dynamic) variável de ambiente: O valor padrão é definido pela implementação.

   No Visual C++, o padrão é `FALSE`.