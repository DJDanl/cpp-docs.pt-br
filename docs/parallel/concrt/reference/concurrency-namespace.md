---
title: Namespace de simultaneidade | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs: C++
helpviewer_keywords: Concurrency namespace
ms.assetid: f1d33ca2-679b-4442-b140-22a9d9df61d1
caps.latest.revision: "37"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8662011107f9befef63ec247060a319172569300
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="concurrency-namespace"></a>Namespace Concurrency
O namespace `Concurrency` oferece classes e funções que permitem que você acesse o Tempo de execução de simultaneidade, uma estrutura de programação simultânea para C++. Para obter mais informações, consulte [Tempo de Execução de Simultaneidade](../../../parallel/concrt/concurrency-runtime.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace concurrency;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="namespaces"></a>Namespaces  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Concurrency::Extensibility Namespace](http://msdn.microsoft.com/en-us/16a86ff2-128e-4edf-89e4-38aac79c81f9)||  
  
### <a name="typedefs"></a>Typedefs  
  
|Nome|Descrição|  
|----------|-----------------|  
|`runtime_object_identity`|Cada instância de mensagem tem uma identidade que o segue como é clonado e transmitido entre componentes de mensagens. Isso não pode ser o endereço do objeto de mensagem.|  
|`task_status`|Um tipo que representa o estado terminal de uma tarefa. Os valores válidos são `completed` e `canceled`.|  
|`TaskProc`|Uma abstração elementar para uma tarefa, definida como `void (__cdecl * TaskProc)(void *)`. Um `TaskProc` é chamado para invocar o corpo de uma tarefa.|  
|`TaskProc_t`|Uma abstração elementar para uma tarefa, definida como `void (__cdecl * TaskProc_t)(void *)`. Um `TaskProc` é chamado para invocar o corpo de uma tarefa.|  
  
### <a name="classes"></a>Classes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe affinity_partitioner](affinity-partitioner-class.md)|O `affinity_partitioner` classe é semelhante de `static_partitioner` classe, mas ele melhora a afinidade de cache por sua opção de mapeamento de subintervalos para threads de trabalho. Ela pode melhorar o desempenho significativamente quando um loop é executado novamente em um mesmo conjunto de dados, e os dados se encaixa no cache. Observe que o mesmo `affinity_partitioner` objeto deve ser usado com iterações subsequentes de um loop paralelo que é executado em um conjunto de dados específico, para se beneficiar com a localidade dos dados.|  
|[Classe agent](agent-class.md)|Uma classe deve ser usado como uma classe base para todos os agentes independentes. Ele é usado para ocultar o estado dos outros agentes e interagir com a transmissão de mensagens.|  
|[Classe auto_partitioner](auto-partitioner-class.md)|O `auto_partitioner` classe representa o método padrão `parallel_for`, `parallel_for_each` e `parallel_transform` usar para o intervalo que itera através da partição. Esse método de particionamento employes roubo de balanceamento de carga de intervalo, bem como por-iterar cancelamento.|  
|[Classe bad_target](bad-target-class.md)|Esta classe descreve uma exceção gerada quando um bloco de mensagens é fornecido um ponteiro para um destino que não é válido para a operação que está sendo executada.|  
|[Classe call](call-class.md)|Um `call` bloco de mensagens é um várias fontes, ordenados `target_block` que invoca uma função especificada ao receber uma mensagem.|  
|[Classe cancellation_token](cancellation-token-class.md)|O `cancellation_token` classe representa a capacidade de determinar se alguma operação foi solicitada para cancelar. Um token fornecido pode ser associado com um `task_group`, `structured_task_group`, ou `task` para fornecer cancelamento implícita. Ele também pode ser controlado de cancelamento ou tem um retorno de chamada registrado para se e quando associado `cancellation_token_source` é cancelada.|  
|[Classe cancellation_token_registration](cancellation-token-registration-class.md)|O `cancellation_token_registration` classe representa uma notificação de retorno de chamada de um `cancellation_token`. Quando o `register` método em um `cancellation_token` é usado para receber uma notificação de quando o cancelamento ocorre, um `cancellation_token_registration` objeto é retornado como um identificador para o retorno de chamada para que o chamador pode solicitar um retorno de chamada específico não ser feita usando o `deregister` método.|  
|[Classe cancellation_token_source](cancellation-token-source-class.md)|O `cancellation_token_source` classe representa a capacidade de cancelar uma operação cancelável.|  
|[Classe choice](choice-class.md)|Um `choice` bloco de mensagens é um bloco de várias fonte, destino único que representa uma interação com um conjunto de fontes de fluxo de controle. O bloco de opção esperará por qualquer uma das várias fontes para produzir uma mensagem e propagará o índice da origem que gerou a mensagem.|  
|[Classe combinable](combinable-class.md)|O `combinable<T>` objeto destina-se a fornecer thread privada cópias de dados, para executar cálculos de subgrupos de local de thread livre de bloqueios durante os algoritmos paralelos. No final da operação em paralelo, os cálculos sub particular de thread, em seguida, podem ser mesclados em um resultado final. Esta classe pode ser usado em vez de uma variável compartilhada e pode resultar em uma melhoria de desempenho se caso contrário, haverá muita contenção nessa variável compartilhada.|  
|[Classe concurrent_priority_queue](concurrent-priority-queue-class.md)|O `concurrent_priority_queue` classe é um contêiner que permite que vários threads para itens simultaneamente por push e pop. Itens são disparados em ordem de prioridade, onde a prioridade é determinada por um functor fornecido como um argumento de modelo.|  
|[Classe concurrent_queue](concurrent-queue-class.md)|O `concurrent_queue` classe é uma classe de contêiner de sequência permite primeiro a entrar, primeiro a sair acesso para seus elementos. Ele permite que um conjunto limitado de operações com segurança de simultaneidade, como `push` e `try_pop`.|  
|[Classe concurrent_unordered_map](concurrent-unordered-map-class.md)|O `concurrent_unordered_map` classe é um contêiner de simultaneidade-safe que controla uma sequência de comprimento variável de elementos do tipo `std::pair<const K, _Element_type>`. A sequência é representada de forma que permite a simultaneidade safe acrescentar, acesso de elemento, acesso de iterador e operações de passagem do iterador.|  
|[Classe concurrent_unordered_multimap](concurrent-unordered-multimap-class.md)|O `concurrent_unordered_multimap` classe é um contêiner de simultaneidade-safe que controla uma sequência de comprimento variável de elementos do tipo `std::pair<const K, _Element_type>`. A sequência é representada de forma que permite a simultaneidade safe acrescentar, acesso de elemento, acesso de iterador e operações de passagem de iterador.|  
|[Classe concurrent_unordered_multiset](concurrent-unordered-multiset-class.md)|O `concurrent_unordered_multiset` classe é um contêiner de simultaneidade-safe que controla uma sequência de comprimento variável de elementos do tipo K. A sequência é representada de forma que permite a simultaneidade safe acrescentar, acesso de elemento, acesso de iterador e operações de passagem de iterador.|  
|[Classe concurrent_unordered_set](concurrent-unordered-set-class.md)|O `concurrent_unordered_set` classe é um contêiner de simultaneidade-safe que controla uma sequência de comprimento variável de elementos do tipo K. A sequência é representada de forma que permite a simultaneidade safe acrescentar, acesso de elemento, acesso de iterador e operações de passagem de iterador.|  
|[Classe concurrent_vector](concurrent-vector-class.md)|O `concurrent_vector` classe é uma classe de contêiner de sequência que permite acesso aleatório para qualquer elemento. Habilita a simultaneidade-safe acrescentar, acesso de elemento, acesso de iterador e operações de passagem do iterador.|  
|[Classe de contexto](context-class.md)|Representa uma abstração para um contexto de execução.|  
|[Classe context_self_unblock](context-self-unblock-class.md)|Esta classe descreve uma exceção gerada quando o `Unblock` método de um `Context` objeto é chamado do mesmo contexto. Isso poderia indicar uma tentativa por um determinado contexto para desbloquear a mesmo.|  
|[Classe context_unblock_unbalanced](context-unblock-unbalanced-class.md)|Esta classe descreve uma exceção lançada quando chamadas para o `Block` e `Unblock` métodos de um `Context` objeto não estão emparelhados corretamente.|  
|[Classe critical_section](critical-section-class.md)|Um mutex não reentrante que reconhece explicitamente o tempo de execução de simultaneidade.|  
|[Classe CurrentScheduler](currentscheduler-class.md)|Representa uma abstração para o Agendador atual associado ao contexto da chamada.|  
|[Classe default_scheduler_exists](default-scheduler-exists-class.md)|Esta classe descreve uma exceção gerada quando o `Scheduler::SetDefaultSchedulerPolicy` método é chamado quando um agendador padrão já existe dentro do processo.|  
|[Classe event](event-class.md)|Um evento de redefinição manual que reconhece explicitamente o tempo de execução de simultaneidade.|  
|[Classe improper_lock](improper-lock-class.md)|Esta classe descreve uma exceção gerada quando um bloqueio é adquirido incorretamente.|  
|[Classe improper_scheduler_attach](improper-scheduler-attach-class.md)|Esta classe descreve uma exceção gerada quando o `Attach` método for chamado em um `Scheduler` objeto que já está anexado ao contexto atual.|  
|[Classe improper_scheduler_detach](improper-scheduler-detach-class.md)|Esta classe descreve uma exceção gerada quando o `CurrentScheduler::Detach` método for chamado em um contexto que não tenha sido anexado ao Agendador de usando o `Attach` método de um `Scheduler` objeto.|  
|[Classe improper_scheduler_reference](improper-scheduler-reference-class.md)|Esta classe descreve uma exceção gerada quando o `Reference` método for chamado em um `Scheduler` objeto que está sendo desligado, em um contexto que não faz parte do que o Agendador.|  
|[Classe invalid_link_target](invalid-link-target-class.md)|Esta classe descreve uma exceção gerada quando o `link_target` método de um bloco de mensagens é chamado e o bloco de mensagens não pode vincular ao destino. Isso pode ser o resultado de exceder o número de links para que o bloco de mensagens é permitido ou tentar vincular a um destino específico duas vezes para a mesma fonte.|  
|[Classe invalid_multiple_scheduling](invalid-multiple-scheduling-class.md)|Esta classe descreve uma exceção lançada quando um `task_handle` objeto é agendada várias vezes usando o `run` método de um `task_group` ou `structured_task_group` objeto sem uma chamada intermediário para o `wait` ou `run_and_wait` métodos.|  
|[Classe invalid_operation](invalid-operation-class.md)|Esta classe descreve uma exceção gerada quando uma operação inválida é executada com mais precisão não é descrita por outro tipo de exceção lançado pelo tempo de execução de simultaneidade.|  
|[Classe invalid_oversubscribe_operation](invalid-oversubscribe-operation-class.md)|Esta classe descreve uma exceção gerada quando o `Context::Oversubscribe` método for chamado com o `_BeginOversubscription` parâmetro definido como `false` sem uma chamada anterior para o `Context::Oversubscribe` método com o `_BeginOversubscription` parâmetro definido como `true`.|  
|[Classe invalid_scheduler_policy_key](invalid-scheduler-policy-key-class.md)|Esta classe descreve uma exceção gerada quando um inválido ou desconhecido de chave é passada para um `SchedulerPolicy` construtor do objeto, ou o `SetPolicyValue` método de um `SchedulerPolicy` objeto é passado a uma chave que deve ser alterada usando outros meios, como o `SetConcurrencyLimits` método.|  
|[Classe invalid_scheduler_policy_thread_specification](invalid-scheduler-policy-thread-specification-class.md)|Esta classe descreve uma exceção gerada quando é feita uma tentativa de definir os limites de simultaneidade de um `SchedulerPolicy` objeto, de modo que o valor da `MinConcurrency` chave é menor que o valor da `MaxConcurrency` chave.|  
|[Classe invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md)|Esta classe descreve uma exceção gerada quando uma chave de política de uma `SchedulerPolicy` objeto é definido como um valor inválido para essa chave.|  
|[Classe ISource](isource-class.md)|O `ISource` classe é a interface para todos os blocos de origem. Blocos de código-fonte propaguem as mensagens `ITarget` blocos.|  
|[Classe ITarget](itarget-class.md)|O `ITarget` classe é a interface para todos os blocos de destino. Blocos de destino consumam mensagens oferecidas a eles por `ISource` blocos.|  
|[Classe join](join-class.md)|Um `join` bloco de mensagens é um destino de único, várias fontes, ordenada `propagator_block` juntos, que combina as mensagens do tipo `T` de cada uma das suas fontes.|  
|[Classe location](location-class.md)|Uma abstração de um local físico em hardware.|  
|[Classe message](message-class.md)|O envelope de mensagem básica que contém a carga de dados que está sendo transmitida entre blocos de mensagens.|  
|[Classe message_not_found](message-not-found-class.md)|Esta classe descreve uma exceção lançada quando um bloco de mensagens não pode localizar uma mensagem solicitada.|  
|[Classe message_processor](message-processor-class.md)|O `message_processor` classe é a classe base abstrata para processamento de `message` objetos. Não há nenhuma garantia sobre a ordem das mensagens.|  
|[Classe missing_wait](missing-wait-class.md)|Esta classe descreve uma exceção gerada quando há tarefas ainda está agendadas para ser um `task_group` ou `structured_task_group` do objeto no momento em que esse objeto destruidor é executado. Essa exceção será lançada nunca se o destruidor é atingido devido a uma pilha de desenrolamento como resultado de uma exceção.|  
|[Classe multi_link_registry](multi-link-registry-class.md)|O `multi_link_registry` objeto é um `network_link_registry` que gerencia vários blocos de origem ou de vários blocos de destino.|  
|[Classe multitype_join](multitype-join-class.md)|Um `multitype_join` bloco de mensagens é um bloco de mensagens várias fonte, destino único que juntos combina mensagens de tipos diferentes de cada uma das suas fontes e oferece uma tupla das mensagens combinadas para seus destinos.|  
|[Classe nested_scheduler_missing_detach](nested-scheduler-missing-detach-class.md)|Esta classe descreve uma exceção gerada quando o tempo de execução de simultaneidade detecta que você não chamou o `CurrentScheduler::Detach` método em um contexto que é anexado a um segundo Agendador usando o `Attach` método o `Scheduler` objeto.|  
|[Classe network_link_registry](network-link-registry-class.md)|O `network_link_registry` gerencia a classe base abstrata os links entre blocos de origem e destino.|  
|[Classe operation_timed_out](operation-timed-out-class.md)|Esta classe descreve uma exceção gerada quando uma operação foi atingido.|  
|[Classe ordered_message_processor](ordered-message-processor-class.md)|Um `ordered_message_processor` é um `message_processor` que permite que os blocos de mensagens processar mensagens na ordem em que foram recebidas.|  
|[Classe overwrite_buffer](overwrite-buffer-class.md)|Um `overwrite_buffer` bloco de mensagens é um multi-destino de várias fontes, ordenada `propagator_block` capaz de armazenar uma única mensagem por vez. Novas mensagens substituem aqueles mantido anteriormente.|  
|[Classe progress_reporter](progress-reporter-class.md)|A classe de relator de andamento permite criar relatórios de notificações de andamento de um tipo específico. Cada objeto progress_reporter está associado a uma determinada ação ou operação assíncrona.|  
|[Classe propagator_block](propagator-block-class.md)|O `propagator_block` classe é uma classe base abstrata para blocos de mensagens de uma origem e destino. Ele combina a funcionalidade de ambos os `source_block` e `target_block` classes.|  
|[Classe reader_writer_lock](reader-writer-lock-class.md)|Um bloqueio de leitor-gravador baseadas em fila do gravador de preferência com local apenas girando. O bloqueio concede primeiro - primeiro acesso (PEPS) para gravadores e impede leitores sob uma carga contínua de gravadores.|  
|[Classe ScheduleGroup](schedulegroup-class.md)|Representa uma abstração para um grupo de agendamento. Organizam os grupos de agendamento de um conjunto de trabalho relacionados que se beneficia de ser agendado próximas temporariamente, por outra tarefa em execução no mesmo grupo antes de passar para outro grupo ou espacialmente, executando vários itens dentro do mesmo grupo no mesmo Nó NUMA ou soquete físico.|  
|[Classe Scheduler](scheduler-class.md)|Representa uma abstração para um agendador de tempo de execução de simultaneidade.|  
|[Classe scheduler_not_attached](scheduler-not-attached-class.md)|Esta classe descreve uma exceção gerada quando é executada uma operação que requer um agendador a ser anexado ao contexto atual e outro não faz.|  
|[Classe scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md)|Esta classe descreve uma exceção gerada devido a uma falha ao adquirir um recurso crítico no tempo de execução de simultaneidade.|  
|[Classe scheduler_worker_creation_error](scheduler-worker-creation-error-class.md)|Esta classe descreve uma exceção gerada devido a uma falha ao criar um contexto de execução do trabalho no tempo de execução de simultaneidade.|  
|[Classe SchedulerPolicy](schedulerpolicy-class.md)|O `SchedulerPolicy` classe contém um conjunto de pares chave/valor, um para cada elemento de diretiva que controlam o comportamento de uma instância do Agendador.|  
|[Classe simple_partitioner](simple-partitioner-class.md)|O `simple_partitioner` classe representa um particionamento estático do intervalo iterado pelo `parallel_for`. O particionador divide o intervalo em partes, de modo que cada parte tem pelo menos o número de iterações especificado pelo tamanho do bloco.|  
|[Classe single_assignment](single-assignment-class.md)|Um `single_assignment` bloco de mensagens é um multi-destino de várias fontes, ordenada `propagator_block` capaz de armazenar uma única gravação-depois de `message`.|  
|[Classe single_link_registry](single-link-registry-class.md)|O `single_link_registry` objeto é um `network_link_registry` que gerencia apenas um único bloco de origem ou de destino.|  
|[Classe source_block](source-block-class.md)|O `source_block` classe é uma classe base abstrata para blocos de código-fonte. A classe fornece funcionalidade de gerenciamento de link básicas como comuns bem como verificações de erro.|  
|[Classe source_link_manager](source-link-manager-class.md)|O `source_link_manager` objeto gerencia mensagens links de rede de bloco para `ISource` blocos.|  
|[Classe static_partitioner](static-partitioner-class.md)|O `static_partitioner` classe representa um particionamento estático do intervalo iterado pelo `parallel_for`. O particionador divide o intervalo em blocos há trabalhadores disponíveis para o Agendador underyling.|  
|[Classe structured_task_group](structured-task-group-class.md)|O `structured_task_group` classe representa uma coleção altamente estruturada de trabalho paralelos. É possível enfileirar tarefas individuais em paralelo para uma `structured_task_group` usando `task_handle` objetos e aguarde até que elas sejam concluídas ou cancele o grupo de tarefas antes de eles terminarem de executar, que anulará as tarefas que não começaram a execução.|  
|[Classe target_block](target-block-class.md)|O `target_block` classe é uma classe base abstrata que fornece funcionalidade de gerenciamento básico do link e verificação de erros para o destino apenas blocos.|  
|[Classe task (Tempo de Execução de Simultaneidade)](task-class.md)|A classe `task` da Biblioteca de Padrões Paralelos (PPL). O objeto `task` representa o trabalho que pode ser executado de forma assíncrona e simultaneamente com outras tarefas e o trabalho paralelo produzido por algoritmos paralelos no Tempo de execução de simultaneidade. Produz um resultado de tipo `_ResultType` após uma conclusão bem-sucedida. Tarefas do tipo `task<void>` não produzem resultados. Uma tarefa pode ser aguardada e cancelada independentemente de outras tarefas. Ela também pode ser composta por outras tarefas usando continuations(`then`) e os padrões join(`when_all`) e choice(`when_any`).|  
|[Classe task_canceled](task-canceled-class.md)|Esta classe descreve uma exceção gerada pela camada de tarefas PPL para forçar a cancelamento da tarefa atual. Ele também é gerado pelo `get()` método [tarefa](http://msdn.microsoft.com/en-us/5389e8a5-5038-40b6-844a-55e9b58ad35f), para uma tarefa cancelada.|  
|[Classe task_completion_event](task-completion-event-class.md)|A classe `task_completion_event` permite atrasar a execução de uma tarefa até que uma condição seja atendida, ou iniciar uma tarefa em resposta a um evento externo.|  
|[Classe task_continuation_context](task-continuation-context-class.md)|A classe `task_continuation_context` permite que você especifique onde gostaria que uma continuação fosse executada. Isso é útil somente para o uso dessa classe por meio de um aplicativo da Windows Store. Para aplicativos que não são da Windows Store, o contexto de execução da continuação da tarefa é determinado pelo tempo de execução e não é configurável.|  
|[Classe task_group](task-group-class.md)|O `task_group` classe representa uma coleção de trabalho paralela que pode ser aguardado ou cancelada.|  
|[Classe task_handle](task-handle-class.md)|O `task_handle` classe representa um item de trabalho paralelas individual. Ele encapsula as instruções e os dados necessários para executar um trabalho.|  
|[Classe task_options (Tempo de Execução de Simultaneidade)](task-options-class-concurrency-runtime.md)|Representa as opções permitidas para criar uma tarefa|  
|[Classe timer](timer-class.md)|Um `timer` bloco de mensagens é um destino único `source_block` capaz de enviar uma mensagem ao destino após determinado período de tempo ou em intervalos específicos.|  
|[Classe transformer](transformer-class.md)|Um `transformer` bloco de mensagens é um destino de único, várias fontes, ordenada `propagator_block` que pode aceitar mensagens de um tipo e é capaz de armazenar um número ilimitado de mensagens de um tipo diferente.|  
|[Classe unbounded_buffer](unbounded-buffer-class.md)|Um `unbounded_buffer` bloco de mensagens é um multi-destino de várias fontes, ordenada `propagator_block` capaz de armazenar um número ilimitado de mensagens.|  
|[Classe unsupported_os](unsupported-os-class.md)|Esta classe descreve uma exceção gerada quando é usado um sistema operacional sem suporte.|  
  
### <a name="structures"></a>Estruturas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Estrutura DispatchState](dispatchstate-structure.md)|O `DispatchState` estrutura é usada para transferir o estado para o `IExecutionContext::Dispatch` método. Ele descreve as circunstâncias em que o `Dispatch` método é chamado em um `IExecutionContext` interface.|  
|[Estrutura IExecutionContext](iexecutioncontext-structure.md)|Uma interface para um contexto de execução que pode executar em um determinado processador virtual e ser trabalhem de forma alternado do contexto.|  
|[Estrutura IExecutionResource](iexecutionresource-structure.md)|Uma abstração para um thread de hardware.|  
|[Estrutura IResourceManager](iresourcemanager-structure.md)|Uma interface para o Gerenciador de recursos do tempo de execução de simultaneidade. Essa é a interface pela qual os agendadores se comunicar com o Gerenciador de recursos.|  
|[Estrutura IScheduler](ischeduler-structure.md)|Uma interface para uma abstração de um agendador de trabalho. Gerenciador de recursos do tempo de execução de simultaneidade usa essa interface para se comunicar com os agendadores de trabalho.|  
|[Estrutura ISchedulerProxy](ischedulerproxy-structure.md)|A interface pela qual agendadores se comunicar com o Gerenciador de recursos do tempo de execução de simultaneidade para negociar a alocação de recursos.|  
|[Estrutura IThreadProxy](ithreadproxy-structure.md)|Uma abstração para um thread de execução. Dependendo do `SchedulerType` chave da diretiva do Agendador que você criar o Gerenciador de recursos será conceder a você um proxy de thread que é apoiado por um thread de Win32 regular ou um thread (UMS) agendáveis do modo de usuário. Threads UMS são com suporte em sistemas operacionais de 64 bits com a versão do Windows 7 e superior.|  
|[Estrutura ITopologyExecutionResource](itopologyexecutionresource-structure.md)|Uma interface para um recurso de execução, conforme definido pelo Gerenciador de recursos.|  
|[Estrutura ITopologyNode](itopologynode-structure.md)|Uma interface para um nó de topologia, conforme definido pelo Gerenciador de recursos. Um nó contém um ou mais recursos de execução.|  
|[Estrutura IUMSCompletionList](iumscompletionlist-structure.md)|Representa uma lista de conclusão UMS. Quando um blocos de thread UMS, o Agendador designado de agendamento de contexto é enviado para tomar uma decisão do que agendar na raiz do processador virtual subjacente enquanto o thread original está bloqueado. Quando o thread original desbloqueia, o sistema operacional enfileira à lista de conclusão que pode ser acessada por meio dessa interface. O Agendador pode consultar a lista de conclusão no contexto de programação designado ou qualquer outro lugar, que ele procura por trabalho.|  
|[Estrutura IUMSScheduler](iumsscheduler-structure.md)|Uma interface para uma abstração de um agendador de trabalho que deseja Gerenciador de recursos do tempo de execução de simultaneidade entregá-threads do modo de usuário agendáveis (UMS). O Gerenciador de recursos usa essa interface para se comunicar com os agendadores do thread UMS. A interface `IUMSScheduler` herda da interface `IScheduler`.|  
|[Estrutura IUMSThreadProxy](iumsthreadproxy-structure.md)|Uma abstração para um thread de execução. Se você quiser que o Agendador para receber os threads do modo de usuário agendáveis (UMS), defina o valor para o elemento de diretiva do Agendador `SchedulerKind` para `UmsThreadDefault`e implementar o `IUMSScheduler` interface. Threads UMS são apenas com suporte em sistemas operacionais de 64 bits com a versão do Windows 7 e superior.|  
|[Estrutura IUMSUnblockNotification](iumsunblocknotification-structure.md)|Representa uma notificação do Gerenciador de recursos que um proxy de thread que bloqueada e disparou um retorno para o Agendador designado contexto de programação foi desbloqueado e está pronto para ser agendado. Essa interface é inválida quando o contexto de execução associadas do proxy de thread, retornado do `GetContext` método, será reagendada.|  
|[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)|Uma abstração para um thread de hardware no qual um proxy do thread pode executar.|  
|[Estrutura scheduler_interface](scheduler-interface-structure.md)|Interface do Agendador|  
|[Estrutura scheduler_ptr (Tempo de Execução de Simultaneidade)](scheduler-ptr-structure-concurrency-runtime.md)|Representa um ponteiro para um agendador. Esta classe existe para permitir a especificação de um tempo de vida compartilhada usando shared_ptr ou apenas uma referência simples ponteiro bruto.|  
  
### <a name="enumerations"></a>Enumerações  
  
|Nome|Descrição|  
|----------|-----------------|  
|[agent_status](concurrency-namespace-enums.md#agent_status)|Os estados válidos para um `agent`.|  
|[Agents_EventType](concurrency-namespace-enums.md#agents_eventtype)|Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pela biblioteca de agentes|  
|[ConcRT_EventType](concurrency-namespace-enums.md#concrt_eventtype)|Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pelo tempo de execução de simultaneidade.|  
|[Concrt_TraceFlags](concurrency-namespace-enums.md#concrt_traceflags)|Sinalizadores de rastreamento para os tipos de evento|  
|[CriticalRegionType](concurrency-namespace-enums.md#criticalregiontype)|O tipo de um contexto está dentro de região crítica.|  
|[DynamicProgressFeedbackType](concurrency-namespace-enums.md#dynamicprogressfeedbacktype)|Usado pelo `DynamicProgressFeedback` com base em políticas para descrever se os recursos para o Agendador serão balanceados acordo com informações estatísticas coletadas do Agendador ou apenas em processadores virtuais entrando e saindo do estado ocioso por meio de chamadas para o `Activate` e `Deactivate` métodos no `IVirtualProcessorRoot` interface. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md#policyelementkey).|  
|[join_type](concurrency-namespace-enums.md#join_type)|O tipo de um `join` bloco de mensagens.|  
|[message_status](concurrency-namespace-enums.md#message_status)|As respostas válidas para uma oferta de uma `message` objeto para um bloco.|  
|[PolicyElementKey](concurrency-namespace-enums.md#policyelementkey)|Chaves de política que descreve aspectos do comportamento do Agendador. Cada elemento de política é descrito por um par chave-valor. Para obter mais informações sobre políticas de agendador e seu impacto em agendadores, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).|  
|[SchedulerType](concurrency-namespace-enums.md#schedulertype)|Usado pelo `SchedulerKind` política para descrever o tipo de threads que o Agendador deve utilizar para contextos de execução subjacente. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md#policyelementkey).|  
|[SchedulingProtocolType](concurrency-namespace-enums.md#schedulingprotocoltype)|Usado pelo `SchedulingProtocol` política para descrever qual algoritmo agendamento será utilizado para o Agendador. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md#policyelementkey).|  
|[SwitchingProxyState](concurrency-namespace-enums.md#switchingproxystate)|Usado para indicar o estado de que um proxy de thread está no, quando ela está executando uma alternância de contexto cooperativo para proxy de um thread diferente.|  
|[task_group_status](concurrency-namespace-enums.md#task_group_status)|Descreve o status de execução de um `task_group` ou `structured_task_group` objeto. Um valor desse tipo é retornado por diversos métodos que esperar em tarefas agendadas para um grupo de tarefas para concluir.|  
|[WinRTInitializationType](concurrency-namespace-enums.md#winrtinitializationtype)|Usado pelo `WinRTInitialization` política para descrever se e como o tempo de execução do Windows será inicializado em threads de Agendador para um aplicativo que é executado em sistemas operacionais com a versão Windows 8 ou superior. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md#policyelementkey).|  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Função ALLOC](concurrency-namespace-functions.md#alloc)|Aloca um bloco de memória do tamanho especificado de Suballocator de cache de tempo de execução a simultaneidade.|  
|[Função asend](concurrency-namespace-functions.md#asend)|Sobrecarregado. Uma operação de envio assíncrono que agenda uma tarefa para propagar os dados para o bloco de destino.|  
|[Função cancel_current_task](concurrency-namespace-functions.md#cancel_current_task)|Cancela a tarefa atualmente em execução. Essa função pode ser chamada de dentro do corpo de uma tarefa para interromper a execução da tarefa e fazer com que ela entre no estado `canceled`.<br /><br /> Não é um cenário com suporte para chamar essa função se você não estiver dentro do corpo de uma `task`. Isso resultará em um comportamento indefinido, tal como um travamento ou um desligamento em seu aplicativo.|  
|[Função create_async](concurrency-namespace-functions.md#create_async)|Cria uma construção assíncrona de Tempo de execução do Windows com base em um objeto de função ou lambda fornecido pelo usuário. O tipo de retorno de `create_async` é `IAsyncAction^`, `IAsyncActionWithProgress<TProgress>^`, `IAsyncOperation<TResult>^` ou `IAsyncOperationWithProgress<TResult, TProgress>^` com base na assinatura do lambda passada para o método.|  
|[Função create_task](concurrency-namespace-functions.md#create_task)|Sobrecarregado. Cria um PPL [tarefa](http://msdn.microsoft.com/en-us/5389e8a5-5038-40b6-844a-55e9b58ad35f) objeto. `create_task`pode ser usado em qualquer lugar você teria que usar um construtor de tarefa. Ele é fornecido principalmente para sua conveniência, pois permite o uso do `auto` palavra-chave durante a criação de tarefas.|  
|[Função CreateResourceManager](concurrency-namespace-functions.md#createresourcemanager)|Retorna uma interface que representa a instância singleton do Gerenciador de recursos do tempo de execução de simultaneidade. O Gerenciador de recursos é responsável pela atribuição de recursos a agendadores que deseja cooperam entre si.|  
|[Função DisableTracing](concurrency-namespace-functions.md#disabletracing)|Desabilita o rastreamento em tempo de execução de simultaneidade. Essa função é preterida porque o rastreamento ETW é não registrado por padrão.|  
|[Função EnableTracing](concurrency-namespace-functions.md#enabletracing)|Habilita o rastreamento em tempo de execução de simultaneidade. Essa função é preterida porque o rastreamento ETW está ativada por padrão.|  
|[Função Free](concurrency-namespace-functions.md#free)|Libera um bloco de memória alocada anteriormente pelo `Alloc` método Suballocator de cache de tempo de execução a simultaneidade.|  
|[get_ambient_scheduler função (tempo de execução de simultaneidade)](concurrency-namespace-functions.md#get_ambient_scheduler)||  
|[Função GetExecutionContextId](concurrency-namespace-functions.md#getexecutioncontextid)|Retorna um identificador exclusivo que pode ser atribuído a um contexto de execução que implementa o `IExecutionContext` interface.|  
|[Função GetOSVersion](concurrency-namespace-functions.md#getosversion)|Retorna a versão do sistema operacional.|  
|[Função GetProcessorCount](concurrency-namespace-functions.md#getprocessorcount)|Retorna o número de threads de hardware do sistema subjacente.|  
|[Função GetProcessorNodeCount](concurrency-namespace-functions.md#getprocessornodecount)|Retorna o número de nós NUMA ou pacotes de processador no sistema subjacente.|  
|[Função GetSchedulerId](concurrency-namespace-functions.md#getschedulerid)|Retorna um identificador exclusivo que pode ser atribuído a um agendador que implementa o `IScheduler` interface.|  
|[Função interruption_point](concurrency-namespace-functions.md#interruption_point)|Cria um ponto de interrupção de cancelamento. Se um cancelamento está em andamento no contexto em que essa função é chamada, isso gerará uma exceção interna que anula a execução do trabalho atualmente em execução paralela. Se o cancelamento não está em andamento, a função não faz nada.|  
|[Função is_current_task_group_canceling](concurrency-namespace-functions.md#is_current_task_group_canceling)|Retorna uma indicação de se a tarefa de grupo que está em execução atualmente embutido no contexto atual está em meio a um cancelamento ativado (ou será em breve). Observe que, se não houver nenhum grupo de tarefas em execução atualmente embutido no contexto atual, `false` será retornado.|  
|[Função make_choice](concurrency-namespace-functions.md#make_choice)|Sobrecarregado. Constrói um `choice` bloco de mensagens de um recurso opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.|  
|[Função make_greedy_join](concurrency-namespace-functions.md#make_greedy_join)|Sobrecarregado. Constrói um `greedy multitype_join` bloco de mensagens de um recurso opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.|  
|[Função make_join](concurrency-namespace-functions.md#make_join)|Sobrecarregado. Constrói um `non_greedy multitype_join` bloco de mensagens de um recurso opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.|  
|[Função make_task](concurrency-namespace-functions.md#make_task)|Um método de fábrica para criar um `task_handle` objeto.|  
|[Função parallel_buffered_sort](concurrency-namespace-functions.md#parallel_buffered_sort)|Sobrecarregado. Organiza os elementos em um intervalo especificado em uma ordem nondescending, ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Essa função é semanticamente similar a `std::sort` porque é uma classificação de comparação instável, baseada no local, exceto que ele precisa `O(n)` espaço adicional e requer inicialização padrão para os elementos que estão sendo classificados.|  
|[Função parallel_for](concurrency-namespace-functions.md#parallel_for)|Sobrecarregado. `parallel_for`itera em um intervalo de índices e executa uma função fornecida pelo usuário em cada iteração em paralelo.|  
|[Função parallel_for_each](concurrency-namespace-functions.md#parallel_for_each)|Sobrecarregado. `parallel_for_each`aplica-se uma função específica para cada elemento em um intervalo, em paralelo. É semanticamente equivalente ao `for_each` funcionar a `std` namespace, exceto a iteração sobre elementos é executada em paralelo, e a ordem de iteração é especificada. O argumento `_Func` deve oferecer suporte a um operador de chamada de função do formulário `operator()(T)` onde o parâmetro `T` é o tipo de item de contêiner que está sendo feita a iteração.|  
|[Função parallel_invoke](concurrency-namespace-functions.md#parallel_invoke)|Sobrecarregado. Executa os objetos de função fornecidos como parâmetros em paralelo e bloqueia até que concluiu a execução. Cada objeto de função pode ser uma expressão lambda, um ponteiro para função, ou qualquer objeto que suporta o operador de chamada de função com a assinatura `void operator()()`.|  
|[Função parallel_radixsort](concurrency-namespace-functions.md#parallel_radixsort)|Sobrecarregado. Organiza elementos em um intervalo especificado em uma ordem decrescente não usando um algoritmo de classificação de base. Essa é uma função de classificação estável que exige uma função de projeção que pode projetar elementos a serem classificados em chaves de tipo inteiro sem sinal. Inicialização padrão é necessária para os elementos que estão sendo classificados.|  
|[Função parallel_reduce](concurrency-namespace-functions.md#parallel_reduce)|Sobrecarregado. Calcula a soma de todos os elementos em um intervalo especificado Calculando somas parciais sucessivas ou calcula o resultado de sucessivos resultados parciais da mesma forma obtido usando uma operação binária especificada diferente de soma, em paralelo. `parallel_reduce`é semanticamente similar a `std::accumulate`, exceto que ele requer que a operação binária associativa e requer um valor de identidade em vez de um valor inicial.|  
|[Função parallel_sort](concurrency-namespace-functions.md#parallel_sort)|Sobrecarregado. Organiza os elementos em um intervalo especificado em uma ordem nondescending, ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Essa função é semanticamente semelhante ao `std::sort` porque é uma classificação de comparação instável, baseada no local.|  
|[Função parallel_transform](concurrency-namespace-functions.md#parallel_transform)|Sobrecarregado. Aplica-se a um objeto de função especificado para cada elemento em um intervalo de origem ou para um par de elementos de dois intervalos de origem e copia os valores de retorno do objeto de função em um intervalo de destino, em paralelo. Nesse funcional é semanticamente equivalente a `std::transform`.|  
|[Função Receive](concurrency-namespace-functions.md#receive)|Sobrecarregado. Geral receber implementação, permitindo que um contexto aguardar a exatamente uma fonte de dados e filtrar os valores que são aceitos.|  
|[Função run_with_cancellation_token](concurrency-namespace-functions.md#run_with_cancellation_token)|Executa um objeto de função imediatamente e de forma síncrona no contexto de um token de cancelamento determinado.|  
|[Função Send](concurrency-namespace-functions.md#send)|Sobrecarregado. Uma operação síncrona de envio, aguarda até que o destino aceita ou recusa a mensagem.|  
|[set_ambient_scheduler função (tempo de execução de simultaneidade)](concurrency-namespace-functions.md#set_ambient_scheduler)||  
|[Função set_task_execution_resources](concurrency-namespace-functions.md#set_task_execution_resources)|Sobrecarregado. Restringe os recursos de execução usados pelos threads de trabalho interno de tempo de execução de simultaneidade para o conjunto especificado de afinidade.<br /><br /> É válido chamar esse método antes do Gerenciador de recursos foi criado, ou entre dois tempos de vida do Gerenciador de recursos. Ele pode ser chamado várias vezes desde que o Gerenciador de recursos não existe no momento da invocação. Depois que um limite de afinidade tiver sido definido, ele permanecerá em vigor até a próxima chamada válida para o `set_task_execution_resources` método.<br /><br /> A máscara de afinidade fornecida não precisa ser um subconjunto da máscara de afinidade de processo. A afinidade do processo será atualizada se necessário.|  
|[Função swap](concurrency-namespace-functions.md#swap)|Troca os elementos de dois objetos `concurrent_vector`.|  
|[task_from_exception função (tempo de execução de simultaneidade)](concurrency-namespace-functions.md#task_from_exception)||  
|[task_from_result função (tempo de execução de simultaneidade)](concurrency-namespace-functions.md#task_from_result)||  
|[Função Trace_agents_register_name](concurrency-namespace-functions.md#trace_agents_register_name)|Associa o nome fornecido para o bloco de mensagens ou o agente no rastreamento ETW.|  
|[Função try_receive](concurrency-namespace-functions.md#try_receive)|Sobrecarregado. Geral try e recebimento de implementação, permitindo que um contexto procurar dados de exatamente uma fonte e filtrar os valores que são aceitos. Se os dados não estiverem prontos, o método retornará false.|  
|[Função Wait](concurrency-namespace-functions.md#wait)|Pausa o contexto atual para um período de tempo especificado.|  
|[Função when_all](concurrency-namespace-functions.md#when_all)|Cria uma tarefa que será concluída com êxito quando todas as tarefas fornecidas como argumentos forem concluídas com êxito.|  
|[Função when_any](concurrency-namespace-functions.md#when_any)|Sobrecarregado. Cria uma tarefa que será concluída com êxito quando todas as tarefas fornecidas como argumentos forem concluídas com êxito.|  
  
### <a name="operators"></a>Operadores  
  
|Nome|Descrição|  
|----------|-----------------| 
|[operator!=](concurrency-namespace-operators.md#operator_neq)|Testa se o `concurrent_vector` objeto à esquerda do operador não é igual de `concurrent_vector` objeto no lado direito.|  
|[operator&&](concurrency-namespace-operators.md#operator_amp_amp)|Sobrecarregado. Cria uma tarefa que será concluída com êxito quando ambas as tarefas fornecidas como argumentos forem concluídas com êxito.|  
|[operator&#124;&#124;](concurrency-namespace-operators.md#operator_lor)|Sobrecarregado. Cria uma tarefa que será concluída com êxito quando qualquer uma das tarefas fornecidos como argumentos for concluído com êxito.|  
|[operator<](concurrency-namespace-operators.md#operator_lt)|Testa se o `concurrent_vector` objeto à esquerda do operador é menor do que o `concurrent_vector` objeto no lado direito.|  
|[operator<=](concurrency-namespace-operators.md#operator_lt_eq)|Testa se o `concurrent_vector` objeto à esquerda do operador é menor ou igual a `concurrent_vector` objeto no lado direito.|  
|[operator==](concurrency-namespace-operators.md#operator_eq_eq)|Testa se o `concurrent_vector` objeto à esquerda do operador é igual de `concurrent_vector` objeto no lado direito.|  
|[operator>](concurrency-namespace-operators.md#operator_gt)|Testa se o `concurrent_vector` objeto à esquerda do operador é maior que o `concurrent_vector` objeto no lado direito.|  
|[operator>=](concurrency-namespace-operators.md#operator_lt_eq)|Testa se o `concurrent_vector` objeto à esquerda do operador é maior que ou igual a `concurrent_vector` objeto no lado direito.|  
  
### <a name="constants"></a>Constantes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[AgentEventGuid](concurrency-namespace-constants1.md#agenteventguid)|Uma categoria de GUID ({B9B5B78C-0713-4898-A21A-C67949DCED07}) que descreve eventos ETW disparados pela biblioteca de agentes no tempo de execução de simultaneidade.|  
|[ChoreEventGuid](concurrency-namespace-constants1.md#choreeventguid)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionadas a tarefas ou tarefas.|  
|[ConcRT_ProviderGuid](concurrency-namespace-constants1.md#concrt_providerguid)|O provedor de ETW GUID para o tempo de execução de simultaneidade.|  
|[CONCRT_RM_VERSION_1](concurrency-namespace-constants1.md#concrt_rm_version_1)|Indica o suporte da interface do Gerenciador de recursos definido no Visual Studio 2010.|  
|[ConcRTEventGuid](concurrency-namespace-constants1.md#concrteventguid)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que não são mais especificamente descritos por outra categoria.|  
|[ContextEventGuid](concurrency-namespace-constants1.md#contexteventguid)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionadas ao contextos.|  
|[COOPERATIVE_TIMEOUT_INFINITE](concurrency-namespace-constants1.md#cooperative_timeout_infinite)|Valor que indica que uma espera nunca deve atingir o tempo limite.|  
|[COOPERATIVE_WAIT_TIMEOUT](concurrency-namespace-constants1.md#cooperative_wait_timeout)|Valor que indica que uma espera atingiu o tempo limite.|  
|[INHERIT_THREAD_PRIORITY](concurrency-namespace-constants1.md#inherit_thread_priority)|Um valor especial para a chave de política `ContextPriority` indicando que a prioridade de thread de todos os contextos no Agendador do deve ser a mesma que o thread que criou o Agendador.|  
|[LockEventGuid](concurrency-namespace-constants1.md#lockeventguid)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionadas a bloqueios.|  
|[MaxExecutionResources](concurrency-namespace-constants1.md#maxexecutionresources)|Um valor especial para as chaves de política `MinConcurrency` e `MaxConcurrency`. O padrão é o número de threads de hardware na máquina na ausência de outras restrições.|  
|[PPLParallelForeachEventGuid](concurrency-namespace-constants1.md#pplparallelforeacheventguid)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionadas ao uso do `parallel_for_each` função.|  
|[PPLParallelForEventGuid](concurrency-namespace-constants1.md#pplparallelforeventguid)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionadas ao uso do `parallel_for` função.|  
|[PPLParallelInvokeEventGuid](concurrency-namespace-constants1.md#pplparallelinvokeeventguid)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionadas ao uso do `parallel_invoke` função.|  
|[ResourceManagerEventGuid](concurrency-namespace-constants1.md#resourcemanagereventguid)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionadas ao Gerenciador de recursos.|  
|[ScheduleGroupEventGuid](concurrency-namespace-constants1.md#schedulegroupeventguid)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionados aos grupos de agendas.|  
|[SchedulerEventGuid](concurrency-namespace-constants1.md#schedulereventguid)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionadas à atividade do Agendador.|  
|[VirtualProcessorEventGuid](concurrency-namespace-constants1.md#virtualprocessoreventguid)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionados aos processadores virtuais.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h, concrt.h, concrtrm.h, concurrent_priority_queue.h, concurrent_queue.h, concurrent_unordered_map.h, concurrent_unordered_set.h, concurrent_vector.h, internal_concurrent_hash.h, internal_split_ordered_ List.h, ppl.h, pplcancellation_token.h, pplconcrt.h, pplinterface.h, ppltasks  
  
## <a name="see-also"></a>Consulte também  
 [Referência](reference-concurrency-runtime.md)

