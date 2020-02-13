---
title: Estrutura IExecutionContext
ms.date: 11/04/2016
f1_keywords:
- IExecutionContext
- CONCRTRM/concurrency::IExecutionContext
- CONCRTRM/concurrency::IExecutionContext::IExecutionContext::Dispatch
- CONCRTRM/concurrency::IExecutionContext::IExecutionContext::GetId
- CONCRTRM/concurrency::IExecutionContext::IExecutionContext::GetProxy
- CONCRTRM/concurrency::IExecutionContext::IExecutionContext::GetScheduler
- CONCRTRM/concurrency::IExecutionContext::IExecutionContext::SetProxy
helpviewer_keywords:
- IExecutionContext structure
ms.assetid: f3108089-ecda-4b07-86db-3efae60c31e0
ms.openlocfilehash: 45d65a5e16121d39233c3ceb801933aa1f5a5f8e
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77138907"
---
# <a name="iexecutioncontext-structure"></a>Estrutura IExecutionContext

Uma interface para um contexto de execução que pode ser executado em um determinado processador virtual e ser alternado por contexto de forma cooperativa.

## <a name="syntax"></a>Sintaxe

```cpp
struct IExecutionContext;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IExecutionContext::D ispatch](#dispatch)|O método que é chamado quando um proxy de thread começa a executar um contexto de execução específico. Essa deve ser a principal rotina de trabalho para o Agendador.|
|[IExecutionContext:: GetId](#getid)|Retorna um identificador exclusivo para o contexto de execução.|
|[IExecutionContext:: GetProxy](#getproxy)|Retorna uma interface para o proxy de thread que está executando este contexto.|
|[IExecutionContext:: getscheduler](#getscheduler)|Retorna uma interface para o Agendador ao qual este contexto de execução pertence.|
|[IExecutionContext:: SetProxy](#setproxy)|Associa um proxy de thread a este contexto de execução. O proxy de thread associado invoca esse método logo antes de começar a executar o método de `Dispatch` do contexto.|

## <a name="remarks"></a>Comentários

Se estiver implementando um Agendador personalizado que interage com o Gerenciador de recursos do Tempo de Execução de Simultaneidade, você precisará implementar a interface `IExecutionContext`. Os threads criados pelo Gerenciador de recursos executam o trabalho em nome do seu Agendador executando o método `IExecutionContext::Dispatch`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IExecutionContext`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="dispatch"></a>IExecutionContext: método ispatch:D

O método que é chamado quando um proxy de thread começa a executar um contexto de execução específico. Essa deve ser a principal rotina de trabalho para o Agendador.

```cpp
virtual void Dispatch(_Inout_ DispatchState* pDispatchState) = 0;
```

### <a name="parameters"></a>Parâmetros

*pDispatchState*<br/>
Um ponteiro para o estado sob o qual esse contexto de execução está sendo expedido. Para obter mais informações sobre o estado de expedição, consulte [expatchstate](dispatchstate-structure.md).

## <a name="getid"></a>Método IExecutionContext:: GetId

Retorna um identificador exclusivo para o contexto de execução.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador inteiro exclusivo.

### <a name="remarks"></a>Comentários

Você deve usar o método `GetExecutionContextId` para obter um identificador exclusivo para o objeto que implementa a interface `IExecutionContext`, antes de usar a interface como um parâmetro para os métodos fornecidos pelo Gerenciador de recursos. Você deve retornar o mesmo identificador quando a função `GetId` for invocada.

Um identificador obtido de uma fonte diferente poderia resultar em um comportamento indefinido.

## <a name="getproxy"></a>Método IExecutionContext:: GetProxy

Retorna uma interface para o proxy de thread que está executando este contexto.

```cpp
virtual IThreadProxy* GetProxy() = 0;
```

### <a name="return-value"></a>Valor retornado

Uma interface `IThreadProxy`. Se o proxy de thread do contexto de execução não tiver sido inicializado com uma chamada para `SetProxy`, a função deverá retornar `NULL`.

### <a name="remarks"></a>Comentários

O Gerenciador de recursos invocará o método `SetProxy` em um contexto de execução, com uma interface `IThreadProxy` como um parâmetro, antes de entrar no método `Dispatch` no contexto. Você deve armazenar esse argumento e retorná-lo em chamadas para `GetProxy()`.

## <a name="getscheduler"></a>Método IExecutionContext:: getscheduler

Retorna uma interface para o Agendador ao qual este contexto de execução pertence.

```cpp
virtual IScheduler* GetScheduler() = 0;
```

### <a name="return-value"></a>Valor retornado

Uma interface `IScheduler`.

### <a name="remarks"></a>Comentários

Você deve inicializar o contexto de execução com uma interface de `IScheduler` válida antes de usá-la como um parâmetro para os métodos fornecidos pelo Gerenciador de recursos.

## <a name="setproxy"></a>Método IExecutionContext:: SetProxy

Associa um proxy de thread a este contexto de execução. O proxy de thread associado invoca esse método logo antes de começar a executar o método de `Dispatch` do contexto.

```cpp
virtual void SetProxy(_Inout_ IThreadProxy* pThreadProxy) = 0;
```

### <a name="parameters"></a>Parâmetros

*pThreadProxy*<br/>
Uma interface para o proxy de thread que está prestes a inserir o método de `Dispatch` nesse contexto de execução.

### <a name="remarks"></a>Comentários

Você deve salvar o parâmetro `pThreadProxy` e retorná-lo em uma chamada para o método `GetProxy`. O Gerenciador de recursos garante que o proxy de thread associado ao contexto de execução não será alterado enquanto o proxy de thread estiver executando o método `Dispatch`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IScheduler](ischeduler-structure.md)<br/>
[Estrutura IThreadProxy](ithreadproxy-structure.md)
