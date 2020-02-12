---
title: Classe message_processor
ms.date: 11/04/2016
f1_keywords:
- message_processor
- AGENTS/concurrency::message_processor
- AGENTS/concurrency::message_processor::async_send
- AGENTS/concurrency::message_processor::sync_send
- AGENTS/concurrency::message_processor::wait
- AGENTS/concurrency::message_processor::process_incoming_message
helpviewer_keywords:
- message_processor class
ms.assetid: 23afb052-daa7-44ed-bf24-d2513db748da
ms.openlocfilehash: 88944b2d935eebd0e031be1431c2a0f4efa3d760
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77139478"
---
# <a name="message_processor-class"></a>Classe message_processor

A classe `message_processor` é a classe base abstrata para o processamento de objetos `message`. Não há nenhuma garantia na ordenação das mensagens.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
class message_processor;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados da carga dentro das mensagens tratadas por este `message_processor` objeto.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`type`|Um alias de tipo para `T`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[async_send](#async_send)|Quando substituído em uma classe derivada, coloca as mensagens no bloco de forma assíncrona.|
|[sync_send](#sync_send)|Quando substituído em uma classe derivada, coloca as mensagens no bloco de forma síncrona.|
|[esperado](#wait)|Quando substituído em uma classe derivada, aguarda a conclusão de todas as operações assíncronas.|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[process_incoming_message](#process_incoming_message)|Quando substituído em uma classe derivada, executa o processamento progressivo de mensagens no bloco. Chamado uma vez toda vez que uma nova mensagem é adicionada e a fila é considerada vazia.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`message_processor`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="async_send"></a>async_send

Quando substituído em uma classe derivada, coloca as mensagens no bloco de forma assíncrona.

```cpp
virtual void async_send(_Inout_opt_ message<T>* _Msg) = 0;
```

### <a name="parameters"></a>Parâmetros

*_Msg*<br/>
Um objeto `message` para enviar de forma assíncrona.

### <a name="remarks"></a>Comentários

Implementações de processador devem substituir esse método.

## <a name="process_incoming_message"></a>process_incoming_message

Quando substituído em uma classe derivada, executa o processamento progressivo de mensagens no bloco. Chamado uma vez toda vez que uma nova mensagem é adicionada e a fila é considerada vazia.

```cpp
virtual void process_incoming_message() = 0;
```

### <a name="remarks"></a>Comentários

As implementações de bloco de mensagem devem substituir esse método.

## <a name="sync_send"></a>sync_send

Quando substituído em uma classe derivada, coloca as mensagens no bloco de forma síncrona.

```cpp
virtual void sync_send(_Inout_opt_ message<T>* _Msg) = 0;
```

### <a name="parameters"></a>Parâmetros

*_Msg*<br/>
Um objeto `message` para enviar de forma síncrona.

### <a name="remarks"></a>Comentários

Implementações de processador devem substituir esse método.

## <a name="wait"></a>esperado

Quando substituído em uma classe derivada, aguarda a conclusão de todas as operações assíncronas.

```cpp
virtual void wait() = 0;
```

### <a name="remarks"></a>Comentários

Implementações de processador devem substituir esse método.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe ordered_message_processor](ordered-message-processor-class.md)
