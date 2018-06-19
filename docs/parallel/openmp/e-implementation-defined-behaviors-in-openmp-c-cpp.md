---
title: E. OpenMP C/C++ de comportamentos definidos na implementação | Microsoft Docs
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
ms.openlocfilehash: 598964ec6a12ac4c357efc04df78bfbe3af798a5
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33688694"
---
# <a name="e-implementation-defined-behaviors-in-openmp-cc"></a>E. Comportamentos definidos na implementação OpenMP C/C++
Este apêndice resume os comportamentos que são descritos como "definido pela implementação" nessa API.  Cada comportamento é referência cruzado a sua descrição na especificação do principal.  
  
## <a name="remarks"></a>Comentários  
 Uma implementação é necessária para definir e documentar seu comportamento nesses casos, mas essa lista pode estar incompleta.  
  
-   **Número de threads:** se uma região parallel for encontrada durante o ajuste dinâmico do número de threads está desabilitado e o número de threads solicitado para a região parallel excede o número que pode fornecer o sistema de tempo de execução, o comportamento de o programa é definido por implementação (consulte a página 9).  
  
     No Visual C++, para uma região parallel não aninhados, 64 threads (o máximo) serão fornecidos.  
  
-   **Número de processadores:** o número de processadores físicos de hospedagem, na verdade, os threads a qualquer momento determinado é definido por implementação (consulte a página 10).  
  
     No Visual C++, esse número não é constante e é controlado pelo sistema operacional.  
  
-   **Criação de equipes de threads:** o número de segmentos em uma equipe que execute uma região parallel aninhada é definido pela implementação. ( Consulte a página 10).  
  
     No Visual C++, isso é determinado pelo sistema operacional.  
  
-   **Schedule (Runtime):** a decisão sobre planejamento é adiada até o tempo de execução. O tamanho de bloco e de tipo de agenda pode ser escolhido em tempo de execução, definindo o `OMP_SCHEDULE` variável de ambiente. Se essa variável de ambiente não for definida, a agenda resultante é definidos na implementação (consulte a página 13).  
  
     No Visual C++, o tipo de agenda é `static` com nenhum tamanho do bloco.  
  
-   **Agendamento padrão:** na ausência da cláusula de agenda, o agendamento padrão é definido por implementação (consulte a página 13).  
  
     No Visual C++, o tipo de agendamento padrão é `static` com nenhum tamanho do bloco.  
  
-   **ATÔMICO:** é definido pela implementação se uma implementação substitui todos os `atomic` diretivas com **crítico** diretivas que têm o mesmo nome exclusivo (consulte a página 20).  
  
     No Visual C++, se os dados modificados por [atômico](../../parallel/openmp/reference/atomic.md) não está em um alinhamento natural ou se for 1 ou 2 bytes tempo todas as operações atômicas que atendem a essa propriedade usará uma seção crítica. Caso contrário, as seções críticas não serão usadas.  
  
-   **omp_get_num_threads:** se o número de threads não foi explicitamente definido pelo usuário, o padrão é definido por implementação (consulte a página 9, e [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37).  
  
     No Visual C++, o número padrão de threads é igual ao número de processadores.  
  
-   **omp_set_dynamic:** o padrão de ajuste dinâmico de segmento é definido por implementação (consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39).  
  
     No Visual C++, o padrão é `FALSE`.  
  
-   **omp_set_nested:** ao paralelismo aninhado estiver habilitado, o número de threads usados para executar regiões paralelas aninhadas é definido por implementação (consulte [seção 3.1.9](../../parallel/openmp/3-1-9-omp-set-nested-function.md) na página 40).  
  
     No Visual C++, o número de threads é determinado pelo sistema operacional.  
  
-   `OMP_SCHEDULE` variável de ambiente: O valor padrão para essa variável de ambiente é definido por implementação (consulte [seção 4.1](../../parallel/openmp/4-1-omp-schedule.md) na página 48).  
  
     No Visual C++, o tipo de agenda é `static` com nenhum tamanho do bloco.  
  
-   `OMP_NUM_THREADS` variável de ambiente: se nenhum valor for especificado para o `OMP_NUM_THREADS` variável de ambiente, ou se o valor especificado não é um inteiro positivo, ou se o valor for maior que o número máximo de threads que o sistema oferece suporte, é o número de threads a ser usado definido por implementação (consulte [seção 4.2](../../parallel/openmp/4-2-omp-num-threads.md) na página 48).  
  
     No Visual C++, se o valor especificado for zero ou menos, o número de threads é igual ao número de processadores.  Se o valor for maior que 64, o número de threads é 64.  
  
-   `OMP_DYNAMIC` variável de ambiente: O valor padrão é definido por implementação (consulte [seção 4.3](../../parallel/openmp/4-3-omp-dynamic.md) na página 49).  
  
     No Visual C++, o padrão é `FALSE`.