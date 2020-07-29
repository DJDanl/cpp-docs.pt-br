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
ms.openlocfilehash: c65eed8abafe424fa27c5b9a72d3c73b7127b68e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219580"
---
# <a name="join-class"></a>Classe join

Um `join` bloco de mensagens é um único destino, várias origens, ordenado, `propagator_block` que combina as mensagens do tipo `T` de cada uma de suas fontes.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T,
    join_type _Jtype = non_greedy>
class join : public propagator_block<single_link_registry<ITarget<std::vector<T>>>,
    multi_link_registry<ISource<T>>>;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de carga das mensagens Unidas e propagadas pelo bloco.

*_Jtype*<br/>
O tipo de `join` bloco é, `greedy` ou`non_greedy`

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[join](#ctor)|Sobrecarregado. Constrói um `join` bloco de mensagens.|
|[~ Destruidor de junção](#dtor)|Destrói o `join` bloco.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Aceita uma mensagem que foi oferecida por este `join` bloco de mensagens, transferindo a propriedade para o chamador.|
|[consume_message](#consume_message)|Consome uma mensagem fornecida anteriormente pelo bloco de `join` mensagens e reservada pelo destino, transferindo a propriedade para o chamador.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `join` bloco de mensagens.|
|[propagate_message](#propagate_message)|Transmite de forma assíncrona uma mensagem de um `ISource` bloco para esse `join` bloco de mensagens. Ele é invocado pelo `propagate` método, quando chamado por um bloco de origem.|
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

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept_message"></a><a name="accept_message"></a>accept_message

Aceita uma mensagem que foi oferecida por este `join` bloco de mensagens, transferindo a propriedade para o chamador.

```cpp
virtual message<_OutputType>* accept_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto oferecido `message` .

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

## <a name="consume_message"></a><a name="consume_message"></a>consume_message

Consome uma mensagem fornecida anteriormente pelo bloco de `join` mensagens e reservada pelo destino, transferindo a propriedade para o chamador.

```cpp
virtual message<_OutputType>* consume_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo consumido.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

Semelhante a `accept` , mas é sempre precedido por uma chamada para `reserve` .

## <a name="join"></a><a name="ctor"></a>em

Constrói um `join` bloco de mensagens.

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

### <a name="parameters"></a>parâmetros

*_NumInputs*<br/>
O número de entradas para o qual esse `join` bloco será permitido.

*_Filter*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.

*_PScheduler*<br/>
O `Scheduler` objeto no qual a tarefa de propagação para o `join` bloco de mensagens está agendada.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto no qual a tarefa de propagação para o `join` bloco de mensagens está agendada. O `Scheduler` objeto usado é implícito pelo grupo de agendamento.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os `_PScheduler` `_PScheduleGroup` parâmetros ou.

O tipo `filter_method` é um functor com assinatura `bool (T const &)` que é invocada por esse `join` bloco de mensagens para determinar se ele deve ou não aceitar uma mensagem oferecida.

## <a name="join"></a><a name="dtor"></a>~ junção

Destrói o `join` bloco.

```cpp
~join();
```

## <a name="link_target_notification"></a><a name="link_target_notification"></a>link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a este `join` bloco de mensagens.

```cpp
virtual void link_target_notification(_Inout_ ITarget<std::vector<T>> *);
```

## <a name="propagate_message"></a><a name="propagate_message"></a>propagate_message

Transmite de forma assíncrona uma mensagem de um `ISource` bloco para esse `join` bloco de mensagens. Ele é invocado pelo `propagate` método, quando chamado por um bloco de origem.

```cpp
message_status propagate_message(
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

Constrói uma mensagem de saída contendo uma mensagem de entrada de cada fonte quando todas propagam uma mensagem. Envia essa mensagem de saída para cada um de seus destinos.

```cpp
void propagate_to_any_targets(_Inout_opt_ message<_OutputType> *);
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

Reserva uma mensagem oferecida anteriormente por este `join` bloco de mensagens.

```cpp
virtual bool reserve_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto oferecido `message` .

### <a name="return-value"></a>Valor retornado

**`true`** se a mensagem tiver sido reservada com êxito, **`false`** caso contrário.

### <a name="remarks"></a>Comentários

After `reserve` é chamado, se ele retornar **`true`** , `consume` ou `release` deve ser chamado para tirar ou liberar a propriedade da mensagem.

## <a name="resume_propagation"></a><a name="resume_propagation"></a>resume_propagation

Retoma a propagação após a liberação de uma reserva.

```cpp
virtual void resume_propagation();
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Choice](choice-class.md)<br/>
[Classe multitype_join](multitype-join-class.md)
