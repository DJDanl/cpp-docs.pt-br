---
title: Instâncias de agendador
ms.date: 11/04/2016
helpviewer_keywords:
- scheduler instances
ms.assetid: 4819365f-ef99-49cc-963e-50a2a35a8d6b
ms.openlocfilehash: e9e9b8124254084ac30191d37d49f2ef72bd677e
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142290"
---
# <a name="scheduler-instances"></a>Instâncias de agendador

Este documento descreve a função de instâncias do Agendador no Tempo de Execução de Simultaneidade e como usar as classes [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) e [Concurrency:: CurrentScheduler](../../parallel/concrt/reference/currentscheduler-class.md) para criar e gerenciar instâncias do Agendador. As instâncias do Agendador são úteis quando você deseja associar políticas de agendamento explícitas a tipos específicos de cargas de trabalho. Por exemplo, você pode criar uma instância de Agendador para executar algumas tarefas em uma prioridade de thread elevada e usar o agendador padrão para executar outras tarefas na prioridade de thread normal.

> [!TIP]
> O Tempo de Execução de Simultaneidade fornece um agendador padrão e, portanto, não é necessário criar um em seu aplicativo. Como o Agendador de Tarefas ajuda você a ajustar o desempenho de seus aplicativos, recomendamos que você comece com a [ppl (biblioteca de padrões paralelos)](../../parallel/concrt/parallel-patterns-library-ppl.md) ou a [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) se você for novo no tempo de execução de simultaneidade.

## <a name="top"></a>As

- [As classes Scheduler e CurrentScheduler](#classes)

- [Criando uma instância do Agendador](#creating)

- [Gerenciando o tempo de vida de uma instância do Agendador](#managing)

- [Métodos e recursos](#features)

- [Exemplo](#example)

## <a name="classes"></a>As classes Scheduler e CurrentScheduler

O Agendador de Tarefas permite que os aplicativos usem uma ou mais *instâncias do Agendador* para agendar o trabalho. A classe [Concurrency:: Scheduler](../../parallel/concrt/reference/scheduler-class.md) representa uma instância do Agendador e encapsula a funcionalidade relacionada às tarefas de agendamento.

Um thread que é anexado a um Agendador é conhecido como *contexto de execução*ou apenas *contexto*. Um Agendador pode estar ativo no contexto atual a qualquer momento. O Agendador ativo também é conhecido como o *Agendador atual*. O Tempo de Execução de Simultaneidade usa a classe [Concurrency:: CurrentScheduler](../../parallel/concrt/reference/currentscheduler-class.md) para fornecer acesso ao Agendador atual. O Agendador atual de um contexto pode ser diferente do Agendador atual para outro contexto. O tempo de execução não fornece uma representação em nível de processo do Agendador atual.

Normalmente, a classe `CurrentScheduler` é usada para acessar o Agendador atual. A classe `Scheduler` é útil quando você precisa gerenciar um Agendador que não seja o atual.

As seções a seguir descrevem como criar e gerenciar uma instância do Agendador. Para obter um exemplo completo que ilustra essas tarefas, consulte [como gerenciar uma instância do Agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md).

[[Superior](#top)]

## <a name="creating"></a>Criando uma instância do Agendador

Há três maneiras de criar um objeto de `Scheduler`:

- Se não houver um Agendador, o tempo de execução criará um agendador padrão para você quando você usar a funcionalidade de tempo de execução, por exemplo, um algoritmo paralelo, para executar o trabalho. O agendador padrão torna-se o Agendador atual para o contexto que inicia o trabalho paralelo.

- O método [Concurrency:: CurrentScheduler:: Create](reference/currentscheduler-class.md#create) cria um objeto `Scheduler` que usa uma política específica e associa esse Agendador ao contexto atual.

- O método [Concurrency:: Scheduler:: Create](reference/scheduler-class.md#create) cria um objeto `Scheduler` que usa uma política específica, mas não o associa ao contexto atual.

Permitir que o tempo de execução crie um agendador padrão permite que todas as tarefas simultâneas compartilhem o mesmo Agendador. Normalmente, a funcionalidade fornecida pela ppl ( [biblioteca de padrões paralelos](../../parallel/concrt/parallel-patterns-library-ppl.md) ) ou pela [biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md) é usada para executar o trabalho paralelo. Portanto, você não precisa trabalhar diretamente com o Agendador para controlar sua política ou tempo de vida. Quando você usar o PPL ou a biblioteca de agentes, o tempo de execução criará o agendador padrão se ele não existir e o tornará o Agendador atual para cada contexto. Quando você cria um Agendador e o define como o Agendador atual, o tempo de execução usa esse Agendador para agendar tarefas. Crie instâncias adicionais do Agendador somente quando precisar de uma política de agendamento específica. Para obter mais informações sobre as políticas associadas a um Agendador, consulte [políticas do Agendador](../../parallel/concrt/scheduler-policies.md).

[[Superior](#top)]

## <a name="managing"></a>Gerenciando o tempo de vida de uma instância do Agendador

O tempo de execução usa um mecanismo de contagem de referência para controlar o tempo de vida de objetos de `Scheduler`.

Quando você usa o método `CurrentScheduler::Create` ou o método `Scheduler::Create` para criar um objeto `Scheduler`, o tempo de execução define a contagem de referência inicial desse Agendador como um. O tempo de execução incrementa a contagem de referência quando você chama o método [Concurrency:: Scheduler:: Attach](reference/scheduler-class.md#attach) . O método `Scheduler::Attach` associa o objeto `Scheduler` ao contexto atual. Isso o torna o Agendador atual. Quando você chama o método `CurrentScheduler::Create`, o tempo de execução cria um objeto `Scheduler` e o anexa ao contexto atual (e define a contagem de referência como um). Você também pode usar o método [Concurrency:: Scheduler:: Reference](reference/scheduler-class.md#reference) para incrementar a contagem de referência de um objeto `Scheduler`.

O tempo de execução decrementa a contagem de referência quando você chama o método [Concurrency:: CurrentScheduler::D Etach](reference/currentscheduler-class.md#detach) para desanexar o Agendador atual ou chamar o método [Concurrency:: Scheduler:: Release](reference/scheduler-class.md#release) . Quando a contagem de referência chega a zero, o tempo de execução destrói o objeto `Scheduler` após a conclusão de todas as tarefas agendadas. Uma tarefa em execução tem permissão para incrementar a contagem de referência do Agendador atual. Portanto, se a contagem de referência chegar a zero e uma tarefa incrementar a contagem de referência, o tempo de execução não destruirá o objeto `Scheduler` até que a contagem de referência chegue novamente a zero e todas as tarefas sejam concluídas.

O tempo de execução mantém uma pilha interna de objetos `Scheduler` para cada contexto. Quando você chama o método `Scheduler::Attach` ou `CurrentScheduler::Create`, o tempo de execução envia o objeto `Scheduler` para a pilha para o contexto atual. Isso o torna o Agendador atual. Quando você chama `CurrentScheduler::Detach`, o tempo de execução exibe o Agendador atual da pilha para o contexto atual e define o anterior como o Agendador atual.

O tempo de execução fornece várias maneiras de gerenciar o tempo de vida de uma instância do Agendador. A tabela a seguir mostra o método apropriado que libera ou desanexa o Agendador do contexto atual para cada método que cria ou anexa um Agendador ao contexto atual.

|Criar ou anexar método|Método liberar ou desanexar|
|-----------------------------|------------------------------|
|`CurrentScheduler::Create`|`CurrentScheduler::Detach`|
|`Scheduler::Create`|`Scheduler::Release`|
|`Scheduler::Attach`|`CurrentScheduler::Detach`|
|`Scheduler::Reference`|`Scheduler::Release`|

Chamar o método Release ou Detach inadequado produz um comportamento não especificado no tempo de execução.

Quando você usa a funcionalidade, por exemplo, a PPL, que faz com que o tempo de execução crie o agendador padrão para você, não libere ou desanexe esse Agendador. O tempo de execução gerencia o tempo de vida de qualquer Agendador que ele cria.

Como o tempo de execução não destrói um objeto de `Scheduler` antes que todas as tarefas tenham sido concluídas, você pode usar o método [Concurrency:: Scheduler:: RegisterShutdownEvent](reference/scheduler-class.md#registershutdownevent) ou os métodos [Concurrency:: CurrentScheduler:: RegisterShutdownEvent](reference/currentscheduler-class.md#registershutdownevent) para receber uma notificação quando um objeto `Scheduler` é destruído. Isso é útil quando você deve aguardar a conclusão de cada tarefa agendada por um objeto `Scheduler`.

[[Superior](#top)]

## <a name="features"></a>Métodos e recursos

Esta seção resume os métodos importantes das classes `CurrentScheduler` e `Scheduler`.

Imagine a classe `CurrentScheduler` como um auxiliar para criar um Agendador para uso no contexto atual. A classe `Scheduler` permite controlar um Agendador que pertence a outro contexto.

A tabela a seguir mostra os métodos importantes que são definidos pela classe `CurrentScheduler`.

|Método|Descrição|
|------------|-----------------|
|[Criar](reference/currentscheduler-class.md#create)|Cria um objeto `Scheduler` que usa a política especificada e a associa ao contexto atual.|
|[Get](reference/currentscheduler-class.md#get)|Recupera um ponteiro para o objeto `Scheduler` que está associado ao contexto atual. Esse método não incrementa a contagem de referência do objeto `Scheduler`.|
|[Desanexar](reference/currentscheduler-class.md#detach)|Desanexa o Agendador atual do contexto atual e define o anterior como o Agendador atual.|
|[RegisterShutdownEvent](reference/currentscheduler-class.md#registershutdownevent)|Registra um evento que o tempo de execução define quando o Agendador atual é destruído.|
|[CreateSchedule](reference/currentscheduler-class.md#createschedulegroup)|Cria um objeto [Concurrency:: Schedule](../../parallel/concrt/reference/schedulegroup-class.md) no Agendador atual.|
|[ScheduleTask](reference/currentscheduler-class.md#scheduletask)|Adiciona uma tarefa leve à fila de agendamento do Agendador atual.|
|[GetPolicy](reference/currentscheduler-class.md#getpolicy)|Recupera uma cópia da política associada ao Agendador atual.|

A tabela a seguir mostra os métodos importantes que são definidos pela classe `Scheduler`.

|Método|Descrição|
|------------|-----------------|
|[Criar](reference/scheduler-class.md#create)|Cria um objeto `Scheduler` que usa a política especificada.|
|[Anexar](reference/scheduler-class.md#attach)|Associa o objeto `Scheduler` junto ao contexto atual.|
|[Referência](reference/scheduler-class.md#reference)|Incrementa o contador de referência do objeto `Scheduler`.|
|[Versão](reference/scheduler-class.md#release)|Decrementa o contador de referência do objeto `Scheduler`.|
|[RegisterShutdownEvent](reference/scheduler-class.md#registershutdownevent)|Registra um evento que o tempo de execução define quando o objeto `Scheduler` é destruído.|
|[CreateSchedule](reference/scheduler-class.md#createschedulegroup)|Cria um objeto [Concurrency:: Schedule](../../parallel/concrt/reference/schedulegroup-class.md) no objeto `Scheduler`.|
|[ScheduleTask](reference/scheduler-class.md#scheduletask)|Agenda uma tarefa leve do objeto `Scheduler`.|
|[GetPolicy](reference/scheduler-class.md#getpolicy)|Recupera uma cópia da política associada ao objeto `Scheduler`.|
|[SetDefaultSchedulerPolicy](reference/scheduler-class.md#setdefaultschedulerpolicy)|Define a política para o tempo de execução a ser usado ao criar o agendador padrão.|
|[ResetDefaultSchedulerPolicy](reference/scheduler-class.md#resetdefaultschedulerpolicy)|Restaura a política padrão para aquela que estava ativa antes da chamada para `SetDefaultSchedulerPolicy`. Se o agendador padrão for criado após essa chamada, o tempo de execução usará as configurações de política padrão para criar o Agendador.|

[[Superior](#top)]

## <a name="example"></a> Exemplo

Para obter exemplos básicos de como criar e gerenciar uma instância do Agendador, consulte [como gerenciar uma instância do Agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md).

## <a name="see-also"></a>Consulte também

[Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)<br/>
[Como gerenciar instâncias de agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md)<br/>
[Políticas de agendador](../../parallel/concrt/scheduler-policies.md)<br/>
[Grupos Agendados](../../parallel/concrt/schedule-groups.md)
