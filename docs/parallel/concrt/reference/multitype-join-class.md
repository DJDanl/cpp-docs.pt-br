---
title: Classe multitype_join
ms.date: 11/04/2016
f1_keywords:
- multitype_join
- AGENTS/concurrency::multitype_join
- AGENTS/concurrency::multitype_join::multitype_join
- AGENTS/concurrency::multitype_join::accept
- AGENTS/concurrency::multitype_join::acquire_ref
- AGENTS/concurrency::multitype_join::consume
- AGENTS/concurrency::multitype_join::link_target
- AGENTS/concurrency::multitype_join::release
- AGENTS/concurrency::multitype_join::release_ref
- AGENTS/concurrency::multitype_join::reserve
- AGENTS/concurrency::multitype_join::unlink_target
- AGENTS/concurrency::multitype_join::unlink_targets
helpviewer_keywords:
- multitype_join class
ms.assetid: 236e87a0-4867-49fd-869a-bef4010e49a7
ms.openlocfilehash: 4214c43fa0d0ab8fdd29ed54738c19f72a07267a
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77138947"
---
# <a name="multitype_join-class"></a>Classe multitype_join

Um `multitype_join` bloco de mensagens é um bloco de mensagens de destino único de várias fontes que combina mensagens de tipos diferentes de cada uma de suas fontes e oferece uma tupla das mensagens combinadas para seus destinos.

## <a name="syntax"></a>Sintaxe

```cpp
template<
    typename T,
    join_type _Jtype = non_greedy
>
class multitype_join: public ISource<typename _Unwrap<T>::type>;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de carga de `tuple` das mensagens Unidas e propagadas pelo bloco.

*_Jtype*<br/>
O tipo de `join` bloco é, `greedy` ou `non_greedy`

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`type`|Um alias de tipo para `T`.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[multitype_join](#ctor)|Sobrecarregado. Constrói um bloco de mensagens `multitype_join`.|
|[~ multitype_join destruidor](#dtor)|Destrói o bloco de mensagens `multitype_join`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[aceitar](#accept)|Aceita uma mensagem que foi oferecida por este bloco de `multitype_join`, transferindo a propriedade para o chamador.|
|[acquire_ref](#acquire_ref)|Adquire uma contagem de referência nessa `multitype_join` o bloco de mensagens para evitar a exclusão.|
|[consumir](#consume)|Consome uma mensagem oferecida anteriormente pelo bloco de mensagens `multitype_join` e foi reservada com êxito pelo destino, transferindo a propriedade para o chamador.|
|[link_target](#link_target)|Vincula um bloco de destino a este `multitype_join` bloco de mensagens.|
|[release](#release)|Libera uma reserva de mensagem anterior bem-sucedida.|
|[release_ref](#release_ref)|Libera uma contagem de referência neste `multiple_join` bloco de mensagens.|
|[reserve](#reserve)|Reserva uma mensagem oferecida anteriormente por este `multitype_join` bloco de mensagens.|
|[unlink_target](#unlink_target)|Desvincula um bloco de destino deste `multitype_join` bloco de mensagens.|
|[unlink_targets](#unlink_targets)|Desvincula todos os destinos desta `multitype_join` bloco de mensagens. (Substitui [as:: unlink_targets](isource-class.md#unlink_targets).)|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[As](isource-class.md)

`multitype_join`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept"></a>aceitar

Aceita uma mensagem que foi oferecida por este bloco de `multitype_join`, transferindo a propriedade para o chamador.

```cpp
virtual message<_Destination_type>* accept(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto `message` oferecido.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o método de `accept`.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a mensagem da qual o chamador agora tem propriedade.

## <a name="acquire_ref"></a>acquire_ref

Adquire uma contagem de referência nessa `multitype_join` o bloco de mensagens para evitar a exclusão.

```cpp
virtual void acquire_ref(_Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado por um objeto `ITarget` que está sendo vinculado a essa fonte durante o método `link_target`.

## <a name="consume"></a>utilização

Consome uma mensagem oferecida anteriormente pelo bloco de mensagens `multitype_join` e foi reservada com êxito pelo destino, transferindo a propriedade para o chamador.

```cpp
virtual message<_Destination_type>* consume(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto `message` reservado.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o método de `consume`.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto de `message` ao qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

O método `consume` é semelhante a `accept`, mas deve ser sempre precedido por uma chamada para `reserve` que retornou **true**.

## <a name="link_target"></a>link_target

Vincula um bloco de destino a este `multitype_join` bloco de mensagens.

```cpp
virtual void link_target(_Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para um bloco de `ITarget` para vincular a este `multitype_join` bloco de mensagens.

## <a name="ctor"></a>multitype_join

Constrói um bloco de mensagens `multitype_join`.

```cpp
explicit multitype_join(
    T _Tuple);

multitype_join(
    Scheduler& _PScheduler,
    T _Tuple);

multitype_join(
    ScheduleGroup& _PScheduleGroup,
    T _Tuple);

multitype_join(
    multitype_join&& _Join);
```

### <a name="parameters"></a>Parâmetros

*_Tuple*<br/>
Uma `tuple` de fontes para este bloco de mensagens `multitype_join`.

*_PScheduler*<br/>
O objeto `Scheduler` no qual a tarefa de propagação para o `multitype_join` bloco de mensagens está agendada.

*_PScheduleGroup*<br/>
O objeto `ScheduleGroup` no qual a tarefa de propagação para o `multitype_join` bloco de mensagens está agendada. O objeto de `Scheduler` usado é implícito pelo grupo de agendamento.

*_Join*<br/>
Um `multitype_join` bloco de mensagens do qual copiar. Observe que o objeto original está órfão, tornando-o um Construtor move.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os parâmetros `_PScheduler` ou `_PScheduleGroup`.

A construção de movimentação não é executada sob um bloqueio, o que significa que cabe ao usuário certificar-se de que não há nenhuma tarefa leve em trânsito no momento da movimentação. Caso contrário, várias corridas podem ocorrer, levando a exceções ou a um estado inconsistente.

## <a name="dtor"></a>~ multitype_join

Destrói o bloco de mensagens `multitype_join`.

```cpp
~multitype_join();
```

## <a name="release"></a>liberar

Libera uma reserva de mensagem anterior bem-sucedida.

```cpp
virtual void release(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto de `message` que está sendo liberado.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o método de `release`.

## <a name="release_ref"></a>release_ref

Libera uma contagem de referência neste `multiple_join` bloco de mensagens.

```cpp
virtual void release_ref(_Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado por um objeto `ITarget` que está sendo desvinculado dessa fonte. O bloco de origem tem permissão para liberar todos os recursos reservados para o bloco de destino.

## <a name="reserve"></a>reservado

Reserva uma mensagem oferecida anteriormente por este `multitype_join` bloco de mensagens.

```cpp
virtual bool reserve(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto de `message` que está sendo reservado.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o método de `reserve`.

### <a name="return-value"></a>Valor retornado

`true` se a mensagem foi reservada com êxito `false` caso contrário. As reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceita por outro destino, a origem poderia negar reservas e assim por diante.

### <a name="remarks"></a>Comentários

Depois de chamar `reserve`, se tiver sucesso, você deverá chamar `consume` ou `release` para tirar ou desistir da posse da mensagem, respectivamente.

## <a name="unlink_target"></a>unlink_target

Desvincula um bloco de destino deste `multitype_join` bloco de mensagens.

```cpp
virtual void unlink_target(_Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para um bloco de `ITarget` para desvincular deste bloco de mensagens `multitype_join`.

## <a name="unlink_targets"></a>unlink_targets

Desvincula todos os destinos desta `multitype_join` bloco de mensagens.

```cpp
virtual void unlink_targets();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe choice](choice-class.md)<br/>
[Classe join](join-class.md)
