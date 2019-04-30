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
ms.openlocfilehash: 59a0f66a0ba3b10c3307a835ff6ccaa216596538
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64339542"
---
# <a name="itarget-class"></a>Classe ITarget

O `ITarget` classe é a interface de todos os blocos de destino. Blocos de destino consumam mensagens oferecidas a eles por `ISource` blocos.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class ITarget;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados da carga de mensagens é aceito pelo bloco de destino.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`filter_method`|A assinatura de qualquer método usado pelo bloco que retorna um `bool` valor para determinar se uma mensagem oferecida deve ser aceitas.|
|`type`|Um alias de tipo para `T`.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[~ Destruidor ITarget](#dtor)|Destrói o `ITarget` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[propagate](#propagate)|Quando substituído em uma classe derivada, assincronamente transmite uma mensagem de um bloco de código-fonte para este bloco de destino.|
|[send](#send)|Quando substituído em uma classe derivada, passa forma síncrona uma mensagem para o bloco de destino.|
|[supports_anonymous_source](#supports_anonymous_source)|Quando substituído em uma classe derivada, retorna true ou false dependendo se o bloco de mensagens aceite mensagens oferecidas por uma fonte que não está vinculada a ele. Se o método substituído retornar **verdadeira**, o destino não for possível adiar uma mensagem oferecida, como a origem a ser identificados no seu registro do link sourse requer o consumo de uma mensagem adiada em um momento posterior.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[link_source](#link_source)|Quando substituído em uma classe derivada, vincula um bloco de origem especificado a este `ITarget` bloco.|
|[unlink_source](#unlink_source)|Quando substituído em uma classe derivada, desvincula um bloco de origem especificado deste `ITarget` bloco.|
|[unlink_sources](#unlink_sources)|Quando substituído em uma classe derivada, desvincula todos os blocos de código-fonte deste `ITarget` bloco.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ITarget`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

##  <a name="dtor"></a> ~ITarget

Destrói o `ITarget` objeto.

```
virtual ~ITarget();
```

##  <a name="link_source"></a> link_source

Quando substituído em uma classe derivada, vincula um bloco de origem especificado a este `ITarget` bloco.

```
virtual void link_source(_Inout_ ISource<T>* _PSource) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PSource*<br/>
O `ISource` bloquear sendo vinculado a este `ITarget` bloco.

### <a name="remarks"></a>Comentários

Essa função não deve ser chamada diretamente em um `ITarget` bloco. Blocos devem ser conectados usando o `link_target` método no `ISource` blocos, que invocarão o `link_source` método no destino correspondente.

##  <a name="propagate"></a> propagate

Quando substituído em uma classe derivada, assincronamente transmite uma mensagem de um bloco de código-fonte para este bloco de destino.

```
virtual message_status propagate(
    _Inout_opt_ message<T>* _PMessage,
    _Inout_opt_ ISource<T>* _PSource) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o `message` objeto.

*_PSource*<br/>
Um ponteiro para o bloco de código-fonte, oferecendo a mensagem.

### <a name="return-value"></a>Valor de retorno

Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.

### <a name="remarks"></a>Comentários

O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o `_PMessage` ou `_PSource` parâmetro é `NULL`.

##  <a name="send"></a> send

Quando substituído em uma classe derivada, passa forma síncrona uma mensagem para o bloco de destino.

```
virtual message_status send(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o `message` objeto.

*_PSource*<br/>
Um ponteiro para o bloco de código-fonte, oferecendo a mensagem.

### <a name="return-value"></a>Valor de retorno

Um [message_status](concurrency-namespace-enums.md) indicação de que o destino decidiu fazer com a mensagem.

### <a name="remarks"></a>Comentários

O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o `_PMessage` ou `_PSource` parâmetro é `NULL`.

Usando o `send` método fora de iniciação de mensagem e propagar as mensagens em uma rede é perigoso e pode resultar em deadlock.

Quando `send` retorna, a mensagem seja já foi aceita e transferida para o bloco de destino, ou ele foi recusado pelo destino.

##  <a name="supports_anonymous_source"></a> supports_anonymous_source

Quando substituído em uma classe derivada, retorna true ou false dependendo se o bloco de mensagens aceite mensagens oferecidas por uma fonte que não está vinculada a ele. Se o método substituído retornar **verdadeira**, o destino não for possível adiar uma mensagem oferecida, como a origem a ser identificados no seu registro do link sourse requer o consumo de uma mensagem adiada em um momento posterior.

```
virtual bool supports_anonymous_source();
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o bloco pode aceitar a mensagem de uma fonte que não está vinculada a ele **falso** caso contrário.

##  <a name="unlink_source"></a> unlink_source

Quando substituído em uma classe derivada, desvincula um bloco de origem especificado deste `ITarget` bloco.

```
virtual void unlink_source(_Inout_ ISource<T>* _PSource) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PSource*<br/>
O `ISource` bloquear sendo desvinculado deste `ITarget` bloco.

### <a name="remarks"></a>Comentários

Essa função não deve ser chamada diretamente em um `ITarget` bloco. Blocos devem ser desconectados usando o `unlink_target` ou `unlink_targets` métodos `ISource` blocos, que invocarão o `unlink_source` método no destino correspondente.

##  <a name="unlink_sources"></a> unlink_sources

Quando substituído em uma classe derivada, desvincula todos os blocos de código-fonte deste `ITarget` bloco.

```
virtual void unlink_sources() = 0;
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe ISource](isource-class.md)
