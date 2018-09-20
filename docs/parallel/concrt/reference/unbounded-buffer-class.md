---
title: Classe unbounded_buffer | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
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
dev_langs:
- C++
ms.assetid: 6b1a939a-1819-4385-b1d8-708f83d4ec47
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 46789b74d0b7b8d882a1e2ea90103c4c2f1e934b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46396337"
---
Uma `unbounded_buffer` bloco de mensagem é um destino de várias, várias fontes, ordenada `propagator_block` capaz de armazenar um número ilimitado de mensagens.

## <a name="syntax"></a>Sintaxe

```
template<
   class             _Type
>
class unbounded_buffer : public propagator_block<multi_link_registry<ITarget<            _Type>>, multi_link_registry<ISource<            _Type>>>;
```

#### <a name="parameters"></a>Parâmetros

*Tipo*<br/>
O tipo de carga das mensagens armazenadas e propagada pelo buffer.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[unbounded_buffer](#ctor)|Sobrecarregado. Constrói um `unbounded_buffer` bloco de mensagem.|
|[~ unbounded_buffer destruidor](#dtor)|Destrói o `unbounded_buffer` bloco de mensagem.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[dequeue](#dequeue)|Remove um item do `unbounded_buffer` bloco de mensagem.|
|[enqueue](#enqueue)|Adiciona um item para o `unbounded_buffer` bloco de mensagem.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Aceita uma mensagem que era oferecida por este `unbounded_buffer` bloco de mensagens, transferindo a propriedade para o chamador.|
|[consume_message](#consume_message)|Consome uma mensagem anteriormente oferecida pelos `unbounded_buffer` bloco de mensagens e reservado pelo destino, transferindo a propriedade para o chamador.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `unbounded_buffer` bloco de mensagem.|
|[process_input_messages](#process_input_messages)|Coloca o `message` `_PMessage` desta `unbounded_buffer` bloco de mensagem e tenta oferecê-lo para todos os destinos vinculados.|
|[propagate_message](#propagate_message)|Passa assincronamente uma mensagem de um `ISource` bloco a este `unbounded_buffer` bloco de mensagem. Ele é invocado pelo `propagate` método, quando chamado por um bloco de código-fonte.|
|[propagate_output_messages](#propagate_output_messages)|Coloca o `message` `_PMessage` desta `unbounded_buffer` bloco de mensagem e tenta oferecê-lo para todos os destinos vinculados. (Substitui [source_block:: propagate_output_messages](source-block-class.md#propagate_output_messages).)|
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|
|[reserve_message](#reserve_message)|Reserva uma mensagem anteriormente oferecida por este `unbounded_buffer` bloco de mensagem. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|
|[resume_propagation](#resume_propagation)|Retoma a propagação depois de uma reserva foi liberada. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|
|[send_message](#send_message)|Forma síncrona transmite uma mensagem de um `ISource` bloco a este `unbounded_buffer` bloco de mensagem. Ele é invocado pelo `send` método, quando chamado por um bloco de código-fonte.|
|[supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada. (Substitui [ITarget:: Supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|

Para obter mais informações, consulte [blocos de mensagens assíncronas](../asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[ISource](isource-class.md)

[ITarget](itarget-class.md)

[source_block](source-block-class.md)

[propagator_block](propagator-block-class.md)

`unbounded_buffer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

##  <a name="accept_message"></a> accept_message

Aceita uma mensagem que era oferecida por este `unbounded_buffer` bloco de mensagens, transferindo a propriedade para o chamador.

```
virtual message<_Type> * accept_message(
   runtime_object_identity                 _MsgId
);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do que o oferecido `message` objeto.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.

##  <a name="consume_message"></a> consume_message

Consome uma mensagem anteriormente oferecida pelos `unbounded_buffer` bloco de mensagens e reservado pelo destino, transferindo a propriedade para o chamador.

```
virtual message<_Type> * consume_message(
   runtime_object_identity                 _MsgId
);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo consumido.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.

### <a name="remarks"></a>Comentários

Semelhante ao `accept`, mas sempre é precedido por uma chamada para `reserve`.

##  <a name="dequeue"></a> Remover da fila

Remove um item do `unbounded_buffer` bloco de mensagem.

```
_Type dequeue();
```

### <a name="return-value"></a>Valor de retorno

A carga da mensagem removida a `unbounded_buffer`.

##  <a name="enqueue"></a> enqueue

Adiciona um item para o `unbounded_buffer` bloco de mensagem.

```
bool enqueue(
   _Type const&                 _Item
);
```

### <a name="parameters"></a>Parâmetros

*Item*<br/>
O item a ser adicionado.

### <a name="return-value"></a>Valor de retorno

`true` Se o item tiver sido aceita, `false` caso contrário.

##  <a name="link_target_notification"></a> link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a este `unbounded_buffer` bloco de mensagem.

```
virtual void link_target_notification(
   _Inout_ ITarget<_Type> *                 _PTarget
);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o destino vinculado recentemente.

##  <a name="propagate_message"></a> propagate_message

Passa assincronamente uma mensagem de um `ISource` bloco a este `unbounded_buffer` bloco de mensagem. Ele é invocado pelo `propagate` método, quando chamado por um bloco de código-fonte.

```
virtual message_status propagate_message(
   _Inout_ message<_Type> *                 _PMessage,
   _Inout_ ISource<_Type> *                 _PSource
);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o `message` objeto.

*_PSource*<br/>
Um ponteiro para o bloco de código-fonte, oferecendo a mensagem.

### <a name="return-value"></a>Valor de retorno

Um [message_status](concurrency-namespace-enums.md#message_status) indicação de que o destino decidiu fazer com a mensagem.

##  <a name="propagate_output_messages"></a> propagate_output_messages

Coloca o `message` `_PMessage` desta `unbounded_buffer` bloco de mensagem e tenta oferecê-lo para todos os destinos vinculados.

```
virtual void propagate_output_messages();
```

### <a name="remarks"></a>Comentários

Se outra mensagem já está à frente esse outro no `unbounded_buffer`, propagação para destinos vinculados não ocorrerá até que as mensagens anteriores foram aceitas ou consumidas. O primeiro destino a ser de vinculado com êxito `accept` ou `consume` apropria-se a mensagem e nenhum outro destino, em seguida, pode receber a mensagem.

##  <a name="process_input_messages"></a> process_input_messages

Coloca o `message` `_PMessage` desta `unbounded_buffer` bloco de mensagem e tenta oferecê-lo para todos os destinos vinculados.

```
virtual void process_input_messages(
   _Inout_ message<_Type> *                 _PMessage
);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem que deve ser processado.

##  <a name="release_message"></a> release_message

Libera uma reserva de mensagem anterior.

```
virtual void release_message(
   runtime_object_identity                 _MsgId
);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo lançada.

##  <a name="reserve_message"></a> reserve_message

Reserva uma mensagem anteriormente oferecida por este `unbounded_buffer` bloco de mensagem.

```
virtual bool reserve_message(
   runtime_object_identity                 _MsgId
);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo reservado.

### <a name="return-value"></a>Valor de retorno

`true` Se a mensagem foi reservada com êxito, `false` caso contrário.

### <a name="remarks"></a>Comentários

Após `reserve` é chamado, se ele retornar `true`, ambos `consume` ou `release` deve ser chamado para executar ou liberar a propriedade da mensagem.

##  <a name="resume_propagation"></a> resume_propagation

Retoma a propagação depois de uma reserva foi liberada.

```
virtual void resume_propagation();
```

##  <a name="send_message"></a> send_message

Forma síncrona transmite uma mensagem de um `ISource` bloco a este `unbounded_buffer` bloco de mensagem. Ele é invocado pelo `send` método, quando chamado por um bloco de código-fonte.

```
virtual message_status send_message(
   _Inout_ message<_Type> *                 _PMessage,
   _Inout_ ISource<_Type> *                 _PSource
);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o `message` objeto.

*_PSource*<br/>
Um ponteiro para o bloco de código-fonte, oferecendo a mensagem.

### <a name="return-value"></a>Valor de retorno

Um [message_status](concurrency-namespace-enums.md#message_status) indicação de que o destino decidiu fazer com a mensagem.

##  <a name="supports_anonymous_source"></a> supports_anonymous_source

Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada.

```
virtual bool supports_anonymous_source();
```

### <a name="return-value"></a>Valor de retorno

`true` porque o bloco não adiar as mensagens oferecidas.

##  <a name="ctor"></a> unbounded_buffer

Constrói um `unbounded_buffer` bloco de mensagem.

```
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

*Filtro*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.

*_PScheduler*<br/>
O `Scheduler` objeto dentro do qual a tarefa de propagação para o `unbounded_buffer` bloco de mensagem está agendado.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto dentro do qual a tarefa de propagação para o `unbounded_buffer` bloco de mensagem está agendado. O `Scheduler` objeto usado é inferido pelo grupo agendado.

### <a name="remarks"></a>Comentários

O tempo de execução usa o agendador padrão, se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.

O tipo `filter_method` é um funtor com assinatura `bool (_Type const &)` que é invocado por este `unbounded_buffer` bloco de mensagem para determinar se ele deve aceitar uma mensagem oferecida.

##  <a name="dtor"></a> ~ unbounded_buffer

Destrói o `unbounded_buffer` bloco de mensagem.

```
~unbounded_buffer();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe overwrite_buffer](overwrite-buffer-class.md)<br/>
[Classe single_assignment](single-assignment-class.md)

