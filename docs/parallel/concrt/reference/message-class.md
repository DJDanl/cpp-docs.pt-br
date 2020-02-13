---
title: Classe message
ms.date: 11/04/2016
f1_keywords:
- message
- AGENTS/concurrency::message
- AGENTS/concurrency::message::message
- AGENTS/concurrency::message::add_ref
- AGENTS/concurrency::message::msg_id
- AGENTS/concurrency::message::remove_ref
- AGENTS/concurrency::message::payload
helpviewer_keywords:
- message class
ms.assetid: 3e1f3505-6c0c-486c-8191-666d0880ec62
ms.openlocfilehash: 700d052b6f22c970387a3ab45d299538a5b74e1b
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77139537"
---
# <a name="message-class"></a>Classe message

O envelope de mensagem básico que contém a carga de dados que está sendo passada entre os blocos de mensagens.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
class message : public ::Concurrency::details::_Runtime_object;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados da carga dentro da mensagem.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`type`|Um alias de tipo para `T`.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[message](#ctor)|Sobrecarregado. Constrói um objeto `message`.|
|[~ Destruidor de mensagem](#dtor)|Destrói o objeto `message`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[add_ref](#add_ref)|Adiciona à contagem de referência para o objeto `message`. Usado para blocos de mensagens que precisam de contagem de referência para determinar os tempos de vida da mensagem.|
|[msg_id](#msg_id)|Retorna a ID do objeto de `message`.|
|[remove_ref](#remove_ref)|Subtrai da contagem de referência para o objeto `message`. Usado para blocos de mensagens que precisam de contagem de referência para determinar os tempos de vida da mensagem.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[payload](#payload)|A carga do objeto de `message`.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`message`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="add_ref"></a>add_ref

Adiciona à contagem de referência para o objeto `message`. Usado para blocos de mensagens que precisam de contagem de referência para determinar os tempos de vida da mensagem.

```cpp
long add_ref();
```

### <a name="return-value"></a>Valor retornado

O novo valor da contagem de referência.

## <a name="ctor"></a>Mensagem

Constrói um objeto `message`.

```cpp
message(
    T const& _P);

message(
    T const& _P,
    runtime_object_identity _Id);

message(
    message const& _Msg);

message(
    _In_ message const* _Msg);
```

### <a name="parameters"></a>Parâmetros

*_P*<br/>
A carga desta mensagem.

*_Id*<br/>
A ID exclusiva desta mensagem.

*_Msg*<br/>
Uma referência ou um ponteiro para um objeto `message`.

### <a name="remarks"></a>Comentários

O construtor que usa um ponteiro para um objeto `message` como um argumento gera uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) se o parâmetro `_Msg` for `NULL`.

## <a name="dtor"></a>~ mensagem

Destrói o objeto `message`.

```cpp
virtual ~message();
```

## <a name="msg_id"></a>msg_id

Retorna a ID do objeto de `message`.

```cpp
runtime_object_identity msg_id() const;
```

### <a name="return-value"></a>Valor retornado

O `runtime_object_identity` do objeto `message`.

## <a name="payload"></a>carga

A carga do objeto de `message`.

```cpp
T const payload;
```

## <a name="remove_ref"></a>remove_ref

Subtrai da contagem de referência para o objeto `message`. Usado para blocos de mensagens que precisam de contagem de referência para determinar os tempos de vida da mensagem.

```cpp
long remove_ref();
```

### <a name="return-value"></a>Valor retornado

O novo valor da contagem de referência.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
