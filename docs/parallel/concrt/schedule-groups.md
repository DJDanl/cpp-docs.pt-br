---
title: Grupos de agendas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- schedule groups
ms.assetid: 03523572-5891-4d17-89ce-fa795605f28b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4fa61772af96ba0d2602ff42a6a43b2b3a13a4e6
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46385893"
---
# <a name="schedule-groups"></a>Grupos de agendas

Este documento descreve a função de grupos de agendamento no tempo de execução de simultaneidade. Um *grupo de agendas* possui afinidade ou grupos, tarefas relacionadas juntas. Cada Agendador possui um ou mais grupos de agendamento. Use grupos de agendamento de quando você exige um alto grau de localidade entre tarefas, por exemplo, quando um grupo de tarefas relacionadas se beneficiar da execução no mesmo nó do processador. Por outro lado, use instâncias de Agendador ao seu aplicativo tem requisitos específicos de qualidade, por exemplo, quando você deseja limitar a quantidade de recursos de processamento que estão alocadas para um conjunto de tarefas. Para obter mais informações sobre instâncias de Agendador, consulte [instâncias de Agendador](../../parallel/concrt/scheduler-instances.md).

> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão e, portanto, não é necessário criá-lo em seu aplicativo. Como o Agendador de tarefas Ajuda você a ajustar o desempenho de seus aplicativos, é recomendável que você comece com o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou o [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você estiver novo no tempo de execução de simultaneidade.

Cada `Scheduler` objeto tem um grupo de agendamento padrão para cada nó de agendamento. Um *agendamento nó* é mapeado para a topologia do sistema subjacente. O tempo de execução cria um nó de agendamento para cada pacote de processador ou nó de arquitetura de memória não uniforme (NUMA), o que for maior. Se você não associar explicitamente uma tarefa com um grupo de agendamento, o agendador escolherá o grupo ao qual a tarefa será adicionada.

O `SchedulingProtocol` política de Agendador influencia a ordem na qual o Agendador executa as tarefas em cada grupo de agendamento. Quando `SchedulingProtocol` é definido como `EnhanceScheduleGroupLocality` (que é o padrão), o Agendador de tarefas escolhe a próxima tarefa a partir do grupo de agendamento que ele está funcionando quando a tarefa atual seja concluída ou cooperativamente produz. O Agendador de tarefas procura o atual grupo de agendas para o trabalho antes de prosseguir para o próximo grupo disponível. Por outro lado, quando `SchedulingProtocol` é definido como `EnhanceForwardProgress`, o Agendador move para o próximo grupo de agendamento depois que cada tarefa seja concluída ou produz. Para obter um exemplo que compara essas políticas, consulte [como: Use grupos de agendamento para a ordem de execução influência](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md).

O tempo de execução usa o [Concurrency:: schedulegroup](../../parallel/concrt/reference/schedulegroup-class.md) classe para representar grupos de agendamento. Para criar uma `ScheduleGroup` do objeto, chame o [concurrency::CurrentScheduler::CreateScheduleGroup](reference/currentscheduler-class.md#createschedulegroup) ou [concurrency::Scheduler::CreateScheduleGroup](reference/scheduler-class.md#createschedulegroup) método. O tempo de execução usa um mecanismo de contagem de referência para controlar a vida útil do `ScheduleGroup` objetos, assim como acontece com o `Scheduler` objetos. Quando você cria um `ScheduleGroup` do objeto, o tempo de execução define a referência de contador para um. O [concurrency::ScheduleGroup::Reference](reference/schedulegroup-class.md#reference) método incrementa o contador de referências em um. O [concurrency::ScheduleGroup::Release](reference/schedulegroup-class.md#release) diminui método o contador de referência por um.

Muitos tipos no tempo de execução de simultaneidade permitem que você associe um objeto junto com um grupo de agendas. Por exemplo, o [concurrency::agent](../../parallel/concrt/reference/agent-class.md) classes de bloco de classe e a mensagem como [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md), [concurrency::join](../../parallel/concrt/reference/join-class.md)e a simultaneidade::[ Timer](reference/timer-class.md), fornecem versões sobrecarregadas do construtor que usam um `ScheduleGroup` objeto. O tempo de execução usa o `Scheduler` que está associado a este objeto `ScheduleGroup` objeto para agendar a tarefa.

Você também pode usar o [concurrency::ScheduleGroup::ScheduleTask](reference/schedulegroup-class.md#scheduletask) método para agendar uma tarefa leve. Para obter mais informações sobre tarefas leves, consulte [tarefas leves](../../parallel/concrt/lightweight-tasks.md).

## <a name="example"></a>Exemplo

Para obter um exemplo que usa grupos para controlar a ordem da execução da tarefa de agendamento, consulte [como: Use grupos de agendamento para a ordem de execução influência](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md).

## <a name="see-also"></a>Consulte também

[Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Instâncias de agendador](../../parallel/concrt/scheduler-instances.md)<br/>
[Como usar grupos agendados para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md)

