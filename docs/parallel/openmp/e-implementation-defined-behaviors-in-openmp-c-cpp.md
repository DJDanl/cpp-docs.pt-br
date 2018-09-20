---
title: E. Definido por implementação no OpenMP C/C++ de comportamentos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: b8d660ca-9bb3-4b6b-87af-45c67d43a731
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6e2e8360dbb2c8851a0ac1c09767928703708a97
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46405002"
---
# <a name="e-implementation-defined-behaviors-in-openmp-cc"></a>E. Comportamentos definidos por implementação no OpenMP C/C++

Este apêndice resume os comportamentos que são descritos como "definido pela implementação" nessa API.  Cada comportamento é referência cruzado a sua descrição na especificação do principal.

## <a name="remarks"></a>Comentários

Uma implementação é necessária para definir e documentar seu comportamento nesses casos, mas essa lista pode estar incompleta.

- **Número de threads:** se uma região parallel for encontrada, enquanto o ajuste dinâmico do número de threads está desabilitado e o número de threads solicitada para a região paralela excede o número que o sistema de tempo de execução pode fornecer o comportamento do o programa é definido pela implementação (consulte a página 9).

     No Visual C++, para uma região paralela não aninhadas, 64 threads (o máximo) serão fornecidos.

- **Número de processadores:** o número de processadores físicos, hospedagem, na verdade, os threads em um determinado momento é definido pela implementação (consulte a página 10).

     No Visual C++, esse número não é constante e é controlado pelo sistema operacional.

- **Criando equipes de threads:** o número de threads em uma equipe que executam uma região paralela aninhada é definido pela implementação. ( Consulte a página 10).

     No Visual C++, isso é determinado pelo sistema operacional.

- **Schedule (Runtime):** a decisão sobre agendamento é adiada até o tempo de execução. O tamanho de bloco e de tipo de agenda pode ser escolhido no tempo de execução, definindo o `OMP_SCHEDULE` variável de ambiente. Se essa variável de ambiente não for definido, o agendamento resultante é definido pela implementação (consulte a página 13).

     No Visual C++, o tipo de agenda é `static` com nenhum tamanho de bloco.

- **Agendamento padrão:** na ausência da cláusula de agendamento, o agendamento padrão é definido pela implementação (consulte a página 13).

     No Visual C++, o tipo de agendamento padrão é `static` com nenhum tamanho de bloco.

- **ATÔMICA:** é definido pela implementação se uma implementação substitui todos os `atomic` diretivas com **críticos** diretivas que têm o mesmo nome exclusivo (consulte a página 20).

     No Visual C++, se os dados modificados por [atômica](../../parallel/openmp/reference/atomic.md) não está em um alinhamento natural ou se for 1 ou 2 bytes longa todas as operações atômicas que atendem a essa propriedade serão usar uma seção crítica. Caso contrário, seções críticas não serão usadas.

- **omp_get_num_threads:** se o número de threads não foi explicitamente definido pelo usuário, o padrão é definido pela implementação (consulte a página 9, e [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37).

     No Visual C++, o número padrão de threads é igual ao número de processadores.

- **omp_set_dynamic:** o padrão para o ajuste dinâmico de thread é definido pela implementação (consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39).

     No Visual C++, o padrão é `FALSE`.

- **omp_set_nested:** quando o paralelismo aninhado é habilitado, o número de threads usados para executar as regiões aninhadas paralelas é definido pela implementação (consulte [seção 3.1.9](../../parallel/openmp/3-1-9-omp-set-nested-function.md) na página 40).

     No Visual C++, o número de threads é determinado pelo sistema operacional.

- `OMP_SCHEDULE` variável de ambiente: O valor padrão para essa variável de ambiente é definido pela implementação (consulte [seção 4.1](../../parallel/openmp/4-1-omp-schedule.md) na página 48).

     No Visual C++, o tipo de agenda é `static` com nenhum tamanho de bloco.

- `OMP_NUM_THREADS` variável de ambiente: se nenhum valor for especificado para o `OMP_NUM_THREADS` variável de ambiente, ou se o valor especificado não é um inteiro positivo, ou se o valor for maior que o número máximo de threads que o sistema pode dar suporte, o número de threads a ser usado é definido pela implementação (consulte [4.2 seção](../../parallel/openmp/4-2-omp-num-threads.md) na página 48).

     No Visual C++, se o valor especificado for zero ou menos, o número de threads é igual ao número de processadores.  Se o valor for maior que 64, o número de threads é 64.

- `OMP_DYNAMIC` variável de ambiente: O valor padrão é definido pela implementação (consulte [seção 4.3](../../parallel/openmp/4-3-omp-dynamic.md) na página 49).

     No Visual C++, o padrão é `FALSE`.