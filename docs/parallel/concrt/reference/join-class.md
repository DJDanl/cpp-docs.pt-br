---
title: Classe join
ms.date: 11/04/2016
f1_keywords:
- join
- AGENTS/concurrency::join
- AGENTS/concurrency::join::join
- AGENTS/concurrency::join::accept_message
- AGENTS/concurrency::join::consume_message
- AGENTS/concurrency::join::link_target_notification
- AGENTS/concurrency::join::propagate_message
- AGENTS/concurrency::join::propagate_to_any_targets
- AGENTS/concurrency::join::release_message
- AGENTS/concurrency::join::reserve_message
- AGENTS/concurrency::join::resume_propagation
helpviewer_keywords:
- join class
ms.assetid: d2217119-70a1-40b6-809f-c1c13a571c3f
ms.openlocfilehash: f75cf8483e7d6d65d118cc8f0ea756302d1b1d7c
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77139847"
---
# <a name="join-class"></a>Classe join

Um `join` bloco de mensagens é um `propagator_block` de destino único, com várias origens e ordenado, que combina mensagens do tipo `T` de cada uma de suas fontes.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T,
    join_type _Jtype = non_greedy>
class join : public propagator_block<single_link_registry<ITarget<std::vector<T>>>,
    multi_link_registry<ISource<T>>>;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de carga das mensagens Unidas e propagadas pelo bloco.

*_Jtype*<br/>
O tipo de `join` bloco é, `greedy` ou `non_greedy`

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[join](#ctor)|Sobrecarregado. Constrói um bloco de mensagens `join`.|
|[~ Destruidor de junção](#dtor)|Destrói o bloco de `join`.|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Aceita uma mensagem que foi oferecida por esse `join` bloco de mensagens, transferindo a propriedade para o chamador.|
|[consume_message](#consume_message)|Consome uma mensagem oferecida anteriormente pelo `join` o bloco de mensagens e reservada pelo destino, transferindo a propriedade para o chamador.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a esse `join` bloco de mensagens.|
|[propagate_message](#propagate_message)|Transmite de forma assíncrona uma mensagem de um bloco de `ISource` para esse `join` bloco de mensagens. Ele é invocado pelo método `propagate`, quando chamado por um bloco de origem.|
|[propagate_to_any_targets](#propagate_to_any_targets)|Constrói uma mensagem de saída contendo uma mensagem de entrada de cada fonte quando todas propagam uma mensagem. Envia essa mensagem de saída para cada um de seus destinos.|
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|
|[reserve_message](#reserve_message)|Reserva uma mensagem oferecida anteriormente por este `join` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|
|[resume_propagation](#resume_propagation)|Retoma a propagação após a liberação de uma reserva. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[As](isource-class.md)

[ITarget](itarget-class.md)

[source_block](source-block-class.md)

[propagator_block](propagator-block-class.md)

`join`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept_message"></a>accept_message

Aceita uma mensagem que foi oferecida por esse `join` bloco de mensagens, transferindo a propriedade para o chamador.

```cpp
virtual message<_OutputType>* accept_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto `message` oferecido.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto de `message` ao qual o chamador agora tem propriedade.

## <a name="consume_message"></a>consume_message

Consome uma mensagem oferecida anteriormente pelo `join` o bloco de mensagens e reservada pelo destino, transferindo a propriedade para o chamador.

```cpp
virtual message<_OutputType>* consume_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
A `runtime_object_identity` do objeto `message` que está sendo consumido.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto de `message` ao qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

Semelhante a `accept`, mas é sempre precedido por uma chamada para `reserve`.

## <a name="ctor"></a>em

Constrói um bloco de mensagens `join`.

```cpp
join(
    size_t _NumInputs);

join(
    size_t _NumInputs,
    filter_method const& _Filter);

join(
    Scheduler& _PScheduler,
    size_t _NumInputs);

join(
    Scheduler& _PScheduler,
    size_t _NumInputs,
    filter_method const& _Filter);

join(
    ScheduleGroup& _PScheduleGroup,
    size_t _NumInputs);

join(
    ScheduleGroup& _PScheduleGroup,
    size_t _NumInputs,
    filter_method const& _Filter);
```

### <a name="parameters"></a>Parâmetros

*_NumInputs*<br/>
O número de entradas que esse bloco de `join` será permitido.

*_Filter*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.

*_PScheduler*<br/>
O objeto `Scheduler` no qual a tarefa de propagação para o `join` bloco de mensagens está agendada.

*_PScheduleGroup*<br/>
O objeto `ScheduleGroup` no qual a tarefa de propagação para o `join` bloco de mensagens está agendada. O objeto de `Scheduler` usado é implícito pelo grupo de agendamento.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os parâmetros `_PScheduler` ou `_PScheduleGroup`.

O tipo `filter_method` é um functor com assinatura `bool (T const &)` que é invocado por esse `join` bloco de mensagens para determinar se ele deve ou não aceitar uma mensagem oferecida.

## <a name="dtor"></a>~ junção

Destrói o bloco de `join`.

```cpp
~join();
```

## <a name="link_target_notification"></a>link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a esse `join` bloco de mensagens.

```cpp
virtual void link_target_notification(_Inout_ ITarget<std::vector<T>> *);
```

## <a name="propagate_message"></a>propagate_message

Transmite de forma assíncrona uma mensagem de um bloco de `ISource` para esse `join` bloco de mensagens. Ele é invocado pelo método `propagate`, quando chamado por um bloco de origem.

```cpp
message_status propagate_message(
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

Constrói uma mensagem de saída contendo uma mensagem de entrada de cada fonte quando todas propagam uma mensagem. Envia essa mensagem de saída para cada um de seus destinos.

```cpp
void propagate_to_any_targets(_Inout_opt_ message<_OutputType> *);
```

## <a name="release_message"></a>release_message

Libera uma reserva de mensagem anterior.

```cpp
virtual void release_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto de `message` que está sendo liberado.

## <a name="reserve_message"></a>reserve_message

Reserva uma mensagem oferecida anteriormente por este `join` bloco de mensagens.

```cpp
virtual bool reserve_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto `message` oferecido.

### <a name="return-value"></a>Valor retornado

**true** se a mensagem tiver sido reservada com êxito; caso contrário, **false** .

### <a name="remarks"></a>Comentários

Depois que `reserve` for chamado, se ele retornar **true**, `consume` ou `release` deverá ser chamado para tirar ou liberar a propriedade da mensagem.

## <a name="resume_propagation"></a>resume_propagation

Retoma a propagação após a liberação de uma reserva.

```cpp
virtual void resume_propagation();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe choice](choice-class.md)<br/>
[Classe multitype_join](multitype-join-class.md)
