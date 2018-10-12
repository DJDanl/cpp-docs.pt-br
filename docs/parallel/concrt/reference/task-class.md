---
title: Classe (tempo de execução de simultaneidade) Task | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- task class
ms.assetid: cdc3a8c0-5cbe-45a0-b5d5-e9f81d94df1a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bac539fc2826b5628769126d9802688c01f01c7b
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49163199"
---
# <a name="task-class-concurrency-runtime"></a>Classe task (Tempo de Execução de Simultaneidade)

A classe `task` da Biblioteca de Padrões Paralelos (PPL). O objeto `task` representa o trabalho que pode ser executado de forma assíncrona e simultaneamente com outras tarefas e o trabalho paralelo produzido por algoritmos paralelos no Tempo de execução de simultaneidade. Produz um resultado de tipo `_ResultType` após uma conclusão bem-sucedida. Tarefas do tipo `task<void>` não produzem resultados. Uma tarefa pode ser aguardada e cancelada independentemente de outras tarefas. Ele também pode ser composto com outras tarefas usando continuações ( `then`) e Junte-se ( `when_all`) e a opção ( `when_any`) padrões.

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class task;

template <>
class task<void>;

template<typename _ReturnType>
class task;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de objeto de tarefa.

*_ReturnType*<br/>
O tipo de resultado desta tarefa.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`result_type`|O tipo do resultado que um objeto desta classe produz.|

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Tarefa](#ctor)|Sobrecarregado. Constrói um objeto `task`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[get](#get)|Sobrecarregado. Retorna o resultado produzido por essa tarefa. Se a tarefa não estiver em um estado terminal, uma chamada para `get` irá aguardar a conclusão da tarefa. Este método não retorna um valor quando chamado em uma tarefa com um `result_type` de `void`.|
|[is_apartment_aware](#is_apartment_aware)|Determina se a tarefa desvincula uma interface de Tempo de execução do Windows `IAsyncInfo` ou se é descendente de tal tarefa.|
|[is_done](#is_done)|Determina se a tarefa foi concluída.|
|[scheduler](#scheduler)|Retorna o agendador para essa tarefa|
|[Em seguida](#then)|Sobrecarregado. Adiciona uma tarefa de continuação para essa tarefa.|
|[wait](#wait)|Aguarda que essa tarefa alcance um estado terminal. É possível para `wait` executar a tarefa em linha, se todas as dependências de tarefas forem atendidas, e ela ainda não tiver sido escolhida para execução por um trabalho em segundo plano.|

### <a name="public-operators"></a>Operadores Públicos

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

##  <a name="get"></a> Obter

Retorna o resultado produzido por essa tarefa. Se a tarefa não estiver em um estado terminal, uma chamada para `get` irá aguardar a conclusão da tarefa. Este método não retorna um valor quando chamado em uma tarefa com um `result_type` de `void`.

```
_ReturnType get() const;

void get() const;
```

### <a name="return-value"></a>Valor de retorno

O resultado da tarefa.

### <a name="remarks"></a>Comentários

Se a tarefa for cancelada, uma chamada para `get` lançará uma [task_canceled](task-canceled-class.md) exceção. Se a tarefa encontrou uma exceção diferente ou uma exceção foi propagada para ela de uma antecessora tarefa, uma chamada para `get` lançará essa exceção.

> [!IMPORTANT]
>  Em um aplicativo de plataforma Universal do Windows (UWP), não chame [concurrency::task::wait](#wait) ou `get` ( `wait` chamadas `get`) no código executado no STA. Caso contrário, o tempo de execução gera [Concurrency:: invalid_operation](invalid-operation-class.md) porque esses métodos bloqueiam o thread atual e pode fazer com que o aplicativo pare de responder. No entanto, você pode chamar o `get` método para receber o resultado da tarefa antecedente em uma continuação baseada em tarefa, porque o resultado está imediatamente disponível.

##  <a name="is_apartment_aware"></a> is_apartment_aware

Determina se a tarefa desvincula uma interface de Tempo de execução do Windows `IAsyncInfo` ou se é descendente de tal tarefa.

```
bool is_apartment_aware() const;
```

### <a name="return-value"></a>Valor de retorno

**True** se a tarefa desempacotar uma `IAsyncInfo` interface ou é descendente de tal tarefa **falso** caso contrário.

##  <a name="is_done"></a>  Task:: is_done (tempo de execução de simultaneidade) do método

Determina se a tarefa foi concluída.

```
bool is_done() const;
```

### <a name="return-value"></a>Valor de retorno

True se a tarefa foi concluída, false caso contrário.

### <a name="remarks"></a>Comentários

A função retorna true se a tarefa for concluída ou cancelada (com ou sem exceção do usuário).

##  <a name="operator_neq"></a> operador! =

Determina se dois objetos `task` representam tarefas internas diferentes.

```
bool operator!= (const task<_ReturnType>& _Rhs) const;

bool operator!= (const task<void>& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
A tarefa a ser comparado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se os objetos se referirem a tarefas subjacentes diferentes, e **falso** caso contrário.

##  <a name="operator_eq"></a> operador =

Substitui o conteúdo de um objeto `task` por outro.

```
task& operator= (const task& _Other);

task& operator= (task&& _Other);
```

### <a name="parameters"></a>Parâmetros

*Outro*<br/>
A fonte `task` objeto.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Como `task` comporta-se como um ponteiro inteligente, após uma atribuição de cópia, isso `task` objetos representa a mesma tarefa real que `_Other` faz.

##  <a name="operator_eq_eq"></a> operador = =

Determina se dois objetos `task` representam a mesma tarefa interna.

```
bool operator== (const task<_ReturnType>& _Rhs) const;

bool operator== (const task<void>& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
A tarefa a ser comparado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se os objetos se referirem à mesma tarefa subjacente, e **falso** caso contrário.

##  <a name="scheduler"></a>  Task:: Scheduler (tempo de execução de simultaneidade) do método

Retorna o agendador para essa tarefa

```
scheduler_ptr scheduler() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o Agendador

##  <a name="ctor"></a> Tarefa

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
O parâmetro do qual a tarefa deve ser construída. Isso pode ser um lambda, um objeto de função, um `task_completion_event<result_type>` objeto ou um Windows::Foundation::IAsyncInfo se você estiver usando tarefas em seu aplicativo de tempo de execução do Windows. O objeto lambda ou função deve ser um tipo equivalente a `std::function<X(void)>`, onde X pode ser uma variável do tipo `result_type`, `task<result_type>`, ou um Windows::Foundation::IAsyncInfo em aplicativos de tempo de execução do Windows.

*_TaskOptions*<br/>
As opções de tarefa incluem o Agendador, token de cancelamento etc.

*Outro*<br/>
A fonte `task` objeto.

### <a name="remarks"></a>Comentários

O construtor padrão para um `task` está presente apenas para permitir que as tarefas a ser usado dentro de contêineres. Uma tarefa construída padrão não pode ser usada até que você atribua uma tarefa válida a ele. Métodos como `get`, `wait` ou `then` lançará uma [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção quando chamado em uma tarefa construída padrão.

Uma tarefa criada por meio de um `task_completion_event` será concluída (e terá sua continuação agendada) quando o evento de conclusão de tarefa é definido.

A versão do construtor que aceita um token de cancelamento cria uma tarefa que pode ser cancelada usando o `cancellation_token_source` o token foi obtido. As tarefas criadas sem um token de cancelamento não são anuláveis.

As tarefas criadas de uma `Windows::Foundation::IAsyncInfo` interface ou lambda que retorna um `IAsyncInfo` interface alcançar seu estado terminal quando a operação assíncrona de tempo de execução do Windows incluído ou a ação for concluída. Da mesma forma, as tarefas criadas de um lamda que retornam um `task<result_type>` alcançar seu estado terminal quando a tarefa interna alcança seu estado terminal e não quando o lamda retornar.

`task` se comporta como um ponteiro inteligente e é seguro passar ao redor por valor. Ele pode ser acessado por vários threads sem a necessidade de bloqueios.

As sobrecargas de construtor que usam uma interface Windows::Foundation::IAsyncInfo ou um lambda que retorna uma interface, só estão disponíveis para aplicativos do Windows Runtime.

Para obter mais informações, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

##  <a name="then"></a> Em seguida

Adiciona uma tarefa de continuação para essa tarefa.

```
template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func) const -> typename details::_ContinuationTypeTraits<_Function,
    _ReturnType>::_TaskOfType;

template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func,
    const task_options& _TaskOptions) const -> typename details::_ContinuationTypeTraits<_Function,
    _ReturnType>::_TaskOfType;

template<typename _Function>
__declspec(
    noinline) auto then(const _Function& _Func,
    cancellation_token _CancellationToken,
    task_continuation_context _ContinuationContext) const -> typename details::_ContinuationTypeTraits<_Function,
    _ReturnType>::_TaskOfType;

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
O tipo do objeto de função que será chamado por essa tarefa.

*_Func*<br/>
A função de continuação a ser executado quando esta tarefa for concluída. Essa função de continuação deve tomar como entrada uma variável de qualquer uma `result_type` ou `task<result_type>`, onde `result_type` é o tipo de resultado que esta tarefa produz.

*_TaskOptions*<br/>
As opções de tarefas incluem o contexto de token, o Agendador e a continuação do cancelamento. Por padrão, as 3 opções antigas são herdadas da tarefa antecedente

*_CancellationToken*<br/>
O token de cancelamento associado à tarefa de continuação. Uma tarefa de continuação que é criada sem um token de cancelamento herdará o token de sua tarefa antecedente.

*_ContinuationContext*<br/>
Uma variável que especifica onde a continuação deve ser executada. Essa variável só é útil quando usado em um aplicativo UWP. Para obter mais informações, consulte [task_continuation_context](task-continuation-context-class.md)

### <a name="return-value"></a>Valor de retorno

A tarefa de continuação criada recentemente. O tipo de resultado da tarefa retornada é determinado por qual `_Func` retorna.

### <a name="remarks"></a>Comentários

As sobrecargas de `then` que recebem um lambda ou functor que retorna uma interface Windows::Foundation::IAsyncInfo, só estão disponíveis para aplicativos do Windows Runtime.

Para obter mais informações sobre como usar continuações de tarefa para compor o trabalho assíncrono, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

##  <a name="wait"></a> Aguarde

Aguarda que essa tarefa alcance um estado terminal. É possível para `wait` executar a tarefa em linha, se todas as dependências de tarefas forem atendidas, e ela ainda não tiver sido escolhida para execução por um trabalho em segundo plano.

```
task_status wait() const;
```

### <a name="return-value"></a>Valor de retorno

Um `task_status` valor que pode ser `completed` ou `canceled`. Se a tarefa encontrou uma exceção durante a execução ou uma exceção foi propagada para ela de uma tarefa antecedente, `wait` lançará essa exceção.

### <a name="remarks"></a>Comentários

> [!IMPORTANT]
>  Em um aplicativo de plataforma Universal do Windows (UWP), não chame `wait` no código executado no STA. Caso contrário, o tempo de execução gera [Concurrency:: invalid_operation](invalid-operation-class.md) porque esse método bloqueia o thread atual e pode fazer com que o aplicativo pare de responder. No entanto, você pode chamar o [concurrency::task::get](#get) método para receber o resultado da tarefa antecedente em uma continuação baseada em tarefa.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
