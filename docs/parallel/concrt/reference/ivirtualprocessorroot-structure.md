---
title: "Estrutura IVirtualProcessorRoot | Microsoft Docs"
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
  - "concrtrm/concurrency::IVirtualProcessorRoot"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura IVirtualProcessorRoot"
ms.assetid: 5ef371b8-9e4f-4fef-bb0d-49099693dd2b
caps.latest.revision: 18
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura IVirtualProcessorRoot
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Uma abstração para um thread de hardware em que um proxy de thread pode ser executado.  
  
## Sintaxe  
  
```  
struct IVirtualProcessorRoot : public IExecutionResource;  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método IVirtualProcessorRoot::Activate](../Topic/IVirtualProcessorRoot::Activate%20Method.md)|Faz com que o proxy de thread associado à interface `pContext` do contexto de execução no início que executa nessa raiz virtual do processador.|  
|[Método IVirtualProcessorRoot::Deactivate](../Topic/IVirtualProcessorRoot::Deactivate%20Method.md)|Faz com que o proxy do thread que executa atualmente nessa raiz virtual do processador para parar de expedir o contexto de execução.  O proxy do thread continuará executar em uma chamada para o método de `Activate` .|  
|[Método IVirtualProcessorRoot::EnsureAllTasksVisible](../Topic/IVirtualProcessorRoot::EnsureAllTasksVisible%20Method.md)|Faz com que os dados armazenados na hierarquia de memória de processadores individuais para ficar visível para todos os processadores no sistema.  Verifique se ao redor completa de memória seja executada em todos os processadores antes que o método retorna.|  
|[Método IVirtualProcessorRoot::GetId](../Topic/IVirtualProcessorRoot::GetId%20Method.md)|Retorna um identificador exclusivo para a raiz virtual do processador.|  
  
## Comentários  
 Cada raiz virtual do processador tem um recurso de execução associado.  A interface de `IVirtualProcessorRoot` herda da interface de [IExecutionResource](../../../parallel/concrt/reference/iexecutionresource-structure.md) .  Várias raiz virtual de processadores podem corresponder ao mesmo thread de hardware subjacente.  
  
 O Gerenciador de Recursos concede raízes virtuais do processador a agendadores em resposta a solicitações de recursos.  Um agendador pode usar uma raiz virtual do processador para executar o trabalho ativando o com um contexto de execução.  
  
## Hierarquia de Herança  
 [IExecutionResource](../../../parallel/concrt/reference/iexecutionresource-structure.md)  
  
 `IVirtualProcessorRoot`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)