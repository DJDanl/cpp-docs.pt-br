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
ms.openlocfilehash: e3a943ed52ce9653086203713bb98331f809314d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372721"
---
# <a name="concurrency-namespace-enums"></a>Enums do namespace de simultaneidade

||||
|-|-|-|
|[Agents_EventType](#agents_eventtype)|[ConcRT_EventType](#concrt_eventtype)|[Concrt_TraceFlags](#concrt_traceflags)|
|[CriticalRegionType](#criticalregiontype)|[DynamicProgressFeedbackType](#dynamicprogressfeedbacktype)|[PolicyElementKey](#policyelementkey)|
|[SchedulerType](#schedulertype)|[AgendamentoProtocoloType](#schedulingprotocoltype)|[ComutaçãoproxyState](#switchingproxystate)|
|[WinRTInitializationType](#winrtinitializationtype)|[agent_status](#agent_status)|[join_type](#join_type)|
|[message_status](#message_status)|[task_group_status](#task_group_status)|

## <a name="agent_status-enumeration"></a><a name="agent_status"></a>enumeração agent_status

Os estados válidos para um `agent`.

```cpp
enum agent_status;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`agent_canceled`|O `agent` foi cancelado.|
|`agent_created`|O `agent` foi criado, mas não começou.|
|`agent_done`|O `agent` acabado sem ser cancelado.|
|`agent_runnable`|O `agent` foi iniciado, mas `run` não entrou em seu método.|
|`agent_started`|O `agent` já começou.|

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Agentes Assíncronos](../../../parallel/concrt/asynchronous-agents.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt.h

## <a name="agents_eventtype-enumeration"></a><a name="agents_eventtype"></a>enumeração Agents_EventType

Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pela Biblioteca de Agentes

```cpp
enum Agents_EventType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`AGENTS_EVENT_CREATE`|Um tipo de evento que representa a criação de um objeto|
|`AGENTS_EVENT_DESTROY`|Um tipo de evento que representa a exclusão de um objeto|
|`AGENTS_EVENT_END`|Um tipo de evento que representa a conclusão de algum processamento|
|`AGENTS_EVENT_LINK`|Um tipo de evento que representa a vinculação de blocos de mensagens|
|`AGENTS_EVENT_NAME`|Um tipo de evento que representa o nome de um objeto|
|`AGENTS_EVENT_SCHEDULE`|Um tipo de evento que representa o agendamento de um processo|
|`AGENTS_EVENT_START`|Um tipo de evento que representa o início de algum processamento|
|`AGENTS_EVENT_UNLINK`|Um tipo de evento que representa a desvinculação de blocos de mensagens|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt.h

## <a name="concrt_eventtype-enumeration"></a><a name="concrt_eventtype"></a>ConcRT_EventType Enumeração

Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pelo Tempo de Execução de Concorrência.

```cpp
enum ConcRT_EventType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`CONCRT_EVENT_ATTACH`|Um tipo de evento que representa o ato de um anexo a um agendador.|
|`CONCRT_EVENT_BLOCK`|Um tipo de evento que representa o ato de um bloqueio de contexto.|
|`CONCRT_EVENT_DETACH`|Um tipo de evento que representa o ato de um desapego de um agendador.|
|`CONCRT_EVENT_END`|Um tipo de evento que marca o início de um par de eventos de início/fim.|
|`CONCRT_EVENT_GENERIC`|Um tipo de evento usado para eventos diversos.|
|`CONCRT_EVENT_IDLE`|Um tipo de evento que representa o ato de um contexto ficando ocioso.|
|`CONCRT_EVENT_START`|Um tipo de evento que marca o início de um par de eventos de início/fim.|
|`CONCRT_EVENT_UNBLOCK`|Um tipo de evento que representa o ato de desbloquear um contexto.|
|`CONCRT_EVENT_YIELD`|Um tipo de evento que representa o ato de um contexto rendendo.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt.h **Namespace:** concurrency

## <a name="concrt_traceflags-enumeration"></a><a name="concrt_traceflags"></a>enumeração Concrt_TraceFlags

Trace bandeiras para os tipos de eventos

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

**Cabeçalho:** concrt.h

## <a name="criticalregiontype-enumeration"></a><a name="criticalregiontype"></a>Enumeração criticalRegionType

O tipo de região crítica que um contexto está dentro.

```cpp
enum CriticalRegionType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`InsideCriticalRegion`|Indica que o contexto está dentro de uma região crítica. Quando dentro de uma região crítica, as suspensões assíncronas são escondidas do agendador. Caso essa suspensão aconteça, o Gerenciador de Recursos esperará que o segmento se torne executável e simplesmente retomá-lo em vez de invocar o agendador novamente. Quaisquer bloqueios tomados dentro de tal região devem ser tomados com extremo cuidado.|
|`InsideHyperCriticalRegion`|Indica que o contexto está dentro de uma região hipercrítica. Quando dentro de uma região hipercrítica, as suspensões síncronas e assíncronas são ocultas do agendador. Caso tal suspensão ou bloqueio aconteça, o gerenciador de recursos esperará que o segmento se torne executável e simplesmente retomá-lo em vez de invocar o agendador novamente. Bloqueios tomados dentro de tal região nunca devem ser compartilhados com código situado fora de tal região. Fazer isso causará um impasse imprevisível.|
|`OutsideCriticalRegion`|Indica que o contexto está fora de qualquer região crítica.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

## <a name="dynamicprogressfeedbacktype-enumeration"></a><a name="dynamicprogressfeedbacktype"></a>Enumeração dynamicProgressFeedbackType

Usado pela `DynamicProgressFeedback` política para descrever se os recursos para o agendador serão rebalanceados de acordo com informações estatísticas coletadas do agendador ou apenas com base em processadores virtuais que vão e saem do estado ocioso através de chamadas para os `Activate` métodos e `Deactivate` métodos na `IVirtualProcessorRoot` interface. Para obter mais informações sobre as políticas de agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).

```cpp
enum DynamicProgressFeedbackType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`ProgressFeedbackDisabled`|O agendador não reúne informações de progresso. O reequilíbrio é feito com base apenas no nível de assinatura do segmento de hardware subjacente. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource::CurrentSubscriptionLevel](IExecutionResource-structure.md).<br /><br /> Este valor é reservado para uso pelo tempo de execução.|
|`ProgressFeedbackEnabled`|O agendador reúne informações de progresso e as repassa para o gerenciador de recursos. O gerenciador de recursos utilizará essas informações estatísticas para reequilibrar os recursos em nome do agendador, além do nível de assinatura do segmento de hardware subjacente. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource::CurrentSubscriptionLevel](IExecutionResource-structure.md).|

## <a name="join_type-enumeration"></a><a name="join_type"></a>enumeração join_type

O tipo `join` de bloco de mensagens.

```cpp
enum join_type;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`greedy`|Bloqueios `join` gananciosos de mensagens aceitam imediatamente uma mensagem após a propagação. Isso é mais eficiente, mas tem a possibilidade de bloqueio ao vivo, dependendo da configuração da rede.|
|`non_greedy`|Blocos de `join` mensagens não gananciosos adiam mensagens e tentam consumi-las depois de todas terem chegado. Estes são garantidos para trabalhar, mas mais lento.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** agents.h

## <a name="message_status-enumeration"></a><a name="message_status"></a>enumeração message_status

As respostas válidas para `message` uma oferta de um objeto a um bloco.

```cpp
enum message_status;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`accepted`|O alvo aceitou a mensagem.|
|`declined`|O alvo não aceitou a mensagem.|
|`missed`|O alvo tentou aceitar a mensagem, mas ela não estava mais disponível.|
|`postponed`|O alvo adiou a mensagem.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** agents.h

## <a name="policyelementkey-enumeration"></a><a name="policyelementkey"></a>Enumeração PolicyElementKey

Chaves de política descrevendo aspectos do comportamento do agendador. Cada elemento de diretiva é descrito por um par de valor-chave. Para obter mais informações sobre políticas de agendadores e seu impacto nos agendadores, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).

```cpp
enum PolicyElementKey;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`ContextPriority`|A prioridade de segmento do sistema operacional de cada contexto no agendador. Se essa tecla for `INHERIT_THREAD_PRIORITY` definida para o valor, os contextos no agendador herdarão a prioridade do segmento que criou o agendador.<br /><br /> Valores válidos : Qualquer um `SetThreadPriority` dos valores válidos para a função Windows e o valor especial`INHERIT_THREAD_PRIORITY`<br /><br /> Valor padrão:`THREAD_PRIORITY_NORMAL`|
|`ContextStackSize`|O tamanho da pilha reservada de cada contexto no agendador em kilobytes.<br /><br /> Valores válidos : Inteiros positivos<br /><br /> Valor padrão `0`: , indicando que o valor padrão do processo para o tamanho da pilha seja usado.|
|`DynamicProgressFeedback`|Determina se os recursos do agendador serão rebalanceados de acordo com informações estatísticas coletadas do agendador ou apenas com base no nível de assinatura dos segmentos de hardware subjacentes. Para obter mais informações, consulte [DynamicProgressFeedbackType](#dynamicprogressfeedbacktype).<br /><br /> Valores válidos : `DynamicProgressFeedbackType` Um membro `ProgressFeedbackEnabled` da enumeração, ou`ProgressFeedbackDisabled`<br /><br /> Valor padrão:`ProgressFeedbackEnabled`|
|`LocalContextCacheSize`|Quando `SchedulingProtocol` a chave de diretiva `EnhanceScheduleGroupLocality`é definida como valor, isso especifica o número máximo de contextos executáveis permitidos para serem armazenados em cache por filas locais de processador virtual. Esses contextos normalmente serão executados em ordem LIFO (Última-in-first-out) no processador virtual que fez com que eles se tornassem executáveis. Observe que esta chave de `SchedulingProtocol` diretiva não tem `EnhanceForwardProgress`sentido quando a chave é definida como valor .<br /><br /> Valores válidos : Inteiros não negativos<br /><br /> Valor padrão:`8`|
|`MaxConcurrency`|O nível máximo de simultuável desejado pelo agendador. O gerenciador de recursos tentará inicialmente alocar tantos processadores virtuais. O valor especial [MaxExecutionResources](concurrency-namespace-constants1.md#maxexecutionresources) indica que o nível de concorrência desejado é o mesmo que o número de threads de hardware na máquina. Se o valor `MinConcurrency` especificado for for maior do que `MaxConcurrency` o número `MaxExecutionResources`de threads `MaxConcurrency` de hardware na máquina `MinConcurrency`e for especificado como , o valor para é aumentado para corresponder ao que está definido para .<br /><br /> Valores válidos : Inteiros positivos e o valor especial`MaxExecutionResources`<br /><br /> Valor padrão:`MaxExecutionResources`|
|`MaxPolicyElementKey`|A chave máxima do elemento de política. Não é uma chave de elemento válida.|
|`MinConcurrency`|O nível mínimo de simultuável que deve ser fornecido ao agendador pelo gerenciador de recursos. O número de processadores virtuais atribuídos a um agendador nunca ficará abaixo do mínimo. O valor especial [MaxExecutionResources](concurrency-namespace-constants1.md#maxexecutionresources) indica que o nível mínimo de concorrência é o mesmo que o número de threads de hardware na máquina. Se o valor `MaxConcurrency` especificado for for menor do que `MinConcurrency` o número `MaxExecutionResources`de threads `MinConcurrency` de hardware na máquina `MaxConcurrency`e for especificado como , o valor para é reduzido para corresponder ao que está definido para .<br /><br /> Valores válidos : Inteiros não negativos e o valor `MaxExecutionResources`especial . Observe que para políticas de agendador usadas para a construção `0` de agendadores de tempo de execução de concorrência, o valor é inválido.<br /><br /> Valor padrão:`1`|
|`SchedulerKind`|O tipo de threads que o agendador utilizará para contextos de execução subjacentes. Para obter mais informações, consulte [SchedulerType](#schedulertype).<br /><br /> Valores válidos : `SchedulerType` Um membro da enumeração, por exemplo,`ThreadScheduler`<br /><br /> Valor padrão `ThreadScheduler`: . Isso se traduz em threads Win32 em todos os sistemas operacionais.|
|`SchedulingProtocol`|Descreve qual algoritmo de agendamento será usado pelo agendador. Para obter mais informações, consulte [SchedulingProtocolType](#schedulingprotocoltype).<br /><br /> Valores válidos : `SchedulingProtocolType` Um membro `EnhanceScheduleGroupLocality` da enumeração, ou`EnhanceForwardProgress`<br /><br /> Valor padrão:`EnhanceScheduleGroupLocality`|
|`TargetOversubscriptionFactor`|Número provisório de processadores virtuais por segmento de hardware. O fator de superassinatura de destino pode ser aumentado `MaxConcurrency` pelo Gerenciador de Recursos, se necessário, para satisfazer com os segmentos de hardware na máquina.<br /><br /> Valores válidos : Inteiros positivos<br /><br /> Valor padrão:`1`|
|`WinRTInitialization`||

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt.h

## <a name="schedulertype-enumeration"></a><a name="schedulertype"></a>Enumeração do tipo agendador

Usado pela `SchedulerKind` diretiva para descrever o tipo de segmentos que o agendador deve utilizar para contextos de execução subjacentes. Para obter mais informações sobre as políticas de agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).

```cpp
enum SchedulerType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`ThreadScheduler`|Indica uma solicitação explícita de threads Win32 regulares.|
|`UmsThreadDefault`|Os threads de agendamento de modo de usuário (UMS) não são suportados no Tempo de Execução de Concurrency no Visual Studio 2013. Usar `UmsThreadDefault` como valor `SchedulerType` para a política não resultará em um erro. No entanto, um agendador criado com essa diretiva será padrão para usar os segmentos Win32.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt.h

## <a name="schedulingprotocoltype-enumeration"></a><a name="schedulingprotocoltype"></a>AgendamentoProtocolType Enumeração

Usado pela `SchedulingProtocol` política para descrever qual algoritmo de agendamento será utilizado para o agendador. Para obter mais informações sobre as políticas de agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).

```cpp
enum SchedulingProtocolType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`EnhanceForwardProgress`|O agendador prefere fazer round-robin através de grupos de agendamento após a execução de cada tarefa. Contextos desbloqueados são tipicamente programados de uma forma fifo (first-in-out). Os processadores virtuais não armazenam contextos desbloqueados.|
|`EnhanceScheduleGroupLocality`|O agendador prefere continuar a trabalhar em tarefas dentro do grupo de agendamento atual antes de passar para outro grupo de agendamento. Os contextos desbloqueados são armazenados em cache por processador virtual e são normalmente programados de uma forma LIFO (Última entrada em primeira) pelo processador virtual que os desbloqueou.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt.h

## <a name="switchingproxystate-enumeration"></a><a name="switchingproxystate"></a>Enumeração do proxystate de switching

Usado para denotar o estado em que um proxy de segmento está, quando ele está executando um switch de contexto cooperativo para um proxy de segmento diferente.

```cpp
enum SwitchingProxyState;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`Blocking`|Indica que o segmento de chamada está bloqueando cooperativamente e deve ser exclusivamente de propriedade do chamador até posteriormente executar novamente e realizar outra ação.|
|`Idle`|Indica que o segmento de chamada não é mais necessário pelo agendador e está sendo devolvido ao Gerenciador de Recursos. O contexto que estava sendo despachado não pode mais ser utilizado pelo Gerenciador de Recursos.|
|`Nesting`|Indica que o segmento de chamada está aninhando um agendador de crianças e é necessário pelo chamador, a fim de anexar a um agendador diferente.|

### <a name="remarks"></a>Comentários

Um parâmetro de `SwitchingProxyState` tipo é passado `IThreadProxy::SwitchTo` para o método para instruir o Gerenciador de recursos como tratar o proxy de thread que está fazendo a chamada.

Para obter mais informações sobre como esse tipo é usado, consulte [IThreadProxy::SwitchTo](ithreadproxy-structure.md#switchto).

## <a name="task_group_status-enumeration"></a><a name="task_group_status"></a>Enumeração task_group_status

Descreve o status de `task_group` `structured_task_group` execução de um ou objeto. Um valor desse tipo é devolvido por inúmeros métodos que aguardam tarefas programadas para um grupo de tarefas para ser concluído.

```cpp
enum task_group_status;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`canceled`|O `task_group` `structured_task_group` objeto foi cancelado. Uma ou mais tarefas podem não ter sido executadas.|
|`completed`|As tarefas enfileiradas para o `task_group` objeto ou `structured_task_group` objeto foram concluídas com sucesso.|
|`not_complete`|As tarefas enfileiradas ao `task_group` objeto não foram concluídas. Observe que este valor não é devolvido atualmente pelo Tempo de Execução de Concorrência.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** pplinterface.h

## <a name="winrtinitializationtype-enumeration"></a><a name="winrtinitializationtype"></a>Enumeração do tipo winRTinitializationtype

Usado pela `WinRTInitialization` política para descrever se e como o Windows Runtime será inicializado em threads de agendador para um aplicativo que é executado em sistemas operacionais com a versão Windows 8 ou superior. Para obter mais informações sobre as políticas de agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).

```cpp
enum WinRTInitializationType;
```

### <a name="values"></a>Valores

|Nome|Descrição|
|----------|-----------------|
|`DoNotInitializeWinRT`|Quando o aplicativo é executado em sistemas operacionais com a versão Windows 8 ou superior, os threads dentro do agendador não inicializarão o Tempo de Execução do Windows .|
|`InitializeWinRTAsMTA`|Quando o aplicativo é executado em sistemas operacionais com a versão Windows 8 ou superior, cada segmento dentro do agendador inicializará o Tempo de Execução do Windows e declarará que ele faz parte do apartamento multithreaded.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt.h

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)
