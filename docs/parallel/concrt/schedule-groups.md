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
ms.openlocfilehash: c1395fbc58d8a4d1d06cd93eea21c0f3d2dec8c6
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="schedule-groups"></a>Grupos de agendas
Este documento descreve a função dos grupos de agendamento no tempo de execução de simultaneidade. Um *grupo agenda* cria afinidade, ou grupos, tarefas relacionadas juntas. Cada Agendador possui um ou mais grupos de agendamento. Use grupos de agendamento de quando você exigir um alto grau de localidade entre tarefas, por exemplo, quando um grupo de tarefas relacionadas se beneficiar de execução no mesmo nó do processador. Por outro lado, use instâncias de Agendador quando seu aplicativo tiver requisitos específicos de qualidade de, por exemplo, quando você quiser limitar a quantidade de recursos de processamento que estão alocadas para um conjunto de tarefas. Para obter mais informações sobre instâncias de Agendador, consulte [instâncias de Agendador](../../parallel/concrt/scheduler-instances.md).  
  
> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão e, portanto, não é necessário criá-lo em seu aplicativo. Como o Agendador de tarefas Ajuda a ajustar o desempenho de seus aplicativos, é recomendável que você inicie com o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você estiver novo no tempo de execução de simultaneidade.  
  
 Cada `Scheduler` objeto tem um grupo de agendamento padrão para cada nó de agendamento. Um *agendamento nó* mapeia para a topologia do sistema subjacente. O tempo de execução cria um nó de agendamento para cada pacote de processador ou arquitetura de memória não uniforme (NUMA), o que for maior. Se você não associar explicitamente uma tarefa com um grupo de agendamento, o agendador escolherá o grupo ao qual adicionar a tarefa.  
  
 O `SchedulingProtocol` política Agendador influencia a ordem na qual o Agendador executa as tarefas em cada grupo de agendamento. Quando `SchedulingProtocol` é definido como `EnhanceScheduleGroupLocality` (que é o padrão), o Agendador de tarefas escolhe a próxima tarefa a partir do grupo de agendamento está trabalhando em quando a tarefa atual seja concluída ou cooperativamente produz. O Agendador de tarefas Pesquisa o grupo atual da agenda para o trabalho antes de passar para o próximo grupo disponível. Por outro lado, quando `SchedulingProtocol` é definido como `EnhanceForwardProgress`, o Agendador move para o próximo grupo de agenda após a conclusão de cada tarefa ou gera. Para obter um exemplo que compara a essas políticas, consulte [como: usar grupos de agendamento para ordem de execução de influência](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md).  
  

 O tempo de execução usa a [concurrency::ScheduleGroup](../../parallel/concrt/reference/schedulegroup-class.md) classe para representar grupos de agendas. Para criar um `ScheduleGroup` de objeto, chame o [concurrency::CurrentScheduler::CreateScheduleGroup](reference/currentscheduler-class.md#createschedulegroup) ou [concurrency::Scheduler::CreateScheduleGroup](reference/scheduler-class.md#createschedulegroup) método. O tempo de execução usa um mecanismo de contagem de referência para controlar o tempo de vida de `ScheduleGroup` objetos, assim como acontece com `Scheduler` objetos. Quando você cria um `ScheduleGroup` do objeto, o tempo de execução define a referência de contador para um. O [concurrency::ScheduleGroup::Reference](reference/schedulegroup-class.md#reference) método incrementa o contador de referência em um. O [concurrency::ScheduleGroup::Release](reference/schedulegroup-class.md#release) diminui método o contador de referência por um.  
  
 Muitos tipos em tempo de execução de simultaneidade permitem que você associe um objeto junto com um grupo de agendamento. Por exemplo, o [concurrency::agent](../../parallel/concrt/reference/agent-class.md) blocos de classe e a mensagem, como classes [concurrency::unbounded_buffer](reference/unbounded-buffer-class.md), [concurrency::join](../../parallel/concrt/reference/join-class.md)e a simultaneidade::[ Timer](reference/timer-class.md), fornecer versões do construtor sobrecarregadas que levam um `ScheduleGroup` objeto. O tempo de execução usa a `Scheduler` que está associado este objeto `ScheduleGroup` objeto para agendar a tarefa.  
  
 Você também pode usar o [concurrency::ScheduleGroup::ScheduleTask](reference/schedulegroup-class.md#scheduletask) método para agendar uma tarefa simples. Para obter mais informações sobre tarefas leves, consulte [tarefas leves](../../parallel/concrt/lightweight-tasks.md).  

  
## <a name="example"></a>Exemplo  
 Para obter um exemplo que usa grupos para controlar a ordem de execução da tarefa de agendamento, consulte [como: usar grupos de agendamento para ordem de execução de influência](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md).  
  
## <a name="see-also"></a>Consulte também  
 [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Instâncias de Agendador](../../parallel/concrt/scheduler-instances.md)   
 [Como usar grupos agendados para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md)

