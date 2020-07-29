---
title: Classe ISource
ms.date: 11/04/2016
f1_keywords:
- ISource
- AGENTS/concurrency::ISource
- AGENTS/concurrency::ISource::accept
- AGENTS/concurrency::ISource::acquire_ref
- AGENTS/concurrency::ISource::consume
- AGENTS/concurrency::ISource::link_target
- AGENTS/concurrency::ISource::release
- AGENTS/concurrency::ISource::release_ref
- AGENTS/concurrency::ISource::reserve
- AGENTS/concurrency::ISource::unlink_target
- AGENTS/concurrency::ISource::unlink_targets
helpviewer_keywords:
- ISource class
ms.assetid: c7b73463-42f6-4dcc-801a-81379b12d35a
ms.openlocfilehash: df592e965b436ed5a1d60702f9e57088887d5a94
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222700"
---
# <a name="isource-class"></a>Classe ISource

A `ISource` classe é a interface para todos os blocos de origem. Os blocos de origem propagam mensagens para `ITarget` blocos.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
class ISource;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de dados da carga dentro das mensagens produzidas pelo bloco de origem.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`source_type`|Um alias de tipo para `T` .|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[~ Destruidor as](#dtor)|Destrói o `ISource` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[aceitar](#accept)|Quando substituído em uma classe derivada, o aceita uma mensagem que foi oferecida por esse `ISource` bloco, transferindo a propriedade para o chamador.|
|[acquire_ref](#acquire_ref)|Quando substituído em uma classe derivada, adquire uma contagem de referência nesse `ISource` bloco para evitar a exclusão.|
|[utilização](#consume)|Quando substituído em uma classe derivada, consome uma mensagem oferecida anteriormente por esse `ISource` bloco e reservada com êxito pelo destino, transferindo a propriedade para o chamador.|
|[link_target](#link_target)|Quando substituído em uma classe derivada, o vincula um bloco de destino a esse `ISource` bloco.|
|[liberar](#release)|Quando substituído em uma classe derivada, libera uma reserva de mensagem anterior bem-sucedida.|
|[release_ref](#release_ref)|Quando substituído em uma classe derivada, libera uma contagem de referência nesse `ISource` bloco.|
|[reservado](#reserve)|Quando substituído em uma classe derivada, o reserva uma mensagem oferecida anteriormente por este `ISource` bloco.|
|[unlink_target](#unlink_target)|Quando substituído em uma classe derivada, desvincula um bloco de destino desse `ISource` bloco, se encontrado para ser vinculado anteriormente.|
|[unlink_targets](#unlink_targets)|Quando substituído em uma classe derivada, Desvincula todos os blocos de destino deste `ISource` bloco.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ISource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept"></a><a name="accept"></a>aceitar

Quando substituído em uma classe derivada, o aceita uma mensagem que foi oferecida por esse `ISource` bloco, transferindo a propriedade para o chamador.

```cpp
virtual message<T>* accept(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto oferecido `message` .

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `accept` método.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a mensagem da qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

O `accept` método é chamado por um destino enquanto uma mensagem está sendo oferecida por `ISource` esse bloco. O ponteiro de mensagem retornado pode ser diferente daquele passado para o `propagate` método do `ITarget` bloco, se essa fonte decidir fazer uma cópia da mensagem.

## <a name="acquire_ref"></a><a name="acquire_ref"></a>acquire_ref

Quando substituído em uma classe derivada, adquire uma contagem de referência nesse `ISource` bloco para evitar a exclusão.

```cpp
virtual void acquire_ref(_Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado por um `ITarget` objeto que está sendo vinculado a essa origem durante o `link_target` método.

## <a name="consume"></a><a name="consume"></a>utilização

Quando substituído em uma classe derivada, consome uma mensagem oferecida anteriormente por esse `ISource` bloco e reservada com êxito pelo destino, transferindo a propriedade para o chamador.

```cpp
virtual message<T>* consume(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
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

## <a name="isource"></a><a name="dtor"></a>~ As

Destrói o `ISource` objeto.

```cpp
virtual ~ISource();
```

## <a name="link_target"></a><a name="link_target"></a>link_target

Quando substituído em uma classe derivada, o vincula um bloco de destino a esse `ISource` bloco.

```cpp
virtual void link_target(_Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está sendo vinculado a este `ISource` bloco.

## <a name="release"></a><a name="release"></a>liberar

Quando substituído em uma classe derivada, libera uma reserva de mensagem anterior bem-sucedida.

```cpp
virtual void release(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto reservado `message` .

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `release` método.

## <a name="release_ref"></a><a name="release_ref"></a>release_ref

Quando substituído em uma classe derivada, libera uma contagem de referência nesse `ISource` bloco.

```cpp
virtual void release_ref(_Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado por um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de origem tem permissão para liberar todos os recursos reservados para o bloco de destino.

## <a name="reserve"></a><a name="reserve"></a>reservado

Quando substituído em uma classe derivada, o reserva uma mensagem oferecida anteriormente por este `ISource` bloco.

```cpp
virtual bool reserve(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto oferecido `message` .

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `reserve` método.

### <a name="return-value"></a>Valor retornado

**`true`** se a mensagem tiver sido reservada com êxito, **`false`** caso contrário. As reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceita por outro destino, a origem poderia negar reservas e assim por diante.

### <a name="remarks"></a>Comentários

Depois de chamar `reserve` , se tiver sucesso, você deverá chamar `consume` ou `release` para obter ou desistir da posse da mensagem, respectivamente.

## <a name="unlink_target"></a><a name="unlink_target"></a>unlink_target

Quando substituído em uma classe derivada, desvincula um bloco de destino desse `ISource` bloco, se encontrado para ser vinculado anteriormente.

```cpp
virtual void unlink_target(_Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está sendo desvinculado deste `ISource` bloco.

## <a name="unlink_targets"></a><a name="unlink_targets"></a>unlink_targets

Quando substituído em uma classe derivada, Desvincula todos os blocos de destino deste `ISource` bloco.

```cpp
virtual void unlink_targets() = 0;
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe ITarget](itarget-class.md)
