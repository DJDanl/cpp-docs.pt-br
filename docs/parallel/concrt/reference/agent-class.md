---
title: "Classe agente | Microsoft Docs"
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
  - "agents/concurrency::agent"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de agente"
ms.assetid: 1b09e3d2-5e37-4966-b016-907ef1512456
caps.latest.revision: 20
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe agente
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Uma classe deve ser usada como uma classe base para todos os agentes independentes. Ele é usado para ocultar o estado dos outros agentes e interagir com a transmissão de mensagens.  
  
## Sintaxe  
  
```  
class agent;  
```  
  
## Membros  
  
### Construtores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor agent::agent](../Topic/agent::agent%20Constructor.md)|Sobrecarregado. Constrói um agente.|  
|[Destruidor agent::~agent](../Topic/agent::~agent%20Destructor.md)|Destrói o agente.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método agent::cancel](../Topic/agent::cancel%20Method.md)|Move um agente da `agent_created` ou `agent_runnable` estados a `agent_canceled` estado.|  
|[Método agent::start](../Topic/agent::start%20Method.md)|Move um agente do `agent_created` estado de `agent_runnable` de estado e agenda para execução.|  
|[Método agent::status](../Topic/agent::status%20Method.md)|Uma fonte síncrona de informações de status do agente.|  
|[Método agent::status\_port](../Topic/agent::status_port%20Method.md)|Uma fonte assíncrona das informações de status do agente.|  
|[Método agent::wait](../Topic/agent::wait%20Method.md)|Espera por um agente concluir a tarefa.|  
|[Método agent::wait\_for\_all](../Topic/agent::wait_for_all%20Method.md)|Aguarda até que todos os agentes especificados para concluir suas tarefas.|  
|[Método agent::wait\_for\_one](../Topic/agent::wait_for_one%20Method.md)|Espera por qualquer um dos agentes para concluir a tarefa especificados.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método agent::done](../Topic/agent::done%20Method.md)|Move um agente para o `agent_done` estado, indicando que o agente foi concluído.|  
|[Método agent::run](../Topic/agent::run%20Method.md)|Representa a tarefa principal de um agente.`run` deve ser substituído em uma classe derivada e especifica que o agente deve fazer depois que ele foi iniciado.|  
  
## Comentários  
 Para obter mais informações, consulte [Agentes assíncronos](../../../parallel/concrt/asynchronous-agents.md).  
  
## Hierarquia de herança  
 `agent`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)