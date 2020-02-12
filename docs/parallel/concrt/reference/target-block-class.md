---
title: Classe target_block
ms.date: 11/04/2016
f1_keywords:
- target_block
- AGENTS/concurrency::target_block
- AGENTS/concurrency::target_block::target_block
- AGENTS/concurrency::target_block::propagate
- AGENTS/concurrency::target_block::send
- AGENTS/concurrency::target_block::async_send
- AGENTS/concurrency::target_block::decline_incoming_messages
- AGENTS/concurrency::target_block::enable_batched_processing
- AGENTS/concurrency::target_block::initialize_target
- AGENTS/concurrency::target_block::link_source
- AGENTS/concurrency::target_block::process_input_messages
- AGENTS/concurrency::target_block::process_message
- AGENTS/concurrency::target_block::propagate_message
- AGENTS/concurrency::target_block::register_filter
- AGENTS/concurrency::target_block::remove_sources
- AGENTS/concurrency::target_block::send_message
- AGENTS/concurrency::target_block::sync_send
- AGENTS/concurrency::target_block::unlink_source
- AGENTS/concurrency::target_block::unlink_sources
- AGENTS/concurrency::target_block::wait_for_async_sends
helpviewer_keywords:
- target_block class
ms.assetid: 3ce181b4-b94a-4894-bf7b-64fc09821f9f
ms.openlocfilehash: 4009133161133a99aeb0ee040f0c82fdbabecaa0
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142648"
---
# <a name="target_block-class"></a>Classe target_block

A classe `target_block` é uma classe base abstrata que fornece funcionalidade básica de gerenciamento de link e verificação de erros para blocos somente de destino.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _SourceLinkRegistry, class _MessageProcessorType = ordered_message_processor<typename _SourceLinkRegistry::type::source_type>>
class target_block : public ITarget<typename _SourceLinkRegistry::type::source_type>;
```

### <a name="parameters"></a>Parâmetros

*_SourceLinkRegistry*<br/>
O registro de link a ser usado para conter os links de origem.

*_MessageProcessorType*<br/>
O tipo de processador para processamento de mensagens.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`source_iterator`|O tipo do iterador para o `source_link_manager` para este objeto de `target_block`.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[target_block](#ctor)|Constrói um objeto `target_block`.|
|[~ target_block destruidor](#dtor)|Destrói o objeto `target_block`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[propagar](#propagate)|Transmite de forma assíncrona uma mensagem de um bloco de origem para esse bloco de destino.|
|[send](#send)|Transmite de forma síncrona uma mensagem de um bloco de origem para esse bloco de destino.|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[async_send](#async_send)|Envia de forma assíncrona uma mensagem para processamento.|
|[decline_incoming_messages](#decline_incoming_messages)|Indica ao bloco que novas mensagens devem ser recusadas.|
|[enable_batched_processing](#enable_batched_processing)|Habilita o processamento em lote para este bloco.|
|[initialize_target](#initialize_target)|Inicializa o objeto base. Especificamente, o objeto `message_processor` precisa ser inicializado.|
|[link_source](#link_source)|Vincula um bloco de origem especificado a este objeto de `target_block`.|
|[process_input_messages](#process_input_messages)|Processa mensagens que são recebidas como entradas.|
|[process_message](#process_message)|Quando substituído em uma classe derivada, o processa uma mensagem que foi aceita por este `target_block` objeto.|
|[propagate_message](#propagate_message)|Quando substituído em uma classe derivada, esse método passa de forma assíncrona uma mensagem de um bloco de `ISource` para esse objeto de `target_block`. Ele é invocado pelo método `propagate`, quando chamado por um bloco de origem.|
|[register_filter](#register_filter)|Registra um método de filtro que será invocado em cada mensagem recebida.|
|[remove_sources](#remove_sources)|Desvincula todas as fontes depois de aguardar a conclusão de operações de envio assíncronas pendentes.|
|[send_message](#send_message)|Quando substituído em uma classe derivada, esse método transmite de forma síncrona uma mensagem de um bloco de `ISource` para esse objeto `target_block`. Ele é invocado pelo método `send`, quando chamado por um bloco de origem.|
|[sync_send](#sync_send)|Envie de forma síncrona uma mensagem para processamento.|
|[unlink_source](#unlink_source)|Desvincula um bloco de origem especificado deste `target_block` objeto.|
|[unlink_sources](#unlink_sources)|Desvincula todos os blocos de origem deste objeto `target_block`. (Substitui [ITarget:: unlink_sources](itarget-class.md#unlink_sources).)|
|[wait_for_async_sends](#wait_for_async_sends)|Aguarda a conclusão de todas as propagações assíncronas.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[ITarget](itarget-class.md)

`target_block`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="async_send"></a>async_send

Envia de forma assíncrona uma mensagem para processamento.

```cpp
void async_send(_Inout_opt_ message<_Source_type>* _PMessage);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem que está sendo enviada.

## <a name="decline_incoming_messages"></a>decline_incoming_messages

Indica ao bloco que novas mensagens devem ser recusadas.

```cpp
void decline_incoming_messages();
```

### <a name="remarks"></a>Comentários

Esse método é chamado pelo destruidor para garantir que novas mensagens sejam recusadas enquanto a destruição está em andamento.

## <a name="enable_batched_processing"></a>enable_batched_processing

Habilita o processamento em lote para este bloco.

```cpp
void enable_batched_processing();
```

## <a name="initialize_target"></a>initialize_target

Inicializa o objeto base. Especificamente, o objeto `message_processor` precisa ser inicializado.

```cpp
void initialize_target(
    _Inout_opt_ Scheduler* _PScheduler = NULL,
    _Inout_opt_ ScheduleGroup* _PScheduleGroup = NULL);
```

### <a name="parameters"></a>Parâmetros

*_PScheduler*<br/>
O Agendador a ser usado para agendar tarefas.

*_PScheduleGroup*<br/>
O grupo de agendamento a ser usado para agendar tarefas.

## <a name="link_source"></a>link_source

Vincula um bloco de origem especificado a este objeto de `target_block`.

```cpp
virtual void link_source(_Inout_ ISource<_Source_type>* _PSource);
```

### <a name="parameters"></a>Parâmetros

*_PSource*<br/>
Um ponteiro para o bloco de `ISource` que deve ser vinculado.

### <a name="remarks"></a>Comentários

Essa função não deve ser chamada diretamente em um objeto `target_block`. Os blocos devem ser conectados usando o método `link_target` em blocos de `ISource`, que invocarão o método `link_source` no destino correspondente.

## <a name="process_input_messages"></a>process_input_messages

Processa mensagens que são recebidas como entradas.

```cpp
virtual void process_input_messages(_Inout_ message<_Source_type>* _PMessage);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem a ser processada.

## <a name="process_message"></a>process_message

Quando substituído em uma classe derivada, o processa uma mensagem que foi aceita por este `target_block` objeto.

```cpp
virtual void process_message(message<_Source_type> *);
```

## <a name="propagate"></a>propagar

Transmite de forma assíncrona uma mensagem de um bloco de origem para esse bloco de destino.

```cpp
virtual message_status propagate(
    _Inout_opt_ message<_Source_type>* _PMessage,
    _Inout_opt_ ISource<_Source_type>* _PSource);
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

## <a name="propagate_message"></a>propagate_message

Quando substituído em uma classe derivada, esse método passa de forma assíncrona uma mensagem de um bloco de `ISource` para esse objeto de `target_block`. Ele é invocado pelo método `propagate`, quando chamado por um bloco de origem.

```cpp
virtual message_status propagate_message(
    _Inout_ message<_Source_type>* _PMessage,
    _Inout_ ISource<_Source_type>* _PSource) = 0;
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md) do que o destino decidiu fazer com a mensagem.

## <a name="register_filter"></a>register_filter

Registra um método de filtro que será invocado em cada mensagem recebida.

```cpp
void register_filter(filter_method const& _Filter);
```

### <a name="parameters"></a>Parâmetros

*_Filter*<br/>
O método de filtro.

## <a name="remove_sources"></a>remove_sources

Desvincula todas as fontes depois de aguardar a conclusão de operações de envio assíncronas pendentes.

```cpp
void remove_sources();
```

### <a name="remarks"></a>Comentários

Todos os blocos de destino devem chamar essa rotina para remover as fontes em seu destruidor.

## <a name="send"></a>Enviar

Transmite de forma síncrona uma mensagem de um bloco de origem para esse bloco de destino.

```cpp
virtual message_status send(
    _Inout_ message<_Source_type>* _PMessage,
    _Inout_ ISource<_Source_type>* _PSource);
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

## <a name="send_message"></a>send_message

Quando substituído em uma classe derivada, esse método transmite de forma síncrona uma mensagem de um bloco de `ISource` para esse objeto `target_block`. Ele é invocado pelo método `send`, quando chamado por um bloco de origem.

```cpp
virtual message_status send_message(
    _Inout_ message<_Source_type> *,
    _Inout_ ISource<_Source_type> *);
```

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md) do que o destino decidiu fazer com a mensagem.

### <a name="remarks"></a>Comentários

Por padrão, esse bloco retorna `declined`, a menos que seja substituído por uma classe derivada.

## <a name="sync_send"></a>sync_send

Envie de forma síncrona uma mensagem para processamento.

```cpp
void sync_send(_Inout_opt_ message<_Source_type>* _PMessage);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem que está sendo enviada.

## <a name="ctor"></a>target_block

Constrói um objeto `target_block`.

```cpp
target_block();
```

## <a name="dtor"></a>~ target_block

Destrói o objeto `target_block`.

```cpp
virtual ~target_block();
```

## <a name="unlink_source"></a>unlink_source

Desvincula um bloco de origem especificado deste `target_block` objeto.

```cpp
virtual void unlink_source(_Inout_ ISource<_Source_type>* _PSource);
```

### <a name="parameters"></a>Parâmetros

*_PSource*<br/>
Um ponteiro para o bloco de `ISource` que deve ser desvinculado.

## <a name="unlink_sources"></a>unlink_sources

Desvincula todos os blocos de origem deste objeto `target_block`.

```cpp
virtual void unlink_sources();
```

## <a name="wait_for_async_sends"></a>wait_for_async_sends

Aguarda a conclusão de todas as propagações assíncronas.

```cpp
void wait_for_async_sends();
```

### <a name="remarks"></a>Comentários

Esse método é usado por destruidores de bloco de mensagem para garantir que todas as operações assíncronas tenham tempo para serem concluídas antes de destruir o bloco.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe ITarget](itarget-class.md)
