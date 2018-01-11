---
title: "Instâncias de Agendador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: scheduler instances
ms.assetid: 4819365f-ef99-49cc-963e-50a2a35a8d6b
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1688a2b689b3fc3391e617f3d65d3c681f05a84f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="scheduler-instances"></a>Instâncias de agendador
Este documento descreve a função de instâncias de Agendador em tempo de execução de simultaneidade e como usar o [concurrency::Scheduler](../../parallel/concrt/reference/scheduler-class.md) e [concurrency::CurrentScheduler](../../parallel/concrt/reference/currentscheduler-class.md) classes para criar e gerenciar instâncias de Agendador. Instâncias de Agendador são úteis quando você deseja associar políticas de agendamento explícitas com tipos específicos de cargas de trabalho. Por exemplo, você pode criar uma instância de Agendador para executar algumas tarefas em uma prioridade de thread com privilégios elevados e use o agendador padrão para executar outras tarefas com a prioridade normal de threads.  
  
> [!TIP]
>  O tempo de execução de simultaneidade fornece um agendador padrão e, portanto, não é necessário criá-lo em seu aplicativo. Como o Agendador de tarefas Ajuda a ajustar o desempenho de seus aplicativos, é recomendável que você inicie com o [biblioteca de padrões paralelos (PPL)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você estiver novo no tempo de execução de simultaneidade.  
  
##  <a name="top"></a>Seções  
  
-   [O Agendador e Classes de CurrentScheduler](#classes)  
  
-   [Criando uma instância de Agendador](#creating)  
  
-   [Gerenciar o tempo de vida de uma instância de Agendador](#managing)  
  
-   [Métodos e recursos](#features)  
  
-   [Exemplo](#example)  
  
##  <a name="classes"></a>O Agendador e Classes de CurrentScheduler  
 O Agendador de tarefas permite que os aplicativos usam uma ou mais *instâncias de Agendador* para agendar o trabalho. O [concurrency::Scheduler](../../parallel/concrt/reference/scheduler-class.md) classe representa uma instância de agendador e encapsula a funcionalidade que está relacionada ao agendamento de tarefas.  
  
 Um thread que está anexado a um agendador é conhecido como um *contexto de execução*, ou apenas *contexto*. Um agendador pode estar ativo no contexto atual a qualquer momento. O Agendador active também é conhecido como o *Agendador atual*. O tempo de execução de simultaneidade usa o [concurrency::CurrentScheduler](../../parallel/concrt/reference/currentscheduler-class.md) classe para fornecer acesso para o Agendador atual. O Agendador atual para um contexto pode ser diferente do Agendador atual para outro contexto. O tempo de execução não fornece uma representação de nível de processo do Agendador atual.  
  
 Normalmente, o `CurrentScheduler` classe é usada para acessar o Agendador atual. O `Scheduler` classe é útil quando você precisa gerenciar um agendador que não é atual.  
  
 As seções a seguir descrevem como criar e gerenciar uma instância do Agendador. Para obter um exemplo completo que ilustra essas tarefas, consulte [como: gerenciar uma instância de Agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md).  
  
 [[Superior](#top)]  
  
##  <a name="creating"></a>Criando uma instância de Agendador  
 Esses três maneiras para criar um `Scheduler` objeto:  
  
-   Se o Agendador não existir, o tempo de execução cria um agendador padrão para você quando você usar a funcionalidade de tempo de execução, por exemplo, um algoritmo paralelo, para executar o trabalho. O agendador padrão torna-se o Agendador atual para o contexto que inicia o trabalho em paralelo.  
  

-   O [concurrency::CurrentScheduler::Create](reference/currentscheduler-class.md#create) método cria um `Scheduler` objeto que usa uma política específica e que o Agendador está associado ao contexto atual.  
  
-   O [concurrency::Scheduler::Create](reference/scheduler-class.md#create) método cria um `Scheduler` objeto que usa uma política específica, mas não associá-lo com o contexto atual.  

  
 Permitir que o tempo de execução criar um agendador padrão permite que todas as tarefas simultâneas compartilhar o mesmo Agendador. Normalmente, a funcionalidade fornecida pelo [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) (PPL) ou o [biblioteca de agentes assíncrona](../../parallel/concrt/asynchronous-agents-library.md) é usada para executar o trabalho paralelos. Portanto, você não precisa trabalhar diretamente com o Agendador para controlar sua política ou o tempo de vida. Quando você usa a PPL ou a biblioteca de agentes, o tempo de execução cria o agendador padrão se não existir e se torna o Agendador atual para cada contexto. Quando você cria um agendador e defina-o como o Agendador atual, o tempo de execução usa que o Agendador para agendar tarefas. Crie instâncias de Agendador adicionais somente quando precisar de uma política específica de agendamento. Para obter mais informações sobre as políticas associadas um agendador, consulte [políticas de Agendador](../../parallel/concrt/scheduler-policies.md).  
  
 [[Superior](#top)]  
  
##  <a name="managing"></a>Gerenciar o tempo de vida de uma instância de Agendador  
 O tempo de execução usa um mecanismo de contagem de referência para controlar o tempo de vida de `Scheduler` objetos.  
  

 Quando você usa o `CurrentScheduler::Create` método ou o `Scheduler::Create` método para criar um `Scheduler` do objeto, o tempo de execução define a contagem de referência inicial de que o Agendador para um. O tempo de execução incrementa a contagem de referência quando você chama o [concurrency::Scheduler::Attach](reference/scheduler-class.md#attach) método. O `Scheduler::Attach` método associa o `Scheduler` objeto junto com o contexto atual. Isso torna o Agendador atual. Quando você chama o `CurrentScheduler::Create` método, o runtime cria um `Scheduler` do objeto e anexa ao contexto atual (e define a contagem de referência para um). Você também pode usar o [concurrency::Scheduler::Reference](reference/scheduler-class.md#reference) método usado para incrementar a contagem de referência de um `Scheduler` objeto.  
  
 Diminui o tempo de execução que a contagem de referência quando você chama o [concurrency::CurrentScheduler::Detach](reference/currentscheduler-class.md#detach) método para desanexar o Agendador atual, ou chame o [concurrency::Scheduler::Release](reference/scheduler-class.md#release) método. Quando a contagem de referência chega a zero, o tempo de execução destrói o `Scheduler` objeto agendada depois que todas as tarefas concluir. Uma tarefa em execução é permitida para incrementar a contagem de referência do Agendador atual. Portanto, se a contagem de referência chega a zero e uma tarefa incrementa a contagem de referência, o tempo de execução não destrói o `Scheduler` objeto até que a contagem de referência chega a zero novamente e concluir todas as tarefas.  

  
 O tempo de execução mantém uma pilha interna de `Scheduler` objetos para cada contexto. Quando você chama o `Scheduler::Attach` ou `CurrentScheduler::Create` envios de método, o tempo de execução que `Scheduler` objeto para a pilha para o contexto atual. Isso torna o Agendador atual. Quando você chama `CurrentScheduler::Detach`, o tempo de execução aparece o Agendador atual da pilha de contexto atual e define aquele anterior como o Agendador atual.  
  
 O tempo de execução fornece várias maneiras de gerenciar o tempo de vida de uma instância do Agendador. A tabela a seguir mostra o método apropriado que libera ou desanexa o Agendador do contexto atual para cada método que cria ou anexa um agendador ao contexto atual.  
  
|Criar ou método attach|Liberar ou método detach|  
|-----------------------------|------------------------------|  
|`CurrentScheduler::Create`|`CurrentScheduler::Detach`|  
|`Scheduler::Create`|`Scheduler::Release`|  
|`Scheduler::Attach`|`CurrentScheduler::Detach`|  
|`Scheduler::Reference`|`Scheduler::Release`|  
  
 Chamando o inadequado de versão ou desanexar o comportamento do método produz não especificado no tempo de execução.  
  
 Quando você usa a funcionalidade, por exemplo, PPL, que faz com que o tempo de execução criar o agendador padrão para você, não liberar ou desanexar neste Agendador. O tempo de execução gerencia o tempo de vida de qualquer Agendador que ele cria.  
  

 Porque o tempo de execução não destrói um `Scheduler` objeto antes de concluir todas as tarefas, você pode usar o [concurrency::Scheduler::RegisterShutdownEvent](reference/scheduler-class.md#registershutdownevent) método ou o [concurrency::CurrentScheduler:: RegisterShutdownEvent](reference/currentscheduler-class.md#registershutdownevent) método para receber uma notificação quando um `Scheduler` objeto é destruído. Isso é útil quando você deve esperar para todas as tarefas agendadas por um `Scheduler` objeto para concluir.  
  
 [[Superior](#top)]  
  
##  <a name="features"></a>Métodos e recursos  
 Esta seção resume os métodos importantes do `CurrentScheduler` e `Scheduler` classes.  
  
 Imagine a `CurrentScheduler` classe como um auxiliar para a criação de um agendador para uso no contexto atual. O `Scheduler` classe permite que você controle um agendador que pertence a outro contexto.  
  
 A tabela a seguir mostra os métodos importantes que são definidos pelo `CurrentScheduler` classe.  
  
|Método|Descrição|  
|------------|-----------------|  
|[Criar](reference/currentscheduler-class.md#create)|Cria um `Scheduler` objeto que usa a política especificada e o associa ao contexto atual.|  
|[Get](reference/currentscheduler-class.md#get)|Recupera um ponteiro para o `Scheduler` objeto que está associado com o contexto atual. Esse método não incrementa a contagem de referência de `Scheduler` objeto.|  
|[Desanexar](reference/currentscheduler-class.md#detach)|Desanexa o Agendador atual do contexto atual e define aquele anterior como o Agendador atual.|  
|[RegisterShutdownEvent](reference/currentscheduler-class.md#registershutdownevent)|Registra um evento que o tempo de execução define quando o Agendador atual é destruído.|  
|[CreateScheduleGroup](reference/currentscheduler-class.md#createschedulegroup)|Cria um [concurrency::ScheduleGroup](../../parallel/concrt/reference/schedulegroup-class.md) objeto no Agendador do atual.|  
|[ScheduleTask](reference/currentscheduler-class.md#scheduletask)|Adiciona uma tarefa leve à fila de agendamento do Agendador atual.|  
|[GetPolicy](reference/currentscheduler-class.md#getpolicy)|Recupera uma cópia da política que está associada com o Agendador atual.|  
  
 A tabela a seguir mostra os métodos importantes que são definidos pelo `Scheduler` classe.  
  
|Método|Descrição|  
|------------|-----------------|  
|[Criar](reference/scheduler-class.md#create)|Cria um `Scheduler` objeto que usa a política especificada.|  
|[Anexar](reference/scheduler-class.md#attach)|Associa o `Scheduler` objeto junto com o contexto atual.|  
|[Referência](reference/scheduler-class.md#reference)|Incrementa o contador de referência do `Scheduler` objeto.|  
|[Versão](reference/scheduler-class.md#release)|Diminui o contador de referência do `Scheduler` objeto.|  
|[RegisterShutdownEvent](reference/scheduler-class.md#registershutdownevent)|Registra um evento que o tempo de execução define quando o `Scheduler` objeto é destruído.|  
|[CreateScheduleGroup](reference/scheduler-class.md#createschedulegroup)|Cria um [concurrency::ScheduleGroup](../../parallel/concrt/reference/schedulegroup-class.md) objeto o `Scheduler` objeto.|  
|[ScheduleTask](reference/scheduler-class.md#scheduletask)|Agenda de uma tarefa leve o `Scheduler` objeto.|  
|[GetPolicy](reference/scheduler-class.md#getpolicy)|Recupera uma cópia da política que está associada com o `Scheduler` objeto.|  
|[SetDefaultSchedulerPolicy](reference/scheduler-class.md#setdefaultschedulerpolicy)|Define a política de execução a ser usada ao criar o agendador padrão.|  
|[ResetDefaultSchedulerPolicy](reference/scheduler-class.md#resetdefaultschedulerpolicy)|Restaura a política padrão para aquele que estava ativa antes da chamada para `SetDefaultSchedulerPolicy`. Se o agendador padrão for criado após essa chamada, o tempo de execução usa configurações de política padrão para criar o Agendador.|  

  
 [[Superior](#top)]  
  
##  <a name="example"></a> Exemplo  
 Para obter exemplos básicos de como criar e gerenciar uma instância de Agendador, consulte [como: gerenciar uma instância de Agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md).  
  
## <a name="see-also"></a>Consulte também  
 [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)   
 [Como: gerenciar uma instância de Agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md)   
 [Políticas de Agendador](../../parallel/concrt/scheduler-policies.md)   
 [Grupos Agendados](../../parallel/concrt/schedule-groups.md)

