---
title: "Classe improper_scheduler_attach | Microsoft Docs"
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
  - "concrt/concurrency::improper_scheduler_attach"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe improper_scheduler_attach"
ms.assetid: 5a76da0a-091b-4748-8f62-b3a28f674f9e
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe improper_scheduler_attach
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção gerada quando o método de `Attach` é chamado em um objeto de `Scheduler` que seja anexado no contexto atual.  
  
## Sintaxe  
  
```  
class improper_scheduler_attach : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor improper\_scheduler\_attach::improper\_scheduler\_attach](../Topic/improper_scheduler_attach::improper_scheduler_attach%20Constructor.md)|Sobrecarregado.  Constrói um objeto `improper_scheduler_attach`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `improper_scheduler_attach`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe Scheduler](../../../parallel/concrt/reference/scheduler-class.md)   
 [Método Scheduler::Attach](../Topic/Scheduler::Attach%20Method.md)