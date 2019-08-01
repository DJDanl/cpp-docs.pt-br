---
title: Classe task (Tempo de Execução de Simultaneidade)
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
ms.openlocfilehash: e0f876b3c0971e70763f36622fb72a3dea671461
ms.sourcegitcommit: 725e86dabe2901175ecc63261c3bf05802dddff4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/31/2019
ms.locfileid: "68682527"
---
# <a name="task-class-concurrency-runtime"></a>Classe task (Tempo de Execução de Simultaneidade)

A classe `task` da Biblioteca de Padrões Paralelos (PPL). Um `task` objeto representa o trabalho que pode ser executado de forma assíncrona e simultânea com outras tarefas e trabalho paralelo produzido por algoritmos paralelos no tempo de execução de simultaneidade. Produz um resultado de tipo `_ResultType` após uma conclusão bem-sucedida. Tarefas do tipo `task<void>` não produzem resultados. Uma tarefa pode ser aguardada e cancelada independentemente de outras tarefas. Ele também pode ser composto por outras tarefas usando os padrões de `then`continuação () e Join `when_all`() e Choice `when_any`(). Quando um objeto Task é atribuído a uma nova variável, o comportamento é o de `std::shared_ptr`; em outras palavras, os dois objetos representam a mesma tarefa subjacente.

## <a name="syntax"></a>Sintaxe

```
template <>
class task<void>;

template<typename _ResultType>
class task;
```

#### <a name="parameters"></a>Parâmetros

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
|[task](#ctor)|Sobrecarregado. Constrói um objeto `task`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get](#get)|Sobrecarregado. Retorna o resultado produzido por essa tarefa. Se a tarefa não estiver em um estado terminal, uma chamada para `get` irá aguardar a conclusão da tarefa. Este método não retorna um valor quando chamado em uma tarefa com um `result_type` de `void`.|
|[is_apartment_aware](#is_apartment_aware)|Determina se a tarefa desvincula uma interface de Tempo de execução do Windows `IAsyncInfo` ou se é descendente de tal tarefa.|
|[is_done](#is_done)|Determina se a tarefa foi concluída.|
|[scheduler](#scheduler)|Retorna o agendador para essa tarefa|
|[Clique](#then)|Sobrecarregado. Adiciona uma tarefa de continuação para essa tarefa.|
|[wait](#wait)|Aguarda que essa tarefa alcance um estado terminal. É possível para `wait` executar a tarefa em linha, se todas as dependências de tarefas forem atendidas, e ela ainda não tiver sido escolhida para execução por um trabalho em segundo plano.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator!=](#operator_neq)|Sobrecarregado. Determina se dois objetos `task` representam tarefas internas diferentes.|
|[operator=](#operator_eq)|Sobrecarregado. Substitui o conteúdo de um objeto `task` por outro.|
|[operator==](#operator_eq_eq)|Sobrecarregado. Determina se dois objetos `task` representam a mesma tarefa interna.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`task`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppltasks. h

**Namespace:** simultaneidade

##  <a name="get"></a>Obter

Retorna o resultado produzido por essa tarefa. Se a tarefa não estiver em um estado terminal, uma chamada para `get` irá aguardar a conclusão da tarefa. Este método não retorna um valor quando chamado em uma tarefa com um `result_type` de `void`.

```
_ResultType get() const;

void get() const;
```

### <a name="return-value"></a>Valor de retorno

O resultado da tarefa.

### <a name="remarks"></a>Comentários

Se a tarefa for cancelada, uma `get` chamada para emitirá uma exceção [task_canceled](task-canceled-class.md) . Se a tarefa encontrou uma exceção diferente ou se uma exceção foi propagada a ela de uma tarefa Antecedent, uma `get` chamada para gerará essa exceção.

> [!IMPORTANT]
>  Em um aplicativo plataforma universal do Windows (UWP), não chame [Concurrency:: Task:: Wait](#wait) ou `get` ( `wait` calls `get`) no código que é executado no thread da interface do usuário. Caso contrário, o tempo de execução lançará [Concurrency:: invalid_operation](invalid-operation-class.md) porque esses métodos bloqueiam o thread atual e podem fazer com que o aplicativo fique sem resposta. No entanto, você pode `get` chamar o método para receber o resultado da tarefa antecedente em uma continuação baseada em tarefa, pois o resultado está imediatamente disponível.

##  <a name="is_apartment_aware"></a> is_apartment_aware

Determina se a tarefa desvincula uma interface de Tempo de execução do Windows `IAsyncInfo` ou se é descendente de tal tarefa.

```
bool is_apartment_aware() const;
```

### <a name="return-value"></a>Valor de retorno

**true** se a tarefa desencapsular uma `IAsyncInfo` interface ou estiver descendente dessa tarefa; caso contrário, **retornará false** .

##  <a name="is_done"></a>Método Task:: is_done (Tempo de Execução de Simultaneidade)

Determina se a tarefa foi concluída.

```
bool is_done() const;
```

### <a name="return-value"></a>Valor de retorno

True se a tarefa for concluída; caso contrário, false.

### <a name="remarks"></a>Comentários

A função retornará true se a tarefa for concluída ou cancelada (com ou sem a exceção do usuário).

##  <a name="operator_neq"></a>operador! =

Determina se dois objetos `task` representam tarefas internas diferentes.

```
bool operator!= (const task<_ResultType>& _Rhs) const;

bool operator!= (const task<void>& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
A tarefa a ser comparada.

### <a name="return-value"></a>Valor de retorno

**true** se os objetos se referirem a diferentes tarefas subjacentes; caso contrário, **false** .

##  <a name="operator_eq"></a>operador =

Substitui o conteúdo de um objeto `task` por outro.

```
task& operator= (const task& _Other);

task& operator= (task&& _Other);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto `task` de origem.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Como `task` se comporta como um ponteiro inteligente, após uma atribuição de cópia, esses `task` objetos representam a mesma tarefa real que `_Other` o faz.

##  <a name="operator_eq_eq"></a>operador = =

Determina se dois objetos `task` representam a mesma tarefa interna.

```
bool operator== (const task<_ResultType>& _Rhs) const;

bool operator== (const task<void>& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
A tarefa a ser comparada.

### <a name="return-value"></a>Valor de retorno

**true** se os objetos se referirem à mesma tarefa subjacente e **false** caso contrário.

##  <a name="scheduler"></a>tarefa:: método do Agendador (Tempo de Execução de Simultaneidade)

Retorna o agendador para essa tarefa

```
scheduler_ptr scheduler() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o Agendador

##  <a name="ctor"></a>agenda

Constrói um objeto `task`.

```
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

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do parâmetro do qual a tarefa deve ser construída.

*_Param*<br/>
O parâmetro do qual a tarefa deve ser construída. Isso pode ser um lambda, um objeto Function, um `task_completion_event<result_type>` objeto ou um Windows:: Foundation:: IAsyncInfo se você estiver usando tarefas em seu aplicativo Windows Runtime. O objeto lambda ou de função deve ser um tipo equivalente `std::function<X(void)>`a, em que X pode ser uma variável `result_type`do `task<result_type>`tipo, ou um Windows:: Foundation:: IAsyncInfo em aplicativos Windows Runtime.

*_TaskOptions*<br/>
As opções de tarefa incluem token de cancelamento, Agendador, etc.

*_Other*<br/>
O objeto `task` de origem.

### <a name="remarks"></a>Comentários

O construtor padrão para um `task` está presente apenas para permitir que as tarefas sejam usadas em contêineres. Uma tarefa construída padrão não pode ser usada até que você atribua uma tarefa válida a ela. `get`Métodos como `wait` ou gerarão uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) quando chamados em uma tarefa construída padrão `then` .

Uma tarefa criada a partir de um `task_completion_event` será concluída (e terá suas continuaçãos agendadas) quando o evento de conclusão de tarefa for definido.

A versão do construtor que usa um token de cancelamento cria uma tarefa que pode ser cancelada `cancellation_token_source` usando o token obtido do. As tarefas criadas sem um token de cancelamento não podem ser canceladas.

As tarefas criadas a `Windows::Foundation::IAsyncInfo` partir de uma interface ou de um `IAsyncInfo` lambda que retorna uma interface atingem o estado do terminal quando a operação ou ação assíncrona Windows Runtimeda em anexo é concluída. Da mesma forma, as tarefas criadas a partir de `task<result_type>` um lambda que retorna um alcance o estado do terminal quando a tarefa interna atinge seu estado de terminal e não quando o lambda retorna.

`task`comporta-se como um ponteiro inteligente e é seguro de passar por valor. Ele pode ser acessado por vários threads sem a necessidade de bloqueios.

As sobrecargas de construtor que usam a interface Windows:: Foundation:: IAsyncInfo ou um lambda retornando essa interface, só estão disponíveis para aplicativos Windows Runtime.

Para obter mais informações, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

##  <a name="then"></a>Clique

Adiciona uma tarefa de continuação para essa tarefa.

```
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

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado por essa tarefa.

*_Func*<br/>
A função de continuação a ser executada quando esta tarefa for concluída. Essa função de continuação deve usar como entrada uma variável de `result_type` ou `task<result_type>`, em `result_type` que é o tipo do resultado que essa tarefa produz.

*_TaskOptions*<br/>
As opções de tarefa incluem token de cancelamento, Agendador e contexto de continuação. Por padrão, as três opções anteriores são herdadas da tarefa antecedente

*_CancellationToken*<br/>
O token de cancelamento a ser associado à tarefa de continuação. Uma tarefa de continuação que é criada sem um token de cancelamento herdará o token de sua tarefa antecedente.

*_ContinuationContext*<br/>
Uma variável que especifica onde a continuação deve ser executada. Essa variável só é útil quando usada em um aplicativo UWP. Para obter mais informações, consulte [task_continuation_context](task-continuation-context-class.md)

### <a name="return-value"></a>Valor de retorno

A tarefa de continuação recém-criada. O tipo de resultado da tarefa retornada é determinado pelo que `_Func` retorna.

### <a name="remarks"></a>Comentários

As sobrecargas de `then` que usam lambda ou functor que retornam uma interface Windows:: Foundation:: IAsyncInfo, estão disponíveis somente para aplicativos Windows Runtime.

Para obter mais informações sobre como usar as continuações de tarefa para compor trabalho assíncrono, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

##  <a name="wait"></a>esperado

Aguarda que essa tarefa alcance um estado terminal. É possível para `wait` executar a tarefa em linha, se todas as dependências de tarefas forem atendidas, e ela ainda não tiver sido escolhida para execução por um trabalho em segundo plano.

```
task_status wait() const;
```

### <a name="return-value"></a>Valor de retorno

Um `task_status` valor que pode `completed` ser ou `canceled`. Se a tarefa encontrou uma exceção durante a execução ou se uma exceção foi propagada a ela de uma tarefa `wait` Antecedent, o gerará essa exceção.

### <a name="remarks"></a>Comentários

> [!IMPORTANT]
>  Em um aplicativo plataforma universal do Windows (UWP), não chame `wait` no código que é executado no thread da interface do usuário. Caso contrário, o tempo de execução lançará [Concurrency:: invalid_operation](invalid-operation-class.md) porque esse método bloqueia o thread atual e pode fazer com que o aplicativo fique sem resposta. No entanto, você pode chamar o método [Concurrency:: Task:: Get](#get) para receber o resultado da tarefa Antecedent em uma continuação baseada em tarefa.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
