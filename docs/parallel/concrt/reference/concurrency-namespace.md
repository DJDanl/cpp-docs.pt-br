---
title: Namespace Concurrency
ms.date: 11/04/2016
f1_keywords:
- concurrent_priority_queue/concurrency
- agents/concurrency
- concurrent_vector/concurrency
- concrt/concurrency
- internal_split_ordered_list/concurrency
- concurrent_queue/concurrency
- pplcancellation_token/concurrency
- pplinterface/concurrency
- ppltasks/concurrency
- ppl/concurrency
- concurrent_unordered_map/concurrency
- concrtrm/concurrency
- concurrent_unordered_set/concurrency
- pplconcrt/concurrency
- internal_concurrent_hash/concurrency
helpviewer_keywords:
- Concurrency namespace
ms.assetid: f1d33ca2-679b-4442-b140-22a9d9df61d1
ms.openlocfilehash: 66c2e6e323ed9f12f30e9392ec7afe431fc2138b
ms.sourcegitcommit: e15b46ea7888dbdd7e0bb47da76aeed680c3c1f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/17/2020
ms.locfileid: "86446734"
---
# <a name="concurrency-namespace"></a>Namespace Concurrency

O namespace `Concurrency` oferece classes e funções que permitem que você acesse o Runtime de simultaneidade, uma estrutura de programação simultânea para C++. Para obter mais informações, consulte [Runtime de Simultaneidade](../../../parallel/concrt/concurrency-runtime.md).

## <a name="syntax"></a>Sintaxe

```cpp
namespace concurrency;
```

## <a name="members"></a>Membros

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|----------|-----------------|
|`runtime_object_identity`|Cada instância de mensagem tem uma identidade que a segue conforme é clonada e passada entre os componentes de mensagens. Esse não pode ser o endereço do objeto de mensagem.|
|`task_status`|Um tipo que representa o estado terminal de uma tarefa. Os valores válidos são `completed` e `canceled`.|
|`TaskProc`|Uma abstração elementar para uma tarefa, definida como `void (__cdecl * TaskProc)(void *)` . Um `TaskProc` é chamado para invocar o corpo de uma tarefa.|
|`TaskProc_t`|Uma abstração elementar para uma tarefa, definida como `void (__cdecl * TaskProc_t)(void *)` . Um `TaskProc` é chamado para invocar o corpo de uma tarefa.|

### <a name="classes"></a>Classes

|Nome|Descrição|
|----------|-----------------|
|[Classe affinity_partitioner](affinity-partitioner-class.md)|A `affinity_partitioner` classe é semelhante à `static_partitioner` classe, mas melhora a afinidade de cache por sua escolha de mapeamento de subintervalos para threads de trabalho. Ele pode melhorar significativamente o desempenho quando um loop é executado novamente no mesmo conjunto de dados e os dados se ajustam ao cache. Observe que o mesmo `affinity_partitioner` objeto deve ser usado com iterações subsequentes de um loop paralelo executado em um determinado conjunto de dados para se beneficiar da localidade dos dados.|
|[Classe de agente](agent-class.md)|Uma classe destinada a ser usada como classe base para todos os agentes independentes. Ele é usado para ocultar o estado de outros agentes e interagir com a passagem de mensagens.|
|[Classe auto_partitioner](auto-partitioner-class.md)|A `auto_partitioner` classe representa o método padrão `parallel_for` `parallel_for_each` e `parallel_transform` usa para particionar o intervalo de iteração. Esse método de particionamento emprega o furto de intervalo para balanceamento de carga, bem como o cancelamento por iteração.|
|[Classe bad_target](bad-target-class.md)|Essa classe descreve uma exceção gerada quando um bloco de mensagens recebe um ponteiro para um destino que é inválido para a operação que está sendo executada.|
|[Classe Call](call-class.md)|Um `call` bloco de mensagens é uma ordenação de várias fontes `target_block` que invoca uma função especificada ao receber uma mensagem.|
|[Classe cancellation_token](cancellation-token-class.md)|A `cancellation_token` classe representa a capacidade de determinar se alguma operação foi solicitada a cancelar. Um determinado token pode ser associado a um `task_group` , `structured_task_group` ou `task` para fornecer cancelamento implícito. Ele também pode ser sondado para cancelamento ou ter um retorno de chamada registrado para If e quando o associado `cancellation_token_source` for cancelado.|
|[Classe cancellation_token_registration](cancellation-token-registration-class.md)|A `cancellation_token_registration` classe representa uma notificação de retorno de chamada de um `cancellation_token` . Quando o `register` método em um `cancellation_token` é usado para receber a notificação de quando o cancelamento ocorre, um `cancellation_token_registration` objeto é retornado como um identificador para o retorno de chamada para que o chamador possa solicitar que um retorno de chamada específico não seja mais feito pelo uso do `deregister` método.|
|[Classe cancellation_token_source](cancellation-token-source-class.md)|A `cancellation_token_source` classe representa a capacidade de cancelar algumas operações canceláveis.|
|[Classe Choice](choice-class.md)|Um `choice` bloco de mensagens é um bloco de várias origens, de destino único, que representa uma interação de fluxo de controle com um conjunto de fontes. O bloco Choice aguardará que qualquer uma de várias fontes gere uma mensagem e propagará o índice da origem que produziu a mensagem.|
|[Classe combinável](combinable-class.md)|O `combinable<T>` objeto destina-se a fornecer cópias de dados de thread privado para executar subcoleções locais de thread sem bloqueio durante algoritmos paralelos. No final da operação paralela, os subcoleções thread-Private podem ser mesclados em um resultado final. Essa classe pode ser usada em vez de uma variável compartilhada e pode resultar em uma melhoria no desempenho se, de outra forma, houvesse muita contenção nessa variável compartilhada.|
|[Classe concurrent_priority_queue](concurrent-priority-queue-class.md)|A `concurrent_priority_queue` classe é um contêiner que permite que vários threads enviem itens por push e pop simultaneamente. Os itens são retirados em ordem de prioridade em que a prioridade é determinada por um functor fornecido como um argumento de modelo.|
|[Classe concurrent_queue](concurrent-queue-class.md)|A `concurrent_queue` classe é uma classe de contêiner de sequência que permite o acesso de primeiro a entrar, primeiro a sair para seus elementos. Ele permite um conjunto limitado de operações protegidas por simultaneidade, como `push` e `try_pop` .|
|[Classe concurrent_unordered_map](concurrent-unordered-map-class.md)|A `concurrent_unordered_map` classe é um contêiner protegido por simultaneidade que controla uma sequência de comprimento variável de elementos do tipo `std::pair<const K, _Element_type>` . A sequência é representada de uma maneira que permite acréscimo seguro de simultaneidade, acesso a elemento, acesso de iterador e operações de percurso de iterador.|
|[Classe concurrent_unordered_multimap](concurrent-unordered-multimap-class.md)|A `concurrent_unordered_multimap` classe é um contêiner protegido por simultaneidade que controla uma sequência de comprimento variável de elementos do tipo `std::pair<const K, _Element_type>` . A sequência é representada de uma maneira que permite acréscimo seguro de simultaneidade, acesso a elementos, acesso iterador e operações de percurso de iterador.|
|[Classe concurrent_unordered_multiset](concurrent-unordered-multiset-class.md)|A `concurrent_unordered_multiset` classe é um contêiner protegido por simultaneidade que controla uma sequência de comprimento variável de elementos do tipo K. A sequência é representada de uma maneira que permite acréscimo seguro de simultaneidade, acesso a elementos, acesso iterador e operações de percurso de iterador.|
|[Classe concurrent_unordered_set](concurrent-unordered-set-class.md)|A `concurrent_unordered_set` classe é um contêiner protegido por simultaneidade que controla uma sequência de comprimento variável de elementos do tipo K. A sequência é representada de uma maneira que permite acréscimo seguro de simultaneidade, acesso a elementos, acesso iterador e operações de percurso de iterador.|
|[Classe concurrent_vector](concurrent-vector-class.md)|A `concurrent_vector` classe é uma classe de contêiner de sequência que permite o acesso aleatório a qualquer elemento. Ele permite acréscimo seguro de simultaneidade, acesso a elementos, acesso iterador e operações de percurso de iterador.|
|[Classe de contexto](context-class.md)|Representa uma abstração para um contexto de execução.|
|[Classe context_self_unblock](context-self-unblock-class.md)|Essa classe descreve uma exceção lançada quando o `Unblock` método de um `Context` objeto é chamado do mesmo contexto. Isso indica uma tentativa por um determinado contexto para desbloquear a si mesmo.|
|[Classe context_unblock_unbalanced](context-unblock-unbalanced-class.md)|Essa classe descreve uma exceção gerada quando chamadas para os `Block` `Unblock` métodos e de um `Context` objeto não são emparelhadas corretamente.|
|[Classe critical_section](critical-section-class.md)|Um mutex não reentrante que reconhece explicitamente o Tempo de Execução de Simultaneidade.|
|[Classe CurrentScheduler](currentscheduler-class.md)|Representa uma abstração para o Agendador atual associado ao contexto de chamada.|
|[Classe default_scheduler_exists](default-scheduler-exists-class.md)|Essa classe descreve uma exceção gerada quando o `Scheduler::SetDefaultSchedulerPolicy` método é chamado quando um agendador padrão já existe dentro do processo.|
|[Classe de evento](event-class.md)|Um evento de redefinição manual que reconhece explicitamente o Tempo de Execução de Simultaneidade.|
|[Classe improper_lock](improper-lock-class.md)|Essa classe descreve uma exceção gerada quando um bloqueio é adquirido de forma inadequada.|
|[Classe improper_scheduler_attach](improper-scheduler-attach-class.md)|Essa classe descreve uma exceção gerada quando o `Attach` método é chamado em um `Scheduler` objeto que já está anexado ao contexto atual.|
|[Classe improper_scheduler_detach](improper-scheduler-detach-class.md)|Essa classe descreve uma exceção gerada quando o `CurrentScheduler::Detach` método é chamado em um contexto que não foi anexado a nenhum Agendador usando o `Attach` método de um `Scheduler` objeto.|
|[Classe improper_scheduler_reference](improper-scheduler-reference-class.md)|Essa classe descreve uma exceção gerada quando o `Reference` método é chamado em um `Scheduler` objeto que está sendo desligado, de um contexto que não faz parte desse Agendador.|
|[Classe invalid_link_target](invalid-link-target-class.md)|Essa classe descreve uma exceção lançada quando o `link_target` método de um bloco de mensagens é chamado e o bloco de mensagens não é capaz de vincular ao destino. Isso pode ser o resultado de exceder o número de links que o bloco de mensagens é permitido ou tentar vincular um destino específico duas vezes à mesma fonte.|
|[Classe invalid_multiple_scheduling](invalid-multiple-scheduling-class.md)|Essa classe descreve uma exceção gerada quando um `task_handle` objeto é agendado várias vezes usando o `run` método de `task_group` um `structured_task_group` objeto ou sem uma chamada intermediária para os `wait` métodos ou `run_and_wait` .|
|[Classe invalid_operation](invalid-operation-class.md)|Essa classe descreve uma exceção lançada quando uma operação inválida é executada e não é mais precisamente descrita por outro tipo de exceção lançado pelo Tempo de Execução de Simultaneidade.|
|[Classe invalid_oversubscribe_operation](invalid-oversubscribe-operation-class.md)|Essa classe descreve uma exceção lançada quando o `Context::Oversubscribe` método é chamado com o `_BeginOversubscription` parâmetro definido como `false` sem uma chamada anterior ao `Context::Oversubscribe` método com o `_BeginOversubscription` parâmetro definido como `true` .|
|[Classe invalid_scheduler_policy_key](invalid-scheduler-policy-key-class.md)|Essa classe descreve uma exceção lançada quando uma chave inválida ou desconhecida é passada para um `SchedulerPolicy` Construtor de objeto ou o `SetPolicyValue` método de um `SchedulerPolicy` objeto é passado para uma chave que deve ser alterada usando outros meios, como o `SetConcurrencyLimits` método.|
|[Classe invalid_scheduler_policy_thread_specification](invalid-scheduler-policy-thread-specification-class.md)|Essa classe descreve uma exceção lançada quando é feita uma tentativa de definir os limites de simultaneidade de um `SchedulerPolicy` objeto de modo que o valor da `MinConcurrency` chave seja menor que o valor da `MaxConcurrency` chave.|
|[Classe invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md)|Essa classe descreve uma exceção gerada quando uma chave de política de um `SchedulerPolicy` objeto é definida como um valor inválido para essa chave.|
|[Classe as](isource-class.md)|A `ISource` classe é a interface para todos os blocos de origem. Os blocos de origem propagam mensagens para `ITarget` blocos.|
|[Classe ITarget](itarget-class.md)|A `ITarget` classe é a interface para todos os blocos de destino. Os blocos de destino consomem mensagens oferecidas por `ISource` blocos.|
|[Classe de junção](join-class.md)|Um `join` bloco de mensagens é um único destino, várias origens, ordenado, `propagator_block` que combina as mensagens do tipo `T` de cada uma de suas fontes.|
|[Classe de localização](location-class.md)|Uma abstração de um local físico no hardware.|
|[Classe de mensagem](message-class.md)|O envelope de mensagem básico que contém a carga de dados que está sendo passada entre os blocos de mensagens.|
|[Classe message_not_found](message-not-found-class.md)|Essa classe descreve uma exceção gerada quando um bloco de mensagens não consegue localizar uma mensagem solicitada.|
|[Classe message_processor](message-processor-class.md)|A `message_processor` classe é a classe base abstrata para o processamento de `message` objetos. Não há nenhuma garantia na ordenação das mensagens.|
|[Classe missing_wait](missing-wait-class.md)|Essa classe descreve uma exceção lançada quando há tarefas ainda agendadas para um `task_group` `structured_task_group` objeto ou no momento em que o destruidor do objeto é executado. Essa exceção nunca será gerada se o destruidor for atingido por causa de um desenrolamento de pilha como o resultado de uma exceção.|
|[Classe multi_link_registry](multi-link-registry-class.md)|O `multi_link_registry` objeto é um `network_link_registry` que gerencia vários blocos de origem ou vários blocos de destino.|
|[Classe multitype_join](multitype-join-class.md)|Um `multitype_join` bloco de mensagens é um bloco de mensagens de destino único de várias fontes que combina mensagens de tipos diferentes de cada uma de suas fontes e oferece uma tupla das mensagens combinadas para seus destinos.|
|[Classe nested_scheduler_missing_detach](nested-scheduler-missing-detach-class.md)|Essa classe descreve uma exceção gerada quando o Tempo de Execução de Simultaneidade detecta que você não chamou o `CurrentScheduler::Detach` método em um contexto anexado a um segundo Agendador usando o `Attach` método do `Scheduler` objeto.|
|[Classe network_link_registry](network-link-registry-class.md)|A `network_link_registry` classe base abstrata gerencia os links entre os blocos de origem e de destino.|
|[Classe operation_timed_out](operation-timed-out-class.md)|Essa classe descreve uma exceção lançada quando uma operação esgotou o tempo limite.|
|[Classe ordered_message_processor](ordered-message-processor-class.md)|Um `ordered_message_processor` é um `message_processor` que permite que os blocos de mensagens processem as mensagens na ordem em que foram recebidas.|
|[Classe overwrite_buffer](overwrite-buffer-class.md)|Um `overwrite_buffer` bloco de mensagens é um recurso de vários destinos, várias fontes, ordenado, `propagator_block` capaz de armazenar uma única mensagem por vez. Novas mensagens substituem as mantidas anteriormente.|
|[Classe progress_reporter](progress-reporter-class.md)|A classe de relator de andamento permite criar relatórios de notificações de andamento de um tipo específico. Cada objeto progress_reporter está associado a uma determinada ação ou operação assíncrona.|
|[Classe propagator_block](propagator-block-class.md)|A `propagator_block` classe é uma classe base abstrata para blocos de mensagens que são uma origem e um destino. Ele combina a funcionalidade das `source_block` `target_block` classes e.|
|[Classe reader_writer_lock](reader-writer-lock-class.md)|Um gravador-bloqueio de leitor baseado em fila de preferência de gravação com rotação somente local. O bloqueio concede o acesso PEPS (primeiro a entrar, primeiro a sair) a gravadores e priva os leitores em uma carga contínua de gravadores.|
|[Classe de agenda](schedulegroup-class.md)|Representa uma abstração para um grupo de agendamento. Os grupos de agendamento organizam um conjunto de trabalho relacionado que se beneficia de ser agendado de forma temporal, executando outra tarefa no mesmo grupo antes de passar para outro grupo, ou espacial, executando vários itens dentro do mesmo grupo no mesmo nó NUMA ou soquete físico.|
|[Classe do Agendador](scheduler-class.md)|Representa uma abstração para um Agendador de Tempo de Execução de Simultaneidade.|
|[Classe scheduler_not_attached](scheduler-not-attached-class.md)|Essa classe descreve uma exceção lançada quando uma operação é executada, o que exige que um Agendador seja anexado ao contexto atual e um não seja.|
|[Classe scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md)|Essa classe descreve uma exceção gerada devido a uma falha na aquisição de um recurso crítico no Tempo de Execução de Simultaneidade.|
|[Classe scheduler_worker_creation_error](scheduler-worker-creation-error-class.md)|Essa classe descreve uma exceção gerada devido a uma falha ao criar um contexto de execução de trabalho no Tempo de Execução de Simultaneidade.|
|[Classe SchedulerPolicy](schedulerpolicy-class.md)|A `SchedulerPolicy` classe contém um conjunto de pares chave/valor, um para cada elemento de política, que controla o comportamento de uma instância do Agendador.|
|[Classe simple_partitioner](simple-partitioner-class.md)|A `simple_partitioner` classe representa um particionamento estático do intervalo iterado por `parallel_for` . O particionador divide o intervalo em partes de forma que cada parte tenha pelo menos o número de iterações especificado pelo tamanho da parte.|
|[Classe single_assignment](single-assignment-class.md)|Um `single_assignment` bloco de mensagens é um recurso de vários destinos, várias fontes, ordenado, `propagator_block` capaz de armazenar um único, uma única gravação `message` .|
|[Classe single_link_registry](single-link-registry-class.md)|O `single_link_registry` objeto é um `network_link_registry` que gerencia apenas um único bloco de origem ou de destino.|
|[Classe source_block](source-block-class.md)|A `source_block` classe é uma classe base abstrata para blocos somente de origem. A classe fornece a funcionalidade básica de gerenciamento de link, bem como verificações de erro comuns.|
|[Classe source_link_manager](source-link-manager-class.md)|O `source_link_manager` objeto gerencia os links de rede do bloco de mensagens para `ISource` blocos.|
|[Classe static_partitioner](static-partitioner-class.md)|A `static_partitioner` classe representa um particionamento estático do intervalo iterado por `parallel_for` . O particionador divide o intervalo em tantas partes quanto há trabalhadores disponíveis para o Agendador subjacente.|
|[Classe structured_task_group](structured-task-group-class.md)|A `structured_task_group` classe representa uma coleção altamente estruturada de trabalho paralelo. Você pode enfileirar tarefas paralelas individuais para um `structured_task_group` usando `task_handle` objetos e esperar que elas sejam concluídas ou cancelar o grupo de tarefas antes de concluir a execução, o que anulará todas as tarefas que não começaram a execução.|
|[Classe target_block](target-block-class.md)|A `target_block` classe é uma classe base abstrata que fornece funcionalidade básica de gerenciamento de link e verificação de erros para blocos somente de destino.|
|[Classe Task (Tempo de Execução de Simultaneidade)](task-class.md)|A classe `task` da Biblioteca de Padrões Paralelos (PPL). O objeto `task` representa o trabalho que pode ser executado de forma assíncrona e simultaneamente com outras tarefas e o trabalho paralelo produzido por algoritmos paralelos no Runtime de simultaneidade. Produz um resultado de tipo `_ResultType` após uma conclusão bem-sucedida. Tarefas do tipo `task<void>` não produzem resultados. Uma tarefa pode ser aguardada e cancelada independentemente de outras tarefas. Ela também pode ser composta por outras tarefas usando continuations(`then`) e os padrões join(`when_all`) e choice(`when_any`).|
|[Classe task_canceled](task-canceled-class.md)|Essa classe descreve uma exceção gerada pela camada de tarefas PPL para forçar a cancelamento da tarefa atual. Ele também é gerado pelo `get()` método na [tarefa](task-class.md), para uma tarefa cancelada.|
|[Classe task_completion_event](task-completion-event-class.md)|A classe `task_completion_event` permite atrasar a execução de uma tarefa até que uma condição seja atendida, ou iniciar uma tarefa em resposta a um evento externo.|
|[Classe task_continuation_context](task-continuation-context-class.md)|A classe `task_continuation_context` permite que você especifique onde gostaria que uma continuação fosse executada. Só é útil usar essa classe de um aplicativo UWP. Para aplicativos não Windows Runtime, o contexto de execução da continuação da tarefa é determinado pelo tempo de execução e não é configurável.|
|[Classe task_group](task-group-class.md)|A `task_group` classe representa uma coleção de trabalho paralelo que pode ser aguardado ou cancelado.|
|[Classe task_handle](task-handle-class.md)|A `task_handle` classe representa um item de trabalho paralelo individual. Ele encapsula as instruções e os dados necessários para executar uma parte do trabalho.|
|[Classe task_options (Tempo de Execução de Simultaneidade)](task-options-class-concurrency-runtime.md)|Representa as opções permitidas para criar uma tarefa|
|[Classe Timer](timer-class.md)|Um `timer` bloco de mensagens é um único destino `source_block` capaz de enviar uma mensagem para seu destino após um período de tempo especificado ter decorrido ou em intervalos específicos.|
|[Classe de transformador](transformer-class.md)|Um `transformer` bloco de mensagens é um único destino, várias origens, ordenado, `propagator_block` que pode aceitar mensagens de um tipo e é capaz de armazenar um número não associado de mensagens de um tipo diferente.|
|[Classe unbounded_buffer](unbounded-buffer-class.md)|Um `unbounded_buffer` bloco de mensagens é um recurso de vários destinos, várias fontes, ordenado, `propagator_block` capaz de armazenar um número de mensagens não associado.|
|[Classe unsupported_os](unsupported-os-class.md)|Essa classe descreve uma exceção lançada quando um sistema operacional sem suporte é usado.|

### <a name="structures"></a>Estruturas

|Nome|Descrição|
|----------|-----------------|
|[Estrutura DispatchState](dispatchstate-structure.md)|A `DispatchState` estrutura é usada para transferir o estado para o `IExecutionContext::Dispatch` método. Ele descreve as circunstâncias sob as quais o `Dispatch` método é invocado em uma `IExecutionContext` interface.|
|[Estrutura IExecutionContext](iexecutioncontext-structure.md)|Uma interface para um contexto de execução que pode ser executado em um determinado processador virtual e ser alternado por contexto de forma cooperativa.|
|[Estrutura IExecutionResource](iexecutionresource-structure.md)|Uma abstração para um thread de hardware.|
|[Estrutura IResourceManager](iresourcemanager-structure.md)|Uma interface para o Gerenciador de recursos do Tempo de Execução de Simultaneidade. Essa é a interface pela qual os agendadores se comunicam com o Gerenciador de recursos.|
|[Estrutura IScheduler](ischeduler-structure.md)|Uma interface para uma abstração de um Agendador de trabalho. O Gerenciador de recursos do Tempo de Execução de Simultaneidade usa essa interface para se comunicar com agendadores de trabalho.|
|[Estrutura ISchedulerProxy](ischedulerproxy-structure.md)|A interface pela qual os agendadores se comunicam com o Gerenciador de recursos do Tempo de Execução de Simultaneidade para negociar a alocação de recursos.|
|[Estrutura IThreadProxy](ithreadproxy-structure.md)|Uma abstração para um thread de execução. Dependendo da `SchedulerType` chave de política do Agendador que você criar, o Gerenciador de recursos lhe concederá um proxy de thread que é apoiado por um Thread Win32 regular ou um thread de agendáveis (UMS) de modo de usuário. Os threads UMS têm suporte em sistemas operacionais de 64 bits com a versão Windows 7 e superior.|
|[Estrutura ITopologyExecutionResource](itopologyexecutionresource-structure.md)|Uma interface para um recurso de execução, conforme definido pelo Gerenciador de recursos.|
|[Estrutura ITopologyNode](itopologynode-structure.md)|Uma interface para um nó de topologia, conforme definido pelo Gerenciador de recursos. Um nó contém um ou mais recursos de execução.|
|[Estrutura IUMSCompletionList](iumscompletionlist-structure.md)|Representa uma lista de conclusão de UMS. Quando um thread UMS é bloqueado, o contexto de agendamento designado do Agendador é expedido para tomar uma decisão do que deve ser agendado na raiz do processador virtual subjacente enquanto o thread original é bloqueado. Quando o thread original é desbloqueado, o sistema operacional o enfileira na lista de conclusão que é acessível por essa interface. O Agendador pode consultar a lista de conclusão no contexto de agendamento designado ou em qualquer outro lugar em que ele procura trabalho.|
|[Estrutura IUMSScheduler](iumsscheduler-structure.md)|Uma interface para uma abstração de um Agendador de trabalho que deseja que o Gerenciador de recursos do Tempo de Execução de Simultaneidade acesse os threads de agendáveis (UMS) do modo de usuário. O Gerenciador de recursos usa essa interface para se comunicar com agendadores de threads UMS. A interface `IUMSScheduler` herda da interface `IScheduler` .|
|[Estrutura IUMSThreadProxy](iumsthreadproxy-structure.md)|Uma abstração para um thread de execução. Se você quiser que o Agendador receba threads de agendáveis (UMS) de modo de usuário, defina o valor para o elemento de política do Agendador `SchedulerKind` como `UmsThreadDefault` e implemente a `IUMSScheduler` interface. Os threads UMS têm suporte apenas em sistemas operacionais de 64 bits com versão Windows 7 e superior.|
|[Estrutura IUMSUnblockNotification](iumsunblocknotification-structure.md)|Representa uma notificação do Gerenciador de recursos que um proxy de thread que bloqueou e disparou um retorno ao contexto de agendamento designado do Agendador foi desbloqueado e está pronto para ser agendado. Essa interface é inválida quando o contexto de execução associado do proxy de thread, retornado do `GetContext` método, é reagendado.|
|[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)|Uma abstração para um thread de hardware no qual um proxy de thread pode ser executado.|
|[Estrutura scheduler_interface](scheduler-interface-structure.md)|Interface do Agendador|
|[Estrutura scheduler_ptr (Runtime de Simultaneidade)](scheduler-ptr-structure-concurrency-runtime.md)|Representa um ponteiro para um Agendador. Essa classe existe para permitir a especificação de um tempo de vida compartilhado usando shared_ptr ou apenas uma referência simples usando ponteiro bruto.|

### <a name="enumerations"></a>Enumerações

|Nome|Descrição|
|----------|-----------------|
|[agent_status](concurrency-namespace-enums.md#agent_status)|Os Estados válidos para um `agent` .|
|[Agents_EventType](concurrency-namespace-enums.md#agents_eventtype)|Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pela biblioteca de agentes|
|[ConcRT_EventType](concurrency-namespace-enums.md#concrt_eventtype)|Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pelo Tempo de Execução de Simultaneidade.|
|[Concrt_TraceFlags](concurrency-namespace-enums.md#concrt_traceflags)|Sinalizadores de rastreamento para os tipos de evento|
|[CriticalRegionType](concurrency-namespace-enums.md#criticalregiontype)|O tipo de região crítica em que um contexto está dentro.|
|[DynamicProgressFeedbackType](concurrency-namespace-enums.md#dynamicprogressfeedbacktype)|Usado pela `DynamicProgressFeedback` política para descrever se os recursos do Agendador serão rebalanceados de acordo com as informações estatísticas coletadas do Agendador ou somente com base nos processadores virtuais que entram e saem do estado ocioso por meio de chamadas para os `Activate` `Deactivate` métodos e na `IVirtualProcessorRoot` interface. Para obter mais informações sobre as políticas do Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md#policyelementkey).|
|[join_type](concurrency-namespace-enums.md#join_type)|O tipo de um `join` bloco de mensagens.|
|[message_status](concurrency-namespace-enums.md#message_status)|As respostas válidas para uma oferta de um `message` objeto a um bloco.|
|[PolicyElementKey](concurrency-namespace-enums.md#policyelementkey)|Chaves de política que descrevem aspectos do comportamento do Agendador. Cada elemento de política é descrito por um par chave-valor. Para obter mais informações sobre as políticas do Agendador e seu impacto sobre os agendadores, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).|
|[SchedulerType](concurrency-namespace-enums.md#schedulertype)|Usado pela `SchedulerKind` política para descrever o tipo de threads que o Agendador deve utilizar para contextos de execução subjacente. Para obter mais informações sobre as políticas do Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md#policyelementkey).|
|[SchedulingProtocolType](concurrency-namespace-enums.md#schedulingprotocoltype)|Usado pela `SchedulingProtocol` política para descrever qual algoritmo de agendamento será utilizado para o Agendador. Para obter mais informações sobre as políticas do Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md#policyelementkey).|
|[SwitchingProxyState](concurrency-namespace-enums.md#switchingproxystate)|Usado para indicar o estado em que um proxy de thread está, quando ele está executando um comutador de contexto cooperativo para um proxy de thread diferente.|
|[task_group_status](concurrency-namespace-enums.md#task_group_status)|Descreve o status de execução de `task_group` um `structured_task_group` objeto ou. Um valor desse tipo é retornado por vários métodos que aguardam a conclusão das tarefas agendadas para um grupo de tarefas.|
|[WinRTInitializationType](concurrency-namespace-enums.md#winrtinitializationtype)|Usado pela `WinRTInitialization` política para descrever se e como o Windows Runtime será inicializado em threads do Agendador para um aplicativo que é executado em sistemas operacionais com a versão Windows 8 ou superior. Para obter mais informações sobre as políticas do Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md#policyelementkey).|

### <a name="functions"></a>Funções

|Nome|Descrição|
|----------|-----------------|
|[Função Alloc](concurrency-namespace-functions.md#alloc)|Aloca um bloco de memória do tamanho especificado no subalocador de cache Tempo de Execução de Simultaneidade.|
|[Função asend](concurrency-namespace-functions.md#asend)|Sobrecarregado. Uma operação Send assíncrona, que agenda uma tarefa para propagar os dados para o bloco de destino.|
|[Função cancel_current_task](concurrency-namespace-functions.md#cancel_current_task)|Cancela a tarefa atualmente em execução. Essa função pode ser chamada de dentro do corpo de uma tarefa para interromper a execução da tarefa e fazer com que ela entre no estado `canceled`.<br /><br /> Não é um cenário com suporte para chamar essa função se você não estiver dentro do corpo de uma `task`. Isso resultará em um comportamento indefinido, como uma falha ou uma falta de resposta em seu aplicativo.|
|[Função create_async](concurrency-namespace-functions.md#create_async)|Cria uma construção assíncrona de Windows Runtime com base em um objeto de função ou lambda fornecido pelo usuário. O tipo de retorno de `create_async` é `IAsyncAction^`, `IAsyncActionWithProgress<TProgress>^`, `IAsyncOperation<TResult>^` ou `IAsyncOperationWithProgress<TResult, TProgress>^` com base na assinatura do lambda passada para o método.|
|[Função create_task](concurrency-namespace-functions.md#create_task)|Sobrecarregado. Cria um objeto de [tarefa](task-class.md) ppl. `create_task`pode ser usado em qualquer lugar em que você tenha usado um construtor de tarefa. Ele é fornecido principalmente por conveniência, pois permite o uso da `auto` palavra-chave durante a criação de tarefas.|
|[Função CreateResourceManager](concurrency-namespace-functions.md#createresourcemanager)|Retorna uma interface que representa a instância singleton do Gerenciador de recursos do Tempo de Execução de Simultaneidade. O Gerenciador de recursos é responsável por atribuir recursos a agendadores que desejam cooperar uns com os outros.|
|[Função DisableTracing](concurrency-namespace-functions.md#disabletracing)|Desabilita o rastreamento no Tempo de Execução de Simultaneidade. Essa função é preterida porque o rastreamento ETW tem o registro cancelado por padrão.|
|[Função EnableTracing](concurrency-namespace-functions.md#enabletracing)|Habilita o rastreamento no Tempo de Execução de Simultaneidade. Essa função foi preterida porque o rastreamento ETW agora está ativado por padrão.|
|[Função Free](concurrency-namespace-functions.md#free)|Libera um bloco de memória alocado anteriormente pelo `Alloc` método para o subalocador de cache tempo de execução de simultaneidade.|
|[Função get_ambient_scheduler (Tempo de Execução de Simultaneidade)](concurrency-namespace-functions.md#get_ambient_scheduler)||
|[Função GetExecutionContextId](concurrency-namespace-functions.md#getexecutioncontextid)|Retorna um identificador exclusivo que pode ser atribuído a um contexto de execução que implementa a `IExecutionContext` interface.|
|[Função GetOSVersion](concurrency-namespace-functions.md#getosversion)|Retorna a versão do sistema operacional.|
|[Função GetProcessorCount](concurrency-namespace-functions.md#getprocessorcount)|Retorna o número de threads de hardware no sistema subjacente.|
|[Função GetProcessorNodeCount](concurrency-namespace-functions.md#getprocessornodecount)|Retorna o número de nós NUMA ou pacotes de processador no sistema subjacente.|
|[Função GetSchedulerId](concurrency-namespace-functions.md#getschedulerid)|Retorna um identificador exclusivo que pode ser atribuído a um Agendador que implementa a `IScheduler` interface.|
|[Função interruption_point](concurrency-namespace-functions.md#interruption_point)|Cria um ponto de interrupção para o cancelamento. Se um cancelamento estiver em andamento no contexto em que essa função é chamada, isso gerará uma exceção interna que anula a execução do trabalho paralelo em execução no momento. Se o cancelamento não estiver em andamento, a função não fará nada.|
|[Função is_current_task_group_canceling](concurrency-namespace-functions.md#is_current_task_group_canceling)|Retorna uma indicação de se o grupo de tarefas que está atualmente em execução embutida no contexto atual está no meio de um cancelamento ativo (ou será em breve). Observe que, se não houver nenhum grupo de tarefas atualmente em execução embutido no contexto atual, `false` será retornado.|
|[Função make_choice](concurrency-namespace-functions.md#make_choice)|Sobrecarregado. Constrói um `choice` bloco de mensagens de um opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.|
|[Função make_greedy_join](concurrency-namespace-functions.md#make_greedy_join)|Sobrecarregado. Constrói um `greedy multitype_join` bloco de mensagens de um opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.|
|[Função make_join](concurrency-namespace-functions.md#make_join)|Sobrecarregado. Constrói um `non_greedy multitype_join` bloco de mensagens de um opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.|
|[Função make_task](concurrency-namespace-functions.md#make_task)|Um método de fábrica para criar um `task_handle` objeto.|
|[Função parallel_buffered_sort](concurrency-namespace-functions.md#parallel_buffered_sort)|Sobrecarregado. Organiza os elementos em um intervalo especificado em uma ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Essa função é semanticamente semelhante ao `std::sort` que é uma classificação baseada em comparação, instável, in-loco, exceto que precisa de `O(n)` espaço adicional, e requer a inicialização padrão para os elementos que estão sendo classificados.|
|[Função parallel_for](concurrency-namespace-functions.md#parallel_for)|Sobrecarregado. `parallel_for`itera em um intervalo de índices e executa uma função fornecida pelo usuário em cada iteração, em paralelo.|
|[Função parallel_for_each](concurrency-namespace-functions.md#parallel_for_each)|Sobrecarregado. `parallel_for_each`aplica uma função especificada para cada elemento dentro de um intervalo, em paralelo. É semanticamente equivalente à `for_each` função no `std` namespace, exceto que a iteração sobre os elementos é executada em paralelo e a ordem de iteração não é especificada. O argumento `_Func` deve dar suporte a um operador de chamada de função no formato `operator()(T)` em que o parâmetro `T` é o tipo de item do contêiner que está sendo iterado.|
|[Função parallel_invoke](concurrency-namespace-functions.md#parallel_invoke)|Sobrecarregado. Executa os objetos de função fornecidos como parâmetros em paralelo e os blocos até que tenham concluído a execução. Cada objeto de função pode ser uma expressão lambda, um ponteiro para função ou qualquer objeto que dê suporte ao operador de chamada de função com a assinatura `void operator()()` .|
|[Função parallel_radixsort](concurrency-namespace-functions.md#parallel_radixsort)|Sobrecarregado. Organiza os elementos em um intervalo especificado em uma ordem não decrescente usando um algoritmo de classificação de base. Essa é uma função de classificação estável que requer uma função de projeção que pode projetar elementos a serem classificados em chaves semelhantes a inteiros não assinadas. A inicialização padrão é necessária para os elementos que estão sendo classificados.|
|[Função parallel_reduce](concurrency-namespace-functions.md#parallel_reduce)|Sobrecarregado. Computa a soma de todos os elementos em um intervalo especificado computando somas parciais sucessivas ou computa o resultado de resultados parciais sucessivos de forma semelhante ao uso de uma operação binária especificada diferente de Sum, em paralelo. `parallel_reduce`é semanticamente semelhante a `std::accumulate` , exceto pelo fato de que ela requer que a operação binária seja associativa e requer um valor de identidade em vez de um valor inicial.|
|[Função parallel_sort](concurrency-namespace-functions.md#parallel_sort)|Sobrecarregado. Organiza os elementos em um intervalo especificado em uma ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Essa função é semanticamente semelhante a que se trata de `std::sort` uma classificação in-loco, instável e em vigor.|
|[Função parallel_transform](concurrency-namespace-functions.md#parallel_transform)|Sobrecarregado. Aplica um objeto de função especificado a cada elemento em um intervalo de origem, ou a um par de elementos de dois intervalos de origem, e copia os valores de retorno do objeto de função em um intervalo de destino, em paralelo. Esse funcionamento é semanticamente equivalente a `std::transform` .|
|[Função receive](concurrency-namespace-functions.md#receive)|Sobrecarregado. Uma implementação de recebimento geral, permitindo que um contexto aguarde dados de exatamente uma fonte e filtre os valores que são aceitos.|
|[Função run_with_cancellation_token](concurrency-namespace-functions.md#run_with_cancellation_token)|Executa um objeto de função imediatamente e de forma síncrona no contexto de um determinado token de cancelamento.|
|[Função send](concurrency-namespace-functions.md#send)|Sobrecarregado. Uma operação de envio síncrona, que aguarda até que o destino aceite ou recuse a mensagem.|
|[Função set_ambient_scheduler (Tempo de Execução de Simultaneidade)](concurrency-namespace-functions.md#set_ambient_scheduler)||
|[Função set_task_execution_resources](concurrency-namespace-functions.md#set_task_execution_resources)|Sobrecarregado. Restringe os recursos de execução usados pelo Tempo de Execução de Simultaneidade threads de trabalho internos para o conjunto de afinidade especificado.<br /><br /> É válido chamar esse método somente antes de o Gerenciador de recursos ter sido criado ou entre dois tempos de vida do Gerenciador de recursos. Ele pode ser invocado várias vezes, desde que o Gerenciador de recursos não exista no momento da invocação. Depois que um limite de afinidade tiver sido definido, ele permanecerá em vigor até a próxima chamada válida para o `set_task_execution_resources` método.<br /><br /> A máscara de afinidade fornecida não precisa ser um subconjunto da máscara de afinidade de processo. A afinidade de processo será atualizada, se necessário.|
|[Função de permuta](concurrency-namespace-functions.md#swap)|Troca os elementos de dois objetos `concurrent_vector`.|
|[Função task_from_exception (Tempo de Execução de Simultaneidade)](concurrency-namespace-functions.md#task_from_exception)||
|[Função task_from_result (Tempo de Execução de Simultaneidade)](concurrency-namespace-functions.md#task_from_result)||
|[Função Trace_agents_register_name](concurrency-namespace-functions.md#trace_agents_register_name)|Associa o nome fornecido ao bloco de mensagens ou ao agente no rastreamento ETW.|
|[Função try_receive](concurrency-namespace-functions.md#try_receive)|Sobrecarregado. Uma implementação geral de teste de recebimento, permitindo que um contexto Procure dados de exatamente uma fonte e filtre os valores que são aceitos. Se os dados não estiverem prontos, o método retornará false.|
|[Função Wait](concurrency-namespace-functions.md#wait)|Pausa o contexto atual por um período de tempo especificado.|
|[Função when_all](concurrency-namespace-functions.md#when_all)|Cria uma tarefa que será concluída com êxito quando todas as tarefas fornecidas como argumentos forem concluídas com êxito.|
|[Função when_any](concurrency-namespace-functions.md#when_any)|Sobrecarregado. Cria uma tarefa que será concluída com êxito quando todas as tarefas fornecidas como argumentos forem concluídas com êxito.|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|----------|-----------------|
|[operador! =](concurrency-namespace-operators.md#operator_neq)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador não é igual ao `concurrent_vector` objeto no lado direito.|
|[&&do operador](concurrency-namespace-operators.md#operator_amp_amp)|Sobrecarregado. Cria uma tarefa que será concluída com êxito quando as duas tarefas fornecidas como argumentos forem concluídas com êxito.|
|[&#124;&#124;do operador](concurrency-namespace-operators.md#operator_lor)|Sobrecarregado. Cria uma tarefa que será concluída com êxito quando uma das tarefas fornecidas como argumentos for concluída com êxito.|
|[<do operador](concurrency-namespace-operators.md#operator_lt)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é menor que o `concurrent_vector` objeto no lado direito.|
|[<do operador =](concurrency-namespace-operators.md#operator_lt_eq)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é menor ou igual ao `concurrent_vector` objeto no lado direito.|
|[operador = =](concurrency-namespace-operators.md#operator_eq_eq)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é igual ao `concurrent_vector` objeto no lado direito.|
|[>do operador](concurrency-namespace-operators.md#operator_gt)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é maior que o `concurrent_vector` objeto no lado direito.|
|[>do operador =](concurrency-namespace-operators.md#operator_lt_eq)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é maior ou igual ao `concurrent_vector` objeto no lado direito.|

### <a name="constants"></a>Constantes

|Nome|Descrição|
|----------|-----------------|
|[AgentEventGuid](concurrency-namespace-constants1.md#agenteventguid)|Um GUID de categoria ({B9B5B78C-0713-4898-A21A-C67949DCED07}) que descreve os eventos de ETW acionados pela biblioteca de agentes no Tempo de Execução de Simultaneidade.|
|[ChoreEventGuid](concurrency-namespace-constants1.md#choreeventguid)|Um GUID de categoria que descreve os eventos ETW disparados pelo Tempo de Execução de Simultaneidade que estão diretamente relacionados a tarefas.|
|[ConcRT_ProviderGuid](concurrency-namespace-constants1.md#concrt_providerguid)|O GUID do provedor de ETW para o Tempo de Execução de Simultaneidade.|
|[CONCRT_RM_VERSION_1](concurrency-namespace-constants1.md#concrt_rm_version_1)|Indica o suporte da interface do Gerenciador de recursos definida no Visual Studio 2010.|
|[ConcRTEventGuid](concurrency-namespace-constants1.md#concrteventguid)|Um GUID de categoria que descreve eventos ETW acionados pelo Tempo de Execução de Simultaneidade que não são mais especificamente descritos por outra categoria.|
|[ContextEventGuid](concurrency-namespace-constants1.md#contexteventguid)|Um GUID de categoria que descreve eventos ETW acionados pelo Tempo de Execução de Simultaneidade que estão diretamente relacionados aos contextos.|
|[COOPERATIVE_TIMEOUT_INFINITE](concurrency-namespace-constants1.md#cooperative_timeout_infinite)|Valor que indica que uma espera nunca deve atingir o tempo limite.|
|[COOPERATIVE_WAIT_TIMEOUT](concurrency-namespace-constants1.md#cooperative_wait_timeout)|Valor que indica que uma espera atingiu o tempo limite.|
|[INHERIT_THREAD_PRIORITY](concurrency-namespace-constants1.md#inherit_thread_priority)|Valor especial para a chave de política `ContextPriority` que indica que a prioridade de thread de todos os contextos no Agendador deve ser a mesma do thread que criou o Agendador.|
|[LockEventGuid](concurrency-namespace-constants1.md#lockeventguid)|Um GUID de categoria que descreve eventos ETW acionados pelo Tempo de Execução de Simultaneidade que estão diretamente relacionados a bloqueios.|
|[MaxExecutionResources](concurrency-namespace-constants1.md#maxexecutionresources)|Valor especial para as chaves de política `MinConcurrency` e `MaxConcurrency` . O padrão é o número de threads de hardware no computador na ausência de outras restrições.|
|[PPLParallelForeachEventGuid](concurrency-namespace-constants1.md#pplparallelforeacheventguid)|Um GUID de categoria que descreve eventos ETW acionados pelo Tempo de Execução de Simultaneidade que estão diretamente relacionados ao uso da `parallel_for_each` função.|
|[PPLParallelForEventGuid](concurrency-namespace-constants1.md#pplparallelforeventguid)|Um GUID de categoria que descreve eventos ETW acionados pelo Tempo de Execução de Simultaneidade que estão diretamente relacionados ao uso da `parallel_for` função.|
|[PPLParallelInvokeEventGuid](concurrency-namespace-constants1.md#pplparallelinvokeeventguid)|Um GUID de categoria que descreve eventos ETW acionados pelo Tempo de Execução de Simultaneidade que estão diretamente relacionados ao uso da `parallel_invoke` função.|
|[ResourceManagerEventGuid](concurrency-namespace-constants1.md#resourcemanagereventguid)|Um GUID de categoria que descreve eventos ETW acionados pelo Tempo de Execução de Simultaneidade que estão diretamente relacionados ao Gerenciador de recursos.|
|[ScheduleGroupEventGuid](concurrency-namespace-constants1.md#schedulegroupeventguid)|Um GUID de categoria que descreve eventos ETW acionados pelo Tempo de Execução de Simultaneidade que estão diretamente relacionados a grupos de agendamento.|
|[SchedulerEventGuid](concurrency-namespace-constants1.md#schedulereventguid)|Um GUID de categoria que descreve eventos ETW acionados pelo Tempo de Execução de Simultaneidade que estão diretamente relacionados à atividade do Agendador.|
|[VirtualProcessorEventGuid](concurrency-namespace-constants1.md#virtualprocessoreventguid)|Um GUID de categoria que descreve eventos ETW acionados pelo Tempo de Execução de Simultaneidade que estão diretamente relacionados a processadores virtuais.|

## <a name="requirements"></a>Requisitos

**Header:** Agents. h, ConcRT. h, concrtrm. h, concurrent_priority_queue. h, concurrent_queue. h, concurrent_unordered_map. h, concurrent_unordered_set. h, concurrent_vector. h, internal_concurrent_hash. h, internal_split_ordered_list. h, ppl. h, pplcancellation_token. h, pplconcrt. h, pplinterface. h, ppltasks. h

## <a name="see-also"></a>Confira também

[Referência](reference-concurrency-runtime.md)
