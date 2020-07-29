---
title: Classe da chamada
ms.date: 11/04/2016
f1_keywords:
- call
- AGENTS/concurrency::call
- AGENTS/concurrency::call::call
- AGENTS/concurrency::call::process_input_messages
- AGENTS/concurrency::call::process_message
- AGENTS/concurrency::call::propagate_message
- AGENTS/concurrency::call::send_message
- AGENTS/concurrency::call::supports_anonymous_source
helpviewer_keywords:
- call class
ms.assetid: 1521970a-1e9c-4b0c-a681-d18e40976f49
ms.openlocfilehash: d3dc730e19aaadfed171816e92837ba2766883cb
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213873"
---
# <a name="call-class"></a>Classe da chamada

Um `call` bloco de mensagens é uma ordenação de várias fontes `target_block` que invoca uma função especificada ao receber uma mensagem.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T, class _FunctorType = std::function<void(T const&)>>
class call : public target_block<multi_link_registry<ISource<T>>>;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de carga das mensagens propagadas para este bloco.

*_FunctorType*<br/>
A assinatura de funções que esse bloco pode aceitar.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[call](#ctor)|Sobrecarregado. Constrói um `call` bloco de mensagens.|
|[~ chamar destruidor](#dtor)|Destrói o `call` bloco de mensagens.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[process_input_messages](#process_input_messages)|Executa a função Call nas mensagens de entrada.|
|[process_message](#process_message)|Processa uma mensagem que foi aceita por este `call` bloco de mensagens.|
|[propagate_message](#propagate_message)|Transmite de forma assíncrona uma mensagem de um `ISource` bloco para esse `call` bloco de mensagens. Ele é invocado pelo `propagate` método, quando chamado por um bloco de origem.|
|[send_message](#send_message)|Transmite de forma síncrona uma mensagem de um `ISource` bloco para esse `call` bloco de mensagens. Ele é invocado pelo `send` método, quando chamado por um bloco de origem.|
|[supports_anonymous_source](#supports_anonymous_source)|Substitui o `supports_anonymous_source` método para indicar que esse bloco pode aceitar mensagens oferecidas por uma fonte que não está vinculada. (Substitui [ITarget:: supports_anonymous_source](itarget-class.md#supports_anonymous_source).)|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[ITarget](itarget-class.md)

[target_block](target-block-class.md)

`call`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="call"></a><a name="ctor"></a>ligação

Constrói um `call` bloco de mensagens.

```cpp
call(
    _Call_method const& _Func);

call(
    _Call_method const& _Func,
    filter_method const& _Filter);

call(
    Scheduler& _PScheduler,
    _Call_method const& _Func);

call(
    Scheduler& _PScheduler,
    _Call_method const& _Func,
    filter_method const& _Filter);

call(
    ScheduleGroup& _PScheduleGroup,
    _Call_method const& _Func);

call(
    ScheduleGroup& _PScheduleGroup,
    _Call_method const& _Func,
    filter_method const& _Filter);
```

### <a name="parameters"></a>parâmetros

*_Func*<br/>
Uma função que será invocada para cada mensagem aceita.

*_Filter*<br/>
Uma função de filtro que determina se as mensagens oferecidas devem ser aceitas.

*_PScheduler*<br/>
O `Scheduler` objeto no qual a tarefa de propagação para o `call` bloco de mensagens está agendada.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto no qual a tarefa de propagação para o `call` bloco de mensagens está agendada. O `Scheduler` objeto usado é implícito pelo grupo de agendamento.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os `_PScheduler` `_PScheduleGroup` parâmetros ou.

O tipo `_Call_method` é um functor com assinatura `void (T const &)` que é invocada por esse `call` bloco de mensagens para processar uma mensagem.

O tipo `filter_method` é um functor com assinatura `bool (T const &)` que é invocada por esse `call` bloco de mensagens para determinar se ele deve ou não aceitar uma mensagem oferecida.

## <a name="call"></a><a name="dtor"></a>~ chamar

Destrói o `call` bloco de mensagens.

```cpp
~call();
```

## <a name="process_input_messages"></a><a name="process_input_messages"></a>process_input_messages

Executa a função Call nas mensagens de entrada.

```cpp
virtual void process_input_messages(_Inout_ message<T>* _PMessage);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem a ser manipulada.

## <a name="process_message"></a><a name="process_message"></a>process_message

Processa uma mensagem que foi aceita por este `call` bloco de mensagens.

```cpp
virtual void process_message(_Inout_ message<T>* _PMessage);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem a ser manipulada.

## <a name="propagate_message"></a><a name="propagate_message"></a>propagate_message

Transmite de forma assíncrona uma mensagem de um `ISource` bloco para esse `call` bloco de mensagens. Ele é invocado pelo `propagate` método, quando chamado por um bloco de origem.

```cpp
virtual message_status propagate_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md) do que o destino decidiu fazer com a mensagem.

## <a name="send_message"></a><a name="send_message"></a>send_message

Transmite de forma síncrona uma mensagem de um `ISource` bloco para esse `call` bloco de mensagens. Ele é invocado pelo `send` método, quando chamado por um bloco de origem.

```cpp
virtual message_status send_message(
    _Inout_ message<T>* _PMessage,
    _Inout_ ISource<T>* _PSource);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para o objeto `message`.

*_PSource*<br/>
Um ponteiro para o bloco de origem que oferece a mensagem.

### <a name="return-value"></a>Valor retornado

Uma indicação [message_status](concurrency-namespace-enums.md) do que o destino decidiu fazer com a mensagem.

## <a name="supports_anonymous_source"></a><a name="supports_anonymous_source"></a>supports_anonymous_source

Substitui o `supports_anonymous_source` método para indicar que esse bloco pode aceitar mensagens oferecidas por uma fonte que não está vinculada.

```cpp
virtual bool supports_anonymous_source();
```

### <a name="return-value"></a>Valor retornado

**`true`** Porque o bloco não adia mensagens oferecidas.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe de transformador](transformer-class.md)
