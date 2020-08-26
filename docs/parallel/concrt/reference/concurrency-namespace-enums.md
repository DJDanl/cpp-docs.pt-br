---
title: Enums do namespace de simultaneidade
ms.date: 11/04/2016
f1_keywords:
- CONCRT/concurrency::Agents_EventType
- CONCRT/concurrency::Concrt_TraceFlags
- CONCRT/concurrency::CriticalRegionType
- CONCRT/concurrency::PolicyElementKey
- CONCRT/concurrency::SchedulerType
- CONCRT/concurrency::SwitchingProxyState
- CONCRT/concurrency::WinRTInitializationType
- CONCRT/concurrency::join_type
- CONCRT/concurrency::message_status Enumeration
ms.assetid: a40e3b2d-ad21-4229-9880-2cfa84f7ab8f
ms.openlocfilehash: 8b9aec0a3464b921ca80f731ac4a3c26e72ef34e
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832237"
---
# <a name="concurrency-namespace-enums"></a>Enums do namespace de simultaneidade

:::row:::
   :::column span="":::
      [`agent_status`](#agent_status)\
      [`Agents_EventType`](#agents_eventtype)\
      [`ConcRT_EventType`](#concrt_eventtype)\
      [`Concrt_TraceFlags`](#concrt_traceflags)\
      [`CriticalRegionType`](#criticalregiontype)
   :::column-end:::
   :::column span="":::
      [`DynamicProgressFeedbackType`](#dynamicprogressfeedbacktype)\
      [`join_type`](#join_type)\
      [`message_status`](#message_status)\
      [`PolicyElementKey`](#policyelementkey)\
      [`SchedulerType`](#schedulertype)
   :::column-end:::
   :::column span="":::
      [`SchedulingProtocolType`](#schedulingprotocoltype)\
      [`SwitchingProxyState`](#switchingproxystate)\
      [`task_group_status`](#task_group_status)\
      [`WinRTInitializationType`](#winrtinitializationtype)
   :::column-end:::
:::row-end:::

## <a name="agent_status-enumeration"></a><a name="agent_status"></a> Enumeração de agent_status

Os Estados válidos para um `agent` .

```cpp
enum agent_status;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`agent_canceled`|O `agent` foi cancelado.|
|`agent_created`|O `agent` foi criado, mas não iniciado.|
|`agent_done`|O `agent` concluído sem ser cancelado.|
|`agent_runnable`|O `agent` foi iniciado, mas não inseriu seu `run` método.|
|`agent_started`|O `agent` foi iniciado.|

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [agentes assíncronos](../../../parallel/concrt/asynchronous-agents.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

## <a name="agents_eventtype-enumeration"></a><a name="agents_eventtype"></a> Enumeração de Agents_EventType

Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pela biblioteca de agentes

```cpp
enum Agents_EventType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`AGENTS_EVENT_CREATE`|Um tipo de evento que representa a criação de um objeto|
|`AGENTS_EVENT_DESTROY`|Um tipo de evento que representa a exclusão de um objeto|
|`AGENTS_EVENT_END`|Um tipo de evento que representa a conclusão de algum processamento|
|`AGENTS_EVENT_LINK`|Um tipo de evento que representa a vinculação de blocos de mensagem|
|`AGENTS_EVENT_NAME`|Um tipo de evento que representa o nome de um objeto|
|`AGENTS_EVENT_SCHEDULE`|Um tipo de evento que representa o agendamento de um processo|
|`AGENTS_EVENT_START`|Um tipo de evento que representa a inicialização de algum processamento|
|`AGENTS_EVENT_UNLINK`|Um tipo de evento que representa a desvinculação de blocos de mensagem|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

## <a name="concrt_eventtype-enumeration"></a><a name="concrt_eventtype"></a> Enumeração de ConcRT_EventType

Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pelo Tempo de Execução de Simultaneidade.

```cpp
enum ConcRT_EventType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`CONCRT_EVENT_ATTACH`|Um tipo de evento que representa o ato de uma anexação a um Agendador.|
|`CONCRT_EVENT_BLOCK`|Um tipo de evento que representa o ato de um bloqueio de contexto.|
|`CONCRT_EVENT_DETACH`|Um tipo de evento que representa o ato de uma desanexação de um Agendador.|
|`CONCRT_EVENT_END`|Um tipo de evento que marca o início de um par de eventos de início/término.|
|`CONCRT_EVENT_GENERIC`|Um tipo de evento usado para eventos diversos.|
|`CONCRT_EVENT_IDLE`|Um tipo de evento que representa o ato de um contexto ficar ocioso.|
|`CONCRT_EVENT_START`|Um tipo de evento que marca o início de um par de eventos de início/término.|
|`CONCRT_EVENT_UNBLOCK`|Um tipo de evento que representa o ato de desbloquear um contexto.|
|`CONCRT_EVENT_YIELD`|Um tipo de evento que representa o ato de um contexto que produz.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** namespace ConcRT. h **:** simultaneidade

## <a name="concrt_traceflags-enumeration"></a><a name="concrt_traceflags"></a> Enumeração de Concrt_TraceFlags

Sinalizadores de rastreamento para os tipos de evento

```cpp
enum Concrt_TraceFlags;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`AgentEventFlag`||
|`AllEventsFlag`||
|`ContextEventFlag`||
|`PPLEventFlag`||
|`ResourceManagerEventFlag`||
|`SchedulerEventFlag`||
|`VirtualProcessorEventFlag`||

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

## <a name="criticalregiontype-enumeration"></a><a name="criticalregiontype"></a> Enumeração CriticalRegionType

O tipo de região crítica em que um contexto está dentro.

```cpp
enum CriticalRegionType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`InsideCriticalRegion`|Indica que o contexto está dentro de uma região crítica. Quando dentro de uma região crítica, as suspensões assíncronas ficam ocultas do Agendador. Se tal suspensão ocorrer, o Gerenciador de recursos aguardará que o thread se torne executável e simplesmente o retomará em vez de invocar o Agendador novamente. Os bloqueios feitos dentro dessa região devem ser feitos com extrema atenção.|
|`InsideHyperCriticalRegion`|Indica que o contexto está dentro de uma região do Hyper-Critical. Quando dentro de uma região do Hyper-Critical, as suspensões síncrona e assíncrona ficam ocultas do Agendador. Caso tal suspensão ou bloqueio aconteça, o Gerenciador de recursos aguardará que o thread se torne executável e simplesmente o retomará em vez de invocar o Agendador novamente. Os bloqueios feitos dentro de uma região desse tipo nunca devem ser compartilhados com código em execução fora dessa região. Isso causará um deadlock imprevisível.|
|`OutsideCriticalRegion`|Indica que o contexto está fora de qualquer região crítica.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

## <a name="dynamicprogressfeedbacktype-enumeration"></a><a name="dynamicprogressfeedbacktype"></a> Enumeração DynamicProgressFeedbackType

Usado pela `DynamicProgressFeedback` política para descrever se os recursos do Agendador serão rebalanceados de acordo com as informações estatísticas coletadas do Agendador ou somente com base nos processadores virtuais que entram e saem do estado ocioso por meio de chamadas para os `Activate` `Deactivate` métodos e na `IVirtualProcessorRoot` interface. Para obter mais informações sobre as políticas do Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).

```cpp
enum DynamicProgressFeedbackType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`ProgressFeedbackDisabled`|O Agendador não coleta informações de progresso. O rebalanceamento é feito com base apenas no nível de assinatura do thread de hardware subjacente. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource:: CurrentSubscriptionLevel](IExecutionResource-structure.md).<br /><br /> Esse valor é reservado para uso pelo tempo de execução.|
|`ProgressFeedbackEnabled`|O Agendador reúne informações de progresso e as transmite para o Gerenciador de recursos. O Gerenciador de recursos utilizará essas informações estatísticas para reequilibrar recursos em nome do Agendador, além do nível de assinatura do thread de hardware subjacente. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource:: CurrentSubscriptionLevel](IExecutionResource-structure.md).|

## <a name="join_type-enumeration"></a><a name="join_type"></a> Enumeração de join_type

O tipo de um `join` bloco de mensagens.

```cpp
enum join_type;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`greedy`|Os `join` blocos de mensagens de ávido aceitam imediatamente uma mensagem após a propagação. Isso é mais eficiente, mas tem a possibilidade de bloqueio ao vivo, dependendo da configuração de rede.|
|`non_greedy`|Blocos de mensagens não-ávidos `join` adiam mensagens e as tentam e as utilizam depois que todas chegaram. Isso tem a garantia de funcionar, mas mais lento.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

## <a name="message_status-enumeration"></a><a name="message_status"></a> Enumeração de message_status

As respostas válidas para uma oferta de um `message` objeto a um bloco.

```cpp
enum message_status;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`accepted`|O destino aceitou a mensagem.|
|`declined`|O destino não aceitou a mensagem.|
|`missed`|O destino tentou aceitar a mensagem, mas ela não estava mais disponível.|
|`postponed`|O destino adie a mensagem.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

## <a name="policyelementkey-enumeration"></a><a name="policyelementkey"></a> Enumeração PolicyElementKey

Chaves de política que descrevem aspectos do comportamento do Agendador. Cada elemento de política é descrito por um par chave-valor. Para obter mais informações sobre as políticas do Agendador e seu impacto sobre os agendadores, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).

```cpp
enum PolicyElementKey;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`ContextPriority`|A prioridade de thread do sistema operacional de cada contexto no Agendador. Se essa chave for definida como o valor `INHERIT_THREAD_PRIORITY` , os contextos no Agendador herdarão a prioridade do thread que criou o Agendador.<br /><br /> Valores válidos: qualquer um dos valores válidos para a função do Windows `SetThreadPriority` e o valor especial `INHERIT_THREAD_PRIORITY`<br /><br /> Valor padrão: `THREAD_PRIORITY_NORMAL`|
|`ContextStackSize`|O tamanho da pilha reservada de cada contexto no Agendador em kilobytes.<br /><br /> Valores válidos: inteiros positivos<br /><br /> Valor padrão: `0` , indicando que o valor padrão do processo para o tamanho da pilha será usado.|
|`DynamicProgressFeedback`|Determina se os recursos do Agendador serão rebalanceados de acordo com as informações estatísticas coletadas do Agendador ou somente com base no nível de assinatura dos threads de hardware subjacentes. Para obter mais informações, consulte [DynamicProgressFeedbackType](#dynamicprogressfeedbacktype).<br /><br /> Valores válidos: um membro da `DynamicProgressFeedbackType` enumeração, `ProgressFeedbackEnabled` ou `ProgressFeedbackDisabled`<br /><br /> Valor padrão: `ProgressFeedbackEnabled`|
|`LocalContextCacheSize`|Quando a `SchedulingProtocol` chave de política é definida com o valor `EnhanceScheduleGroupLocality` , isso especifica o número máximo de contextos executáveis que podem ser armazenados em cache por filas locais de processador virtual. Esses contextos normalmente serão executados na ordem de UEPS (último a entrar, primeiro a sair) no processador virtual que os fez para se tornarem executáveis. Observe que essa chave de política não tem significado quando a `SchedulingProtocol` chave é definida com o valor `EnhanceForwardProgress` .<br /><br /> Valores válidos: inteiros não negativos<br /><br /> Valor padrão: `8`|
|`MaxConcurrency`|O nível máximo de simultaneidade desejado pelo Agendador. O Gerenciador de recursos tentará alocar inicialmente esse número de processadores virtuais. O valor especial [MaxExecutionResources](concurrency-namespace-constants1.md#maxexecutionresources) indica que o nível de simultaneidade desejado é o mesmo que o número de threads de hardware no computador. Se o valor especificado para `MinConcurrency` for maior que o número de threads de hardware no computador e `MaxConcurrency` for especificado como `MaxExecutionResources` , o valor de `MaxConcurrency` será gerado para corresponder ao que está definido para `MinConcurrency` .<br /><br /> Valores válidos: inteiros positivos e o valor especial `MaxExecutionResources`<br /><br /> Valor padrão: `MaxExecutionResources`|
|`MaxPolicyElementKey`|A chave de elemento de política máxima. Não é uma chave de elemento válida.|
|`MinConcurrency`|O nível mínimo de simultaneidade que deve ser fornecido ao agendador pelo Gerenciador de recursos. O número de processadores virtuais atribuídos a um Agendador nunca ficará abaixo do mínimo. O valor especial [MaxExecutionResources](concurrency-namespace-constants1.md#maxexecutionresources) indica que o nível de simultaneidade mínimo é igual ao número de threads de hardware no computador. Se o valor especificado para `MaxConcurrency` for menor que o número de threads de hardware no computador e `MinConcurrency` for especificado como `MaxExecutionResources` , o valor de `MinConcurrency` será reduzido para corresponder ao que está definido para `MaxConcurrency` .<br /><br /> Valores válidos: inteiros não negativos e o valor especial `MaxExecutionResources` . Observe que para as políticas do Agendador usadas para a construção de agendadores de Tempo de Execução de Simultaneidade, o valor `0` é inválido.<br /><br /> Valor padrão: `1`|
|`SchedulerKind`|O tipo de threads que o Agendador usará para contextos de execução subjacente. Para obter mais informações, consulte [SchedulerType](#schedulertype).<br /><br /> Valores válidos: um membro da `SchedulerType` enumeração, por exemplo, `ThreadScheduler`<br /><br /> Valor padrão: `ThreadScheduler` . Isso se traduz em threads Win32 em todos os sistemas operacionais.|
|`SchedulingProtocol`|Descreve qual algoritmo de agendamento será usado pelo Agendador. Para obter mais informações, consulte [SchedulingProtocolType](#schedulingprotocoltype).<br /><br /> Valores válidos: um membro da `SchedulingProtocolType` enumeração, `EnhanceScheduleGroupLocality` ou `EnhanceForwardProgress`<br /><br /> Valor padrão: `EnhanceScheduleGroupLocality`|
|`TargetOversubscriptionFactor`|Número provisório de processadores virtuais por thread de hardware. O fator de desassinatura de destino pode ser aumentado pelo Gerenciador de recursos, se necessário, para atender aos `MaxConcurrency` threads de hardware no computador.<br /><br /> Valores válidos: inteiros positivos<br /><br /> Valor padrão: `1`|
|`WinRTInitialization`||

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

## <a name="schedulertype-enumeration"></a><a name="schedulertype"></a> Enumeração SchedulerType

Usado pela `SchedulerKind` política para descrever o tipo de threads que o Agendador deve utilizar para contextos de execução subjacente. Para obter mais informações sobre as políticas do Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).

```cpp
enum SchedulerType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`ThreadScheduler`|Indica uma solicitação explícita de threads Win32 regulares.|
|`UmsThreadDefault`|Não há suporte para threads de modo de usuário agendáveis (UMS) no Tempo de Execução de Simultaneidade no Visual Studio 2013. O uso de `UmsThreadDefault` como um valor para a `SchedulerType` política não resultará em um erro. No entanto, um Agendador criado com essa política usará como padrão threads Win32.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

## <a name="schedulingprotocoltype-enumeration"></a><a name="schedulingprotocoltype"></a> Enumeração SchedulingProtocolType

Usado pela `SchedulingProtocol` política para descrever qual algoritmo de agendamento será utilizado para o Agendador. Para obter mais informações sobre as políticas do Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).

```cpp
enum SchedulingProtocolType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`EnhanceForwardProgress`|O Agendador prefere fazer Round-Robin por meio de grupos de agendamento depois de executar cada tarefa. Contextos desbloqueados normalmente são agendados de forma FIFO (primeiro a entrar, primeiro a sair). Os processadores virtuais não armazenam em cache contextos desbloqueados.|
|`EnhanceScheduleGroupLocality`|O Agendador prefere continuar a trabalhar nas tarefas do grupo de agendamento atual antes de passar para outro grupo de agendamento. Contextos desbloqueados são armazenados em cache por processador virtual e normalmente são agendados em uma maneira UEPS (último a entrar, primeiro a sair) pelo processador virtual que os desbloqueiam.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

## <a name="switchingproxystate-enumeration"></a><a name="switchingproxystate"></a> Enumeração SwitchingProxyState

Usado para indicar o estado em que um proxy de thread está, quando ele está executando um comutador de contexto cooperativo para um proxy de thread diferente.

```cpp
enum SwitchingProxyState;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`Blocking`|Indica que o thread de chamada é um bloqueio cooperativo e deve ser exclusivamente de Propriedade do chamador até que subsequentemente seja executado novamente e executando outra ação.|
|`Idle`|Indica que o thread de chamada não é mais necessário para o Agendador e está sendo retornado para o Gerenciador de recursos. O contexto que estava sendo expedido não pode mais ser utilizado pelo Gerenciador de recursos.|
|`Nesting`|Indica que o thread de chamada está aninhando um Agendador filho e é necessário para o chamador, a fim de anexá-lo a um Agendador diferente.|

### <a name="remarks"></a>Comentários

Um parâmetro do tipo `SwitchingProxyState` é passado para o método `IThreadProxy::SwitchTo` para instruir o Gerenciador de recursos como tratar o proxy de thread que está fazendo a chamada.

Para obter mais informações sobre como esse tipo é usado, consulte [IThreadProxy:: SwitchTo](ithreadproxy-structure.md#switchto).

## <a name="task_group_status-enumeration"></a><a name="task_group_status"></a> Enumeração de task_group_status

Descreve o status de execução de `task_group` um `structured_task_group` objeto ou. Um valor desse tipo é retornado por vários métodos que aguardam a conclusão das tarefas agendadas para um grupo de tarefas.

```cpp
enum task_group_status;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`canceled`|O `task_group` `structured_task_group` objeto ou foi cancelado. Uma ou mais tarefas podem não ter sido executadas.|
|`completed`|As tarefas enfileiradas para `task_group` o `structured_task_group` objeto ou foram concluídas com êxito.|
|`not_complete`|As tarefas enfileiradas para o `task_group` objeto não foram concluídas. Observe que esse valor não é retornado atualmente pelo Tempo de Execução de Simultaneidade.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** pplinterface. h

## <a name="winrtinitializationtype-enumeration"></a><a name="winrtinitializationtype"></a> Enumeração WinRTInitializationType

Usado pela `WinRTInitialization` política para descrever se e como o Windows Runtime será inicializado em threads do Agendador para um aplicativo que é executado em sistemas operacionais com a versão Windows 8 ou superior. Para obter mais informações sobre as políticas do Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).

```cpp
enum WinRTInitializationType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`DoNotInitializeWinRT`|Quando o aplicativo é executado em sistemas operacionais com a versão Windows 8 ou superior, os threads no Agendador não inicializarão o Windows Runtime.|
|`InitializeWinRTAsMTA`|Quando o aplicativo é executado em sistemas operacionais com a versão Windows 8 ou superior, cada thread dentro do Agendador inicializará o Windows Runtime e declarará que ele faz parte do apartamento multi-threaded.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
