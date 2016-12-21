---
title: "barrier | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "barrier"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "barrier OpenMP directive"
ms.assetid: 5c73ad4f-c768-443a-8f9e-4fd8bc2253c7
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# barrier
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Sincroniza todos os threads de uma equipe; todos os threads faça uma pausa na barreira, até que todos os segmentos de executar a barreira.  
  
## Sintaxe  
  
```  
#pragma omp barrier  
```  
  
## Comentários  
 O `barrier` diretiva oferece suporte a cláusulas sem OpenMP.  
  
 Para obter mais informações, consulte [2.6.3 barrier Directive](../../../parallel/openmp/2-6-3-barrier-directive.md).  
  
## Exemplo  
 Para obter um exemplo de como usar `barrier`, consulte [master](../../../parallel/openmp/reference/master.md).  
  
## Consulte também  
 [Directives](../../../parallel/openmp/reference/openmp-directives.md)