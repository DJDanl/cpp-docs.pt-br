---
title: enumerações do namespace de simultaneidade
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
ms.openlocfilehash: d3eb49cd1555f23cc83efb0d8d912998295b3c55
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62337598"
---
# <a name="concurrency-namespace-enums"></a>enumerações do namespace de simultaneidade

||||
|-|-|-|
|[Agents_EventType](#agents_eventtype)|[ConcRT_EventType](#concrt_eventtype)|[Concrt_TraceFlags](#concrt_traceflags)|
|[CriticalRegionType](#criticalregiontype)|[DynamicProgressFeedbackType](#dynamicprogressfeedbacktype)|[PolicyElementKey](#policyelementkey)|
|[SchedulerType](#schedulertype)|[SchedulingProtocolType](#schedulingprotocoltype)|[SwitchingProxyState](#switchingproxystate)|
|[WinRTInitializationType](#winrtinitializationtype)|[agent_status](#agent_status)|[join_type](#join_type)|
|[message_status](#message_status)|[task_group_status](#task_group_status)|

##  <a name="agent_status"></a>  agent_status Enumeration

Os estados válidos para um `agent`.

```
enum agent_status;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`agent_canceled`|O `agent` foi cancelado.|
|`agent_created`|O `agent` foi criada, mas não foi iniciado.|
|`agent_done`|O `agent` encerrado sem que está sendo cancelada.|
|`agent_runnable`|O `agent` foi iniciado, mas não inseriu seu `run` método.|
|`agent_started`|O `agent` foi iniciada.|

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [agentes assíncronos](../../../parallel/concrt/asynchronous-agents.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

##  <a name="agents_eventtype"></a>  Enumeração Agents_EventType

Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pela biblioteca de agentes

```
enum Agents_EventType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`AGENTS_EVENT_CREATE`|Um tipo de evento que representa a criação de um objeto|
|`AGENTS_EVENT_DESTROY`|Um tipo de evento que representa a exclusão de um objeto|
|`AGENTS_EVENT_END`|Processamento de um tipo de evento que representa a conclusão de algumas|
|`AGENTS_EVENT_LINK`|Um tipo de evento que representa a vinculação de blocos de mensagem|
|`AGENTS_EVENT_NAME`|Um tipo de evento que representa o nome de um objeto|
|`AGENTS_EVENT_SCHEDULE`|Um tipo de evento que representa o agendamento de um processo|
|`AGENTS_EVENT_START`|Processamento de um tipo de evento que representa a inicialização de alguns|
|`AGENTS_EVENT_UNLINK`|Um tipo de evento que representa a separação dos blocos de mensagem|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

##  <a name="concrt_eventtype"></a>  ConcRT_EventType Enumeration

Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pelo tempo de execução de simultaneidade.

```
enum ConcRT_EventType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`CONCRT_EVENT_ATTACH`|Um tipo de evento que representa o ato de uma anexação a um agendador.|
|`CONCRT_EVENT_BLOCK`|Um tipo de evento que representa o ato de um contexto de bloqueio.|
|`CONCRT_EVENT_DETACH`|Um tipo de evento que representa o ato de uma desanexação de um agendador.|
|`CONCRT_EVENT_END`|Um tipo de evento que marca o início de um par de eventos de início/término.|
|`CONCRT_EVENT_GENERIC`|Um tipo de evento usado para diversos eventos.|
|`CONCRT_EVENT_IDLE`|Um tipo de evento que representa o ato de um contexto que se tornam ociosos.|
|`CONCRT_EVENT_START`|Um tipo de evento que marca o início de um par de eventos de início/término.|
|`CONCRT_EVENT_UNBLOCK`|Um tipo de evento que representa o ato de um contexto de desbloqueio.|
|`CONCRT_EVENT_YIELD`|Um tipo de evento que representa o ato de uma resposta de contexto.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h **Namespace:** simultaneidade

##  <a name="concrt_traceflags"></a>  Concrt_TraceFlags Enumeration

Sinalizadores de rastreamento para os tipos de evento

```
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

**Cabeçalho:** concrt. h

##  <a name="criticalregiontype"></a>  Enumeração CriticalRegionType

O tipo de um contexto está dentro de região crítica.

```
enum CriticalRegionType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`InsideCriticalRegion`|Indica que o contexto dentro de uma região crítica. Quando dentro de uma região crítica, suspensões assíncronas estão ocultos do Agendador. Se tal uma suspensão acontece, o Gerenciador de recursos aguardará o thread se torne executável e basta retomá-lo em vez de invocar o Agendador novamente. Quaisquer bloqueios dentro de tal região devem ser executados com extremo cuidado.|
|`InsideHyperCriticalRegion`|Indica que o contexto dentro de uma região hyper crítica. Quando dentro de uma região de hyper-crítica, suspensões síncronas e assíncronas estão ocultos do Agendador. Se tal uma suspensão ou bloqueio ocorrer, o Gerenciador de recursos aguardará o thread se torne executável e basta retomá-lo em vez de invocar o Agendador novamente. Bloqueios dentro de tal região nunca devem ser compartilhados com o código em execução fora de tal uma região. Isso fará com que o deadlock imprevisível.|
|`OutsideCriticalRegion`|Indica que o contexto está fora de qualquer região crítica.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

##  <a name="dynamicprogressfeedbacktype"></a>  DynamicProgressFeedbackType Enumeration

Usado pelo `DynamicProgressFeedback` com base em políticas para descrever se recursos para o Agendador serão redistribuídos de acordo com as informações estatísticas coletadas do Agendador ou apenas em processadores virtuais entrando e saindo do estado ocioso por meio de chamadas para o `Activate` e `Deactivate` métodos no `IVirtualProcessorRoot` interface. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).

```
enum DynamicProgressFeedbackType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`ProgressFeedbackDisabled`|O Agendador não coleta informações de progresso. O rebalanceamento é feito com base apenas no nível da assinatura do thread de hardware subjacente. Para obter mais informações sobre os níveis de assinatura, consulte [iexecutionresource:: Currentsubscriptionlevel](IExecutionResource-structure.md).<br /><br /> Esse valor é reservado para uso pelo tempo de execução.|
|`ProgressFeedbackEnabled`|O Agendador reúne informações sobre o andamento e o passa para o Gerenciador de recursos. O Gerenciador de recursos utilizará essas informações estatísticas para reequilibrar recursos em nome do Agendador além do nível de assinatura do thread de hardware subjacente. Para obter mais informações sobre os níveis de assinatura, consulte [iexecutionresource:: Currentsubscriptionlevel](IExecutionResource-structure.md).|

##  <a name="join_type"></a>  Enumeração join_type

O tipo de um `join` bloco de mensagem.

```
enum join_type;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`greedy`|Greedy `join` blocos de mensagens aceitam imediatamente uma mensagem após a propagação. Isso é mais eficiente, mas tem a possibilidade de live-lock, dependendo da configuração de rede.|
|`non_greedy`|Não greedy `join` blocos de mensagens adiar as mensagens e tente e consumi-los depois que todos tenham chegado. Eles são garantidos para funcionar, mas é mais lenta.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

##  <a name="message_status"></a>  Enumeração message_status

As respostas válidas para uma oferta de uma `message` objeto para um bloco.

```
enum message_status;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`accepted`|O destino aceitou a mensagem.|
|`declined`|O destino não aceitou a mensagem.|
|`missed`|O destino tentou aceitar a mensagem, mas ele não estava disponível.|
|`postponed`|O destino adiado a mensagem.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

##  <a name="policyelementkey"></a>  Enumeração PolicyElementKey

Chaves de política que descrevem aspectos do comportamento do Agendador. Cada elemento de política é descrito por um par chave-valor. Para obter mais informações sobre políticas de agendador e seu impacto em agendadores, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).

```
enum PolicyElementKey;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`ContextPriority`|A prioridade de thread do sistema operacional de cada contexto com o Agendador. Se essa chave for definida como o valor `INHERIT_THREAD_PRIORITY` os contextos no Agendador herdará a prioridade do thread que criou o Agendador.<br /><br /> Valores válidos: Qualquer um dos valores válidos para o Windows `SetThreadPriority` função e o valor especial `INHERIT_THREAD_PRIORITY`<br /><br /> Valor padrão: `THREAD_PRIORITY_NORMAL`|
|`ContextStackSize`|O tamanho da pilha reservado de cada contexto com o Agendador em quilobytes.<br /><br /> Valores válidos: Números inteiros positivos<br /><br /> Valor padrão: `0`, indicando que o valor de padrão do processo para o tamanho da pilha será usado.|
|`DynamicProgressFeedback`|Determina se os recursos para o Agendador serão redistribuídos de acordo com as informações estatísticas coletadas do Agendador ou apenas com base no nível de assinatura de threads de hardware subjacente. Para obter mais informações, consulte [DynamicProgressFeedbackType](#dynamicprogressfeedbacktype).<br /><br /> Valores válidos: Um membro do `DynamicProgressFeedbackType` enumeração, seja `ProgressFeedbackEnabled` ou `ProgressFeedbackDisabled`<br /><br /> Valor padrão: `ProgressFeedbackEnabled`|
|`LocalContextCacheSize`|Quando o `SchedulingProtocol` chave de política é definida como o valor `EnhanceScheduleGroupLocality`, isso Especifica o número máximo de executáveis contextos podem ser armazenados em cache por filas locais do processador virtual. Nesses contextos, normalmente serão executado na ordem do último a entrar, primeiro a sair (UEPS) no processador virtual que os causaram se torne executável. Observe que essa chave de política não tem nenhum que significa que quando o `SchedulingProtocol` chave é definida como o valor `EnhanceForwardProgress`.<br /><br /> Valores válidos: Inteiros não negativos<br /><br /> Valor padrão: `8`|
|`MaxConcurrency`|O nível desejada pelo Agendador de simultaneidade máximo. O Gerenciador de recursos tentará alocar inicialmente este número de processadores virtuais. O valor especial [MaxExecutionResources](concurrency-namespace-constants1.md#maxexecutionresources) indica que o nível de simultaneidade desejada é o mesmo que o número de threads de hardware no computador. Se o valor especificado para `MinConcurrency` é maior que o número de threads de hardware no computador e `MaxConcurrency` é especificado como `MaxExecutionResources`, o valor de `MaxConcurrency` é gerado para corresponder ao que está definido para `MinConcurrency`.<br /><br /> Valores válidos: Números inteiros positivos e o valor especial `MaxExecutionResources`<br /><br /> Valor padrão: `MaxExecutionResources`|
|`MaxPolicyElementKey`|A chave do elemento de diretiva máximo. Não é uma chave de elemento válido.|
|`MinConcurrency`|O nível de simultaneidade mínimo que deve ser fornecido para o Agendador pelo Gerenciador de recursos. O número de processadores virtuais atribuídos a um agendador nunca ficará abaixo do mínimo. O valor especial [MaxExecutionResources](concurrency-namespace-constants1.md#maxexecutionresources) indica que o nível de simultaneidade mínimo é o mesmo que o número de threads de hardware no computador. Se o valor especificado para `MaxConcurrency` é menor que o número de threads de hardware no computador e `MinConcurrency` é especificado como `MaxExecutionResources`, o valor de `MinConcurrency` será reduzida para corresponder ao que está definido para `MaxConcurrency`.<br /><br /> Valores válidos: Inteiros não negativos e o valor especial `MaxExecutionResources`. Observe que, para políticas de Agendador usadas para a construção de agendadores de tempo de execução de simultaneidade, o valor de `0` é inválido.<br /><br /> Valor padrão: `1`|
|`SchedulerKind`|O tipo de threads que utilizam o Agendador para contextos de execução subjacente. Para obter mais informações, consulte [SchedulerType](#schedulertype).<br /><br /> Valores válidos: Um membro do `SchedulerType` enumeração, por exemplo, `ThreadScheduler`<br /><br /> Valor padrão: `ThreadScheduler`. Isso se traduz em threads Win32 em todos os sistemas operacionais.|
|`SchedulingProtocol`|Descreve qual algoritmo de agendamento será usado pelo Agendador. Para obter mais informações, consulte [SchedulingProtocolType](#schedulingprotocoltype).<br /><br /> Valores válidos: Um membro do `SchedulingProtocolType` enumeração, seja `EnhanceScheduleGroupLocality` ou `EnhanceForwardProgress`<br /><br /> Valor padrão: `EnhanceScheduleGroupLocality`|
|`TargetOversubscriptionFactor`|Provisório número de processadores virtuais por thread de hardware. O fator de excesso de assinatura de destino pode ser aumentado pelo Gerenciador de recursos, se necessário, para satisfazer `MaxConcurrency` com os threads de hardware no computador.<br /><br /> Valores válidos: Números inteiros positivos<br /><br /> Valor padrão: `1`|
|`WinRTInitialization`||

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

##  <a name="schedulertype"></a>  Enumeração SchedulerType

Usado pelo `SchedulerKind` política para descrever o tipo de threads que o Agendador deve utilizar para contextos de execução subjacente. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).

```
enum SchedulerType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`ThreadScheduler`|Indica uma solicitação explícita de threads regulares do Win32.|
|`UmsThreadDefault`|Threads agendáveis no modo de usuário (UMS) não têm suporte no tempo de execução de simultaneidade no Visual Studio 2013. Usando o `UmsThreadDefault` como um valor para o `SchedulerType` política não resultará em erro. No entanto, um agendador criado com essa política padrão usando threads Win32.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

##  <a name="schedulingprotocoltype"></a>  Enumeração SchedulingProtocolType

Usado pelo `SchedulingProtocol` diretiva descrever qual algoritmo de agendamento será utilizado para o Agendador. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).

```
enum SchedulingProtocolType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`EnhanceForwardProgress`|O Agendador prefere round-robin por meio de grupos de agendamento depois de executar cada tarefa. Desbloqueado contextos são normalmente agendados de modo primeiro a entrar, primeiro a sair (PEPS). Processadores virtuais não armazenar em cache contextos desbloqueados.|
|`EnhanceScheduleGroupLocality`|Prefere o Agendador para continuar a trabalhar em tarefas dentro do grupo de agendamento atual antes de passar para outro grupo de agendas. Desbloqueado contextos são armazenadas em cache por processador virtual e normalmente são agendados de uma forma do último a entrar, primeiro a sair (UEPS) por processador virtual que desbloqueá-los.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

##  <a name="switchingproxystate"></a>  Enumeração SwitchingProxyState

Usado para indicar o estado de em que um proxy de thread está, quando ele está executando uma alternância de contexto cooperativo para um proxy de thread diferente.

```
enum SwitchingProxyState;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`Blocking`|Indica que o thread de chamada está bloqueando de forma cooperativa e deve ser exclusivamente adquirido pelo chamador até que, posteriormente, executando novamente e executar outra ação.|
|`Idle`|Indica que o thread de chamada não for mais necessário pelo Agendador e está sendo retornado para o Gerenciador de recursos. O contexto que estava sendo despachado não é mais capaz de ser utilizado pelo Gerenciador de recursos.|
|`Nesting`|Indica que o thread de chamada é aninhando um agendador filho e é necessário pelo chamador, para anexar a um agendador diferente.|

### <a name="remarks"></a>Comentários

Um parâmetro do tipo `SwitchingProxyState` é passada para o método `IThreadProxy::SwitchTo` para instruir o Gerenciador de recursos como tratar o proxy de thread que está fazendo a chamada.

Para obter mais informações sobre como esse tipo é usado, consulte [ithreadproxy:: Switchto](ithreadproxy-structure.md#switchto).

##  <a name="task_group_status"></a>  task_group_status Enumeration

Descreve o status de execução de um `task_group` ou `structured_task_group` objeto. Um valor desse tipo é retornado por vários métodos que esperam que tarefas agendadas para um grupo de tarefas para concluir.

```
enum task_group_status;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`canceled`|O `task_group` ou `structured_task_group` objeto foi cancelado. Não podem ter executado uma ou mais tarefas.|
|`completed`|As tarefas enfileiradas para o `task_group` ou `structured_task_group` objeto foi concluído com êxito.|
|`not_complete`|As tarefas enfileiradas para o `task_group` objeto não foram concluídos. Observe que esse valor não é retornado no momento pelo tempo de execução de simultaneidade.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** pplinterface. h

##  <a name="winrtinitializationtype"></a>  Enumeração WinRTInitializationType

Usado pelo `WinRTInitialization` política para descrever se e como o tempo de execução do Windows será inicializado em segmentos de Agendador para um aplicativo que é executado em sistemas operacionais com a versão Windows 8 ou superior. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).

```
enum WinRTInitializationType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`DoNotInitializeWinRT`|Quando o aplicativo é executado nos sistemas operacionais com a versão Windows 8 ou superior, threads dentro do Agendador não inicializarão o tempo de execução do Windows.|
|`InitializeWinRTAsMTA`|Quando o aplicativo é executado em sistemas operacionais com a versão Windows 8 ou superior, cada thread dentro do Agendador inicializará o tempo de execução do Windows e declarará que ele faz parte do apartamento de vários threads.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
