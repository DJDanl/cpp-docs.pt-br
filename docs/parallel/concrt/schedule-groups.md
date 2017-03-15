---
title: "Grupos de agendas | Microsoft Docs"
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
  - "grupos de agendas"
ms.assetid: 03523572-5891-4d17-89ce-fa795605f28b
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Grupos de agendas
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento descreve a função de grupos de agendamento no tempo de execução de simultaneidade. Um *grupo de programação* cria afinidade ou agrupa, tarefas relacionadas. Cada Agendador possui um ou mais grupos de agendamento. Usar grupos de agendamento quando você requer um alto grau de localidade entre tarefas, por exemplo, quando um grupo de tarefas relacionadas se beneficiar da execução no mesmo nó do processador. Por outro lado, use instâncias de Agendador quando seu aplicativo tiver requisitos de qualidade específicos, por exemplo, quando você deseja limitar a quantidade de recursos de processamento que estão alocados para um conjunto de tarefas. Para obter mais informações sobre instâncias de Agendador, consulte [instâncias de Agendador](../../parallel/concrt/scheduler-instances.md).  
  
> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão e, portanto, não é necessário criar um em seu aplicativo. Como o Agendador de tarefas Ajuda a ajustar o desempenho de seus aplicativos, é recomendável que você inicie com o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou o [Asynchronous Agents Library](../../parallel/concrt/asynchronous-agents-library.md) se você for novo no tempo de execução de simultaneidade.  
  
 Cada `Scheduler` objeto tem um grupo de agendamento padrão para cada nó de agendamento. Um *agendamento nó* mapeia para a topologia do sistema subjacente. O tempo de execução cria um nó de agendamento para cada pacote de processador ou arquitetura de memória não-uniforme (NUMA), o que for maior. Se você não associar explicitamente uma tarefa com um grupo de agendamento, o agendador escolherá o grupo ao qual adicionar a tarefa.  
  
 O `SchedulingProtocol` política Agendador influencia a ordem na qual o Agendador executa as tarefas em cada grupo de agendamento. Quando `SchedulingProtocol` é definido como `EnhanceScheduleGroupLocality` (que é o padrão), o Agendador de tarefas escolhe a próxima tarefa a partir do grupo de agendamento que ele está trabalhando quando a tarefa atual termine ou cooperativamente produz. O Agendador de tarefas Pesquisa o grupo atual do agendamento do trabalho antes de passar para o próximo grupo disponível. Por outro lado, quando `SchedulingProtocol` está definido como `EnhanceForwardProgress`, o Agendador move para o próximo grupo de agenda após conclusão de cada tarefa ou produz. Para obter um exemplo que compara essas políticas, consulte [como: usar grupos de agendamento para a ordem de execução de influência](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md).  
  
 O tempo de execução usa o [concurrency::ScheduleGroup](../Topic/ScheduleGroup%20Class.md) classe para representar grupos de agendamento. Para criar um `ScheduleGroup` de objeto, chame o [concurrency::CurrentScheduler::CreateScheduleGroup](../Topic/CurrentScheduler::CreateScheduleGroup%20Method.md) ou [concurrency::Scheduler::CreateScheduleGroup](../Topic/Scheduler::CreateScheduleGroup%20Method.md) método. O tempo de execução usa um mecanismo de contagem de referência para controlar o tempo de vida de `ScheduleGroup` objetos, assim como acontece com `Scheduler` objetos. Quando você cria um `ScheduleGroup` do objeto, o tempo de execução define a referência de contador para um. O [concurrency::ScheduleGroup::Reference](../Topic/ScheduleGroup::Reference%20Method.md) método incrementa o contador de referência em um. O [concurrency::ScheduleGroup::Release](../Topic/ScheduleGroup::Release%20Method.md) diminui método o contador de referência por um.  
  
 Muitos tipos no tempo de execução de simultaneidade permitem que você associe um objeto junto com um grupo de agendamento. Por exemplo, o [concurrency::agent](../../parallel/concrt/reference/agent-class.md) Bloco de classe e mensagem classes como [concurrency::unbounded_buffer](../Topic/unbounded_buffer%20Class.md), [concurrency::join](../Topic/join%20Class.md), e simultaneidade::[timer](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/d5d4c847-5ad6-4c7f-b35b-d0b6f446d8b4/locales/en-US), fornecer versões sobrecarregadas do construtor que usam uma `ScheduleGroup` objeto. O tempo de execução usa o `Scheduler` associado este objeto `ScheduleGroup` objeto para agendar a tarefa.  
  
 Você também pode usar o [concurrency::ScheduleGroup::ScheduleTask](../Topic/ScheduleGroup::ScheduleTask%20Method.md) método para agendar uma tarefa simples. Para obter mais informações sobre tarefas leves, consulte [tarefas leves](../../parallel/concrt/lightweight-tasks.md).  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo que usa grupos para controlar a ordem de execução de tarefa de agendamento, consulte [como: usar grupos de agendamento para a ordem de execução de influência](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md).  
  
## <a name="see-also"></a>Consulte também  
 [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Instâncias de Agendador](../../parallel/concrt/scheduler-instances.md)   
 [Como: usar grupos de agendas para influenciar a ordem de execução](../../parallel/concrt/how-to-use-schedule-groups-to-influence-order-of-execution.md)

