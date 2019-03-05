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
ms.openlocfilehash: 436d0d4cc16ee18449178782b775a25bb1d8592a
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57268949"
---
# <a name="singleassignment-class"></a>Classe single_assignment

Um `single_assignment` bloco de mensagem é um destino de vários várias fontes, ordenada `propagator_block` capaz de armazenar uma única gravação-depois que `message`.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class single_assignment : public propagator_block<multi_link_registry<ITarget<T>>, multi_link_registry<ISource<T>>>;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de carga da mensagem armazenada e propagada pelo buffer.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[single_assignment](#ctor)|Sobrecarregado. Constrói um `single_assignment` bloco de mensagem.|
|[~single_assignment Destructor](#dtor)|Destrói o `single_assignment` bloco de mensagem.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[has_value](#has_value)|Verifica se este `single_assignment` bloco de mensagens foi inicializado com um valor ainda.|
|[value](#value)|Obtém uma referência ao conteúdo atual da mensagem que está sendo armazenada no `single_assignment` bloco de mensagem.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Aceita uma mensagem que era oferecida por este `single_assignment` bloco de mensagens, retornando uma cópia da mensagem para o chamador.|
|[consume_message](#consume_message)|Consome uma mensagem anteriormente oferecida pelos `single_assignment` e reservado pelo destino, retornando uma cópia da mensagem para o chamador.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `single_assignment` bloco de mensagem.|
|[propagate_message](#propagate_message)|Passa assincronamente uma mensagem de um `ISource` bloco a este `single_assignment` bloco de mensagem. Ele é invocado pelo `propagate` método, quando chamado por um bloco de código-fonte.|
|[propagate_to_any_targets](#propagate_to_any_targets)|Coloca o `message _PMessage` desta `single_assignment` bloco de mensagens e oferecê-la para todos os destinos vinculados.|
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|
|[reserve_message](#reserve_message)|Reserva uma mensagem anteriormente oferecida por este `single_assignment` bloco de mensagem. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|
|[resume_propagation](#resume_propagation)|Retoma a propagação depois de uma reserva foi liberada. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|
|[send_message](#send_message)|Forma síncrona transmite uma mensagem de um `ISource` bloco a este `single_assignment` bloco de mensagem. Ele é invocado pelo `send` método, quando chamado por um bloco de código-fonte.|

## <a name="remarks"></a>Comentários

Um `single_assignment` bloco de mensagem propaga cópias da sua mensagem para cada destino.

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[ISource](isource-class.md)

[ITarget](itarget-class.md)

[source_block](source-block-class.md)

[propagator_block](propagator-block-class.md)

`single_assignment`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

##  <a name="accept_message"></a> accept_message

Aceita uma mensagem que era oferecida por este `single_assignment` bloco de mensagens, retornando uma cópia da mensagem para o chamador.

```
virtual message<T>* accept_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do que o oferecido `message` objeto.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.

### <a name="remarks"></a>Comentários

O `single_assignment` bloco retorna cópias da mensagem para seus destinos de mensagens, em vez de transferir a propriedade da mensagem atualmente mantida.

##  <a name="consume_message"></a> consume_message

Consome uma mensagem anteriormente oferecida pelos `single_assignment` e reservado pelo destino, retornando uma cópia da mensagem para o chamador.

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

Verifica se este `single_assignment` bloco de mensagens foi inicializado com um valor ainda.

```
bool has_value() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o bloco tiver recebido um valor **falso** caso contrário.

##  <a name="link_target_notification"></a> link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a este `single_assignment` bloco de mensagem.

```
virtual void link_target_notification(_Inout_ ITarget<T>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o destino vinculado recentemente.

##  <a name="propagate_message"></a> propagate_message

Passa assincronamente uma mensagem de um `ISource` bloco a este `single_assignment` bloco de mensagem. Ele é invocado pelo `propagate` método, quando chamado por um bloco de código-fonte.

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

Coloca o `message` `_PMessage` desta `single_assignment` bloco de mensagens e oferecê-la para todos os destinos vinculados.

```
virtual void propagate_to_any_targets(_Inout_opt_ message<T>* _PMessage);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para um `message` que este `single_assignment` tem assumiu a propriedade do bloco de mensagem.

##  <a name="release_message"></a> release_message

Libera uma reserva de mensagem anterior.

```
virtual void release_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo lançada.

##  <a name="reserve_message"></a> reserve_message

Reserva uma mensagem anteriormente oferecida por este `single_assignment` bloco de mensagem.

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

##  <a name="send_message"></a> send_message

Forma síncrona transmite uma mensagem de um `ISource` bloco a este `single_assignment` bloco de mensagem. Ele é invocado pelo `send` método, quando chamado por um bloco de código-fonte.

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

##  <a name="ctor"></a> single_assignment

Constrói um `single_assignment` bloco de mensagem.

```
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
O `Scheduler` objeto dentro do qual a tarefa de propagação para o `single_assignment` bloco de mensagem está agendado.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto dentro do qual a tarefa de propagação para o `single_assignment` bloco de mensagem está agendado. O `Scheduler` objeto usado é inferido pelo grupo agendado.

### <a name="remarks"></a>Comentários

O tempo de execução usa o agendador padrão, se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.

O tipo `filter_method` é um funtor com assinatura `bool (T const &)` que é invocado por este `single_assignment` bloco de mensagem para determinar se ele deve aceitar uma mensagem oferecida.

##  <a name="dtor"></a> ~single_assignment

Destrói o `single_assignment` bloco de mensagem.

```
~single_assignment();
```

##  <a name="value"></a> Valor

Obtém uma referência ao conteúdo atual da mensagem que está sendo armazenada no `single_assignment` bloco de mensagem.

```
T const& value();
```

### <a name="return-value"></a>Valor de retorno

A carga da mensagem armazenada.

### <a name="remarks"></a>Comentários

Esse método aguardará até que uma mensagem chega se nenhuma mensagem estiver atualmente armazenada no `single_assignment` bloco de mensagem.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe overwrite_buffer](overwrite-buffer-class.md)<br/>
[Classe unbounded_buffer](unbounded-buffer-class.md)
