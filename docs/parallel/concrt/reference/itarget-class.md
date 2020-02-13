---
title: Classe ITarget
ms.date: 11/04/2016
f1_keywords:
- ITarget
- AGENTS/concurrency::ITarget
- AGENTS/concurrency::ITarget::propagate
- AGENTS/concurrency::ITarget::send
- AGENTS/concurrency::ITarget::supports_anonymous_source
- AGENTS/concurrency::ITarget::link_source
- AGENTS/concurrency::ITarget::unlink_source
- AGENTS/concurrency::ITarget::unlink_sources
helpviewer_keywords:
- ITarget class
ms.assetid: 5678db25-112a-4f72-be13-42e16b67c48b
ms.openlocfilehash: dc9eacad744536e640417a4ebf51b975bd05bcc7
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142031"
---
# <a name="itarget-class"></a>Classe ITarget

A classe `ITarget` é a interface para todos os blocos de destino. Os blocos de destino consomem mensagens oferecidas por blocos de `ISource`.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
class ITarget;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados da carga dentro das mensagens aceitas pelo bloco de destino.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`filter_method`|A assinatura de qualquer método usado pelo bloco que retorna um valor `bool` para determinar se uma mensagem oferecida deve ser aceita.|
|`type`|Um alias de tipo para `T`.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[~ Destruidor ITarget](#dtor)|Destrói o objeto `ITarget`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[propagar](#propagate)|Quando substituído em uma classe derivada, o passa de forma assíncrona uma mensagem de um bloco de origem para esse bloco de destino.|
|[send](#send)|Quando substituído em uma classe derivada, passa sincronamente uma mensagem para o bloco de destino.|
|[supports_anonymous_source](#supports_anonymous_source)|Quando substituído em uma classe derivada, retorna true ou false dependendo se o bloco de mensagem aceita mensagens oferecidas por uma fonte que não está vinculada a ela. Se o método substituído retornar **true**, o destino não poderá adiar uma mensagem oferecida, pois o consumo de uma mensagem adiada em um momento posterior exigirá que a origem seja identificada em seu registro de link de origem.|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[link_source](#link_source)|Quando substituído em uma classe derivada, o vincula um bloco de origem especificado a esse bloco de `ITarget`.|
|[unlink_source](#unlink_source)|Quando substituído em uma classe derivada, desvincula um bloco de origem especificado desse bloco de `ITarget`.|
|[unlink_sources](#unlink_sources)|Quando substituído em uma classe derivada, Desvincula todos os blocos de origem desse bloco de `ITarget`.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ITarget`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="dtor"></a>~ ITarget

Destrói o objeto `ITarget`.

```cpp
virtual ~ITarget();
```

## <a name="link_source"></a>link_source

Quando substituído em uma classe derivada, o vincula um bloco de origem especificado a esse bloco de `ITarget`.

```cpp
virtual void link_source(_Inout_ ISource<T>* _PSource) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PSource*<br/>
O bloco de `ISource` que está sendo vinculado a este bloco de `ITarget`.

### <a name="remarks"></a>Comentários

Essa função não deve ser chamada diretamente em um bloco de `ITarget`. Os blocos devem ser conectados usando o método `link_target` em blocos de `ISource`, que invocarão o método `link_source` no destino correspondente.

## <a name="propagate"></a>propagar

Quando substituído em uma classe derivada, o passa de forma assíncrona uma mensagem de um bloco de origem para esse bloco de destino.

```cpp
virtual message_status propagate(
    _Inout_opt_ message<T>* _PMessage,
    _Inout_opt_ ISource<T>* _PSource) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md) do que o destino decidiu fazer com a mensagem.

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) se o parâmetro `_PMessage` ou `_PSource` for `NULL`.

## <a name="send"></a>Enviar

Quando substituído em uma classe derivada, passa sincronamente uma mensagem para o bloco de destino.

```cpp
virtual message_status send(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md) do que o destino decidiu fazer com a mensagem.

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) se o parâmetro `_PMessage` ou `_PSource` for `NULL`.

O uso do método `send` fora do início da mensagem e a propagação de mensagens em uma rede é perigoso e pode levar a deadlock.

Quando `send` retorna, a mensagem já foi aceita e transferida para o bloco de destino ou foi recusada pelo destino.

## <a name="supports_anonymous_source"></a>supports_anonymous_source

Quando substituído em uma classe derivada, retorna true ou false dependendo se o bloco de mensagem aceita mensagens oferecidas por uma fonte que não está vinculada a ela. Se o método substituído retornar **true**, o destino não poderá adiar uma mensagem oferecida, pois o consumo de uma mensagem adiada em um momento posterior exigirá que a origem seja identificada em seu registro de link sourse.

```cpp
virtual bool supports_anonymous_source();
```

### <a name="return-value"></a>Valor retornado

**true** se o bloco puder aceitar a mensagem de uma fonte que não esteja vinculada a ela **false** caso contrário.

## <a name="unlink_source"></a>unlink_source

Quando substituído em uma classe derivada, desvincula um bloco de origem especificado desse bloco de `ITarget`.

```cpp
virtual void unlink_source(_Inout_ ISource<T>* _PSource) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PSource*<br/>
O bloco de `ISource` que está sendo desvinculado deste bloco de `ITarget`.

### <a name="remarks"></a>Comentários

Essa função não deve ser chamada diretamente em um bloco de `ITarget`. Os blocos devem ser desconectados usando os métodos `unlink_target` ou `unlink_targets` em blocos de `ISource`, o que invocará o método `unlink_source` no destino correspondente.

## <a name="unlink_sources"></a>unlink_sources

Quando substituído em uma classe derivada, Desvincula todos os blocos de origem desse bloco de `ITarget`.

```cpp
virtual void unlink_sources() = 0;
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe ISource](isource-class.md)
