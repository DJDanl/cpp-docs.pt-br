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
ms.openlocfilehash: d42c7fbd3e065fc295027b7c56e207b2a49221bb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358730"
---
# <a name="task-class-concurrency-runtime"></a>Classe task (Runtime de Simultaneidade)

A classe `task` da Biblioteca de Padrões Paralelos (PPL). Um `task` objeto representa um trabalho que pode ser executado de forma assíncrona e simultânea com outras tarefas e trabalhos paralelos produzidos por algoritmos paralelos no Tempo de Execução de Concurrency. Produz um resultado de tipo `_ResultType` após uma conclusão bem-sucedida. Tarefas do tipo `task<void>` não produzem resultados. Uma tarefa pode ser aguardada e cancelada independentemente de outras tarefas. Também pode ser composto com outras `then`tarefas `when_all`usando continuações `when_any`e aderindo a padrões de escolha e escolha. Quando um objeto de tarefa é atribuído a uma `std::shared_ptr`nova variável, o comportamento é o de ; em outras palavras, ambos os objetos representam a mesma tarefa subjacente.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
class task<void>;

template<typename _ResultType>
class task;
```

### <a name="parameters"></a>Parâmetros

*_ResultType*<br/>
O tipo de resultado que a tarefa produz.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`result_type`|O tipo do resultado que um objeto desta classe produz.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Tarefa](#ctor)|Sobrecarregado. Constrói um objeto `task`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get](#get)|Sobrecarregado. Retorna o resultado produzido por essa tarefa. Se a tarefa não estiver em um estado terminal, uma chamada para `get` irá aguardar a conclusão da tarefa. Este método não retorna um valor quando chamado em uma tarefa com um `result_type` de `void`.|
|[is_apartment_aware](#is_apartment_aware)|Determina se a tarefa desvincula uma interface de Windows Runtime `IAsyncInfo` ou se é descendente de tal tarefa.|
|[is_done](#is_done)|Determina se a tarefa foi concluída.|
|[Agendador](#scheduler)|Retorna o agendador para essa tarefa|
|[Então](#then)|Sobrecarregado. Adiciona uma tarefa de continuação para essa tarefa.|
|[Esperar](#wait)|Aguarda que essa tarefa alcance um estado terminal. É possível para `wait` executar a tarefa em linha, se todas as dependências de tarefas forem atendidas, e ela ainda não tiver sido escolhida para execução por um trabalho em segundo plano.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador!=](#operator_neq)|Sobrecarregado. Determina se dois objetos `task` representam tarefas internas diferentes.|
|[operador=](#operator_eq)|Sobrecarregado. Substitui o conteúdo de um objeto `task` por outro.|
|[operador==](#operator_eq_eq)|Sobrecarregado. Determina se dois objetos `task` representam a mesma tarefa interna.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [O Paralelismo da Tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`task`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppltasks.h

**Namespace:** concurrency

## <a name="get"></a><a name="get"></a>Obter

Retorna o resultado produzido por essa tarefa. Se a tarefa não estiver em um estado terminal, uma chamada para `get` irá aguardar a conclusão da tarefa. Este método não retorna um valor quando chamado em uma tarefa com um `result_type` de `void`.

```cpp
_ResultType get() const;

void get() const;
```

### <a name="return-value"></a>Valor retornado

O resultado da tarefa.

### <a name="remarks"></a>Comentários

Se a tarefa for cancelada, `get` uma chamada será lançada uma [task_canceled](task-canceled-class.md) exceção. Se a tarefa encontrou uma exceção diferente ou uma exceção foi propagada a ela a partir de uma tarefa antecedente, uma chamada para `get` lançar essa exceção.

> [!IMPORTANT]
> Em um aplicativo Universal Windows Platform (UWP), não chame [a concorrência::task::wait](#wait) or `get` (chamadas) `wait` `get`em código que é executado no segmento de interface do usuário. Caso contrário, o tempo de execução joga [simultâneo::invalid_operation](invalid-operation-class.md) porque esses métodos bloqueiam o segmento atual e podem fazer com que o aplicativo fique sem resposta. No entanto, `get` você pode chamar o método para receber o resultado da tarefa antecedente em uma continuação baseada em tarefas porque o resultado está disponível imediatamente.

## <a name="is_apartment_aware"></a><a name="is_apartment_aware"></a>is_apartment_aware

Determina se a tarefa desvincula uma interface de Windows Runtime `IAsyncInfo` ou se é descendente de tal tarefa.

```cpp
bool is_apartment_aware() const;
```

### <a name="return-value"></a>Valor retornado

**verdade** se a tarefa `IAsyncInfo` desembrulhar uma interface ou for descendente de tal tarefa, **falsa** de outra forma.

## <a name="taskis_done-method-concurrency-runtime"></a><a name="is_done"></a>tarefa::Método is_done (Tempo de execução de concorrência)

Determina se a tarefa foi concluída.

```cpp
bool is_done() const;
```

### <a name="return-value"></a>Valor retornado

Verdade se a tarefa foi concluída, falsa de outra forma.

### <a name="remarks"></a>Comentários

A função retorna verdadeira se a tarefa for concluída ou cancelada (com ou sem exceção do usuário).

## <a name="operator"></a><a name="operator_neq"></a>operador!=

Determina se dois objetos `task` representam tarefas internas diferentes.

```cpp
bool operator!= (const task<_ResultType>& _Rhs) const;

bool operator!= (const task<void>& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
A tarefa de comparar.

### <a name="return-value"></a>Valor retornado

**verdade** se os objetos se referem a diferentes tarefas subjacentes, e **falsas** de outra forma.

## <a name="operator"></a><a name="operator_eq"></a>operador=

Substitui o conteúdo de um objeto `task` por outro.

```cpp
task& operator= (const task& _Other);

task& operator= (task&& _Other);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto `task` de origem.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Como `task` se comporta como um ponteiro inteligente, `task` após uma atribuição de `_Other` cópia, esses objetos representam a mesma tarefa real que faz.

## <a name="operator"></a><a name="operator_eq_eq"></a>operador==

Determina se dois objetos `task` representam a mesma tarefa interna.

```cpp
bool operator== (const task<_ResultType>& _Rhs) const;

bool operator== (const task<void>& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
A tarefa de comparar.

### <a name="return-value"></a>Valor retornado

**verdade** se os objetos se referem à mesma tarefa subjacente, e **falso** de outra forma.

## <a name="taskscheduler-method-concurrency-runtime"></a><a name="scheduler"></a>tarefa::método de agendador (Tempo de execução de concorrência)

Retorna o agendador para essa tarefa

```cpp
scheduler_ptr scheduler() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o agendador

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

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de parâmetro a partir do qual a tarefa deve ser construída.

*_Param*<br/>
O parâmetro a partir do qual a tarefa deve ser construída. Isso pode ser um lambda, `task_completion_event<result_type>` um objeto de função, um objeto ou um Windows::Foundation::IAsyncInfo se você estiver usando tarefas no aplicativo Windows Runtime. O objeto lambda ou função deve `std::function<X(void)>`ser um tipo equivalente `result_type`a `task<result_type>`, onde X pode ser uma variável de tipo , ou um Windows::Foundation::IAsyncInfo em aplicativos Windows Runtime.

*_TaskOptions*<br/>
As opções de tarefa incluem token de cancelamento, agendador etc.

*_Other*<br/>
O objeto `task` de origem.

### <a name="remarks"></a>Comentários

O construtor padrão `task` para a só está presente para permitir que tarefas sejam usadas dentro de contêineres. Uma tarefa construída padrão não pode ser usada até que você atribua uma tarefa válida a ela. Métodos como `get` `wait` , `then` ou lançarão uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) quando chamado em uma tarefa construída padrão.

Uma tarefa criada a `task_completion_event` partir de uma vontade será concluída (e terá suas continuações programadas) quando o evento de conclusão da tarefa for definido.

A versão do construtor que pega um token de cancelamento cria `cancellation_token_source` uma tarefa que pode ser cancelada usando o token foi obtido. Tarefas criadas sem um token de cancelamento não podem ser canceladas.

Tarefas criadas `Windows::Foundation::IAsyncInfo` a partir de uma `IAsyncInfo` interface ou lambda que retorna uma interface chegam ao seu estado terminal quando a operação assíncrona ou ação do Windows Runtime concluída. Da mesma forma, tarefas criadas `task<result_type>` a partir de uma lambda que retorna um estado terminal quando a tarefa interna atinge seu estado terminal, e não quando a lambda retorna.

`task`comporta-se como um ponteiro inteligente e é seguro para passar por valor. Ele pode ser acessado por vários threads sem a necessidade de fechaduras.

As sobrecargas de construtores que tomam uma interface Windows::Foundation::IAsyncInfo ou uma lambda retornando tal interface, só estão disponíveis para aplicativos do Windows Runtime.

Para obter mais informações, consulte [O Paralelismo da Tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="then"></a><a name="then"></a>Então

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

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado por esta tarefa.

*_Func*<br/>
A função de continuação será executada quando esta tarefa for concluída. Esta função de continuação deve `result_type` tomar `task<result_type>`como `result_type` entrada uma variável de qualquer um ou , onde está o tipo de resultado que esta tarefa produz.

*_TaskOptions*<br/>
As opções de tarefa incluem token de cancelamento, agendador e contexto de continuação. Por padrão, as 3 opções anteriores são herdadas da tarefa antecedente

*_CancellationToken*<br/>
O token de cancelamento para associar-se à tarefa de continuação. Uma tarefa de continuação criada sem um token de cancelamento herdará o token de sua tarefa antecedente.

*_ContinuationContext*<br/>
Uma variável que especifica onde a continuação deve ser executada. Esta variável só é útil quando usada em um aplicativo UWP. Para obter mais informações, consulte [task_continuation_context](task-continuation-context-class.md)

### <a name="return-value"></a>Valor retornado

A recém-criada tarefa de continuação. O tipo de resultado da tarefa `_Func` retornada é determinado pelo que retorna.

### <a name="remarks"></a>Comentários

As sobrecargas `then` disso levam um lambda ou functor que retorna uma interface Windows::Foundation::IAsyncInfo, só estão disponíveis para aplicativos do Windows Runtime.

Para obter mais informações sobre como usar continuações de tarefas para compor trabalhos assíncronos, consulte [O Paralelismo da Tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

## <a name="wait"></a><a name="wait"></a>Esperar

Aguarda que essa tarefa alcance um estado terminal. É possível para `wait` executar a tarefa em linha, se todas as dependências de tarefas forem atendidas, e ela ainda não tiver sido escolhida para execução por um trabalho em segundo plano.

```cpp
task_status wait() const;
```

### <a name="return-value"></a>Valor retornado

Um `task_status` valor que `completed` poderia `canceled`ser ou . Se a tarefa encontrou uma exceção durante a execução, ou uma `wait` exceção foi propagada a ela a partir de uma tarefa antecedente, lançará essa exceção.

### <a name="remarks"></a>Comentários

> [!IMPORTANT]
> Em um aplicativo Universal Windows Platform (UWP), não chame `wait` o código que é executado no segmento de interface do usuário. Caso contrário, o tempo de execução joga [simultâneo::invalid_operation](invalid-operation-class.md) porque este método bloqueia o segmento atual e pode fazer com que o aplicativo fique sem resposta. No entanto, você pode chamar o método [de concorrência::task::get](#get) para receber o resultado da tarefa antecedente em uma continuação baseada em tarefas.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)
