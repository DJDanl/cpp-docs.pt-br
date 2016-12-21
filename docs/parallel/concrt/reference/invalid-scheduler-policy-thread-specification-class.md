---
title: "Classe invalid_scheduler_policy_thread_specification | Microsoft Docs"
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
  - "concrt/concurrency::invalid_scheduler_policy_thread_specification"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe invalid_scheduler_policy_thread_specification"
ms.assetid: 2d0fafb2-18f8-4284-8040-3db640d33303
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe invalid_scheduler_policy_thread_specification
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção gerada quando é realizada uma tentativa de definir os limites de simultaneidade de um objeto de `SchedulerPolicy` de modo que o valor da chave de `MinConcurrency` for menor que o valor da chave de `MaxConcurrency` .  
  
## Sintaxe  
  
```  
class invalid_scheduler_policy_thread_specification : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor invalid\_scheduler\_policy\_thread\_specification::invalid\_scheduler\_policy\_thread\_specification](../Topic/invalid_scheduler_policy_thread_specification::invalid_scheduler_policy_thread_specification%20Constructor.md)|Sobrecarregado.  Constrói um objeto `invalid_scheduler_policy_value`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `invalid_scheduler_policy_thread_specification`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe SchedulerPolicy](../../../parallel/concrt/reference/schedulerpolicy-class.md)   
 [Enumeração PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md)   
 [Método SchedulerPolicy::SetConcurrencyLimits](../Topic/SchedulerPolicy::SetConcurrencyLimits%20Method.md)