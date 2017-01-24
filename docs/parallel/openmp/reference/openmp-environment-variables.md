---
title: "OpenMP Environment Variables | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 2178ce2b-ffa1-45ec-a455-64437711d15d
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# OpenMP Environment Variables
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Fornece links para as variáveis de ambiente usadas na API OpenMP.  
  
 A implementação do Visual C\+\+ do OpenMP padrão inclui as seguintes variáveis de ambiente.  Essas variáveis de ambiente são lidos na inicialização do programa e modificações em seus valores são ignoradas em tempo de execução \(por exemplo, usando [\_putenv, \_wputenv](../../../c-runtime-library/reference/putenv-wputenv.md)\).  
  
|Variável de ambiente|Descrição|  
|--------------------------|---------------|  
|[OMP\_DYNAMIC](../../../parallel/openmp/reference/omp-dynamic.md)|Especifica se o tempo de execução de OpenMP pode ajustar o número de segmentos em uma região paralela.|  
|[OMP\_NESTED](../../../parallel/openmp/reference/omp-nested.md)|Especifica se o paralelismo aninhado está ativado, a menos que o paralelismo aninhado está habilitado ou desabilitado com `omp_set_nested`.|  
|[OMP\_NUM\_THREADS](../Topic/OMP_NUM_THREADS.md)|Define o número máximo de threads na região paralela, a menos que substituída por [omp\_set\_num\_threads](../../../parallel/openmp/reference/omp-set-num-threads.md) ou [num\_threads](../../../parallel/openmp/reference/num-threads.md).|  
|[OMP\_SCHEDULE](../../../parallel/openmp/reference/omp-schedule.md)|Modifica o comportamento da [schedule](../../../parallel/openmp/reference/schedule.md) cláusula quando `schedule(runtime)` é especificado em um `for` ou `parallel for` diretiva.|  
  
## Consulte também  
 [Library Reference](../../../parallel/openmp/reference/openmp-library-reference.md)