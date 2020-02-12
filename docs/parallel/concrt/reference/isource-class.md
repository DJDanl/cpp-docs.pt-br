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
ms.openlocfilehash: a9ef9990db6376536f2f2a15c053b3b1d4ed12cf
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77139315"
---
# <a name="isource-class"></a>Classe ISource

A classe `ISource` é a interface para todos os blocos de origem. Os blocos de origem propagam mensagens para blocos de `ITarget`.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
class ISource;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados da carga dentro das mensagens produzidas pelo bloco de origem.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`source_type`|Um alias de tipo para `T`.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[~ Destruidor as](#dtor)|Destrói o objeto `ISource`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[aceitar](#accept)|Quando substituído em uma classe derivada, o aceita uma mensagem que foi oferecida por esse `ISource` bloco, transferindo a propriedade para o chamador.|
|[acquire_ref](#acquire_ref)|Quando substituído em uma classe derivada, adquire uma contagem de referência nesse bloco de `ISource`, para evitar a exclusão.|
|[consumir](#consume)|Quando substituído em uma classe derivada, consome uma mensagem oferecida anteriormente por esse `ISource` bloco e reservado com êxito pelo destino, transferindo a propriedade para o chamador.|
|[link_target](#link_target)|Quando substituído em uma classe derivada, o vincula um bloco de destino a esse bloco de `ISource`.|
|[release](#release)|Quando substituído em uma classe derivada, libera uma reserva de mensagem anterior bem-sucedida.|
|[release_ref](#release_ref)|Quando substituído em uma classe derivada, libera uma contagem de referência neste `ISource` bloco.|
|[reserve](#reserve)|Quando substituído em uma classe derivada, o reserva uma mensagem anteriormente oferecida por este bloco de `ISource`.|
|[unlink_target](#unlink_target)|Quando substituído em uma classe derivada, desvincula um bloco de destino desse bloco de `ISource`, se for encontrado anteriormente vinculado.|
|[unlink_targets](#unlink_targets)|Quando substituído em uma classe derivada, Desvincula todos os blocos de destino desse bloco de `ISource`.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ISource`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept"></a>aceitar

Quando substituído em uma classe derivada, o aceita uma mensagem que foi oferecida por esse `ISource` bloco, transferindo a propriedade para o chamador.

```cpp
virtual message<T>* accept(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto `message` oferecido.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o método de `accept`.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a mensagem da qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

O método `accept` é chamado por um destino enquanto uma mensagem está sendo oferecida por esse bloco de `ISource`. O ponteiro de mensagem retornado pode ser diferente daquele passado para o método `propagate` do bloco de `ITarget`, se essa fonte decidir fazer uma cópia da mensagem.

## <a name="acquire_ref"></a>acquire_ref

Quando substituído em uma classe derivada, adquire uma contagem de referência nesse bloco de `ISource`, para evitar a exclusão.

```cpp
virtual void acquire_ref(_Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado por um objeto `ITarget` que está sendo vinculado a essa fonte durante o método `link_target`.

## <a name="consume"></a>utilização

Quando substituído em uma classe derivada, consome uma mensagem oferecida anteriormente por esse `ISource` bloco e reservado com êxito pelo destino, transferindo a propriedade para o chamador.

```cpp
virtual message<T>* consume(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
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

## <a name="dtor"></a>~ As

Destrói o objeto `ISource`.

```cpp
virtual ~ISource();
```

## <a name="link_target"></a>link_target

Quando substituído em uma classe derivada, o vincula um bloco de destino a esse bloco de `ISource`.

```cpp
virtual void link_target(_Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está sendo vinculado a este bloco de `ISource`.

## <a name="release"></a>liberar

Quando substituído em uma classe derivada, libera uma reserva de mensagem anterior bem-sucedida.

```cpp
virtual void release(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto `message` reservado.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o método de `release`.

## <a name="release_ref"></a>release_ref

Quando substituído em uma classe derivada, libera uma contagem de referência neste `ISource` bloco.

```cpp
virtual void release_ref(_Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado por um objeto `ITarget` que está sendo desvinculado dessa fonte. O bloco de origem tem permissão para liberar todos os recursos reservados para o bloco de destino.

## <a name="reserve"></a>reservado

Quando substituído em uma classe derivada, o reserva uma mensagem anteriormente oferecida por este bloco de `ISource`.

```cpp
virtual bool reserve(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto `message` oferecido.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o método de `reserve`.

### <a name="return-value"></a>Valor retornado

**true** se a mensagem tiver sido reservada com êxito; caso contrário, **false** . As reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceita por outro destino, a origem poderia negar reservas e assim por diante.

### <a name="remarks"></a>Comentários

Depois de chamar `reserve`, se tiver sucesso, você deverá chamar `consume` ou `release` para tirar ou desistir da posse da mensagem, respectivamente.

## <a name="unlink_target"></a>unlink_target

Quando substituído em uma classe derivada, desvincula um bloco de destino desse bloco de `ISource`, se for encontrado anteriormente vinculado.

```cpp
virtual void unlink_target(_Inout_ ITarget<T>* _PTarget) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está sendo desvinculado deste bloco de `ISource`.

## <a name="unlink_targets"></a>unlink_targets

Quando substituído em uma classe derivada, Desvincula todos os blocos de destino desse bloco de `ISource`.

```cpp
virtual void unlink_targets() = 0;
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe ITarget](itarget-class.md)
