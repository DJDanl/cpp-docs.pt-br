---
title: "Classe task_canceled | Microsoft Docs"
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
  - "concrt/concurrency::task_canceled"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe task_canceled"
ms.assetid: c3f0b234-2cc1-435f-a48e-995f45b190be
caps.latest.revision: 11
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe task_canceled
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção acionada pela camada de tarefas de PPL para forçar o cancelamento da tarefa atual.  Também será lançada pelo método `get()` em [tarefa](../Topic/Task%20Class%20-%20Internal%20Members.md), para uma tarefa cancelada.  
  
## Sintaxe  
  
```  
class task_canceled : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor task\_canceled::task\_canceled](../Topic/task_canceled::task_canceled%20Constructor.md)|Sobrecarregado.  Constrói um objeto `task_canceled`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `task_canceled`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Método task::get](../Topic/task::get%20Method.md)   
 [Função cancel\_current\_task](../Topic/cancel_current_task%20Function.md)