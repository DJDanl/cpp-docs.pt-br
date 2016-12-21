---
title: "Tarefas leves | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tarefas leves"
ms.assetid: b6dcfc7a-9fa9-4144-96a6-2845ea272017
caps.latest.revision: 7
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tarefas leves
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento descreve a função de tarefas de peso leve em tempo de execução de simultaneidade.  *Uma tarefa de peso leve* é uma tarefa que você agende diretamente de um objeto de `concurrency::Scheduler` ou de `concurrency::ScheduleGroup` .  Uma tarefa de peso leve é semelhante à função que você fornece a API do windows [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453) a função.  Em virtude disso, as tarefas de peso leve são úteis quando se adapta o código existente para usar a funcionalidade de programação de tempo de execução de simultaneidade.  O tempo de execução próprio de simultaneidade usa tarefas de peso leve programar agentes assíncronas e enviar mensagens entre blocos assíncronas da mensagem.  
  
> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão, e em virtude disso não é necessário criar um relatório em seu aplicativo.  Como o agendador de tarefas o ajuda a ajustar o desempenho dos aplicativos, recomendamos que você comece com [Biblioteca de padrões paralelos \(PPL\)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você é novato em tempo de execução de simultaneidade.  
  
 As tarefas de peso leve levam menos sobrecarga de agentes assíncronas e grupos de trabalho.  Por exemplo, o tempo de execução não o informa quando uma tarefa superficial é concluída.  Além disso, o tempo de execução não captura nem controla as exceções emitidas de uma tarefa de peso leve.  Para obter mais informações sobre a manipulação de exceções e tarefas de peso leve, consulte [Tratamento de Exceção](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md).  
  
 Para a maioria das tarefas, recomendamos que você use uma funcionalidade mais robusta como grupos de trabalho e algoritmos paralelos porque permitem mais facilmente interromper tarefas mais complexas em básicas.  Para obter mais informações sobre grupos de trabalho, consulte [Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md).  Para obter mais informações sobre algoritmos paralelos, consulte [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md).  
  
 Para criar uma tarefa de peso leve, chame [concurrency::ScheduleGroup::ScheduleTask](../Topic/ScheduleGroup::ScheduleTask%20Method.md), [concurrency::CurrentScheduler::ScheduleTask](../Topic/CurrentScheduler::ScheduleTask%20Method.md), ou o método de [concurrency::Scheduler::ScheduleTask](../Topic/Scheduler::ScheduleTask%20Method.md) .  Para esperar uma tarefa de peso leve concluir, aguarda o agendador pai para fechar ou usar um mecanismo de sincronização como um objeto de [concurrency::event](../Topic/event%20Class.md) .  
  
## Exemplo  
 Para obter um exemplo que demonstra como adaptar o código existente para usar uma tarefa superficial, considere [Instruções passo a passo: adaptando um código existente para usar tarefas leves](../Topic/Walkthrough:%20Adapting%20Existing%20Code%20to%20Use%20Lightweight%20Tasks.md).  
  
## Consulte também  
 [Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Instruções passo a passo: adaptando um código existente para usar tarefas leves](../Topic/Walkthrough:%20Adapting%20Existing%20Code%20to%20Use%20Lightweight%20Tasks.md)