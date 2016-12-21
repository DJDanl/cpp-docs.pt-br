---
title: "Estrutura IUMSThreadProxy | Microsoft Docs"
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
  - "concrtrm/concurrency::IUMSThreadProxy"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura IUMSThreadProxy"
ms.assetid: 61c69b7e-5c37-4048-bcb4-e75c536afd86
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura IUMSThreadProxy
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Uma abstração para um thread de execução.  Se você deseja que o agendador para ser concedido threads schedulable \(UMS\) de modo de usuário, defina o valor do elemento `SchedulerKind` de política do agendador a `UmsThreadDefault`, e implementa a interface de `IUMSScheduler` .  Os threads UMS só têm suporte em sistemas operacionais de 64 bits com o Windows 7 e versão posterior.  
  
## Sintaxe  
  
```  
struct IUMSThreadProxy : public IThreadProxy;  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método IUMSThreadProxy::EnterCriticalRegion](../Topic/IUMSThreadProxy::EnterCriticalRegion%20Method.md)|Chamado para inserir uma região crítico.  Quando dentro de uma região crítico, o agendador não observará as operações assíncronas de bloqueio que acontecem durante a região.  Isso significa que o agendador não reentered para falhas de página, suspensões de thread, chamadas de procedimento assíncronas \(APCs\) de kernel, e assim por diante, para UMS thread.|  
|[Método IUMSThreadProxy::EnterHyperCriticalRegion](../Topic/IUMSThreadProxy::EnterHyperCriticalRegion%20Method.md)|Chamado para inserir uma região hyper\- crítico.  Quando dentro de uma região hyper\- crítico, o agendador não observará nenhuma operação de bloqueio que acontecem durante a região.  Isso significa que o agendador não reentered bloqueando chamadas de função, as tentativas de bloqueio, falhas de aquisição do bloqueio de página, suspensões de thread, chamadas de procedimento assíncronas \(APCs\) de kernel, e assim por diante, para UMS thread.|  
|[Método IUMSThreadProxy::ExitCriticalRegion](../Topic/IUMSThreadProxy::ExitCriticalRegion%20Method.md)|Chamado para sair de uma região crítico.|  
|[Método IUMSThreadProxy::ExitHyperCriticalRegion](../Topic/IUMSThreadProxy::ExitHyperCriticalRegion%20Method.md)|Chamado para sair de uma região hyper\- crítico.|  
|[Método IUMSThreadProxy::GetCriticalRegionType](../Topic/IUMSThreadProxy::GetCriticalRegionType%20Method.md)|Retorna a qual tipo de região crítico o proxy do thread está no.  Como as regiões hyper\- críticos é um superconjunto de regiões críticos do, se o código inseriu uma região crítico e em uma região hyper\- crítico, `InsideHyperCriticalRegion` será retornado.|  
  
## Hierarquia de Herança  
 [IThreadProxy](../../../parallel/concrt/reference/ithreadproxy-structure.md)  
  
 `IUMSThreadProxy`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Estrutura IUMSScheduler](../../../parallel/concrt/reference/iumsscheduler-structure.md)   
 [Enumeração SchedulerType](../Topic/SchedulerType%20Enumeration.md)