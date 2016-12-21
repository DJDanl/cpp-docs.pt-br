---
title: "Estrutura IScheduler | Microsoft Docs"
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
  - "concrtrm/concurrency::IScheduler"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura IScheduler"
ms.assetid: 471de85a-2b1a-4b6d-ab81-2eff2737161e
caps.latest.revision: 18
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura IScheduler
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Uma interface para uma abstração de um agendador de trabalho.  O Gerenciador de Recursos de tempo de execução de simultaneidade usa essa interface para se comunicar com os agendadores de trabalho.  
  
## Sintaxe  
  
```  
struct IScheduler;  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método IScheduler::AddVirtualProcessors](../Topic/IScheduler::AddVirtualProcessors%20Method.md)|Fornece um agendador com um conjunto de raízes virtuais do processador para seu uso.  Cada interface de `IVirtualProcessorRoot` representa o direito da execução de um único thread que pode executar o trabalho em nome do agendador.|  
|[Método IScheduler::GetId](../Topic/IScheduler::GetId%20Method.md)|Retorna um identificador exclusivo do agendador.|  
|[Método IScheduler::GetPolicy](../Topic/IScheduler::GetPolicy%20Method.md)|Retorna uma cópia de política do agendador.  Para obter mais informações sobre as políticas de agendador, consulte [SchedulerPolicy](../../../parallel/concrt/reference/schedulerpolicy-class.md).|  
|[Método IScheduler::NotifyResourcesExternallyBusy](../Topic/IScheduler::NotifyResourcesExternallyBusy%20Method.md)|Notifica este agendador que os threads de hardware representados pelo conjunto de raízes virtuais do processador na matriz `ppVirtualProcessorRoots` agora estão sendo usados por outros agendadores.|  
|[Método IScheduler::NotifyResourcesExternallyIdle](../Topic/IScheduler::NotifyResourcesExternallyIdle%20Method.md)|Notifica este agendador que os threads de hardware representados pelo conjunto de raízes virtuais do processador na matriz `ppVirtualProcessorRoots` não estão sendo usados por outros agendadores.|  
|[Método IScheduler::RemoveVirtualProcessors](../Topic/IScheduler::RemoveVirtualProcessors%20Method.md)|Inicia a remoção de raízes virtuais do processador que foram atribuídas anteriormente neste agendador.|  
|[Método IScheduler::Statistics](../Topic/IScheduler::Statistics%20Method.md)|Fornece informações relacionadas à chegada e as taxas de conclusão da tarefa, e o comprimento da fila para um agendador.|  
  
## Comentários  
 Se você estiver implementando um agendador personalizado que se comunicam com o Gerenciador de Recursos, você deve fornecer uma implementação da interface de `IScheduler` .  Essa interface é uma extremidade de um canal bidirecional de comunicação entre um agendador e o Gerenciador de Recursos.  A outra extremidade é representada por interfaces de `IResourceManager` e de `ISchedulerProxy` que são implementadas pelo Gerenciador de Recursos.  
  
## Hierarquia de Herança  
 `IScheduler`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Enumeração PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md)   
 [Classe SchedulerPolicy](../../../parallel/concrt/reference/schedulerpolicy-class.md)   
 [Estrutura IExecutionContext](../Topic/IExecutionContext%20Structure.md)   
 [Estrutura IThreadProxy](../../../parallel/concrt/reference/ithreadproxy-structure.md)   
 [Estrutura IVirtualProcessorRoot](../../../parallel/concrt/reference/ivirtualprocessorroot-structure.md)   
 [Estrutura IResourceManager](../../../parallel/concrt/reference/iresourcemanager-structure.md)