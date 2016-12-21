---
title: "Estrutura IThreadProxy | Microsoft Docs"
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
  - "concrtrm/concurrency::IThreadProxy"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura IThreadProxy"
ms.assetid: feb89241-a555-4e61-ad48-40add54daeca
caps.latest.revision: 21
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura IThreadProxy
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Uma abstração para um thread de execução.  Dependendo da chave da política de `SchedulerType` do agendador você cria, o Gerenciador de Recursos conceder\-lhe\-á um proxy do thread que é voltado por um thread normal do Win32 ou por um thread schedulable \(UMS\) do modo de usuário.  Os threads UMS têm suporte em sistemas operacionais de 64 bits com o Windows 7 e versão posterior.  
  
## Sintaxe  
  
```  
struct IThreadProxy;  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método IThreadProxy::GetId](../Topic/IThreadProxy::GetId%20Method.md)|Retorna um identificador exclusivo para o proxy de thread.|  
|[Método IThreadProxy::SwitchOut](../Topic/IThreadProxy::SwitchOut%20Method.md)|Desassocia o contexto da raiz virtual subjacente do processador.|  
|[Método IThreadProxy::SwitchTo](../Topic/IThreadProxy::SwitchTo%20Method.md)|Executa uma opção cooperativo do contexto atualmente em execução a um diferente.|  
|[Método IThreadProxy::YieldToSystem](../Topic/IThreadProxy::YieldToSystem%20Method.md)|Faz com que o thread de chamada à execução de desempenho para outro thread que ele fique pronto para ser executado no processador atual.  O sistema operacional seleciona o thread seguir a ser executado.|  
  
## Comentários  
 Os proxies de thread são acoplados aos contextos de execução representados pela interface `IExecutionContext` como expedir meio do trabalho.  
  
## Hierarquia de Herança  
 `IThreadProxy`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Estrutura IExecutionContext](../Topic/IExecutionContext%20Structure.md)   
 [Estrutura IScheduler](../../../parallel/concrt/reference/ischeduler-structure.md)   
 [Estrutura IVirtualProcessorRoot](../../../parallel/concrt/reference/ivirtualprocessorroot-structure.md)