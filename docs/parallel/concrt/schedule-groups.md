---
title: Grupos de agendas
ms.date: 11/04/2016
helpviewer_keywords:
- schedule groups
ms.assetid: 03523572-5891-4d17-89ce-fa795605f28b
ms.openlocfilehash: 1765c10f4cf8fe499aed1a140d2bba1ecaaf2300
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142307"
---
# <a name="schedule-groups"></a>Grupos de agendas

Este documento descreve a função de grupos de agendamento no Tempo de Execução de Simultaneidade. Um *grupo de agendamento* affinitizes, ou grupos, tarefas relacionadas em conjunto. Cada Agendador tem um ou mais grupos de agendamento. Use grupos de agendamento quando precisar de um alto grau de localidade entre tarefas, por exemplo, quando um grupo de tarefas relacionadas se beneficiar da execução no mesmo nó do processador. Por outro lado, use instâncias do Agendador quando seu aplicativo tiver requisitos específicos de qualidade, por exemplo, quando você quiser limitar a quantidade de recursos de processamento alocados a um conjunto de tarefas. Para obter mais informações sobre instâncias do Agendador, consulte [instâncias do Agendador](../../parallel/concrt/scheduler-instances.md).

> [!TIP]
> O Tempo de Execução de Simultaneidade fornece um agendador padrão e, portanto, não é necessário criar um em seu aplicativo. Como o Agendador de Tarefas ajuda você a ajustar o desempenho de seus aplicativos, recomendamos que você comece com a [ppl (biblioteca de padrões paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou a [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você for novo no tempo de execução de simultaneidade.

Cada objeto de `Scheduler` tem um grupo de agendamento padrão para cada nó de agendamento. Um *nó de agendamento* é mapeado para a topologia de sistema subjacente. O tempo de execução cria um nó de agendamento para cada pacote de processador ou nó NUMA (arquitetura de memória não uniforme), o número que for maior. Se você não associar explicitamente uma tarefa a um grupo de agendamento, o Agendador escolherá a qual grupo adicionar a tarefa.

O `SchedulingProtocol` política do Agendador influencia a ordem em que o Agendador executa as tarefas em cada grupo de agendamento. Quando `SchedulingProtocol` é definido como `EnhanceScheduleGroupLocality` (que é o padrão), o Agendador de Tarefas escolhe a próxima tarefa do grupo de agendamento no qual ele está trabalhando quando a tarefa atual é concluída ou é produzida de uma cooperativa. O Agendador de Tarefas pesquisa o grupo de agendas atual para trabalho antes de passar para o próximo grupo disponível. Por outro lado, quando `SchedulingProtocol` é definido como `EnhanceForwardProgress`, o Agendador passa para o próximo grupo de agendamento após a conclusão de cada tarefa ou a concessão. Para obter um exemplo que compara essas políticas, consulte [como: usar grupos de agendamento para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md).

O tempo de execução usa a classe [Concurrency:: Schedule](../../parallel/concrt/reference/schedulegroup-class.md) Group para representar grupos de agendamento. Para criar um objeto `ScheduleGroup`, chame o método [Concurrency:: CurrentScheduler:: CreateSchedule](reference/currentscheduler-class.md#createschedulegroup) ou [Concurrency:: Scheduler:: CreateSchedule](reference/scheduler-class.md#createschedulegroup) . O tempo de execução usa um mecanismo de contagem de referência para controlar o tempo de vida de objetos `ScheduleGroup`, assim como faz com `Scheduler` objetos. Quando você cria um objeto `ScheduleGroup`, o tempo de execução define o contador de referência como um. O método [Concurrency:: Schedule:: Reference](reference/schedulegroup-class.md#reference) incrementa o contador de referência em um. O método [Concurrency:: Scheduler:: Release](reference/schedulegroup-class.md#release) Decrementa o contador de referência em um.

Muitos tipos na Tempo de Execução de Simultaneidade permitem que você associe um objeto a um grupo de agendamento. Por exemplo, a classe [Concurrency:: Agent](../../parallel/concrt/reference/agent-class.md) e as classes de bloco de mensagem, como [concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md), [Concurrency:: join](../../parallel/concrt/reference/join-class.md)e Concurrency::[timer](reference/timer-class.md), fornecem versões sobrecarregadas do construtor que usam um objeto `ScheduleGroup`. O tempo de execução usa o objeto `Scheduler` associado a esse objeto `ScheduleGroup` para agendar a tarefa.

Você também pode usar o método [Concurrency:: Schedule:: ScheduleTask](reference/schedulegroup-class.md#scheduletask) para agendar uma tarefa leve. Para obter mais informações sobre tarefas leves, consulte [tarefas leves](../../parallel/concrt/lightweight-tasks.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Para obter um exemplo que usa grupos de agendamento para controlar a ordem de execução da tarefa, consulte [como: usar grupos de agendamento para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md).

## <a name="see-also"></a>Consulte também

[Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Instâncias de agendador](../../parallel/concrt/scheduler-instances.md)<br/>
[Como usar grupos agendados para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md)
