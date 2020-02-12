---
title: classe unbounded_buffer
ms.date: 11/04/2016
f1_keywords:
- unbounded_buffer
- AGENTS/concurrency::unbounded_buffer
- AGENTS/concurrency::unbounded_buffer::unbounded_buffer
- AGENTS/concurrency::unbounded_buffer::dequeue
- AGENTS/concurrency::unbounded_buffer::enqueue
- AGENTS/concurrency::unbounded_buffer::accept_message
- AGENTS/concurrency::unbounded_buffer::consume_message
- AGENTS/concurrency::unbounded_buffer::link_target_notification
- AGENTS/concurrency::unbounded_buffer::process_input_messages
- AGENTS/concurrency::unbounded_buffer::propagate_message
- AGENTS/concurrency::unbounded_buffer::propagate_output_messages
- AGENTS/concurrency::unbounded_buffer::release_message
- AGENTS/concurrency::unbounded_buffer::reserve_message
- AGENTS/concurrency::unbounded_buffer::resume_propagation
- AGENTS/concurrency::unbounded_buffer::send_message
- AGENTS/concurrency::unbounded_buffer::supports_anonymous_source
ms.assetid: 6b1a939a-1819-4385-b1d8-708f83d4ec47
ms.openlocfilehash: d0f2f81957ee88d4263c6acd879bd286c95631eb
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142330"
---
# <a name="unbounded_buffer-class"></a>classe unbounded_buffer

Um `unbounded_buffer` bloco de mensagens é um `propagator_block` de vários destinos, com várias fontes e ordenado, capaz de armazenar um número de mensagens não associado.

## <a name="syntax"></a>Sintaxe

```cpp
template<
   class             _Type
>
class unbounded_buffer : public propagator_block<multi_link_registry<ITarget<            _Type>>, multi_link_registry<ISource<            _Type>>>;
```

### <a name="parameters"></a>Parâmetros

*_Type*<br/>
O tipo de carga das mensagens armazenadas e propagadas pelo buffer.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[unbounded_buffer](#ctor)|Sobrecarregado. Constrói um bloco de mensagens `unbounded_buffer`.|
|[~ unbounded_buffer destruidor](#dtor)|Destrói o bloco de mensagens `unbounded_buffer`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[remoção da fila](#dequeue)|Remove um item do bloco de mensagens `unbounded_buffer`.|
|[enfileirar](#enqueue)|Adiciona um item à `unbounded_buffer` o bloco de mensagens.|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Aceita uma mensagem que foi oferecida por esse `unbounded_buffer` bloco de mensagens, transferindo a propriedade para o chamador.|
|[consume_message](#consume_message)|Consome uma mensagem oferecida anteriormente pelo `unbounded_buffer` o bloco de mensagens e reservada pelo destino, transferindo a propriedade para o chamador.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a esse `unbounded_buffer` bloco de mensagens.|
|[process_input_messages](#process_input_messages)|Coloca o `message` `_PMessage` neste `unbounded_buffer` bloco de mensagens e tenta oferecê-lo a todos os destinos vinculados.|
|[propagate_message](#propagate_message)|Transmite de forma assíncrona uma mensagem de um bloco de `ISource` para esse `unbounded_buffer` bloco de mensagens. Ele é invocado pelo método `propagate`, quando chamado por um bloco de origem.|
|[propagate_output_messages](#propagate_output_messages)|Coloca o `message` `_PMessage` neste `unbounded_buffer` bloco de mensagens e tenta oferecê-lo a todos os destinos vinculados. (Substitui [source_block::p ropagate_output_messages](source-block-class.md#propagate_output_messages).)|
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|
|[reserve_message](#reserve_message)|Reserva uma mensagem oferecida anteriormente por este `unbounded_buffer` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|
|[resume_propagation](#resume_propagation)|Retoma a propagação após a liberação de uma reserva. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|
|[send_message](#send_message)|Transmite de forma síncrona uma mensagem de um bloco de `ISource` para esse `unbounded_buffer` bloco de mensagens. Ele é invocado pelo método `send`, quando chamado por um bloco de origem.|
|[supports_anonymous_source](#supports_anonymous_source)|Substitui o método `supports_anonymous_source` para indicar que esse bloco pode aceitar mensagens oferecidas por uma fonte que não está vinculada. (Substitui [ITarget:: supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|

Para obter mais informações, consulte [blocos de mensagens assíncronas](../asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[As](isource-class.md)

[ITarget](itarget-class.md)

[source_block](source-block-class.md)

[propagator_block](propagator-block-class.md)

`unbounded_buffer`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept_message"></a>accept_message

Aceita uma mensagem que foi oferecida por esse `unbounded_buffer` bloco de mensagens, transferindo a propriedade para o chamador.

```cpp
virtual message<_Type> * accept_message(
   runtime_object_identity                 _MsgId
);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto `message` oferecido.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto de `message` ao qual o chamador agora tem propriedade.

## <a name="consume_message"></a>consume_message

Consome uma mensagem oferecida anteriormente pelo `unbounded_buffer` o bloco de mensagens e reservada pelo destino, transferindo a propriedade para o chamador.

```cpp
virtual message<_Type> * consume_message(
   runtime_object_identity                 _MsgId
);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
A `runtime_object_identity` do objeto `message` que está sendo consumido.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto de `message` ao qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

Semelhante a `accept`, mas é sempre precedido por uma chamada para `reserve`.

## <a name="dequeue"></a>remoção da fila

Remove um item do bloco de mensagens `unbounded_buffer`.

```cpp
_Type dequeue();
```

### <a name="return-value"></a>Valor retornado

A carga da mensagem removida da `unbounded_buffer`.

## <a name="enqueue"></a>enfileirar

Adiciona um item à `unbounded_buffer` o bloco de mensagens.

```cpp
bool enqueue(
   _Type const&                 _Item
);
```

### <a name="parameters"></a>Parâmetros

*_Item*<br/>
O item a ser adicionado.

### <a name="return-value"></a>Valor retornado

**true** se o item foi aceito; caso contrário, **false** .

## <a name="link_target_notification"></a>link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a esse `unbounded_buffer` bloco de mensagens.

```cpp
virtual void link_target_notification(
   _Inout_ ITarget<_Type> *                 _PTarget
);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o destino vinculado recentemente.

## <a name="propagate_message"></a>propagate_message

Transmite de forma assíncrona uma mensagem de um bloco de `ISource` para esse `unbounded_buffer` bloco de mensagens. Ele é invocado pelo método `propagate`, quando chamado por um bloco de origem.

```cpp
virtual message_status propagate_message(
   _Inout_ message<_Type> *                 _PMessage,
   _Inout_ ISource<_Type> *                 _PSource
);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md#message_status) do que o destino decidiu fazer com a mensagem.

## <a name="propagate_output_messages"></a>propagate_output_messages

Coloca o `message` `_PMessage` neste `unbounded_buffer` bloco de mensagens e tenta oferecê-lo a todos os destinos vinculados.

```cpp
virtual void propagate_output_messages();
```

### <a name="remarks"></a>Comentários

Se outra mensagem já estiver à frente desta na `unbounded_buffer`, a propagação para destinos vinculados não ocorrerá até que nenhuma mensagem anterior seja aceita ou consumida. O primeiro destino vinculado para `accept` com êxito ou `consume` a mensagem se apropriar e nenhum outro destino poderá obter a mensagem.

## <a name="process_input_messages"></a>process_input_messages

Coloca o `message` `_PMessage` neste `unbounded_buffer` bloco de mensagens e tenta oferecê-lo a todos os destinos vinculados.

```cpp
virtual void process_input_messages(
   _Inout_ message<_Type> *                 _PMessage
);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem a ser processada.

## <a name="release_message"></a>release_message

Libera uma reserva de mensagem anterior.

```cpp
virtual void release_message(
   runtime_object_identity                 _MsgId
);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto de `message` que está sendo liberado.

## <a name="reserve_message"></a>reserve_message

Reserva uma mensagem oferecida anteriormente por este `unbounded_buffer` bloco de mensagens.

```cpp
virtual bool reserve_message(
   runtime_object_identity                 _MsgId
);
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

Transmite de forma síncrona uma mensagem de um bloco de `ISource` para esse `unbounded_buffer` bloco de mensagens. Ele é invocado pelo método `send`, quando chamado por um bloco de origem.

```cpp
virtual message_status send_message(
   _Inout_ message<_Type> *                 _PMessage,
   _Inout_ ISource<_Type> *                 _PSource
);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md#message_status) do que o destino decidiu fazer com a mensagem.

## <a name="supports_anonymous_source"></a>supports_anonymous_source

Substitui o método `supports_anonymous_source` para indicar que esse bloco pode aceitar mensagens oferecidas por uma fonte que não está vinculada.

```cpp
virtual bool supports_anonymous_source();
```

### <a name="return-value"></a>Valor retornado

**true** porque o bloco não adia mensagens oferecidas.

## <a name="ctor"></a>unbounded_buffer

Constrói um bloco de mensagens `unbounded_buffer`.

```cpp
unbounded_buffer();

unbounded_buffer(
   filter_method const&                 _Filter
);

unbounded_buffer(
   Scheduler&                 _PScheduler
);

unbounded_buffer(
   Scheduler&                 _PScheduler,
   filter_method const&                 _Filter
);

unbounded_buffer(
   ScheduleGroup&                 _PScheduleGroup
);

unbounded_buffer(
   ScheduleGroup&                 _PScheduleGroup,
   filter_method const&                 _Filter
);
```

### <a name="parameters"></a>Parâmetros

*_Filter*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.

*_PScheduler*<br/>
O objeto `Scheduler` no qual a tarefa de propagação para o `unbounded_buffer` bloco de mensagens está agendada.

*_PScheduleGroup*<br/>
O objeto `ScheduleGroup` no qual a tarefa de propagação para o `unbounded_buffer` bloco de mensagens está agendada. O objeto de `Scheduler` usado é implícito pelo grupo de agendamento.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os parâmetros `_PScheduler` ou `_PScheduleGroup`.

O tipo `filter_method` é um functor com assinatura `bool (_Type const &)` que é invocado por esse `unbounded_buffer` bloco de mensagens para determinar se ele deve ou não aceitar uma mensagem oferecida.

## <a name="dtor"></a>~ unbounded_buffer

Destrói o bloco de mensagens `unbounded_buffer`.

```cpp
~unbounded_buffer();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe overwrite_buffer](overwrite-buffer-class.md)<br/>
[Classe single_assignment](single-assignment-class.md)
