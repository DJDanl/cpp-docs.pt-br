---
title: "funções de namespace de simultaneidade | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- concrt/concurrency::Alloc
- concrt/concurrency::DisableTracing
- concrt/concurrency::EnableTracing
- concrtrm/concurrency::GetExecutionContextId
- concrtrm/concurrency::GetOSVersion
- concrtrm/concurrency::GetProcessorNodeCount
- concrtrm/concurrency::GetSchedulerId
- agents/concurrency::asend
- ppltasks/concurrency::cancel_current_task
- ppltasks/concurrency::create_async
- ppltasks/concurrency::create_task
- concurrent_vector/concurrency::internal_assign_iterators
- ppl/concurrency::interruption_point
- agents/concurrency::make_choice
- agents/concurrency::make_greedy_join
- ppl/concurrency::make_task
- ppl/concurrency::parallel_buffered_sort
- ppl/concurrency::parallel_for_each
- ppl/concurrency::parallel_invoke
- ppl/concurrency::parallel_reduce
- ppl/concurrency::parallel_sort
- agents/concurrency::receive
- ppl/concurrency::run_with_cancellation_token
- pplconcrt/concurrency::set_ambient_scheduler
- concrt/concurrency::set_task_execution_resources
- ppltasks/concurrency::task_from_exception
- ppltasks/concurrency::task_from_result
- concrt/concurrency::wait
- ppltasks/concurrency::when_all
- ppltasks/concurrency::when_any
dev_langs:
- C++
ms.assetid: 520a6dff-9324-4df2-990d-302e3050af6a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 66cf776e02d286b04c4fe9338d74d6a9db196a68
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="concurrency-namespace-functions"></a>funções de namespace de simultaneidade
||||  
|-|-|-|  
|[Alloc](#alloc)|[CreateResourceManager](#createresourcemanager)|[DisableTracing](#disabletracing)|  
|[EnableTracing](#enabletracing)|[Livre](#free)|[GetExecutionContextId](#getexecutioncontextid)|  
|[GetOSVersion](#getosversion)|[GetProcessorCount](#getprocessorcount)|[GetProcessorNodeCount](#getprocessornodecount)|  
|[GetSchedulerId](#getschedulerid)|[Trace_agents_register_name](#trace_agents_register_name)|[asend](#asend)|  
|[cancel_current_task](#cancel_current_task)|[clear](#clear)|[create_async](#create_async)|  
|[create_task](#create_task)|[get_ambient_scheduler](#get_ambient_scheduler)|[internal_assign_iterators](#internal_assign_iterators)|  
|[interruption_point](#interruption_point)|[is_current_task_group_canceling](#is_current_task_group_canceling)|[make_choice](#make_choice)|  
|[make_greedy_join](#make_greedy_join)|[make_join](#make_join)|[make_task](#make_task)|  
|[parallel_buffered_sort](#parallel_buffered_sort)|[parallel_for](#parallel_for)|[parallel_for_each](#parallel_for_each)|  
|[parallel_invoke](#parallel_invoke)|[parallel_radixsort](#parallel_radixsort)|[parallel_reduce](#parallel_reduce)|  
|[parallel_sort](#parallel_sort)|[parallel_transform](#parallel_transform)|[receive](#receive)|  
|[run_with_cancellation_token](#run_with_cancellation_token)|[send](#send)|[set_ambient_scheduler](#set_ambient_scheduler)|  
|[set_task_execution_resources](#set_task_execution_resources)|[swap](#swap)|[task_from_exception](#task_from_exception)|  
|[task_from_result](#task_from_result)|[try_receive](#try_receive)|[wait](#wait)|  
|[when_all](#when_all)|[when_any](#when_any)|  
  
##  <a name="alloc"></a>  Alloc  
 Aloca um bloco de memória do tamanho especificado de Suballocator de cache de tempo de execução a simultaneidade.  
  
```
void* __cdecl Alloc(size_t _NumBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_NumBytes`  
 O número de bytes de memória a ser alocada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro de memória alocada recentemente.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre quais cenários em seu aplicativo podem se beneficiar do usando o Suballocator de cache, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
##  <a name="asend"></a>  asend  
 Uma operação de envio assíncrono que agenda uma tarefa para propagar os dados para o bloco de destino.  
  
```
template <class T>
bool asend(
    _Inout_ ITarget<T>* _Trg,
    const T& _Data);

template <class T>
bool asend(
    ITarget<T>& _Trg,
    const T& _Data);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados a serem enviados.  
  
 `_Trg`  
 Um ponteiro ou uma referência para o destino ao qual os dados são enviados.  
  
 `_Data`  
 Uma referência para os dados a serem enviados.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se a mensagem foi aceito antes que o método é retornado, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [funções de transmissão de mensagens](../../../parallel/concrt/message-passing-functions.md).  
  
##  <a name="cancel_current_task"></a>  cancel_current_task  
 Cancela a tarefa atualmente em execução. Essa função pode ser chamada de dentro do corpo de uma tarefa para interromper a execução da tarefa e fazer com que ela entre no estado `canceled`.  
  
 Não é um cenário com suporte para chamar essa função se você não estiver dentro do corpo de uma `task`. Isso resultará em um comportamento indefinido, tal como um travamento ou um desligamento em seu aplicativo.  
  
```
inline __declspec(noreturn) void __cdecl cancel_current_task();
```  
  
##  <a name="clear"></a>  clear  
 Limpa a fila simultânea, destruição de qualquer elementos de fila no momento. Este método não é seguro de simultaneidade.  
  
```
template<typename T, class _Ax>
void concurrent_queue<T, _Ax>::clear();
```   
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 `_Ax`  
  
##  <a name="create_async"></a>  create_async  
 Cria uma construção assíncrona de Tempo de execução do Windows com base em um objeto de função ou lambda fornecido pelo usuário. O tipo de retorno de `create_async` é `IAsyncAction^`, `IAsyncActionWithProgress<TProgress>^`, `IAsyncOperation<TResult>^` ou `IAsyncOperationWithProgress<TResult, TProgress>^` com base na assinatura do lambda passada para o método.  
  
```
template<typename _Function>
__declspec(noinline) auto create_async(const _Function& _Func)
    -> decltype(ref new details::_AsyncTaskGeneratorThunk<_Function>(_Func));
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 `_Func`  
 O objeto de lambda ou função a partir do qual criar uma construção assíncrona de Tempo de execução do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma construção assíncrona representada por um IAsyncAction ^, IAsyncActionWithProgress\<TProgress > ^, IAsyncOperation\<TResult > ^, ou um IAsyncOperationWithProgress\<TResult, TProgress > ^. A interface retornada depende de assinatura do lambda passada na função.  
  
### <a name="remarks"></a>Comentários  
 O tipo de retorno do lambda determina se a construção é uma ação ou uma operação.  
  
 Lambdas que retornam void causam a criação de ações. Lambdas que retornam um resultado do tipo `TResult` causam a criação de operações de TResult.  
  
 Lambda também pode retornar um `task<TResult>` que encapsula o trabalho assíncrono em si mesmo ou é a continuação de uma cadeia de tarefas que representam o trabalho assíncrono. Nesse caso, o próprio lambda é executado em linha, uma vez que as tarefas são aqueles que são executadas de forma assíncrona e o tipo de retorno do lambda é desencapsulado para produzir a construção assíncrona retornada por `create_async`. Isso significa que uma expressão lambda que retorna uma tarefa\<void > fará com que a criação de uma expressão lambda que retorna uma tarefa e ações\<TResult > fará com que a criação de operações de TResult.  
  
 O lambda pode usar zero, um ou dois argumentos. Os argumentos válidos são `progress_reporter<TProgress>` e `cancellation_token`, nessa ordem se ambos forem usados. Um lambda sem argumentos causará a criação de uma construção assíncrona sem o recurso de relatório de andamento. Uma expressão lambda que leva um progress_reporter\<TProgress > fará com que `create_async` para retornar uma construção assíncrona que relata o andamento do tipo TProgress cada vez que o `report` é chamado de método do objeto progress_reporter. Um lambda que usa um cancellation_token pode usar esse token para verificar se há cancelamento ou passá-lo para tarefas que ele cria para que o cancelamento da construção assíncrona cause o cancelamento dessas tarefas.  
  
 Se o corpo do objeto lambda ou a função retornará um resultado (e não uma tarefa\<TResult >), o lamdba será executado de forma assíncrona dentro do processo MTA no contexto de uma tarefa, o tempo de execução cria implicitamente para ele. O método `IAsyncInfo::Cancel` causará o cancelamento da tarefa implícita.  
  
 Se o corpo do lambda retorna uma tarefa, o lambda será executado em linha e declarando-se o lambda para usar um argumento do tipo `cancellation_token` pode disparar o cancelamento de quaisquer tarefas criadas dentro do lambda passando esse token quando você as cria. Você também pode usar o método `register_callback` no token para fazer com que o Tempo de execução invoque um retorno de chamada ao chamar `IAsyncInfo::Cancel` na operação assíncrona ou na ação produzida.  
  
 Essa função só está disponível para aplicativos de tempo de execução do Windows.  
  
##  <a name="createresourcemanager"></a>  CreateResourceManager  
 Retorna uma interface que representa a instância singleton do Gerenciador de recursos do tempo de execução de simultaneidade. O Gerenciador de recursos é responsável pela atribuição de recursos a agendadores que deseja cooperam entre si.  
  
```
IResourceManager* __cdecl CreateResourceManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma interface `IResourceManager`.  
  
### <a name="remarks"></a>Comentários  
 Várias chamadas subsequentes para este método retornará a mesma instância do Gerenciador de recursos. Cada chamada para os incrementos de método uma referência de contagem no Gerenciador de recursos e deve ser associado com uma chamada para o [Iresourcemanager](http://msdn.microsoft.com/en-us/5d1356ec-fbd3-4284-a361-1e9e20bbb522) método quando o Agendador é feita com o Gerenciador de recursos de comunicação.  
  
 [unsupported_os](unsupported-os-class.md) é gerada se o sistema operacional não é suportado pelo tempo de execução de simultaneidade.  
  
##  <a name="create_task"></a>  create_task  
 Cria um PPL [tarefa](http://msdn.microsoft.com/en-us/5389e8a5-5038-40b6-844a-55e9b58ad35f) objeto. `create_task` pode ser usado em qualquer lugar você teria que usar um construtor de tarefa. Ele é fornecido principalmente para sua conveniência, pois permite o uso do `auto` palavra-chave durante a criação de tarefas.  
  
```
template<typename T>
__declspec(noinline) auto create_task(T _Param, const task_options& _TaskOptions = task_options())
    -> task<typename details::_TaskTypeFromParam<T>::T>;

template<typename _ReturnType>
__declspec( noinline) task<_ReturnType> create_task(const task<_ReturnType>& _Task);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo do parâmetro do qual a tarefa é a ser construído.  
  
 `_ReturnType`  
 `_Param`  
 O parâmetro do qual a tarefa é a ser construído. Isso pode ser um objeto de função ou lambda, um `task_completion_event` objeto, outro `task` objeto ou uma interface Windows::Foundation::IAsyncInfo se você estiver usando as tarefas em seu aplicativo UWP.  
  
 `_TaskOptions`  
 `_Task`  
  
### <a name="return-value"></a>Valor de retorno  
 Uma nova tarefa do tipo `T`, que é inferido do `_Param`.  
  
### <a name="remarks"></a>Comentários  
 A primeira sobrecarga se comporta como um construtor de tarefa que usa um único parâmetro.  
  
 A segunda sobrecarga associa o token de cancelamento fornecido com a tarefa recém-criada. Se você usar essa sobrecarga não são permitidas para passar um diferentes `task` objeto como o primeiro parâmetro.  
  
 O tipo da tarefa retornada é inferido do primeiro parâmetro para a função. Se `_Param` é um `task_completion_event<T>`, um `task<T>`, ou um functor que retorna um tipo `T` ou `task<T>`, o tipo da tarefa criado é `task<T>`.  
  
 Em um aplicativo UWP, se `_Param` é do tipo Windows::Foundation::IAsyncOperation\<T > ^ ou Windows::Foundation::IAsyncOperationWithProgress\<T, P > ^, ou um functor que retorna qualquer um desses tipos, a tarefa criada será de tipo `task<T>`. Se `_Param` é do tipo Windows::Foundation::IAsyncAction ^ ou Windows::Foundation::IAsyncActionWithProgress\<P > ^, ou um functor que retorna qualquer um desses tipos, a tarefa criada tem digitará `task<void>`.  
  
##  <a name="disabletracing">DisableTracing</a>  
 Desabilita o rastreamento em tempo de execução de simultaneidade. Essa função é preterida porque o rastreamento ETW é não registrado por padrão.  
  
```
__declspec(deprecated("Concurrency::DisableTracing is a deprecated function.")) _CRTIMP HRESULT __cdecl DisableTracing();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o rastreamento foi desabilitado corretamente, `S_OK` será retornado. Se o rastreamento não foi iniciado anteriormente, `E_NOT_STARTED` será retornado  
  
##  <a name="enabletracing"></a>  EnableTracing  
 Habilita o rastreamento em tempo de execução de simultaneidade. Essa função é preterida porque o rastreamento ETW está ativada por padrão.  
  
```
__declspec(deprecated("Concurrency::EnableTracing is a deprecated function.")) _CRTIMP HRESULT __cdecl EnableTracing();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o rastreamento foi iniciado corretamente, `S_OK` retornado; caso contrário, `E_NOT_STARTED` será retornado.  
  
##  <a name="free"></a>  Free  
 Libera um bloco de memória alocada anteriormente pelo `Alloc` método Suballocator de cache de tempo de execução a simultaneidade.  
  
```
void __cdecl Free(_Pre_maybenull_ _Post_invalid_ void* _PAllocation);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PAllocation`  
 Um ponteiro de memória anteriormente alocado pelo `Alloc` método que deve ser liberado. Se o parâmetro `_PAllocation` é definido como o valor `NULL`, esse método será ignorá-la e retorne imediatamente.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre quais cenários em seu aplicativo podem se beneficiar do usando o Suballocator de cache, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).  
  
##  <a name="get_ambient_scheduler"></a>  get_ambient_scheduler  
  
```
inline std::shared_ptr<::Concurrency::scheduler_interface> get_ambient_scheduler();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="getexecutioncontextid"></a>  GetExecutionContextId  
 Retorna um identificador exclusivo que pode ser atribuído a um contexto de execução que implementa o `IExecutionContext` interface.  
  
```
unsigned int __cdecl GetExecutionContextId();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador exclusivo para um contexto de execução.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para obter um identificador para o contexto de execução antes de você passar um `IExecutionContext` interface como um parâmetro para qualquer um dos métodos oferecidos pelo Gerenciador de recursos.  
  
##  <a name="getosversion"></a>  GetOSVersion  
 Retorna a versão do sistema operacional.  
  
```
IResourceManager::OSVersion __cdecl GetOSVersion();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor enumerado que representa o sistema operacional.  
  
### <a name="remarks"></a>Comentários  
 [unsupported_os](unsupported-os-class.md) é gerada se o sistema operacional não é suportado pelo tempo de execução de simultaneidade.  
  
##  <a name="getprocessorcount"></a>  GetProcessorCount  
 Retorna o número de threads de hardware do sistema subjacente.  
  
```
unsigned int __cdecl GetProcessorCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de threads de hardware.  
  
### <a name="remarks"></a>Comentários  
 [unsupported_os](unsupported-os-class.md) é gerada se o sistema operacional não é suportado pelo tempo de execução de simultaneidade.  
  
##  <a name="getprocessornodecount"></a>  GetProcessorNodeCount  
 Retorna o número de nós NUMA ou pacotes de processador no sistema subjacente.  
  
```
unsigned int __cdecl GetProcessorNodeCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de nós NUMA ou pacotes de processador.  
  
### <a name="remarks"></a>Comentários  
 Se o sistema contiver mais nós de pacotes de processador, o número de nós NUMA é retornado, caso contrário, o número de pacotes de processador é retornado.  
  
 [unsupported_os](unsupported-os-class.md) é gerada se o sistema operacional não é suportado pelo tempo de execução de simultaneidade.  
  
##  <a name="getschedulerid"></a>  GetSchedulerId  
 Retorna um identificador exclusivo que pode ser atribuído a um agendador que implementa o `IScheduler` interface.  
  
```
unsigned int __cdecl GetSchedulerId();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador exclusivo para um agendador.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para obter um identificador para o Agendador antes de você passar um `IScheduler` interface como um parâmetro para qualquer um dos métodos oferecidos pelo Gerenciador de recursos.  
  
##  <a name="internal_assign_iterators"></a>  internal_assign_iterators  
  
```
template<typename T, class _Ax>
template<class _I> 
void concurrent_vector<T, _Ax>::internal_assign_iterators(
   _I first,
   _I last);
```   
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 `_Ax`  
 `_I`  
 `first`  
 `last`  
  
##  <a name="interruption_point"></a>  interruption_point  
 Cria um ponto de interrupção de cancelamento. Se um cancelamento está em andamento no contexto em que essa função é chamada, isso gerará uma exceção interna que anula a execução do trabalho atualmente em execução paralela. Se o cancelamento não está em andamento, a função não faz nada.  
  
```
inline void interruption_point();
```  
  
### <a name="remarks"></a>Comentários  
 Você não deve capturar a exceção interna cancelamento gerada pelo `interruption_point()` função. A exceção será capturada e tratada pelo tempo de execução e detectá-lo pode fazer com que o programa se comportem de forma anormal.  
  
##  <a name="is_current_task_group_canceling"></a>  is_current_task_group_canceling  
 Retorna uma indicação de se a tarefa de grupo que está em execução atualmente embutido no contexto atual está em meio a um cancelamento ativado (ou será em breve). Observe que, se não houver nenhum grupo de tarefas em execução atualmente embutido no contexto atual, `false` será retornado.  
  
```
bool __cdecl is_current_task_group_canceling();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o grupo de tarefas que está em execução atualmente está cancelando, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).  
  
##  <a name="make_choice"></a>  make_choice  
 Constrói um `choice` bloco de mensagens de um recurso opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.  
  
```
template<typename T1, typename T2, typename... Ts>
choice<std::tuple<T1, T2, Ts...>> make_choice(
    Scheduler& _PScheduler,
    T1  _Item1,
    T2  _Item2,
    Ts... _Items);

template<typename T1, typename T2, typename... Ts>
choice<std::tuple<T1, T2, Ts...>> make_choice(
    ScheduleGroup& _PScheduleGroup,
    T1  _Item1,
    T2  _Item2,
    Ts... _Items);

template<typename T1, typename T2, typename... Ts>
choice<std::tuple<T1, T2, Ts...>> make_choice(
    T1  _Item1,
    T2  _Item2,
    Ts... _Items);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T1`  
 O tipo de bloco de mensagem da primeira fonte.  
  
 `T2`  
 O tipo de bloco de mensagens da origem do segundo.  
  
 `_PScheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefas para o `choice` bloco de mensagens está agendado.  
  
 `_Item1`  
 A primeira fonte.  
  
 `_Item2`  
 A segunda fonte.  
  
 `_Items`  
 Fontes adicionais.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefas para o `choice` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `choice` SMB com duas ou mais fontes de entrada.  
  
##  <a name="make_greedy_join"></a>  make_greedy_join  
 Constrói um `greedy multitype_join` bloco de mensagens de um recurso opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.  
  
```
template<typename T1, typename T2, typename... Ts>
multitype_join<std::tuple<T1, T2, Ts...>,greedy> make_greedy_join(
    Scheduler& _PScheduler,
    T1 _Item1,
    T2 _Item2,
    Ts... _Items);

template<typename T1, typename T2, typename... Ts>
multitype_join<std::tuple<T1, T2, Ts...>, greedy> make_greedy_join(
    ScheduleGroup& _PScheduleGroup,
    T1 _Item1,
    T2 _Item2,
    Ts... _Items);

template<typename T1, typename T2, typename... Ts>
multitype_join<std::tuple<T1, T2, Ts...>, greedy> make_greedy_join(
    T1 _Item1,
    T2 _Items,
    Ts... _Items);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T1`  
 O tipo de bloco de mensagem da primeira fonte.  
  
 `T2`  
 O tipo de bloco de mensagens da origem do segundo.  
  
 `_PScheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefas para o `multitype_join` bloco de mensagens está agendado.  
  
 `_Item1`  
 A primeira fonte.  
  
 `_Item2`  
 A segunda fonte.  
  
 `_Items`  
 Fontes adicionais.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefas para o `multitype_join` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `greedy multitype_join` SMB com duas ou mais fontes de entrada.  
  
##  <a name="make_join"></a>  make_join  
 Constrói um `non_greedy multitype_join` bloco de mensagens de um recurso opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.  
  
```
template<typename T1, typename T2, typename... Ts>
multitype_join<std::tuple<T1, T2, Ts...>> 
    make_join(
 Scheduler& _PScheduler,
    T1 _Item1,
    T2 _Item2,
    Ts... _Items);

template<typename T1, typename T2, typename... Ts>
multitype_join<std::tuple<T1, T2, Ts...>> make_join(
 ScheduleGroup& _PScheduleGroup,
    T1 _Item1,
    T2 _Item2,
    Ts... _Items);

template<typename T1, typename T2, typename... Ts>
multitype_join<std::tuple<T1, T2, Ts...>> make_join(
    T1 _Item1,
    T2 _Item2,
    Ts... _Items);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T1`  
 O tipo de bloco de mensagem da primeira fonte.  
  
 `T2`  
 O tipo de bloco de mensagens da origem do segundo.  
  
 `_PScheduler`  
 O `Scheduler` objeto dentro do qual a propagação de tarefas para o `multitype_join` bloco de mensagens está agendado.  
  
 `_Item1`  
 A primeira fonte.  
  
 `_Item2`  
 A segunda fonte.  
  
 `_Items`  
 Fontes adicionais.  
  
 `_PScheduleGroup`  
 O `ScheduleGroup` objeto dentro do qual a propagação de tarefas para o `multitype_join` bloco de mensagens está agendado. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `non_greedy multitype_join` SMB com duas ou mais fontes de entrada.  
  
##  <a name="make_task"></a>  make_task  
 Um método de fábrica para criar um `task_handle` objeto.  
  
```
template <class _Function>
task_handle<_Function> make_task(const _Function& _Func);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo do objeto de função que será chamado para executar o trabalho representado pelo `task_handle` objeto.  
  
 `_Func`  
 A função que será chamada para executar o trabalho representado pelo `task_handle` objeto. Isso pode ser um functor lambda, um ponteiro para uma função, ou qualquer objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto `task_handle`.  
  
### <a name="remarks"></a>Comentários  
 Essa função é útil quando você precisa criar um `task_handle` do objeto com uma expressão lambda, pois permite que você criar o objeto sem conhecer o verdadeiro tipo de functor o lambda.  
  
##  <a name="parallel_buffered_sort"></a>  parallel_buffered_sort  
 Organiza os elementos em um intervalo especificado em uma ordem nondescending, ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Essa função é semanticamente similar a `std::sort` porque é uma classificação de comparação instável, baseada no local, exceto que ele precisa `O(n)` espaço adicional e requer inicialização padrão para os elementos que estão sendo classificados.  
  
```
template<typename _Random_iterator>
inline void parallel_buffered_sort(
    const _Random_iterator& _Begin,
    const _Random_iterator& _End);

template<typename _Allocator,
    typename _Random_iterator>
inline void parallel_buffered_sort(
    const _Random_iterator& _Begin,
    const _Random_iterator& _End);

template<typename _Allocator,
    typename _Random_iterator>
inline void parallel_buffered_sort(
    const _Allocator& _Alloc,
    const _Random_iterator& _Begin,
    const _Random_iterator& _End);

template<typename _Random_iterator,
    typename _Function>
inline void parallel_buffered_sort(
    const _Random_iterator& _Begin,
    const _Random_iterator& _End,
    const _Function& _Func,
    const size_t _Chunk_size = 2048);

template<typename _Allocator,
    typename _Random_iterator,
    typename _Function>
inline void parallel_buffered_sort(
    const _Random_iterator& _Begin,
    const _Random_iterator& _End,
    const _Function& _Func,
    const size_t _Chunk_size = 2048);

template<typename _Allocator,
    typename _Random_iterator,
    typename _Function>
inline void parallel_buffered_sort(
    const _Allocator& _Alloc,
    const _Random_iterator& _Begin,
    const _Random_iterator& _End,
    const _Function& _Func,
    const size_t _Chunk_size = 2048);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Random_iterator`  
 O tipo de iterador de intervalo de entrada.  
  
 `_Allocator`  
 O tipo de um alocador de memória compatível da biblioteca padrão C++.  
  
 `_Function`  
 O tipo de comparador binário.  
  
 `_Begin`  
 Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser classificado.  
  
 `_End`  
 Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser classificado.  
  
 `_Alloc`  
 Uma instância de um alocador de memória compatível da biblioteca padrão C++.  
  
 `_Func`  
 Um objeto de função de predicado definida pelo usuário que define o critério de comparação a ser atendidas pelo sucessivos elementos na ordem. Um predicado binário usa dois argumentos e retorna `true` quando é atendido e `false` quando não é atendido. Essa função de comparador deve impor uma ordenação fraca estrita aos pares de elementos da sequência.  
  
 `_Chunk_size`  
 O tamanho mínimo de uma parte que será dividido em dois para execução paralela.  
  
### <a name="remarks"></a>Comentários  
 Todas as sobrecargas requerem `n * sizeof(T)` espaço adicional, onde `n` é o número de elementos a serem classificadas, e `T` é o tipo de elemento. Na maioria dos casos parallel_buffered_sort mostrará uma melhoria no desempenho em [parallel_sort](concurrency-namespace-functions.md), e você deve usá-lo sobre parallel_sort se você tiver a memória disponível.  
  
 Se você não fornecer um comparador binário `std::less` é usado como o padrão, o que requer que o tipo de elemento fornecer o operador `operator<()`.  
  
 Se você não fornecer um tipo de alocador ou instância, o alocador de memória da biblioteca padrão C++ `std::allocator<T>` é usada para alocar o buffer.  
  
 O algoritmo divide o intervalo de entrada em duas partes e sucessivamente divide cada bloco em duas partes sub para execução em paralelo. O argumento opcional `_Chunk_size` pode ser usado para indicar para o algoritmo que deve manipula partes de tamanho < `_Chunk_size` em série.  
  
##  <a name="parallel_for"></a>  parallel_for  
 `parallel_for` itera em um intervalo de índices e executa uma função fornecida pelo usuário em cada iteração em paralelo.  
  
```
template <typename _Index_type, typename _Function, typename _Partitioner>
void parallel_for(
    _Index_type first,
    _Index_type last,
    _Index_type _Step,
    const _Function& _Func,
    _Partitioner&& _Part);

template <typename _Index_type, typename _Function>
void parallel_for(
    _Index_type first,
    _Index_type last,
    _Index_type _Step,
    const _Function& _Func);

template <typename _Index_type, typename _Function>
void parallel_for(
    _Index_type first,
    _Index_type last,
    const _Function& _Func,
    const auto_partitioner& _Part = auto_partitioner());

template <typename _Index_type, typename _Function>
void parallel_for(
    _Index_type first,
    _Index_type last,
    const _Function& _Func,
    const static_partitioner& _Part);

template <typename _Index_type, typename _Function>
void parallel_for(
    _Index_type first,
    _Index_type last,
    const _Function& _Func,
    const simple_partitioner& _Part);

template <typename _Index_type, typename _Function>
void parallel_for(
    _Index_type first,
    _Index_type last,
    const _Function& _Func,
    affinity_partitioner& _Part);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index_type`  
 O tipo do índice que está sendo usado para a iteração.  
  
 `_Function`  
 O tipo da função que será executada em cada iteração.  
  
 `_Partitioner`  
 O tipo do particionador usado para particionar o intervalo fornecido.  
  
 `first`  
 O primeiro índice a ser incluído na iteração.  
  
 `last`  
 O índice de um após o último índice a ser incluído na iteração.  
  
 `_Step`  
 O valor pelo qual a etapa ao fazer a iteração de `first` para `last`. A etapa deve ser positiva. [invalid_argument](../../../standard-library/invalid-argument-class.md) é gerada se a etapa for menor que 1.  
  
 `_Func`  
 A função a ser executada em cada iteração. Isso pode ser uma expressão lambda, um ponteiro de função, ou qualquer objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()(_Index_type)`.  
  
 `_Part`  
 Uma referência ao objeto particionador. O argumento pode ser um dos `const` [auto_partitioner](auto-partitioner-class.md)`&`, `const` [static_partitioner](static-partitioner-class.md)`&`, `const` [simple_ o particionador](simple-partitioner-class.md) `&` ou [affinity_partitioner](affinity-partitioner-class.md) `&` se um [affinity_partitioner](affinity-partitioner-class.md) objeto é usado, a referência deve ser um valor de l não constante referência, para que o algoritmo possa armazenar o estado para futuras loops para reutilização.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [algoritmos paralelos](../../../parallel/concrt/parallel-algorithms.md).  
  
##  <a name="parallel_for_each"></a>  parallel_for_each  
 `parallel_for_each` aplica-se uma função específica para cada elemento em um intervalo, em paralelo. É semanticamente equivalente ao `for_each` funcionar a `std` namespace, exceto a iteração sobre elementos é executada em paralelo, e a ordem de iteração é especificada. O argumento `_Func` deve oferecer suporte a um operador de chamada de função do formulário `operator()(T)` onde o parâmetro `T` é o tipo de item de contêiner que está sendo feita a iteração.  
  
```
template <typename _Iterator, typename _Function>
void parallel_for_each(
    _Iterator first,
    _Iterator last,
    const _Function& _Func);

template <typename _Iterator, typename _Function, typename _Partitioner>
void parallel_for_each(
    _Iterator first,
    _Iterator last,
    const _Function& _Func,
    _Partitioner&& _Part);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Iterator`  
 O tipo de iterador que está sendo usado para iterar sobre o contêiner.  
  
 `_Function`  
 O tipo da função que será aplicada a cada elemento dentro do intervalo.  
  
 `_Partitioner`  
 `first`  
 Um iterador endereçamento a posição do primeiro elemento a ser incluído na iteração paralela.  
  
 `last`  
 Um iterador endereçamento a posição após o elemento final devem ser incluídos na iteração paralela.  
  
 `_Func`  
 Um objeto de função definida pelo usuário que é aplicado a cada elemento no intervalo.  
  
 `_Part`  
 Uma referência ao objeto particionador. O argumento pode ser um dos `const` [auto_partitioner](auto-partitioner-class.md)`&`, `const` [static_partitioner](static-partitioner-class.md)`&`, `const` [simple_ o particionador](simple-partitioner-class.md) `&` ou [affinity_partitioner](affinity-partitioner-class.md) `&` se um [affinity_partitioner](affinity-partitioner-class.md) objeto é usado, a referência deve ser um valor de l não constante referência, para que o algoritmo possa armazenar o estado para futuras loops para reutilização.  
  
### <a name="remarks"></a>Comentários  
 [auto_partitioner](auto-partitioner-class.md) será usado para a sobrecarga sem um particionador explícita.  
  
 Para acessar iteradores que não suportam aleatório, apenas [auto_partitioner](auto-partitioner-class.md) tem suporte.  
  
 Para obter mais informações, consulte [algoritmos paralelos](../../../parallel/concrt/parallel-algorithms.md).  
  
##  <a name="parallel_invoke"></a>  parallel_invoke  
 Executa os objetos de função fornecidos como parâmetros em paralelo e bloqueia até que concluiu a execução. Cada objeto de função pode ser uma expressão lambda, um ponteiro para função, ou qualquer objeto que suporta o operador de chamada de função com a assinatura `void operator()()`.  
  
```
template <typename _Function1, typename _Function2>
void parallel_invoke(
    const _Function1& _Func1,
    const _Function2& _Func2);

template <typename _Function1, typename _Function2, typename _Function3>
void parallel_invoke(
    const _Function1& _Func1,
    const _Function2& _Func2,
    const _Function3& _Func3);

template <typename _Function1,
    typename _Function2,
    typename _Function3,
    typename _Function4>
void parallel_invoke(
    const _Function1& _Func1,
    const _Function2& _Func2,
    const _Function3& _Func3,
    const _Function4& _Func4);

template <typename _Function1,
    typename _Function2,
    typename _Function3,
    typename _Function4,
    typename _Function5>
void parallel_invoke(
    const _Function1& _Func1,
    const _Function2& _Func2,
    const _Function3& _Func3,
    const _Function4& _Func4,
    const _Function5& _Func5);

template <typename _Function1,
    typename _Function2,
    typename _Function3,
    typename _Function4,
    typename _Function5,
    typename _Function6>
void parallel_invoke(
    const _Function1& _Func1,
    const _Function2& _Func2,
    const _Function3& _Func3,
    const _Function4& _Func4,
    const _Function5& _Func5,
    const _Function6& _Func6);

template <typename _Function1,
    typename _Function2,
    typename _Function3,
    typename _Function4,
    typename _Function5,
    typename _Function6,
    typename _Function7>
void parallel_invoke(
    const _Function1& _Func1,
    const _Function2& _Func2,
    const _Function3& _Func3,
    const _Function4& _Func4,
    const _Function5& _Func5,
    const _Function6& _Func6,
    const _Function7& _Func7);

template <typename _Function1,
    typename _Function2,
    typename _Function3,
    typename _Function4,
    typename _Function5,
    typename _Function6,
    typename _Function7,
    typename _Function8>
void parallel_invoke(
    const _Function1& _Func1,
    const _Function2& _Func2,
    const _Function3& _Func3,
    const _Function4& _Func4,
    const _Function5& _Func5,
    const _Function6& _Func6,
    const _Function7& _Func7,
    const _Function8& _Func8);

template <typename _Function1,
    typename _Function2,
    typename _Function3,
    typename _Function4,
    typename _Function5,
    typename _Function6,
    typename _Function7,
    typename _Function8,
    typename _Function9>
void parallel_invoke(
    const _Function1& _Func1,
    const _Function2& _Func2,
    const _Function3& _Func3,
    const _Function4& _Func4,
    const _Function5& _Func5,
    const _Function6& _Func6,
    const _Function7& _Func7,
    const _Function8& _Func8,
    const _Function9& _Func9);

template <typename _Function1,
    typename _Function2,
    typename _Function3,
    typename _Function4,
    typename _Function5,
    typename _Function6,
    typename _Function7,
    typename _Function8,
    typename _Function9,
    typename _Function10>
void parallel_invoke(
    const _Function1& _Func1,
    const _Function2& _Func2,
    const _Function3& _Func3,
    const _Function4& _Func4,
    const _Function5& _Func5,
    const _Function6& _Func6,
    const _Function7& _Func7,
    const _Function8& _Func8,
    const _Function9& _Func9,
    const _Function10& _Func10);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function1`  
 O tipo do primeiro objeto de função a ser executado em paralelo.  
  
 `_Function2`  
 O tipo do segundo objeto de função a ser executado em paralelo.  
  
 `_Function3`  
 O tipo do terceiro objeto de função a ser executado em paralelo.  
  
 `_Function4`  
 O tipo do objeto de função quarto a ser executado em paralelo.  
  
 `_Function5`  
 O tipo do objeto de função quinto a ser executado em paralelo.  
  
 `_Function6`  
 O tipo do objeto de função sexto a ser executado em paralelo.  
  
 `_Function7`  
 O tipo do sétimo objeto de função a ser executado em paralelo.  
  
 `_Function8`  
 O tipo do objeto de função oitavo a ser executado em paralelo.  
  
 `_Function9`  
 O tipo do objeto de função nono a ser executado em paralelo.  
  
 `_Function10`  
 O tipo do objeto de função décimo a ser executado em paralelo.  
  
 `_Func1`  
 O primeiro objeto de função a ser executado em paralelo.  
  
 `_Func2`  
 O segundo objeto de função a ser executado em paralelo.  
  
 `_Func3`  
 O terceiro objeto de função a ser executado em paralelo.  
  
 `_Func4`  
 O quarto objeto de função a ser executado em paralelo.  
  
 `_Func5`  
 O quinto objeto de função a ser executado em paralelo.  
  
 `_Func6`  
 O sexto objeto de função a ser executado em paralelo.  
  
 `_Func7`  
 O sétimo objeto de função a ser executado em paralelo.  
  
 `_Func8`  
 O objeto de função oitavo a ser executado em paralelo.  
  
 `_Func9`  
 O nono objeto de função a ser executado em paralelo.  
  
 `_Func10`  
 O décimo objeto de função a ser executado em paralelo.  
  
### <a name="remarks"></a>Comentários  
 Observe que um ou mais dos objetos de função fornecidos como parâmetros podem ser executada embutido no contexto do chamador.  
  
 Se um ou mais dos objetos de função passados como parâmetros para essa função lança uma exceção, o tempo de execução seleciona um tal exceção de sua escolha e propagá-lo sem a chamada para `parallel_invoke`.  
  
 Para obter mais informações, consulte [algoritmos paralelos](../../../parallel/concrt/parallel-algorithms.md).  
  
##  <a name="parallel_radixsort"></a>  parallel_radixsort  
 Organiza elementos em um intervalo especificado em uma ordem decrescente não usando um algoritmo de classificação de base. Essa é uma função de classificação estável que exige uma função de projeção que pode projetar elementos a serem classificados em chaves de tipo inteiro sem sinal. Inicialização padrão é necessária para os elementos que estão sendo classificados.  
  
```
template<typename _Random_iterator>
inline void parallel_radixsort(
    const _Random_iterator& _Begin,
    const _Random_iterator& _End);

template<typename _Allocator, typename _Random_iterator>
inline void parallel_radixsort(
    const _Random_iterator& _Begin,
    const _Random_iterator& _End);

template<typename _Allocator, typename _Random_iterator>
inline void parallel_radixsort(
    const _Allocator& _Alloc,
    const _Random_iterator& _Begin,
    const _Random_iterator& _End);

template<typename _Random_iterator, typename _Function>
inline void parallel_radixsort(
    const _Random_iterator& _Begin,
    const _Random_iterator& _End,
    const _Function& _Proj_func,
    const size_t _Chunk_size = 256* 256);

template<typename _Allocator, typename _Random_iterator,
    typename _Function>
inline void parallel_radixsort(
    const _Random_iterator& _Begin,
    const _Random_iterator& _End,
    const _Function& _Proj_func,
    const size_t _Chunk_size = 256* 256);

template<typename _Allocator,
    typename _Random_iterator,
    typename _Function>
inline void parallel_radixsort(
    const _Allocator& _Alloc,
    const _Random_iterator& _Begin,
    const _Random_iterator& _End,
    const _Function& _Proj_func,
    const size_t _Chunk_size = 256* 256);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Random_iterator`  
 O tipo de iterador de intervalo de entrada.  
  
 `_Allocator`  
 O tipo de um alocador de memória compatível da biblioteca padrão C++.  
  
 `_Function`  
 O tipo da função de projeção.  
  
 `_Begin`  
 Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser classificado.  
  
 `_End`  
 Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser classificado.  
  
 `_Alloc`  
 Uma instância de um alocador de memória compatível da biblioteca padrão C++.  
  
 `_Proj_func`  
 Um objeto de função de projeção definido pelo usuário que converte um elemento em um valor inteiro.  
  
 `_Chunk_size`  
 O tamanho mínimo de uma parte que será dividido em dois para execução paralela.  
  
### <a name="remarks"></a>Comentários  
 Todas as sobrecargas requerem `n * sizeof(T)` espaço adicional, onde `n` é o número de elementos a serem classificadas, e `T` é o tipo de elemento. Um functor de projeção unário com a assinatura `I _Proj_func(T)` é necessário para retornar uma chave quando um elemento específico, onde `T` é o tipo de elemento e `I` é um tipo de tipo inteiro sem sinal.  
  
 Se você não fornecer uma função de projeção, uma função de projeção padrão que simplesmente retorna o elemento é usada para tipos integrais. A função falhará se o elemento não é um tipo integral na ausência de uma função de projeção de compilação.  
  
 Se você não fornecer um tipo de alocador ou instância, o alocador de memória da biblioteca padrão C++ `std::allocator<T>` é usada para alocar o buffer.  
  
 O algoritmo divide o intervalo de entrada em duas partes e sucessivamente divide cada bloco em duas partes sub para execução em paralelo. O argumento opcional `_Chunk_size` pode ser usado para indicar para o algoritmo que deve manipula partes de tamanho < `_Chunk_size` em série.  
  
##  <a name="parallel_reduce"></a>  parallel_reduce  
 Calcula a soma de todos os elementos em um intervalo especificado Calculando somas parciais sucessivas ou calcula o resultado de sucessivos resultados parciais da mesma forma obtido usando uma operação binária especificada diferente de soma, em paralelo. `parallel_reduce` é semanticamente similar a `std::accumulate`, exceto que ele requer que a operação binária associativa e requer um valor de identidade em vez de um valor inicial.  
  
```
template<typename _Forward_iterator>
inline typename std::iterator_traits<_Forward_iterator>::value_type parallel_reduce(
    _Forward_iterator _Begin,
    _Forward_iterator _End,
    const typename std::iterator_traits<_Forward_iterator>::value_type& _Identity);

template<typename _Forward_iterator, typename _Sym_reduce_fun>
inline typename std::iterator_traits<_Forward_iterator>::value_type parallel_reduce(
    _Forward_iterator _Begin,
    _Forward_iterator _End,
    const typename std::iterator_traits<_Forward_iterator>::value_type& _Identity,
    _Sym_reduce_fun _Sym_fun);

template<typename _Reduce_type,
    typename _Forward_iterator,
    typename _Range_reduce_fun,
    typename _Sym_reduce_fun>
inline _Reduce_type parallel_reduce(
    _Forward_iterator _Begin,
    _Forward_iterator _End,
    const _Reduce_type& _Identity,
    const _Range_reduce_fun& _Range_fun,
    const _Sym_reduce_fun& _Sym_fun);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Forward_iterator`  
 O tipo de iterador do intervalo de entrada.  
  
 `_Sym_reduce_fun`  
 O tipo da função redução simétrica. Isso deve ser um tipo de função com assinatura `_Reduce_type _Sym_fun(_Reduce_type, _Reduce_type)`, onde _Reduce_type é o mesmo como o tipo de identidade e o tipo de resultado de redução. Para a terceira sobrecarga, isso deve ser consistente com o tipo de saída de `_Range_reduce_fun`.  
  
 `_Reduce_type`  
 O tipo que pode reduzir a entrada, que pode ser diferente do tipo de elemento de entrada. O valor de retorno e o valor de identidade serão tem esse tipo.  
  
 `_Range_reduce_fun`  
 O tipo da função de redução de intervalo. Isso deve ser um tipo de função com assinatura `_Reduce_type _Range_fun(_Forward_iterator, _Forward_iterator, _Reduce_type)`, _Reduce_type é o mesmo que o tipo de identidade e o tipo de resultado de redução.  
  
 `_Begin`  
 Um iterador de entrada do primeiro elemento em um intervalo de endereçamento seja reduzido.  
  
 `_End`  
 Um iterador de entrada endereçamento do elemento que é uma posição fora o elemento final no intervalo a ser reduzido.  
  
 `_Identity`  
 O valor de identidade `_Identity` é do mesmo tipo como o tipo de resultado da redução e também o `value_type` do iterador para as sobrecargas de primeiro e segundo. Para a terceira sobrecarga, o valor de identidade deve ter o mesmo tipo que o tipo de resultado de redução, mas pode ser diferente de `value_type` do iterador. Ele deve ter um valor apropriado, de modo que o operador de redução de intervalo `_Range_fun`, quando aplicado a um intervalo de um único elemento de tipo `value_type` e o valor de identidade, se comporta como uma conversão de tipo do valor do tipo `value_type` para o tipo de identidade.  
  
 `_Sym_fun`  
 A função simétrica que será usada no segundo de redução. Para obter mais informações, consulte comentários.  
  
 `_Range_fun`  
 A função que será usada na primeira fase de redução. Para obter mais informações, consulte comentários.  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado da redução.  
  
### <a name="remarks"></a>Comentários  
 Para executar uma redução em paralela, a função divide o intervalo em partes com base no número de trabalhadores disponíveis para o Agendador subjacente. A redução ocorre em duas fases, a primeira fase executa uma redução em cada bloco e a segunda fase executa uma redução entre os resultados parciais de cada parte.  
  
 A primeira sobrecarga requer que o iterador `value_type`, `T`, ser o mesmo como o tipo de valor de identidade, bem como o tipo de resultado de redução. O tipo de elemento T deve fornecer o operador `T T::operator + (T)` para reduzir os elementos em cada bloco. O mesmo operador é usado na segunda fase.  
  
 A segunda sobrecarga também requer que o iterador `value_type` ser o mesmo como o tipo de valor de identidade, bem como o tipo de resultado de redução. O operador binário fornecido `_Sym_fun` é usado em ambas as fases de redução, com o valor de identidade como o valor inicial para a primeira fase.  
  
 Para a terceira sobrecarga, o tipo de valor de identidade deve ser o mesmo como o tipo de resultado de redução, mas o iterador `value_type` pode ser diferente de ambos. A função de redução de intervalo `_Range_fun` é usado na primeira etapa com o valor de identidade como o valor inicial e a função binária `_Sym_reduce_fun` é aplicada para sub resultados na segunda fase.  
  
##  <a name="parallel_sort"></a>  parallel_sort  
 Organiza os elementos em um intervalo especificado em uma ordem nondescending, ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Essa função é semanticamente semelhante ao `std::sort` porque é uma classificação de comparação instável, baseada no local.  
  
```
template<typename _Random_iterator>
inline void parallel_sort(
    const _Random_iterator& _Begin,
    const _Random_iterator& _End);

template<typename _Random_iterator,typename _Function>
inline void parallel_sort(
    const _Random_iterator& _Begin,
    const _Random_iterator& _End,
    const _Function& _Func,
    const size_t _Chunk_size = 2048);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Random_iterator`  
 O tipo de iterador de intervalo de entrada.  
  
 `_Function`  
 O tipo de functor a comparação binária.  
  
 `_Begin`  
 Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser classificado.  
  
 `_End`  
 Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser classificado.  
  
 `_Func`  
 Um objeto de função de predicado definida pelo usuário que define o critério de comparação a ser atendidas pelo sucessivos elementos na ordem. Um predicado binário usa dois argumentos e retorna `true` quando é atendido e `false` quando não é atendido. Essa função de comparador deve impor uma ordenação fraca estrita aos pares de elementos da sequência.  
  
 `_Chunk_size`  
 O tamanho mínimo de uma parte que será dividido em dois para execução paralela.  
  
### <a name="remarks"></a>Comentários  
 A primeira sobrecarga usa o comparador binário `std::less`.  
  
 O segundo sobrecarregado usa o comparador binário fornecido deve ter a assinatura `bool _Func(T, T)` onde `T` é o tipo dos elementos no intervalo de entrada.  
  
 O algoritmo divide o intervalo de entrada em duas partes e sucessivamente divide cada bloco em duas partes sub para execução em paralelo. O argumento opcional `_Chunk_size` pode ser usado para indicar para o algoritmo que deve manipula partes de tamanho < `_Chunk_size` em série.  
  
##  <a name="parallel_transform"></a>  parallel_transform  
 Aplica-se a um objeto de função especificado para cada elemento em um intervalo de origem ou para um par de elementos de dois intervalos de origem e copia os valores de retorno do objeto de função em um intervalo de destino, em paralelo. Nesse funcional é semanticamente equivalente a `std::transform`.  
  
```
template <typename _Input_iterator1,
    typename _Output_iterator,
    typename _Unary_operator>
_Output_iterator parallel_transform(
    _Input_iterator1 first1,
    _Input_iterator1 last1,
    _Output_iterator _Result,
    const _Unary_operator& _Unary_op,
    const auto_partitioner& _Part = auto_partitioner());

template <typename _Input_iterator1,
    typename _Output_iterator,
    typename _Unary_operator>
_Output_iterator parallel_transform(
    _Input_iterator1 first1,
    _Input_iterator1 last1,
    _Output_iterator _Result,
    const _Unary_operator& _Unary_op,
    const static_partitioner& _Part);

template <typename _Input_iterator1,
    typename _Output_iterator,
    typename _Unary_operator>
_Output_iterator parallel_transform(
    _Input_iterator1 first1,
    _Input_iterator1 last1,
    _Output_iterator _Result,
    const _Unary_operator& _Unary_op,
    const simple_partitioner& _Part);

template <typename _Input_iterator1,
    typename _Output_iterator,
    typename _Unary_operator>
_Output_iterator parallel_transform(
    _Input_iterator1 first1,
    _Input_iterator1 last1,
    _Output_iterator _Result,
    const _Unary_operator& _Unary_op,
    affinity_partitioner& _Part);

template <typename _Input_iterator1,
    typename _Input_iterator2,
    typename _Output_iterator,
    typename _Binary_operator,
    typename _Partitioner>
_Output_iterator parallel_transform(
    _Input_iterator1 first1,
    _Input_iterator1 last1,
    _Input_iterator2
 first2,
    _Output_iterator _Result,
    const _Binary_operator& _Binary_op,
    _Partitioner&& _Part);

template <typename _Input_iterator1,
    typename _Input_iterator2,
    typename _Output_iterator,
    typename _Binary_operator>
_Output_iterator parallel_transform(
    _Input_iterator1 first1,
    _Input_iterator1 last1,
    _Input_iterator2
 first2,
    _Output_iterator _Result,
    const _Binary_operator& _Binary_op);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Input_iterator1`  
 O tipo do primeiro ou apenas iterador de entrada.  
  
 `_Output_iterator`  
 O tipo de iterador de saída.  
  
 `_Unary_operator`  
 O tipo de functor o unário para ser executado em cada elemento no intervalo de entrada.  
  
 `_Input_iterator2`  
 O tipo do segundo iterador de entrada.  
  
 `_Binary_operator`  
 O tipo do binário functor pairwise executado nos elementos de intervalos de origem de dois.  
  
 `_Partitioner`  
 `first1`  
 Um iterador de entrada endereçamento a posição do primeiro elemento na primeira ou apenas o intervalo de origem a ser operado.  
  
 `last1`  
 Um iterador de entrada a uma posição após o elemento final no primeiro ou apenas o intervalo de origem a ser operado de endereçamento.  
  
 `_Result`  
 Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino.  
  
 `_Unary_op`  
 Um objeto de função definida pelo usuário unário é aplicado a cada elemento no intervalo de origem.  
  
 `_Part`  
 Uma referência ao objeto particionador. O argumento pode ser um dos `const` [auto_partitioner](auto-partitioner-class.md)`&`, `const` [static_partitioner](static-partitioner-class.md)`&`, `const` [simple_ o particionador](simple-partitioner-class.md) `&` ou [affinity_partitioner](affinity-partitioner-class.md) `&` se um [affinity_partitioner](affinity-partitioner-class.md) objeto é usado, a referência deve ser um valor de l não constante referência, para que o algoritmo possa armazenar o estado para futuras loops para reutilização.  
  
 `first2`  
 Um iterador de entrada que trata da posição do primeiro elemento no segundo intervalo de origem no qual a operação ocorrerá.  
  
 `_Binary_op`  
 Um objeto de binários de função definida pelo usuário que é aplicado em cache, em uma ordem de encaminhamento, para os intervalos de origem de dois.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de saída que trata da posição logo após o elemento final no intervalo de destino que está recebendo os elementos de saída transformados pelo objeto de função.  
  
### <a name="remarks"></a>Comentários  
 [auto_partitioner](auto-partitioner-class.md) será usado para as sobrecargas sem um argumento particionador explícita.  
  
 Para acessar iteradores que não suportam aleatório, apenas [auto_partitioner](auto-partitioner-class.md) tem suporte.  
  
 As sobrecargas que têm o argumento `_Unary_op` transformar o intervalo de entrada para o intervalo de saída aplicando o functor unário para cada elemento no intervalo de entrada. `_Unary_op` deve oferecer suporte para o operador de chamada de função com assinatura `operator()(T)` onde `T` é o tipo de valor do intervalo que está sendo feita a iteração.  
  
 As sobrecargas que têm o argumento `_Binary_op` transformar dois intervalos de entrada para o intervalo de saída aplicando o binário functor para um elemento de entrada primeiro intervalo e um elemento do segundo intervalo de entrada. `_Binary_op` deve oferecer suporte para o operador de chamada de função com assinatura `operator()(T, U)` onde `T`, `U` são tipos de valor dos dois iteradores de entrada.  
  
 Para obter mais informações, consulte [algoritmos paralelos](../../../parallel/concrt/parallel-algorithms.md).  
  
##  <a name="receive"></a>  Receber  
 Geral receber implementação, permitindo que um contexto aguardar a exatamente uma fonte de dados e filtrar os valores que são aceitos.  
  
```
template <class T>
T receive(
    _Inout_ ISource<T>* _Src,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);

template <class T>
T receive(
    _Inout_ ISource<T>* _Src,
    typename ITarget<T>::filter_method const& _Filter_proc,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);

template <class T>
T receive(
    ISource<T>& _Src,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);

template <class T>
T receive(
    ISource<T>& _Src,
    typename ITarget<T>::filter_method const& _Filter_proc,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de carga.  
  
 `_Src`  
 Um ponteiro ou uma referência para a origem da qual os dados são esperados.  
  
 `_Timeout`  
 O tempo máximo para o qual o método deve para os dados, em milissegundos.  
  
 `_Filter_proc`  
 Uma função de filtro que determina se as mensagens devem ser aceitas.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de origem, o tipo de carga.  
  
### <a name="remarks"></a>Comentários  
 Se o parâmetro `_Timeout` tem um valor que não seja a constante `COOPERATIVE_TIMEOUT_INFINITE`, a exceção [operation_timed_out](operation-timed-out-class.md) é gerada se o período de tempo especificado expirar antes que uma mensagem é recebida. Se você quiser que um limite de comprimento zero, você deve usar o [try_receive](concurrency-namespace-functions.md) função, em vez de chamar `receive` com um tempo limite de `0` (zero), pois é mais eficiente e não lançar exceções em tempos limite.  
  
 Para obter mais informações, consulte [funções de transmissão de mensagens](../../../parallel/concrt/message-passing-functions.md).  
  
##  <a name="run_with_cancellation_token"></a>  run_with_cancellation_token  
 Executa um objeto de função imediatamente e de forma síncrona no contexto de um token de cancelamento determinado.  
  
```
template<typename _Function>
void run_with_cancellation_token(
    const _Function& _Func,
    cancellation_token _Ct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo do objeto de função que será chamado.  
  
 `_Func`  
 O objeto de função que será executado. Este objeto deve dar suporte o operador de chamada de função com uma assinatura de void(void).  
  
 `_Ct`  
 O token de cancelamento que controlará o cancelamento implícita do objeto de função. Use `cancellation_token::none()` se você deseja executar a função sem qualquer possibilidade de cancelamento implícita de um grupo de tarefa pai que está sendo cancelado.  
  
### <a name="remarks"></a>Comentários  
 Os pontos de interrupção no objeto de função serão disparados quando o `cancellation_token` é cancelada. O token explícito `_Ct` isolará isso `_Func` de cancelamento de pai, se o pai tiver um token diferente ou não.  
  
##  <a name="send"></a>  send  
 Uma operação síncrona de envio, aguarda até que o destino aceita ou recusa a mensagem.  
  
```
template <class T>
bool send(_Inout_ ITarget<T>* _Trg, const T& _Data);

template <class T>
bool send(ITarget<T>& _Trg, const T& _Data);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de carga.  
  
 `_Trg`  
 Um ponteiro ou uma referência para o destino ao qual os dados são enviados.  
  
 `_Data`  
 Uma referência para os dados a serem enviados.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se a mensagem foi aceita, `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [funções de transmissão de mensagens](../../../parallel/concrt/message-passing-functions.md).  
  
##  <a name="set_ambient_scheduler"></a>  set_ambient_scheduler  
  
```
inline void set_ambient_scheduler(std::shared_ptr<::Concurrency::scheduler_interface> _Scheduler);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Scheduler`  
  
##  <a name="set_task_execution_resources"></a>  set_task_execution_resources  
 Restringe os recursos de execução usados pelos threads de trabalho interno de tempo de execução de simultaneidade para o conjunto especificado de afinidade.  
  
 É válido chamar esse método antes do Gerenciador de recursos foi criado, ou entre dois tempos de vida do Gerenciador de recursos. Ele pode ser chamado várias vezes desde que o Gerenciador de recursos não existe no momento da invocação. Depois que um limite de afinidade tiver sido definido, ele permanecerá em vigor até a próxima chamada válida para o `set_task_execution_resources` método.  
  
 A máscara de afinidade fornecida não precisa ser um subconjunto da máscara de afinidade de processo. A afinidade do processo será atualizada se necessário.  
  
```
void __cdecl set_task_execution_resources(
    DWORD_PTR _ProcessAffinityMask);

void __cdecl set_task_execution_resources(
    unsigned short count,
    PGROUP_AFFINITY _PGroupAffinity);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_ProcessAffinityMask`  
 A máscara de afinidade de threads de trabalho de tempo de execução de simultaneidade devem ser restritas a. Use esse método em um sistema com mais de 64 threads de hardware somente se você quiser limitar o tempo de execução de simultaneidade para um subconjunto do grupo de processador atual. Em geral, você deve usar a versão do método que aceita uma matriz de afinidades de grupo como um parâmetro, a fim de restringir afinidade em computadores com mais de 64 threads de hardware.  
  
 `count`  
 O número de `GROUP_AFFINITY` entradas na matriz especificada pelo parâmetro `_PGroupAffinity`.  
  
 `_PGroupAffinity`  
 Uma matriz de `GROUP_AFFINITY` entradas.  
  
### <a name="remarks"></a>Comentários  
 O método lançará um [invalid_operation](invalid-operation-class.md) exceção se um Gerenciador de recursos está presente no momento em que ele é invocado, e um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se a afinidade especificada resulta em um conjunto vazio de recursos.  
  
 A versão do método que usa uma matriz de afinidades de grupo como um parâmetro só deve ser usada em sistemas operacionais com a versão do Windows 7 ou superior. Caso contrário, um [invalid_operation](invalid-operation-class.md) exceção será lançada.  
  
 Modificar programaticamente a afinidade do processo depois que esse método foi chamado não fará com que o Gerenciador de recursos para reavaliar a afinidade, que ele é restrito aos. Portanto, a afinidade de processar todas as alterações devem ser feitas antes de chamar esse método.  
  
##  <a name="swap"></a>  swap  
 Troca os elementos de dois objetos `concurrent_vector`.  
  
```
template<typename T, class _Ax>
inline void swap(
    concurrent_vector<T, _Ax>& _A,
    concurrent_vector<T, _Ax>& _B);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados dos elementos armazenados em vetores de simultâneas.  
  
 `_Ax`  
 O tipo do alocador de vetores de simultâneas.  
  
 `_A`  
 O vetor simultâneo cujos elementos são sejam trocadas com aquelas do vetor simultâneo `_B`.  
  
 `_B`  
 O vetor simultâneo fornecendo os elementos a ser trocado ou vetor cujos elementos são sejam trocadas com aquelas do vetor simultâneo `_A`.  
  
### <a name="remarks"></a>Comentários  
 A função de modelo é um algoritmo especializado na classe de contêiner `concurrent_vector` para executar a função de membro `_A`. [concurrent_vector::swap](concurrent-vector-class.md#swap)( `_B`). Essas são instâncias de ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função do modelo, `template <class T> void swap(T&, T&)`, no algoritmo classe funciona por meio da atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.  
  
 Este método não é seguro de simultaneidade. Certifique-se de que nenhum outro thread está executando operações em qualquer um dos vetores de simultâneas quando você chamar esse método.  
  
##  <a name="task_from_exception"></a>  task_from_exception  
  
```
template<typename _TaskType, typename _ExType>
task<_TaskType> task_from_exception(
    _ExType _Exception,
    const task_options& _TaskOptions = task_options());
```  
  
### <a name="parameters"></a>Parâmetros  
 `_TaskType`  
 `_ExType`  
 `_Exception`  
 `_TaskOptions`  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="task_from_result"></a>  task_from_result  
  
```
template<typename T>
task<T> task_from_result(
    T _Param,
    const task_options& _TaskOptions = task_options());

inline task<bool> task_from_result(ool _Param);

inline task<void> task_from_result(
    const task_options& _TaskOptions = task_options());
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 `_Param`  
 `_TaskOptions`  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="trace_agents_register_name"></a>  Trace_agents_register_name  
 Associa o nome fornecido para o bloco de mensagens ou o agente no rastreamento ETW.  
  
```
template <class T>
void Trace_agents_register_name(
    _Inout_ T* _PObject,
    _In_z_ const wchar_t* _Name);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo do objeto. Isso normalmente é um bloco de mensagens ou um agente.  
  
 `_PObject`  
 Um ponteiro para o bloco de mensagens ou o agente que está sendo chamado no rastreamento.  
  
 `_Name`  
 O nome para o objeto fornecido.  
  
##  <a name="try_receive"></a>  try_receive  
 Geral try e recebimento de implementação, permitindo que um contexto procurar dados de exatamente uma fonte e filtrar os valores que são aceitos. Se os dados não estiverem prontos, o método retornará false.  
  
``` 
template <class T>
bool try_receive(_Inout_ ISource<T>* _Src, T& _value);

template <class T>
bool try_receive(
    _Inout_ ISource<T>* _Src,
    T& _value,
    typename ITarget<T>::filter_method const& _Filter_proc);

template <class T>
bool try_receive(ISource<T>& _Src, T& _value);

template <class T>
bool try_receive(
    ISource<T>& _Src,
    T& _value,
    typename ITarget<T>::filter_method const& _Filter_proc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de carga  
  
 `_Src`  
 Um ponteiro ou uma referência para a origem da qual os dados são esperados.  
  
 `_value`  
 Uma referência a um local onde o resultado será colocado.  
  
 `_Filter_proc`  
 Uma função de filtro que determina se as mensagens devem ser aceitas.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `bool` valor que indica se ou não uma carga foi colocada em `_value`.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [funções de transmissão de mensagens](../../../parallel/concrt/message-passing-functions.md).  
  
##  <a name="wait"></a>  wait  
 Pausa o contexto atual para um período de tempo especificado.  
  
```
void __cdecl wait(unsigned int _Milliseconds);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Milliseconds`  
 O número de milissegundos que o contexto atual deve ser pausado para. Se o `_Milliseconds` parâmetro está definido como o valor `0`, o contexto atual deve resultar em execução a outros contextos de execução antes de continuar.  
  
### <a name="remarks"></a>Comentários  
 Se esse método for chamado em um contexto de Agendador do tempo de execução de simultaneidade, o Agendador encontrará um contexto diferente para executar no recurso subjacente. Como o Agendador é cooperativo por natureza, neste contexto não é possível retomar exatamente após o número de milissegundos especificado. Se o Agendador está ocupado executando outras tarefas que não geram trabalhem de forma para o Agendador, o período de espera pode ser indefinido.  
  
##  <a name="when_all"></a>  when_all  
 Cria uma tarefa que será concluída com êxito quando todas as tarefas fornecidas como argumentos forem concluídas com êxito.  
  
```
template <typename _Iterator>
auto when_all(
    _Iterator _Begin,
    _Iterator _End,
    const task_options& _TaskOptions = task_options()) -> 
    decltype (details::_WhenAllImpl<typename std::iterator_traits<_Iterator>::value_type::result_type,
    _Iterator>::_Perform(_TaskOptions, _Begin,  _End));
```   
  
### <a name="parameters"></a>Parâmetros  
 `_Iterator`  
 O tipo do iterador de entrada.  
  
 `_Begin`  
 A posição do primeiro elemento no intervalo de elementos a ser combinada na tarefa resultante.  
  
 `_End`  
 A posição do primeiro elemento além do intervalo de elementos a ser combinada na tarefa resultante.  
  
 `_TaskOptions`  
  
### <a name="return-value"></a>Valor de retorno  
 Uma tarefa que é concluída com êxito quando todas as tarefas de entrada tiverem sido concluídas com êxito. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::vector<T>>`. Se as tarefas de entrada forem do tipo `void`, a tarefa de saída também será um `task<void>`.  
  
### <a name="remarks"></a>Comentários  
 `when_all` é uma função sem bloqueio que produz um `task` como resultado. Ao contrário de [Task:: wait](task-class.md#wait), é seguro chamar essa função em um aplicativo UWP no thread de ASTA (aplicativo STA).  
  
 Se uma das tarefas foi cancelada ou gera uma exceção, a tarefa retornada será concluída no início, no estado cancelado, e a exceção, se houver um encontrou, será gerada se você chamar [Task:: Get](task-class.md#get) ou `task::wait` nessa tarefa.  
  
 Para obter mais informações, consulte [paralelismo de tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
##  <a name="when_any"></a>  when_any  
 Cria uma tarefa que será concluída com êxito quando todas as tarefas fornecidas como argumentos forem concluídas com êxito.  
  
```
template<typename _Iterator>
auto when_any(
    _Iterator _Begin,
    _Iterator _End,
    const task_options& _TaskOptions = task_options()) 
    -> decltype (
        details::_WhenAnyImpl<
            typename std::iterator_traits<_Iterator>::value_type::result_type,
            _Iterator>::_Perform(_TaskOptions, _Begin, _End));

template<typename _Iterator>
auto when_any(
    _Iterator _Begin,
    _Iterator _End,
    cancellation_token _CancellationToken) 
       -> decltype (
           details::_WhenAnyImpl<
               typename std::iterator_traits<_Iterator>::value_type::result_type,
               _Iterator>::_Perform(_CancellationToken._GetImplValue(), _Begin, _End));
```   
  
### <a name="parameters"></a>Parâmetros  
 `_Iterator`  
 O tipo do iterador de entrada.  
  
 `_Begin`  
 A posição do primeiro elemento no intervalo de elementos a ser combinada na tarefa resultante.  
  
 `_End`  
 A posição do primeiro elemento além do intervalo de elementos a ser combinada na tarefa resultante.  
  
 `_TaskOptions`  
 `_CancellationToken`  
 O token de cancelamento que controla o cancelamento da tarefa retornada. Se você não fornecer um token de cancelamento, a tarefa resultante receberá o token de cancelamento da tarefa que fez com que ela fosse concluída.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma tarefa que foi concluída com êxito quando alguma das tarefas de entrada foi concluída com êxito. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::pair<T, size_t>>>`, em que o primeiro elemento do par é o resultado da conclusão da tarefa e o segundo elemento é o índice da tarefa que foi concluída. Se as tarefas de entrada forem do tipo `void`, a saída será um `task<size_t>`, em que o resultado é o índice de conclusão da tarefa.  
  
### <a name="remarks"></a>Comentários  
 `when_any` é uma função sem bloqueio que produz um `task` como resultado. Ao contrário de [Task:: wait](task-class.md#wait), é seguro chamar essa função em um aplicativo UWP no thread de ASTA (aplicativo STA).  
  
 Para obter mais informações, consulte [paralelismo de tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
