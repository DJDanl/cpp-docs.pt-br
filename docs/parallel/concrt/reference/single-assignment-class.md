---
title: Classe single_assignment
ms.date: 11/04/2016
f1_keywords:
- single_assignment
- AGENTS/concurrency::single_assignment
- AGENTS/concurrency::single_assignment::single_assignment
- AGENTS/concurrency::single_assignment::has_value
- AGENTS/concurrency::single_assignment::value
- AGENTS/concurrency::single_assignment::accept_message
- AGENTS/concurrency::single_assignment::consume_message
- AGENTS/concurrency::single_assignment::link_target_notification
- AGENTS/concurrency::single_assignment::propagate_message
- AGENTS/concurrency::single_assignment::propagate_to_any_targets
- AGENTS/concurrency::single_assignment::release_message
- AGENTS/concurrency::single_assignment::reserve_message
- AGENTS/concurrency::single_assignment::resume_propagation
- AGENTS/concurrency::single_assignment::send_message
helpviewer_keywords:
- single_assignment class
ms.assetid: ccc34728-8de9-4e07-b83d-a36a58d9d2b9
ms.openlocfilehash: 0d302f4f7f85737d9c3b2368e3ae04d88bc1a370
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142732"
---
# <a name="single_assignment-class"></a>Classe single_assignment

Um `single_assignment` bloco de mensagens é um `propagator_block` de vários destinos, com várias origens e ordenados, capaz de armazenar um único `message`de gravação única.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
class single_assignment : public propagator_block<multi_link_registry<ITarget<T>>, multi_link_registry<ISource<T>>>;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de carga da mensagem armazenada e propagada pelo buffer.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[single_assignment](#ctor)|Sobrecarregado. Constrói um bloco de mensagens `single_assignment`.|
|[~ single_assignment destruidor](#dtor)|Destrói o bloco de mensagens `single_assignment`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[has_value](#has_value)|Verifica se este `single_assignment` bloco de mensagens foi inicializado com um valor ainda.|
|[value](#value)|Obtém uma referência à carga atual da mensagem que está sendo armazenada no bloco de mensagens `single_assignment`.|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Aceita uma mensagem que foi oferecida por esse `single_assignment` bloco de mensagens, retornando uma cópia da mensagem para o chamador.|
|[consume_message](#consume_message)|Consome uma mensagem oferecida anteriormente pelo `single_assignment` e reservada pelo destino, retornando uma cópia da mensagem para o chamador.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a esse `single_assignment` bloco de mensagens.|
|[propagate_message](#propagate_message)|Transmite de forma assíncrona uma mensagem de um bloco de `ISource` para esse `single_assignment` bloco de mensagens. Ele é invocado pelo método `propagate`, quando chamado por um bloco de origem.|
|[propagate_to_any_targets](#propagate_to_any_targets)|Coloca a `message _PMessage` neste bloco de mensagens `single_assignment` e a oferece a todos os destinos vinculados.|
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|
|[reserve_message](#reserve_message)|Reserva uma mensagem oferecida anteriormente por este `single_assignment` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|
|[resume_propagation](#resume_propagation)|Retoma a propagação após a liberação de uma reserva. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|
|[send_message](#send_message)|Transmite de forma síncrona uma mensagem de um bloco de `ISource` para esse `single_assignment` bloco de mensagens. Ele é invocado pelo método `send`, quando chamado por um bloco de origem.|

## <a name="remarks"></a>Comentários

Um `single_assignment` bloco de mensagens propaga cópias de sua mensagem para cada destino.

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[As](isource-class.md)

[ITarget](itarget-class.md)

[source_block](source-block-class.md)

[propagator_block](propagator-block-class.md)

`single_assignment`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept_message"></a>accept_message

Aceita uma mensagem que foi oferecida por esse `single_assignment` bloco de mensagens, retornando uma cópia da mensagem para o chamador.

```cpp
virtual message<T>* accept_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto `message` oferecido.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto de `message` ao qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

O `single_assignment` bloco de mensagens retorna cópias da mensagem para seus destinos, em vez de transferir a propriedade da mensagem atualmente armazenada.

## <a name="consume_message"></a>consume_message

Consome uma mensagem oferecida anteriormente pelo `single_assignment` e reservada pelo destino, retornando uma cópia da mensagem para o chamador.

```cpp
virtual message<T>* consume_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
A `runtime_object_identity` do objeto `message` que está sendo consumido.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto de `message` ao qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

Semelhante a `accept`, mas é sempre precedido por uma chamada para `reserve`.

## <a name="has_value"></a>has_value

Verifica se este `single_assignment` bloco de mensagens foi inicializado com um valor ainda.

```cpp
bool has_value() const;
```

### <a name="return-value"></a>Valor retornado

**true** se o bloco tiver recebido um valor; caso contrário, **false** .

## <a name="link_target_notification"></a>link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a esse `single_assignment` bloco de mensagens.

```cpp
virtual void link_target_notification(_Inout_ ITarget<T>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o destino vinculado recentemente.

## <a name="propagate_message"></a>propagate_message

Transmite de forma assíncrona uma mensagem de um bloco de `ISource` para esse `single_assignment` bloco de mensagens. Ele é invocado pelo método `propagate`, quando chamado por um bloco de origem.

```cpp
virtual message_status propagate_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md) do que o destino decidiu fazer com a mensagem.

## <a name="propagate_to_any_targets"></a>propagate_to_any_targets

Coloca o `message` `_PMessage` neste `single_assignment` bloco de mensagens e o oferece a todos os destinos vinculados.

```cpp
virtual void propagate_to_any_targets(_Inout_opt_ message<T>* _PMessage);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para um `message` que esse `single_assignment` bloco de mensagens assumiu a propriedade.

## <a name="release_message"></a>release_message

Libera uma reserva de mensagem anterior.

```cpp
virtual void release_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto de `message` que está sendo liberado.

## <a name="reserve_message"></a>reserve_message

Reserva uma mensagem oferecida anteriormente por este `single_assignment` bloco de mensagens.

```cpp
virtual bool reserve_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto de `message` que está sendo reservado.

### <a name="return-value"></a>Valor retornado

**true** se a mensagem tiver sido reservada com êxito; caso contrário, **false** .

### <a name="remarks"></a>Comentários

Depois que `reserve` for chamado, se ele retornar **true**, `consume` ou `release` deverá ser chamado para tirar ou liberar a propriedade da mensagem.

## <a name="resume_propagation"></a>resume_propagation

Retoma a propagação após a liberação de uma reserva.

```cpp
virtual void resume_propagation();
```

## <a name="send_message"></a>send_message

Transmite de forma síncrona uma mensagem de um bloco de `ISource` para esse `single_assignment` bloco de mensagens. Ele é invocado pelo método `send`, quando chamado por um bloco de origem.

```cpp
virtual message_status send_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md) do que o destino decidiu fazer com a mensagem.

## <a name="ctor"></a>single_assignment

Constrói um bloco de mensagens `single_assignment`.

```cpp
single_assignment();

single_assignment(
    filter_method const& _Filter);

single_assignment(
    Scheduler& _PScheduler);

single_assignment(
    Scheduler& _PScheduler,
    filter_method const& _Filter);

single_assignment(
    ScheduleGroup& _PScheduleGroup);

single_assignment(
    ScheduleGroup& _PScheduleGroup,
    filter_method const& _Filter);
```

### <a name="parameters"></a>Parâmetros

*_Filter*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.

*_PScheduler*<br/>
O objeto `Scheduler` no qual a tarefa de propagação para o `single_assignment` bloco de mensagens está agendada.

*_PScheduleGroup*<br/>
O objeto `ScheduleGroup` no qual a tarefa de propagação para o `single_assignment` bloco de mensagens está agendada. O objeto de `Scheduler` usado é implícito pelo grupo de agendamento.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os parâmetros `_PScheduler` ou `_PScheduleGroup`.

O tipo `filter_method` é um functor com assinatura `bool (T const &)` que é invocado por esse `single_assignment` bloco de mensagens para determinar se ele deve ou não aceitar uma mensagem oferecida.

## <a name="dtor"></a>~ single_assignment

Destrói o bloco de mensagens `single_assignment`.

```cpp
~single_assignment();
```

## <a name="value"></a>valor

Obtém uma referência à carga atual da mensagem que está sendo armazenada no bloco de mensagens `single_assignment`.

```cpp
T const& value();
```

### <a name="return-value"></a>Valor retornado

A carga da mensagem armazenada.

### <a name="remarks"></a>Comentários

Esse método aguardará até que uma mensagem chegue se nenhuma mensagem estiver armazenada atualmente no bloco de mensagens `single_assignment`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe overwrite_buffer](overwrite-buffer-class.md)<br/>
[Classe unbounded_buffer](unbounded-buffer-class.md)
