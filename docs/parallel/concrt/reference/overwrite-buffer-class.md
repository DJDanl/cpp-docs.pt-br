---
title: Classe overwrite_buffer
ms.date: 11/04/2016
f1_keywords:
- overwrite_buffer
- AGENTS/concurrency::overwrite_buffer
- AGENTS/concurrency::overwrite_buffer::overwrite_buffer
- AGENTS/concurrency::overwrite_buffer::has_value
- AGENTS/concurrency::overwrite_buffer::value
- AGENTS/concurrency::overwrite_buffer::accept_message
- AGENTS/concurrency::overwrite_buffer::consume_message
- AGENTS/concurrency::overwrite_buffer::link_target_notification
- AGENTS/concurrency::overwrite_buffer::propagate_message
- AGENTS/concurrency::overwrite_buffer::propagate_to_any_targets
- AGENTS/concurrency::overwrite_buffer::release_message
- AGENTS/concurrency::overwrite_buffer::reserve_message
- AGENTS/concurrency::overwrite_buffer::resume_propagation
- AGENTS/concurrency::overwrite_buffer::send_message
- AGENTS/concurrency::overwrite_buffer::supports_anonymous_source
helpviewer_keywords:
- overwrite_buffer class
ms.assetid: 5cc428fe-3697-419c-9fb2-78f6181c9293
ms.openlocfilehash: 7579ee4b9c650b0fe707eccb0f8c2b67a3efac14
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231683"
---
# <a name="overwrite_buffer-class"></a>Classe overwrite_buffer

Um `overwrite_buffer` bloco de mensagens é um recurso de vários destinos, várias fontes, ordenado, `propagator_block` capaz de armazenar uma única mensagem por vez. Novas mensagens substituem as mantidas anteriormente.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
class overwrite_buffer : public propagator_block<multi_link_registry<ITarget<T>>, multi_link_registry<ISource<T>>>;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de carga das mensagens armazenadas e propagadas pelo buffer.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[overwrite_buffer](#ctor)|Sobrecarregado. Constrói um `overwrite_buffer` bloco de mensagens.|
|[~ overwrite_buffer destruidor](#dtor)|Destrói o `overwrite_buffer` bloco de mensagens.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[has_value](#has_value)|Verifica se este `overwrite_buffer` bloco de mensagens tem um valor ainda.|
|[value](#value)|Obtém uma referência à carga atual da mensagem que está sendo armazenada no `overwrite_buffer` bloco de mensagens.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Aceita uma mensagem que foi oferecida por este `overwrite_buffer` bloco de mensagens, retornando uma cópia da mensagem para o chamador.|
|[consume_message](#consume_message)|Consome uma mensagem fornecida anteriormente pelo bloco de `overwrite_buffer` mensagens e reservada pelo destino, retornando uma cópia da mensagem para o chamador.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `overwrite_buffer` bloco de mensagens.|
|[propagate_message](#propagate_message)|Transmite de forma assíncrona uma mensagem de um `ISource` bloco para esse `overwrite_buffer` bloco de mensagens. Ele é invocado pelo `propagate` método, quando chamado por um bloco de origem.|
|[propagate_to_any_targets](#propagate_to_any_targets)|Coloca o `message _PMessage` nesse `overwrite_buffer` bloco de mensagens e o oferece a todos os destinos vinculados.|
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|
|[reserve_message](#reserve_message)|Reserva uma mensagem oferecida anteriormente por este `overwrite_buffer` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|
|[resume_propagation](#resume_propagation)|Retoma a propagação após a liberação de uma reserva. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|
|[send_message](#send_message)|Transmite de forma síncrona uma mensagem de um `ISource` bloco para esse `overwrite_buffer` bloco de mensagens. Ele é invocado pelo `send` método, quando chamado por um bloco de origem.|
|[supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que esse bloco pode aceitar mensagens oferecidas por uma fonte que não está vinculada. (Substitui [ITarget:: supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|

## <a name="remarks"></a>Comentários

Um `overwrite_buffer` bloco de mensagens propaga cópias de sua mensagem armazenada para cada um de seus destinos.

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[As](isource-class.md)

[ITarget](itarget-class.md)

[source_block](source-block-class.md)

[propagator_block](propagator-block-class.md)

`overwrite_buffer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept_message"></a><a name="accept_message"></a>accept_message

Aceita uma mensagem que foi oferecida por este `overwrite_buffer` bloco de mensagens, retornando uma cópia da mensagem para o chamador.

```cpp
virtual message<T>* accept_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto oferecido `message` .

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

O `overwrite_buffer` bloco de mensagens retorna cópias da mensagem para seus destinos, em vez de transferir a propriedade da mensagem atualmente armazenada.

## <a name="consume_message"></a><a name="consume_message"></a>consume_message

Consome uma mensagem fornecida anteriormente pelo bloco de `overwrite_buffer` mensagens e reservada pelo destino, retornando uma cópia da mensagem para o chamador.

```cpp
virtual message<T>* consume_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo consumido.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

Semelhante a `accept` , mas é sempre precedido por uma chamada para `reserve` .

## <a name="has_value"></a><a name="has_value"></a>has_value

Verifica se este `overwrite_buffer` bloco de mensagens tem um valor ainda.

```cpp
bool has_value() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o bloco tiver recebido um valor, **`false`** caso contrário.

## <a name="link_target_notification"></a><a name="link_target_notification"></a>link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a este `overwrite_buffer` bloco de mensagens.

```cpp
virtual void link_target_notification(_Inout_ ITarget<T>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para o destino vinculado recentemente.

## <a name="overwrite_buffer"></a><a name="dtor"></a>~ overwrite_buffer

Destrói o `overwrite_buffer` bloco de mensagens.

```cpp
~overwrite_buffer();
```

## <a name="overwrite_buffer"></a><a name="ctor"></a>overwrite_buffer

Constrói um `overwrite_buffer` bloco de mensagens.

```cpp
overwrite_buffer();

overwrite_buffer(
    filter_method const& _Filter);

overwrite_buffer(
    Scheduler& _PScheduler);

overwrite_buffer(
    Scheduler& _PScheduler,
    filter_method const& _Filter);

overwrite_buffer(
    ScheduleGroup& _PScheduleGroup);

overwrite_buffer(
    ScheduleGroup& _PScheduleGroup,
    filter_method const& _Filter);
```

### <a name="parameters"></a>parâmetros

*_Filter*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.

*_PScheduler*<br/>
O `Scheduler` objeto no qual a tarefa de propagação para o `overwrite_buffer` bloco de mensagens está agendada.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto no qual a tarefa de propagação para o `overwrite_buffer` bloco de mensagens está agendada. O `Scheduler` objeto usado é implícito pelo grupo de agendamento.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os `_PScheduler` `_PScheduleGroup` parâmetros ou.

O tipo `filter_method` é um functor com assinatura `bool (T const &)` que é invocada por esse `overwrite_buffer` bloco de mensagens para determinar se ele deve ou não aceitar uma mensagem oferecida.

## <a name="propagate_message"></a><a name="propagate_message"></a>propagate_message

Transmite de forma assíncrona uma mensagem de um `ISource` bloco para esse `overwrite_buffer` bloco de mensagens. Ele é invocado pelo `propagate` método, quando chamado por um bloco de origem.

```cpp
virtual message_status propagate_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md) do que o destino decidiu fazer com a mensagem.

## <a name="propagate_to_any_targets"></a><a name="propagate_to_any_targets"></a>propagate_to_any_targets

Coloca o `message _PMessage` nesse `overwrite_buffer` bloco de mensagens e o oferece a todos os destinos vinculados.

```cpp
virtual void propagate_to_any_targets(_Inout_ message<T>* _PMessage);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para um `message` objeto que `overwrite_buffer` tem a propriedade assumida.

### <a name="remarks"></a>Comentários

Esse método substitui a mensagem atual no `overwrite_buffer` pelo com a mensagem recém aceita `_PMessage` .

## <a name="send_message"></a><a name="send_message"></a>send_message

Transmite de forma síncrona uma mensagem de um `ISource` bloco para esse `overwrite_buffer` bloco de mensagens. Ele é invocado pelo `send` método, quando chamado por um bloco de origem.

```cpp
virtual message_status send_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md) do que o destino decidiu fazer com a mensagem.

## <a name="supports_anonymous_source"></a><a name="supports_anonymous_source"></a>supports_anonymous_source

Substitui o `supports_anonymous_source` método para indicar que esse bloco pode aceitar mensagens oferecidas por uma fonte que não está vinculada.

```cpp
virtual bool supports_anonymous_source();
```

### <a name="return-value"></a>Valor retornado

**`true`** Porque o bloco não adia mensagens oferecidas.

## <a name="release_message"></a><a name="release_message"></a>release_message

Libera uma reserva de mensagem anterior.

```cpp
virtual void release_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo liberado.

## <a name="reserve_message"></a><a name="reserve_message"></a>reserve_message

Reserva uma mensagem oferecida anteriormente por este `overwrite_buffer` bloco de mensagens.

```cpp
virtual bool reserve_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo reservado.

### <a name="return-value"></a>Valor retornado

**`true`** se a mensagem tiver sido reservada com êxito, **`false`** caso contrário.

### <a name="remarks"></a>Comentários

After `reserve` é chamado, se ele retornar **`true`** , `consume` ou `release` deve ser chamado para tirar ou liberar a propriedade da mensagem.

## <a name="resume_propagation"></a><a name="resume_propagation"></a>resume_propagation

Retoma a propagação após a liberação de uma reserva.

```cpp
virtual void resume_propagation();
```

## <a name="value"></a><a name="value"></a> valor

Obtém uma referência à carga atual da mensagem que está sendo armazenada no `overwrite_buffer` bloco de mensagens.

```cpp
T value();
```

### <a name="return-value"></a>Valor retornado

A carga da mensagem armazenada no momento.

### <a name="remarks"></a>Comentários

O valor armazenado no `overwrite_buffer` pode ser alterado imediatamente após o retorno desse método. Esse método aguardará até que uma mensagem chegue se nenhuma mensagem estiver armazenada no momento no `overwrite_buffer` .

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe unbounded_buffer](unbounded-buffer-class.md)<br/>
[Classe single_assignment](single-assignment-class.md)
