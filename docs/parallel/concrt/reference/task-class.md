---
title: Classe task (Runtime de Simultaneidade)
ms.date: 07/30/2019
f1_keywords:
- task
- PPLTASKS/concurrency::task
- PPLTASKS/concurrency::task::task
- PPLTASKS/concurrency::task::get
- PPLTASKS/concurrency::task::is_apartment_aware
- PPLTASKS/concurrency::task::is_done
- PPLTASKS/concurrency::task::scheduler
- PPLTASKS/concurrency::task::then
- PPLTASKS/concurrency::task::wait
helpviewer_keywords:
- task class
ms.assetid: cdc3a8c0-5cbe-45a0-b5d5-e9f81d94df1a
ms.openlocfilehash: 6a063f0bba9482824817e4efe21ae5b7bf3c0995
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219528"
---
# <a name="task-class-concurrency-runtime"></a>Classe task (Runtime de Simultaneidade)

A classe `task` da Biblioteca de Padrões Paralelos (PPL). Um `task` objeto representa o trabalho que pode ser executado de forma assíncrona e simultânea com outras tarefas e trabalho paralelo produzido por algoritmos paralelos no tempo de execução de simultaneidade. Produz um resultado de tipo `_ResultType` após uma conclusão bem-sucedida. Tarefas do tipo `task<void>` não produzem resultados. Uma tarefa pode ser aguardada e cancelada independentemente de outras tarefas. Ele também pode ser composto por outras tarefas usando os padrões de continuação ( `then` ) e Join ( `when_all` ) e Choice ( `when_any` ). Quando um objeto Task é atribuído a uma nova variável, o comportamento é o de `std::shared_ptr` ; em outras palavras, os dois objetos representam a mesma tarefa subjacente.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
class task<void>;

template<typename _ResultType>
class task;
```

### <a name="parameters"></a>parâmetros

*_ResultType*<br/>
O tipo do resultado que a tarefa produz.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`result_type`|O tipo do resultado que um objeto desta classe produz.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[agenda](#ctor)|Sobrecarregado. Constrói um objeto `task`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get](#get)|Sobrecarregado. Retorna o resultado produzido por essa tarefa. Se a tarefa não estiver em um estado terminal, uma chamada para `get` irá aguardar a conclusão da tarefa. Esse método não retorna um valor quando chamado em uma tarefa com um `result_type` de **`void`** .|
|[is_apartment_aware](#is_apartment_aware)|Determina se a tarefa desvincula uma interface de Windows Runtime `IAsyncInfo` ou se é descendente de tal tarefa.|
|[is_done](#is_done)|Determina se a tarefa foi concluída.|
|[Agendador](#scheduler)|Retorna o agendador para essa tarefa|
|[Clique](#then)|Sobrecarregado. Adiciona uma tarefa de continuação para essa tarefa.|
|[esperado](#wait)|Aguarda que essa tarefa alcance um estado terminal. É possível para `wait` executar a tarefa em linha, se todas as dependências de tarefas forem atendidas, e ela ainda não tiver sido escolhida para execução por um trabalho em segundo plano.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador! =](#operator_neq)|Sobrecarregado. Determina se dois objetos `task` representam tarefas internas diferentes.|
|[operador =](#operator_eq)|Sobrecarregado. Substitui o conteúdo de um objeto `task` por outro.|
|[operador = =](#operator_eq_eq)|Sobrecarregado. Determina se dois objetos `task` representam a mesma tarefa interna.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`task`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppltasks. h

**Namespace:** simultaneidade

## <a name="get"></a><a name="get"></a>Obter

Retorna o resultado produzido por essa tarefa. Se a tarefa não estiver em um estado terminal, uma chamada para `get` irá aguardar a conclusão da tarefa. Esse método não retorna um valor quando chamado em uma tarefa com um `result_type` de **`void`** .

```cpp
_ResultType get() const;

void get() const;
```

### <a name="return-value"></a>Valor retornado

O resultado da tarefa.

### <a name="remarks"></a>Comentários

Se a tarefa for cancelada, uma chamada para gerará `get` uma exceção de [task_canceled](task-canceled-class.md) . Se a tarefa encontrou uma exceção diferente ou se uma exceção foi propagada a ela de uma tarefa Antecedent, uma chamada para gerará `get` essa exceção.

> [!IMPORTANT]
> Em um aplicativo Plataforma Universal do Windows (UWP), não chame [Concurrency:: Task:: Wait](#wait) ou `get` ( `wait` calls `get` ) no código que é executado no thread da interface do usuário. Caso contrário, o tempo de execução lançará [Concurrency:: invalid_operation](invalid-operation-class.md) porque esses métodos bloqueiam o thread atual e podem fazer com que o aplicativo fique sem resposta. No entanto, você pode chamar o `get` método para receber o resultado da tarefa antecedente em uma continuação baseada em tarefa, pois o resultado está imediatamente disponível.

## <a name="is_apartment_aware"></a><a name="is_apartment_aware"></a>is_apartment_aware

Determina se a tarefa desvincula uma interface de Windows Runtime `IAsyncInfo` ou se é descendente de tal tarefa.

```cpp
bool is_apartment_aware() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** se a tarefa desencapsular uma `IAsyncInfo` interface ou estiver descendente dessa tarefa, **`false`** caso contrário.

## <a name="taskis_done-method-concurrency-runtime"></a><a name="is_done"></a>Método Task:: is_done (Tempo de Execução de Simultaneidade)

Determina se a tarefa foi concluída.

```cpp
bool is_done() const;
```

### <a name="return-value"></a>Valor retornado

True se a tarefa for concluída; caso contrário, false.

### <a name="remarks"></a>Comentários

A função retornará true se a tarefa for concluída ou cancelada (com ou sem a exceção do usuário).

## <a name="operator"></a><a name="operator_neq"></a>operador! =

Determina se dois objetos `task` representam tarefas internas diferentes.

```cpp
bool operator!= (const task<_ResultType>& _Rhs) const;

bool operator!= (const task<void>& _Rhs) const;
```

### <a name="parameters"></a>parâmetros

*_Rhs*<br/>
A tarefa a ser comparada.

### <a name="return-value"></a>Valor retornado

**`true`** Se os objetos se referirem a diferentes tarefas subjacentes e, **`false`** caso contrário,.

## <a name="operator"></a><a name="operator_eq"></a>operador =

Substitui o conteúdo de um objeto `task` por outro.

```cpp
task& operator= (const task& _Other);

task& operator= (task&& _Other);
```

### <a name="parameters"></a>parâmetros

*_Other*<br/>
O objeto `task` de origem.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Como `task` se comporta como um ponteiro inteligente, após uma atribuição de cópia, esses `task` objetos representam a mesma tarefa real que o `_Other` faz.

## <a name="operator"></a><a name="operator_eq_eq"></a>operador = =

Determina se dois objetos `task` representam a mesma tarefa interna.

```cpp
bool operator== (const task<_ResultType>& _Rhs) const;

bool operator== (const task<void>& _Rhs) const;
```

### <a name="parameters"></a>parâmetros

*_Rhs*<br/>
A tarefa a ser comparada.

### <a name="return-value"></a>Valor retornado

**`true`** Se os objetos se referirem à mesma tarefa subjacente e, **`false`** caso contrário,.

## <a name="taskscheduler-method-concurrency-runtime"></a><a name="scheduler"></a>tarefa:: método do Agendador (Tempo de Execução de Simultaneidade)

Retorna o agendador para essa tarefa

```cpp
scheduler_ptr scheduler() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o Agendador

## <a name="task"></a>Tarefa <a name="ctor"></a>

Constrói um objeto `task`.

```cpp
task();

template<typename T>
__declspec(
    noinline) explicit task(T _Param);

template<typename T>
__declspec(
    noinline) explicit task(T _Param, const task_options& _TaskOptions);

task(
    const task& _Other);

task(
    task&& _Other);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo do parâmetro do qual a tarefa deve ser construída.

*_Param*<br/>
O parâmetro do qual a tarefa deve ser construída. Isso pode ser um lambda, um objeto Function, um `task_completion_event<result_type>` objeto ou um Windows:: Foundation:: IAsyncInfo se você estiver usando tarefas em seu aplicativo Windows Runtime. O objeto lambda ou de função deve ser um tipo equivalente a `std::function<X(void)>` , em que X pode ser uma variável do tipo `result_type` , `task<result_type>` ou um Windows:: Foundation:: IAsyncInfo em aplicativos Windows Runtime.

*_TaskOptions*<br/>
As opções de tarefa incluem token de cancelamento, Agendador, etc.

*_Other*<br/>
O objeto `task` de origem.

### <a name="remarks"></a>Comentários

O construtor padrão para um `task` está presente apenas para permitir que as tarefas sejam usadas em contêineres. Uma tarefa construída padrão não pode ser usada até que você atribua uma tarefa válida a ela. Métodos como `get` `wait` ou `then` lançarão uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) quando chamados em uma tarefa construída padrão.

Uma tarefa criada a partir de um `task_completion_event` será concluída (e terá suas continuaçãos agendadas) quando o evento de conclusão de tarefa for definido.

A versão do construtor que usa um token de cancelamento cria uma tarefa que pode ser cancelada usando o `cancellation_token_source` token obtido do. As tarefas criadas sem um token de cancelamento não podem ser canceladas.

As tarefas criadas a partir de uma `Windows::Foundation::IAsyncInfo` interface ou de um lambda que retorna uma `IAsyncInfo` interface atingem o estado do terminal quando a operação ou ação assíncrona Windows Runtimeda em anexo é concluída. Da mesma forma, as tarefas criadas a partir de um lambda que retorna um `task<result_type>` alcance o estado do terminal quando a tarefa interna atinge seu estado de terminal e não quando o lambda retorna.

`task`comporta-se como um ponteiro inteligente e é seguro de passar por valor. Ele pode ser acessado por vários threads sem a necessidade de bloqueios.

As sobrecargas de construtor que usam a interface Windows:: Foundation:: IAsyncInfo ou um lambda retornando essa interface, só estão disponíveis para aplicativos Windows Runtime.

Para obter mais informações, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="then"></a><a name="then"></a>Clique

Adiciona uma tarefa de continuação para essa tarefa.

```cpp
template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func) const -> typename details::_ContinuationTypeTraits<_Function,
    _ResultType>::_TaskOfType;

template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func,
    const task_options& _TaskOptions) const -> typename details::_ContinuationTypeTraits<_Function,
    _ResultType>::_TaskOfType;

template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func,
    cancellation_token _CancellationToken,
    task_continuation_context _ContinuationContext) const -> typename details::_ContinuationTypeTraits<_Function,
    _ResultType>::_TaskOfType;

template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func,
    const task_options& _TaskOptions = task_options()) const -> typename details::_ContinuationTypeTraits<_Function,
    void>::_TaskOfType;

template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func,
    cancellation_token _CancellationToken,
    task_continuation_context _ContinuationContext) const -> typename details::_ContinuationTypeTraits<_Function,
    void>::_TaskOfType;
```

### <a name="parameters"></a>parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado por essa tarefa.

*_Func*<br/>
A função de continuação a ser executada quando esta tarefa for concluída. Essa função de continuação deve usar como entrada uma variável de `result_type` ou `task<result_type>` , em que `result_type` é o tipo do resultado que essa tarefa produz.

*_TaskOptions*<br/>
As opções de tarefa incluem token de cancelamento, Agendador e contexto de continuação. Por padrão, as três opções anteriores são herdadas da tarefa antecedente

*_CancellationToken*<br/>
O token de cancelamento a ser associado à tarefa de continuação. Uma tarefa de continuação que é criada sem um token de cancelamento herdará o token de sua tarefa antecedente.

*_ContinuationContext*<br/>
Uma variável que especifica onde a continuação deve ser executada. Essa variável só é útil quando usada em um aplicativo UWP. Para obter mais informações, consulte [task_continuation_context](task-continuation-context-class.md)

### <a name="return-value"></a>Valor retornado

A tarefa de continuação recém-criada. O tipo de resultado da tarefa retornada é determinado pelo que `_Func` retorna.

### <a name="remarks"></a>Comentários

As sobrecargas de `then` que usam lambda ou functor que retornam uma interface Windows:: Foundation:: IAsyncInfo, estão disponíveis somente para aplicativos Windows Runtime.

Para obter mais informações sobre como usar as continuações de tarefa para compor trabalho assíncrono, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="wait"></a><a name="wait"></a>esperado

Aguarda que essa tarefa alcance um estado terminal. É possível para `wait` executar a tarefa em linha, se todas as dependências de tarefas forem atendidas, e ela ainda não tiver sido escolhida para execução por um trabalho em segundo plano.

```cpp
task_status wait() const;
```

### <a name="return-value"></a>Valor retornado

Um `task_status` valor que pode ser `completed` ou `canceled` . Se a tarefa encontrou uma exceção durante a execução ou se uma exceção foi propagada a ela de uma tarefa Antecedent, o `wait` gerará essa exceção.

### <a name="remarks"></a>Comentários

> [!IMPORTANT]
> Em um aplicativo Plataforma Universal do Windows (UWP), não chame `wait` no código que é executado no thread da interface do usuário. Caso contrário, o tempo de execução lançará [Concurrency:: invalid_operation](invalid-operation-class.md) porque esse método bloqueia o thread atual e pode fazer com que o aplicativo fique sem resposta. No entanto, você pode chamar o método [Concurrency:: Task:: Get](#get) para receber o resultado da tarefa Antecedent em uma continuação baseada em tarefa.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
