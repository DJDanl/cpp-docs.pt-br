---
title: "Estrutura ISchedulerProxy | Microsoft Docs"
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
  - "concrtrm/concurrency::ISchedulerProxy"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura ISchedulerProxy"
ms.assetid: af416973-7a1c-4c30-aa3b-4161c2aaea54
caps.latest.revision: 18
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura ISchedulerProxy
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A interface pelos agendadores que se comunicam com o Gerenciador de Recursos de tempo de execução de simultaneidade para negociar a atribuição de recursos.  
  
## Sintaxe  
  
```  
struct ISchedulerProxy;  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método ISchedulerProxy::BindContext](../Topic/ISchedulerProxy::BindContext%20Method.md)|Associa um contexto de execução com um proxy de thread, se não for associada ao.|  
|[Método ISchedulerProxy::CreateOversubscriber](../Topic/ISchedulerProxy::CreateOversubscriber%20Method.md)|Cria uma nova raiz virtual de processador no thread de hardware associado a um recurso existente de execução.|  
|[Método ISchedulerProxy::RequestInitialVirtualProcessors](../Topic/ISchedulerProxy::RequestInitialVirtualProcessors%20Method.md)|Solicita uma alocação inicial de raízes virtuais do processador.  Cada raiz virtual do processador representa a capacidade de executar um thread que pode executar o trabalho para o agendador.|  
|[Método ISchedulerProxy::Shutdown](../Topic/ISchedulerProxy::Shutdown%20Method.md)|Notifica o Gerenciador de Recursos do agendador está sendo fechado.  Isso fará com que o Gerenciador de Recursos recupere imediatamente todos os recursos concedidos ao agendador.|  
|[Método ISchedulerProxy::SubscribeCurrentThread](../Topic/ISchedulerProxy::SubscribeCurrentThread%20Method.md)|Registra o thread atual com o Gerenciador de Recursos, associando o com este agendador.|  
|[Método ISchedulerProxy::UnbindContext](../Topic/ISchedulerProxy::UnbindContext%20Method.md)|Desassocia um proxy do thread de contexto de execução especificado pelo parâmetro de `pContext` e o retorna ao pool livre de fábrica de proxy de thread.  Esse método pode ser chamado somente um contexto de execução que é associado pelo método de [ISchedulerProxy::BindContext](../Topic/ISchedulerProxy::BindContext%20Method.md) e não é iniciado ainda ser por meio do parâmetro de `pContext` de uma chamada de método de [IThreadProxy::SwitchTo](../Topic/IThreadProxy::SwitchTo%20Method.md) .|  
  
## Comentários  
 O Gerenciador de Recursos fornece uma interface de `ISchedulerProxy` a cada agendador que se registrar com ela que usa o método de [IResourceManager::RegisterScheduler](../Topic/IResourceManager::RegisterScheduler%20Method.md) .  
  
## Hierarquia de Herança  
 `ISchedulerProxy`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Estrutura IScheduler](../../../parallel/concrt/reference/ischeduler-structure.md)   
 [Estrutura IThreadProxy](../../../parallel/concrt/reference/ithreadproxy-structure.md)   
 [Estrutura IVirtualProcessorRoot](../../../parallel/concrt/reference/ivirtualprocessorroot-structure.md)   
 [Estrutura IResourceManager](../../../parallel/concrt/reference/iresourcemanager-structure.md)