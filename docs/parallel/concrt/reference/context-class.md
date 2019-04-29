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
ms.openlocfilehash: 9074dad572a3a74a5b456e9790dc359ddf8b7c60
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62262743"
---
# <a name="context-class"></a>Classe Context

Representa uma abstração para um contexto de execução.

## <a name="syntax"></a>Sintaxe

```
class Context;
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[~ Destruidor contexto](#dtor)||

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Bloco](#block)|Bloqueia o contexto atual.|
|[CurrentContext](#currentcontext)|Retorna um ponteiro para o contexto atual.|
|[GetId](#getid)|Retorna um identificador para o contexto que é exclusivo dentro do Agendador ao qual pertence o contexto.|
|[GetScheduleGroupId](#getschedulegroupid)|Retorna um identificador para o grupo de agendas que o contexto está trabalhando no momento.|
|[GetVirtualProcessorId](#getvirtualprocessorid)|Retorna um identificador para o processador virtual atualmente em execução no contexto.|
|[ID](#id)|Retorna um identificador para o contexto atual que é exclusivo dentro do Agendador ao qual pertence o contexto atual.|
|[IsCurrentTaskCollectionCanceling](#iscurrenttaskcollectioncanceling)|Retorna um valor que indica se a coleção de tarefas que atualmente está em execução inline no contexto atual está no meio de um cancelamento ativo (ou estarão em breve).|
|[IsSynchronouslyBlocked](#issynchronouslyblocked)|Determina se o contexto é bloqueado de forma síncrona. Um contexto é considerado como bloqueado de forma síncrona se executar explicitamente uma ação que resulte em bloqueio.|
|[Subscrever](#oversubscribe)|Injeta um processador virtual adicional em um agendador para a duração de um bloco de código quando chamado em um contexto de execução em um dos processadores virtuais em que o Agendador.|
|[ScheduleGroupId](#schedulegroupid)|Retorna um identificador para o grupo de agendas que o contexto atual está trabalhando.|
|[Desbloquear](#unblock)|Desbloqueia o contexto e faz com que ele se torne executável.|
|[VirtualProcessorId](#virtualprocessorid)|Retorna um identificador para o processador virtual em que o contexto atual está em execução.|
|[Yield](#yield)|Gera a execução para que o outro contexto seja executado. Se nenhum outro contexto estiver disponível para produzir, o Agendador poderá produzir para outro thread do sistema operacional.|

## <a name="remarks"></a>Comentários

O Agendador de tempo de execução de simultaneidade (consulte [Agendador](scheduler-class.md)) usa contextos para executar o trabalho na fila a ele pelo seu aplicativo. Um thread do Win32 é um exemplo de um contexto de execução em um sistema de operacional Windows.

A qualquer momento, o nível de simultaneidade de um agendador é igual ao número de processadores virtuais concedidos a ela pelo Gerenciador de recursos. Um processador virtual é uma abstração para um recurso de processamento e mapeia para um thread de hardware no sistema subjacente. Apenas um único contexto de Agendador pode executar em um processador virtual em um determinado momento.

O Agendador é cooperativo por natureza e um contexto de execução pode render seu processador virtual em um contexto diferente a qualquer momento se desejar entrar em um estado de espera. Quando a espera acaba, ele não pode continuar até que um processador virtual disponível do Agendador comece a executá-lo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Context`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="block"></a> Bloco

Bloqueia o contexto atual.

```
static void __cdecl Block();
```

### <a name="remarks"></a>Comentários

Esse método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada, se não houver nenhum agendador associado atualmente com o contexto de chamada.

Se o contexto de chamada está em execução em um processador virtual, o processador virtual encontrará outro contexto executável para executar ou pode potencialmente criar um novo.

Após o `Block` método foi chamado ou será chamado, ele deve ser emparelhados com uma chamada para o [desbloquear](#unblock) método de outro contexto de execução em ordem para que ele seja executado novamente. Lembre-se de que há um período crítico entre o ponto em que seu código publicar seu contexto para outro thread para ser capaz de chamar o `Unblock` método e o ponto em que o método real é chamada para `Block` é feita. Durante esse período, você não deve chamar qualquer método que por sua vez pode bloquear e desbloquear por seus próprios motivos (por exemplo, adquirir um bloqueio). Chamadas para o `Block` e `Unblock` método não rastrear o motivo para o bloqueio e desbloqueio. Apenas um objeto deve ter a propriedade de um `Block` -  `Unblock` par.

Esse método poderá gerar uma variedade de exceções, incluindo [scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md).

##  <a name="dtor"></a> ~Context

```
virtual ~Context();
```

##  <a name="currentcontext"></a> CurrentContext

Retorna um ponteiro para o contexto atual.

```
static Context* __cdecl CurrentContext();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o contexto atual.

### <a name="remarks"></a>Comentários

Esse método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada, se não houver nenhum agendador associado atualmente com o contexto de chamada.

##  <a name="getid"></a> GetId

Retorna um identificador para o contexto que é exclusivo dentro do Agendador ao qual pertence o contexto.

```
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o contexto que é exclusivo dentro do Agendador ao qual pertence o contexto.

##  <a name="getschedulegroupid"></a> GetScheduleGroupId

Retorna um identificador para o grupo de agendas que o contexto está trabalhando no momento.

```
virtual unsigned int GetScheduleGroupId() const = 0;
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o grupo de agendas que o contexto está trabalhando no momento.

### <a name="remarks"></a>Comentários

O valor de retorno desse método é uma amostragem instantânea do grupo de agendamento que o contexto está em execução. Se esse método for chamado em um contexto diferente do contexto atual, o valor pode ser obsoleto no momento em que ele é retornado e não pode ser utilizado. Normalmente, esse método é usado para depuração ou apenas para fins de rastreamento.

##  <a name="getvirtualprocessorid"></a> GetVirtualProcessorId

Retorna um identificador para o processador virtual atualmente em execução no contexto.

```
virtual unsigned int GetVirtualProcessorId() const = 0;
```

### <a name="return-value"></a>Valor de retorno

Se o contexto no momento está em execução em um processador virtual, um identificador para o processador virtual em que o contexto está sendo executado em; Caso contrário, o valor `-1`.

### <a name="remarks"></a>Comentários

O valor de retorno desse método é uma amostragem instantânea do processador virtual que o contexto está em execução. Esse valor pode ser obsoleto no momento em que ele é retornado e não pode ser utilizado. Normalmente, esse método é usado para depuração ou apenas para fins de rastreamento.

##  <a name="id"></a> Id

Retorna um identificador para o contexto atual que é exclusivo dentro do Agendador ao qual pertence o contexto atual.

```
static unsigned int __cdecl Id();
```

### <a name="return-value"></a>Valor de retorno

Se o contexto atual estiver anexado a um agendador, um identificador para o contexto atual que é exclusivo dentro do Agendador ao qual o contexto atual pertence; Caso contrário, o valor `-1`.

##  <a name="iscurrenttaskcollectioncanceling"></a> IsCurrentTaskCollectionCanceling

Retorna um valor que indica se a coleção de tarefas que atualmente está em execução inline no contexto atual está no meio de um cancelamento ativo (ou estarão em breve).

```
static bool __cdecl IsCurrentTaskCollectionCanceling();
```

### <a name="return-value"></a>Valor de retorno

Se um agendador é anexado ao contexto de chamada e um grupo de tarefas está executando uma tarefa embutida no contexto, indica se esse grupo de tarefas está no meio de um cancelamento ativo (ou estarão em breve); Caso contrário, o valor `false`.

##  <a name="issynchronouslyblocked"></a> IsSynchronouslyBlocked

Determina se o contexto é bloqueado de forma síncrona. Um contexto é considerado como bloqueado de forma síncrona se executar explicitamente uma ação que resulte em bloqueio.

```
virtual bool IsSynchronouslyBlocked() const = 0;
```

### <a name="return-value"></a>Valor de retorno

Se o contexto é bloqueado de forma síncrona.

### <a name="remarks"></a>Comentários

Um contexto é considerado como bloqueado de forma síncrona se executar explicitamente uma ação que resulte em bloqueio. O Agendador de thread, isso indica que uma chamada direta para o `Context::Block` método ou um objeto de sincronização que foi criado usando o `Context::Block` método.

O valor de retorno desse método é um exemplo de instantâneo de se o contexto é bloqueado de forma síncrona. Esse valor pode ser obsoleto no momento em que ele é retornado e só pode ser usado em circunstâncias muito específicas.

##  <a name="operator_delete"></a> operador delete

Um `Context` objeto é destruído internamente pelo tempo de execução. Ele não pode ser explicitamente excluído.

```
void operator delete(void* _PObject);
```

### <a name="parameters"></a>Parâmetros

*_PObject*<br/>
Um ponteiro para o objeto a ser excluído.

##  <a name="oversubscribe"></a> Subscrever

Injeta um processador virtual adicional em um agendador para a duração de um bloco de código quando chamado em um contexto de execução em um dos processadores virtuais em que o Agendador.

```
static void __cdecl Oversubscribe(bool _BeginOversubscription);
```

### <a name="parameters"></a>Parâmetros

*_BeginOversubscription*<br/>
Se **verdadeira**, uma indicação de que um processador virtual adicional deve ser adicionado durante o excesso de assinatura. Se **falsos**, uma indicação de que o excesso de assinatura deve terminar e o processador virtual adicionado anteriormente deve ser removido.

##  <a name="schedulegroupid"></a> ScheduleGroupId

Retorna um identificador para o grupo de agendas que o contexto atual está trabalhando.

```
static unsigned int __cdecl ScheduleGroupId();
```

### <a name="return-value"></a>Valor de retorno

Se o contexto atual está conectado a um agendador e trabalhando em um grupo de agendas, um identificador para o Agendador de grupo que o contexto atual está trabalhando em; Caso contrário, o valor `-1`.

##  <a name="unblock"></a> Desbloquear

Desbloqueia o contexto e faz com que ele se torne executável.

```
virtual void Unblock() = 0;
```

### <a name="remarks"></a>Comentários

É permitido para uma chamada para o `Unblock` método antes de uma chamada correspondente para o [bloco](#block) método. Desde que as chamadas para o `Block` e `Unblock` métodos estão emparelhados corretamente, o tempo de execução manipula corretamente a corrida natural de qualquer ordenação. Uma `Unblock` chamada antes de uma `Block` chamada simplesmente anula o efeito do `Block` chamar.

Existem diversas exceções que podem ser geradas do método. Se um contexto tenta chamar o `Unblock` método em si, uma [context_self_unblock](context-self-unblock-class.md) exceção será lançada. Se chamadas para `Block` e `Unblock` não são emparelhados corretamente (por exemplo, duas chamadas para `Unblock` são feitas para um contexto que está sendo executado), um [context_unblock_unbalanced](context-unblock-unbalanced-class.md) exceção será lançada.

Lembre-se de que há um período crítico entre o ponto em que seu código publicar seu contexto para outro thread para ser capaz de chamar o `Unblock` método e o ponto em que o método real é chamada para `Block` é feita. Durante esse período, você não deve chamar qualquer método que por sua vez pode bloquear e desbloquear por seus próprios motivos (por exemplo, adquirir um bloqueio). Chamadas para o `Block` e `Unblock` método não rastrear o motivo para o bloqueio e desbloqueio. Apenas um objeto deve ter a propriedade de um `Block` e `Unblock` par.

##  <a name="virtualprocessorid"></a> VirtualProcessorId

Retorna um identificador para o processador virtual em que o contexto atual está em execução.

```
static unsigned int __cdecl VirtualProcessorId();
```

### <a name="return-value"></a>Valor de retorno

Se o contexto atual estiver anexado a um agendador, um identificador para o processador virtual em que o contexto atual está em execução; Caso contrário, o valor `-1`.

### <a name="remarks"></a>Comentários

O valor de retorno desse método é uma amostragem instantânea do processador virtual que o contexto atual está em execução. Esse valor pode ser obsoleto no momento em que ele é retornado e não pode ser utilizado. Normalmente, esse método é usado para depuração ou apenas para fins de rastreamento.

##  <a name="yield"></a> yield

Gera a execução para que o outro contexto seja executado. Se nenhum outro contexto estiver disponível para produzir, o Agendador poderá produzir para outro thread do sistema operacional.

```
static void __cdecl Yield();
```

### <a name="remarks"></a>Comentários

Esse método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada, se não houver nenhum agendador associado atualmente com o contexto de chamada.

##  <a name="yieldexecution"></a> YieldExecution

Gera a execução para que o outro contexto seja executado. Se nenhum outro contexto estiver disponível para produzir, o Agendador poderá produzir para outro thread do sistema operacional.

```
static void __cdecl YieldExecution();
```

### <a name="remarks"></a>Comentários

Esse método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada, se não houver nenhum agendador associado atualmente com o contexto de chamada.

Essa função é nova no Visual Studio 2015 e é idêntica do [Yield](#yield) funcionar, mas não entra em conflito com a macro Yield no Windows. h.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Scheduler](scheduler-class.md)<br/>
[Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)
