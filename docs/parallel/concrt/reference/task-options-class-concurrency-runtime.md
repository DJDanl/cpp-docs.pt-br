---
title: task_options Classe (Tempo de Execução de Simultaneidade)
ms.date: 11/04/2016
f1_keywords:
- ppltasks/concurrency::task_options
ms.assetid: f93d146b-70f7-46ec-8c2f-c33b8bb0af69
ms.openlocfilehash: c832ce759c556765fa412b2ef77333bc6612b8c3
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57265204"
---
# <a name="taskoptions-class-concurrency-runtime"></a>task_options Classe (Tempo de Execução de Simultaneidade)

Representa as opções permitidas para criar uma tarefa

## <a name="syntax"></a>Sintaxe

```
class task_options;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[task_options:: task_options (tempo de execução de simultaneidade) do construtor](#ctor)|Sobrecarregado. Lista padrão de opções de criação de tarefas|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[task_options:: get_cancellation_token (tempo de execução de simultaneidade) do método](#get_cancellation_token)|Retorna o token de cancelamento|
|[task_options:: get_continuation_context (tempo de execução de simultaneidade) do método](#get_continuation_context)|Retorna o contexto de continuação|
|[task_options:: get_scheduler (tempo de execução de simultaneidade) do método](#get_scheduler)|Retorna o agendador|
|[task_options:: has_cancellation_token (tempo de execução de simultaneidade) do método](#has_cancellation_token)|Indica se um token de cancelamento foi especificado pelo usuário|
|[task_options:: has_scheduler (tempo de execução de simultaneidade) do método](#has_scheduler)|Indica se um agendamento n foi especificado pelo usuário|
|[task_options:: set_cancellation_token (tempo de execução de simultaneidade) do método](#set_cancellation_token)|Define o token fornecido nas opções|
|[task_options:: set_continuation_context (tempo de execução de simultaneidade) do método](#set_continuation_context)|Define o contexto de continuação fornecido nas opções|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`task_options`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppltasks. h

**Namespace:** simultaneidade

##  <a name="get_cancellation_token"></a>  task_options:: get_cancellation_token (tempo de execução de simultaneidade) do método

Retorna o token de cancelamento

```
cancellation_token get_cancellation_token() const;
```

### <a name="return-value"></a>Valor de retorno

##  <a name="get_continuation_context"></a>  task_options:: get_continuation_context (tempo de execução de simultaneidade) do método

Retorna o contexto de continuação

```
task_continuation_context get_continuation_context() const;
```

### <a name="return-value"></a>Valor de retorno

##  <a name="get_scheduler"></a>  task_options:: get_scheduler (tempo de execução de simultaneidade) do método

Retorna o agendador

```
scheduler_ptr get_scheduler() const;
```

### <a name="return-value"></a>Valor de retorno

##  <a name="has_cancellation_token"></a>  task_options:: has_cancellation_token (tempo de execução de simultaneidade) do método

Indica se um token de cancelamento foi especificado pelo usuário

```
bool has_cancellation_token() const;
```

### <a name="return-value"></a>Valor de retorno

##  <a name="has_scheduler"></a>  task_options:: has_scheduler (tempo de execução de simultaneidade) do método

Indica se um agendamento n foi especificado pelo usuário

```
bool has_scheduler() const;
```

### <a name="return-value"></a>Valor de retorno

##  <a name="set_cancellation_token"></a>  task_options:: set_cancellation_token (tempo de execução de simultaneidade) do método

Define o token fornecido nas opções

```
void set_cancellation_token(cancellation_token _Token);
```

### <a name="parameters"></a>Parâmetros

`_Token`

##  <a name="set_continuation_context"></a>  task_options:: set_continuation_context (tempo de execução de simultaneidade) do método

Define o contexto de continuação fornecido nas opções

```
void set_continuation_context(task_continuation_context _ContinuationContext);
```

### <a name="parameters"></a>Parâmetros

`_ContinuationContext`

##  <a name="ctor"></a>  task_options:: task_options (tempo de execução de simultaneidade) do construtor

Lista padrão de opções de criação de tarefas

```
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
