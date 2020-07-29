---
title: Classe transformer
ms.date: 11/04/2016
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
helpviewer_keywords:
- transformer class
ms.assetid: eea71925-7043-4a92-bfd4-dbc0ece5d081
ms.openlocfilehash: adc83ab2d8268460b3a35be44f5733c8b6fa1c43
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217890"
---
# <a name="transformer-class"></a>Classe transformer

Um `transformer` bloco de mensagens é um único destino, várias origens, ordenado, `propagator_block` que pode aceitar mensagens de um tipo e é capaz de armazenar um número não associado de mensagens de um tipo diferente.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _Input, class _Output>
class transformer : public propagator_block<single_link_registry<ITarget<_Output>>,
    multi_link_registry<ISource<_Input>>>;
```

### <a name="parameters"></a>parâmetros

*_Input*<br/>
O tipo de carga das mensagens aceitas pelo buffer.

*_Output*<br/>
O tipo de carga das mensagens armazenadas e propagadas pelo buffer.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[transformador](#ctor)|Sobrecarregado. Constrói um `transformer` bloco de mensagens.|
|[~ Destruidor de transformador](#dtor)|Destrói o `transformer` bloco de mensagens.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Aceita uma mensagem que foi oferecida por este `transformer` bloco de mensagens, transferindo a propriedade para o chamador.|
|[consume_message](#consume_message)|Consome uma mensagem fornecida anteriormente pelo `transformer` e reservada pelo destino, transferindo a propriedade para o chamador.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `transformer` bloco de mensagens.|
|[propagate_message](#propagate_message)|Transmite de forma assíncrona uma mensagem de um `ISource` bloco para esse `transformer` bloco de mensagens. Ele é invocado pelo `propagate` método, quando chamado por um bloco de origem.|
|[propagate_to_any_targets](#propagate_to_any_targets)|Executa a função de transformador nas mensagens de entrada.|
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|
|[reserve_message](#reserve_message)|Reserva uma mensagem oferecida anteriormente por este `transformer` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|
|[resume_propagation](#resume_propagation)|Retoma a propagação após a liberação de uma reserva. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|
|[send_message](#send_message)|Transmite de forma síncrona uma mensagem de um `ISource` bloco para esse `transformer` bloco de mensagens. Ele é invocado pelo `send` método, quando chamado por um bloco de origem.|
|[supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que esse bloco pode aceitar mensagens oferecidas por uma fonte que não está vinculada. (Substitui [ITarget:: supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[As](isource-class.md)

[ITarget](itarget-class.md)

[source_block](source-block-class.md)

[propagator_block](propagator-block-class.md)

`transformer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept_message"></a><a name="accept_message"></a>accept_message

Aceita uma mensagem que foi oferecida por este `transformer` bloco de mensagens, transferindo a propriedade para o chamador.

```cpp
virtual message<_Output>* accept_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto oferecido `message` .

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

## <a name="consume_message"></a><a name="consume_message"></a>consume_message

Consome uma mensagem fornecida anteriormente pelo `transformer` e reservada pelo destino, transferindo a propriedade para o chamador.

```cpp
virtual message<_Output>* consume_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo consumido.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

Semelhante a `accept` , mas é sempre precedido por uma chamada para `reserve` .

## <a name="link_target_notification"></a><a name="link_target_notification"></a>link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a este `transformer` bloco de mensagens.

```cpp
virtual void link_target_notification(_Inout_ ITarget<_Output> *);
```

## <a name="propagate_message"></a><a name="propagate_message"></a>propagate_message

Transmite de forma assíncrona uma mensagem de um `ISource` bloco para esse `transformer` bloco de mensagens. Ele é invocado pelo `propagate` método, quando chamado por um bloco de origem.

```cpp
virtual message_status propagate_message(
    _Inout_ message<_Input>* _PMessage,
    _Inout_ ISource<_Input>* _PSource);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md) do que o destino decidiu fazer com a mensagem.

## <a name="propagate_to_any_targets"></a><a name="propagate_to_any_targets"></a>propagate_to_any_targets

Executa a função de transformador nas mensagens de entrada.

```cpp
virtual void propagate_to_any_targets(_Inout_opt_ message<_Output> *);
```

## <a name="release_message"></a><a name="release_message"></a>release_message

Libera uma reserva de mensagem anterior.

```cpp
virtual void release_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo liberado.

## <a name="reserve_message"></a><a name="reserve_message"></a>reserve_message

Reserva uma mensagem oferecida anteriormente por este `transformer` bloco de mensagens.

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

## <a name="send_message"></a><a name="send_message"></a>send_message

Transmite de forma síncrona uma mensagem de um `ISource` bloco para esse `transformer` bloco de mensagens. Ele é invocado pelo `send` método, quando chamado por um bloco de origem.

```cpp
virtual message_status send_message(
    _Inout_ message<_Input>* _PMessage,
    _Inout_ ISource<_Input>* _PSource);
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

## <a name="transformer"></a><a name="ctor"></a>transformador

Constrói um `transformer` bloco de mensagens.

```cpp
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

### <a name="parameters"></a>parâmetros

*_Func*<br/>
Uma função que será invocada para cada mensagem aceita.

*_PTarget*<br/>
Um ponteiro para um bloco de destino para vincular ao transformador.

*_Filter*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.

*_PScheduler*<br/>
O `Scheduler` objeto no qual a tarefa de propagação para o `transformer` bloco de mensagens está agendada.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto no qual a tarefa de propagação para o `transformer` bloco de mensagens está agendada. O `Scheduler` objeto usado é implícito pelo grupo de agendamento.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os `_PScheduler` `_PScheduleGroup` parâmetros ou.

O tipo `_Transform_method` é um functor com assinatura `_Output (_Input const &)` que é invocada por esse `transformer` bloco de mensagens para processar uma mensagem.

O tipo `filter_method` é um functor com assinatura `bool (_Input const &)` que é invocada por esse `transformer` bloco de mensagens para determinar se ele deve ou não aceitar uma mensagem oferecida.

## <a name="transformer"></a><a name="dtor"></a>~ transformador

Destrói o `transformer` bloco de mensagens.

```cpp
~transformer();
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Call](call-class.md)
