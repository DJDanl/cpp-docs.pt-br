---
title: "Classe SchedulerPolicy | Microsoft Docs"
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
  - "concrt/concurrency::SchedulerPolicy"
  - "concrtrm/concurrency::SchedulerPolicy"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe SchedulerPolicy"
ms.assetid: bcebf51a-65f8-45a3-809b-d1ff93527dc4
caps.latest.revision: 22
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe SchedulerPolicy
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe `SchedulerPolicy` contém um conjunto de pares de chave\/valor, um para cada elemento de política, que controlam o comportamento de uma instância do agendador.  
  
## Sintaxe  
  
```  
class SchedulerPolicy;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor SchedulerPolicy::SchedulerPolicy](../Topic/SchedulerPolicy::SchedulerPolicy%20Constructor.md)|Sobrecarregado.  Constrói uma nova política de agendador e a preenche com valores para [chaves de política](../Topic/PolicyElementKey%20Enumeration.md) suportadas por agendadores de tempo de execução de simultaneidade e pelo Gerenciador de Recursos.|  
|[Destruidor SchedulerPolicy::~SchedulerPolicy](../Topic/SchedulerPolicy::~SchedulerPolicy%20Destructor.md)|Destrói uma política de agendador.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método SchedulerPolicy::GetPolicyValue](../Topic/SchedulerPolicy::GetPolicyValue%20Method.md)|Recupera o valor da chave de política fornecida como o parâmetro `_Key`.|  
|[Método SchedulerPolicy::SetConcurrencyLimits](../Topic/SchedulerPolicy::SetConcurrencyLimits%20Method.md)|Define simultaneamente as políticas de `MinConcurrency` e `MaxConcurrency` no objeto `SchedulerPolicy`.|  
|[Método SchedulerPolicy::SetPolicyValue](../Topic/SchedulerPolicy::SetPolicyValue%20Method.md)|Defina o valor da chave de política fornecida como o parâmetro `_Key` e retorna o valor antigo.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador SchedulerPolicy::operator\=](../Topic/SchedulerPolicy::operator=%20Operator.md)|Atribui a política de agendador de outra política de agendador.|  
  
## Comentários  
 Para obter mais informações sobre as políticas que podem ser controladas usando a classe de `SchedulerPolicy`, consulte [Enumeração PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md).  
  
## Hierarquia de Herança  
 `SchedulerPolicy`  
  
## Requisitos  
 **Cabeçalho:** concrt.h, concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Enumeração PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md)   
 [Classe CurrentScheduler](../Topic/CurrentScheduler%20Class.md)   
 [Classe Scheduler](../../../parallel/concrt/reference/scheduler-class.md)   
 [Agendador de Tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)