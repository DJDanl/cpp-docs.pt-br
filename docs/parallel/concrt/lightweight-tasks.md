---
title: Tarefas Leves
ms.date: 11/04/2016
helpviewer_keywords:
- lightweight tasks
ms.assetid: b6dcfc7a-9fa9-4144-96a6-2845ea272017
ms.openlocfilehash: 7b798312c9660e51338d51a97a052ad4e5bdca6b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69512181"
---
# <a name="lightweight-tasks"></a>Tarefas Leves

Este documento descreve a função de tarefas leves no Tempo de Execução de Simultaneidade. Uma *tarefa leve* é uma tarefa que você agenda diretamente de um `concurrency::Scheduler` objeto `concurrency::ScheduleGroup` ou. Uma tarefa leve é semelhante à função que você fornece à função [CreateThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread) da API do Windows. Portanto, tarefas leves são úteis quando você adapta o código existente para usar a funcionalidade de agendamento do Tempo de Execução de Simultaneidade. O Tempo de Execução de Simultaneidade em si usa tarefas leves para agendar agentes assíncronos e enviar mensagens entre blocos de mensagens assíncronas.

> [!TIP]
>  O Tempo de Execução de Simultaneidade fornece um agendador padrão e, portanto, não é necessário criar um em seu aplicativo. Como o Agendador de Tarefas ajuda você a ajustar o desempenho de seus aplicativos, recomendamos que você comece com a [ppl (biblioteca de padrões paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou a [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você for novo no tempo de execução de simultaneidade.

As tarefas leves trazem menos sobrecarga do que os agentes assíncronos e grupos de tarefas. Por exemplo, o tempo de execução não informa quando uma tarefa leve é concluída. Além disso, o tempo de execução não detecta nem manipula exceções que são geradas de uma tarefa leve. Para obter mais informações sobre o tratamento de exceção e tarefas leves, consulte [manipulação de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

Para a maioria das tarefas, recomendamos que você use uma funcionalidade mais robusta, como grupos de tarefas e algoritmos paralelos, pois eles permitem que você divida tarefas complexas com mais facilidade em outras básicas. Para obter mais informações sobre grupos de tarefas, consulte [paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md). Para obter mais informações sobre algoritmos paralelos, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

Para criar uma tarefa leve, chame o método [Concurrency:: Schedule](reference/schedulegroup-class.md#scheduletask):: ScheduleTask, [Concurrency:: CurrentScheduler:: ScheduleTask](reference/currentscheduler-class.md#scheduletask)ou [Concurrency:: Scheduler:: ScheduleTask](reference/scheduler-class.md#scheduletask) . Para aguardar a conclusão de uma tarefa leve, aguarde até que o Agendador pai seja desligado ou use um mecanismo de sincronização, como um objeto de [simultaneidade:: Event](../../parallel/concrt/reference/event-class.md) .

## <a name="example"></a>Exemplo

Para obter um exemplo que demonstra como adaptar o código existente para usar uma tarefa leve, [consulte Passo a passos: Adaptando o código existente para usar tarefas](../../parallel/concrt/walkthrough-adapting-existing-code-to-use-lightweight-tasks.md)leves.

## <a name="see-also"></a>Consulte também

[Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Passo a passo: Adaptando um código existente para usar tarefas leves](../../parallel/concrt/walkthrough-adapting-existing-code-to-use-lightweight-tasks.md)
