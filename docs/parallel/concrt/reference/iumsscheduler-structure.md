---
title: "Estrutura IUMSScheduler | Microsoft Docs"
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
  - "concrtrm/concurrency::IUMSScheduler"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "estrutura IUMSScheduler"
ms.assetid: 3a500225-4e02-4849-bb56-d744865f5870
caps.latest.revision: 18
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura IUMSScheduler
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Uma interface para uma abstração de um agendador de trabalho que deseja o Gerenciador de Recursos de tempo de execução de simultaneidade para se entregar o modo de usuário \(UMS\) schedulable thread.  O Gerenciador de Recursos usa essa interface para se comunicar com os agendadores de thread UMS.  A interface de `IUMSScheduler` herda da interface de `IScheduler` .  
  
## Sintaxe  
  
```  
struct IUMSScheduler : public IScheduler;  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método IUMSScheduler::SetCompletionList](../Topic/IUMSScheduler::SetCompletionList%20Method.md)|Atribui uma interface de `IUMSCompletionList` a um agendador de thread UMS.|  
  
## Comentários  
 Se você estiver implementando um agendador personalizado que se comunicam com o Gerenciador de Recursos, e você quiser que os threads UMS a serem passados ao agendador em vez de threads comuns do Win32, você deve fornecer uma implementação da interface de `IUMSScheduler` .  Além disso, você deve definir o valor de política para a chave `SchedulerKind` de política do agendador para ser `UmsThreadDefault`.  Se a política especifica os UMS thread, a interface de `IScheduler` que é passado como um parâmetro para o método de [IResourceManager::RegisterScheduler](../Topic/IResourceManager::RegisterScheduler%20Method.md) deve ser uma interface de `IUMSScheduler` .  
  
 O Gerenciador de Recursos pode entregar\-lhe threads UMS somente em sistemas operacionais que têm o recurso UMS. sistemas operacionais de 64 bits com versão Windows 7 e threads mais altos UMS de suporte.  Se você criar uma política do agendador com a chave de `SchedulerKind` ao valor `UmsThreadDefault` e plataforma subjacente não oferecer suporte a UMS, o valor da chave de `SchedulerKind` nessa política será alterado para o valor `ThreadScheduler`.  Você sempre deve ler a parte desse valor de política antes de esperar receber threads UMS.  
  
 A interface de `IUMSScheduler` é uma extremidade de um canal bidirecional de comunicação entre um agendador e o Gerenciador de Recursos.  A outra extremidade é representada por `IResourceManager` e `ISchedulerProxy` interfaces, que são implementados pelo Gerenciador de Recursos.  
  
## Hierarquia de Herança  
 [IScheduler](../../../parallel/concrt/reference/ischeduler-structure.md)  
  
 `IUMSScheduler`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Enumeração PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md)   
 [Estrutura IScheduler](../../../parallel/concrt/reference/ischeduler-structure.md)   
 [Estrutura IUMSCompletionList](../../../parallel/concrt/reference/iumscompletionlist-structure.md)   
 [Estrutura IResourceManager](../../../parallel/concrt/reference/iresourcemanager-structure.md)