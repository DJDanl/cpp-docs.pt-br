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
ms.openlocfilehash: e02fa1ffbf4c3e2c7d17dfe2d6ae66758945d9de
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219506"
---
# <a name="unbounded_buffer-class"></a>classe unbounded_buffer

Um `unbounded_buffer` bloco de mensagens é um recurso de vários destinos, várias fontes, ordenado, `propagator_block` capaz de armazenar um número de mensagens não associado.

## <a name="syntax"></a>Sintaxe

```cpp
template<
   class             _Type
>
class unbounded_buffer : public propagator_block<multi_link_registry<ITarget<            _Type>>, multi_link_registry<ISource<            _Type>>>;
```

### <a name="parameters"></a>parâmetros

*_Type*<br/>
O tipo de carga das mensagens armazenadas e propagadas pelo buffer.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[unbounded_buffer](#ctor)|Sobrecarregado. Constrói um `unbounded_buffer` bloco de mensagens.|
|[~ unbounded_buffer destruidor](#dtor)|Destrói o `unbounded_buffer` bloco de mensagens.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[remover da fila](#dequeue)|Remove um item do `unbounded_buffer` bloco de mensagens.|
|[enfileirar](#enqueue)|Adiciona um item ao `unbounded_buffer` bloco de mensagens.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Aceita uma mensagem que foi oferecida por este `unbounded_buffer` bloco de mensagens, transferindo a propriedade para o chamador.|
|[consume_message](#consume_message)|Consome uma mensagem fornecida anteriormente pelo bloco de `unbounded_buffer` mensagens e reservada pelo destino, transferindo a propriedade para o chamador.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `unbounded_buffer` bloco de mensagens.|
|[process_input_messages](#process_input_messages)|Coloca o `message` `_PMessage` nesse `unbounded_buffer` bloco de mensagens e tenta oferecê-lo a todos os destinos vinculados.|
|[propagate_message](#propagate_message)|Transmite de forma assíncrona uma mensagem de um `ISource` bloco para esse `unbounded_buffer` bloco de mensagens. Ele é invocado pelo `propagate` método, quando chamado por um bloco de origem.|
|[propagate_output_messages](#propagate_output_messages)|Coloca o `message` `_PMessage` nesse `unbounded_buffer` bloco de mensagens e tenta oferecê-lo a todos os destinos vinculados. (Substitui [source_block::p ropagate_output_messages](source-block-class.md#propagate_output_messages).)|
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|
|[reserve_message](#reserve_message)|Reserva uma mensagem oferecida anteriormente por este `unbounded_buffer` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|
|[resume_propagation](#resume_propagation)|Retoma a propagação após a liberação de uma reserva. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|
|[send_message](#send_message)|Transmite de forma síncrona uma mensagem de um `ISource` bloco para esse `unbounded_buffer` bloco de mensagens. Ele é invocado pelo `send` método, quando chamado por um bloco de origem.|
|[supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que esse bloco pode aceitar mensagens oferecidas por uma fonte que não está vinculada. (Substitui [ITarget:: supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|

Para obter mais informações, consulte [blocos de mensagens assíncronas](../asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[As](isource-class.md)

[ITarget](itarget-class.md)

[source_block](source-block-class.md)

[propagator_block](propagator-block-class.md)

`unbounded_buffer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept_message"></a><a name="accept_message"></a>accept_message

Aceita uma mensagem que foi oferecida por este `unbounded_buffer` bloco de mensagens, transferindo a propriedade para o chamador.

```cpp
virtual message<_Type> * accept_message(
   runtime_object_identity                 _MsgId
);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto oferecido `message` .

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

## <a name="consume_message"></a><a name="consume_message"></a>consume_message

Consome uma mensagem fornecida anteriormente pelo bloco de `unbounded_buffer` mensagens e reservada pelo destino, transferindo a propriedade para o chamador.

```cpp
virtual message<_Type> * consume_message(
   runtime_object_identity                 _MsgId
);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo consumido.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

Semelhante a `accept` , mas é sempre precedido por uma chamada para `reserve` .

## <a name="dequeue"></a><a name="dequeue"></a>remoção da fila

Remove um item do `unbounded_buffer` bloco de mensagens.

```cpp
_Type dequeue();
```

### <a name="return-value"></a>Valor retornado

A carga da mensagem removida do `unbounded_buffer` .

## <a name="enqueue"></a><a name="enqueue"></a>enfileirar

Adiciona um item ao `unbounded_buffer` bloco de mensagens.

```cpp
bool enqueue(
   _Type const&                 _Item
);
```

### <a name="parameters"></a>parâmetros

*_Item*<br/>
O item a ser adicionado.

### <a name="return-value"></a>Valor retornado

**`true`** Se o item foi aceito, **`false`** caso contrário.

## <a name="link_target_notification"></a><a name="link_target_notification"></a>link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a este `unbounded_buffer` bloco de mensagens.

```cpp
virtual void link_target_notification(
   _Inout_ ITarget<_Type> *                 _PTarget
);
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para o destino vinculado recentemente.

## <a name="propagate_message"></a><a name="propagate_message"></a>propagate_message

Transmite de forma assíncrona uma mensagem de um `ISource` bloco para esse `unbounded_buffer` bloco de mensagens. Ele é invocado pelo `propagate` método, quando chamado por um bloco de origem.

```cpp
virtual message_status propagate_message(
   _Inout_ message<_Type> *                 _PMessage,
   _Inout_ ISource<_Type> *                 _PSource
);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md#message_status) do que o destino decidiu fazer com a mensagem.

## <a name="propagate_output_messages"></a><a name="propagate_output_messages"></a>propagate_output_messages

Coloca o `message` `_PMessage` nesse `unbounded_buffer` bloco de mensagens e tenta oferecê-lo a todos os destinos vinculados.

```cpp
virtual void propagate_output_messages();
```

### <a name="remarks"></a>Comentários

Se outra mensagem já estiver à frente desta no `unbounded_buffer` , a propagação para destinos vinculados não ocorrerá até que nenhuma mensagem anterior seja aceita ou consumida. O primeiro destino vinculado para com êxito `accept` ou `consume` a mensagem apropria-se, e nenhum outro destino pode obter a mensagem.

## <a name="process_input_messages"></a><a name="process_input_messages"></a>process_input_messages

Coloca o `message` `_PMessage` nesse `unbounded_buffer` bloco de mensagens e tenta oferecê-lo a todos os destinos vinculados.

```cpp
virtual void process_input_messages(
   _Inout_ message<_Type> *                 _PMessage
);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem a ser processada.

## <a name="release_message"></a><a name="release_message"></a>release_message

Libera uma reserva de mensagem anterior.

```cpp
virtual void release_message(
   runtime_object_identity                 _MsgId
);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo liberado.

## <a name="reserve_message"></a><a name="reserve_message"></a>reserve_message

Reserva uma mensagem oferecida anteriormente por este `unbounded_buffer` bloco de mensagens.

```cpp
virtual bool reserve_message(
   runtime_object_identity                 _MsgId
);
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

## <a name="send_message"></a><a name="send_message"></a>send_message

Transmite de forma síncrona uma mensagem de um `ISource` bloco para esse `unbounded_buffer` bloco de mensagens. Ele é invocado pelo `send` método, quando chamado por um bloco de origem.

```cpp
virtual message_status send_message(
   _Inout_ message<_Type> *                 _PMessage,
   _Inout_ ISource<_Type> *                 _PSource
);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md#message_status) do que o destino decidiu fazer com a mensagem.

## <a name="supports_anonymous_source"></a><a name="supports_anonymous_source"></a>supports_anonymous_source

Substitui o `supports_anonymous_source` método para indicar que esse bloco pode aceitar mensagens oferecidas por uma fonte que não está vinculada.

```cpp
virtual bool supports_anonymous_source();
```

### <a name="return-value"></a>Valor retornado

**`true`** Porque o bloco não adia mensagens oferecidas.

## <a name="unbounded_buffer"></a><a name="ctor"></a>unbounded_buffer

Constrói um `unbounded_buffer` bloco de mensagens.

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

### <a name="parameters"></a>parâmetros

*_Filter*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.

*_PScheduler*<br/>
O `Scheduler` objeto no qual a tarefa de propagação para o `unbounded_buffer` bloco de mensagens está agendada.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto no qual a tarefa de propagação para o `unbounded_buffer` bloco de mensagens está agendada. O `Scheduler` objeto usado é implícito pelo grupo de agendamento.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os `_PScheduler` `_PScheduleGroup` parâmetros ou.

O tipo `filter_method` é um functor com assinatura `bool (_Type const &)` que é invocada por esse `unbounded_buffer` bloco de mensagens para determinar se ele deve ou não aceitar uma mensagem oferecida.

## <a name="unbounded_buffer"></a><a name="dtor"></a>~ unbounded_buffer

Destrói o `unbounded_buffer` bloco de mensagens.

```cpp
~unbounded_buffer();
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe overwrite_buffer](overwrite-buffer-class.md)<br/>
[Classe single_assignment](single-assignment-class.md)
