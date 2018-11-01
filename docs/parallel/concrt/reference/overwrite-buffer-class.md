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
ms.openlocfilehash: 680c07015538a2eacc9480d3cd22da9a36071e32
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50455986"
---
# <a name="overwritebuffer-class"></a>Classe overwrite_buffer

Uma `overwrite_buffer` bloco de mensagem é um destino de várias, várias fontes, ordenada `propagator_block` capaz de armazenar uma única mensagem por vez. Novas mensagens substituem aqueles mantidos anteriormente.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class overwrite_buffer : public propagator_block<multi_link_registry<ITarget<T>>, multi_link_registry<ISource<T>>>;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de carga das mensagens armazenadas e propagada pelo buffer.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[overwrite_buffer](#ctor)|Sobrecarregado. Constrói um `overwrite_buffer` bloco de mensagem.|
|[~ overwrite_buffer destruidor](#dtor)|Destrói o `overwrite_buffer` bloco de mensagem.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[has_value](#has_value)|Verifica se este `overwrite_buffer` bloco de mensagem tem um valor ainda.|
|[value](#value)|Obtém uma referência ao conteúdo atual da mensagem que está sendo armazenada no `overwrite_buffer` bloco de mensagem.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Aceita uma mensagem que era oferecida por este `overwrite_buffer` bloco de mensagens, retornando uma cópia da mensagem para o chamador.|
|[consume_message](#consume_message)|Consome uma mensagem anteriormente oferecida pelos `overwrite_buffer` bloco de mensagens e reservado pelo destino, retornando uma cópia da mensagem para o chamador.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `overwrite_buffer` bloco de mensagem.|
|[propagate_message](#propagate_message)|Passa assincronamente uma mensagem de um `ISource` bloco a este `overwrite_buffer` bloco de mensagem. Ele é invocado pelo `propagate` método, quando chamado por um bloco de código-fonte.|
|[propagate_to_any_targets](#propagate_to_any_targets)|Coloca o `message _PMessage` desta `overwrite_buffer` bloco de mensagens e oferecê-la para todos os destinos vinculados.|
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|
|[reserve_message](#reserve_message)|Reserva uma mensagem anteriormente oferecida por este `overwrite_buffer` bloco de mensagem. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|
|[resume_propagation](#resume_propagation)|Retoma a propagação depois de uma reserva foi liberada. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|
|[send_message](#send_message)|Forma síncrona transmite uma mensagem de um `ISource` bloco a este `overwrite_buffer` bloco de mensagem. Ele é invocado pelo `send` método, quando chamado por um bloco de código-fonte.|
|[supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada. (Substitui [ITarget:: Supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|

## <a name="remarks"></a>Comentários

Um `overwrite_buffer` bloco de mensagem propaga cópias da sua mensagem armazenada para cada um dos seus destinos.

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[ISource](isource-class.md)

[ITarget](itarget-class.md)

[source_block](source-block-class.md)

[propagator_block](propagator-block-class.md)

`overwrite_buffer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

##  <a name="accept_message"></a> accept_message

Aceita uma mensagem que era oferecida por este `overwrite_buffer` bloco de mensagens, retornando uma cópia da mensagem para o chamador.

```
virtual message<T>* accept_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do que o oferecido `message` objeto.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.

### <a name="remarks"></a>Comentários

O `overwrite_buffer` bloco retorna cópias da mensagem para seus destinos de mensagens, em vez de transferir a propriedade da mensagem atualmente mantida.

##  <a name="consume_message"></a> consume_message

Consome uma mensagem anteriormente oferecida pelos `overwrite_buffer` bloco de mensagens e reservado pelo destino, retornando uma cópia da mensagem para o chamador.

```
virtual message<T>* consume_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo consumido.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.

### <a name="remarks"></a>Comentários

Semelhante ao `accept`, mas sempre é precedido por uma chamada para `reserve`.

##  <a name="has_value"></a> has_value

Verifica se este `overwrite_buffer` bloco de mensagem tem um valor ainda.

```
bool has_value() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o bloco tiver recebido um valor **falso** caso contrário.

##  <a name="link_target_notification"></a> link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a este `overwrite_buffer` bloco de mensagem.

```
virtual void link_target_notification(_Inout_ ITarget<T>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o destino vinculado recentemente.

##  <a name="dtor"></a> ~ overwrite_buffer

Destrói o `overwrite_buffer` bloco de mensagem.

```
~overwrite_buffer();
```

##  <a name="ctor"></a> overwrite_buffer

Constrói um `overwrite_buffer` bloco de mensagem.

```
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

### <a name="parameters"></a>Parâmetros

*Filtro*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.

*_PScheduler*<br/>
O `Scheduler` objeto dentro do qual a tarefa de propagação para o `overwrite_buffer` bloco de mensagem está agendado.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto dentro do qual a tarefa de propagação para o `overwrite_buffer` bloco de mensagem está agendado. O `Scheduler` objeto usado é inferido pelo grupo agendado.

### <a name="remarks"></a>Comentários

O tempo de execução usa o agendador padrão, se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.

O tipo `filter_method` é um funtor com assinatura `bool (T const &)` que é invocado por este `overwrite_buffer` bloco de mensagem para determinar se ele deve aceitar uma mensagem oferecida.

##  <a name="propagate_message"></a> propagate_message

Passa assincronamente uma mensagem de um `ISource` bloco a este `overwrite_buffer` bloco de mensagem. Ele é invocado pelo `propagate` método, quando chamado por um bloco de código-fonte.

```
virtual message_status propagate_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o `message` objeto.

*_PSource*<br/>
Um ponteiro para o bloco de código-fonte, oferecendo a mensagem.

### <a name="return-value"></a>Valor de retorno

Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.

##  <a name="propagate_to_any_targets"></a> propagate_to_any_targets

Coloca o `message _PMessage` desta `overwrite_buffer` bloco de mensagens e oferecê-la para todos os destinos vinculados.

```
virtual void propagate_to_any_targets(_Inout_ message<T>* _PMessage);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para um `message` objeto que este `overwrite_buffer` tem apropriou do.

### <a name="remarks"></a>Comentários

Esse método substitui a mensagem atual na `overwrite_buffer` com a mensagem recentemente aceita `_PMessage`.

##  <a name="send_message"></a> send_message

Forma síncrona transmite uma mensagem de um `ISource` bloco a este `overwrite_buffer` bloco de mensagem. Ele é invocado pelo `send` método, quando chamado por um bloco de código-fonte.

```
virtual message_status send_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o `message` objeto.

*_PSource*<br/>
Um ponteiro para o bloco de código-fonte, oferecendo a mensagem.

### <a name="return-value"></a>Valor de retorno

Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.

##  <a name="supports_anonymous_source"></a> supports_anonymous_source

Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada.

```
virtual bool supports_anonymous_source();
```

### <a name="return-value"></a>Valor de retorno

**True** porque o bloco não adiar oferecido mensagens.

##  <a name="release_message"></a> release_message

Libera uma reserva de mensagem anterior.

```
virtual void release_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo lançada.

##  <a name="reserve_message"></a> reserve_message

Reserva uma mensagem anteriormente oferecida por este `overwrite_buffer` bloco de mensagem.

```
virtual bool reserve_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo reservado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se a mensagem foi reservada com êxito, **falso** caso contrário.

### <a name="remarks"></a>Comentários

Após `reserve` é chamado, se ele retorna **verdadeiro**, ambos `consume` ou `release` deve ser chamado para executar ou liberar a propriedade da mensagem.

##  <a name="resume_propagation"></a> resume_propagation

Retoma a propagação depois de uma reserva foi liberada.

```
virtual void resume_propagation();
```

##  <a name="value"></a> Valor

Obtém uma referência ao conteúdo atual da mensagem que está sendo armazenada no `overwrite_buffer` bloco de mensagem.

```
T value();
```

### <a name="return-value"></a>Valor de retorno

A carga da mensagem armazenada no momento.

### <a name="remarks"></a>Comentários

O valor armazenado no `overwrite_buffer` poderia alterar imediatamente após esse método retornar. Esse método aguardará até que uma mensagem chega se nenhuma mensagem estiver atualmente armazenada no `overwrite_buffer`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe unbounded_buffer](unbounded-buffer-class.md)<br/>
[Classe single_assignment](single-assignment-class.md)
