---
title: "Namespace Concurrency | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "concurrent_priority_queue/concurrency"
  - "agents/concurrency"
  - "concurrent_vector/concurrency"
  - "concrt/concurrency"
  - "internal_split_ordered_list/concurrency"
  - "concurrent_queue/concurrency"
  - "pplcancellation_token/concurrency"
  - "pplinterface/concurrency"
  - "ppltasks/concurrency"
  - "ppl/concurrency"
  - "concurrent_unordered_map/concurrency"
  - "concrtrm/concurrency"
  - "concurrent_unordered_set/concurrency"
  - "pplconcrt/concurrency"
  - "internal_concurrent_hash/concurrency"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Namespace Concurrency"
ms.assetid: f1d33ca2-679b-4442-b140-22a9d9df61d1
caps.latest.revision: 37
caps.handback.revision: 37
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Namespace Concurrency
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

O namespace `Concurrency` oferece classes e funções que permitem que você acesse o Tempo de execução de simultaneidade, uma estrutura de programação simultânea para C++. Para obter mais informações, consulte [tempo de execução de simultaneidade](../../../parallel/concrt/concurrency-runtime.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace concurrency;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="namespaces"></a>Namespaces  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Namespace Concurrency::Extensibility](http://msdn.microsoft.com/pt-br/16a86ff2-128e-4edf-89e4-38aac79c81f9)||  
  
### <a name="typedefs"></a>Typedefs  
  
|Nome|Descrição|  
|----------|-----------------|  
|`runtime_object_identity`|Cada instância de mensagem tem uma identidade que o segue como é clonada e passado entre componentes de mensagens. Isso não pode ser o endereço do objeto de mensagem.|  
|`task_status`|Um tipo que representa o estado terminal de uma tarefa. Os valores válidos são `completed` e `canceled`.|  
|`TaskProc`|Uma abstração elementar para uma tarefa, definida como `void (__cdecl * TaskProc)(void *)`. A `TaskProc` é chamado para invocar o corpo de uma tarefa.|  
|`TaskProc_t`|Uma abstração elementar para uma tarefa, definida como `void (__cdecl * TaskProc_t)(void *)`. A `TaskProc` é chamado para invocar o corpo de uma tarefa.|  
  
### <a name="classes"></a>Classes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe affinity_partitioner](../Topic/affinity_partitioner%20Class.md)|O `affinity_partitioner` classe é semelhante de `static_partitioner` classe, mas ele melhora a afinidade de cache, sua escolha de mapeamento de subintervalos para threads de trabalho. Ele pode melhorar significativamente o desempenho quando um loop é executado novamente o mesmo conjunto de dados e os dados couberem no cache. Observe que o mesmo `affinity_partitioner` objeto deve ser usado com as iterações subsequentes de um loop paralelo é executado em um conjunto de dados específico, para se beneficiar de localidade dos dados.|  
|[Classe agente](../../../parallel/concrt/reference/agent-class.md)|Uma classe deve ser usada como uma classe base para todos os agentes independentes. Ele é usado para ocultar o estado dos outros agentes e interagir com a transmissão de mensagens.|  
|[Classe auto_partitioner](../../../parallel/concrt/reference/auto-partitioner-class.md)|O `auto_partitioner` classe representa o método padrão `parallel_for`, `parallel_for_each` e `parallel_transform` usar para o intervalo que itera através de partição. Esse método de particionamento employes roubo de balanceamento de carga de intervalo, bem como por-iterar cancelamento.|  
|[Classe bad_target](../../../parallel/concrt/reference/bad-target-class.md)|Esta classe descreve uma exceção gerada quando um bloco de mensagens é dado um ponteiro para um destino que é inválido para a operação que está sendo executada.|  
|[Classe da chamada](../../../parallel/concrt/reference/call-class.md)|Um `call` Bloco de mensagens é um várias fontes, ordenados `target_block` que chama uma função especificada quando receber uma mensagem.|  
|[Classe cancellation_token](../../../parallel/concrt/reference/cancellation-token-class.md)|O `cancellation_token` classe representa a capacidade de determinar se alguma operação foi solicitada para cancelar. Um token fornecido pode ser associado com um `task_group`, `structured_task_group`, ou `task` para fornecer cancelamento implícito. Também pode ser controlado de cancelamento ou ter um retorno de chamada registrado para se e quando associado `cancellation_token_source` é cancelada.|  
|[Classe cancellation_token_registration](../../../parallel/concrt/reference/cancellation-token-registration-class.md)|O `cancellation_token_registration` classe representa uma notificação de retorno de chamada de um `cancellation_token`. Quando o `register` método em um `cancellation_token` é usado para receber notificação quando ocorre o cancelamento, uma `cancellation_token_registration` objeto é retornado como um identificador para o retorno de chamada para que o chamador pode solicitar um retorno de chamada específico não ser feitas por meio do uso do `deregister` método.|  
|[Classe cancellation_token_source](../../../parallel/concrt/reference/cancellation-token-source-class.md)|O `cancellation_token_source` classe representa a capacidade de cancelar uma operação cancelável.|  
|[Classe Choice](../../../parallel/concrt/reference/choice-class.md)|Um `choice` Bloco de mensagens é um bloco de várias fonte, destino único que representa uma interação de fluxo de controle com um conjunto de fontes. O bloco de opção aguardará para qualquer uma das várias fontes para produzir uma mensagem e irá propagar o índice da origem que produziu a mensagem.|  
|[Classe combinable](../../../parallel/concrt/reference/combinable-class.md)|O `combinable<T>` objeto se destina a fornecer cópias de thread particular de dados, para executar computações subpropriedades de locais de thread sem bloqueio durante algoritmos paralelos. No final da operação em paralelo, as computações de subpropriedades thread privado, em seguida, podem ser mescladas em um resultado final. Essa classe pode ser usado em vez de uma variável compartilhada e pode resultar em uma melhoria de desempenho se há muita contenção naquela variável compartilhada.|  
|[Classe concurrent_priority_queue](../../../parallel/concrt/reference/concurrent-priority-queue-class.md)|O `concurrent_priority_queue` classe é um contêiner que permite que vários threads para itens simultaneamente push e pop. Itens são exibidos em ordem de prioridade em que a prioridade é determinada por um functor fornecido como um argumento de modelo.|  
|[Classe concurrent_queue](../Topic/concurrent_queue%20Class.md)|O `concurrent_queue` classe é uma classe de contêiner de sequência permite primeiro a entrar, PEPS acesso a seus elementos. Ele permite que um conjunto limitado de operações com segurança de simultaneidade, tais como `push` e `try_pop`.|  
|[Classe concurrent_unordered_map](../../../parallel/concrt/reference/concurrent-unordered-map-class.md)|O `concurrent_unordered_map` classe é um contêiner de prova de simultaneidade que controla uma sequência de comprimento variado de elementos do tipo `std::pair<const K, _Element_type>`. A sequência é representada de forma que permite a prova de simultaneidade acrescentar, acesso de elemento, acesso de iterador e operações de passagem do iterador.|  
|[Classe concurrent_unordered_multimap](../../../parallel/concrt/reference/concurrent-unordered-multimap-class.md)|O `concurrent_unordered_multimap` classe é um contêiner de prova de simultaneidade que controla uma sequência de comprimento variado de elementos do tipo `std::pair<const K, _Element_type>`. A sequência é representada de forma que permite a prova de simultaneidade acrescentar, acesso de elemento, acesso de iterador e operações de passagem do iterador.|  
|[Classe concurrent_unordered_multiset](../../../parallel/concrt/reference/concurrent-unordered-multiset-class.md)|O `concurrent_unordered_multiset` classe é um contêiner de prova de simultaneidade que controla uma sequência de comprimento variado de elementos do tipo K. A sequência é representada de forma que permite a prova de simultaneidade acrescentar, acesso de elemento, acesso de iterador e operações de passagem do iterador.|  
|[Classe concurrent_unordered_set](../../../parallel/concrt/reference/concurrent-unordered-set-class.md)|O `concurrent_unordered_set` classe é um contêiner de prova de simultaneidade que controla uma sequência de comprimento variado de elementos do tipo K. A sequência é representada de forma que permite a prova de simultaneidade acrescentar, acesso de elemento, acesso de iterador e operações de passagem do iterador.|  
|[Classe concurrent_vector](../../../parallel/concrt/reference/concurrent-vector-class.md)|O `concurrent_vector` classe é uma classe de contêiner de sequência que permite acesso aleatório a qualquer elemento. Ele permite a prova de simultaneidade acrescentar, acesso de elemento, acesso de iterador e operações de passagem do iterador.|  
|[Classe de contexto](Context%20Class.md)|Representa uma abstração de um contexto de execução.|  
|[Classe context_self_unblock](../../../parallel/concrt/reference/context-self-unblock-class.md)|Esta classe descreve uma exceção gerada quando o `Unblock` método de um `Context` objeto é chamado no mesmo contexto. Isso indica uma tentativa por um determinado contexto para desbloquear a mesmo.|  
|[Classe context_unblock_unbalanced](../../../parallel/concrt/reference/context-unblock-unbalanced-class.md)|Esta classe descreve uma exceção lançada quando chama o `Block` e `Unblock` métodos de um `Context` objeto não estão emparelhados corretamente.|  
|[Classe CRITICAL_SECTION](../../../parallel/concrt/reference/critical-section-class.md)|Um mutex não reentrante que reconhece explicitamente o tempo de execução de simultaneidade.|  
|[Classe CurrentScheduler](../Topic/CurrentScheduler%20Class.md)|Representa uma abstração para o Agendador atual associado ao contexto de chamada.|  
|[Classe default_scheduler_exists](../../../parallel/concrt/reference/default-scheduler-exists-class.md)|Esta classe descreve uma exceção gerada quando o `Scheduler::SetDefaultSchedulerPolicy` método é chamado quando um agendador padrão já existe dentro do processo.|  
|[Classe Event](../Topic/event%20Class.md)|Um evento de redefinição manual que reconhece explicitamente o tempo de execução de simultaneidade.|  
|[Classe improper_lock](../../../parallel/concrt/reference/improper-lock-class.md)|Esta classe descreve uma exceção gerada quando um bloqueio é adquirido incorretamente.|  
|[Classe improper_scheduler_attach](../../../parallel/concrt/reference/improper-scheduler-attach-class.md)|Esta classe descreve uma exceção gerada quando o `Attach` método for chamado em um `Scheduler` objeto que já está anexado ao contexto atual.|  
|[Classe improper_scheduler_detach](../Topic/improper_scheduler_detach%20Class.md)|Esta classe descreve uma exceção gerada quando o `CurrentScheduler::Detach` método for chamado em um contexto que não foi anexado a qualquer Agendador usando o `Attach` método de um `Scheduler` objeto.|  
|[Classe improper_scheduler_reference](../Topic/improper_scheduler_reference%20Class.md)|Esta classe descreve uma exceção gerada quando o `Reference` método for chamado em um `Scheduler` objeto que está sendo desligado, em um contexto que não faz parte do que o Agendador.|  
|[Classe invalid_link_target](../../../parallel/concrt/reference/invalid-link-target-class.md)|Esta classe descreve uma exceção gerada quando o `link_target` método de um bloco de mensagens é chamado e o bloco de mensagens não pode vincular ao destino. Isso pode ser o resultado de exceder o número de links que o bloco de mensagens é permitido ou a tentativa de vincular a um destino específico duas vezes para a mesma fonte.|  
|[Classe invalid_multiple_scheduling](../../../parallel/concrt/reference/invalid-multiple-scheduling-class.md)|Esta classe descreve uma exceção gerada quando uma `task_handle` objeto é agendada várias vezes usando o `run` método de um `task_group` ou `structured_task_group` objeto sem uma chamada intermediária para o `wait` ou `run_and_wait` métodos.|  
|[Classe invalid_operation](../Topic/invalid_operation%20Class.md)|Esta classe descreve uma exceção gerada quando ocorre uma operação inválida que não é descrita com mais precisão por outro tipo de exceção lançado pelo tempo de execução de simultaneidade.|  
|[Classe invalid_oversubscribe_operation](../../../parallel/concrt/reference/invalid-oversubscribe-operation-class.md)|Esta classe descreve uma exceção gerada quando o `Context::Oversubscribe` método for chamado com o `_BeginOversubscription` parâmetro definido como `false` sem uma chamada anterior para o `Context::Oversubscribe` método com o `_BeginOversubscription` parâmetro definido como `true`.|  
|[Classe invalid_scheduler_policy_key](../../../parallel/concrt/reference/invalid-scheduler-policy-key-class.md)|Esta classe descreve uma exceção gerada quando um inválido ou desconhecido de chave é passado para um `SchedulerPolicy` construtor do objeto, ou o `SetPolicyValue` método de um `SchedulerPolicy` objeto é passado uma chave que deve ser alterada usando outros meios, como o `SetConcurrencyLimits` método.|  
|[Classe invalid_scheduler_policy_thread_specification](../../../parallel/concrt/reference/invalid-scheduler-policy-thread-specification-class.md)|Esta classe descreve uma exceção lançada quando é feita uma tentativa de definir os limites de simultaneidade de um `SchedulerPolicy` objeto, de modo que o valor da `MinConcurrency` chave é menor que o valor da `MaxConcurrency` chave.|  
|[Classe invalid_scheduler_policy_value](../../../parallel/concrt/reference/invalid-scheduler-policy-value-class.md)|Esta classe descreve uma exceção gerada quando uma chave de política de uma `SchedulerPolicy` objeto é definido como um valor inválido para essa chave.|  
|[Classe ISource](../../../parallel/concrt/reference/isource-class.md)|O `ISource` classe é a interface para todos os blocos de origem. Blocos de código-fonte propaguem as mensagens `ITarget` blocos.|  
|[Classe ITarget](../../../parallel/concrt/reference/itarget-class.md)|O `ITarget` classe é a interface de todos os blocos de destino. Blocos de destino consumam mensagens oferecidas a eles por `ISource` blocos.|  
|[Classe JOIN](../Topic/join%20Class.md)|Um `join` Bloco de mensagens é um único destino, com várias fontes, ordenada `propagator_block` juntos, que combina as mensagens do tipo `T` de cada uma das suas fontes.|  
|[Classe Location](../../../parallel/concrt/reference/location-class.md)|Uma abstração de um local físico no hardware.|  
|[Classe de mensagem](../../../parallel/concrt/reference/message-class.md)|O envelope de mensagem básica que contém a carga de dados sendo passada entre blocos de mensagens.|  
|[Classe message_not_found](../../../parallel/concrt/reference/message-not-found-class.md)|Esta classe descreve uma exceção lançada quando um bloco de mensagens não pode localizar uma mensagem solicitada.|  
|[Classe message_processor](../../../parallel/concrt/reference/message-processor-class.md)|O `message_processor` classe é a classe base abstrata para processamento de `message` objetos. Não há nenhuma garantia sobre a ordem das mensagens.|  
|[Classe missing_wait](../../../parallel/concrt/reference/missing-wait-class.md)|Esta classe descreve uma exceção gerada quando há tarefas ainda está agendadas para ser um `task_group` ou `structured_task_group` do objeto no momento do objeto destruidor é executado. Essa exceção nunca será gerada se o destruidor for atingido devido a uma pilha de desenrolamento como resultado de uma exceção.|  
|[Classe multi_link_registry](../../../parallel/concrt/reference/multi-link-registry-class.md)|O `multi_link_registry` objeto é um `network_link_registry` que gerencia vários blocos de código-fonte ou vários blocos de destino.|  
|[Classe multitype_join](../../../parallel/concrt/reference/multitype-join-class.md)|Um `multitype_join` Bloco de mensagens é um bloco de mensagens com várias fonte, destino único que juntos combina mensagens de diferentes tipos de cada uma das suas fontes e oferece uma tupla das mensagens combinadas para seus destinos.|  
|[Classe nested_scheduler_missing_detach](../../../parallel/concrt/reference/nested-scheduler-missing-detach-class.md)|Esta classe descreve uma exceção gerada quando o tempo de execução de simultaneidade detecta que você não chamou o `CurrentScheduler::Detach` método em um contexto que é anexado a um segundo Agendador usando o `Attach` método o `Scheduler` objeto.|  
|[Classe network_link_registry](../Topic/network_link_registry%20Class.md)|O `network_link_registry` gerencia a classe base abstrata os links entre os blocos de origem e destino.|  
|[Classe operation_timed_out](../../../parallel/concrt/reference/operation-timed-out-class.md)|Esta classe descreve uma exceção lançada quando uma operação expirou.|  
|[Classe ordered_message_processor](../Topic/ordered_message_processor%20Class.md)|Um `ordered_message_processor` é um `message_processor` que permite que blocos de mensagens processar as mensagens na ordem em que foram recebidas.|  
|[Classe overwrite_buffer](../../../parallel/concrt/reference/overwrite-buffer-class.md)|Um `overwrite_buffer` Bloco de mensagens é um destino de vários com várias fontes, ordenada `propagator_block` capaz de armazenar uma única mensagem por vez. Novas mensagens substituem aqueles mantido anteriormente.|  
|[Classe progress_reporter](../../../parallel/concrt/reference/progress-reporter-class.md)|A classe de relator de andamento permite criar relatórios de notificações de andamento de um tipo específico. Cada objeto progress_reporter está associado a uma determinada ação ou operação assíncrona.|  
|[Classe propagator_block](../../../parallel/concrt/reference/propagator-block-class.md)|O `propagator_block` classe é uma classe base abstrata para blocos de mensagens de origem e destino. Ele combina a funcionalidade de ambos os `source_block` e `target_block` classes.|  
|[Classe reader_writer_lock](../Topic/reader_writer_lock%20Class.md)|Um bloqueio de leitor-gravador baseado em fila preferência gravador com local apenas girando. O bloqueio concede primeiro em - primeiro acesso (FIFO) para escritores e impede os leitores sob uma carga contínua de gravadores.|  
|[Classe ScheduleGroup](../Topic/ScheduleGroup%20Class.md)|Representa uma abstração para um grupo de agendamento. Grupos de agendamento de organizam um conjunto de trabalho relacionados que se beneficia de ser agendado juntos temporariamente, por outra tarefa em execução no mesmo grupo antes de passar para outro grupo ou espacialmente, executando vários itens dentro do mesmo grupo no mesmo nó NUMA ou soquete físico.|  
|[Classe de Agendador](../../../parallel/concrt/reference/scheduler-class.md)|Representa uma abstração de um agendador de tempo de execução de simultaneidade.|  
|[Classe scheduler_not_attached](../Topic/scheduler_not_attached%20Class.md)|Esta classe descreve uma exceção gerada quando é executada uma operação que requer um agendador a ser anexado ao contexto atual e não.|  
|[Classe scheduler_resource_allocation_error](../../../parallel/concrt/reference/scheduler-resource-allocation-error-class.md)|Esta classe descreve uma exceção lançada devido a uma falha ao adquirir um recurso crítico em tempo de execução de simultaneidade.|  
|[Classe scheduler_worker_creation_error](../Topic/scheduler_worker_creation_error%20Class.md)|Esta classe descreve uma exceção lançada devido a uma falha ao criar um contexto de execução do trabalho em tempo de execução de simultaneidade.|  
|[Classe SchedulerPolicy](../../../parallel/concrt/reference/schedulerpolicy-class.md)|O `SchedulerPolicy` classe contém um conjunto de pares chave/valor, um para cada elemento de diretiva que controlam o comportamento de uma instância de Agendador.|  
|[Classe simple_partitioner](../Topic/simple_partitioner%20Class.md)|O `simple_partitioner` classe representa um particionamento estático do intervalo iterado pelo `parallel_for`. O particionador divide o intervalo em partes, de modo que cada parte tenha pelo menos o número de iterações especificado pelo tamanho do bloco.|  
|[Classe single_assignment](../../../parallel/concrt/reference/single-assignment-class.md)|Um `single_assignment` Bloco de mensagens é um destino de vários com várias fontes, ordenada `propagator_block` capaz de armazenar uma única gravação-depois de `message`.|  
|[Classe single_link_registry](../Topic/single_link_registry%20Class.md)|O `single_link_registry` objeto é um `network_link_registry` que gerencia apenas um único bloco de origem ou de destino.|  
|[Classe source_block](../Topic/source_block%20Class.md)|O `source_block` classe é uma classe base abstrata para blocos de código-fonte. A classe fornece funcionalidade de gerenciamento básico de link como comuns bem como verificações de erro.|  
|[Classe source_link_manager](../Topic/source_link_manager%20Class.md)|O `source_link_manager` objeto gerencia conexões de rede bloquear mensagens com `ISource` blocos.|  
|[Classe static_partitioner](../Topic/static_partitioner%20Class.md)|O `static_partitioner` classe representa um particionamento estático do intervalo iterado pelo `parallel_for`. O particionador divide o intervalo em quantos blocos há trabalhadores disponíveis para o Agendador underyling.|  
|[Classe structured_task_group](../../../parallel/concrt/reference/structured-task-group-class.md)|O `structured_task_group` classe representa uma coleção altamente estruturada de trabalho paralelos. É possível enfileirar tarefas paralelas individuais para um `structured_task_group` usando `task_handle` objetos e aguarde a conclusão ou cancelar o grupo de tarefas antes de eles tem terminado a execução, que anulará as tarefas que não começaram a execução.|  
|[Classe target_block](../../../parallel/concrt/reference/target-block-class.md)|O `target_block` classe é uma classe base abstrata que fornece funcionalidade de gerenciamento básico de link e verificação de erros para o destino bloqueia somente.|  
|[tarefa de classe (tempo de execução de simultaneidade)](../../../parallel/concrt/reference/task-class-concurrency-runtime.md)|A classe `task` da Biblioteca de Padrões Paralelos (PPL). O objeto `task` representa o trabalho que pode ser executado de forma assíncrona e simultaneamente com outras tarefas e o trabalho paralelo produzido por algoritmos paralelos no Tempo de execução de simultaneidade. Produz um resultado de tipo `_ResultType` após uma conclusão bem-sucedida. Tarefas do tipo `task<void>` não produzem resultados. Uma tarefa pode ser aguardada e cancelada independentemente de outras tarefas. Ela também pode ser composta por outras tarefas usando continuations(`then`) e os padrões join(`when_all`) e choice(`when_any`).|  
|[Classe task_canceled](../../../parallel/concrt/reference/task-canceled-class.md)|Esta classe descreve uma exceção lançada pela camada de tarefas de PPL para forçar a cancelamento da tarefa atual. Ela também é gerada pelo `get()` método [tarefa](http://msdn.microsoft.com/pt-br/5389e8a5-5038-40b6-844a-55e9b58ad35f), para uma tarefa cancelada.|  
|[Classe task_completion_event](../../../parallel/concrt/reference/task-completion-event-class.md)|A classe `task_completion_event` permite atrasar a execução de uma tarefa até que uma condição seja atendida, ou iniciar uma tarefa em resposta a um evento externo.|  
|[Classe task_continuation_context](../../../parallel/concrt/reference/task-continuation-context-class.md)|A classe `task_continuation_context` permite que você especifique onde gostaria que uma continuação fosse executada. Só é útil para usar essa classe em um aplicativo da Windows Store. Para aplicativos da Windows Store, o contexto de execução da continuação da tarefa é determinado pelo tempo de execução e não é configurável.|  
|[Classe task_group](../Topic/task_group%20Class.md)|O `task_group` classe representa uma coleção de trabalho paralelo que pode ser cancelada ou aguardada.|  
|[Classe task_handle](../../../parallel/concrt/reference/task-handle-class.md)|O `task_handle` classe representa um item de trabalho paralelas individuais. Ele encapsula as instruções e os dados necessários para executar um trabalho.|  
|[task_options classe (tempo de execução de simultaneidade)](../Topic/task_options%20Class%20\(Concurrency%20Runtime\).md)|Representa as opções permitidas para criar uma tarefa|  
|[Classe Timer](../../../parallel/concrt/reference/timer-class.md)|Um `timer` Bloco de mensagens é um destino único `source_block` capaz de enviar uma mensagem para seu destino após um período de tempo decorrido ou em intervalos específicos.|  
|[Classe Transformer](../../../parallel/concrt/reference/transformer-class.md)|Um `transformer` Bloco de mensagens é um único destino, com várias fontes, ordenada `propagator_block` que pode aceitar mensagens de um tipo e é capaz de armazenar um número ilimitado de mensagens de um tipo diferente.|  
|[Classe unbounded_buffer](../Topic/unbounded_buffer%20Class.md)|Um `unbounded_buffer` Bloco de mensagens é um destino de vários com várias fontes, ordenada `propagator_block` capaz de armazenar um número ilimitado de mensagens.|  
|[Classe unsupported_os](../../../parallel/concrt/reference/unsupported-os-class.md)|Esta classe descreve uma exceção gerada quando é usado um sistema operacional sem suporte.|  
  
### <a name="structures"></a>Estruturas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Estrutura DispatchState](../../../parallel/concrt/reference/dispatchstate-structure.md)|O `DispatchState` estrutura é usada para transferir o estado para o `IExecutionContext::Dispatch` método. Ele descreve as circunstâncias em que o `Dispatch` método é invocado em um `IExecutionContext` interface.|  
|[Estrutura IExecutionContext](../Topic/IExecutionContext%20Structure.md)|Uma interface para um contexto de execução que pode executar em um determinado processador virtual e ser cooperativamente contexto alternado.|  
|[Estrutura IExecutionResource](../../../parallel/concrt/reference/iexecutionresource-structure.md)|Uma abstração de um thread de hardware.|  
|[Estrutura IResourceManager](../../../parallel/concrt/reference/iresourcemanager-structure.md)|Uma interface para o Gerenciador de recursos do tempo de execução de simultaneidade. Essa é a interface pela qual agendadores se comunicar com o Gerenciador de recursos.|  
|[Estrutura IScheduler](../../../parallel/concrt/reference/ischeduler-structure.md)|Uma interface para uma abstração de um agendador de trabalho. O Gerenciador de recursos do tempo de execução de simultaneidade usa essa interface para se comunicar com os agendadores de trabalho.|  
|[Estrutura ISchedulerProxy](../../../parallel/concrt/reference/ischedulerproxy-structure.md)|A interface pela qual agendadores se comunicar com o Gerenciador de recursos do tempo de execução de simultaneidade para negociar a alocação de recursos.|  
|[Estrutura IThreadProxy](../../../parallel/concrt/reference/ithreadproxy-structure.md)|Uma abstração de um thread de execução. Dependendo do `SchedulerType` chave da diretiva do Agendador é criar o Gerenciador de recursos concederá a você um proxy de thread é apoiado por um thread do Win32 regular ou um thread (UMS) agendáveis do modo de usuário. Threads UMS são suportados em sistemas operacionais de 64 bits com a versão do Windows 7 e superior.|  
|[Estrutura ITopologyExecutionResource](../../../parallel/concrt/reference/itopologyexecutionresource-structure.md)|Uma interface para um recurso de execução, conforme definido pelo Gerenciador de recursos.|  
|[Estrutura ITopologyNode](../../../parallel/concrt/reference/itopologynode-structure.md)|Uma interface para um nó de topologia, conforme definido pelo Gerenciador de recursos. Um nó contém um ou mais recursos de execução.|  
|[Estrutura IUMSCompletionList](../../../parallel/concrt/reference/iumscompletionlist-structure.md)|Representa uma lista de conclusão UMS. Quando bloqueia um thread UMS, o Agendador designado de agendamento de contexto é despachado para tomar uma decisão do que agendar na raiz do processador virtual subjacente enquanto o thread original está bloqueado. Quando o thread original desbloqueia, o sistema operacional enfileira à lista de conclusão que pode ser acessada por meio dessa interface. O Agendador pode consultar a lista de conclusão no contexto de programação designado ou qualquer outro lugar, que ele procura por trabalho.|  
|[Estrutura IUMSScheduler](../../../parallel/concrt/reference/iumsscheduler-structure.md)|Uma interface para uma abstração de um agendador de trabalho que deseja que o Gerenciador de recursos do tempo de execução de simultaneidade para entregá-lo threads (UMS) agendáveis de modo de usuário. O Gerenciador de recursos usa essa interface para se comunicar com os agendadores do thread UMS. A interface `IUMSScheduler` herda da interface `IScheduler`.|  
|[Estrutura IUMSThreadProxy](../../../parallel/concrt/reference/iumsthreadproxy-structure.md)|Uma abstração de um thread de execução. Se desejar que o Agendador para receber threads (UMS) agendáveis de modo de usuário, defina o valor para o elemento de diretiva Agendador `SchedulerKind` para `UmsThreadDefault`, e implementar o `IUMSScheduler` interface. Threads UMS são somente com suporte em sistemas operacionais de 64 bits com a versão do Windows 7 e superior.|  
|[Estrutura IUMSUnblockNotification](../../../parallel/concrt/reference/iumsunblocknotification-structure.md)|Representa uma notificação do Gerenciador de recursos que o proxy thread bloqueado e disparado um retorno para o Agendador designado contexto de programação foi desbloqueado e está pronto para ser agendado. Essa interface é inválida quando o contexto de execução associadas do proxy de thread, retornado do `GetContext` método, será reagendada.|  
|[Estrutura IVirtualProcessorRoot](../../../parallel/concrt/reference/ivirtualprocessorroot-structure.md)|Uma abstração de um thread de hardware no qual um proxy de thread pode executar.|  
|[Estrutura scheduler_interface](../../../parallel/concrt/reference/scheduler-interface-structure.md)|Interface do Agendador|  
|[scheduler_ptr estrutura (tempo de execução de simultaneidade)](../../../parallel/concrt/reference/scheduler-ptr-structure-concurrency-runtime.md)|Representa um ponteiro para um agendador. Esta classe existe para permitir a especificação de um tempo de vida compartilhada usando shared_ptr ou apenas uma referência simples usando o ponteiro bruto.|  
  
### <a name="enumerations"></a>Enumerações  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Enumeração agent_status](../Topic/agent_status%20Enumeration.md)|Os estados válidos para um `agent`.|  
|[Enumeração Agents_EventType](../Topic/Agents_EventType%20Enumeration.md)|Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pela biblioteca de agentes|  
|[Enumeração ConcRT_EventType](../Topic/ConcRT_EventType%20Enumeration.md)|Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pelo tempo de execução de simultaneidade.|  
|[Enumeração Concrt_TraceFlags](../Topic/Concrt_TraceFlags%20Enumeration.md)|Sinalizadores de rastreamento para os tipos de evento|  
|[Enumeração CriticalRegionType](../Topic/CriticalRegionType%20Enumeration.md)|O tipo de região crítica, que um contexto está dentro.|  
|[Enumeração DynamicProgressFeedbackType](../Topic/DynamicProgressFeedbackType%20Enumeration.md)|Usado pelo `DynamicProgressFeedback` baseado em políticas para descrever se recursos para o Agendador serão balanceados acordo com informações estatísticas coletadas do Agendador ou apenas em processadores virtuais sai no estado ocioso por meio de chamadas para o `Activate` e `Deactivate` métodos o `IVirtualProcessorRoot` interface. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [enumeração PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md).|  
|[Enumeração join_type](../Topic/join_type%20Enumeration.md)|O tipo de um `join` Bloco de mensagens.|  
|[Enumeração message_status](../Topic/message_status%20Enumeration.md)|As respostas válidas para uma oferta de uma `message` objeto para um bloco.|  
|[Enumeração PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md)|Chaves de política que descrevem aspectos do comportamento do Agendador. Cada elemento de diretiva é descrito por um par chave-valor. Para obter mais informações sobre políticas de agendador e seu impacto agendadores, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).|  
|[Enumeração SchedulerType](../Topic/SchedulerType%20Enumeration.md)|Usado pelo `SchedulerKind` diretiva descrever o tipo de threads que o Agendador deve utilizar para contextos de execução subjacente. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [enumeração PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md).|  
|[Enumeração SchedulingProtocolType](../Topic/SchedulingProtocolType%20Enumeration.md)|Usado pelo `SchedulingProtocol` diretiva descrever qual algoritmo de agendamento será utilizado para o Agendador. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [enumeração PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md).|  
|[Enumeração SwitchingProxyState](../Topic/SwitchingProxyState%20Enumeration.md)|Usada para indicar o estado de em que um proxy thread está, quando ele está em execução uma alternância de contexto cooperativo para proxy de um thread diferente.|  
|[Enumeração task_group_status](../Topic/task_group_status%20Enumeration.md)|Descreve o status de execução de um `task_group` ou `structured_task_group` objeto. Um valor desse tipo é retornado por diversos métodos que aguardar as tarefas agendadas para um grupo de tarefas para concluir.|  
|[Enumeração WinRTInitializationType](../Topic/WinRTInitializationType%20Enumeration.md)|Usado pelo `WinRTInitialization` diretiva descrever se e como o tempo de execução do Windows será inicializado em threads de Agendador para um aplicativo que é executado em sistemas operacionais com a versão do Windows 8 ou superior. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [enumeração PolicyElementKey](../Topic/PolicyElementKey%20Enumeration.md).|  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Função ALLOC](../Topic/Alloc%20Function.md)|Aloca um bloco de memória do tamanho especificado de Suballocator de cache de simultaneidade em tempo de execução.|  
|[Função asend](../Topic/asend%20Function.md)|Sobrecarregado. Uma operação de envio assíncronas que agenda uma tarefa para propagar os dados para o bloco de destino.|  
|[Função cancel_current_task](../Topic/cancel_current_task%20Function.md)|Cancela a tarefa atualmente em execução. Essa função pode ser chamada de dentro do corpo de uma tarefa para interromper a execução da tarefa e fazer com que ela entre no estado `canceled`.<br /><br /> Não é um cenário com suporte para chamar essa função se você não estiver dentro do corpo de uma `task`. Isso resultará em um comportamento indefinido, tal como um travamento ou um desligamento em seu aplicativo.|  
|[Função create_async](../Topic/create_async%20Function.md)|Cria uma construção assíncrona de Tempo de execução do Windows com base em um objeto de função ou lambda fornecido pelo usuário. O tipo de retorno de `create_async` é `IAsyncAction^`, `IAsyncActionWithProgress<TProgress>^`, `IAsyncOperation<TResult>^` ou `IAsyncOperationWithProgress<TResult, TProgress>^` com base na assinatura do lambda passada para o método.|  
|[Função create_task](../Topic/create_task%20Function.md)|Sobrecarregado. Cria um PPL [tarefa](http://msdn.microsoft.com/pt-br/5389e8a5-5038-40b6-844a-55e9b58ad35f) objeto. `create_task` pode ser usado em qualquer lugar você teria que usar um construtor de tarefa. Ele é fornecido principalmente para sua conveniência, pois permite o uso do `auto` palavra-chave durante a criação de tarefas.|  
|[Função CreateResourceManager](../Topic/CreateResourceManager%20Function.md)|Retorna uma interface que representa a instância singleton do Gerenciador de recursos do tempo de execução de simultaneidade. O Gerenciador de recursos é responsável por atribuir recursos a agendadores que deseja cooperar entre si.|  
|[Função DisableTracing](../Topic/DisableTracing%20Function.md)|Desabilita o rastreamento em tempo de execução de simultaneidade. Essa função é substituída porque o rastreamento ETW não é registrado por padrão.|  
|[Função EnableTracing](../Topic/EnableTracing%20Function.md)|Habilita o rastreamento em tempo de execução de simultaneidade. Essa função é substituída porque o rastreamento ETW está ativada por padrão.|  
|[Função Free](../Topic/Free%20Function.md)|Libera um bloco de memória alocado anteriormente pelo `Alloc` método Suballocator de cache de simultaneidade em tempo de execução.|  
|[Função (tempo de execução de simultaneidade) get_ambient_scheduler](../Topic/get_ambient_scheduler%20Function%20\(Concurrency%20Runtime\).md)||  
|[Função GetExecutionContextId](../Topic/GetExecutionContextId%20Function.md)|Retorna um identificador exclusivo que pode ser atribuído a um contexto de execução que implementa o `IExecutionContext` interface.|  
|[Função GetOSVersion](../Topic/GetOSVersion%20Function.md)|Retorna a versão do sistema operacional.|  
|[Função GetProcessorCount](../Topic/GetProcessorCount%20Function.md)|Retorna o número de threads de hardware no sistema subjacente.|  
|[Função GetProcessorNodeCount](../Topic/GetProcessorNodeCount%20Function.md)|Retorna o número de nós NUMA ou pacotes de processador no sistema subjacente.|  
|[Função GetSchedulerId](../Topic/GetSchedulerId%20Function.md)|Retorna um identificador exclusivo que pode ser atribuído a um agendador que implementa o `IScheduler` interface.|  
|[Função interruption_point](../Topic/interruption_point%20Function.md)|Cria um ponto de interrupção para cancelamento. Se um cancelamento está em andamento no contexto em que essa função é chamada, isso gerará uma exceção interna que anula a execução do trabalho atualmente em execução paralela. Se o cancelamento não está em andamento, a função não faz nada.|  
|[Função is_current_task_group_canceling](../Topic/is_current_task_group_canceling%20Function.md)|Retorna uma indicação de se a tarefa de grupo que está atualmente em execução embutido no contexto atual está no meio de um cancelamento ativo (ou estarão em breve). Observe que, se não houver nenhum grupo de tarefas atualmente em execução embutido no contexto atual, `false` será retornado.|  
|[Função make_choice](../Topic/make_choice%20Function.md)|Sobrecarregado. Constrói um `choice` Bloco de mensagens de um recurso opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.|  
|[Função make_greedy_join](../Topic/make_greedy_join%20Function.md)|Sobrecarregado. Constrói um `greedy multitype_join` Bloco de mensagens de um recurso opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.|  
|[Função make_join](../Topic/make_join%20Function.md)|Sobrecarregado. Constrói um `non_greedy multitype_join` Bloco de mensagens de um recurso opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.|  
|[Função make_task](../Topic/make_task%20Function.md)|Um método de fábrica para criar um `task_handle` objeto.|  
|[Função parallel_buffered_sort](../Topic/parallel_buffered_sort%20Function.md)|Sobrecarregado. Organiza os elementos em um intervalo especificado em uma ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Essa função é semanticamente similar a `std::sort` pois ela é uma classificação de comparação instável, baseada no local, exceto que ele precisa `O(n)` espaço adicional e requer inicialização padrão para os elementos que estão sendo classificados.|  
|[Função parallel_for](../Topic/parallel_for%20Function.md)|Sobrecarregado. `parallel_for` itera em um intervalo de índices e executa uma função fornecida pelo usuário em cada iteração em paralelo.|  
|[Função parallel_for_each](../Topic/parallel_for_each%20Function.md)|Sobrecarregado. `parallel_for_each` aplica uma função especificada a cada elemento dentro de um intervalo, em paralelo. É semanticamente equivalente ao `for_each` funcionar a `std` namespace, exceto iteração sobre os elementos é executada em paralelo, e a ordem de iteração é especificada. O argumento `_Func` deve oferecer suporte a um operador de chamada de função do formulário `operator()(T)` onde o parâmetro `T` é o tipo de item do contêiner que está sendo iterado.|  
|[Função parallel_invoke](../Topic/parallel_invoke%20Function.md)|Sobrecarregado. Executa os objetos de função fornecidos como parâmetros em paralelo e bloqueia até que tem terminado a execução. Cada objeto de função pode ser uma expressão lambda, um ponteiro para função, ou qualquer objeto que suporta o operador de chamada de função com a assinatura `void operator()()`.|  
|[Função parallel_radixsort](../Topic/parallel_radixsort%20Function.md)|Sobrecarregado. Organiza elementos em um intervalo especificado em uma ordem não decrescente usando um algoritmo de classificação de base. Essa é uma função de classificação estável que exige uma função de projeção que pode projetar os elementos a serem classificados em chaves de tipo inteiro não assinadas. Inicialização padrão é necessária para os elementos que estão sendo classificados.|  
|[Função parallel_reduce](../Topic/parallel_reduce%20Function.md)|Sobrecarregado. Calcula a soma de todos os elementos em um intervalo especificado por Calculando somas parciais sucessivas ou calcula o resultado de resultados parciais sucessivos da mesma forma obtidos com o uso de uma operação binária especificada diferente da soma, em paralelo. `parallel_reduce` é semanticamente similar a `std::accumulate`, exceto que ele requer que a operação de binário a ser associativa e requer um valor de identidade em vez de um valor inicial.|  
|[Função parallel_sort](../Topic/parallel_sort%20Function.md)|Sobrecarregado. Organiza os elementos em um intervalo especificado em uma ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Essa função é semanticamente similar a `std::sort` que é uma espécie de comparar instável, baseada no local.|  
|[Função parallel_transform](../Topic/parallel_transform%20Function.md)|Sobrecarregado. Aplica um objeto de função especificado para cada elemento em um intervalo de origem ou para um par de elementos de dois intervalos de origem e copia os valores de retorno do objeto de função em um intervalo de destino, em paralelo. Nesse funcional é semanticamente equivalente a `std::transform`.|  
|[Função Receive](../Topic/receive%20Function.md)|Sobrecarregado. Geral receber implementação, permitindo um contexto de esperar para dados de exatamente uma fonte e filtrar os valores aceitos.|  
|[Função run_with_cancellation_token](../Topic/run_with_cancellation_token%20Function.md)|Executa um objeto de função imediatamente e de forma síncrona no contexto de um token de cancelamento fornecido.|  
|[Função Send](../Topic/send%20Function.md)|Sobrecarregado. Uma operação de envio síncrono, que aguarda até que o destino aceita ou recusa a mensagem.|  
|[Função (tempo de execução de simultaneidade) set_ambient_scheduler](../Topic/set_ambient_scheduler%20Function%20\(Concurrency%20Runtime\).md)||  
|[Função set_task_execution_resources](../Topic/set_task_execution_resources%20Function.md)|Sobrecarregado. Restringe os recursos de execução usados pelos threads de trabalho interno de tempo de execução de simultaneidade para a afinidade do conjunto especificado.<br /><br /> Ele é válido para chamar esse método antes do Gerenciador de recursos tiver sido criado, ou entre dois tempos de vida do Gerenciador de recursos. Ele pode ser chamado várias vezes enquanto o Gerenciador de recursos não existe no momento da invocação. Após um limite de afinidade foi definido, ela permanecerá em vigor até a próxima chamada válida para o `set_task_execution_resources` método.<br /><br /> A máscara de afinidade fornecida não precisa ser um subconjunto da máscara de afinidade de processo. A afinidade do processo será atualizada se necessário.|  
|[Função swap](../Topic/swap%20Function.md)|Troca os elementos de dois `concurrent_vector` objetos.|  
|[Função (tempo de execução de simultaneidade) task_from_exception](../Topic/task_from_exception%20Function%20\(Concurrency%20Runtime\).md)||  
|[Função (tempo de execução de simultaneidade) task_from_result](../Topic/task_from_result%20Function%20\(Concurrency%20Runtime\).md)||  
|[Função Trace_agents_register_name](../Topic/Trace_agents_register_name%20Function.md)|Associa o nome fornecido para o bloco de mensagens ou o agente no rastreamento ETW.|  
|[Função try_receive](../Topic/try_receive%20Function.md)|Sobrecarregado. Geral try-receive implementação, permitindo um contexto procurar dados de exatamente uma fonte e filtrar os valores aceitos. Se os dados não estiverem prontos, o método retornará false.|  
|[Função Wait](../Topic/wait%20Function.md)|Pausa o contexto atual para um período de tempo especificado.|  
|[Função when_all](../Topic/when_all%20Function.md)|Cria uma tarefa que será concluída com êxito quando todas as tarefas fornecidas como argumentos forem concluídas com êxito.|  
|[Função when_any](../Topic/when_any%20Function.md)|Sobrecarregado. Cria uma tarefa que será concluída com êxito quando todas as tarefas fornecidas como argumentos forem concluídas com êxito.|  
  
### <a name="operators"></a>Operadores  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operador! = operador](../Topic/operator!=%20Operator.md)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador não é igual do `concurrent_vector` objeto no lado direito.|  
|[operador & & operador](../Topic/operator&&%20Operator.md)|Sobrecarregado. Cria uma tarefa que será concluída com êxito quando ambas as tarefas fornecidas como argumentos forem concluídas com êxito.|  
|[operador &#124; &#124; Operador](../Topic/operator%7C%7C%20Operator.md)|Sobrecarregado. Cria uma tarefa que será concluída com êxito quando qualquer uma das tarefas fornecidas como argumentos forem concluídas com êxito.|  
|[operador < operador](../Topic/operator%3C%20Operator.md)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é menor do que o `concurrent_vector` objeto no lado direito.|  
|[operador < operador =](../Topic/operator%3C=%20Operator.md)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é menor ou igual a `concurrent_vector` objeto no lado direito.|  
|[operador Operator = =](../Topic/operator==%20Operator.md)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é igual do `concurrent_vector` objeto no lado direito.|  
|[operador > operador](../Topic/operator%3E%20Operator.md)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é maior que o `concurrent_vector` objeto no lado direito.|  
|[operador > = operador](../Topic/operator%3E=%20Operator.md)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é maior que ou igual a `concurrent_vector` objeto no lado direito.|  
  
### <a name="constants"></a>Constantes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante AgentEventGuid](../Topic/AgentEventGuid%20Constant.md)|Uma categoria de GUID ({B9B5B78C-0713-4898-A21A-C67949DCED07}) que descreve eventos ETW acionados pela biblioteca de agentes no tempo de execução de simultaneidade.|  
|[Constante ChoreEventGuid](../Topic/ChoreEventGuid%20Constant.md)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionados a tarefas ou tarefas.|  
|[Constante ConcRT_ProviderGuid](../Topic/ConcRT_ProviderGuid%20Constant.md)|O GUID para o tempo de execução de simultaneidade do provedor ETW.|  
|[Constante CONCRT_RM_VERSION_1](../Topic/CONCRT_RM_VERSION_1%20Constant.md)|Indica suporte da interface do Gerenciador de recursos definido no Visual Studio 2010.|  
|[Constante ConcRTEventGuid](../Topic/ConcRTEventGuid%20Constant.md)|Uma categoria de GUID descrevendo eventos ETW disparado no tempo de execução de simultaneidade que não são mais especificamente descritos por outra categoria.|  
|[Constante ContextEventGuid](../Topic/ContextEventGuid%20Constant.md)|Uma categoria de GUID descrevendo eventos ETW disparado no tempo de execução de simultaneidade que estão diretamente relacionados aos contextos.|  
|[Constante COOPERATIVE_TIMEOUT_INFINITE](../Topic/COOPERATIVE_TIMEOUT_INFINITE%20Constant.md)|Valor que indica que uma espera nunca deve atingir o tempo limite.|  
|[Constante COOPERATIVE_WAIT_TIMEOUT](../Topic/COOPERATIVE_WAIT_TIMEOUT%20Constant.md)|Valor que indica que uma espera esgotado.|  
|[Constante INHERIT_THREAD_PRIORITY](../Topic/INHERIT_THREAD_PRIORITY%20Constant.md)|Valor especial para a chave de política `ContextPriority` indicando que a prioridade do thread de todos os contextos do agendador deve ser o mesmo que o thread que criou o Agendador.|  
|[Constante LockEventGuid](../Topic/LockEventGuid%20Constant.md)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionados a bloqueios.|  
|[Constante MaxExecutionResources](../Topic/MaxExecutionResources%20Constant.md)|Valor especial para as chaves de política `MinConcurrency` e `MaxConcurrency`. O padrão é o número de threads de hardware no computador na ausência de outras restrições.|  
|[Constante PPLParallelForeachEventGuid](../Topic/PPLParallelForeachEventGuid%20Constant.md)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionados ao uso do `parallel_for_each` função.|  
|[Constante PPLParallelForEventGuid](../Topic/PPLParallelForEventGuid%20Constant.md)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionados ao uso do `parallel_for` função.|  
|[Constante PPLParallelInvokeEventGuid](../Topic/PPLParallelInvokeEventGuid%20Constant.md)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionados ao uso do `parallel_invoke` função.|  
|[Constante ResourceManagerEventGuid](../Topic/ResourceManagerEventGuid%20Constant.md)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionadas ao Gerenciador de recursos.|  
|[Constante ScheduleGroupEventGuid](../Topic/ScheduleGroupEventGuid%20Constant.md)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionados aos grupos de agendas.|  
|[Constante SchedulerEventGuid](../Topic/SchedulerEventGuid%20Constant.md)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionados à atividade do Agendador.|  
|[Constante VirtualProcessorEventGuid](../Topic/VirtualProcessorEventGuid%20Constant.md)|Uma categoria de GUID descrevendo eventos ETW acionado no tempo de execução de simultaneidade que estão diretamente relacionados aos processadores virtuais.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h, concrt.h, concrtrm. h, concurrent_priority_queue.h, concurrent_queue.h, concurrent_unordered_map.h, concurrent_unordered_set.h, concurrent_vector.h, internal_concurrent_hash.h, internal_split_ordered_list.h, ppl.h, pplcancellation_token.h, pplconcrt.h, pplinterface.h, ppltasks.h  
  
## <a name="see-also"></a>Consulte também  
 [Referência](../../../parallel/concrt/reference/reference-concurrency-runtime.md)

