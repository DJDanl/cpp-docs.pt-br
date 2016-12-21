---
title: "Estrutura IUMSUnblockNotification | Microsoft Docs"
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
  - "concrtrm/concurrency::IUMSUnblockNotification"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura IUMSUnblockNotification"
ms.assetid: eaca9529-c1cc-472b-8ec6-722a1ff0fa2a
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura IUMSUnblockNotification
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Representa uma notificação do Gerenciador de Recursos que um proxy do thread que bloqueasse e irá disparar um retorno ao agendador designado contexto agendando desbloqueou e está pronto para ser agendada.  Essa interface não é válido quando o contexto associado de execução do proxy de thread, retornado pelo método de `GetContext` , é reprogramado.  
  
## Sintaxe  
  
```  
struct IUMSUnblockNotification;  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método IUMSUnblockNotification::GetContext](../Topic/IUMSUnblockNotification::GetContext%20Method.md)|Retorna a interface de `IExecutionContext` para o contexto de execução associado ao proxy do thread que tenha desbloqueado.  Uma vez que esse método retorna subjacente e o contexto de execução esteve reprogramado através de uma chamada ao método de `IThreadProxy::SwitchTo` , essa interface não é mais válida.|  
|[Método IUMSUnblockNotification::GetNextUnblockNotification](../Topic/IUMSUnblockNotification::GetNextUnblockNotification%20Method.md)|Retorna a interface de `IUMSUnblockNotification` seguir na cadeia retornada do método `IUMSCompletionList::GetUnblockNotifications`.|  
  
## Hierarquia de Herança  
 `IUMSUnblockNotification`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Estrutura IUMSScheduler](../../../parallel/concrt/reference/iumsscheduler-structure.md)   
 [Estrutura IUMSCompletionList](../../../parallel/concrt/reference/iumscompletionlist-structure.md)