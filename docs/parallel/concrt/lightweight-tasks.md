---
title: Tarefas leves | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- lightweight tasks
ms.assetid: b6dcfc7a-9fa9-4144-96a6-2845ea272017
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d602f83cfe2da6bc1506e07720d3ef021ebce04a
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33687407"
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

