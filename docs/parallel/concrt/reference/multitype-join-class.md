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
ms.openlocfilehash: 2fd94ef072fcab9af076fcdfa1b5c094d77f89c8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50547378"
---
# <a name="multitypejoin-class"></a>Classe multitype_join

Um `multitype_join` bloco de mensagens é um bloco de mensagens várias fonte, destino único que combina mensagens de diferentes tipos de cada uma das suas fontes e oferece uma tupla das mensagens combinadas para seus destinos.

## <a name="syntax"></a>Sintaxe

```
template<
    typename T,
    join_type _Jtype = non_greedy
>
class multitype_join: public ISource<typename _Unwrap<T>::type>;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O `tuple` tipo de carga das mensagens ingressou e propagada pelo bloco.

*_Jtype*<br/>
O tipo de `join` bloco é `greedy` ou `non_greedy`

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`type`|Um alias de tipo para `T`.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[multitype_join](#ctor)|Sobrecarregado. Constrói um `multitype_join` bloco de mensagem.|
|[~ multitype_join destruidor](#dtor)|Destrói o `multitype_join` bloco de mensagem.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[accept](#accept)|Aceita uma mensagem que era oferecida por este `multitype_join` bloco, transferindo a propriedade para o chamador.|
|[acquire_ref](#acquire_ref)|Adquire uma contagem de referência sobre isso `multitype_join` bloco de mensagem, para impedir a exclusão.|
|[consume](#consume)|Consome uma mensagem anteriormente oferecida pelos `multitype_join` bloco de mensagens e reservada com êxito pelo destino, transferindo a propriedade para o chamador.|
|[link_target](#link_target)|Isso vincula um bloco de destino `multitype_join` bloco de mensagem.|
|[release](#release)|Libera uma reserva de mensagem bem-sucedida anterior.|
|[release_ref](#release_ref)|Libera uma contagem de referência sobre isso `multiple_join` bloco de mensagem.|
|[reserve](#reserve)|Reserva uma mensagem anteriormente oferecida por este `multitype_join` bloco de mensagem.|
|[unlink_target](#unlink_target)|Desvincula um bloco de destino deste `multitype_join` bloco de mensagem.|
|[unlink_targets](#unlink_targets)|Desvincula todos os destinos neste `multitype_join` bloco de mensagem. (Substitui [ISource:: Unlink_targets](isource-class.md#unlink_targets).)|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[ISource](isource-class.md)

`multitype_join`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

##  <a name="accept"></a> Aceitar

Aceita uma mensagem que era oferecida por este `multitype_join` bloco, transferindo a propriedade para o chamador.

```
virtual message<_Destination_type>* accept(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do que o oferecido `message` objeto.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `accept` método.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a mensagem de que o chamador agora tem a propriedade do.

##  <a name="acquire_ref"></a> acquire_ref

Adquire uma contagem de referência sobre isso `multitype_join` bloco de mensagem, para impedir a exclusão.

```
virtual void acquire_ref(_Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado um `ITarget` objeto que está sendo vinculado a essa fonte durante o `link_target` método.

##  <a name="consume"></a> consumir

Consome uma mensagem anteriormente oferecida pelos `multitype_join` bloco de mensagens e reservada com êxito pelo destino, transferindo a propriedade para o chamador.

```
virtual message<_Destination_type>* consume(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` de reservado `message` objeto.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `consume` método.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.

### <a name="remarks"></a>Comentários

O `consume` método é semelhante ao `accept`, mas sempre deve ser precedido por uma chamada para `reserve` que retornado **true**.

##  <a name="link_target"></a> link_target

Isso vincula um bloco de destino `multitype_join` bloco de mensagem.

```
virtual void link_target(_Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para um `ITarget` bloco para vincular a este `multitype_join` bloco de mensagem.

##  <a name="ctor"></a> multitype_join

Constrói um `multitype_join` bloco de mensagem.

```
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
Um `tuple` das fontes para este `multitype_join` bloco de mensagem.

*_PScheduler*<br/>
O `Scheduler` objeto dentro do qual a tarefa de propagação para o `multitype_join` bloco de mensagem está agendado.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto dentro do qual a tarefa de propagação para o `multitype_join` bloco de mensagem está agendado. O `Scheduler` objeto usado é inferido pelo grupo agendado.

*Juntar*<br/>
Um `multitype_join` copiar do bloco de mensagem. Observe que o objeto original ficar órfão, fazendo de um construtor de movimentação.

### <a name="remarks"></a>Comentários

O tempo de execução usa o agendador padrão, se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.

Construção de movimentação não é executada em um bloqueio, o que significa que ele depende do usuário para certificar-se de que não há nenhuma tarefa leve em andamento no momento da movimentação. Caso contrário, corridas inúmeros podem ocorrer, levando a estado inconsistente ou exceções.

##  <a name="dtor"></a> ~ multitype_join

Destrói o `multitype_join` bloco de mensagem.

```
~multitype_join();
```

##  <a name="release"></a> versão

Libera uma reserva de mensagem bem-sucedida anterior.

```
virtual void release(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo lançada.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `release` método.

##  <a name="release_ref"></a> release_ref

Libera uma contagem de referência sobre isso `multiple_join` bloco de mensagem.

```
virtual void release_ref(_Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de origem é permitido para liberar quaisquer recursos reservados para o bloco de destino.

##  <a name="reserve"></a> reservar

Reserva uma mensagem anteriormente oferecida por este `multitype_join` bloco de mensagem.

```
virtual bool reserve(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo reservado.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `reserve` método.

### <a name="return-value"></a>Valor de retorno

`true` Se a mensagem foi reservada com êxito, `false` caso contrário. As reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceito por outro destino, a fonte pode negar reservas e assim por diante.

### <a name="remarks"></a>Comentários

Depois de chamar `reserve`, se tiver êxito, você deve chamar `consume` ou `release` para levar ou desistir posse da mensagem, respectivamente.

##  <a name="unlink_target"></a> unlink_target

Desvincula um bloco de destino deste `multitype_join` bloco de mensagem.

```
virtual void unlink_target(_Inout_ ITarget<_Destination_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para um `ITarget` bloco desvincular deste `multitype_join` bloco de mensagem.

##  <a name="unlink_targets"></a> unlink_targets

Desvincula todos os destinos neste `multitype_join` bloco de mensagem.

```
virtual void unlink_targets();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe choice](choice-class.md)<br/>
[Classe join](join-class.md)
