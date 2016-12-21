---
title: "Classe nested_scheduler_missing_detach | Microsoft Docs"
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
  - "concrt/concurrency::nested_scheduler_missing_detach"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe nested_scheduler_missing_detach"
ms.assetid: 65d3f277-6d43-4160-97ef-caf8b26c1641
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe nested_scheduler_missing_detach
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção gerada quando o tempo de execução de simultaneidade detectar que você negligenciou chamar o método de `CurrentScheduler::Detach` em um contexto que anexa a um segundo agendador que usa o método de `Attach` do objeto de `Scheduler` .  
  
## Sintaxe  
  
```  
class nested_scheduler_missing_detach : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor nested\_scheduler\_missing\_detach::nested\_scheduler\_missing\_detach](../Topic/nested_scheduler_missing_detach::nested_scheduler_missing_detach%20Constructor.md)|Sobrecarregado.  Constrói um objeto `nested_scheduler_missing_detach`.|  
  
## Comentários  
 Esta exceção é gerada somente quando você aninha dentro de um outro agendador chamando o método de `Attach` de um objeto de `Scheduler` em um contexto por que já esteja anexado ou pertencente a outro agendador.  O tempo de execução de simultaneidade gerará esta exceção quando oportunista pode detectar o cenário como um auxílio para localizar o problema.  Cada instância não negligência de chamar o método de `CurrentScheduler::Detach` é garantida para gerar essa exceção.  
  
## Hierarquia de Herança  
 `exception`  
  
 `nested_scheduler_missing_detach`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe Scheduler](../../../parallel/concrt/reference/scheduler-class.md)   
 [Método CurrentScheduler::Detach](../Topic/CurrentScheduler::Detach%20Method.md)   
 [Método Scheduler::Attach](../Topic/Scheduler::Attach%20Method.md)