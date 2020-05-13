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
ms.openlocfilehash: 532247ca1776452ad32476d2bcdfafcee3481058
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358798"
---
# <a name="iexecutioncontext-structure"></a>Estrutura IExecutionContext

Uma interface para um contexto de execução que pode ser executada em um determinado processador virtual e ser cooperativamente comutada.

## <a name="syntax"></a>Sintaxe

```cpp
struct IExecutionContext;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IExecutionContext::Dispatch](#dispatch)|O método que é chamado quando um proxy thread começa a executar um contexto de execução particular. Esta deve ser a principal rotina do trabalhador para o seu agendador.|
|[IExecutionContext::GetId](#getid)|Retorna um identificador único para o contexto de execução.|
|[iExecutionContext::getProxy](#getproxy)|Retorna uma interface para o proxy de segmento que está executando este contexto.|
|[IExecutionContext::GetScheduler](#getscheduler)|Retorna uma interface ao agendador a que este contexto de execução pertence.|
|[iExecutionContext::SetProxy](#setproxy)|Associa um proxy de segmento a este contexto de execução. O proxy de segmento associado invoca esse método antes `Dispatch` de começar a executar o método do contexto.|

## <a name="remarks"></a>Comentários

Se você estiver implementando um agendador personalizado que faz interface com o Gerenciador `IExecutionContext` de Recursos do Concurrency Runtime, você precisará implementar a interface. Os threads criados pelo Gerenciador de Recursos realizam trabalhos `IExecutionContext::Dispatch` em nome do seu agendador executando o método.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IExecutionContext`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="iexecutioncontextdispatch-method"></a><a name="dispatch"></a>IExecutionContext::Dispatch Method

O método que é chamado quando um proxy thread começa a executar um contexto de execução particular. Esta deve ser a principal rotina do trabalhador para o seu agendador.

```cpp
virtual void Dispatch(_Inout_ DispatchState* pDispatchState) = 0;
```

### <a name="parameters"></a>Parâmetros

*pDispatchState*<br/>
Um ponteiro para o estado sob o qual este contexto de execução está sendo despachado. Para obter mais informações sobre o estado de despacho, consulte [DispatchState](dispatchstate-structure.md).

## <a name="iexecutioncontextgetid-method"></a><a name="getid"></a>IExecutionContext::GetId Method

Retorna um identificador único para o contexto de execução.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador inteiro único.

### <a name="remarks"></a>Comentários

Você deve usar `GetExecutionContextId` o método para obter um identificador `IExecutionContext` exclusivo para o objeto que implementa a interface, antes de usar a interface como parâmetro para métodos fornecidos pelo Gerenciador de recursos. Espera-se que retorne o mesmo `GetId` identificador quando a função for invocada.

Um identificador obtido de uma fonte diferente pode resultar em comportamento indefinido.

## <a name="iexecutioncontextgetproxy-method"></a><a name="getproxy"></a>IExecutionContext::GetProxy Method

Retorna uma interface para o proxy de segmento que está executando este contexto.

```cpp
virtual IThreadProxy* GetProxy() = 0;
```

### <a name="return-value"></a>Valor retornado

Uma interface `IThreadProxy`. Se o proxy de segmento do contexto de execução não tiver sido inicializado com uma chamada para `SetProxy`, a função deve retornar `NULL`.

### <a name="remarks"></a>Comentários

O Gerenciador de `SetProxy` recursos invocará o `IThreadProxy` método em um contexto de `Dispatch` execução, com uma interface como parâmetro, antes de inserir o método no contexto. Espera-se que você armazene este `GetProxy()`argumento e o devolva em chamadas para .

## <a name="iexecutioncontextgetscheduler-method"></a><a name="getscheduler"></a>IExecutionContext::GetScheduler Method

Retorna uma interface ao agendador a que este contexto de execução pertence.

```cpp
virtual IScheduler* GetScheduler() = 0;
```

### <a name="return-value"></a>Valor retornado

Uma interface `IScheduler`.

### <a name="remarks"></a>Comentários

Você é obrigado a inicializar o `IScheduler` contexto de execução com uma interface válida antes de usá-lo como parâmetro para métodos fornecidos pelo Gerenciador de recursos.

## <a name="iexecutioncontextsetproxy-method"></a><a name="setproxy"></a>IExecutionContext::SetProxy Method

Associa um proxy de segmento a este contexto de execução. O proxy de segmento associado invoca esse método antes `Dispatch` de começar a executar o método do contexto.

```cpp
virtual void SetProxy(_Inout_ IThreadProxy* pThreadProxy) = 0;
```

### <a name="parameters"></a>Parâmetros

*pThreadProxy*<br/>
Uma interface para o proxy thread `Dispatch` que está prestes a inserir o método neste contexto de execução.

### <a name="remarks"></a>Comentários

Espera-se que você `pThreadProxy` salve o parâmetro e `GetProxy` o devolva em uma chamada para o método. O Gerenciador de recursos garante que o proxy de segmento associado ao `Dispatch` contexto de execução não será altere enquanto o proxy de thread estiver executando o método.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)<br/>
[Estrutura IScheduler](ischeduler-structure.md)<br/>
[Estrutura IThreadProxy](ithreadproxy-structure.md)
