---
title: "OpenMP variáveis de ambiente | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 2178ce2b-ffa1-45ec-a455-64437711d15d
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 18e608862d59357ae26ff918b6b6a1c8b903b270
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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