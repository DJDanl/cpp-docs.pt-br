---
title: Classe ordered_message_processor
ms.date: 11/04/2016
f1_keywords:
- ordered_message_processor
- AGENTS/concurrency::ordered_message_processor
- AGENTS/concurrency::ordered_message_processor::ordered_message_processor
- AGENTS/concurrency::ordered_message_processor::async_send
- AGENTS/concurrency::ordered_message_processor::initialize
- AGENTS/concurrency::ordered_message_processor::initialize_batched_processing
- AGENTS/concurrency::ordered_message_processor::sync_send
- AGENTS/concurrency::ordered_message_processor::wait
- AGENTS/concurrency::ordered_message_processor::process_incoming_message
helpviewer_keywords:
- ordered_message_processor class
ms.assetid: 787adfb7-7f79-4a70-864a-80e3b64088cd
ms.openlocfilehash: ea9ca799f36cac0d843a578eb7cef9c1e9c5cda6
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77138779"
---
# <a name="ordered_message_processor-class"></a>Classe ordered_message_processor

Uma `ordered_message_processor` é uma `message_processor` que permite que os blocos de mensagens processem as mensagens na ordem em que foram recebidas.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
class ordered_message_processor : public message_processor<T>;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de carga de mensagens tratadas pelo processador.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`type`|Um alias de tipo para `T`.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[ordered_message_processor](#ctor)|Constrói um objeto `ordered_message_processor`.|
|[~ ordered_message_processor destruidor](#dtor)|Destrói o objeto `ordered_message_processor`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[async_send](#async_send)|O Enfileira mensagens de forma assíncrona e inicia uma tarefa de processamento, se isso ainda não tiver sido feito. (Substitui [message_processor:: async_send](message-processor-class.md#async_send).)|
|[inicializar](#initialize)|Inicializa o objeto `ordered_message_processor` com a função de retorno de chamada, o Agendador e o grupo de agendamento apropriados.|
|[initialize_batched_processing](#initialize_batched_processing)|Inicializar o processamento de mensagens em lote|
|[sync_send](#sync_send)|O enfileira as mensagens de forma síncrona e inicia uma tarefa de processamento, se isso ainda não tiver sido feito. (Substitui [message_processor:: sync_send](message-processor-class.md#sync_send).)|
|[esperado](#wait)|Uma espera de rotação específica do processador usada em destruidores de blocos de mensagens para garantir que todas as tarefas de processamento assíncrono tenham tempo para serem concluídas antes da destruição do bloco. (Substitui [message_processor:: Wait](message-processor-class.md#wait).)|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[process_incoming_message](#process_incoming_message)|A função de processamento que é chamada de forma assíncrona. Ele removerá as mensagens da fila e começará a processá-las. (Substitui [message_processor::p rocess_incoming_message](message-processor-class.md#process_incoming_message).)|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[message_processor](message-processor-class.md)

`ordered_message_processor`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="async_send"></a>async_send

O Enfileira mensagens de forma assíncrona e inicia uma tarefa de processamento, se isso ainda não tiver sido feito.

```cpp
virtual void async_send(_Inout_opt_ message<T>* _Msg);
```

### <a name="parameters"></a>Parâmetros

*_Msg*<br/>
Um ponteiro para uma mensagem.

## <a name="initialize"></a>inicializar

Inicializa o objeto `ordered_message_processor` com a função de retorno de chamada, o Agendador e o grupo de agendamento apropriados.

```cpp
void initialize(
    _Inout_opt_ Scheduler* _PScheduler,
    _Inout_opt_ ScheduleGroup* _PScheduleGroup,
    _Handler_method const& _Handler);
```

### <a name="parameters"></a>Parâmetros

*_PScheduler*<br/>
Um ponteiro para o Agendador a ser usado para agendar tarefas de peso leve.

*_PScheduleGroup*<br/>
Um ponteiro para o grupo de agendamento a ser usado para agendar tarefas de peso leve.

*_Handler*<br/>
O manipulador functor invocado durante o retorno de chamada.

## <a name="initialize_batched_processing"></a>initialize_batched_processing

Inicializar o processamento de mensagens em lote

```cpp
virtual void initialize_batched_processing(
    _Handler_method const& _Processor,
    _Propagator_method const& _Propagator);
```

### <a name="parameters"></a>Parâmetros

*_Processor*<br/>
O functor do processador foi invocado durante o retorno de chamada.

*_Propagator*<br/>
O propagador functor invocado durante o retorno de chamada.

## <a name="ctor"></a>ordered_message_processor

Constrói um objeto `ordered_message_processor`.

```cpp
ordered_message_processor();
```

### <a name="remarks"></a>Comentários

Essa `ordered_message_processor` não agendará manipuladores assíncronos ou síncronos até que a função `initialize` seja chamada.

## <a name="dtor"></a>~ ordered_message_processor

Destrói o objeto `ordered_message_processor`.

```cpp
virtual ~ordered_message_processor();
```

### <a name="remarks"></a>Comentários

Aguarda todas as operações assíncronas pendentes antes de destruir o processador.

## <a name="process_incoming_message"></a>process_incoming_message

A função de processamento que é chamada de forma assíncrona. Ele removerá as mensagens da fila e começará a processá-las.

```cpp
virtual void process_incoming_message();
```

## <a name="sync_send"></a>sync_send

O enfileira as mensagens de forma síncrona e inicia uma tarefa de processamento, se isso ainda não tiver sido feito.

```cpp
virtual void sync_send(_Inout_opt_ message<T>* _Msg);
```

### <a name="parameters"></a>Parâmetros

*_Msg*<br/>
Um ponteiro para uma mensagem.

## <a name="wait"></a>esperado

Uma espera de rotação específica do processador usada em destruidores de blocos de mensagens para garantir que todas as tarefas de processamento assíncrono tenham tempo para serem concluídas antes da destruição do bloco.

```cpp
virtual void wait();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
