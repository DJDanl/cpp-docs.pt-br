---
title: "Classe invalid_multiple_scheduling | Microsoft Docs"
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
  - "concrt/concurrency::invalid_multiple_scheduling"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe invalid_multiple_scheduling"
ms.assetid: e9a47cb7-a778-4df7-92b0-3752119fd4c7
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe invalid_multiple_scheduling
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção gerada quando um objeto de `task_handle` é agendado várias vezes usando o método de `run` de um objeto de `task_group` ou de `structured_task_group` sem uma chamada de intervenção os métodos de `wait` ou de `run_and_wait` .  
  
## Sintaxe  
  
```  
class invalid_multiple_scheduling : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor invalid\_multiple\_scheduling::invalid\_multiple\_scheduling](../Topic/invalid_multiple_scheduling::invalid_multiple_scheduling%20Constructor.md)|Sobrecarregado.  Constrói um objeto `invalid_multiple_scheduling`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `invalid_multiple_scheduling`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe task\_handle](../../../parallel/concrt/reference/task-handle-class.md)   
 [Classe task\_group](../Topic/task_group%20Class.md)   
 [Método task\_group::run](../Topic/task_group::run%20Method.md)   
 [Método task\_group::wait](../Topic/task_group::wait%20Method.md)   
 [Método task\_group::run\_and\_wait](../Topic/task_group::run_and_wait%20Method.md)   
 [Classe structured\_task\_group](../../../parallel/concrt/reference/structured-task-group-class.md)   
 [Método structured\_task\_group::run](../Topic/structured_task_group::run%20Method.md)   
 [Método structured\_task\_group::wait](../Topic/structured_task_group::wait%20Method.md)   
 [Método structured\_task\_group::run\_and\_wait](../Topic/structured_task_group::run_and_wait%20Method.md)