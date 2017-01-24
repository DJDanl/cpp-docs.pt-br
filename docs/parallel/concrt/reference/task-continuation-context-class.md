---
title: "Classe task_continuation_context | Microsoft Docs"
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
  - "ppltasks/concurrency::task_continuation_context"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe task_continuation_context"
ms.assetid: 1fb5a76a-3682-45c2-a615-8b6b527741f0
caps.latest.revision: 15
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe task_continuation_context
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

O `task_continuation_context` classe permite que você especifique onde você deseja uma continuação para ser executado. Só é útil para usar essa classe em um aplicativo da Windows Store. Para aplicativos da Windows Store, o contexto de execução da continuação da tarefa é determinado pelo tempo de execução e não é configurável.  
  
## Sintaxe  
  
```  
class task_continuation_context : public details::_ContextCallback;  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método task\_continuation\_context::get\_current\_winrt\_context](../Topic/task_continuation_context::get_current_winrt_context%20Method.md)|Retorna um objeto de contexto de continuação da tarefa que representa o contexto de thread atual do winrt.|  
|[Método task\_continuation\_context::use\_arbitrary](../Topic/task_continuation_context::use_arbitrary%20Method.md)|Cria um contexto de continuação da tarefa que permite que o tempo de execução escolher o contexto de execução para uma continuação.|  
|[Método task\_continuation\_context::use\_current](../Topic/task_continuation_context::use_current%20Method.md)|Retorna um objeto de contexto de continuação da tarefa que representa o contexto de execução atual.|  
|[Método task\_continuation\_context::use\_default](../Topic/task_continuation_context::use_default%20Method.md)|Cria o contexto de continuação de tarefa padrão.|  
|[Método task\_continuation\_context::use\_synchronous\_execution](../Topic/task_continuation_context::use_synchronous_execution%20Method.md)|Retorna um objeto de contexto de continuação da tarefa que representa o contexto de execução síncrona.|  
  
## Hierarquia de herança  
 `_ContextCallback`  
  
 `task_continuation_context`  
  
## Requisitos  
 **Cabeçalho:** ppltasks.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe Task](http://msdn.microsoft.com/pt-br/5389e8a5-5038-40b6-844a-55e9b58ad35f)