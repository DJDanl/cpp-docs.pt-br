---
title: "Classe missing_wait | Microsoft Docs"
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
  - "concrt/concurrency::missing_wait"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe missing_wait"
ms.assetid: ff981875-bd43-47e3-806f-b03c9f418b18
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe missing_wait
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção gerada quando há ainda tarefas agendadas para um objeto de `task_group` ou de `structured_task_group` no momento em que o destruidor do objeto seja executado.  Essa exceção será gerada se o destruidor nunca é atingido devido a uma pilha que desenrola como resultado de uma exceção.  
  
## Sintaxe  
  
```  
class missing_wait : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor missing\_wait::missing\_wait](../Topic/missing_wait::missing_wait%20Constructor.md)|Sobrecarregado.  Constrói um objeto `missing_wait`.|  
  
## Comentários  
 Fluxo ausente de exceção, você é responsável para chamar `wait` ou o método de `run_and_wait` de um objeto de `task_group` ou de `structured_task_group` antes de permitir esse objeto a destruct.  O tempo de execução gerará esta exceção como uma indicação de que você esqueceu chamar o método de `wait` ou de `run_and_wait` .  
  
## Hierarquia de Herança  
 `exception`  
  
 `missing_wait`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe task\_group](../Topic/task_group%20Class.md)   
 [Método task\_group::wait](../Topic/task_group::wait%20Method.md)   
 [Método task\_group::run\_and\_wait](../Topic/task_group::run_and_wait%20Method.md)   
 [Classe structured\_task\_group](../../../parallel/concrt/reference/structured-task-group-class.md)   
 [Método structured\_task\_group::wait](../Topic/structured_task_group::wait%20Method.md)   
 [Método structured\_task\_group::run\_and\_wait](../Topic/structured_task_group::run_and_wait%20Method.md)