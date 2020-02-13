---
title: Classe propagator_block
ms.date: 11/04/2016
f1_keywords:
- propagator_block
- AGENTS/concurrency::propagator_block
- AGENTS/concurrency::propagator_block::propagator_block
- AGENTS/concurrency::propagator_block::propagate
- AGENTS/concurrency::propagator_block::send
- AGENTS/concurrency::propagator_block::decline_incoming_messages
- AGENTS/concurrency::propagator_block::initialize_source_and_target
- AGENTS/concurrency::propagator_block::link_source
- AGENTS/concurrency::propagator_block::process_input_messages
- AGENTS/concurrency::propagator_block::propagate_message
- AGENTS/concurrency::propagator_block::register_filter
- AGENTS/concurrency::propagator_block::remove_network_links
- AGENTS/concurrency::propagator_block::send_message
- AGENTS/concurrency::propagator_block::unlink_source
- AGENTS/concurrency::propagator_block::unlink_sources
helpviewer_keywords:
- propagator_block class
ms.assetid: 86aa75fd-eda5-42aa-aadf-25c0c1c9742d
ms.openlocfilehash: 340af181669cbbf4c5ba910aa3ee862bd40ba27f
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77138740"
---
# <a name="propagator_block-class"></a>Classe propagator_block

A classe `propagator_block` é uma classe base abstrata para blocos de mensagens que são uma origem e um destino. Ele combina a funcionalidade das classes `source_block` e `target_block`.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _TargetLinkRegistry, class _SourceLinkRegistry, class _MessageProcessorType = ordered_message_processor<typename _TargetLinkRegistry::type::type>>
class propagator_block : public source_block<_TargetLinkRegistry,
    _MessageProcessorType>,
public ITarget<typename _SourceLinkRegistry::type::source_type>;
```

### <a name="parameters"></a>Parâmetros

*_TargetLinkRegistry*<br/>
O registro de link a ser usado para conter os links de destino.

*_SourceLinkRegistry*<br/>
O registro de link a ser usado para conter os links de origem.

*_MessageProcessorType*<br/>
O tipo de processador para processamento de mensagens.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`source_iterator`|O tipo do iterador para o `source_link_manager` para este `propagator_block`.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[propagator_block](#ctor)|Constrói um objeto `propagator_block`.|
|[~ propagator_block destruidor](#dtor)|Destrói um objeto `propagator_block`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[propagar](#propagate)|Transmite de forma assíncrona uma mensagem de um bloco de origem para esse bloco de destino.|
|[send](#send)|Inicia de forma síncrona uma mensagem para esse bloco. Chamado por um bloco de `ISource`. Quando essa função for concluída, a mensagem já será propagada para o bloco.|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[decline_incoming_messages](#decline_incoming_messages)|Indica ao bloco que novas mensagens devem ser recusadas.|
|[initialize_source_and_target](#initialize_source_and_target)|Inicializa o objeto base. Especificamente, o objeto `message_processor` precisa ser inicializado.|
|[link_source](#link_source)|Vincula um bloco de origem especificado a este objeto de `propagator_block`.|
|[process_input_messages](#process_input_messages)|Processar mensagens de entrada. Isso só é útil para blocos de propagadores, que derivam de source_block (Substitui [source_block::p rocess_input_messages](source-block-class.md#process_input_messages).)|
|[propagate_message](#propagate_message)|Quando substituído em uma classe derivada, esse método passa de forma assíncrona uma mensagem de um bloco de `ISource` para esse objeto de `propagator_block`. Ele é invocado pelo método `propagate`, quando chamado por um bloco de origem.|
|[register_filter](#register_filter)|Registra um método de filtro que será invocado em cada mensagem recebida.|
|[remove_network_links](#remove_network_links)|Remove todos os links de rede de origem e de destino deste `propagator_block` objeto.|
|[send_message](#send_message)|Quando substituído em uma classe derivada, esse método transmite de forma síncrona uma mensagem de um bloco de `ISource` para esse objeto `propagator_block`. Ele é invocado pelo método `send`, quando chamado por um bloco de origem.|
|[unlink_source](#unlink_source)|Desvincula um bloco de origem especificado deste `propagator_block` objeto.|
|[unlink_sources](#unlink_sources)|Desvincula todos os blocos de origem deste objeto `propagator_block`. (Substitui [ITarget:: unlink_sources](itarget-class.md#unlink_sources).)|

## <a name="remarks"></a>Comentários

Para evitar várias heranças, a classe `propagator_block` herda da classe `source_block` e `ITarget` classe abstrata. A maioria das funcionalidades na classe `target_block` é replicada aqui.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[As](isource-class.md)

[ITarget](itarget-class.md)

[source_block](source-block-class.md)

`propagator_block`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="decline_incoming_messages"></a>decline_incoming_messages

Indica ao bloco que novas mensagens devem ser recusadas.

```cpp
void decline_incoming_messages();
```

### <a name="remarks"></a>Comentários

Esse método é chamado pelo destruidor para garantir que novas mensagens sejam recusadas enquanto a destruição está em andamento.

## <a name="initialize_source_and_target"></a>initialize_source_and_target

Inicializa o objeto base. Especificamente, o objeto `message_processor` precisa ser inicializado.

```cpp
void initialize_source_and_target(
    _Inout_opt_ Scheduler* _PScheduler = NULL,
    _Inout_opt_ ScheduleGroup* _PScheduleGroup = NULL);
```

### <a name="parameters"></a>Parâmetros

*_PScheduler*<br/>
O Agendador a ser usado para agendar tarefas.

*_PScheduleGroup*<br/>
O grupo de agendamento a ser usado para agendar tarefas.

## <a name="link_source"></a>link_source

Vincula um bloco de origem especificado a este objeto de `propagator_block`.

```cpp
virtual void link_source(_Inout_ ISource<_Source_type>* _PSource);
```

### <a name="parameters"></a>Parâmetros

*_PSource*<br/>
Um ponteiro para o bloco de `ISource` que deve ser vinculado.

## <a name="process_input_messages"></a>process_input_messages

Processar mensagens de entrada. Isso só é útil para blocos de propagadores, que derivam de source_block

```cpp
virtual void process_input_messages(_Inout_ message<_Target_type>* _PMessage);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem a ser processada.

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

O método `propagate` é invocado em um bloco de destino por um bloco de origem vinculado. Ele enfileira uma tarefa assíncrona para manipular a mensagem, se já não estiver na fila ou em execução.

O método gera uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) se o parâmetro `_PMessage` ou `_PSource` for `NULL`.

## <a name="propagate_message"></a>propagate_message

Quando substituído em uma classe derivada, esse método passa de forma assíncrona uma mensagem de um bloco de `ISource` para esse objeto de `propagator_block`. Ele é invocado pelo método `propagate`, quando chamado por um bloco de origem.

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

## <a name="ctor"></a>propagator_block

Constrói um objeto `propagator_block`.

```cpp
propagator_block();
```

## <a name="dtor"></a>~ propagator_block

Destrói um objeto `propagator_block`.

```cpp
virtual ~propagator_block();
```

## <a name="register_filter"></a>register_filter

Registra um método de filtro que será invocado em cada mensagem recebida.

```cpp
void register_filter(filter_method const& _Filter);
```

### <a name="parameters"></a>Parâmetros

*_Filter*<br/>
O método de filtro.

## <a name="remove_network_links"></a>remove_network_links

Remove todos os links de rede de origem e de destino deste `propagator_block` objeto.

```cpp
void remove_network_links();
```

## <a name="send"></a>Enviar

Inicia de forma síncrona uma mensagem para esse bloco. Chamado por um bloco de `ISource`. Quando essa função for concluída, a mensagem já será propagada para o bloco.

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

Esse método gera uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) se o parâmetro `_PMessage` ou `_PSource` for `NULL`.

## <a name="send_message"></a>send_message

Quando substituído em uma classe derivada, esse método transmite de forma síncrona uma mensagem de um bloco de `ISource` para esse objeto `propagator_block`. Ele é invocado pelo método `send`, quando chamado por um bloco de origem.

```cpp
virtual message_status send_message(
    _Inout_ message<_Source_type> *,
    _Inout_ ISource<_Source_type> *);
```

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md) do que o destino decidiu fazer com a mensagem.

### <a name="remarks"></a>Comentários

Por padrão, esse bloco retorna `declined`, a menos que seja substituído por uma classe derivada.

## <a name="unlink_source"></a>unlink_source

Desvincula um bloco de origem especificado deste `propagator_block` objeto.

```cpp
virtual void unlink_source(_Inout_ ISource<_Source_type>* _PSource);
```

### <a name="parameters"></a>Parâmetros

*_PSource*<br/>
Um ponteiro para o bloco de `ISource` que deve ser desvinculado.

## <a name="unlink_sources"></a>unlink_sources

Desvincula todos os blocos de origem deste objeto `propagator_block`.

```cpp
virtual void unlink_sources();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe source_block](source-block-class.md)<br/>
[Classe ITarget](itarget-class.md)
