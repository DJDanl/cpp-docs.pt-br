---
title: task_options Classe (Runtime de Simultaneidade)
ms.date: 11/04/2016
f1_keywords:
- ppltasks/concurrency::task_options
ms.assetid: f93d146b-70f7-46ec-8c2f-c33b8bb0af69
ms.openlocfilehash: 5f60a07d709a79f3ce4845c8fbd1c40cb2ee7328
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142540"
---
# <a name="task_options-class-concurrency-runtime"></a>task_options Classe (Runtime de Simultaneidade)

Representa as opções permitidas para criar uma tarefa

## <a name="syntax"></a>Sintaxe

```cpp
class task_options;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor task_options:: task_options (Tempo de Execução de Simultaneidade)](#ctor)|Sobrecarregado. Lista padrão de opções de criação de tarefas|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Método task_options:: get_cancellation_token (Tempo de Execução de Simultaneidade)](#get_cancellation_token)|Retorna o token de cancelamento|
|[Método task_options:: get_continuation_context (Tempo de Execução de Simultaneidade)](#get_continuation_context)|Retorna o contexto de continuação|
|[Método task_options:: get_scheduler (Tempo de Execução de Simultaneidade)](#get_scheduler)|Retorna o agendador|
|[Método task_options:: has_cancellation_token (Tempo de Execução de Simultaneidade)](#has_cancellation_token)|Indica se um token de cancelamento foi especificado pelo usuário|
|[Método task_options:: has_scheduler (Tempo de Execução de Simultaneidade)](#has_scheduler)|Indica se um agendamento n foi especificado pelo usuário|
|[Método task_options:: set_cancellation_token (Tempo de Execução de Simultaneidade)](#set_cancellation_token)|Define o token fornecido nas opções|
|[Método task_options:: set_continuation_context (Tempo de Execução de Simultaneidade)](#set_continuation_context)|Define o contexto de continuação fornecido nas opções|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`task_options`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ppltasks. h

**Namespace:** simultaneidade

## <a name="get_cancellation_token"></a>Método task_options:: get_cancellation_token (Tempo de Execução de Simultaneidade)

Retorna o token de cancelamento

```cpp
cancellation_token get_cancellation_token() const;
```

### <a name="return-value"></a>Valor retornado

## <a name="get_continuation_context"></a>Método task_options:: get_continuation_context (Tempo de Execução de Simultaneidade)

Retorna o contexto de continuação

```cpp
task_continuation_context get_continuation_context() const;
```

### <a name="return-value"></a>Valor retornado

## <a name="get_scheduler"></a>Método task_options:: get_scheduler (Tempo de Execução de Simultaneidade)

Retorna o agendador

```cpp
scheduler_ptr get_scheduler() const;
```

### <a name="return-value"></a>Valor retornado

## <a name="has_cancellation_token"></a>Método task_options:: has_cancellation_token (Tempo de Execução de Simultaneidade)

Indica se um token de cancelamento foi especificado pelo usuário

```cpp
bool has_cancellation_token() const;
```

### <a name="return-value"></a>Valor retornado

## <a name="has_scheduler"></a>Método task_options:: has_scheduler (Tempo de Execução de Simultaneidade)

Indica se um agendamento n foi especificado pelo usuário

```cpp
bool has_scheduler() const;
```

### <a name="return-value"></a>Valor retornado

## <a name="set_cancellation_token"></a>Método task_options:: set_cancellation_token (Tempo de Execução de Simultaneidade)

Define o token fornecido nas opções

```cpp
void set_cancellation_token(cancellation_token _Token);
```

### <a name="parameters"></a>Parâmetros

`_Token`

## <a name="set_continuation_context"></a>Método task_options:: set_continuation_context (Tempo de Execução de Simultaneidade)

Define o contexto de continuação fornecido nas opções

```cpp
void set_continuation_context(task_continuation_context _ContinuationContext);
```

### <a name="parameters"></a>Parâmetros

`_ContinuationContext`

## <a name="ctor"></a>Construtor task_options:: task_options (Tempo de Execução de Simultaneidade)

Lista padrão de opções de criação de tarefas

```cpp
task_options();

task_options(
    cancellation_token _Token);

task_options(
    task_continuation_context _ContinuationContext);

task_options(
    cancellation_token _Token,
    task_continuation_context _ContinuationContext);

template<typename _SchedType>
task_options(
    std::shared_ptr<_SchedType> _Scheduler);

task_options(
    scheduler_interface& _Scheduler);

task_options(
    scheduler_ptr _Scheduler);

task_options(
    const task_options& _TaskOptions);
```

### <a name="parameters"></a>Parâmetros

`_SchedType`

`_Token`

`_ContinuationContext`

`_Scheduler`

`_TaskOptions`

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
