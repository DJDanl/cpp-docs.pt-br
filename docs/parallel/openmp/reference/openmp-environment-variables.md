---
title: OpenMP variáveis de ambiente | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
dev_langs:
- C++
ms.assetid: 2178ce2b-ffa1-45ec-a455-64437711d15d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 98b61535fd07066c4a1ee24658fdfe81047efc90
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46446563"
---
# <a name="openmp-environment-variables"></a>OpenMP Variáveis de ambiente

Fornece links para as variáveis de ambiente usadas na API OpenMP.

A implementação do Visual C++ do OpenMP padrão inclui as seguintes variáveis de ambiente. Essas variáveis de ambiente são lidas na inicialização do programa e as modificações com seus valores são ignoradas em tempo de execução (por exemplo, usando [putenv, wputenv](../../../c-runtime-library/reference/putenv-wputenv.md)).

|Variável de ambiente|Descrição|
|--------------------------|-----------------|
|[OMP_DYNAMIC](../../../parallel/openmp/reference/omp-dynamic.md)|Especifica se o OpenMP no tempo de execução pode ajustar o número de threads em uma região paralela.|
|[OMP_NESTED](../../../parallel/openmp/reference/omp-nested.md)|Especifica se o paralelismo aninhado está habilitado, a menos que o paralelismo aninhado está habilitado ou desabilitado com `omp_set_nested`.|
|[OMP_NUM_THREADS](../../../parallel/openmp/reference/omp-num-threads.md)|Define o número máximo de threads na região paralela, a menos que substituído por [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) ou [num_threads](../../../parallel/openmp/reference/num-threads.md).|
|[OMP_SCHEDULE](../../../parallel/openmp/reference/omp-schedule.md)|Modifica o comportamento do [agendamento](../../../parallel/openmp/reference/schedule.md) cláusula quando `schedule(runtime)` é especificado em uma `for` ou `parallel for` diretiva.|

## <a name="see-also"></a>Consulte também

[Referência da biblioteca](../../../parallel/openmp/reference/openmp-library-reference.md)