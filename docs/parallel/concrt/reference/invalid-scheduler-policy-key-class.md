---
title: "Classe invalid_scheduler_policy_key | Microsoft Docs"
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
  - "concrt/concurrency::invalid_scheduler_policy_key"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe invalid_scheduler_policy_key"
ms.assetid: 6a7c42fe-9bc4-4a02-bebb-99fe9ef9817d
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe invalid_scheduler_policy_key
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção gerada quando uma chave inválida ou desconhecida é passado a um construtor do objeto de `SchedulerPolicy` , ou o método de `SetPolicyValue` de um objeto de `SchedulerPolicy` é passado a uma chave que deve ser modificada usando outros meios como o método de `SetConcurrencyLimits` .  
  
## Sintaxe  
  
```  
class invalid_scheduler_policy_key : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor invalid\_scheduler\_policy\_key::invalid\_scheduler\_policy\_key](../Topic/invalid_scheduler_policy_key::invalid_scheduler_policy_key%20Constructor.md)|Sobrecarregado.  Constrói um objeto `invalid_scheduler_policy_key`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `invalid_scheduler_policy_key`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe SchedulerPolicy](../../../parallel/concrt/reference/schedulerpolicy-class.md)   
 [Enumeração PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md)   
 [Método SchedulerPolicy::SetPolicyValue](../Topic/SchedulerPolicy::SetPolicyValue%20Method.md)   
 [Método SchedulerPolicy::SetConcurrencyLimits](../Topic/SchedulerPolicy::SetConcurrencyLimits%20Method.md)