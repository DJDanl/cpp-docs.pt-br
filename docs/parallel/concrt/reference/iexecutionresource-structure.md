---
title: "Estrutura IExecutionResource | Microsoft Docs"
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
  - "concrtrm/concurrency::IExecutionResource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura IExecutionResource"
ms.assetid: 6b27042b-b98c-4f7f-b831-566950af84cd
caps.latest.revision: 16
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura IExecutionResource
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Uma abstração para um thread de hardware.  
  
## Sintaxe  
  
```  
struct IExecutionResource;  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método IExecutionResource::CurrentSubscriptionLevel](../Topic/IExecutionResource::CurrentSubscriptionLevel%20Method.md)|Retorna o número de raízes virtuais ativadas de processador e os threads externos assinados associado atualmente com o thread de hardware subjacente esse recurso de execução representam.|  
|[Método IExecutionResource::GetExecutionResourceId](../Topic/IExecutionResource::GetExecutionResourceId%20Method.md)|Retorna um identificador exclusivo para o thread de hardware que esse recurso de execução representa.|  
|[Método IExecutionResource::GetNodeId](../Topic/IExecutionResource::GetNodeId%20Method.md)|Retorna um identificador exclusivo do nó de processador que esse recurso de execução pertence.|  
|[Método IExecutionResource::Remove](../Topic/IExecutionResource::Remove%20Method.md)|Retorna esse recurso de execução para o Gerenciador de Recursos.|  
  
## Comentários  
 Os recursos de execução autônomas do ou podem ser associados a raiz virtual do processador.  Um recurso de execução autônoma é criado quando um thread em seu aplicativo cria uma assinatura de thread.  Os métodos [ISchedulerProxy::SubscribeThread](../Topic/ISchedulerProxy::SubscribeCurrentThread%20Method.md) e [ISchedulerProxy::RequestInitialVirtualProcessors](../Topic/ISchedulerProxy::RequestInitialVirtualProcessors%20Method.md) criam assinaturas de thread, e retornam uma interface de `IExecutionResource` que representa a assinatura.  Criar uma assinatura de thread é uma maneira de informar o Gerenciador de Recursos que um determinado thread participará de trabalho em fila a um agendador, junto com as raiz que virtuais do processador o Gerenciador de Recursos atribui ao agendador.  O Gerenciador de Recursos usa as informações para evitar oversubscribing os threads de hardware onde possível.  
  
## Hierarquia de Herança  
 `IExecutionResource`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Estrutura IVirtualProcessorRoot](../../../parallel/concrt/reference/ivirtualprocessorroot-structure.md)   
 [Método ISchedulerProxy::SubscribeCurrentThread](../Topic/ISchedulerProxy::SubscribeCurrentThread%20Method.md)   
 [Método ISchedulerProxy::RequestInitialVirtualProcessors](../Topic/ISchedulerProxy::RequestInitialVirtualProcessors%20Method.md)