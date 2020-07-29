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
ms.openlocfilehash: c648e77e404cf39eab281a93e03d8b427da375f8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87205854"
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

### <a name="parameters"></a>parâmetros

*T*<br/>
O `tuple` tipo de carga das mensagens Unidas e propagadas pelo bloco.

*_Jtype*<br/>
O tipo de `join` bloco é, `greedy` ou`non_greedy`

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`type`|Um alias de tipo para `T` .|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[multitype_join](#ctor)|Sobrecarregado. Constrói um `multitype_join` bloco de mensagens.|
|[~ multitype_join destruidor](#dtor)|Destrói o `multitype_join` bloco de mensagens.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[aceitar](#accept)|Aceita uma mensagem que foi oferecida por este `multitype_join` bloco, transferindo a propriedade para o chamador.|
|[acquire_ref](#acquire_ref)|Adquire uma contagem de referência neste `multitype_join` bloco de mensagens para evitar a exclusão.|
|[utilização](#consume)|Consome uma mensagem fornecida anteriormente pelo bloco de `multitype_join` mensagens e reservada com êxito pelo destino, transferindo a propriedade para o chamador.|
|[link_target](#link_target)|Vincula um bloco de destino a este `multitype_join` bloco de mensagens.|
|[liberar](#release)|Libera uma reserva de mensagem anterior bem-sucedida.|
|[release_ref](#release_ref)|Libera uma contagem de referência neste `multiple_join` bloco de mensagens.|
|[reservado](#reserve)|Reserva uma mensagem oferecida anteriormente por este `multitype_join` bloco de mensagens.|
|[unlink_target](#unlink_target)|Desvincula um bloco de destino deste `multitype_join` bloco de mensagens.|
|[unlink_targets](#unlink_targets)|Desvincula todos os destinos deste `multitype_join` bloco de mensagens. (Substitui [as:: unlink_targets](isource-class.md#unlink_targets).)|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[As](isource-class.md)

`multitype_join`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept"></a><a name="accept"></a>aceitar

Aceita uma mensagem que foi oferecida por este `multitype_join` bloco, transferindo a propriedade para o chamador.

```cpp
virtual message<_Destination_type>* accept(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto oferecido `message` .

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `accept` método.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a mensagem da qual o chamador agora tem propriedade.

## <a name="acquire_ref"></a><a name="acquire_ref"></a>acquire_ref

Adquire uma contagem de referência neste `multitype_join` bloco de mensagens para evitar a exclusão.

```cpp
virtual void acquire_ref(_Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado por um `ITarget` objeto que está sendo vinculado a essa origem durante o `link_target` método.

## <a name="consume"></a><a name="consume"></a>utilização

Consome uma mensagem fornecida anteriormente pelo bloco de `multitype_join` mensagens e reservada com êxito pelo destino, transferindo a propriedade para o chamador.

```cpp
virtual message<_Destination_type>* consume(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto reservado `message` .

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `consume` método.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

O `consume` método é semelhante a `accept` , mas sempre deve ser precedido por uma chamada para `reserve` isso retornado **`true`** .

## <a name="link_target"></a><a name="link_target"></a>link_target

Vincula um bloco de destino a este `multitype_join` bloco de mensagens.

```cpp
virtual void link_target(_Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para um `ITarget` bloco a ser vinculado a este `multitype_join` bloco de mensagens.

## <a name="multitype_join"></a><a name="ctor"></a>multitype_join

Constrói um `multitype_join` bloco de mensagens.

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

### <a name="parameters"></a>parâmetros

*_Tuple*<br/>
Uma `tuple` das fontes para este `multitype_join` bloco de mensagens.

*_PScheduler*<br/>
O `Scheduler` objeto no qual a tarefa de propagação para o `multitype_join` bloco de mensagens está agendada.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto no qual a tarefa de propagação para o `multitype_join` bloco de mensagens está agendada. O `Scheduler` objeto usado é implícito pelo grupo de agendamento.

*_Join*<br/>
Um `multitype_join` bloco de mensagens do qual copiar. Observe que o objeto original está órfão, tornando-o um Construtor move.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os `_PScheduler` `_PScheduleGroup` parâmetros ou.

A construção de movimentação não é executada sob um bloqueio, o que significa que cabe ao usuário certificar-se de que não há nenhuma tarefa leve em trânsito no momento da movimentação. Caso contrário, várias corridas podem ocorrer, levando a exceções ou a um estado inconsistente.

## <a name="multitype_join"></a><a name="dtor"></a>~ multitype_join

Destrói o `multitype_join` bloco de mensagens.

```cpp
~multitype_join();
```

## <a name="release"></a><a name="release"></a>liberar

Libera uma reserva de mensagem anterior bem-sucedida.

```cpp
virtual void release(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo liberado.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `release` método.

## <a name="release_ref"></a><a name="release_ref"></a>release_ref

Libera uma contagem de referência neste `multiple_join` bloco de mensagens.

```cpp
virtual void release_ref(_Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado por um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de origem tem permissão para liberar todos os recursos reservados para o bloco de destino.

## <a name="reserve"></a><a name="reserve"></a>reservado

Reserva uma mensagem oferecida anteriormente por este `multitype_join` bloco de mensagens.

```cpp
virtual bool reserve(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo reservado.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `reserve` método.

### <a name="return-value"></a>Valor retornado

**`true`** se a mensagem tiver sido reservada com êxito, **`false`** caso contrário. As reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceita por outro destino, a origem poderia negar reservas e assim por diante.

### <a name="remarks"></a>Comentários

Depois de chamar `reserve` , se tiver sucesso, você deverá chamar `consume` ou `release` para obter ou desistir da posse da mensagem, respectivamente.

## <a name="unlink_target"></a><a name="unlink_target"></a>unlink_target

Desvincula um bloco de destino deste `multitype_join` bloco de mensagens.

```cpp
virtual void unlink_target(_Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para um `ITarget` bloco para desvincular deste `multitype_join` bloco de mensagens.

## <a name="unlink_targets"></a><a name="unlink_targets"></a>unlink_targets

Desvincula todos os destinos deste `multitype_join` bloco de mensagens.

```cpp
virtual void unlink_targets();
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Choice](choice-class.md)<br/>
[Classe de junção](join-class.md)
