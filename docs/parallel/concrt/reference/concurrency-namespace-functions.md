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
ms.openlocfilehash: 15b265744640628425502706d69fd98a1c64bda2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374368"
---
# <a name="concurrency-namespace-functions"></a>Funções do namespace de simultaneidade

||||
|-|-|-|
|[Alloc](#alloc)|[Criar Gerenciamento de recursos](#createresourcemanager)|[Desativar tracing](#disabletracing)|
|[EnableTracing](#enabletracing)|[Gratuito](#free)|[ObterExecutionContextId](#getexecutioncontextid)|
|[GetOSVersion](#getosversion)|[GetProcessorCount](#getprocessorcount)|[GetProcessorNodeCount](#getprocessornodecount)|
|[GetSchedulerId](#getschedulerid)|[Trace_agents_register_name](#trace_agents_register_name)|[Asend](#asend)|
|[cancel_current_task](#cancel_current_task)|[Claro](#clear)|[create_async](#create_async)|
|[create_task](#create_task)|[get_ambient_scheduler](#get_ambient_scheduler)|[internal_assign_iterators](#internal_assign_iterators)|
|[interruption_point](#interruption_point)|[is_current_task_group_canceling](#is_current_task_group_canceling)|[make_choice](#make_choice)|
|[make_greedy_join](#make_greedy_join)|[make_join](#make_join)|[make_task](#make_task)|
|[parallel_buffered_sort](#parallel_buffered_sort)|[Parallel_for](#parallel_for)|[Parallel_for_each](#parallel_for_each)|
|[Parallel_invoke](#parallel_invoke)|[parallel_radixsort](#parallel_radixsort)|[parallel_reduce](#parallel_reduce)|
|[parallel_sort](#parallel_sort)|[parallel_transform](#parallel_transform)|[Receber](#receive)|
|[run_with_cancellation_token](#run_with_cancellation_token)|[send](#send)|[set_ambient_scheduler](#set_ambient_scheduler)|
|[set_task_execution_resources](#set_task_execution_resources)|[Trocar](#swap)|[task_from_exception](#task_from_exception)|
|[task_from_result](#task_from_result)|[Try_receive](#try_receive)|[Esperar](#wait)|
|[when_all](#when_all)|[when_any](#when_any)|

## <a name="alloc"></a><a name="alloc"></a>Alloc

Aloca um bloco de memória do tamanho especificado do Subalocador de Cache de Tempo de Execução de Concorrência.

```cpp
void* __cdecl Alloc(size_t _NumBytes);
```

### <a name="parameters"></a>Parâmetros

*_NumBytes*<br/>
O número de bytes de memória para alocar.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a memória recém-alocada.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre quais cenários em sua aplicação podem se beneficiar do uso do Subalocador de Cache, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).

## <a name="asend"></a><a name="asend"></a>Asend

Uma operação de envio assíncrono, que agenda uma tarefa para propagar os dados para o bloco de destino.

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

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem enviados.

*_Trg*<br/>
Um ponteiro ou referência ao destino para o qual os dados são enviados.

*_Data*<br/>
Uma referência aos dados a serem enviados.

### <a name="return-value"></a>Valor retornado

**verdade** se a mensagem foi aceita antes que o método retornasse, **falso** de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Funções de passagem de mensagens](../../../parallel/concrt/message-passing-functions.md).

## <a name="cancel_current_task"></a><a name="cancel_current_task"></a>cancel_current_task

Cancela a tarefa atualmente em execução. Essa função pode ser chamada de dentro do corpo de uma tarefa para interromper a execução da tarefa e fazer com que ela entre no estado `canceled`.

Não é um cenário com suporte para chamar essa função se você não estiver dentro do corpo de uma `task`. Isso resultará em um comportamento indefinido, tal como um travamento ou um desligamento em seu aplicativo.

```cpp
inline __declspec(noreturn) void __cdecl cancel_current_task();
```

## <a name="clear"></a><a name="clear"></a>Claro

Limpa a fila simultânea, destruindo quaisquer elementos enfileirados no momento. Este método não é seguro para a concorrência.

```cpp
template<typename T, class _Ax>
void concurrent_queue<T, _Ax>::clear();
```

### <a name="parameters"></a>Parâmetros

*T*<br/>

*_Ax*<br/>

## <a name="create_async"></a><a name="create_async"></a>create_async

Cria uma construção assíncrona de Windows Runtime com base em um objeto de função ou lambda fornecido pelo usuário. O tipo de retorno de `create_async` é `IAsyncAction^`, `IAsyncActionWithProgress<TProgress>^`, `IAsyncOperation<TResult>^` ou `IAsyncOperationWithProgress<TResult, TProgress>^` com base na assinatura do lambda passada para o método.

```cpp
template<typename _Function>
__declspec(noinline) auto create_async(const _Function& _Func)
    -> decltype(ref new details::_AsyncTaskGeneratorThunk<_Function>(_Func));
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
Digite.

*_Func*<br/>
O objeto de lambda ou função a partir do qual criar uma construção assíncrona de Windows Runtime.

### <a name="return-value"></a>Valor retornado

Uma construção assíncrona representada por um IAsyncAction^, IAsyncActionWithProgress\<\<TProgress>^, IAsyncOperation\<TResult>^, ou um IAsyncOperationWithProgress TResult, TProgress>^. A interface retornada depende de assinatura do lambda passada na função.

### <a name="remarks"></a>Comentários

O tipo de retorno do lambda determina se a construção é uma ação ou uma operação.

Lambdas que retornam void causam a criação de ações. Lambdas que retornam um resultado do tipo `TResult` causam a criação de operações de TResult.

Lambda também pode retornar um `task<TResult>` que encapsula o trabalho assíncrono em si mesmo ou é a continuação de uma cadeia de tarefas que representam o trabalho assíncrono. Nesse caso, o próprio lambda é executado em linha, uma vez que as tarefas são aqueles que são executadas de forma assíncrona e o tipo de retorno do lambda é desencapsulado para produzir a construção assíncrona retornada por `create_async`. Isso implica que uma lambda\<que devolva um vazio de tarefas>\<causará a criação de ações, e uma lambda que retorna uma tarefa TResult> causará a criação de operações de TResult.

O lambda pode usar zero, um ou dois argumentos. Os argumentos válidos são `progress_reporter<TProgress>` e `cancellation_token`, nessa ordem se ambos forem usados. Um lambda sem argumentos causará a criação de uma construção assíncrona sem o recurso de relatório de andamento. Uma lambda que\<leva um progress_reporter `create_async` TProgress> fará com que retorne uma construção `report` assíncrona que relata o progresso do tipo TProgress cada vez que o método do progress_reporter objeto é chamado. Um lambda que usa um cancellation_token pode usar esse token para verificar se há cancelamento ou passá-lo para tarefas que ele cria para que o cancelamento da construção assíncrona cause o cancelamento dessas tarefas.

Se o corpo do objeto lambda ou função retornar\<um resultado (e não uma tarefa TResult>), o lamdba será executado de forma assíncrona dentro do processo MTA no contexto de uma tarefa que o Runtime cria implicitamente para ele. O método `IAsyncInfo::Cancel` causará o cancelamento da tarefa implícita.

Se o corpo do lambda retorna uma tarefa, o lambda será executado em linha e declarando-se o lambda para usar um argumento do tipo `cancellation_token` pode disparar o cancelamento de quaisquer tarefas criadas dentro do lambda passando esse token quando você as cria. Você também pode usar o método `register_callback` no token para fazer com que o Runtime invoque um retorno de chamada ao chamar `IAsyncInfo::Cancel` na operação assíncrona ou na ação produzida.

Esta função só está disponível para aplicativos do Windows Runtime.

## <a name="createresourcemanager"></a><a name="createresourcemanager"></a>Criar Gerenciamento de recursos

Retorna uma interface que representa a instância singleton do Gerenciador de Recursos do Concurrency Runtime. O Gestor de Recursos é responsável por atribuir recursos a agendadores que queiram cooperar entre si.

```cpp
IResourceManager* __cdecl CreateResourceManager();
```

### <a name="return-value"></a>Valor retornado

Uma interface `IResourceManager`.

### <a name="remarks"></a>Comentários

Várias chamadas subseqüentes para este método retornarão a mesma instância do Gerenciador de recursos. Cada chamada para o método incrementa uma contagem de referência no Gerenciador de recursos e deve ser combinada com uma chamada para o [método IResourceManager::Release](iresourcemanager-structure.md) quando seu agendador terminar de se comunicar com o Gerenciador de recursos.

[unsupported_os](unsupported-os-class.md) é lançada se o sistema operacional não for suportado pelo Tempo de Execução de Concorrência.

## <a name="create_task"></a><a name="create_task"></a>create_task

Cria um objeto [de tarefa](task-class.md) PPL. `create_task`pode ser usado em qualquer lugar que você teria usado um construtor de tarefas. Ele é fornecido principalmente por conveniência, porque `auto` permite o uso da palavra-chave ao criar tarefas.

```cpp
template<typename T>
__declspec(noinline) auto create_task(T _Param, const task_options& _TaskOptions = task_options())
    -> task<typename details::_TaskTypeFromParam<T>::T>;

template<typename _ReturnType>
__declspec( noinline) task<_ReturnType> create_task(const task<_ReturnType>& _Task);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de parâmetro a partir do qual a tarefa deve ser construída.

*_ReturnType*<br/>
Digite.

*_Param*<br/>
O parâmetro a partir do qual a tarefa deve ser construída. Isso pode ser um objeto lambda ou função, um `task_completion_event` objeto, um objeto diferente `task` ou uma interface Windows::Foundation::IAsyncInfo se você estiver usando tarefas em seu aplicativo UWP.

*_TaskOptions*<br/>
As opções de tarefas.

*_Task*<br/>
A tarefa a ser criada.

### <a name="return-value"></a>Valor retornado

Uma nova tarefa `T`do tipo, `_Param`que é inferida de .

### <a name="remarks"></a>Comentários

A primeira sobrecarga se comporta como um construtor de tarefas que toma um único parâmetro.

A segunda sobrecarga associa o token de cancelamento fornecido com a tarefa recém-criada. Se você usar essa sobrecarga, você não `task` pode passar em um objeto diferente como o primeiro parâmetro.

O tipo da tarefa retornada é inferido do primeiro parâmetro para a função. Se `_Param` for `task_completion_event<T>`um `task<T>`, a , ou um `T` `task<T>`functor que retorna qualquer `task<T>`tipo ou , o tipo da tarefa criada é .

Em `_Param` um aplicativo UWP, se for do tipo Windows::Foundation::IAsyncOperation\<T>^ ou\<Windows::Foundation::IAsyncOperationWithProgress T,P>^, ou um `task<T>`functor que retorna qualquer um desses tipos, a tarefa criada será do tipo . Se `_Param` for do tipo Windows::Foundation::IAsyncAction^ ou Windows::Foundation::IAsyncActionWithProgress\<P>^, ou um functor que `task<void>`retorna qualquer um desses tipos, a tarefa criada terá tipo .

## <a name="disabletracing"></a><a name="disabletracing"></a>Desativar tracing

Desabilita o rastreamento no Tempo de Execução de Concorrência. Esta função é preterida porque o rastreamento de ETW não é registrado por padrão.

```cpp
__declspec(deprecated("Concurrency::DisableTracing is a deprecated function.")) _CRTIMP HRESULT __cdecl DisableTracing();
```

### <a name="return-value"></a>Valor retornado

Se o rastreamento foi `S_OK` corretamente desativado, é devolvido. Se o rastreamento não foi `E_NOT_STARTED` iniciado anteriormente, é devolvido

## <a name="enabletracing"></a><a name="enabletracing"></a>EnableTracing

Permite o rastreamento no Tempo de Execução de Concorrência. Esta função é preterida porque o rastreamento etw está agora ligado por padrão.

```cpp
__declspec(deprecated("Concurrency::EnableTracing is a deprecated function.")) _CRTIMP HRESULT __cdecl EnableTracing();
```

### <a name="return-value"></a>Valor retornado

Se o rastreamento foi `S_OK` corretamente iniciado, é devolvido; caso contrário, `E_NOT_STARTED` é devolvido.

## <a name="free"></a><a name="free"></a>Livre

Libera um bloco de memória anteriormente `Alloc` alocado pelo método para o Subalocador de Cache de Tempo de Execução de Concorrência.

```cpp
void __cdecl Free(_Pre_maybenull_ _Post_invalid_ void* _PAllocation);
```

### <a name="parameters"></a>Parâmetros

*_PAllocation*<br/>
Um ponteiro para a memória `Alloc` previamente alocado pelo método que deve ser liberado. Se o `_PAllocation` parâmetro estiver definido `NULL`como valor, este método irá ignorá-lo e retornar imediatamente.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre quais cenários em sua aplicação podem se beneficiar do uso do Subalocador de Cache, consulte [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md).

## <a name="get_ambient_scheduler"></a><a name="get_ambient_scheduler"></a>get_ambient_scheduler

```cpp
inline std::shared_ptr<::Concurrency::scheduler_interface> get_ambient_scheduler();
```

### <a name="return-value"></a>Valor retornado

## <a name="getexecutioncontextid"></a><a name="getexecutioncontextid"></a>ObterExecutionContextId

Retorna um identificador único que pode ser atribuído a `IExecutionContext` um contexto de execução que implementa a interface.

```cpp
unsigned int __cdecl GetExecutionContextId();
```

### <a name="return-value"></a>Valor retornado

Um identificador único para um contexto de execução.

### <a name="remarks"></a>Comentários

Use este método para obter um identificador para `IExecutionContext` o seu contexto de execução antes de passar uma interface como parâmetro para qualquer um dos métodos oferecidos pelo Gerenciador de Recursos.

## <a name="getosversion"></a><a name="getosversion"></a>GetOSVersion

Retorna a versão do sistema operacional.

```cpp
IResourceManager::OSVersion __cdecl GetOSVersion();
```

### <a name="return-value"></a>Valor retornado

Um valor enumerado representando o sistema operacional.

### <a name="remarks"></a>Comentários

[unsupported_os](unsupported-os-class.md) é lançada se o sistema operacional não for suportado pelo Tempo de Execução de Concorrência.

## <a name="getprocessorcount"></a><a name="getprocessorcount"></a>GetProcessorCount

Retorna o número de threads de hardware no sistema subjacente.

```cpp
unsigned int __cdecl GetProcessorCount();
```

### <a name="return-value"></a>Valor retornado

O número de threads de hardware.

### <a name="remarks"></a>Comentários

[unsupported_os](unsupported-os-class.md) é lançada se o sistema operacional não for suportado pelo Tempo de Execução de Concorrência.

## <a name="getprocessornodecount"></a><a name="getprocessornodecount"></a>GetProcessorNodeCount

Retorna o número de nós NUMA ou pacotes de processador no sistema subjacente.

```cpp
unsigned int __cdecl GetProcessorNodeCount();
```

### <a name="return-value"></a>Valor retornado

O número de nódulos NUMA ou pacotes de processador.

### <a name="remarks"></a>Comentários

Se o sistema contiver mais nós NUMA do que pacotes de processador, o número de nós NUMA será devolvido, caso contrário, o número de pacotes do processador será devolvido.

[unsupported_os](unsupported-os-class.md) é lançada se o sistema operacional não for suportado pelo Tempo de Execução de Concorrência.

## <a name="getschedulerid"></a><a name="getschedulerid"></a>GetSchedulerId

Retorna um identificador exclusivo que pode ser atribuído a `IScheduler` um agendador que implementa a interface.

```cpp
unsigned int __cdecl GetSchedulerId();
```

### <a name="return-value"></a>Valor retornado

Um identificador único para um agendador.

### <a name="remarks"></a>Comentários

Use este método para obter um identificador para `IScheduler` o seu agendador antes de passar uma interface como parâmetro para qualquer um dos métodos oferecidos pelo Gerenciador de Recursos.

## <a name="internal_assign_iterators"></a><a name="internal_assign_iterators"></a>internal_assign_iterators

```cpp
template<typename T, class _Ax>
template<class _I>
void concurrent_vector<T, _Ax>::internal_assign_iterators(
   _I first,
   _I last);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>

*_Ax*<br/>

*_I*<br/>

*Primeiro*<br/>

*Última*<br/>

## <a name="interruption_point"></a><a name="interruption_point"></a>interruption_point

Cria um ponto de interrupção para cancelamento. Se um cancelamento estiver em andamento no contexto em que essa função é chamada, isso lançará uma exceção interna que aborta a execução do trabalho paralelo em execução atualmente. Se o cancelamento não estiver em andamento, a função não faz nada.

```cpp
inline void interruption_point();
```

### <a name="remarks"></a>Comentários

Você não deve pegar a exceção de cancelamento interno lançada pela `interruption_point()` função. A exceção será capturada e tratada pelo tempo de execução, e capturá-la pode fazer com que seu programa se comporte de forma anormal.

## <a name="is_current_task_group_canceling"></a><a name="is_current_task_group_canceling"></a>is_current_task_group_canceling

Retorna uma indicação de se o grupo de tarefas que está executando inline no contexto atual está no meio de um cancelamento ativo (ou será em breve). Observe que se não houver nenhum grupo de tarefas `false` atualmente executando inline no contexto atual, será devolvido.

```cpp
bool __cdecl is_current_task_group_canceling();
```

### <a name="return-value"></a>Valor retornado

**verdade** se o grupo de tarefas que está sendo executado no momento está cancelando, **falso** de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Cancelamento](../../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md#cancellation).

## <a name="make_choice"></a><a name="make_choice"></a>make_choice

Constrói um `choice` bloco de mensagens a partir de uma fonte de entrada opcional `Scheduler` ou `ScheduleGroup` ou duas ou mais.

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

### <a name="parameters"></a>Parâmetros

*T1*<br/>
O tipo de bloqueio de mensagem da primeira fonte.

*T2*<br/>
O tipo de bloqueio de mensagem da segunda fonte.

*_PScheduler*<br/>
O `Scheduler` objeto dentro do qual `choice` a tarefa de propagação para o bloco de mensagens é agendada.

*_Item1*<br/>
A primeira origem.

*_Item2*<br/>
A segunda origem.

*_Items*<br/>
Fontes adicionais.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto dentro do qual `choice` a tarefa de propagação para o bloco de mensagens é agendada. O `Scheduler` objeto utilizado está implícito pelo grupo de agendamento.

### <a name="return-value"></a>Valor retornado

Um `choice` bloco de mensagens com duas ou mais fontes de entrada.

## <a name="make_greedy_join"></a><a name="make_greedy_join"></a>make_greedy_join

Constrói um `greedy multitype_join` bloco de mensagens a partir de uma fonte de entrada opcional `Scheduler` ou `ScheduleGroup` ou duas ou mais.

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

### <a name="parameters"></a>Parâmetros

*T1*<br/>
O tipo de bloqueio de mensagem da primeira fonte.

*T2*<br/>
O tipo de bloqueio de mensagem da segunda fonte.

*_PScheduler*<br/>
O `Scheduler` objeto dentro do qual `multitype_join` a tarefa de propagação para o bloco de mensagens é agendada.

*_Item1*<br/>
A primeira origem.

*_Item2*<br/>
A segunda origem.

*_Items*<br/>
Fontes adicionais.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto dentro do qual `multitype_join` a tarefa de propagação para o bloco de mensagens é agendada. O `Scheduler` objeto utilizado está implícito pelo grupo de agendamento.

### <a name="return-value"></a>Valor retornado

Um `greedy multitype_join` bloco de mensagens com duas ou mais fontes de entrada.

## <a name="make_join"></a><a name="make_join"></a>make_join

Constrói um `non_greedy multitype_join` bloco de mensagens a partir de uma fonte de entrada opcional `Scheduler` ou `ScheduleGroup` ou duas ou mais.

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

### <a name="parameters"></a>Parâmetros

*T1*<br/>
O tipo de bloqueio de mensagem da primeira fonte.

*T2*<br/>
O tipo de bloqueio de mensagem da segunda fonte.

*_PScheduler*<br/>
O `Scheduler` objeto dentro do qual `multitype_join` a tarefa de propagação para o bloco de mensagens é agendada.

*_Item1*<br/>
A primeira origem.

*_Item2*<br/>
A segunda origem.

*_Items*<br/>
Fontes adicionais.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto dentro do qual `multitype_join` a tarefa de propagação para o bloco de mensagens é agendada. O `Scheduler` objeto utilizado está implícito pelo grupo de agendamento.

### <a name="return-value"></a>Valor retornado

Um `non_greedy multitype_join` bloco de mensagens com duas ou mais fontes de entrada.

## <a name="make_task"></a><a name="make_task"></a>make_task

Um método de `task_handle` fábrica para criar um objeto.

```cpp
template <class _Function>
task_handle<_Function> make_task(const _Function& _Func);
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado `task_handle` para executar o trabalho representado pelo objeto.

*_Func*<br/>
A função que será invocada para executar `task_handle` o trabalho representado pelo objeto. Este pode ser um functor lambda, um ponteiro para uma função ou qualquer objeto `void operator()()`que suporte uma versão do operador de chamada de função com a assinatura .

### <a name="return-value"></a>Valor retornado

Um objeto `task_handle` .

### <a name="remarks"></a>Comentários

Esta função é útil quando `task_handle` você precisa criar um objeto com uma expressão lambda, porque permite que você crie o objeto sem saber o verdadeiro tipo de lambda functor.

## <a name="parallel_buffered_sort"></a><a name="parallel_buffered_sort"></a>parallel_buffered_sort

Organiza os elementos em um intervalo especificado em uma ordem não descendente, ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Esta função é semanticamente `std::sort` semelhante à de que é uma espécie baseada em `O(n)` comparação, instável no lugar, exceto que precisa de espaço adicional, e requer inicialização padrão para os elementos que estão sendo classificados.

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

### <a name="parameters"></a>Parâmetros

*_Random_iterator*<br/>
O tipo de iterador da faixa de entrada.

*Get_allocator*<br/>
O tipo de alocador de memória compatível com c++ Standard Library.

*_Function*<br/>
O tipo do comparador binário.

*_Begin*<br/>
Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser classificado.

*_End*<br/>
Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser classificado.

*_Alloc*<br/>
Um exemplo de um alocador de memória compatível com c++ Standard Library.

*_Func*<br/>
Um objeto de função predicado definido pelo usuário que define o critério de comparação a ser satisfeito por elementos sucessivos na ordem. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido. Essa função de comparador deve impor uma ordenação fraca estrita aos pares de elementos da sequência.

*_Chunk_size*<br/>
O tamanho do mimimum de um pedaço que será dividido em dois para execução paralela.

### <a name="remarks"></a>Comentários

Todas as `n * sizeof(T)` sobrecargas requerem `n` espaço adicional, onde está o `T` número de elementos a serem classificados, e é o tipo de elemento. Na maioria dos casos, parallel_buffered_sort mostrará uma melhora no desempenho em [relação parallel_sort](concurrency-namespace-functions.md), e você deve usá-lo ao longo parallel_sort se você tiver a memória disponível.

Se você não fornecer um comparador `std::less` binário é usado como padrão, o `operator<()`que requer o tipo de elemento para fornecer ao operador .

Se você não fornecer um tipo ou instância de alocador, o `std::allocator<T>` alocador de memória C++ Standard Library será usado para alocar o buffer.

O algoritmo divide o intervalo de entrada em dois pedaços e sucessivamente divide cada pedaço em dois subpedaços para execução em paralelo. O argumento `_Chunk_size` opcional pode ser usado para indicar ao algoritmo que `_Chunk_size` ele deve lidar com pedaços de tamanho < serialmente.

## <a name="parallel_for"></a><a name="parallel_for"></a>Parallel_for

`parallel_for`itera sobre uma gama de índices e executa uma função fornecida pelo usuário em cada iteração, em paralelo.

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

### <a name="parameters"></a>Parâmetros

*_Index_type*<br/>
O tipo de índice utilizado para a iteração.

*_Function*<br/>
O tipo de função que será executada em cada iteração.

*_Partitioner*<br/>
O tipo do particionário que é usado para particionar a faixa fornecida.

*Primeiro*<br/>
O primeiro índice a ser incluído na iteração.

*Última*<br/>
O índice passou do último índice a ser incluído na iteração.

*_Step*<br/>
O valor pelo qual passar ao `first` `last`iterar de para . O passo deve ser positivo. [invalid_argument](../../../standard-library/invalid-argument-class.md) é lançada se o passo for menor que 1.

*_Func*<br/>
A função a ser executada em cada iteração. Isso pode ser uma expressão lambda, um ponteiro de função ou qualquer objeto `void operator()(_Index_type)`que suporte uma versão do operador de chamada de função com a assinatura .

*_Part*<br/>
Uma referência ao objeto particionário. O argumento pode `const`ser `const`um dos [auto_partitioner](auto-partitioner-class.md)`&`, [static_partitioner](static-partitioner-class.md)`&`, `const` [simple_partitioner](simple-partitioner-class.md) `&` ou [affinity_partitioner](affinity-partitioner-class.md) `&` Se um objeto [affinity_partitioner](affinity-partitioner-class.md) for usado, a referência deve ser uma referência de valor l não const, de modo que o algoritmo possa armazenar estado para loops futuros para reutilização.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Algoritmos Paralelos](../../../parallel/concrt/parallel-algorithms.md).

## <a name="parallel_for_each"></a><a name="parallel_for_each"></a>Parallel_for_each

`parallel_for_each`aplica uma função especificada para cada elemento dentro de um intervalo, em paralelo. É semanticamente equivalente à `for_each` função `std` no namespace, exceto que a iteração sobre os elementos é realizada em paralelo, e a ordem de iteração não é especificada. O `_Func` argumento deve apoiar um operador `operator()(T)` de chamada `T` de função do formulário onde o parâmetro é o tipo de item do contêiner que está sendo iterado.

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

### <a name="parameters"></a>Parâmetros

*_Iterator*<br/>
O tipo de iterator que está sendo usado para iterar sobre o recipiente.

*_Function*<br/>
O tipo de função que será aplicada a cada elemento dentro do intervalo.

*_Partitioner*<br/>
*Primeiro*<br/>
Um iterador abordando a posição do primeiro elemento a ser incluído na iteração paralela.

*Última*<br/>
Um iterador abordando a posição um passado o elemento final a ser incluído na iteração paralela.

*_Func*<br/>
Um objeto de função definido pelo usuário que é aplicado a cada elemento no intervalo.

*_Part*<br/>
Uma referência ao objeto particionário. O argumento pode `const`ser `const`um dos [auto_partitioner](auto-partitioner-class.md)`&`, [static_partitioner](static-partitioner-class.md)`&`, `const` [simple_partitioner](simple-partitioner-class.md) `&` ou [affinity_partitioner](affinity-partitioner-class.md) `&` Se um objeto [affinity_partitioner](affinity-partitioner-class.md) for usado, a referência deve ser uma referência de valor l não const, de modo que o algoritmo possa armazenar estado para loops futuros para reutilização.

### <a name="remarks"></a>Comentários

[auto_partitioner](auto-partitioner-class.md) será usado para a sobrecarga sem um particionário explícito.

Para os iterizadores que não suportam acesso aleatório, apenas [auto_partitioner](auto-partitioner-class.md) é suportado.

Para obter mais informações, consulte [Algoritmos Paralelos](../../../parallel/concrt/parallel-algorithms.md).

## <a name="parallel_invoke"></a><a name="parallel_invoke"></a>Parallel_invoke

Executa os objetos de função fornecidos como parâmetros em paralelo, e bloqueia até que eles tenham terminado a execução. Cada objeto de função pode ser uma expressão lambda, um ponteiro para funcionar `void operator()()`ou qualquer objeto que suporte o operador de chamada de função com a assinatura .

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

### <a name="parameters"></a>Parâmetros

*_Function1*<br/>
O tipo do primeiro objeto de função a ser executado em paralelo.

*_Function2*<br/>
O tipo do objeto de segunda função a ser executado em paralelo.

*_Function3*<br/>
O tipo do objeto da terceira função a ser executado em paralelo.

*_Function4*<br/>
O tipo do objeto da quarta função a ser executado em paralelo.

*_Function5*<br/>
O tipo do quinto objeto de função a ser executado em paralelo.

*_Function6*<br/>
O tipo do objeto de sexta função a ser executado em paralelo.

*_Function7*<br/>
O tipo do objeto de sétima função a ser executado em paralelo.

*_Function8*<br/>
O tipo do oitavo objeto de função a ser executado em paralelo.

*_Function9*<br/>
O tipo do nono objeto de função a ser executado em paralelo.

*_Function10*<br/>
O tipo do objeto de décima função a ser executado em paralelo.

*_Func1*<br/>
O primeiro objeto de função a ser executado em paralelo.

*_Func2*<br/>
O objeto de segunda função a ser executado em paralelo.

*_Func3*<br/>
O terceiro objeto de função a ser executado em paralelo.

*_Func4*<br/>
O quarto objeto de função a ser executado em paralelo.

*_Func5*<br/>
O quinto objeto de função a ser executado em paralelo.

*_Func6*<br/>
O sexto objeto de função a ser executado em paralelo.

*_Func7*<br/>
O objeto da sétima função a ser executado em paralelo.

*_Func8*<br/>
O oitavo objeto de função a ser executado em paralelo.

*_Func9*<br/>
O nono objeto de função a ser executado em paralelo.

*_Func10*<br/>
O décimo objeto de função a ser executado em paralelo.

### <a name="remarks"></a>Comentários

Observe que um ou mais dos objetos de função fornecidos como parâmetros podem ser executados inline no contexto de chamada.

Se um ou mais objetos de função passarem como parâmetros para esta função, o tempo de execução `parallel_invoke`selecionará uma dessas exceções de sua escolha e a propagará da chamada para .

Para obter mais informações, consulte [Algoritmos Paralelos](../../../parallel/concrt/parallel-algorithms.md).

## <a name="parallel_radixsort"></a><a name="parallel_radixsort"></a>parallel_radixsort

Organiza elementos em um intervalo especificado em uma ordem não descendente usando um algoritmo de classificação radix. Esta é uma função de classificação estável que requer uma função de projeção que pode projetar elementos a serem classificados em teclas inteiras não assinadas. A inicialização padrão é necessária para os elementos que estão sendo classificados.

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

### <a name="parameters"></a>Parâmetros

*_Random_iterator*<br/>
O tipo de iterador da faixa de entrada.

*Get_allocator*<br/>
O tipo de alocador de memória compatível com c++ Standard Library.

*_Function*<br/>
O tipo de função de projeção.

*_Begin*<br/>
Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser classificado.

*_End*<br/>
Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser classificado.

*_Alloc*<br/>
Um exemplo de um alocador de memória compatível com c++ Standard Library.

*_Proj_func*<br/>
Um objeto de função de projeção definido pelo usuário que converte um elemento em um valor integral.

*_Chunk_size*<br/>
O tamanho do mimimum de um pedaço que será dividido em dois para execução paralela.

### <a name="remarks"></a>Comentários

Todas as `n * sizeof(T)` sobrecargas requerem `n` espaço adicional, onde está o `T` número de elementos a serem classificados, e é o tipo de elemento. Um functor de projeção `I _Proj_func(T)` não-ary com a assinatura é `T` necessário para `I` retornar uma chave quando dado um elemento, onde está o tipo de elemento e é um tipo inteiro não assinado.

Se você não fornecer uma função de projeção, uma função de projeção padrão que simplesmente retorna o elemento é usada para tipos integrais. A função não será compilada se o elemento não for um tipo integral na ausência de uma função de projeção.

Se você não fornecer um tipo ou instância de alocador, o `std::allocator<T>` alocador de memória C++ Standard Library será usado para alocar o buffer.

O algoritmo divide o intervalo de entrada em dois pedaços e sucessivamente divide cada pedaço em dois subpedaços para execução em paralelo. O argumento `_Chunk_size` opcional pode ser usado para indicar ao algoritmo que `_Chunk_size` ele deve lidar com pedaços de tamanho < serialmente.

## <a name="parallel_reduce"></a><a name="parallel_reduce"></a>parallel_reduce

Calcula a soma de todos os elementos em uma faixa especificada calculando sucessivas somas parciais, ou calcula o resultado de resultados parciais sucessivos obtidos da mesma forma usando uma operação binária especificada que não seja a soma, em paralelo. `parallel_reduce`é semanticamente semelhante `std::accumulate`a, exceto que requer que a operação binária seja associativa, e requer um valor de identidade em vez de um valor inicial.

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

### <a name="parameters"></a>Parâmetros

*_Forward_iterator*<br/>
O tipo de iterador do intervalo de entrada.

*_Sym_reduce_fun*<br/>
O tipo de função de redução simétrica. Este deve ser um `_Reduce_type _Sym_fun(_Reduce_type, _Reduce_type)`tipo de função com assinatura, onde _Reduce_type é o mesmo que o tipo de identidade e o tipo de resultado da redução. Para a terceira sobrecarga, isso deve ser `_Range_reduce_fun`consistente com o tipo de saída de .

*_Reduce_type*<br/>
O tipo que a entrada reduzirá, que pode ser diferente do tipo de elemento de entrada. O valor de retorno e valor de identidade terá esse tipo.

*_Range_reduce_fun*<br/>
O tipo de função de redução de faixa. Este deve ser um `_Reduce_type _Range_fun(_Forward_iterator, _Forward_iterator, _Reduce_type)`tipo de função com assinatura, _Reduce_type é o mesmo que o tipo de identidade e o tipo de resultado da redução.

*_Begin*<br/>
Um iterizador de entrada abordando o primeiro elemento no intervalo a ser reduzido.

*_End*<br/>
Um iterador de entrada abordando o elemento que está uma posição além do elemento final no intervalo a ser reduzido.

*_Identity*<br/>
O valor `_Identity` de identidade é do mesmo tipo de `value_type` resultado da redução e também do iterador para a primeira e segunda sobrecargas. Para a terceira sobrecarga, o valor `value_type` de identidade deve ter o mesmo tipo de resultado da redução, mas pode ser diferente do do iterador. Deve ter um valor apropriado, de `_Range_fun`tal forma que o operador de `value_type` redução de faixa, quando aplicado a uma faixa `value_type` de um único elemento de tipo e o valor de identidade, se comporte como um tipo lançado do valor do tipo para o tipo de identidade.

*_Sym_fun*<br/>
A função simétrica que será usada no segundo da redução. Consulte o Comentário para obter mais informações.

*_Range_fun*<br/>
A função que será utilizada na primeira fase da redução. Consulte o Comentário para obter mais informações.

### <a name="return-value"></a>Valor retornado

O resultado da redução.

### <a name="remarks"></a>Comentários

Para realizar uma redução paralela, a função divide o intervalo em pedaços com base no número de trabalhadores disponíveis para o agendador subjacente. A redução ocorre em duas fases, a primeira fase realiza uma redução dentro de cada pedaço, e a segunda fase realiza uma redução entre os resultados parciais de cada pedaço.

A primeira sobrecarga requer que o `value_type` `T`iterador seja o mesmo do tipo de valor de identidade, bem como o tipo de resultado de redução. O elemento tipo T `T T::operator + (T)` deve fornecer ao operador para reduzir os elementos em cada pedaço. O mesmo operador também é usado na segunda fase.

A segunda sobrecarga também requer que `value_type` o iterador seja o mesmo que o tipo de valor de identidade, bem como o tipo de resultado de redução. O operador `_Sym_fun` binário fornecido é utilizado em ambas as fases de redução, com o valor de identidade como valor inicial para a primeira fase.

Para a terceira sobrecarga, o tipo de valor de identidade deve ser o `value_type` mesmo que o tipo de resultado de redução, mas o do iterador pode ser diferente de ambos. A função `_Range_fun` de redução de faixa é usada na primeira fase com `_Sym_reduce_fun` o valor de identidade como valor inicial, e a função binária é aplicada a subresultados na segunda fase.

## <a name="parallel_sort"></a><a name="parallel_sort"></a>parallel_sort

Organiza os elementos em um intervalo especificado em uma ordem não descendente, ou de acordo com um critério de ordenação especificado por um predicado binário, em paralelo. Esta função é semanticamente `std::sort` semelhante a que é uma espécie baseada em comparação, instável, no lugar.

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

### <a name="parameters"></a>Parâmetros

*_Random_iterator*<br/>
O tipo de iterador da faixa de entrada.

*_Function*<br/>
O tipo de functor de comparação binária.

*_Begin*<br/>
Um iterador de acesso aleatório que trata da posição do primeiro elemento no intervalo a ser classificado.

*_End*<br/>
Um iterador de acesso aleatório que trata da posição logo após o elemento final no intervalo a ser classificado.

*_Func*<br/>
Um objeto de função predicado definido pelo usuário que define o critério de comparação a ser satisfeito por elementos sucessivos na ordem. Um predicado binário usa dois argumentos e retorna **true** quando é atendido e **false** quando não é atendido. Essa função de comparador deve impor uma ordenação fraca estrita aos pares de elementos da sequência.

*_Chunk_size*<br/>
O tamanho mínimo de um pedaço que será dividido em dois para execução paralela.

### <a name="remarks"></a>Comentários

A primeira sobrecarga usa o comparador `std::less`binário .

O segundo sobrecarregado usa o comparator binário `bool _Func(T, T)` fornecido `T` que deve ter a assinatura onde está o tipo de elementos na faixa de entrada.

O algoritmo divide o intervalo de entrada em dois pedaços e sucessivamente divide cada pedaço em dois subpedaços para execução em paralelo. O argumento `_Chunk_size` opcional pode ser usado para indicar ao algoritmo que `_Chunk_size` ele deve lidar com pedaços de tamanho < serialmente.

## <a name="parallel_transform"></a><a name="parallel_transform"></a>parallel_transform

Aplica um objeto de função especificado a cada elemento em um intervalo de origem ou a um par de elementos de duas faixas de origem e copia os valores de retorno do objeto de função em uma faixa de destino, em paralelo. Este funcional é semanticamente `std::transform`equivalente a .

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

### <a name="parameters"></a>Parâmetros

*_Input_iterator1*<br/>
O tipo do primeiro ou único ativador de entrada.

*_Output_iterator*<br/>
O tipo do ativador de saída.

*_Unary_operator*<br/>
O tipo de functor unary a ser executado em cada elemento na faixa de entrada.

*_Input_iterator2*<br/>
O tipo de segundo ativador de entrada.

*_Binary_operator*<br/>
O tipo de functor binário executado em pares em elementos das duas faixas de origem.

*_Partitioner*<br/>
*primeiro1*<br/>
Um iterizador de entrada abordando a posição do primeiro elemento na primeira ou única faixa de origem a ser operada.

*último1*<br/>
Um iterizador de entrada abordando a posição um após o elemento final na primeira ou única faixa de origem a ser operada.

*_Result*<br/>
Um iterador de saída que trata da posição do primeiro elemento no intervalo de destino.

*_Unary_op*<br/>
Um objeto de função não-ary definido pelo usuário que é aplicado a cada elemento na faixa de origem.

*_Part*<br/>
Uma referência ao objeto particionário. O argumento pode `const`ser `const`um dos [auto_partitioner](auto-partitioner-class.md)`&`, [static_partitioner](static-partitioner-class.md)`&`, `const` [simple_partitioner](simple-partitioner-class.md) `&` ou [affinity_partitioner](affinity-partitioner-class.md) `&` Se um objeto [affinity_partitioner](affinity-partitioner-class.md) for usado, a referência deve ser uma referência de valor l não const, de modo que o algoritmo possa armazenar estado para loops futuros para reutilização.

*primeiro2*<br/>
Um iterador de entrada que trata da posição do primeiro elemento no segundo intervalo de origem no qual a operação ocorrerá.

*_Binary_op*<br/>
Um objeto de função binária definido pelo usuário que é aplicado em sentido par, em uma ordem avançada, às duas faixas de origem.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que trata da posição logo após o elemento final no intervalo de destino que está recebendo os elementos de saída transformados pelo objeto de função.

### <a name="remarks"></a>Comentários

[auto_partitioner](auto-partitioner-class.md) serão usados para as sobrecargas sem um argumento particionário explícito.

Para os iterizadores que não suportam acesso aleatório, apenas [auto_partitioner](auto-partitioner-class.md) é suportado.

As sobrecargas que `_Unary_op` levam o argumento transformam o intervalo de entrada na faixa de saída aplicando o functor unary a cada elemento na faixa de entrada. `_Unary_op`deve suportar o operador `operator()(T)` de `T` chamada de função com assinatura onde está o tipo de valor da faixa que está sendo iterado mais.

As sobrecargas que `_Binary_op` levam o argumento transformam duas faixas de entrada na faixa de saída aplicando o functor binário a um elemento da primeira faixa de entrada e um elemento da segunda faixa de entrada. `_Binary_op`deve suportar o operador `operator()(T, U)` de `T` `U` chamada de função com assinatura onde, são tipos de valor dos dois iteradores de entrada.

Para obter mais informações, consulte [Algoritmos Paralelos](../../../parallel/concrt/parallel-algorithms.md).

## <a name="receive"></a><a name="receive"></a>Receber

Uma implementação geral recebe, permitindo que um contexto aguarde dados de exatamente uma fonte e filtre os valores que são aceitos.

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

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de carga.

*_Src*<br/>
Um ponteiro ou referência à fonte a partir da qual os dados são esperados.

*_Timeout*<br/>
O tempo máximo para o qual o método deve para os dados, em milissegundos.

*_Filter_proc*<br/>
Uma função de filtro que determina se as mensagens devem ser aceitas.

### <a name="return-value"></a>Valor retornado

Um valor da fonte do tipo de carga.

### <a name="remarks"></a>Comentários

Se o `_Timeout` parâmetro tiver um valor `COOPERATIVE_TIMEOUT_INFINITE`diferente da constante, a exceção [operation_timed_out](operation-timed-out-class.md) será lançada se o tempo especificado expirar antes de uma mensagem ser recebida. Se você quiser um intervalo de comprimento zero, você deve `receive` usar a `0` função [try_receive,](concurrency-namespace-functions.md) em vez de chamar com um tempo de (zero), pois é mais eficiente e não lança exceções nos intervalos de tempo.

Para obter mais informações, consulte [Funções de passagem de mensagens](../../../parallel/concrt/message-passing-functions.md).

## <a name="run_with_cancellation_token"></a><a name="run_with_cancellation_token"></a>run_with_cancellation_token

Executa um objeto de função imediatamente e sincronizadamente no contexto de um determinado token de cancelamento.

```cpp
template<typename _Function>
void run_with_cancellation_token(
    const _Function& _Func,
    cancellation_token _Ct);
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado.

*_Func*<br/>
O objeto de função que será executado. Este objeto deve suportar o operador de chamada de função com uma assinatura de vazio (vazio).

*_Ct*<br/>
O token de cancelamento que controlará o cancelamento implícito do objeto de função. Use `cancellation_token::none()` se quiser que a função seja executada sem qualquer possibilidade de cancelamento implícito de um grupo de tarefas pai sendo cancelado.

### <a name="remarks"></a>Comentários

Quaisquer pontos de interrupção no objeto de `cancellation_token` função serão acionados quando o for cancelado. O token `_Ct` explícito `_Func` isolará isso do cancelamento dos pais se o pai tiver um token diferente ou nenhum token.

## <a name="send"></a><a name="send"></a>Enviar

Uma operação de envio síncrono, que espera até que o alvo aceite ou recuse a mensagem.

```cpp
template <class T>
bool send(_Inout_ ITarget<T>* _Trg, const T& _Data);

template <class T>
bool send(ITarget<T>& _Trg, const T& _Data);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de carga.

*_Trg*<br/>
Um ponteiro ou referência ao destino para o qual os dados são enviados.

*_Data*<br/>
Uma referência aos dados a serem enviados.

### <a name="return-value"></a>Valor retornado

**verdade** se a mensagem foi aceita, **falsa** de outra forma.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Funções de passagem de mensagens](../../../parallel/concrt/message-passing-functions.md).

## <a name="set_ambient_scheduler"></a><a name="set_ambient_scheduler"></a>set_ambient_scheduler

```cpp
inline void set_ambient_scheduler(std::shared_ptr<::Concurrency::scheduler_interface> _Scheduler);
```

### <a name="parameters"></a>Parâmetros

*_Scheduler*<br/>
O agendador ambiente para definir.

## <a name="set_task_execution_resources"></a><a name="set_task_execution_resources"></a>set_task_execution_resources

Restringe os recursos de execução usados pelos segmentos internos do trabalhador interno Do trabalhador do Concurrency Runtime ao conjunto de afinidade especificado.

É válido chamar esse método somente antes de o Gerenciador de recursos ter sido criado ou entre duas vidas do Gerenciador de recursos. Ele pode ser invocado várias vezes desde que o Gerenciador de recursos não exista no momento da invocação. Depois que um limite de afinidade foi definido, ele `set_task_execution_resources` permanece em vigor até a próxima chamada válida para o método.

A máscara de afinidade fornecida não precisa ser um subconjunto da máscara de afinidade do processo. A afinidade do processo será atualizada se necessário.

```cpp
void __cdecl set_task_execution_resources(
    DWORD_PTR _ProcessAffinityMask);

void __cdecl set_task_execution_resources(
    unsigned short count,
    PGROUP_AFFINITY _PGroupAffinity);
```

### <a name="parameters"></a>Parâmetros

*_ProcessAffinityMask*<br/>
A máscara de afinidade a que os segmentos de trabalhador do Concurrency Runtime devem ser restritas. Use este método em um sistema com mais de 64 threads de hardware somente se você quiser limitar o Tempo de Execução de Concorrência a um subconjunto do grupo de processadores atual. Em geral, você deve usar a versão do método que aceita uma matriz de afinidades de grupo como parâmetro, para restringir a afinidade em máquinas com mais de 64 threads de hardware.

*contagem*<br/>
O número `GROUP_AFFINITY` de entradas na matriz especificada pelo parâmetro `_PGroupAffinity`.

*_PGroupAffinity*<br/>
Uma série `GROUP_AFFINITY` de entradas.

### <a name="remarks"></a>Comentários

O método lançará uma exceção [invalid_operation](invalid-operation-class.md) se um Gerenciador de Recursos estiver presente no momento em que for invocado, e uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) se a afinidade especificada resultar em um conjunto vazio de recursos.

A versão do método que toma uma matriz de afinidades de grupo como parâmetro só deve ser usada em sistemas operacionais com a versão Windows 7 ou superior. Caso contrário, uma exceção [invalid_operation](invalid-operation-class.md) é lançada.

Modificar programáticamente a afinidade do processo após a invocação desse método não fará com que o Gerenciador de Recursos reavalie a afinidade a que está restrito. Portanto, todas as mudanças na afinidade de processo devem ser feitas antes de chamar esse método.

## <a name="swap"></a><a name="swap"></a>Trocar

Troca os elementos de dois objetos `concurrent_vector`.

```cpp
template<typename T, class _Ax>
inline void swap(
    concurrent_vector<T, _Ax>& _A,
    concurrent_vector<T, _Ax>& _B);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*_Ax*<br/>
O tipo alocador dos vetores simultâneos.

*_A*<br/>
O vetor simultâneo cujos elementos `_B`devem ser trocados com os do vetor simultâneo .

*_B*<br/>
O vetor simultâneo que fornece os elementos a serem trocados, `_A`ou o vetor cujos elementos devem ser trocados com os do vetor simultâneo .

### <a name="remarks"></a>Comentários

A função modelo é um algoritmo `concurrent_vector` especializado na classe `_A`de contêineres para executar a função de membro. [concurrent_vector::swap](concurrent-vector-class.md#swap) `_B`( ). Essas são instâncias de ordenação parcial de modelos de função pelo compilador. Quando as funções de modelo são sobrecarregadas de forma que a correspondência do modelo com a chamada de função não é exclusiva, o compilador seleciona a versão mais especializada do modelo de função. A versão geral da `template <class T> void swap(T&, T&)`função modelo, na classe algoritmo funciona por atribuição e é uma operação lenta. A versão especializada em cada contêiner é muito mais rápida, uma vez que ela pode funcionar com a representação interna da classe de contêiner.

Este método não é seguro para a concorrência. Você deve garantir que nenhum outro segmento esteja executando operações em qualquer um dos vetores simultâneos quando você chamar este método.

## <a name="task_from_exception"></a><a name="task_from_exception"></a>task_from_exception

```cpp
template<typename _TaskType, typename _ExType>
task<_TaskType> task_from_exception(
    _ExType _Exception,
    const task_options& _TaskOptions = task_options());
```

### <a name="parameters"></a>Parâmetros

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

### <a name="parameters"></a>Parâmetros

*T*<br/>

*_Param*<br/>

*_TaskOptions*<br/>

### <a name="return-value"></a>Valor retornado

## <a name="trace_agents_register_name"></a><a name="trace_agents_register_name"></a>Trace_agents_register_name

Associa o nome dado ao bloco de mensagens ou agente no rastreamento do ETW.

```cpp
template <class T>
void Trace_agents_register_name(
    _Inout_ T* _PObject,
    _In_z_ const wchar_t* _Name);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do objeto. Este é tipicamente um bloco de mensagens ou um agente.

*_PObject*<br/>
Um ponteiro para o bloco de mensagens ou agente que está sendo nomeado no rastreamento.

*_Name*<br/>
O nome do objeto dado.

## <a name="try_receive"></a><a name="try_receive"></a>Try_receive

Uma implementação geral de try-receive, permitindo que um contexto procure dados de exatamente uma fonte e filtre os valores que são aceitos. Se os dados não estão prontos, o método retornará **falso**.

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

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de carga

*_Src*<br/>
Um ponteiro ou referência à fonte a partir da qual os dados são esperados.

*_value*<br/>
Uma referência a um local onde o resultado será colocado.

*_Filter_proc*<br/>
Uma função de filtro que determina se as mensagens devem ser aceitas.

### <a name="return-value"></a>Valor retornado

Um `bool` valor indicando se uma carga `_value`foi ou não colocada em .

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Funções de passagem de mensagens](../../../parallel/concrt/message-passing-functions.md).

## <a name="wait"></a><a name="wait"></a>Esperar

Pausa o contexto atual por um período de tempo especificado.

```cpp
void __cdecl wait(unsigned int _Milliseconds);
```

### <a name="parameters"></a>Parâmetros

*_Milliseconds*<br/>
O número de milissegundos para o contexto atual deve ser pausado. Se `_Milliseconds` o parâmetro for definido `0`como valor, o contexto atual deve render a execução a outros contextos executáveis antes de continuar.

### <a name="remarks"></a>Comentários

Se esse método for chamado em um contexto de agendador de tempo de execução de concorrência, o agendador encontrará um contexto diferente para executar no recurso subjacente. Como o agendador é cooperativo por natureza, esse contexto não pode ser retomado exatamente após o número de milissegundos especificados. Se o agendador estiver ocupado executando outras tarefas que não cedem cooperativamente ao agendador, o período de espera pode ser indefinido.

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

### <a name="parameters"></a>Parâmetros

*_Iterator*<br/>
O tipo do iterador de entrada.

*_Begin*<br/>
A posição do primeiro elemento no intervalo de elementos a ser combinada na tarefa resultante.

*_End*<br/>
A posição do primeiro elemento além do intervalo de elementos a ser combinada na tarefa resultante.

*_TaskOptions*<br/>
O objeto `task_options`.

### <a name="return-value"></a>Valor retornado

Uma tarefa que é concluída com sucesso quando todas as tarefas de entrada forem concluídas com sucesso. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::vector<T>>`. Se as tarefas de entrada forem do tipo `void`, a tarefa de saída também será um `task<void>`.

### <a name="remarks"></a>Comentários

`when_all`é uma função de não `task` bloqueio que produz um como resultado. Ao contrário [da tarefa::wait](task-class.md#wait), é seguro chamar essa função em um aplicativo UWP no segmento ASTA (Application STA).

Se uma das tarefas for cancelada ou for uma exceção, a tarefa retornada será concluída mais cedo, no estado cancelado, `task::wait` e a exceção, se ocorrer, será lançada se você chamar [tarefa::obter](task-class.md#get) ou nessa tarefa.

Para obter mais informações, consulte [O Paralelismo da Tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

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

### <a name="parameters"></a>Parâmetros

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

Uma tarefa que foi concluída com êxito quando alguma das tarefas de entrada foi concluída com êxito. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::pair<T, size_t>>>`, em que o primeiro elemento do par é o resultado da conclusão da tarefa e o segundo elemento é o índice da tarefa que foi concluída. Se as tarefas de entrada forem do tipo `void`, a saída será um `task<size_t>`, em que o resultado é o índice de conclusão da tarefa.

### <a name="remarks"></a>Comentários

`when_any`é uma função de não `task` bloqueio que produz um como resultado. Ao contrário [da tarefa::wait](task-class.md#wait), é seguro chamar essa função em um aplicativo UWP no segmento ASTA (Application STA).

Para obter mais informações, consulte [O Paralelismo da Tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)
