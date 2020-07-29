---
title: Funções do namespace de simultaneidade
ms.date: 11/04/2016
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
ms.assetid: 520a6dff-9324-4df2-990d-302e3050af6a
ms.openlocfilehash: 86324d126fa1c3b659e6500579c4a1d220874094
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87182740"
---
# <a name="concurrency-namespace-functions"></a>Funções do namespace de simultaneidade

||||
|-|-|-|
|[Alocação](#alloc)|[CreateResourceManager](#createresourcemanager)|[DisableTracing](#disabletracing)|
|[EnableTracing](#enabletracing)|[Gratuito](#free)|[GetExecutionContextId](#getexecutioncontextid)|
|[GetOSVersion](#getosversion)|[GetProcessorCount](#getprocessorcount)|[GetProcessorNodeCount](#getprocessornodecount)|
|[GetSchedulerId](#getschedulerid)|[Trace_agents_register_name](#trace_agents_register_name)|[asend](#asend)|
|[cancel_current_task](#cancel_current_task)|[formatação](#clear)|[create_async](#create_async)|
|[create_task](#create_task)|[get_ambient_scheduler](#get_ambient_scheduler)|[internal_assign_iterators](#internal_assign_iterators)|
|[interruption_point](#interruption_point)|[is_current_task_group_canceling](#is_current_task_group_canceling)|[make_choice](#make_choice)|
|[make_greedy_join](#make_greedy_join)|[make_join](#make_join)|[make_task](#make_task)|
|[parallel_buffered_sort](#parallel_buffered_sort)|[parallel_for](#parallel_for)|[parallel_for_each](#parallel_for_each)|
|[parallel_invoke](#parallel_invoke)|[parallel_radixsort](#parallel_radixsort)|[parallel_reduce](#parallel_reduce)|
|[parallel_sort](#parallel_sort)|[parallel_transform](#parallel_transform)|[recebe](#receive)|
|[run_with_cancellation_token](#run_with_cancellation_token)|[send](#send)|[set_ambient_scheduler](#set_ambient_scheduler)|
|[set_task_execution_resources](#set_task_execution_resources)|[permuta](#swap)|[task_from_exception](#task_from_exception)|
|[task_from_result](#task_from_result)|[try_receive](#try_receive)|[esperado](#wait)|
|[when_all](#when_all)|[when_any](#when_any)|

## <a name="alloc"></a><a name="alloc"></a>Alocação

Aloca um bloco de memória do tamanho especificado no subalocador de cache Tempo de Execução de Simultaneidade.

```cpp
void* __cdecl Alloc(size_t _NumBytes);
```

### <a name="parameters"></a>parâmetros

*_NumBytes*<br/>
O número de bytes de memória a serem alocados.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a memória alocada recentemente.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre quais cenários em seu aplicativo podem se beneficiar do uso do subalocador de cache, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).

## <a name="asend"></a><a name="asend"></a>asend

Uma operação Send assíncrona, que agenda uma tarefa para propagar os dados para o bloco de destino.

```cpp
template <class T>
bool asend(
    _Inout_ ITarget<T>* _Trg,
    const T& _Data);

template <class T>
bool asend(
    ITarget<T>& _Trg,
    const T& _Data);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo dos dados a serem enviados.

*_Trg*<br/>
Um ponteiro ou referência ao destino para o qual os dados são enviados.

*_Data*<br/>
Uma referência aos dados a serem enviados.

### <a name="return-value"></a>Valor retornado

**`true`** se a mensagem foi aceita antes do retorno do método, **`false`** caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [funções de passagem de mensagens](../../../parallel/concrt/message-passing-functions.md).

## <a name="cancel_current_task"></a><a name="cancel_current_task"></a>cancel_current_task

Cancela a tarefa atualmente em execução. Essa função pode ser chamada de dentro do corpo de uma tarefa para interromper a execução da tarefa e fazer com que ela entre no estado `canceled`.

Não é um cenário com suporte para chamar essa função se você não estiver dentro do corpo de uma `task`. Isso resultará em um comportamento indefinido, como uma falha ou uma falta de resposta em seu aplicativo.

```cpp
inline __declspec(noreturn) void __cdecl cancel_current_task();
```

## <a name="clear"></a><a name="clear"></a>formatação

Limpa a fila simultânea, destruindo todos os elementos atualmente enfileirados. Esse método não é seguro para simultaneidade.

```cpp
template<typename T, class _Ax>
void concurrent_queue<T, _Ax>::clear();
```

### <a name="parameters"></a>parâmetros

*T*<br/>

*_Ax*<br/>

## <a name="create_async"></a><a name="create_async"></a>create_async

Cria uma construção assíncrona de Windows Runtime com base em um objeto de função ou lambda fornecido pelo usuário. O tipo de retorno de `create_async` é `IAsyncAction^`, `IAsyncActionWithProgress<TProgress>^`, `IAsyncOperation<TResult>^` ou `IAsyncOperationWithProgress<TResult, TProgress>^` com base na assinatura do lambda passada para o método.

```cpp
template<typename _Function>
__declspec(noinline) auto create_async(const _Function& _Func)
    -> decltype(ref new details::_AsyncTaskGeneratorThunk<_Function>(_Func));
```

### <a name="parameters"></a>parâmetros

*_Function*<br/>
Digite.

*_Func*<br/>
O objeto de lambda ou função a partir do qual criar uma construção assíncrona de Windows Runtime.

### <a name="return-value"></a>Valor retornado

Uma construção assíncrona representada por um IAsyncAction ^, IAsyncActionWithProgress \<TProgress> ^, IAsyncOperation \<TResult> ^ ou IAsyncOperationWithProgress \<TResult, TProgress> ^. A interface retornada depende de assinatura do lambda passada na função.

### <a name="remarks"></a>Comentários

O tipo de retorno do lambda determina se a construção é uma ação ou uma operação.

Lambdas que retornam void causam a criação de ações. Lambdas que retornam um resultado do tipo `TResult` causam a criação de operações de TResult.

Lambda também pode retornar um `task<TResult>` que encapsula o trabalho assíncrono em si mesmo ou é a continuação de uma cadeia de tarefas que representam o trabalho assíncrono. Nesse caso, o próprio lambda é executado em linha, uma vez que as tarefas são aqueles que são executadas de forma assíncrona e o tipo de retorno do lambda é desencapsulado para produzir a construção assíncrona retornada por `create_async`. Isso implica que um lambda que retorna uma tarefa causará \<void> a criação de ações, e um lambda que retorna uma tarefa causará \<TResult> a criação de operações de TResult.

O lambda pode usar zero, um ou dois argumentos. Os argumentos válidos são `progress_reporter<TProgress>` e `cancellation_token`, nessa ordem se ambos forem usados. Um lambda sem argumentos causará a criação de uma construção assíncrona sem o recurso de relatório de andamento. Um lambda que usa um progress_reporter \<TProgress> fará com que `create_async` o retorne um constructo assíncrono que relate o progresso do tipo TProgress cada vez que o `report` método do objeto progress_reporter for chamado. Um lambda que usa um cancellation_token pode usar esse token para verificar se há cancelamento ou passá-lo para tarefas que ele cria para que o cancelamento da construção assíncrona cause o cancelamento dessas tarefas.

Se o corpo do objeto lambda ou de função retornar um resultado (e não uma tarefa \<TResult> ), o Lamdba será executado de forma assíncrona no MTA do processo no contexto de uma tarefa que o runtime cria implicitamente. O método `IAsyncInfo::Cancel` causará o cancelamento da tarefa implícita.

Se o corpo do lambda retorna uma tarefa, o lambda será executado em linha e declarando-se o lambda para usar um argumento do tipo `cancellation_token` pode disparar o cancelamento de quaisquer tarefas criadas dentro do lambda passando esse token quando você as cria. Você também pode usar o método `register_callback` no token para fazer com que o Runtime invoque um retorno de chamada ao chamar `IAsyncInfo::Cancel` na operação assíncrona ou na ação produzida.

Essa função só está disponível para Windows Runtime aplicativos.

## <a name="createresourcemanager"></a><a name="createresourcemanager"></a>CreateResourceManager

Retorna uma interface que representa a instância singleton do Gerenciador de recursos do Tempo de Execução de Simultaneidade. O Gerenciador de recursos é responsável por atribuir recursos a agendadores que desejam cooperar uns com os outros.

```cpp
IResourceManager* __cdecl CreateResourceManager();
```

### <a name="return-value"></a>Valor retornado

Uma interface `IResourceManager`.

### <a name="remarks"></a>Comentários

Várias chamadas subsequentes para esse método retornarão a mesma instância do Gerenciador de recursos. Cada chamada para o método incrementa uma contagem de referência no Gerenciador de recursos e deve ser correspondida com uma chamada para o método [IResourceManager:: Release](iresourcemanager-structure.md) quando o Agendador terminar de se comunicar com o Gerenciador de recursos.

[unsupported_os](unsupported-os-class.md) será gerada se o sistema operacional não tiver suporte do tempo de execução de simultaneidade.

## <a name="create_task"></a><a name="create_task"></a>create_task

Cria um objeto de [tarefa](task-class.md) ppl. `create_task`pode ser usado em qualquer lugar em que você tenha usado um construtor de tarefa. Ele é fornecido principalmente por conveniência, pois permite o uso da **`auto`** palavra-chave durante a criação de tarefas.

```cpp
template<typename T>
__declspec(noinline) auto create_task(T _Param, const task_options& _TaskOptions = task_options())
    -> task<typename details::_TaskTypeFromParam<T>::T>;

template<typename _ReturnType>
__declspec( noinline) task<_ReturnType> create_task(const task<_ReturnType>& _Task);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo do parâmetro do qual a tarefa deve ser construída.

*_ReturnType*<br/>
Digite.

*_Param*<br/>
O parâmetro do qual a tarefa deve ser construída. Isso pode ser um objeto lambda ou de função, um `task_completion_event` objeto, um `task` objeto diferente ou uma interface Windows:: Foundation:: IAsyncInfo se você estiver usando tarefas em seu aplicativo UWP.

*_TaskOptions*<br/>
As opções de tarefa.

*_Task*<br/>
A tarefa a ser criada.

### <a name="return-value"></a>Valor retornado

Uma nova tarefa do tipo `T` , que é inferida de `_Param` .

### <a name="remarks"></a>Comentários

A primeira sobrecarga se comporta como um construtor de tarefa que usa um único parâmetro.

A segunda sobrecarga associa o token de cancelamento fornecido à tarefa recém-criada. Se você usar essa sobrecarga, não poderá passar um `task` objeto diferente como o primeiro parâmetro.

O tipo da tarefa retornada é inferido do primeiro parâmetro para a função. Se `_Param` for a `task_completion_event<T>` , a `task<T>` ou um functor que retorna um dos tipos `T` ou `task<T>` , o tipo da tarefa criada será `task<T>` .

Em um aplicativo UWP, se `_Param` for do tipo Windows:: Foundation:: IAsyncOperation \<T> ^ ou Windows:: Foundation:: IAsyncOperationWithProgress \<T,P> ^ ou um functor que retorna um desses tipos, a tarefa criada será do tipo `task<T>` . Se `_Param` for do tipo Windows:: Foundation:: IAsyncAction ^ ou Windows:: Foundation:: IAsyncActionWithProgress \<P> ^ ou um functor que retorna um desses tipos, a tarefa criada terá o tipo `task<void>` .

## <a name="disabletracing"></a><a name="disabletracing"></a>DisableTracing

Desabilita o rastreamento no Tempo de Execução de Simultaneidade. Essa função é preterida porque o rastreamento ETW tem o registro cancelado por padrão.

```cpp
__declspec(deprecated("Concurrency::DisableTracing is a deprecated function.")) _CRTIMP HRESULT __cdecl DisableTracing();
```

### <a name="return-value"></a>Valor retornado

Se o rastreamento foi desabilitado corretamente, `S_OK` será retornado. Se o rastreamento não foi iniciado anteriormente, `E_NOT_STARTED` será retornado

## <a name="enabletracing"></a><a name="enabletracing"></a>EnableTracing

Habilita o rastreamento no Tempo de Execução de Simultaneidade. Essa função foi preterida porque o rastreamento ETW agora está ativado por padrão.

```cpp
__declspec(deprecated("Concurrency::EnableTracing is a deprecated function.")) _CRTIMP HRESULT __cdecl EnableTracing();
```

### <a name="return-value"></a>Valor retornado

Se o rastreamento foi iniciado corretamente, `S_OK` será retornado; caso contrário, `E_NOT_STARTED` será retornado.

## <a name="free"></a><a name="free"></a>Informações

Libera um bloco de memória alocado anteriormente pelo `Alloc` método para o subalocador de cache tempo de execução de simultaneidade.

```cpp
void __cdecl Free(_Pre_maybenull_ _Post_invalid_ void* _PAllocation);
```

### <a name="parameters"></a>parâmetros

*_PAllocation*<br/>
Um ponteiro para a memória alocada anteriormente pelo `Alloc` método que deve ser liberado. Se o parâmetro `_PAllocation` for definido como o valor `NULL` , esse método irá ignorá-lo e retornar imediatamente.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre quais cenários em seu aplicativo podem se beneficiar do uso do subalocador de cache, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).

## <a name="get_ambient_scheduler"></a><a name="get_ambient_scheduler"></a>get_ambient_scheduler

```cpp
inline std::shared_ptr<::Concurrency::scheduler_interface> get_ambient_scheduler();
```

### <a name="return-value"></a>Valor retornado

## <a name="getexecutioncontextid"></a><a name="getexecutioncontextid"></a>GetExecutionContextId

Retorna um identificador exclusivo que pode ser atribuído a um contexto de execução que implementa a `IExecutionContext` interface.

```cpp
unsigned int __cdecl GetExecutionContextId();
```

### <a name="return-value"></a>Valor retornado

Um identificador exclusivo para um contexto de execução.

### <a name="remarks"></a>Comentários

Use este método para obter um identificador para seu contexto de execução antes de passar uma `IExecutionContext` interface como um parâmetro para qualquer um dos métodos oferecidos pelo Gerenciador de recursos.

## <a name="getosversion"></a><a name="getosversion"></a>GetOSVersion

Retorna a versão do sistema operacional.

```cpp
IResourceManager::OSVersion __cdecl GetOSVersion();
```

### <a name="return-value"></a>Valor retornado

Um valor enumerado que representa o sistema operacional.

### <a name="remarks"></a>Comentários

[unsupported_os](unsupported-os-class.md) será gerada se o sistema operacional não tiver suporte do tempo de execução de simultaneidade.

## <a name="getprocessorcount"></a><a name="getprocessorcount"></a>GetProcessorCount

Retorna o número de threads de hardware no sistema subjacente.

```cpp
unsigned int __cdecl GetProcessorCount();
```

### <a name="return-value"></a>Valor retornado

O número de threads de hardware.

### <a name="remarks"></a>Comentários

[unsupported_os](unsupported-os-class.md) será gerada se o sistema operacional não tiver suporte do tempo de execução de simultaneidade.

## <a name="getprocessornodecount"></a><a name="getprocessornodecount"></a>GetProcessorNodeCount

Retorna o número de nós NUMA ou pacotes de processador no sistema subjacente.

```cpp
unsigned int __cdecl GetProcessorNodeCount();
```

### <a name="return-value"></a>Valor retornado

O número de nós NUMA ou pacotes de processador.

### <a name="remarks"></a>Comentários

Se o sistema contiver mais nós NUMA do que pacotes de processador, o número de nós NUMA será retornado, caso contrário, o número de pacotes de processador será retornado.

[unsupported_os](unsupported-os-class.md) será gerada se o sistema operacional não tiver suporte do tempo de execução de simultaneidade.

## <a name="getschedulerid"></a><a name="getschedulerid"></a>GetSchedulerId

Retorna um identificador exclusivo que pode ser atribuído a um Agendador que implementa a `IScheduler` interface.

```cpp
unsigned int __cdecl GetSchedulerId();
```

### <a name="return-value"></a>Valor retornado

Um identificador exclusivo para um Agendador.

### <a name="remarks"></a>Comentários

Use esse método para obter um identificador para o Agendador antes de passar uma `IScheduler` interface como um parâmetro para qualquer um dos métodos oferecidos pelo Gerenciador de recursos.

## <a name="internal_assign_iterators"></a><a name="internal_assign_iterators"></a>internal_assign_iterators

```cpp
template<typename T, class _Ax>
template<class _I>
void concurrent_vector<T, _Ax>::internal_assign_iterators(
   _I first,
   _I last);
```

### <a name="parameters"></a>parâmetros

*T*<br/>

*_Ax*<br/>

*_I*<br/>

*first*<br/>

*last*<br/>

## <a name="interruption_point"></a><a name="interruption_point"></a>interruption_point

Cria um ponto de interrupção para o cancelamento. Se um cancelamento estiver em andamento no contexto em que essa função é chamada, isso gerará uma exceção interna que anula a execução do trabalho paralelo em execução no momento. Se o cancelamento não estiver em andamento, a função não fará nada.

```cpp
inline void interruption_point();
```

### <a name="remarks"></a>Comentários

Você não deve capturar a exceção de cancelamento interna gerada pela `interruption_point()` função. A exceção será capturada e tratada pelo tempo de execução e a captura poderá fazer com que o seu programa se comporte de forma anormal.

## <a name="is_current_task_group_canceling"></a><a name="is_current_task_group_canceling"></a>is_current_task_group_canceling

Retorna uma indicação de se o grupo de tarefas que está atualmente em execução embutida no contexto atual está no meio de um cancelamento ativo (ou será em breve). Observe que, se não houver nenhum grupo de tarefas atualmente em execução embutido no contexto atual, **`false`** será retornado.

```cpp
bool __cdecl is_current_task_group_canceling();
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o grupo de tarefas que está sendo executado no momento estiver sendo cancelado, **`false`** caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).

## <a name="make_choice"></a><a name="make_choice"></a>make_choice

Constrói um `choice` bloco de mensagens de um opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.

```cpp
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

### <a name="parameters"></a>parâmetros

*T1*<br/>
O tipo de bloco de mensagem da primeira origem.

*T2*<br/>
O tipo de bloco de mensagens da segunda fonte.

*_PScheduler*<br/>
O `Scheduler` objeto no qual a tarefa de propagação para o `choice` bloco de mensagens está agendada.

*_Item1*<br/>
A primeira origem.

*_Item2*<br/>
A segunda origem.

*_Items*<br/>
Fontes adicionais.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto no qual a tarefa de propagação para o `choice` bloco de mensagens está agendada. O `Scheduler` objeto usado é implícito pelo grupo de agendamento.

### <a name="return-value"></a>Valor retornado

Um `choice` bloco de mensagens com duas ou mais fontes de entrada.

## <a name="make_greedy_join"></a><a name="make_greedy_join"></a>make_greedy_join

Constrói um `greedy multitype_join` bloco de mensagens de um opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.

```cpp
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

### <a name="parameters"></a>parâmetros

*T1*<br/>
O tipo de bloco de mensagem da primeira origem.

*T2*<br/>
O tipo de bloco de mensagens da segunda fonte.

*_PScheduler*<br/>
O `Scheduler` objeto no qual a tarefa de propagação para o `multitype_join` bloco de mensagens está agendada.

*_Item1*<br/>
A primeira origem.

*_Item2*<br/>
A segunda origem.

*_Items*<br/>
Fontes adicionais.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto no qual a tarefa de propagação para o `multitype_join` bloco de mensagens está agendada. O `Scheduler` objeto usado é implícito pelo grupo de agendamento.

### <a name="return-value"></a>Valor retornado

Um `greedy multitype_join` bloco de mensagens com duas ou mais fontes de entrada.

## <a name="make_join"></a><a name="make_join"></a>make_join

Constrói um `non_greedy multitype_join` bloco de mensagens de um opcional `Scheduler` ou `ScheduleGroup` e duas ou mais fontes de entrada.

```cpp
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

### <a name="parameters"></a>parâmetros

*T1*<br/>
O tipo de bloco de mensagem da primeira origem.

*T2*<br/>
O tipo de bloco de mensagens da segunda fonte.

*_PScheduler*<br/>
O `Scheduler` objeto no qual a tarefa de propagação para o `multitype_join` bloco de mensagens está agendada.

*_Item1*<br/>
A primeira origem.

*_Item2*<br/>
A segunda origem.

*_Items*<br/>
Fontes adicionais.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto no qual a tarefa de propagação para o `multitype_join` bloco de mensagens está agendada. O `Scheduler` objeto usado é implícito pelo grupo de agendamento.

### <a name="return-value"></a>Valor retornado

Um `non_greedy multitype_join` bloco de mensagens com duas ou mais fontes de entrada.

## <a name="make_task"></a><a name="make_task"></a>make_task

Um método de fábrica para criar um `task_handle` objeto.

```cpp
template <class _Function>
task_handle<_Function> make_task(const _Function& _Func);
```

### <a name="parameters"></a>parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para executar o trabalho representado pelo `task_handle` objeto.

*_Func*<br/>
A função que será invocada para executar o trabalho representado pelo `task_handle` objeto. Isso pode ser um functor lambda, um ponteiro para uma função ou qualquer objeto que ofereça suporte a uma versão do operador de chamada de função com a assinatura `void operator()()` .

### <a name="return-value"></a>Valor retornado

Um objeto `task_handle`.

### <a name="remarks"></a>Comentários

Essa função é útil quando você precisa criar um `task_handle` objeto com uma expressão lambda, pois ela permite que você crie o objeto sem saber o tipo true do functor lambda.

## <a name="parallel_buffered_sort"></a><a name="parallel_buffered_sort"></a>parallel_buffered_sort

Organiza os elementos em um intervalo especificado em uma ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Essa função é semanticamente semelhante ao `std::sort` que é uma classificação baseada em comparação, instável, in-loco, exceto que precisa de `O(n)` espaço adicional, e requer a inicialização padrão para os elementos que estão sendo classificados.

```cpp
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

### <a name="parameters"></a>parâmetros

*_Random_iterator*<br/>
O tipo de iterador do intervalo de entrada.

*_Allocator*<br/>
O tipo de um alocador de memória compatível com biblioteca padrão C++.

*_Function*<br/>
O tipo do comparador de binário.

*_Begin*<br/>
Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser classificado.

*_End*<br/>
Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser classificado.

*_Alloc*<br/>
Uma instância de um alocador de memória compatível com biblioteca padrão C++.

*_Func*<br/>
Um objeto de função de predicado definido pelo usuário que define o critério de comparação a ser satisfeito por elementos sucessivos na ordenação. Um predicado binário usa dois argumentos e retorna **`true`** quando satisfeito e **`false`** quando não está satisfeito. Essa função de comparador deve impor uma ordenação fraca estrita aos pares de elementos da sequência.

*_Chunk_size*<br/>
O tamanho de mínimo de uma parte que será dividida em duas para execução paralela.

### <a name="remarks"></a>Comentários

Todas as sobrecargas exigem `n * sizeof(T)` espaço adicional, em que `n` é o número de elementos a serem classificados e `T` é o tipo de elemento. Na maioria dos casos parallel_buffered_sort mostrará uma melhoria no desempenho do [parallel_sort](concurrency-namespace-functions.md), e você deverá usá-lo em parallel_sort se tiver a memória disponível.

Se você não fornecer um comparador de binário `std::less` é usado como o padrão, o que exige que o tipo de elemento forneça o operador `operator<()` .

Se você não fornecer um tipo ou instância de alocador, o alocador de memória da biblioteca padrão C++ `std::allocator<T>` será usado para alocar o buffer.

O algoritmo divide o intervalo de entrada em duas partes e divide sucessivamente cada parte em duas subpartes para execução em paralelo. O argumento opcional `_Chunk_size` pode ser usado para indicar ao algoritmo que ele deve manipular partes do tamanho < em `_Chunk_size` série.

## <a name="parallel_for"></a><a name="parallel_for"></a>parallel_for

`parallel_for`itera em um intervalo de índices e executa uma função fornecida pelo usuário em cada iteração, em paralelo.

```cpp
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

### <a name="parameters"></a>parâmetros

*_Index_type*<br/>
O tipo do índice que está sendo usado para a iteração.

*_Function*<br/>
O tipo da função que será executada em cada iteração.

*_Partitioner*<br/>
O tipo do particionador que é usado para particionar o intervalo fornecido.

*first*<br/>
O primeiro índice a ser incluído na iteração.

*last*<br/>
O índice que ultrapassou o último índice a ser incluído na iteração.

*_Step*<br/>
O valor pelo qual percorrer ao iterar de `first` para `last` . A etapa deve ser positiva. [invalid_argument](../../../standard-library/invalid-argument-class.md) será gerada se a etapa for menor que 1.

*_Func*<br/>
A função a ser executada em cada iteração. Isso pode ser uma expressão lambda, um ponteiro de função ou qualquer objeto que ofereça suporte a uma versão do operador de chamada de função com a assinatura `void operator()(_Index_type)` .

*_Part*<br/>
Uma referência ao objeto do particionador. O argumento pode ser um dos **`const`** [auto_partitioner](auto-partitioner-class.md) `&` , **`const`** [static_partitioner](static-partitioner-class.md) `&` , **`const`** [simple_partitioner](simple-partitioner-class.md) `&` ou [affinity_partitioner](affinity-partitioner-class.md) `&` se um objeto [affinity_partitioner](affinity-partitioner-class.md) for usado, a referência deverá ser uma referência não const l-Value, para que o algoritmo possa armazenar o estado para loops futuros a serem reutilizados.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [algoritmos paralelos](../../../parallel/concrt/parallel-algorithms.md).

## <a name="parallel_for_each"></a><a name="parallel_for_each"></a>parallel_for_each

`parallel_for_each`aplica uma função especificada para cada elemento dentro de um intervalo, em paralelo. É semanticamente equivalente à `for_each` função no `std` namespace, exceto que a iteração sobre os elementos é executada em paralelo e a ordem de iteração não é especificada. O argumento `_Func` deve dar suporte a um operador de chamada de função no formato `operator()(T)` em que o parâmetro `T` é o tipo de item do contêiner que está sendo iterado.

```cpp
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

### <a name="parameters"></a>parâmetros

*_Iterator*<br/>
O tipo do iterador que está sendo usado para iterar no contêiner.

*_Function*<br/>
O tipo da função que será aplicada a cada elemento dentro do intervalo.

*_Partitioner*<br/>
*first*<br/>
Um iterador que aborda a posição do primeiro elemento a ser incluído na iteração paralela.

*last*<br/>
Um iterador que aborda a posição um passado do elemento final a ser incluído na iteração paralela.

*_Func*<br/>
Um objeto de função definido pelo usuário que é aplicado a cada elemento no intervalo.

*_Part*<br/>
Uma referência ao objeto do particionador. O argumento pode ser um dos **`const`** [auto_partitioner](auto-partitioner-class.md) `&` , **`const`** [static_partitioner](static-partitioner-class.md) `&` , **`const`** [simple_partitioner](simple-partitioner-class.md) `&` ou [affinity_partitioner](affinity-partitioner-class.md) `&` se um objeto [affinity_partitioner](affinity-partitioner-class.md) for usado, a referência deverá ser uma referência não const l-Value, para que o algoritmo possa armazenar o estado para loops futuros a serem reutilizados.

### <a name="remarks"></a>Comentários

[auto_partitioner](auto-partitioner-class.md) será usado para a sobrecarga sem um particionador explícito.

Para iteradores que não dão suporte ao acesso aleatório, há suporte apenas para [auto_partitioner](auto-partitioner-class.md) .

Para obter mais informações, consulte [algoritmos paralelos](../../../parallel/concrt/parallel-algorithms.md).

## <a name="parallel_invoke"></a><a name="parallel_invoke"></a>parallel_invoke

Executa os objetos de função fornecidos como parâmetros em paralelo e os blocos até que tenham concluído a execução. Cada objeto de função pode ser uma expressão lambda, um ponteiro para função ou qualquer objeto que dê suporte ao operador de chamada de função com a assinatura `void operator()()` .

```cpp
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

### <a name="parameters"></a>parâmetros

*_Function1*<br/>
O tipo do primeiro objeto de função a ser executado em paralelo.

*_Function2*<br/>
O tipo do segundo objeto de função a ser executado em paralelo.

*_Function3*<br/>
O tipo do terceiro objeto de função a ser executado em paralelo.

*_Function4*<br/>
O tipo do quarto objeto de função a ser executado em paralelo.

*_Function5*<br/>
O tipo do quinto objeto de função a ser executado em paralelo.

*_Function6*<br/>
O tipo do sexto objeto de função a ser executado em paralelo.

*_Function7*<br/>
O tipo do sétimo objeto de função a ser executado em paralelo.

*_Function8*<br/>
O tipo do oitavo objeto de função a ser executado em paralelo.

*_Function9*<br/>
O tipo do nono objeto de função a ser executado em paralelo.

*_Function10*<br/>
O tipo do décimo objeto de função a ser executado em paralelo.

*_Func1*<br/>
O primeiro objeto de função a ser executado em paralelo.

*_Func2*<br/>
O segundo objeto de função a ser executado em paralelo.

*_Func3*<br/>
O terceiro objeto de função a ser executado em paralelo.

*_Func4*<br/>
O quarto objeto de função a ser executado em paralelo.

*_Func5*<br/>
O quinto objeto de função a ser executado em paralelo.

*_Func6*<br/>
O sexto objeto de função a ser executado em paralelo.

*_Func7*<br/>
O sétimo objeto de função a ser executado em paralelo.

*_Func8*<br/>
O oitavo objeto de função a ser executado em paralelo.

*_Func9*<br/>
O nono objeto de função a ser executado em paralelo.

*_Func10*<br/>
O décimo objeto de função a ser executado em paralelo.

### <a name="remarks"></a>Comentários

Observe que um ou mais dos objetos de função fornecidos como parâmetros podem ser executados embutidos no contexto de chamada.

Se um ou mais dos objetos de função passados como parâmetros para essa função lançar uma exceção, o tempo de execução selecionará uma exceção de sua escolha e a propagará da chamada para `parallel_invoke` .

Para obter mais informações, consulte [algoritmos paralelos](../../../parallel/concrt/parallel-algorithms.md).

## <a name="parallel_radixsort"></a><a name="parallel_radixsort"></a>parallel_radixsort

Organiza os elementos em um intervalo especificado em uma ordem não decrescente usando um algoritmo de classificação de base. Essa é uma função de classificação estável que requer uma função de projeção que pode projetar elementos a serem classificados em chaves semelhantes a inteiros não assinadas. A inicialização padrão é necessária para os elementos que estão sendo classificados.

```cpp
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

### <a name="parameters"></a>parâmetros

*_Random_iterator*<br/>
O tipo de iterador do intervalo de entrada.

*_Allocator*<br/>
O tipo de um alocador de memória compatível com biblioteca padrão C++.

*_Function*<br/>
O tipo da função de projeção.

*_Begin*<br/>
Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser classificado.

*_End*<br/>
Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser classificado.

*_Alloc*<br/>
Uma instância de um alocador de memória compatível com biblioteca padrão C++.

*_Proj_func*<br/>
Um objeto de função de projeção definido pelo usuário que converte um elemento em um valor integral.

*_Chunk_size*<br/>
O tamanho de mínimo de uma parte que será dividida em duas para execução paralela.

### <a name="remarks"></a>Comentários

Todas as sobrecargas exigem `n * sizeof(T)` espaço adicional, em que `n` é o número de elementos a serem classificados e `T` é o tipo de elemento. Uma projeção unário functor com a assinatura `I _Proj_func(T)` é necessária para retornar uma chave quando um elemento é fornecido, em que `T` é o tipo de elemento e `I` é um tipo de inteiro sem sinal.

Se você não fornecer uma função de projeção, uma função de projeção padrão que simplesmente retorna o elemento é usada para tipos integrais. A função não será compilada se o elemento não for um tipo integral na ausência de uma função de projeção.

Se você não fornecer um tipo ou instância de alocador, o alocador de memória da biblioteca padrão C++ `std::allocator<T>` será usado para alocar o buffer.

O algoritmo divide o intervalo de entrada em duas partes e divide sucessivamente cada parte em duas subpartes para execução em paralelo. O argumento opcional `_Chunk_size` pode ser usado para indicar ao algoritmo que ele deve manipular partes do tamanho < em `_Chunk_size` série.

## <a name="parallel_reduce"></a><a name="parallel_reduce"></a>parallel_reduce

Computa a soma de todos os elementos em um intervalo especificado computando somas parciais sucessivas ou computa o resultado de resultados parciais sucessivos de forma semelhante ao uso de uma operação binária especificada diferente de Sum, em paralelo. `parallel_reduce`é semanticamente semelhante a `std::accumulate` , exceto pelo fato de que ela requer que a operação binária seja associativa e requer um valor de identidade em vez de um valor inicial.

```cpp
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

### <a name="parameters"></a>parâmetros

*_Forward_iterator*<br/>
O tipo de iterador do intervalo de entrada.

*_Sym_reduce_fun*<br/>
O tipo da função de redução simétrica. Esse deve ser um tipo de função com assinatura `_Reduce_type _Sym_fun(_Reduce_type, _Reduce_type)` , em que _Reduce_type é o mesmo que o tipo de identidade e o tipo de resultado da redução. Para a terceira sobrecarga, isso deve ser consistente com o tipo de saída de `_Range_reduce_fun` .

*_Reduce_type*<br/>
O tipo para o qual a entrada será reduzida, que pode ser diferente do tipo de elemento de entrada. O valor de retorno e o valor de identidade terão esse tipo.

*_Range_reduce_fun*<br/>
O tipo da função de redução de intervalo. Esse deve ser um tipo de função com assinatura `_Reduce_type _Range_fun(_Forward_iterator, _Forward_iterator, _Reduce_type)` , _Reduce_type é o mesmo que o tipo de identidade e o tipo de resultado da redução.

*_Begin*<br/>
Um iterador de entrada que aborda o primeiro elemento no intervalo a ser reduzido.

*_End*<br/>
Um iterador de entrada que aborda o elemento que é uma posição além do elemento final no intervalo a ser reduzido.

*_Identity*<br/>
O valor de identidade `_Identity` é do mesmo tipo que o tipo de resultado da redução e também o `value_type` do iterador para a primeira e segunda sobrecargas. Para a terceira sobrecarga, o valor de identidade deve ter o mesmo tipo do tipo de resultado da redução, mas pode ser diferente do `value_type` do iterador. Ele deve ter um valor apropriado, de modo que o operador de redução de intervalo `_Range_fun` , quando aplicado a um intervalo de um único elemento do tipo `value_type` e o valor de identidade, se comporta como uma conversão de tipo do valor de tipo `value_type` para o tipo de identidade.

*_Sym_fun*<br/>
A função simétrica que será usada no segundo da redução. Consulte comentários para obter mais informações.

*_Range_fun*<br/>
A função que será usada na primeira fase da redução. Consulte comentários para obter mais informações.

### <a name="return-value"></a>Valor retornado

O resultado da redução.

### <a name="remarks"></a>Comentários

Para executar uma redução paralela, a função divide o intervalo em partes com base no número de trabalhadores disponíveis para o Agendador subjacente. A redução ocorre em duas fases, a primeira fase executa uma redução em cada parte e a segunda fase executa uma redução entre os resultados parciais de cada parte.

A primeira sobrecarga requer que o iterador `value_type` , `T` , seja o mesmo que o tipo de valor de identidade, bem como o tipo de resultado de redução. O tipo de elemento T deve fornecer o operador `T T::operator + (T)` para reduzir os elementos em cada parte. O mesmo operador também é usado na segunda fase.

A segunda sobrecarga também exige que o iterador `value_type` seja o mesmo que o tipo de valor de identidade, bem como o tipo de resultado de redução. O operador binário fornecido `_Sym_fun` é usado em ambas as fases de redução, com o valor de identidade como o valor inicial para a primeira fase.

Para a terceira sobrecarga, o tipo de valor de identidade deve ser o mesmo que o tipo de resultado de redução, mas o iterador `value_type` pode ser diferente de ambos. A função de redução de intervalo `_Range_fun` é usada na primeira fase com o valor de identidade como o valor inicial e a função Binary `_Sym_reduce_fun` é aplicada aos subresultados na segunda fase.

## <a name="parallel_sort"></a><a name="parallel_sort"></a>parallel_sort

Organiza os elementos em um intervalo especificado em uma ordem não decrescente ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Essa função é semanticamente semelhante a que se trata de `std::sort` uma classificação in-loco, instável e em vigor.

```cpp
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

### <a name="parameters"></a>parâmetros

*_Random_iterator*<br/>
O tipo de iterador do intervalo de entrada.

*_Function*<br/>
O tipo de functor de comparação binária.

*_Begin*<br/>
Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser classificado.

*_End*<br/>
Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser classificado.

*_Func*<br/>
Um objeto de função de predicado definido pelo usuário que define o critério de comparação a ser satisfeito por elementos sucessivos na ordenação. Um predicado binário usa dois argumentos e retorna **`true`** quando satisfeito e **`false`** quando não está satisfeito. Essa função de comparador deve impor uma ordenação fraca estrita aos pares de elementos da sequência.

*_Chunk_size*<br/>
O tamanho mínimo de uma parte que será dividida em duas para execução paralela.

### <a name="remarks"></a>Comentários

A primeira sobrecarga usa o comparador binário `std::less` .

O segundo sobrecarregado usa o comparador binário fornecido que deve ter a assinatura `bool _Func(T, T)` onde `T` é o tipo dos elementos no intervalo de entrada.

O algoritmo divide o intervalo de entrada em duas partes e divide sucessivamente cada parte em duas subpartes para execução em paralelo. O argumento opcional `_Chunk_size` pode ser usado para indicar ao algoritmo que ele deve manipular partes do tamanho < em `_Chunk_size` série.

## <a name="parallel_transform"></a><a name="parallel_transform"></a>parallel_transform

Aplica um objeto de função especificado a cada elemento em um intervalo de origem, ou a um par de elementos de dois intervalos de origem, e copia os valores de retorno do objeto de função em um intervalo de destino, em paralelo. Esse funcionamento é semanticamente equivalente a `std::transform` .

```cpp
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

### <a name="parameters"></a>parâmetros

*_Input_iterator1*<br/>
O tipo do primeiro ou somente iterador de entrada.

*_Output_iterator*<br/>
O tipo do iterador de saída.

*_Unary_operator*<br/>
O tipo de functor unário a ser executado em cada elemento no intervalo de entrada.

*_Input_iterator2*<br/>
O tipo do segundo iterador de entrada.

*_Binary_operator*<br/>
O tipo do functor binário executado emparelha em elementos dos dois intervalos de origem.

*_Partitioner*<br/>
*first1*<br/>
Um iterador de entrada que aborda a posição do primeiro elemento no primeiro ou somente o intervalo de origem a ser operado.

*last1*<br/>
Um iterador de entrada que aborda a posição um passado do elemento final no primeiro ou somente o intervalo de origem a ser operado.

*_Result*<br/>
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino.

*_Unary_op*<br/>
Um objeto de função unário definido pelo usuário que é aplicado a cada elemento no intervalo de origem.

*_Part*<br/>
Uma referência ao objeto do particionador. O argumento pode ser um dos **`const`** [auto_partitioner](auto-partitioner-class.md) `&` , **`const`** [static_partitioner](static-partitioner-class.md) `&` , **`const`** [simple_partitioner](simple-partitioner-class.md) `&` ou [affinity_partitioner](affinity-partitioner-class.md) `&` se um objeto [affinity_partitioner](affinity-partitioner-class.md) for usado, a referência deverá ser uma referência não const l-Value, para que o algoritmo possa armazenar o estado para loops futuros a serem reutilizados.

*first2*<br/>
Um iterador de entrada que trata da posição do primeiro elemento no segundo intervalo de origem no qual a operação ocorrerá.

*_Binary_op*<br/>
Um objeto de função binária definido pelo usuário que é aplicado emparelhar, em uma ordem de encaminhamento, aos dois intervalos de origem.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que trata da posição logo após o elemento final no intervalo de destino que está recebendo os elementos de saída transformados pelo objeto de função.

### <a name="remarks"></a>Comentários

[auto_partitioner](auto-partitioner-class.md) será usado para as sobrecargas sem um argumento de particionador explícito.

Para iteradores que não dão suporte ao acesso aleatório, há suporte apenas para [auto_partitioner](auto-partitioner-class.md) .

As sobrecargas que usam o argumento transformam `_Unary_op` o intervalo de entrada no intervalo de saída aplicando o functor unário a cada elemento no intervalo de entrada. `_Unary_op`deve oferecer suporte ao operador de chamada de função com assinatura, `operator()(T)` em que `T` é o tipo de valor do intervalo que está sendo iterado.

As sobrecargas que usam o argumento transformam `_Binary_op` dois intervalos de entrada no intervalo de saída aplicando o functor binário a um elemento do primeiro intervalo de entrada e um elemento do segundo intervalo de entrada. `_Binary_op`deve oferecer suporte ao operador de chamada de função com assinatura `operator()(T, U)` , em que `T` , `U` são tipos de valor dos dois iteradores de entrada.

Para obter mais informações, consulte [algoritmos paralelos](../../../parallel/concrt/parallel-algorithms.md).

## <a name="receive"></a><a name="receive"></a>recebe

Uma implementação de recebimento geral, permitindo que um contexto aguarde dados de exatamente uma fonte e filtre os valores que são aceitos.

```cpp
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

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de carga.

*_Src*<br/>
Um ponteiro ou referência à fonte da qual os dados são esperados.

*_Timeout*<br/>
O tempo máximo para o qual o método deve para os dados, em milissegundos.

*_Filter_proc*<br/>
Uma função de filtro que determina se as mensagens devem ser aceitas.

### <a name="return-value"></a>Valor retornado

Um valor da origem, do tipo de carga.

### <a name="remarks"></a>Comentários

Se o parâmetro `_Timeout` tiver um valor diferente da constante `COOPERATIVE_TIMEOUT_INFINITE` , a exceção [operation_timed_out](operation-timed-out-class.md) será lançada se a quantidade especificada de tempo expirar antes que uma mensagem seja recebida. Se você quiser um tempo limite de comprimento zero, use a função [try_receive](concurrency-namespace-functions.md) , em vez de chamar `receive` com um tempo limite de `0` (zero), pois ele é mais eficiente e não gera exceções em tempos limite.

Para obter mais informações, consulte [funções de passagem de mensagens](../../../parallel/concrt/message-passing-functions.md).

## <a name="run_with_cancellation_token"></a><a name="run_with_cancellation_token"></a>run_with_cancellation_token

Executa um objeto de função imediatamente e de forma síncrona no contexto de um determinado token de cancelamento.

```cpp
template<typename _Function>
void run_with_cancellation_token(
    const _Function& _Func,
    cancellation_token _Ct);
```

### <a name="parameters"></a>parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado.

*_Func*<br/>
O objeto de função que será executado. Este objeto deve dar suporte ao operador de chamada de função com uma assinatura de void (void).

*_Ct*<br/>
O token de cancelamento que controlará o cancelamento implícito do objeto de função. Use `cancellation_token::none()` se quiser que a função seja executada sem qualquer possibilidade de cancelamento implícito de um grupo de tarefas pai ser cancelado.

### <a name="remarks"></a>Comentários

Qualquer ponto de interrupção no objeto de função será disparado quando o `cancellation_token` for cancelado. O token explícito `_Ct` isolará isso `_Func` do cancelamento pai, se o pai tiver um token diferente ou nenhum token.

## <a name="send"></a><a name="send"></a>Enviar

Uma operação de envio síncrona, que aguarda até que o destino aceite ou recuse a mensagem.

```cpp
template <class T>
bool send(_Inout_ ITarget<T>* _Trg, const T& _Data);

template <class T>
bool send(ITarget<T>& _Trg, const T& _Data);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de carga.

*_Trg*<br/>
Um ponteiro ou referência ao destino para o qual os dados são enviados.

*_Data*<br/>
Uma referência aos dados a serem enviados.

### <a name="return-value"></a>Valor retornado

**`true`** se a mensagem foi aceita, **`false`** caso contrário.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [funções de passagem de mensagens](../../../parallel/concrt/message-passing-functions.md).

## <a name="set_ambient_scheduler"></a><a name="set_ambient_scheduler"></a>set_ambient_scheduler

```cpp
inline void set_ambient_scheduler(std::shared_ptr<::Concurrency::scheduler_interface> _Scheduler);
```

### <a name="parameters"></a>parâmetros

*_Scheduler*<br/>
O Agendador de ambiente a ser definido.

## <a name="set_task_execution_resources"></a><a name="set_task_execution_resources"></a>set_task_execution_resources

Restringe os recursos de execução usados pelo Tempo de Execução de Simultaneidade threads de trabalho internos para o conjunto de afinidade especificado.

É válido chamar esse método somente antes de o Gerenciador de recursos ter sido criado ou entre dois tempos de vida do Gerenciador de recursos. Ele pode ser invocado várias vezes, desde que o Gerenciador de recursos não exista no momento da invocação. Depois que um limite de afinidade tiver sido definido, ele permanecerá em vigor até a próxima chamada válida para o `set_task_execution_resources` método.

A máscara de afinidade fornecida não precisa ser um subconjunto da máscara de afinidade de processo. A afinidade de processo será atualizada, se necessário.

```cpp
void __cdecl set_task_execution_resources(
    DWORD_PTR _ProcessAffinityMask);

void __cdecl set_task_execution_resources(
    unsigned short count,
    PGROUP_AFFINITY _PGroupAffinity);
```

### <a name="parameters"></a>parâmetros

*_ProcessAffinityMask*<br/>
A máscara de afinidade à qual o Tempo de Execução de Simultaneidade threads de trabalho deve ser restringido. Use esse método em um sistema com mais de 64 threads de hardware somente se você quiser limitar o Tempo de Execução de Simultaneidade a um subconjunto do grupo de processadores atual. Em geral, você deve usar a versão do método que aceita uma matriz de afinidades de grupo como um parâmetro, para restringir a afinidade em máquinas com mais de 64 threads de hardware.

*contagem*<br/>
O número de `GROUP_AFFINITY` entradas na matriz especificadas pelo parâmetro `_PGroupAffinity` .

*_PGroupAffinity*<br/>
Uma matriz de `GROUP_AFFINITY` entradas.

### <a name="remarks"></a>Comentários

O método lançará uma exceção de [invalid_operation](invalid-operation-class.md) se um Gerenciador de recursos estiver presente no momento em que for invocado, e uma exceção de [invalid_argument](../../../standard-library/invalid-argument-class.md) se a afinidade especificada resultar em um conjunto vazio de recursos.

A versão do método que usa uma matriz de afinidades de grupo como um parâmetro só deve ser usada em sistemas operacionais com a versão Windows 7 ou superior. Caso contrário, uma exceção de [invalid_operation](invalid-operation-class.md) será lançada.

Modificar programaticamente a afinidade do processo após esse método ter sido invocado não fará com que o Gerenciador de recursos reavalie a afinidade à qual ele está restrito. Portanto, todas as alterações na afinidade de processo devem ser feitas antes de chamar esse método.

## <a name="swap"></a><a name="swap"></a>permuta

Troca os elementos de dois objetos `concurrent_vector`.

```cpp
template<typename T, class _Ax>
inline void swap(
    concurrent_vector<T, _Ax>& _A,
    concurrent_vector<T, _Ax>& _B);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*_Ax*<br/>
O tipo de alocador dos vetores simultâneos.

*_A*<br/>
O vetor simultâneo cujos elementos devem ser trocados por aqueles do vetor simultâneo `_B` .

*_B*<br/>
O vetor simultâneo que fornece os elementos a serem trocados ou o vetor cujos elementos devem ser trocados com aqueles do vetor simultâneo `_A` .

### <a name="remarks"></a>Comentários

A função de modelo é um algoritmo especializado na classe de contêiner `concurrent_vector` para executar a função de membro `_A` . [concurrent_vector:: swap](concurrent-vector-class.md#swap)( `_B` ). Essas são instâncias de ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da função de modelo, `template <class T> void swap(T&, T&)` , na classe de algoritmo, funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

Esse método não é seguro para simultaneidade. Você deve garantir que nenhum outro thread esteja executando operações em qualquer um dos vetores simultâneos ao chamar esse método.

## <a name="task_from_exception"></a><a name="task_from_exception"></a>task_from_exception

```cpp
template<typename _TaskType, typename _ExType>
task<_TaskType> task_from_exception(
    _ExType _Exception,
    const task_options& _TaskOptions = task_options());
```

### <a name="parameters"></a>parâmetros

*_TaskType*<br/>

*_ExType*<br/>

*_Exception*<br/>

*_TaskOptions*<br/>

### <a name="return-value"></a>Valor retornado

## <a name="task_from_result"></a><a name="task_from_result"></a>task_from_result

```cpp
template<typename T>
task<T> task_from_result(
    T _Param,
    const task_options& _TaskOptions = task_options());

inline task<bool> task_from_result(ool _Param);

inline task<void> task_from_result(
    const task_options& _TaskOptions = task_options());
```

### <a name="parameters"></a>parâmetros

*T*<br/>

*_Param*<br/>

*_TaskOptions*<br/>

### <a name="return-value"></a>Valor retornado

## <a name="trace_agents_register_name"></a><a name="trace_agents_register_name"></a>Trace_agents_register_name

Associa o nome fornecido ao bloco de mensagens ou ao agente no rastreamento ETW.

```cpp
template <class T>
void Trace_agents_register_name(
    _Inout_ T* _PObject,
    _In_z_ const wchar_t* _Name);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo do objeto. Normalmente, esse é um bloco de mensagem ou um agente.

*_PObject*<br/>
Um ponteiro para o bloco de mensagens ou agente que está sendo nomeado no rastreamento.

*_Name*<br/>
O nome do objeto fornecido.

## <a name="try_receive"></a><a name="try_receive"></a>try_receive

Uma implementação geral de teste de recebimento, permitindo que um contexto Procure dados de exatamente uma fonte e filtre os valores que são aceitos. Se os dados não estiverem prontos, o método retornará **`false`** .

```cpp
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

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de carga

*_Src*<br/>
Um ponteiro ou referência à fonte da qual os dados são esperados.

*_value*<br/>
Uma referência a um local onde o resultado será colocado.

*_Filter_proc*<br/>
Uma função de filtro que determina se as mensagens devem ser aceitas.

### <a name="return-value"></a>Valor retornado

Um **`bool`** valor que indica se uma carga foi colocada ou não `_value` .

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [funções de passagem de mensagens](../../../parallel/concrt/message-passing-functions.md).

## <a name="wait"></a><a name="wait"></a>esperado

Pausa o contexto atual por um período de tempo especificado.

```cpp
void __cdecl wait(unsigned int _Milliseconds);
```

### <a name="parameters"></a>parâmetros

*_Milliseconds*<br/>
O número de milissegundos para o qual o contexto atual deve ser pausado. Se o `_Milliseconds` parâmetro for definido como o valor `0` , o contexto atual deverá gerar a execução para outros contextos executáveis antes de continuar.

### <a name="remarks"></a>Comentários

Se esse método for chamado em um Tempo de Execução de Simultaneidade contexto do Agendador, o Agendador encontrará um contexto diferente para ser executado no recurso subjacente. Como o Agendador é cooperativo por natureza, esse contexto não pode continuar exatamente após o número de milissegundos especificado. Se o Agendador estiver ocupado executando outras tarefas que não geram um rendimento cooperativo para o Agendador, o período de espera poderá ser indefinido.

## <a name="when_all"></a><a name="when_all"></a>when_all

Cria uma tarefa que será concluída com êxito quando todas as tarefas fornecidas como argumentos forem concluídas com êxito.

```cpp
template <typename _Iterator>
auto when_all(
    _Iterator _Begin,
    _Iterator _End,
    const task_options& _TaskOptions = task_options()) ->
    decltype (details::_WhenAllImpl<typename std::iterator_traits<_Iterator>::value_type::result_type,
    _Iterator>::_Perform(_TaskOptions, _Begin,  _End));
```

### <a name="parameters"></a>parâmetros

*_Iterator*<br/>
O tipo do iterador de entrada.

*_Begin*<br/>
A posição do primeiro elemento no intervalo de elementos a ser combinada na tarefa resultante.

*_End*<br/>
A posição do primeiro elemento além do intervalo de elementos a ser combinada na tarefa resultante.

*_TaskOptions*<br/>
O objeto `task_options`.

### <a name="return-value"></a>Valor retornado

Uma tarefa que é concluída com êxito quando todas as tarefas de entrada foram concluídas com êxito. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::vector<T>>`. Se as tarefas de entrada forem do tipo **`void`** , a tarefa de saída também será um `task<void>` .

### <a name="remarks"></a>Comentários

`when_all`é uma função sem bloqueio que produz a `task` como resultado. Ao contrário da [tarefa:: Wait](task-class.md#wait), é seguro chamar essa função em um aplicativo UWP no thread Asta (Application STA).

Se uma das tarefas for cancelada ou lançar uma exceção, a tarefa retornada será concluída antecipadamente, no estado cancelado, e a exceção, se ocorrer, será gerada se você chamar [Task:: Get](task-class.md#get) ou `task::wait` nessa tarefa.

Para obter mais informações, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="when_any"></a><a name="when_any"></a>when_any

Cria uma tarefa que será concluída com êxito quando todas as tarefas fornecidas como argumentos forem concluídas com êxito.

```cpp
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

### <a name="parameters"></a>parâmetros

*_Iterator*<br/>
O tipo do iterador de entrada.

*_Begin*<br/>
A posição do primeiro elemento no intervalo de elementos a ser combinada na tarefa resultante.

*_End*<br/>
A posição do primeiro elemento além do intervalo de elementos a ser combinada na tarefa resultante.

*_TaskOptions*<br/>
*_CancellationToken*<br/>
O token de cancelamento que controla o cancelamento da tarefa retornada. Se você não fornecer um token de cancelamento, a tarefa resultante receberá o token de cancelamento da tarefa que fez com que ela fosse concluída.

### <a name="return-value"></a>Valor retornado

Uma tarefa que foi concluída com êxito quando alguma das tarefas de entrada foi concluída com êxito. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::pair<T, size_t>>>`, em que o primeiro elemento do par é o resultado da conclusão da tarefa e o segundo elemento é o índice da tarefa que foi concluída. Se as tarefas de entrada forem do tipo **`void`** , a saída será a `task<size_t>` , em que o resultado é o índice da tarefa de conclusão.

### <a name="remarks"></a>Comentários

`when_any`é uma função sem bloqueio que produz a `task` como resultado. Ao contrário da [tarefa:: Wait](task-class.md#wait), é seguro chamar essa função em um aplicativo UWP no thread Asta (Application STA).

Para obter mais informações, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
