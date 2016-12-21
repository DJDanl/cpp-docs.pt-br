---
title: "Classe task_completion_event | Microsoft Docs"
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
  - "ppltasks/concurrency::task_completion_event"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe task_completion_event"
ms.assetid: fb19ed98-f245-48dc-9ba5-487ba879b28a
caps.latest.revision: 11
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe task_completion_event
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe `task_completion_event` permite que você atrase a execução de uma tarefa até que uma condição seja satisfeita, ou inicie uma tarefa em resposta a um evento externo.  
  
## Sintaxe  
  
```  
template<  
   typename _ResultType  
>  
class task_completion_event;  
  
template<>  
class task_completion_event<void>;  
```  
  
#### Parâmetros  
 `_ResultType`  
 O tipo de resultado desta tarefa de `task_completion_event`.  
  
 `T`  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor task\_completion\_event::task\_completion\_event](../Topic/task_completion_event::task_completion_event%20Constructor.md)|Constrói um objeto `task_completion_event`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método task\_completion\_event::set](../Topic/task_completion_event::set%20Method.md)|Sobrecarregado.  Defina o evento de conclusão de tarefas.|  
|[Método task\_completion\_event::set\_exception](../Topic/task_completion_event::set_exception%20Method.md)|Sobrecarregado.  Propaga uma exceção a todas as tarefas associadas a esse evento.|  
  
## Comentários  
 Use uma tarefa criada de um evento de conclusão de tarefa quando seu cenário exigir que você crie uma tarefa que será concluída e, portanto, terá suas continuações agendadas para execução, em algum ponto no futuro.  O `task_completion_event` deve ter o mesmo tipo que a tarefa que você cria, e chamar o método definido no evento de conclusão da tarefa com um valor desse tipo fará com que a tarefa associada seja concluída, e fornecerá esse valor como resultado às suas continuações.  
  
 Se o evento de conclusão da tarefa nunca é sinalizado, todas as tarefas criadas a partir dele serão canceladas quando ele for destruído.  
  
 `task_completion_event` se comporta como um ponteiro inteligente e deve ser passado por um valor.  
  
## Hierarquia de Herança  
 `task_completion_event`  
  
## Requisitos  
 **Cabeçalho:** ppltasks.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [task Class](http://msdn.microsoft.com/pt-br/5389e8a5-5038-40b6-844a-55e9b58ad35f)