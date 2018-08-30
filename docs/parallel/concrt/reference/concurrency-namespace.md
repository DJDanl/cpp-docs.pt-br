---
title: Namespace de simultaneidade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- Concurrency namespace
ms.assetid: f1d33ca2-679b-4442-b140-22a9d9df61d1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 324acb33998246933b0c426357368247c6689c47
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43211311"
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
|[Concurrency::Extensibility Namespace](https://msdn.microsoft.com/16a86ff2-128e-4edf-89e4-38aac79c81f9)||  
  
### <a name="typedefs"></a>Typedefs  
  
|Nome|Descrição|  
|----------|-----------------|  
|`runtime_object_identity`|Cada instância de mensagem tem uma identidade que o segue conforme ele é clonado e passado entre componentes de mensagens. Isso não pode ser o endereço do objeto de mensagem.|  
|`task_status`|Um tipo que representa o estado terminal de uma tarefa. Os valores válidos são `completed` e `canceled`.|  
|`TaskProc`|Uma abstração elementar para uma tarefa, definida como `void (__cdecl * TaskProc)(void *)`. Um `TaskProc` é chamado para invocar o corpo de uma tarefa.|  
|`TaskProc_t`|Uma abstração elementar para uma tarefa, definida como `void (__cdecl * TaskProc_t)(void *)`. Um `TaskProc` é chamado para invocar o corpo de uma tarefa.|  
  
### <a name="classes"></a>Classes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe affinity_partitioner](affinity-partitioner-class.md)|O `affinity_partitioner` classe é semelhante ao `static_partitioner` classe, mas ele melhora a afinidade de cache, sua opção de mapeamento de subintervalos para threads de trabalho. Ele pode melhorar o desempenho significativamente quando um loop é executado novamente no mesmo conjunto de dados e os dados se encaixa no cache. Observe que o mesmo `affinity_partitioner` objeto deve ser usado com as iterações subsequentes de um loop paralelo que é executado em um conjunto de dados específico, para se beneficiar de localidade dos dados.|  
|[Classe agent](agent-class.md)|Uma classe que se destina a ser usado como uma classe base para todos os agentes independentes. Ele é usado para ocultar o estado de outros agentes e interagir usando a transmissão de mensagens.|  
|[Classe auto_partitioner](auto-partitioner-class.md)|O `auto_partitioner` classe representa o método padrão `parallel_for`, `parallel_for_each` e `parallel_transform` usar para particionar o intervalo que itera em. Esse método de particionamento utiliza uma variam de roubo de balanceamento de carga, bem como por-iterar cancelamento.|  
|[Classe bad_target](bad-target-class.md)|Esta classe descreve uma exceção gerada quando um bloco de mensagens é receber um ponteiro para um destino que é inválido para a operação que está sendo executada.|  
|[Classe call](call-class.md)|Um `call` bloco de mensagem é uma origem de várias, ordenados `target_block` que invoca uma função especificada ao receber uma mensagem.|  
|[Classe cancellation_token](cancellation-token-class.md)|O `cancellation_token` classe representa a capacidade de determinar se alguma operação foi solicitada para cancelar. Um token determinado pode ser associado com um `task_group`, `structured_task_group`, ou `task` para fornecer cancelamento implícito. Ele também pode ser pesquisado para cancelamento ou ter um retorno de chamada registrado para se e quando associado `cancellation_token_source` é cancelada.|  
|[Classe cancellation_token_registration](cancellation-token-registration-class.md)|O `cancellation_token_registration` classe representa uma notificação de retorno de chamada de um `cancellation_token`. Quando o `register` método em um `cancellation_token` é usado para receber notificações de quando o cancelamento ocorre, um `cancellation_token_registration` objeto é retornado como um identificador para o retorno de chamada para que o chamador possa solicitar um retorno de chamada específico não precisa mais ser feitas por meio do uso da `deregister` método.|  
|[Classe cancellation_token_source](cancellation-token-source-class.md)|O `cancellation_token_source` classe representa a capacidade de cancelar qualquer operação anulável.|  
|[Classe choice](choice-class.md)|Um `choice` bloco de mensagens é um bloco de várias fonte, destino único que representa uma interação de fluxo de controle com um conjunto de fontes. O bloco de opção aguardará para qualquer uma das várias fontes para produzir uma mensagem e propagará o índice da origem que gerou a mensagem.|  
|[Classe combinable](combinable-class.md)|O `combinable<T>` objeto destina-se a fornecer cópias de thread privada dos dados, executar cálculos de subpropriedades de local de thread livre de bloqueio durante algoritmos paralelos. No final da operação em paralelo, os cálculos de subpropriedades de thread / privada, em seguida, podem ser mesclados em um resultado final. Essa classe pode ser usado em vez de uma variável compartilhada e pode resultar em uma melhoria de desempenho em caso de outra forma muita contenção naquela variável compartilhada.|  
|[Classe concurrent_priority_queue](concurrent-priority-queue-class.md)|O `concurrent_priority_queue` classe é um contêiner que permite que vários threads simultaneamente os itens de push e pop. Itens são exibidos em ordem de prioridade em que a prioridade é determinada por um funtor fornecido como um argumento de modelo.|  
|[Classe concurrent_queue](concurrent-queue-class.md)|O `concurrent_queue` classe é uma classe de contêiner de sequência que permite que primeiro a entrar, primeiro a sair acesso a seus elementos. Ele permite que um conjunto limitado de operações de prova de simultaneidade, tais como `push` e `try_pop`.|  
|[Classe concurrent_unordered_map](concurrent-unordered-map-class.md)|O `concurrent_unordered_map` classe é um contêiner protegido contra simultaneidade que controla uma sequência de comprimento variado de elementos do tipo `std::pair<const K, _Element_type>`. A sequência é representada de maneira que permite a prova de simultaneidade de acréscimo, acesso de elemento, acesso de iterador e operações de passagem de iterador.|  
|[Classe concurrent_unordered_multimap](concurrent-unordered-multimap-class.md)|O `concurrent_unordered_multimap` classe é um contêiner protegido contra simultaneidade que controla uma sequência de comprimento variado de elementos do tipo `std::pair<const K, _Element_type>`. A sequência é representada de maneira que permite a prova de simultaneidade de acréscimo, acesso de elemento de iterador e operações de passagem de iterador.|  
|[Classe concurrent_unordered_multiset](concurrent-unordered-multiset-class.md)|O `concurrent_unordered_multiset` classe é um contêiner protegido contra simultaneidade que controla uma sequência de comprimento variado de elementos do tipo K. A sequência é representada de maneira que permite a prova de simultaneidade de acréscimo, acesso de elemento de iterador e operações de passagem de iterador.|  
|[Classe concurrent_unordered_set](concurrent-unordered-set-class.md)|O `concurrent_unordered_set` classe é um contêiner protegido contra simultaneidade que controla uma sequência de comprimento variado de elementos do tipo K. A sequência é representada de maneira que permite a prova de simultaneidade de acréscimo, acesso de elemento de iterador e operações de passagem de iterador.|  
|[Classe concurrent_vector](concurrent-vector-class.md)|O `concurrent_vector` classe é uma classe de contêiner de sequência que permite acesso aleatório a qualquer elemento. Ele habilita a prova de simultaneidade de acréscimo, acesso de elemento, acesso de iterador e operações de passagem de iterador.|  
|[Classe de contexto](context-class.md)|Representa uma abstração para um contexto de execução.|  
|[Classe context_self_unblock](context-self-unblock-class.md)|Esta classe descreve uma exceção gerada quando o `Unblock` método de um `Context` objeto é chamado no mesmo contexto. Isso poderia indicar uma tentativa por um determinado contexto para desbloquear em si.|  
|[Classe context_unblock_unbalanced](context-unblock-unbalanced-class.md)|Esta classe descreve uma exceção lançada quando chamadas para o `Block` e `Unblock` métodos de um `Context` objeto não são emparelhados corretamente.|  
|[Classe critical_section](critical-section-class.md)|Um mutex não reentrante que esteja explicitamente ciente do tempo de execução de simultaneidade.|  
|[Classe CurrentScheduler](currentscheduler-class.md)|Representa uma abstração para o Agendador atual associado com o contexto de chamada.|  
|[Classe default_scheduler_exists](default-scheduler-exists-class.md)|Esta classe descreve uma exceção gerada quando o `Scheduler::SetDefaultSchedulerPolicy` método é chamado quando um agendador padrão já existe dentro do processo.|  
|[Classe event](event-class.md)|Um evento de redefinição manual que esteja explicitamente ciente do tempo de execução de simultaneidade.|  
|[Classe improper_lock](improper-lock-class.md)|Esta classe descreve uma exceção gerada quando um bloqueio é adquirido incorretamente.|  
|[Classe improper_scheduler_attach](improper-scheduler-attach-class.md)|Esta classe descreve uma exceção gerada quando o `Attach` método é chamado em um `Scheduler` objeto que já está anexado ao contexto atual.|  
|[Classe improper_scheduler_detach](improper-scheduler-detach-class.md)|Esta classe descreve uma exceção gerada quando o `CurrentScheduler::Detach` método é chamado em um contexto que ainda não foi anexado a qualquer Agendador usando o `Attach` método de um `Scheduler` objeto.|  
|[Classe improper_scheduler_reference](improper-scheduler-reference-class.md)|Esta classe descreve uma exceção gerada quando o `Reference` método é chamado em um `Scheduler` objeto que está sendo desligado, de um contexto que não faz parte do que o Agendador.|  
|[Classe invalid_link_target](invalid-link-target-class.md)|Esta classe descreve uma exceção gerada quando o `link_target` método de um bloco de mensagens é chamado e o bloco de mensagens é não foi possível vincular ao destino. Isso pode ser o resultado de exceder o número de links que o bloco de mensagens é permitido ou tentar vincular a um destino específico duas vezes para a mesma fonte.|  
|[Classe invalid_multiple_scheduling](invalid-multiple-scheduling-class.md)|Esta classe descreve uma exceção gerada quando um `task_handle` objeto é agendada várias vezes usando o `run` método de um `task_group` ou `structured_task_group` objeto sem uma chamada intermediária para o `wait` ou `run_and_wait` métodos.|  
|[Classe invalid_operation](invalid-operation-class.md)|Esta classe descreve uma exceção gerada quando uma operação inválida é executada, o que não é descrita com mais precisão por outro tipo de exceção gerado pelo tempo de execução de simultaneidade.|  
|[Classe invalid_oversubscribe_operation](invalid-oversubscribe-operation-class.md)|Esta classe descreve uma exceção gerada quando o `Context::Oversubscribe` método for chamado com o `_BeginOversubscription` parâmetro definido como `false` sem uma chamada anterior para o `Context::Oversubscribe` método com o `_BeginOversubscription` parâmetro definido como `true`.|  
|[Classe invalid_scheduler_policy_key](invalid-scheduler-policy-key-class.md)|Esta classe descreve uma exceção gerada quando um inválido ou desconhecido de chave é passado para um `SchedulerPolicy` construtor de objeto, ou o `SetPolicyValue` método de um `SchedulerPolicy` objeto é passado a uma chave que deve ser alterada usando outros meios, como o `SetConcurrencyLimits` método.|  
|[Classe invalid_scheduler_policy_thread_specification](invalid-scheduler-policy-thread-specification-class.md)|Esta classe descreve uma exceção gerada quando é feita uma tentativa de definir os limites de simultaneidade de um `SchedulerPolicy` objeto, de modo que o valor da `MinConcurrency` chave é menor que o valor da `MaxConcurrency` chave.|  
|[Classe invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md)|Esta classe descreve uma exceção gerada quando uma chave de política de um `SchedulerPolicy` objeto é definido como um valor inválido para essa chave.|  
|[Classe ISource](isource-class.md)|O `ISource` classe é a interface para todos os blocos de origem. Blocos de origem propagam as mensagens `ITarget` blocos.|  
|[Classe ITarget](itarget-class.md)|O `ITarget` classe é a interface de todos os blocos de destino. Blocos de destino consumam mensagens oferecidas a eles por `ISource` blocos.|  
|[Classe join](join-class.md)|Um `join` bloco de mensagem é um destino de único, várias fontes, ordenada `propagator_block` que combina as mensagens do tipo `T` de cada uma das suas fontes.|  
|[Classe location](location-class.md)|Uma abstração de um local físico em hardware.|  
|[Classe message](message-class.md)|O envelope de mensagem básica que contém o conteúdo dos dados que está sendo transmitido entre blocos de mensagens.|  
|[Classe message_not_found](message-not-found-class.md)|Esta classe descreve uma exceção gerada quando um bloco de mensagens não conseguir encontrar uma mensagem solicitada.|  
|[Classe message_processor](message-processor-class.md)|O `message_processor` classe é a classe base abstrata para o processamento de `message` objetos. Não há nenhuma garantia sobre a ordenação das mensagens.|  
|[Classe missing_wait](missing-wait-class.md)|Esta classe descreve uma exceção gerada quando há tarefas que ainda está agendadas para um `task_group` ou `structured_task_group` do objeto do objeto ao tempo destruidor é executado. Essa exceção nunca será gerada se o destruidor for atingido devido a uma pilha de desenrolamento como resultado de uma exceção.|  
|[Classe multi_link_registry](multi-link-registry-class.md)|O `multi_link_registry` objeto é um `network_link_registry` que gerencia vários blocos de código-fonte ou vários blocos de destino.|  
|[Classe multitype_join](multitype-join-class.md)|Um `multitype_join` bloco de mensagens é um bloco de mensagens várias fonte, destino único que combina mensagens de diferentes tipos de cada uma das suas fontes e oferece uma tupla das mensagens combinadas para seus destinos.|  
|[Classe nested_scheduler_missing_detach](nested-scheduler-missing-detach-class.md)|Esta classe descreve uma exceção gerada quando o tempo de execução de simultaneidade detecta que você não chamou o `CurrentScheduler::Detach` método em um contexto que é anexado a um agendador segundo usando o `Attach` método da `Scheduler` objeto.|  
|[Classe network_link_registry](network-link-registry-class.md)|O `network_link_registry` gerencia a classe base abstrata os links entre os blocos de origem e destino.|  
|[Classe operation_timed_out](operation-timed-out-class.md)|Esta classe descreve uma exceção gerada quando uma operação foi atingido.|  
|[Classe ordered_message_processor](ordered-message-processor-class.md)|Uma `ordered_message_processor` é um `message_processor` que permite que os blocos de mensagem processar mensagens na ordem em que foram recebidas.|  
|[Classe overwrite_buffer](overwrite-buffer-class.md)|Uma `overwrite_buffer` bloco de mensagem é um destino de várias, várias fontes, ordenada `propagator_block` capaz de armazenar uma única mensagem por vez. Novas mensagens substituem aqueles mantidos anteriormente.|  
|[Classe progress_reporter](progress-reporter-class.md)|A classe de relator de andamento permite criar relatórios de notificações de andamento de um tipo específico. Cada objeto progress_reporter está associado a uma determinada ação ou operação assíncrona.|  
|[Classe propagator_block](propagator-block-class.md)|O `propagator_block` classe é uma classe base abstrata para blocos de mensagens que são uma origem e destino. Ele combina a funcionalidade de ambos os `source_block` e `target_block` classes.|  
|[Classe reader_writer_lock](reader-writer-lock-class.md)|Um bloqueio de leitor-gravador baseado em fila do gravador preferência com local apenas em rotação. O bloqueio concede a primeiro – primeiro acesso (FIFO) para gravadores e consome os leitores sob uma carga contínua de gravadores.|  
|[Classe ScheduleGroup](schedulegroup-class.md)|Representa uma abstração para um grupo de agendas. Grupos de agendas organizam um conjunto de trabalho relacionados que se beneficiam de ser agendados em datas próximas temporariamente, por executando outra tarefa no mesmo grupo antes de passar para outro grupo ou espaçadamente, executando vários itens dentro do mesmo grupo no mesmo Nó NUMA ou soquete físico.|  
|[Classe Scheduler](scheduler-class.md)|Representa uma abstração para um agendador de tempo de execução de simultaneidade.|  
|[Classe scheduler_not_attached](scheduler-not-attached-class.md)|Esta classe descreve uma exceção gerada quando é executada uma operação que exige um agendador a ser anexado ao contexto atual e um não é.|  
|[Classe scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md)|Esta classe descreve uma exceção gerada devido a uma falha ao adquirir um recurso crítico no tempo de execução de simultaneidade.|  
|[Classe scheduler_worker_creation_error](scheduler-worker-creation-error-class.md)|Esta classe descreve uma exceção gerada devido a uma falha ao criar um contexto de execução do trabalho no tempo de execução de simultaneidade.|  
|[Classe SchedulerPolicy](schedulerpolicy-class.md)|O `SchedulerPolicy` classe contém um conjunto de pares chave/valor, uma para cada elemento de diretiva que controlam o comportamento de uma instância do Agendador.|  
|[Classe simple_partitioner](simple-partitioner-class.md)|O `simple_partitioner` classe representa um particionamento estático do intervalo iterado pelo `parallel_for`. O particionador divide o intervalo em partes, de modo que cada parte tem pelo menos o número de iterações especificado pelo tamanho do bloco.|  
|[Classe single_assignment](single-assignment-class.md)|Um `single_assignment` bloco de mensagem é um destino de vários várias fontes, ordenada `propagator_block` capaz de armazenar uma única gravação-depois que `message`.|  
|[Classe single_link_registry](single-link-registry-class.md)|O `single_link_registry` objeto é um `network_link_registry` que gerencia apenas um único bloco de origem ou destino.|  
|[Classe source_block](source-block-class.md)|O `source_block` classe é uma classe base abstrata para blocos de código-fonte. A classe fornece funcionalidade de gerenciamento de link básico como verificações de erro bem tão comuns.|  
|[Classe source_link_manager](source-link-manager-class.md)|O `source_link_manager` objeto gerencia mensagens links de rede de bloco para `ISource` blocos.|  
|[Classe static_partitioner](static-partitioner-class.md)|O `static_partitioner` classe representa um particionamento estático do intervalo iterado pelo `parallel_for`. O particionador divide o intervalo em quantos blocos há trabalhadores disponíveis para o Agendador underyling.|  
|[Classe structured_task_group](structured-task-group-class.md)|O `structured_task_group` classe representa uma coleção altamente estruturada de trabalho em paralelo. Você pode colocar na fila de tarefas individuais em paralelo para uma `structured_task_group` usando `task_handle` objetos e aguarde até que elas sejam concluídas ou cancele o grupo de tarefas antes que eles concluírem a execução, qual anulará todas as tarefas que não começaram a execução.|  
|[Classe target_block](target-block-class.md)|O `target_block` classe é uma classe base abstrata que fornece funcionalidade de gerenciamento básico de link e verificação de erros de destino bloqueia somente.|  
|[Classe task (Tempo de Execução de Simultaneidade)](task-class.md)|A classe `task` da Biblioteca de Padrões Paralelos (PPL). O objeto `task` representa o trabalho que pode ser executado de forma assíncrona e simultaneamente com outras tarefas e o trabalho paralelo produzido por algoritmos paralelos no Tempo de execução de simultaneidade. Produz um resultado de tipo `_ResultType` após uma conclusão bem-sucedida. Tarefas do tipo `task<void>` não produzem resultados. Uma tarefa pode ser aguardada e cancelada independentemente de outras tarefas. Ela também pode ser composta por outras tarefas usando continuations(`then`) e os padrões join(`when_all`) e choice(`when_any`).|  
|[Classe task_canceled](task-canceled-class.md)|Esta classe descreve uma exceção acionada pela camada de tarefas de PPL para forçar a cancelamento da tarefa atual. Ele também é gerado pela `get()` método no [tarefa](https://msdn.microsoft.com/5389e8a5-5038-40b6-844a-55e9b58ad35f), para uma tarefa cancelada.|  
|[Classe task_completion_event](task-completion-event-class.md)|A classe `task_completion_event` permite atrasar a execução de uma tarefa até que uma condição seja atendida, ou iniciar uma tarefa em resposta a um evento externo.|  
|[Classe task_continuation_context](task-continuation-context-class.md)|A classe `task_continuation_context` permite que você especifique onde gostaria que uma continuação fosse executada. Ele só é útil usar essa classe de um aplicativo UWP. Para aplicativos não - Windows Runtime, o contexto de execução da continuação da tarefa é determinado pelo tempo de execução e não é configurável.|  
|[Classe task_group](task-group-class.md)|O `task_group` classe representa uma coleção de trabalho paralelo que pode ser cancelada ou aguardada.|  
|[Classe task_handle](task-handle-class.md)|O `task_handle` classe representa um item de trabalho paralelas individuais. Ele encapsula as instruções e os dados necessários para executar um trabalho.|  
|[Classe task_options (Tempo de Execução de Simultaneidade)](task-options-class-concurrency-runtime.md)|Representa as opções permitidas para criar uma tarefa|  
|[Classe timer](timer-class.md)|Um `timer` bloco de mensagens é um destino de único `source_block` capaz de enviar uma mensagem para o destino depois de determinado período de tempo decorrido ou em intervalos específicos.|  
|[Classe transformer](transformer-class.md)|Um `transformer` bloco de mensagem é um destino de único, várias fontes, ordenada `propagator_block` que pode aceitar mensagens de um tipo e é capaz de armazenar um número ilimitado de mensagens de um tipo diferente.|  
|[Classe unbounded_buffer](unbounded-buffer-class.md)|Uma `unbounded_buffer` bloco de mensagem é um destino de várias, várias fontes, ordenada `propagator_block` capaz de armazenar um número ilimitado de mensagens.|  
|[Classe unsupported_os](unsupported-os-class.md)|Esta classe descreve uma exceção lançada quando um sistema operacional sem suporte é usado.|  
  
### <a name="structures"></a>Estruturas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Estrutura DispatchState](dispatchstate-structure.md)|O `DispatchState` estrutura é usada para transferir o estado para o `IExecutionContext::Dispatch` método. Ele descreve as circunstâncias em que o `Dispatch` método é invocado em um `IExecutionContext` interface.|  
|[Estrutura IExecutionContext](iexecutioncontext-structure.md)|Uma interface para um contexto de execução que pode ser executado em um determinado processador virtual e ser cooperativamente contexto alternado.|  
|[Estrutura IExecutionResource](iexecutionresource-structure.md)|Uma abstração para um thread de hardware.|  
|[Estrutura IResourceManager](iresourcemanager-structure.md)|Uma interface para o Gerenciador de recursos do tempo de execução de simultaneidade. Essa é a interface pela qual agendadores de se comunicar com o Gerenciador de recursos.|  
|[Estrutura IScheduler](ischeduler-structure.md)|Uma interface para uma abstração de um agendador de trabalho. Gerenciador de recursos do tempo de execução de simultaneidade usa essa interface para se comunicar com os agendadores de trabalho.|  
|[Estrutura ISchedulerProxy](ischedulerproxy-structure.md)|A interface pela qual agendadores de se comunicar com o Gerenciador de recursos do tempo de execução de simultaneidade para negociar a alocação de recursos.|  
|[Estrutura IThreadProxy](ithreadproxy-structure.md)|Uma abstração para um thread de execução. Dependendo do `SchedulerType` chave de política do Agendador, você cria, o Gerenciador de recursos concederá a você um proxy de thread que é apoiado por um thread do Win32 regular ou em um thread (UMS) agendáveis do modo de usuário. Threads UMS são com suporte em sistemas operacionais de 64 bits com a versão do Windows 7 e superior.|  
|[Estrutura ITopologyExecutionResource](itopologyexecutionresource-structure.md)|Uma interface para um recurso de execução, conforme definido pelo Gerenciador de recursos.|  
|[Estrutura ITopologyNode](itopologynode-structure.md)|Uma interface para um nó da topologia conforme definido pelo Gerenciador de recursos. Um nó contém um ou mais recursos de execução.|  
|[Estrutura IUMSCompletionList](iumscompletionlist-structure.md)|Representa uma lista de conclusão UMS. Quando um thread seja bloqueado UMS, o Agendador designado de agendamento de contexto é enviado para tomar uma decisão do que agendar na raiz do processador virtual subjacente enquanto o thread original será bloqueado. Quando o thread original será desbloqueado, o sistema operacional coloca em fila-lo à lista de preenchimento que é acessível por meio dessa interface. O Agendador pode consultar a lista de conclusão no contexto de programação designado ou qualquer outro lugar, que ele procura por trabalho.|  
|[Estrutura IUMSScheduler](iumsscheduler-structure.md)|Uma interface para uma abstração de um agendador de trabalho que deseja o Gerenciador de recursos do tempo de execução de simultaneidade entregá-lo a threads agendáveis no modo de usuário (UMS). O Gerenciador de recursos usa essa interface para se comunicar com os agendadores de thread UMS. A interface `IUMSScheduler` herda da interface `IScheduler`.|  
|[Estrutura IUMSThreadProxy](iumsthreadproxy-structure.md)|Uma abstração para um thread de execução. Se você quiser que seu Agendador para ser concedida a threads agendáveis no modo de usuário (UMS), defina o valor para o elemento de política de Agendador `SchedulerKind` à `UmsThreadDefault`e implementar o `IUMSScheduler` interface. Threads UMS são apenas com suporte em sistemas operacionais de 64 bits com a versão do Windows 7 e superior.|  
|[Estrutura IUMSUnblockNotification](iumsunblocknotification-structure.md)|Representa uma notificação do Gerenciador de recursos que um proxy de thread que bloqueado e disparou um retorno para o Agendador designado o contexto de programação tem desbloqueado e está pronto para ser agendada. Essa interface é inválida quando o contexto de execução associadas do proxy de thread, retornado do `GetContext` método, será reagendada.|  
|[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)|Uma abstração para um thread de hardware no qual um proxy de thread pode executar.|  
|[Estrutura scheduler_interface](scheduler-interface-structure.md)|Interface de Agendador|  
|[Estrutura scheduler_ptr (Tempo de Execução de Simultaneidade)](scheduler-ptr-structure-concurrency-runtime.md)|Representa um ponteiro para um agendador. Esta classe existe para permitir a especificação de um tempo de vida compartilhado usando o shared_ptr ou apenas uma referência simples usando o ponteiro bruto.|  
  
### <a name="enumerations"></a>Enumerações  
  
|Nome|Descrição|  
|----------|-----------------|  
|[agent_status](concurrency-namespace-enums.md#agent_status)|Os estados válidos para um `agent`.|  
|[Agents_EventType](concurrency-namespace-enums.md#agents_eventtype)|Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pela biblioteca de agentes|  
|[ConcRT_EventType](concurrency-namespace-enums.md#concrt_eventtype)|Os tipos de eventos que podem ser rastreados usando a funcionalidade de rastreamento oferecida pelo tempo de execução de simultaneidade.|  
|[Concrt_TraceFlags](concurrency-namespace-enums.md#concrt_traceflags)|Sinalizadores de rastreamento para os tipos de evento|  
|[CriticalRegionType](concurrency-namespace-enums.md#criticalregiontype)|O tipo de um contexto está dentro de região crítica.|  
|[DynamicProgressFeedbackType](concurrency-namespace-enums.md#dynamicprogressfeedbacktype)|Usado pelo `DynamicProgressFeedback` com base em políticas para descrever se recursos para o Agendador serão redistribuídos de acordo com as informações estatísticas coletadas do Agendador ou apenas em processadores virtuais entrando e saindo do estado ocioso por meio de chamadas para o `Activate` e `Deactivate` métodos no `IVirtualProcessorRoot` interface. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md#policyelementkey).|  
|[join_type](concurrency-namespace-enums.md#join_type)|O tipo de um `join` bloco de mensagem.|  
|[message_status](concurrency-namespace-enums.md#message_status)|As respostas válidas para uma oferta de uma `message` objeto para um bloco.|  
|[PolicyElementKey](concurrency-namespace-enums.md#policyelementkey)|Chaves de política que descrevem aspectos do comportamento do Agendador. Cada elemento de política é descrito por um par chave-valor. Para obter mais informações sobre políticas de agendador e seu impacto em agendadores, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).|  
|[SchedulerType](concurrency-namespace-enums.md#schedulertype)|Usado pelo `SchedulerKind` política para descrever o tipo de threads que o Agendador deve utilizar para contextos de execução subjacente. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md#policyelementkey).|  
|[SchedulingProtocolType](concurrency-namespace-enums.md#schedulingprotocoltype)|Usado pelo `SchedulingProtocol` diretiva descrever qual algoritmo de agendamento será utilizado para o Agendador. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md#policyelementkey).|  
|[SwitchingProxyState](concurrency-namespace-enums.md#switchingproxystate)|Usado para indicar o estado de em que um proxy de thread está, quando ele está executando uma alternância de contexto cooperativo para um proxy de thread diferente.|  
|[task_group_status](concurrency-namespace-enums.md#task_group_status)|Descreve o status de execução de um `task_group` ou `structured_task_group` objeto. Um valor desse tipo é retornado por vários métodos que esperam que tarefas agendadas para um grupo de tarefas para concluir.|  
|[WinRTInitializationType](concurrency-namespace-enums.md#winrtinitializationtype)|Usado pelo `WinRTInitialization` política para descrever se e como o tempo de execução do Windows será inicializado em segmentos de Agendador para um aplicativo que é executado em sistemas operacionais com a versão Windows 8 ou superior. Para obter mais informações sobre políticas de Agendador disponíveis, consulte [PolicyElementKey](concurrency-namespace-enums.md#policyelementkey).|  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Função ALLOC](concurrency-namespace-functions.md#alloc)|Aloca um bloco de memória do tamanho especificado a partir do Concurrency Runtime Caching Suballocator.|  
|[Função asend](concurrency-namespace-functions.md#asend)|Sobrecarregado. Uma operação de envio assíncrono que agenda uma tarefa para propagar os dados para o bloco de destino.|  
|[Função cancel_current_task](concurrency-namespace-functions.md#cancel_current_task)|Cancela a tarefa atualmente em execução. Essa função pode ser chamada de dentro do corpo de uma tarefa para interromper a execução da tarefa e fazer com que ela entre no estado `canceled`.<br /><br /> Não é um cenário com suporte para chamar essa função se você não estiver dentro do corpo de uma `task`. Isso resultará em um comportamento indefinido, tal como um travamento ou um desligamento em seu aplicativo.|  
|[Função create_async](concurrency-namespace-functions.md#create_async)|Cria uma construção assíncrona de Tempo de execução do Windows com base em um objeto de função ou lambda fornecido pelo usuário. O tipo de retorno de `create_async` é `IAsyncAction^`, `IAsyncActionWithProgress<TProgress>^`, `IAsyncOperation<TResult>^` ou `IAsyncOperationWithProgress<TResult, TProgress>^` com base na assinatura do lambda passada para o método.|  
|[Função create_task](concurrency-namespace-functions.md#create_task)|Sobrecarregado. Cria um PPL [tarefa](https://msdn.microsoft.com/5389e8a5-5038-40b6-844a-55e9b58ad35f) objeto. `create_task` pode ser usado em qualquer lugar que você usaria um construtor de tarefa. Ele é fornecido principalmente para conveniência, pois ele permite o uso do `auto` palavra-chave durante a criação de tarefas.|  
|[Função CreateResourceManager](concurrency-namespace-functions.md#createresourcemanager)|Retorna uma interface que representa a instância singleton do Gerenciador de recursos do tempo de execução de simultaneidade. O Gerenciador de recursos é responsável por atribuir recursos a agendadores que desejam cooperar entre si.|  
|[Função DisableTracing](concurrency-namespace-functions.md#disabletracing)|Desabilita o rastreamento em tempo de execução de simultaneidade. Essa função é preterida porque o rastreamento ETW é cancelado por padrão.|  
|[Função EnableTracing](concurrency-namespace-functions.md#enabletracing)|Habilita o rastreamento em tempo de execução de simultaneidade. Essa função é preterida porque o rastreamento ETW agora é ativado por padrão.|  
|[Função Free](concurrency-namespace-functions.md#free)|Libera um bloco de memória alocado anteriormente pelo `Alloc` método para o Concurrency Runtime Caching Suballocator.|  
|[Função (tempo de execução de simultaneidade) get_ambient_scheduler](concurrency-namespace-functions.md#get_ambient_scheduler)||  
|[Função GetExecutionContextId](concurrency-namespace-functions.md#getexecutioncontextid)|Retorna um identificador exclusivo que pode ser atribuído a um contexto de execução que implementa o `IExecutionContext` interface.|  
|[Função GetOSVersion](concurrency-namespace-functions.md#getosversion)|Retorna a versão do sistema operacional.|  
|[Função GetProcessorCount](concurrency-namespace-functions.md#getprocessorcount)|Retorna o número de threads de hardware no sistema subjacente.|  
|[Função GetProcessorNodeCount](concurrency-namespace-functions.md#getprocessornodecount)|Retorna o número de nós NUMA ou pacotes de processadores no sistema subjacente.|  
|[Função GetSchedulerId](concurrency-namespace-functions.md#getschedulerid)|Retorna um identificador exclusivo que pode ser atribuído a um agendador que implementa o `IScheduler` interface.|  
|[Função interruption_point](concurrency-namespace-functions.md#interruption_point)|Cria um ponto de interrupção para o cancelamento. Se um cancelamento está em andamento no contexto em que essa função é chamada, isso gerará uma exceção interna que anula a execução do trabalho paralelo em execução no momento. Se o cancelamento não está em andamento, a função não faz nada.|  
|[Função is_current_task_group_canceling](concurrency-namespace-functions.md#is_current_task_group_canceling)|Retorna uma indicação de se a tarefa de grupo que está em execução inline no contexto atual está no meio de um cancelamento ativo (ou estarão em breve). Observe que, se não houver nenhum grupo de tarefas atualmente em execução inline no contexto atual, `false` será retornado.|  
|[Função make_choice](concurrency-namespace-functions.md#make_choice)|Sobrecarregado. Constrói uma `choice` bloco de mensagens de um recurso opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.|  
|[Função make_greedy_join](concurrency-namespace-functions.md#make_greedy_join)|Sobrecarregado. Constrói uma `greedy multitype_join` bloco de mensagens de um recurso opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.|  
|[Função make_join](concurrency-namespace-functions.md#make_join)|Sobrecarregado. Constrói uma `non_greedy multitype_join` bloco de mensagens de um recurso opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.|  
|[Função make_task](concurrency-namespace-functions.md#make_task)|Um método de fábrica para criar um `task_handle` objeto.|  
|[Função parallel_buffered_sort](concurrency-namespace-functions.md#parallel_buffered_sort)|Sobrecarregado. Organiza os elementos em um intervalo especificado em uma ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Essa função é semanticamente similar a `std::sort` é de uma classificação de comparação instável, baseada no local, exceto que ele precisa `O(n)` espaço adicional e requer a inicialização padrão para os elementos que estão sendo classificados.|  
|[Função parallel_for](concurrency-namespace-functions.md#parallel_for)|Sobrecarregado. `parallel_for` itera em um intervalo de índices e executa uma função fornecida pelo usuário em cada iteração, em paralelo.|  
|[Função parallel_for_each](concurrency-namespace-functions.md#parallel_for_each)|Sobrecarregado. `parallel_for_each` aplica uma função especificada para cada elemento dentro de um intervalo, em paralelo. Ele é semanticamente equivalente à `for_each` funcionar no `std` namespace, exceto aquela iteração sobre elementos é executada em paralelo, e a ordem de iteração é especificada. O argumento `_Func` deve oferecer suporte a um operador de chamada de função do formulário `operator()(T)` em que o parâmetro `T` é o tipo de item do contêiner que está sendo iterado.|  
|[Função parallel_invoke](concurrency-namespace-functions.md#parallel_invoke)|Sobrecarregado. Executa os objetos de função fornecidos como parâmetros em paralelo e blocos até que eles concluírem a execução. Cada objeto de função pode ser uma expressão lambda, um ponteiro para função, ou qualquer objeto que suporta o operador de chamada de função com a assinatura `void operator()()`.|  
|[Função parallel_radixsort](concurrency-namespace-functions.md#parallel_radixsort)|Sobrecarregado. Organiza elementos em um intervalo especificado em uma ordem não decrescente usando um algoritmo de classificação de base. Essa é uma função de classificação estável que exige uma função de projeção que pode projetar os elementos a serem classificados nas chaves de tipo inteiro sem sinal. Inicialização padrão é necessária para os elementos que estão sendo classificados.|  
|[Função parallel_reduce](concurrency-namespace-functions.md#parallel_reduce)|Sobrecarregado. Calcula a soma de todos os elementos em um intervalo especificado Calculando somas parciais sucessivas ou calcula o resultado de resultados parciais sucessivos obtidos usando uma operação binária especificada diferente da soma, em paralelo. `parallel_reduce` é semanticamente similar a `std::accumulate`, exceto que ele requer que a operação binária ser associativa e requer um valor de identidade em vez de um valor inicial.|  
|[Função parallel_sort](concurrency-namespace-functions.md#parallel_sort)|Sobrecarregado. Organiza os elementos em um intervalo especificado em uma ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Essa função é semanticamente similar a `std::sort` é de uma classificação de comparação instável, baseada no local.|  
|[Função parallel_transform](concurrency-namespace-functions.md#parallel_transform)|Sobrecarregado. Aplica-se um objeto de função especificado a cada elemento em um intervalo de origem, um par de elementos de dois intervalos de origem e copia os valores de retorno do objeto de função em um intervalo de destino, em paralelo. Nesse funcional é semanticamente equivalente a `std::transform`.|  
|[Função Receive](concurrency-namespace-functions.md#receive)|Sobrecarregado. Geral receber implementação, permitindo que um contexto de espera para dados de origem exatamente um e filtrar os valores que são aceitos.|  
|[Função run_with_cancellation_token](concurrency-namespace-functions.md#run_with_cancellation_token)|Executa um objeto de função imediatamente e de forma síncrona no contexto de um token de cancelamento fornecido.|  
|[Função Send](concurrency-namespace-functions.md#send)|Sobrecarregado. Uma operação de envio síncronos, que aguarda até que o destino aceita ou rejeita a mensagem.|  
|[Função (tempo de execução de simultaneidade) set_ambient_scheduler](concurrency-namespace-functions.md#set_ambient_scheduler)||  
|[Função set_task_execution_resources](concurrency-namespace-functions.md#set_task_execution_resources)|Sobrecarregado. Restringe os recursos de execução usados pelos threads de trabalho interno de tempo de execução de simultaneidade para o conjunto especificado de afinidade.<br /><br /> Ele é válido chamar esse método antes do Gerenciador de recursos foi criado, ou entre dois tempos de vida do Gerenciador de recursos. Ele pode ser chamado várias vezes desde que o Gerenciador de recursos não existe no momento da invocação. Depois que um limite de afinidade tiver sido definido, ele permanecerá em vigor até a próxima chamada válida para o `set_task_execution_resources` método.<br /><br /> A máscara de afinidade fornecida não precisa ser um subconjunto da máscara de afinidade de processo. A afinidade do processo será atualizada se necessário.|  
|[Função swap](concurrency-namespace-functions.md#swap)|Troca os elementos de dois objetos `concurrent_vector`.|  
|[Função (tempo de execução de simultaneidade) task_from_exception](concurrency-namespace-functions.md#task_from_exception)||  
|[Função (tempo de execução de simultaneidade) task_from_result](concurrency-namespace-functions.md#task_from_result)||  
|[Função Trace_agents_register_name](concurrency-namespace-functions.md#trace_agents_register_name)|Associa o nome fornecido para o bloco de mensagem ou o agente no rastreamento de ETW.|  
|[Função try_receive](concurrency-namespace-functions.md#try_receive)|Sobrecarregado. Geral try-receive implementação, permitindo que um contexto procurar dados de origem exatamente um e filtrar os valores que são aceitos. Se os dados não estiverem prontos, o método retornará false.|  
|[Função Wait](concurrency-namespace-functions.md#wait)|Pausa o contexto atual por um período de tempo especificado.|  
|[Função when_all](concurrency-namespace-functions.md#when_all)|Cria uma tarefa que será concluída com êxito quando todas as tarefas fornecidas como argumentos forem concluídas com êxito.|  
|[Função when_any](concurrency-namespace-functions.md#when_any)|Sobrecarregado. Cria uma tarefa que será concluída com êxito quando todas as tarefas fornecidas como argumentos forem concluídas com êxito.|  
  
### <a name="operators"></a>Operadores  
  
|Nome|Descrição|  
|----------|-----------------| 
|[operator!=](concurrency-namespace-operators.md#operator_neq)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador não é igual ao `concurrent_vector` objeto no lado direito.|  
|[operator&&](concurrency-namespace-operators.md#operator_amp_amp)|Sobrecarregado. Cria uma tarefa que será concluída com êxito quando ambas as tarefas fornecidas como argumentos forem concluídas com êxito.|  
|[operator&#124;&#124;](concurrency-namespace-operators.md#operator_lor)|Sobrecarregado. Cria uma tarefa que será concluída com êxito quando qualquer uma das tarefas fornecidas como argumentos forem concluídas com êxito.|  
|[operator<](concurrency-namespace-operators.md#operator_lt)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é menor do que o `concurrent_vector` objeto no lado direito.|  
|[operator<=](concurrency-namespace-operators.md#operator_lt_eq)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é menor ou igual ao `concurrent_vector` objeto no lado direito.|  
|[operator==](concurrency-namespace-operators.md#operator_eq_eq)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é igual ao `concurrent_vector` objeto no lado direito.|  
|[operator>](concurrency-namespace-operators.md#operator_gt)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é maior que o `concurrent_vector` objeto no lado direito.|  
|[operator>=](concurrency-namespace-operators.md#operator_lt_eq)|Testa se o `concurrent_vector` objeto no lado esquerdo do operador é maior que ou igual ao `concurrent_vector` objeto no lado direito.|  
  
### <a name="constants"></a>Constantes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[AgentEventGuid](concurrency-namespace-constants1.md#agenteventguid)|Uma categoria de GUID ({B9B5B78C-0713-4898-A21A-C67949DCED07}) que descreve eventos ETW são acionados pela biblioteca de agentes no tempo de execução de simultaneidade.|  
|[ChoreEventGuid](concurrency-namespace-constants1.md#choreeventguid)|Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionados a tarefas ou tarefas.|  
|[ConcRT_ProviderGuid](concurrency-namespace-constants1.md#concrt_providerguid)|O GUID para o tempo de execução de simultaneidade do provedor ETW.|  
|[CONCRT_RM_VERSION_1](concurrency-namespace-constants1.md#concrt_rm_version_1)|Indica que há suporte da interface do Gerenciador de recursos definido no Visual Studio 2010.|  
|[ConcRTEventGuid](concurrency-namespace-constants1.md#concrteventguid)|Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que não são descritas mais especificamente por outra categoria.|  
|[ContextEventGuid](concurrency-namespace-constants1.md#contexteventguid)|Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionadas aos contextos.|  
|[COOPERATIVE_TIMEOUT_INFINITE](concurrency-namespace-constants1.md#cooperative_timeout_infinite)|Valor que indica que uma espera nunca deve atingir o tempo limite.|  
|[COOPERATIVE_WAIT_TIMEOUT](concurrency-namespace-constants1.md#cooperative_wait_timeout)|Valor que indica que uma espera atingiu o tempo limite.|  
|[INHERIT_THREAD_PRIORITY](concurrency-namespace-constants1.md#inherit_thread_priority)|Valor especial para a chave de política `ContextPriority` indicando que a prioridade do thread de todos os contextos em que o Agendador deve ser o mesmo que um thread que criou o Agendador.|  
|[LockEventGuid](concurrency-namespace-constants1.md#lockeventguid)|Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionados a bloqueios.|  
|[MaxExecutionResources](concurrency-namespace-constants1.md#maxexecutionresources)|Valor especial para as chaves de política `MinConcurrency` e `MaxConcurrency`. O padrão é o número de threads de hardware na máquina na ausência de outras restrições.|  
|[PPLParallelForeachEventGuid](concurrency-namespace-constants1.md#pplparallelforeacheventguid)|Uma categoria que descreve os eventos ETW de GUID acionado pelo tempo de execução de simultaneidade que estão diretamente relacionadas ao uso do `parallel_for_each` função.|  
|[PPLParallelForEventGuid](concurrency-namespace-constants1.md#pplparallelforeventguid)|Uma categoria que descreve os eventos ETW de GUID acionado pelo tempo de execução de simultaneidade que estão diretamente relacionadas ao uso do `parallel_for` função.|  
|[PPLParallelInvokeEventGuid](concurrency-namespace-constants1.md#pplparallelinvokeeventguid)|Uma categoria que descreve os eventos ETW de GUID acionado pelo tempo de execução de simultaneidade que estão diretamente relacionadas ao uso do `parallel_invoke` função.|  
|[ResourceManagerEventGuid](concurrency-namespace-constants1.md#resourcemanagereventguid)|Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionadas ao Gerenciador de recursos.|  
|[ScheduleGroupEventGuid](concurrency-namespace-constants1.md#schedulegroupeventguid)|Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionados a grupos de agendas.|  
|[SchedulerEventGuid](concurrency-namespace-constants1.md#schedulereventguid)|Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionadas à atividade do Agendador.|  
|[VirtualProcessorEventGuid](concurrency-namespace-constants1.md#virtualprocessoreventguid)|Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionados a processadores virtuais.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Agents. h, concrt. h, concrtrm. h, concurrent_priority_queue.h, concurrent_queue.h, concurrent_unordered_map. h, concurrent_unordered_set. h, concurrent_vector. h, internal_concurrent_hash.h, internal_split_ordered_ List.h, ppl.h, pplcancellation_token. h, pplconcrt. h, pplinterface. h, ppltasks. h  
  
## <a name="see-also"></a>Consulte também  
 [Referência](reference-concurrency-runtime.md)

