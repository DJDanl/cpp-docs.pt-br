---
title: Classe Transformer | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- transformer
- AGENTS/concurrency::transformer
- AGENTS/concurrency::transformer::transformer
- AGENTS/concurrency::transformer::accept_message
- AGENTS/concurrency::transformer::consume_message
- AGENTS/concurrency::transformer::link_target_notification
- AGENTS/concurrency::transformer::propagate_message
- AGENTS/concurrency::transformer::propagate_to_any_targets
- AGENTS/concurrency::transformer::release_message
- AGENTS/concurrency::transformer::reserve_message
- AGENTS/concurrency::transformer::resume_propagation
- AGENTS/concurrency::transformer::send_message
- AGENTS/concurrency::transformer::supports_anonymous_source
dev_langs:
- C++
helpviewer_keywords:
- transformer class
ms.assetid: eea71925-7043-4a92-bfd4-dbc0ece5d081
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8e5c6b9d15ef2ca456fd91dbd7829d94e33e2c0a
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49162224"
---
# <a name="transformer-class"></a>Classe transformer

Um `transformer` bloco de mensagem é um destino de único, várias fontes, ordenada `propagator_block` que pode aceitar mensagens de um tipo e é capaz de armazenar um número ilimitado de mensagens de um tipo diferente.

## <a name="syntax"></a>Sintaxe

```
template<class _Input, class _Output>
class transformer : public propagator_block<single_link_registry<ITarget<_Output>>,
    multi_link_registry<ISource<_Input>>>;
```

#### <a name="parameters"></a>Parâmetros

*_Input*<br/>
O tipo de carga das mensagens aceitas pelo buffer.

*Saída*<br/>
O tipo de carga das mensagens armazenadas e propagada pelo buffer.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[transformer](#ctor)|Sobrecarregado. Constrói um `transformer` bloco de mensagem.|
|[~ transformer destruidor](#dtor)|Destrói o `transformer` bloco de mensagem.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Aceita uma mensagem que era oferecida por este `transformer` bloco de mensagens, transferindo a propriedade para o chamador.|
|[consume_message](#consume_message)|Consome uma mensagem anteriormente oferecida pelos `transformer` e reservado pelo destino, transferindo a propriedade para o chamador.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `transformer` bloco de mensagem.|
|[propagate_message](#propagate_message)|Passa assincronamente uma mensagem de um `ISource` bloco a este `transformer` bloco de mensagem. Ele é invocado pelo `propagate` método, quando chamado por um bloco de código-fonte.|
|[propagate_to_any_targets](#propagate_to_any_targets)|Executa a função de transformador as mensagens de entrada.|
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|
|[reserve_message](#reserve_message)|Reserva uma mensagem anteriormente oferecida por este `transformer` bloco de mensagem. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|
|[resume_propagation](#resume_propagation)|Retoma a propagação depois de uma reserva foi liberada. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|
|[send_message](#send_message)|Forma síncrona transmite uma mensagem de um `ISource` bloco a este `transformer` bloco de mensagem. Ele é invocado pelo `send` método, quando chamado por um bloco de código-fonte.|
|[supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que este bloco pode aceitar mensagens oferecidas a ele por uma fonte que não está vinculada. (Substitui [ITarget:: Supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[ISource](isource-class.md)

[ITarget](itarget-class.md)

[source_block](source-block-class.md)

[propagator_block](propagator-block-class.md)

`transformer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

##  <a name="accept_message"></a> accept_message

Aceita uma mensagem que era oferecida por este `transformer` bloco de mensagens, transferindo a propriedade para o chamador.

```
virtual message<_Output>* accept_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do que o oferecido `message` objeto.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.

##  <a name="consume_message"></a> consume_message

Consome uma mensagem anteriormente oferecida pelos `transformer` e reservado pelo destino, transferindo a propriedade para o chamador.

```
virtual message<_Output>* consume_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo consumido.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.

### <a name="remarks"></a>Comentários

Semelhante ao `accept`, mas sempre é precedido por uma chamada para `reserve`.

##  <a name="link_target_notification"></a> link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a este `transformer` bloco de mensagem.

```
virtual void link_target_notification(_Inout_ ITarget<_Output> *);
```

##  <a name="propagate_message"></a> propagate_message

Passa assincronamente uma mensagem de um `ISource` bloco a este `transformer` bloco de mensagem. Ele é invocado pelo `propagate` método, quando chamado por um bloco de código-fonte.

```
virtual message_status propagate_message(
    _Inout_ message<_Input>* _PMessage,
    _Inout_ ISource<_Input>* _PSource);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o `message` objeto.

*_PSource*<br/>
Um ponteiro para o bloco de código-fonte, oferecendo a mensagem.

### <a name="return-value"></a>Valor de retorno

Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.

##  <a name="propagate_to_any_targets"></a> propagate_to_any_targets

Executa a função de transformador as mensagens de entrada.

```
virtual void propagate_to_any_targets(_Inout_opt_ message<_Output> *);
```

##  <a name="release_message"></a> release_message

Libera uma reserva de mensagem anterior.

```
virtual void release_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo lançada.

##  <a name="reserve_message"></a> reserve_message

Reserva uma mensagem anteriormente oferecida por este `transformer` bloco de mensagem.

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

Forma síncrona transmite uma mensagem de um `ISource` bloco a este `transformer` bloco de mensagem. Ele é invocado pelo `send` método, quando chamado por um bloco de código-fonte.

```
virtual message_status send_message(
    _Inout_ message<_Input>* _PMessage,
    _Inout_ ISource<_Input>* _PSource);
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

##  <a name="ctor"></a> transformador

Constrói um `transformer` bloco de mensagem.

```
transformer(
    _Transform_method const& _Func,
    _Inout_opt_ ITarget<_Output>* _PTarget = NULL);

transformer(
    _Transform_method const& _Func,
    _Inout_opt_ ITarget<_Output>* _PTarget,
    filter_method const& _Filter);

transformer(
    Scheduler& _PScheduler,
    _Transform_method const& _Func,
    _Inout_opt_ ITarget<_Output>* _PTarget = NULL);

transformer(
    Scheduler& _PScheduler,
    _Transform_method const& _Func,
    _Inout_opt_ ITarget<_Output>* _PTarget,
    filter_method const& _Filter);

transformer(
    ScheduleGroup& _PScheduleGroup,
    _Transform_method const& _Func,
    _Inout_opt_ ITarget<_Output>* _PTarget = NULL);

transformer(
    ScheduleGroup& _PScheduleGroup,
    _Transform_method const& _Func,
    _Inout_opt_ ITarget<_Output>* _PTarget,
    filter_method const& _Filter);
```

### <a name="parameters"></a>Parâmetros

*_Func*<br/>
Uma função que será invocada para cada mensagem aceita.

*_PTarget*<br/>
Um ponteiro para um bloco de destino para vincular com o transformador.

*Filtro*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.

*_PScheduler*<br/>
O `Scheduler` objeto dentro do qual a tarefa de propagação para o `transformer` bloco de mensagem está agendado.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto dentro do qual a tarefa de propagação para o `transformer` bloco de mensagem está agendado. O `Scheduler` objeto usado é inferido pelo grupo agendado.

### <a name="remarks"></a>Comentários

O tempo de execução usa o agendador padrão, se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.

O tipo `_Transform_method` é um funtor com assinatura `_Output (_Input const &)` que é invocado por este `transformer` bloco de mensagem para processar uma mensagem.

O tipo `filter_method` é um funtor com assinatura `bool (_Input const &)` que é invocado por este `transformer` bloco de mensagem para determinar se ele deve aceitar uma mensagem oferecida.

##  <a name="dtor"></a> ~ transformer

Destrói o `transformer` bloco de mensagem.

```
~transformer();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe call](call-class.md)
