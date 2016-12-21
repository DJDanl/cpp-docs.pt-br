---
title: "OpenMP Directives | Microsoft Docs"
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
ms.assetid: 0562c263-344c-466d-843e-de830d918940
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# OpenMP Directives
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Fornece links para as diretivas usadas na API OpenMP.  
  
 Visual C\+\+ dá suporte as seguintes diretivas OpenMP:  
  
|Diretiva|Descrição|  
|--------------|---------------|  
|[atomic](../../../parallel/openmp/reference/atomic.md)|Especifica que um local de memória que será atualizado atomicamente.|  
|[barrier](../../../parallel/openmp/reference/barrier.md)|Sincroniza todos os threads de uma equipe; todos os threads faça uma pausa na barreira, até que todos os segmentos de executar a barreira.|  
|[critical](../../../parallel/openmp/reference/critical.md)|Especifica o código só é executado em um segmento por vez.|  
|[flush](../../../parallel/openmp/reference/flush-openmp.md)|Especifica que todos os segmentos têm o mesmo modo de exibição de memória para todos os objetos compartilhados.|  
|[for](../Topic/for%20\(OpenMP\).md)|Faz com que o trabalho realizado em um loop for dentro de uma região paralela seja dividido entre os threads.|  
|[master](../../../parallel/openmp/reference/master.md)|Especifica que somente o mestre threadshould executar uma seção do programa.|  
|[ordered](../../../parallel/openmp/reference/ordered-openmp-directives.md)|Especifica que o código em um paralelo loop deve ser executado como um loop seqüencial.|  
|[parallel](../../../parallel/openmp/reference/parallel.md)|Define uma região paralela, que é o código que será executado por vários threads em paralelo.|  
|[sections](../../../parallel/openmp/reference/sections-openmp.md)|Identifica as seções de código seja dividido entre todos os threads.|  
|[single](../Topic/single.md)|Permite especificar que uma seção de código deve ser executada em um único segmento, não necessariamente o thread mestre.|  
|[threadprivate](../Topic/threadprivate.md)|Especifica que uma variável é privativo de um thread.|  
  
## Consulte também  
 [OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)   
 [Clauses](../../../parallel/openmp/reference/openmp-clauses.md)