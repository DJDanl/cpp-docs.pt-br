---
title: Classe Context
ms.date: 11/04/2016
f1_keywords:
- Context
- CONCRT/concurrency::Context
- CONCRT/concurrency::Context::Block
- CONCRT/concurrency::Context::CurrentContext
- CONCRT/concurrency::Context::GetId
- CONCRT/concurrency::Context::GetScheduleGroupId
- CONCRT/concurrency::Context::GetVirtualProcessorId
- CONCRT/concurrency::Context::Id
- CONCRT/concurrency::Context::IsCurrentTaskCollectionCanceling
- CONCRT/concurrency::Context::IsSynchronouslyBlocked
- CONCRT/concurrency::Context::Oversubscribe
- CONCRT/concurrency::Context::ScheduleGroupId
- CONCRT/concurrency::Context::Unblock
- CONCRT/concurrency::Context::VirtualProcessorId
- CONCRT/concurrency::Context::Yield
helpviewer_keywords:
- Context class
ms.assetid: c0d553f3-961d-4ecd-9a29-4fa4351673b8
ms.openlocfilehash: 7c47d9db64b0af7d5413abed3f85e9d41a591fa2
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79422174"
---
# <a name="context-class"></a>Classe Context

Representa uma abstração para um contexto de execução.

## <a name="syntax"></a>Sintaxe

```cpp
class Context;
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[~ Destruidor de contexto](#dtor)||

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Bloco](#block)|Bloqueia o contexto atual.|
|[CurrentContext](#currentcontext)|Retorna um ponteiro para o contexto atual.|
|[GetId](#getid)|Retorna um identificador para o contexto que é exclusivo dentro do Agendador ao qual o contexto pertence.|
|[GetScheduleGroupId](#getschedulegroupid)|Retorna um identificador para o grupo de agenda no qual o contexto está trabalhando no momento.|
|[GetVirtualProcessorId](#getvirtualprocessorid)|Retorna um identificador para o processador virtual no qual o contexto está sendo executado no momento.|
|[Id](#id)|Retorna um identificador para o contexto atual que é exclusivo dentro do Agendador ao qual o contexto atual pertence.|
|[IsCurrentTaskCollectionCanceling](#iscurrenttaskcollectioncanceling)|Retorna uma indicação de se a coleção de tarefas que está atualmente em execução embutida no contexto atual está no meio de um cancelamento ativo (ou será em breve).|
|[IsSynchronouslyBlocked](#issynchronouslyblocked)|Determina se o contexto está bloqueado de forma síncrona ou não. Um contexto é considerado como bloqueado de forma síncrona se ele executa explicitamente uma ação que levou ao bloqueio.|
|[Subscrever](#oversubscribe)|Injeta um processador virtual adicional em um Agendador pela duração de um bloco de código quando invocado em um contexto em execução em um dos processadores virtuais nesse Agendador.|
|[ScheduleGroupId](#schedulegroupid)|Retorna um identificador para o grupo de agenda no qual o contexto atual está trabalhando.|
|[Bloqueá](#unblock)|Desbloqueia o contexto e faz com que ele se torne executável.|
|[VirtualProcessorId](#virtualprocessorid)|Retorna um identificador para o processador virtual no qual o contexto atual está sendo executado.|
|[Yield](#yield)|Produz a execução para que outro contexto possa ser executado. Se nenhum outro contexto estiver disponível para gerar, o Agendador poderá gerar um outro thread do sistema operacional.|

## <a name="remarks"></a>Comentários

O Agendador de Tempo de Execução de Simultaneidade (consulte o [Agendador](scheduler-class.md)) usa contextos de execução para executar o trabalho na fila para ele pelo seu aplicativo. Um Thread Win32 é um exemplo de um contexto de execução em um sistema operacional Windows.

A qualquer momento, o nível de simultaneidade de um Agendador é igual ao número de processadores virtuais concedidos a ele pelo Gerenciador de recursos. Um processador virtual é uma abstração para um recurso de processamento e é mapeado para um thread de hardware no sistema subjacente. Apenas um único contexto de Agendador pode ser executado em um processador virtual em um determinado momento.

O Agendador é cooperativa por natureza e um contexto em execução pode gerar seu processador virtual para um contexto diferente a qualquer momento, caso queira entrar em um estado de espera. Quando sua espera de satisfação, ela não pode continuar até que um processador virtual disponível do Agendador comece a executá-lo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Context`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="block"></a>Impeça

Bloqueia o contexto atual.

```cpp
static void __cdecl Block();
```

### <a name="remarks"></a>Comentários

Esse método fará com que o agendador padrão do processo seja criado e/ou anexado ao contexto de chamada se não houver um Agendador associado ao contexto de chamada no momento.

Se o contexto de chamada estiver sendo executado em um processador virtual, o processador virtual encontrará outro contexto executável para executar ou pode potencialmente criar um novo.

Depois que o método de `Block` foi chamado ou será chamado, você deve emparelhar com uma chamada para o método de [desbloqueio](#unblock) de outro contexto de execução para que ele seja executado novamente. Lembre-se de que há um período crítico entre o ponto em que o código publica seu contexto para outro thread para poder chamar o método `Unblock` e o ponto em que a chamada de método real para `Block` é feita. Durante esse período, você não deve chamar nenhum método que, por sua vez, pode bloquear e desbloquear por seus próprios motivos (por exemplo, adquirir um bloqueio). As chamadas para o método `Block` e `Unblock` não controlam o motivo do bloqueio e desbloqueio. Somente um objeto deve ter a propriedade de um `Block`- `Unblock` par.

Esse método pode lançar uma variedade de exceções, incluindo [scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md).

## <a name="dtor"></a>~ Contexto

```cpp
virtual ~Context();
```

## <a name="currentcontext"></a>CurrentContext

Retorna um ponteiro para o contexto atual.

```cpp
static Context* __cdecl CurrentContext();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o contexto atual.

### <a name="remarks"></a>Comentários

Esse método fará com que o agendador padrão do processo seja criado e/ou anexado ao contexto de chamada se não houver um Agendador associado ao contexto de chamada no momento.

## <a name="getid"></a>GetId

Retorna um identificador para o contexto que é exclusivo dentro do Agendador ao qual o contexto pertence.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador para o contexto que é exclusivo dentro do Agendador ao qual o contexto pertence.

## <a name="getschedulegroupid"></a>GetScheduleGroupId

Retorna um identificador para o grupo de agenda no qual o contexto está trabalhando no momento.

```cpp
virtual unsigned int GetScheduleGroupId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador para o grupo de agenda no qual o contexto está trabalhando no momento.

### <a name="remarks"></a>Comentários

O valor de retorno desse método é uma amostragem instantânea do grupo de agendamento no qual o contexto está sendo executado. Se esse método for chamado em um contexto diferente do contexto atual, o valor poderá ser obsoleto no momento em que é retornado e não pode ser confiado. Normalmente, esse método é usado apenas para fins de depuração ou rastreamento.

## <a name="getvirtualprocessorid"></a>GetVirtualProcessorId

Retorna um identificador para o processador virtual no qual o contexto está sendo executado no momento.

```cpp
virtual unsigned int GetVirtualProcessorId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Se o contexto estiver sendo executado em um processador virtual, um identificador para o processador virtual no qual o contexto está sendo executado no momento; caso contrário, o valor `-1`.

### <a name="remarks"></a>Comentários

O valor de retorno desse método é uma amostragem instantânea do processador virtual em que o contexto está sendo executado. Esse valor pode ser obsoleto no momento em que é retornado e não pode ser confiado. Normalmente, esse método é usado apenas para fins de depuração ou rastreamento.

## <a name="id"></a>Sessão

Retorna um identificador para o contexto atual que é exclusivo dentro do Agendador ao qual o contexto atual pertence.

```cpp
static unsigned int __cdecl Id();
```

### <a name="return-value"></a>Valor retornado

Se o contexto atual for anexado a um Agendador, um identificador para o contexto atual que é exclusivo dentro do Agendador ao qual o contexto atual pertence; caso contrário, o valor `-1`.

## <a name="iscurrenttaskcollectioncanceling"></a>IsCurrentTaskCollectionCanceling

Retorna uma indicação de se a coleção de tarefas que está atualmente em execução embutida no contexto atual está no meio de um cancelamento ativo (ou será em breve).

```cpp
static bool __cdecl IsCurrentTaskCollectionCanceling();
```

### <a name="return-value"></a>Valor retornado

Se um Agendador estiver anexado ao contexto de chamada e um grupo de tarefas estiver executando uma tarefa embutida nesse contexto, uma indicação de se esse grupo de tarefas está no meio de um cancelamento ativo (ou será em breve); caso contrário, o valor `false`.

## <a name="issynchronouslyblocked"></a>IsSynchronouslyBlocked

Determina se o contexto está bloqueado de forma síncrona ou não. Um contexto é considerado como bloqueado de forma síncrona se ele executa explicitamente uma ação que levou ao bloqueio.

```cpp
virtual bool IsSynchronouslyBlocked() const = 0;
```

### <a name="return-value"></a>Valor retornado

Se o contexto está bloqueado de forma síncrona.

### <a name="remarks"></a>Comentários

Um contexto é considerado como bloqueado de forma síncrona se ele executa explicitamente uma ação que levou ao bloqueio. No Agendador de threads, isso indica uma chamada direta para o método `Context::Block` ou um objeto de sincronização que foi criado usando o método `Context::Block`.

O valor de retorno desse método é um exemplo instantâneo que indica se o contexto está bloqueado de forma síncrona. Esse valor pode estar obsoleto no momento em que é retornado e só pode ser usado em circunstâncias muito específicas.

## <a name="operator_delete"></a>operador Delete

Um objeto `Context` é destruído internamente pelo tempo de execução. Ele não pode ser excluído explicitamente.

```cpp
void operator delete(void* _PObject);
```

### <a name="parameters"></a>parâmetros

*_PObject*<br/>
Um ponteiro para o objeto a ser excluído.

## <a name="oversubscribe"></a>Subscrever

Injeta um processador virtual adicional em um Agendador pela duração de um bloco de código quando invocado em um contexto em execução em um dos processadores virtuais nesse Agendador.

```cpp
static void __cdecl Oversubscribe(bool _BeginOversubscription);
```

### <a name="parameters"></a>parâmetros

*_BeginOversubscription*<br/>
Se **for true**, uma indicação de que um processador virtual extra deve ser adicionado durante a assinatura em excesso. Se **for false**, uma indicação de que a assinatura deve terminar e o processador virtual adicionado anteriormente deve ser removido.

## <a name="schedulegroupid"></a>ScheduleGroupId

Retorna um identificador para o grupo de agenda no qual o contexto atual está trabalhando.

```cpp
static unsigned int __cdecl ScheduleGroupId();
```

### <a name="return-value"></a>Valor retornado

Se o contexto atual for anexado a um Agendador e estiver trabalhando em um grupo de agendamento, um identificador para o grupo do Agendador no qual o contexto atual está trabalhando; caso contrário, o valor `-1`.

## <a name="unblock"></a>Bloqueá

Desbloqueia o contexto e faz com que ele se torne executável.

```cpp
virtual void Unblock() = 0;
```

### <a name="remarks"></a>Comentários

É perfeitamente legal que uma chamada para o método `Unblock` venha antes de uma chamada correspondente ao método [Block](#block) . Desde que as chamadas para os métodos `Block` e `Unblock` sejam emparelhadas adequadamente, o tempo de execução lida corretamente com a corrida natural de qualquer ordem. Uma chamada de `Unblock` que chega antes de uma chamada de `Block` simplesmente nega o efeito da chamada de `Block`.

Há várias exceções que podem ser geradas desse método. Se um contexto tentar chamar o método `Unblock` sozinho, uma exceção de [context_self_unblock](context-self-unblock-class.md) será lançada. Se as chamadas para `Block` e `Unblock` não forem emparelhadas corretamente (por exemplo, duas chamadas para `Unblock` são feitas para um contexto que está em execução no momento), uma exceção de [context_unblock_unbalanced](context-unblock-unbalanced-class.md) será lançada.

Lembre-se de que há um período crítico entre o ponto em que o código publica seu contexto para outro thread para poder chamar o método `Unblock` e o ponto em que a chamada de método real para `Block` é feita. Durante esse período, você não deve chamar nenhum método que, por sua vez, pode bloquear e desbloquear por seus próprios motivos (por exemplo, adquirir um bloqueio). As chamadas para o método `Block` e `Unblock` não controlam o motivo do bloqueio e desbloqueio. Somente um objeto deve ter propriedade de um par de `Block` e de `Unblock`.

## <a name="virtualprocessorid"></a>VirtualProcessorId

Retorna um identificador para o processador virtual no qual o contexto atual está sendo executado.

```cpp
static unsigned int __cdecl VirtualProcessorId();
```

### <a name="return-value"></a>Valor retornado

Se o contexto atual estiver anexado a um Agendador, um identificador para o processador virtual no qual o contexto atual está sendo executado; caso contrário, o valor `-1`.

### <a name="remarks"></a>Comentários

O valor de retorno desse método é uma amostragem instantânea do processador virtual em que o contexto atual está sendo executado. Esse valor pode ser obsoleto no momento em que é retornado e não pode ser confiado. Normalmente, esse método é usado apenas para fins de depuração ou rastreamento.

## <a name="yield"></a>Proporcionar

Produz a execução para que outro contexto possa ser executado. Se nenhum outro contexto estiver disponível para gerar, o Agendador poderá gerar um outro thread do sistema operacional.

```cpp
static void __cdecl Yield();
```

### <a name="remarks"></a>Comentários

Esse método fará com que o agendador padrão do processo seja criado e/ou anexado ao contexto de chamada se não houver um Agendador associado ao contexto de chamada no momento.

## <a name="yieldexecution"></a>YieldExecution

Produz a execução para que outro contexto possa ser executado. Se nenhum outro contexto estiver disponível para gerar, o Agendador poderá gerar um outro thread do sistema operacional.

```cpp
static void __cdecl YieldExecution();
```

### <a name="remarks"></a>Comentários

Esse método fará com que o agendador padrão do processo seja criado e/ou anexado ao contexto de chamada se não houver um Agendador associado ao contexto de chamada no momento.

Essa função é nova no Visual Studio 2015 e é idêntica à função [yield](#yield) , mas não entra em conflito com a macro yield em Windows. h.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Scheduler](scheduler-class.md)<br/>
[Agendador de Tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)
