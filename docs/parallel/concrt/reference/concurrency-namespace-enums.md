---
title: "enumerações de namespace de simultaneidade | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs:
- C++
ms.assetid: a40e3b2d-ad21-4229-9880-2cfa84f7ab8f
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 7589f0054e9393f938bf69d4e1751202cbc02456
ms.lasthandoff: 03/17/2017

---
# <a name="concurrency-namespace-enums"></a>enumerações de namespace de simultaneidade
||||  
|-|-|-|  
|[Agents_EventType](#agents_eventtype)|[ConcRT_EventType](#concrt_eventtype)|[Concrt_TraceFlags](#concrt_traceflags)|  
|[CriticalRegionType](#criticalregiontype)|[DynamicProgressFeedbackType](#dynamicprogressfeedbacktype)|[PolicyElementKey](#policyelementkey)|  
|[SchedulerType](#schedulertype)|[SchedulingProtocolType](#schedulingprotocoltype)|[SwitchingProxyState](#switchingproxystate)|  
|[WinRTInitializationType](#winrtinitializationtype)|[agent_status](#agent_status)|[join_type](#join_type)|  
|[message_status](#message_status)|[task_group_status](#task_group_status)|  
  
##  <a name="agent_status"></a>Enumeração agent_status  
 Os estados válidos para um `agent`.  
  
```
enum agent_status;
```  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`agent_canceled`|O `agent` foi cancelado.|  
|`agent_created`|O `agent` foi criado, mas não foi iniciado.|  
|`agent_done`|O `agent` concluída sem que está sendo cancelada.|  
|`agent_runnable`|O `agent` foi iniciado, mas não inseriu seu `run` método.|  
|`agent_started`|O `agent` foi iniciado.|  

### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [agentes assíncronos](../../../parallel/concrt/asynchronous-agents.md).  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h

##  <a name="agents_eventtype"></a>Enumeração Agents_EventType  
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
|`AGENTS_EVENT_LINK`|Um tipo de evento que representa a vinculação de blocos de mensagens|  
|`AGENTS_EVENT_NAME`|Um tipo de evento que representa o nome de um objeto|  
|`AGENTS_EVENT_SCHEDULE`|Um tipo de evento que representa o agendamento de um processo|  
|`AGENTS_EVENT_START`|Processamento de um tipo de evento que representa o início de alguns|  
|`AGENTS_EVENT_UNLINK`|Um tipo de evento que representa a desvinculação de blocos de mensagens|  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h

##  <a name="concrt_eventtype"></a>Enumeração ConcRT_EventType  
 Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pelo tempo de execução de simultaneidade.  
  
```
enum ConcRT_EventType;
```  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CONCRT_EVENT_ATTACH`|Um tipo de evento que representa o ato de uma anexação a um agendador.|  
|`CONCRT_EVENT_BLOCK`|Um tipo de evento que representa o ato de um bloqueio de contexto.|  
|`CONCRT_EVENT_DETACH`|Um tipo de evento que representa o ato de uma desanexação de um agendador.|  
|`CONCRT_EVENT_END`|Um tipo de evento que marca o início de um par de eventos de início/término.|  
|`CONCRT_EVENT_GENERIC`|Um tipo de evento usado para diversos eventos.|  
|`CONCRT_EVENT_IDLE`|Um tipo de evento que representa o ato de um contexto se tornam ociosos.|  
|`CONCRT_EVENT_START`|Um tipo de evento que marca o início de um par de eventos de início/término.|  
|`CONCRT_EVENT_UNBLOCK`|Um tipo de evento que representa o ato de um contexto de desbloqueio.|  
|`CONCRT_EVENT_YIELD`|Um tipo de evento que representa o ato de produzindo um contexto.|  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  **Namespace:** simultaneidade

##  <a name="concrt_traceflags"></a>Enumeração Concrt_TraceFlags  
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
 **Cabeçalho:** concrt.h

##  <a name="criticalregiontype"></a>Enumeração CriticalRegionType  
 O tipo de região crítica, que um contexto está dentro.  
  
```
enum CriticalRegionType;
```  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`InsideCriticalRegion`|Indica que o contexto dentro de uma região crítica. Quando dentro de uma região crítica, suspensões assíncronas ficam ocultos do Agendador. Se uma suspensão acontece, o Gerenciador de recursos aguardará o segmento executável e basta retomá-lo em vez de chamar o Agendador novamente. Qualquer bloqueios dentro de tal região devem ser executados com muito cuidado.|  
|`InsideHyperCriticalRegion`|Indica que o contexto dentro de uma região hyper-crítica. Quando dentro de uma região hyper-crítica, suspensões síncronas e assíncronas estão ocultos do Agendador. Deve uma suspensão ou bloqueando acontecer, o Gerenciador de recursos aguardará o segmento executável e basta retomá-lo em vez de chamar o Agendador novamente. Bloqueios dentro de tal região nunca devem ser compartilhados com o código em execução fora de tal região. Isso fará com que o bloqueio imprevisível.|  
|`OutsideCriticalRegion`|Indica que o contexto está fora de qualquer região crítica.|  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h 

##  <a name="dynamicprogressfeedbacktype"></a>Enumeração DynamicProgressFeedbackType  
 Usado pelo `DynamicProgressFeedback` baseado em políticas para descrever se recursos para o Agendador serão balanceados acordo com informações estatísticas coletadas do Agendador ou apenas em processadores virtuais sai no estado ocioso por meio de chamadas para o `Activate` e `Deactivate` métodos o `IVirtualProcessorRoot` interface. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).  
  
```
enum DynamicProgressFeedbackType;
```  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`ProgressFeedbackDisabled`|O Agendador não coleta informações sobre o andamento. Rebalanceamento é feita com base exclusivamente no nível de assinatura do thread de hardware subjacentes. Para obter mais informações sobre níveis de assinatura, consulte [Currentsubscriptionlevel](IExecutionResource-structure.md).<br /><br /> Esse valor é reservado para uso pelo tempo de execução.|  
|`ProgressFeedbackEnabled`|O Agendador reúne informações sobre o andamento e a transmite para o Gerenciador de recursos. O Gerenciador de recursos utilizará essas informações estatísticas para reequilibrar recursos em nome do Agendador além do nível de assinatura do thread de hardware subjacentes. Para obter mais informações sobre níveis de assinatura, consulte [Currentsubscriptionlevel](IExecutionResource-structure.md).|  
##  <a name="join_type"></a>Enumeração join_type  
 O tipo de um `join` bloco de mensagens.  
  
```
enum join_type;
```  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`greedy`|Greedy `join` blocos de mensagens aceitam imediatamente uma mensagem após a propagação. Isso é mais eficiente, mas tem a possibilidade de live-lock, dependendo da configuração de rede.|  
|`non_greedy`|Não greedy `join` blocos de mensagens adiar as mensagens e tente e consumi-los depois que todos tenham chegado. Esses são garantidas para funcionar, mas é mais lento.|  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  

##  <a name="message_status"></a>Enumeração message_status  
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
|`postponed`|O destino adiou a mensagem.|  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  

##  <a name="policyelementkey"></a>Enumeração PolicyElementKey  
 Chaves de política que descrevem aspectos do comportamento do Agendador. Cada elemento de diretiva é descrito por um par chave-valor. Para obter mais informações sobre políticas de agendador e seu impacto agendadores, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
```
enum PolicyElementKey;
```  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`ContextPriority`|A prioridade de thread do sistema operacional de cada contexto do Agendador. Se essa chave for definida como o valor `INHERIT_THREAD_PRIORITY` os contextos do Agendador herdará a prioridade do thread que criou o Agendador.<br /><br /> Valores válidos: qualquer um dos valores válidos para o Windows `SetThreadPriority` função e o valor especial`INHERIT_THREAD_PRIORITY`<br /><br /> Valor padrão:`THREAD_PRIORITY_NORMAL`|  
|`ContextStackSize`|O tamanho da pilha reservado de cada contexto do Agendador em quilobytes.<br /><br /> Valores válidos: inteiros positivos<br /><br /> Valor padrão: `0`, indicando que o valor padrão do processo para o tamanho da pilha será usado.|  
|`DynamicProgressFeedback`|Determina se os recursos para o Agendador serão balanceados acordo com informações estatísticas coletadas do Agendador ou apenas com base no nível de assinatura dos threads de hardware subjacentes. Para obter mais informações, consulte [DynamicProgressFeedbackType](#dynamicprogressfeedbacktype).<br /><br /> Valores válidos: membro do `DynamicProgressFeedbackType` enumeração, `ProgressFeedbackEnabled` ou`ProgressFeedbackDisabled`<br /><br /> Valor padrão:`ProgressFeedbackEnabled`|  
|`LocalContextCacheSize`|Quando o `SchedulingProtocol` chave de política é definida como o valor `EnhanceScheduleGroupLocality`, especifica o número máximo de contextos executáveis podem ser armazenados em cache por filas locais do processador virtual. Nesses contextos, normalmente serão executados na ordem do último a entrar, primeiro a sair (UEPS) no processador virtual que fez com que eles se tornem executável. Observe que essa chave de política não tem nenhum indicando quando o `SchedulingProtocol` chave é definida como o valor `EnhanceForwardProgress`.<br /><br /> Valores válidos: inteiros não negativos<br /><br /> Valor padrão:`8`|  
|`MaxConcurrency`|A concorrência máxima nível desejada pelo Agendador. O Gerenciador de recursos tentará alocar inicialmente este número de processadores virtuais. O valor especial [MaxExecutionResources](concurrency-namespace-constants1.md#maxexecutionresources) indica que o nível de simultaneidade desejado é igual ao número de threads de hardware no computador. Se o valor especificado para `MinConcurrency` é maior que o número de threads de hardware no computador e `MaxConcurrency` é especificado como `MaxExecutionResources`, o valor de `MaxConcurrency` é gerado para coincidir com o que é definido para `MinConcurrency`.<br /><br /> Valores válidos: inteiros positivos e o valor especial`MaxExecutionResources`<br /><br /> Valor padrão:`MaxExecutionResources`|  
|`MaxPolicyElementKey`|A chave de elemento de diretiva máximo. Não é uma chave de elemento válido.|  
|`MinConcurrency`|O nível de simultaneidade mínimo que deve ser fornecido ao Agendador pelo Gerenciador de recursos. O número de processadores virtuais atribuídos a um agendador nunca irá abaixo do mínimo. O valor especial [MaxExecutionResources](concurrency-namespace-constants1.md#maxexecutionresources) indica que o nível de simultaneidade mínimo é igual ao número de threads de hardware no computador. Se o valor especificado para `MaxConcurrency` é menor que o número de threads de hardware no computador e `MinConcurrency` é especificado como `MaxExecutionResources`, o valor de `MinConcurrency` é reduzido para coincidir com o que é definido para `MaxConcurrency`.<br /><br /> Valores válidos: inteiros não negativos e o valor especial `MaxExecutionResources`. Observe que, para políticas de Agendador usadas para a construção de agendadores de tempo de execução de simultaneidade, o valor de `0` é inválido.<br /><br /> Valor padrão:`1`|  
|`SchedulerKind`|O tipo de threads que utiliza o Agendador para contextos de execução subjacente. Para obter mais informações, consulte [SchedulerType](#schedulertype).<br /><br /> Valores válidos: membro o `SchedulerType` enumeração, por exemplo,`ThreadScheduler`<br /><br /> Valor padrão: `ThreadScheduler`. Isso se traduz em threads de Win32 em todos os sistemas operacionais.|  
|`SchedulingProtocol`|Descreve qual algoritmo de agendamento será usado pelo Agendador. Para obter mais informações, consulte [SchedulingProtocolType](#schedulingprotocoltype).<br /><br /> Valores válidos: membro do `SchedulingProtocolType` enumeração, `EnhanceScheduleGroupLocality` ou`EnhanceForwardProgress`<br /><br /> Valor padrão:`EnhanceScheduleGroupLocality`|  
|`TargetOversubscriptionFactor`|Provisório número de processadores virtuais por thread de hardware. O fator de excesso de assinatura de destino pode ser aumentado pelo Gerenciador de recursos, se necessário, para atender a `MaxConcurrency` com os threads de hardware no computador.<br /><br /> Valores válidos: inteiros positivos<br /><br /> Valor padrão:`1`|  
|`WinRTInitialization`||  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  

##  <a name="schedulertype"></a>Enumeração SchedulerType  
 Usado pelo `SchedulerKind` diretiva descrever o tipo de threads que o Agendador deve utilizar para contextos de execução subjacente. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).  
  
```
enum SchedulerType;
``` 

### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`ThreadScheduler`|Indica uma solicitação explícita de threads regulares do Win32.|  
|`UmsThreadDefault`|Threads do modo de usuário agendáveis (UMS) não têm suporte em tempo de execução de simultaneidade no Visual Studio 2013. Usando `UmsThreadDefault` como um valor para o `SchedulerType` política não resultará em um erro. No entanto, um agendador criado com essa política será padronizado para usar threads do Win32.|  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
##  <a name="schedulingprotocoltype"></a>Enumeração SchedulingProtocolType  
 Usado pelo `SchedulingProtocol` diretiva descrever qual algoritmo de agendamento será utilizado para o Agendador. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).  
  
```
enum SchedulingProtocolType;
```  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`EnhanceForwardProgress`|O Agendador prefere round robin por meio de grupos de agendamento depois de executar cada tarefa. Contextos desbloqueados normalmente são agendados de modo primeiro a entrar, primeiro a sair (PEPS). Processadores virtuais não desbloqueados contextos em cache.|  
|`EnhanceScheduleGroupLocality`|O Agendador prefere continuar a trabalhar em tarefas dentro do grupo de agendamento atual antes de passar para outro grupo de agendamento. Desbloqueado contextos são armazenadas em cache por processador virtual e normalmente são agendados de modo último a entrar, primeiro a sair (UEPS) por processador virtual que desbloqueá-los.|  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
 
##  <a name="switchingproxystate"></a>Enumeração SwitchingProxyState  
 Usada para indicar o estado de em que um proxy thread está, quando ele está em execução uma alternância de contexto cooperativo para proxy de um thread diferente.  
  
```
enum SwitchingProxyState;
```  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`Blocking`|Indica que o thread de chamada está bloqueando cooperativamente e deve ser exclusivamente pertence ao chamador até subsequentemente executando novamente e executar outra ação.|  
|`Idle`|Indica que o thread de chamada não for mais necessário pelo Agendador e está sendo retornado para o Gerenciador de recursos. O contexto que estava sendo enviado não é capaz de ser utilizado pelo Gerenciador de recursos.|  
|`Nesting`|Indica que o thread de chamada é aninhando um agendador filho e é necessário pelo chamador, para anexar a um agendador diferente.|  

### <a name="remarks"></a>Comentários  
 Um parâmetro de tipo `SwitchingProxyState` é passado para o método `IThreadProxy::SwitchTo` para instruir o Gerenciador de recursos como tratar o proxy thread que está fazendo a chamada.  
  
 Para obter mais informações sobre como esse tipo é usado, consulte [Ithreadproxy](ithreadproxy-structure.md#switchto).  
  
##  <a name="task_group_status"></a>Enumeração task_group_status  
 Descreve o status de execução de um `task_group` ou `structured_task_group` objeto. Um valor desse tipo é retornado por diversos métodos que aguardar as tarefas agendadas para um grupo de tarefas para concluir.  
  
```
enum task_group_status;
```  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`canceled`|O `task_group` ou `structured_task_group` objeto foi cancelado. Não podem ter executado uma ou mais tarefas.|  
|`completed`|As tarefas na fila para o `task_group` ou `structured_task_group` objeto foi concluído com êxito.|  
|`not_complete`|As tarefas na fila para o `task_group` objeto não foram concluídos. Observe que esse valor não é retornado no momento pelo tempo de execução de simultaneidade.|  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** pplinterface.h  

##  <a name="winrtinitializationtype"></a>Enumeração WinRTInitializationType  
 Usado pelo `WinRTInitialization` diretiva descrever se e como o tempo de execução do Windows será inicializado em threads de Agendador para um aplicativo que é executado em sistemas operacionais com a versão do Windows 8 ou superior. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md).  
  
```
enum WinRTInitializationType;
```  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`DoNotInitializeWinRT`|Quando o aplicativo é executado em sistemas operacionais com a versão do Windows 8 ou superior, segmentos no Agendador não inicializará o tempo de execução do Windows.|  
|`InitializeWinRTAsMTA`|Quando o aplicativo é executado em sistemas operacionais com a versão do Windows 8 ou superior, cada thread no Agendador inicializará o tempo de execução do Windows e declarar que ele faz parte de multithreaded apartment.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  

## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

