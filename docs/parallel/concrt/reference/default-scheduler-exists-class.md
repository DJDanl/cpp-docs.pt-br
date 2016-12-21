---
title: "Classe default_scheduler_exists | Microsoft Docs"
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
  - "concrt/concurrency::default_scheduler_exists"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe default_scheduler_exists"
ms.assetid: f6e575e2-4e0f-455a-9e06-54f462ce0c1c
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe default_scheduler_exists
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção gerada quando o método de `Scheduler::SetDefaultSchedulerPolicy` é chamado quando um agendador padrão já existe no processo.  
  
## Sintaxe  
  
```  
class default_scheduler_exists : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor default\_scheduler\_exists::default\_scheduler\_exists](../Topic/default_scheduler_exists::default_scheduler_exists%20Constructor.md)|Sobrecarregado.  Constrói um objeto `default_scheduler_exists`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `default_scheduler_exists`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Método Scheduler::SetDefaultSchedulerPolicy](../Topic/Scheduler::SetDefaultSchedulerPolicy%20Method.md)