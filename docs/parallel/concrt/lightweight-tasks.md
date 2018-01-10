---
title: Tarefas leves | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: lightweight tasks
ms.assetid: b6dcfc7a-9fa9-4144-96a6-2845ea272017
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 010f5fd443271bec1d28b6760f0c17f4e17d803b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="lightweight-tasks"></a>Tarefas Leves
Este documento descreve a função de tarefas leves no tempo de execução de simultaneidade. Um *tarefa leve* é uma tarefa que você agendar diretamente de um `concurrency::Scheduler` ou `concurrency::ScheduleGroup` objeto. A função que você fornece a API do Windows é semelhante a uma tarefa leve [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453) função. Portanto, as tarefas leves são úteis quando você adaptar o código existente para usar a funcionalidade de agendamento de tempo de execução de simultaneidade. O tempo de execução de simultaneidade em si usa tarefas leves para agendar agentes assíncronos e enviar mensagens entre blocos de mensagens assíncronas.  
  
> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão e, portanto, não é necessário criá-lo em seu aplicativo. Como o Agendador de tarefas Ajuda a ajustar o desempenho de seus aplicativos, é recomendável que você inicie com o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você estiver novo no tempo de execução de simultaneidade.  
  
 Tarefas leves carregam menos sobrecarga de agentes assíncronos e grupos de tarefas. Por exemplo, o tempo de execução não informam quando uma tarefa simples termina. Além disso, o tempo de execução não catch ou manipular exceções que são geradas a partir de uma tarefa simples. Para obter mais informações sobre o tratamento de exceção e tarefas leves, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).  
  
 Para a maioria das tarefas, recomendamos que você usa a funcionalidade mais robusta, como grupos de tarefas e os algoritmos paralelos porque eles permitem que você mais facilmente invadir tarefas complexas os mais básicos. Para obter mais informações sobre grupos de tarefas, consulte [paralelismo de tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md). Para obter mais informações sobre os algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  
  
 Para criar uma tarefa simples, chame o [concurrency::ScheduleGroup::ScheduleTask](reference/schedulegroup-class.md#scheduletask), [concurrency::CurrentScheduler::ScheduleTask](reference/currentscheduler-class.md#scheduletask), ou [concurrency::Scheduler::ScheduleTask ](reference/scheduler-class.md#scheduletask) método. Para aguardar uma a conclusão da tarefa leve, aguarde até que o Agendador pai desligar ou usar um mecanismo de sincronização, como um [concurrency::event](../../parallel/concrt/reference/event-class.md) objeto.  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo que demonstra como adaptar o código existente para usar uma tarefa simples, consulte [passo a passo: adaptando um código existente para usar tarefas leves](../../parallel/concrt/walkthrough-adapting-existing-code-to-use-lightweight-tasks.md).  
  
## <a name="see-also"></a>Consulte também  
 [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Instruções passo a passo: adaptando um código existente para usar tarefas leves](../../parallel/concrt/walkthrough-adapting-existing-code-to-use-lightweight-tasks.md)

