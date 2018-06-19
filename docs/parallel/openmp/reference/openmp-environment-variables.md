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
ms.openlocfilehash: 02248b7725f2a4312f26984c798e7248463d2615
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33692302"
---
# <a name="openmp-environment-variables"></a>OpenMP Variáveis de ambiente
Fornece links para variáveis de ambiente usadas na API do OpenMP.  
  
 A implementação do Visual C++ do OpenMP padrão inclui as seguintes variáveis de ambiente. Essas variáveis de ambiente são lidas na inicialização do programa e modificações para seus valores são ignoradas em tempo de execução (por exemplo, usando [putenv, wputenv](../../../c-runtime-library/reference/putenv-wputenv.md)).  
  
|Variável de ambiente|Descrição|  
|--------------------------|-----------------|  
|[OMP_DYNAMIC](../../../parallel/openmp/reference/omp-dynamic.md)|Especifica se o OpenMP no tempo de execução pode ajustar o número de segmentos em uma região parallel.|  
|[OMP_NESTED](../../../parallel/openmp/reference/omp-nested.md)|Especifica se o paralelismo aninhado está habilitado, a menos que o paralelismo aninhado está habilitado ou desabilitado com `omp_set_nested`.|  
|[OMP_NUM_THREADS](../../../parallel/openmp/reference/omp-num-threads.md)|Define o número máximo de threads na região paralela, a menos que substituído por [omp_set_num_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) ou [num_threads](../../../parallel/openmp/reference/num-threads.md).|  
|[OMP_SCHEDULE](../../../parallel/openmp/reference/omp-schedule.md)|Modifica o comportamento do [agenda](../../../parallel/openmp/reference/schedule.md) cláusula quando `schedule(runtime)` é especificado em uma `for` ou `parallel for` diretiva.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca](../../../parallel/openmp/reference/openmp-library-reference.md)