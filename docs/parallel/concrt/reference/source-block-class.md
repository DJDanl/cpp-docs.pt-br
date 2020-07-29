---
title: Classe source_block
ms.date: 11/04/2016
f1_keywords:
- source_block
- AGENTS/concurrency::source_block
- AGENTS/concurrency::source_block::source_block
- AGENTS/concurrency::source_block::accept
- AGENTS/concurrency::source_block::acquire_ref
- AGENTS/concurrency::source_block::consume
- AGENTS/concurrency::source_block::link_target
- AGENTS/concurrency::source_block::release
- AGENTS/concurrency::source_block::release_ref
- AGENTS/concurrency::source_block::reserve
- AGENTS/concurrency::source_block::unlink_target
- AGENTS/concurrency::source_block::unlink_targets
- AGENTS/concurrency::source_block::accept_message
- AGENTS/concurrency::source_block::async_send
- AGENTS/concurrency::source_block::consume_message
- AGENTS/concurrency::source_block::enable_batched_processing
- AGENTS/concurrency::source_block::initialize_source
- AGENTS/concurrency::source_block::link_target_notification
- AGENTS/concurrency::source_block::process_input_messages
- AGENTS/concurrency::source_block::propagate_output_messages
- AGENTS/concurrency::source_block::propagate_to_any_targets
- AGENTS/concurrency::source_block::release_message
- AGENTS/concurrency::source_block::remove_targets
- AGENTS/concurrency::source_block::reserve_message
- AGENTS/concurrency::source_block::resume_propagation
- AGENTS/concurrency::source_block::sync_send
- AGENTS/concurrency::source_block::unlink_target_notification
- AGENTS/concurrency::source_block::wait_for_outstanding_async_sends
helpviewer_keywords:
- source_block class
ms.assetid: fbdd4146-e8d0-42e8-b714-fe633f69ffbf
ms.openlocfilehash: 304bc65d969fa677d67bf578021a63f628e0a1f5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228434"
---
# <a name="source_block-class"></a>Classe source_block

A `source_block` classe é uma classe base abstrata para blocos somente de origem. A classe fornece a funcionalidade básica de gerenciamento de link, bem como verificações de erro comuns.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _TargetLinkRegistry, class _MessageProcessorType = ordered_message_processor<typename _TargetLinkRegistry::type::type>>
class source_block : public ISource<typename _TargetLinkRegistry::type::type>;
```

### <a name="parameters"></a>parâmetros

*_TargetLinkRegistry*<br/>
Registro de link a ser usado para conter os links de destino.

*_MessageProcessorType*<br/>
Tipo de processador para processamento de mensagens.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`target_iterator`|O iterador para percorrer os destinos conectados.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[source_block](#ctor)|Constrói um objeto `source_block`.|
|[~ source_block destruidor](#dtor)|Destrói o `source_block` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[aceitar](#accept)|Aceita uma mensagem que foi oferecida por este `source_block` objeto, transferindo a propriedade para o chamador.|
|[acquire_ref](#acquire_ref)|Adquire uma contagem de referência neste `source_block` objeto para evitar a exclusão.|
|[utilização](#consume)|Consome uma mensagem fornecida anteriormente por esse `source_block` objeto e reservada com êxito pelo destino, transferindo a propriedade para o chamador.|
|[link_target](#link_target)|Vincula um bloco de destino a este `source_block` objeto.|
|[liberar](#release)|Libera uma reserva de mensagem anterior bem-sucedida.|
|[release_ref](#release_ref)|Libera uma contagem de referência neste `source_block` objeto.|
|[reservado](#reserve)|Reserva uma mensagem oferecida anteriormente por este `source_block` objeto.|
|[unlink_target](#unlink_target)|Desvincula um bloco de destino deste `source_block` objeto.|
|[unlink_targets](#unlink_targets)|Desvincula todos os blocos de destino deste `source_block` objeto. (Substitui [as:: unlink_targets](isource-class.md#unlink_targets).)|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Quando substituído em uma classe derivada, o aceita uma mensagem oferecida pela origem. Os blocos de mensagens devem substituir esse método para validar o `_MsgId` e retornar uma mensagem.|
|[async_send](#async_send)|Enfileira mensagens de forma assíncrona e inicia uma tarefa de propagação, se isso ainda não tiver sido feito|
|[consume_message](#consume_message)|Quando substituído em uma classe derivada, consome uma mensagem que foi reservada anteriormente.|
|[enable_batched_processing](#enable_batched_processing)|Habilita o processamento em lote para este bloco.|
|[initialize_source](#initialize_source)|Inicializa o `message_propagator` dentro dele `source_block` .|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a esse `source_block` objeto.|
|[process_input_messages](#process_input_messages)|Processar mensagens de entrada. Isso só é útil para blocos de propagadores, que derivam de source_block|
|[propagate_output_messages](#propagate_output_messages)|Propagar mensagens para destinos.|
|[propagate_to_any_targets](#propagate_to_any_targets)|Quando substituído em uma classe derivada, o propaga a mensagem determinada para qualquer um ou todos os destinos vinculados. Essa é a rotina de propagação principal para blocos de mensagens.|
|[release_message](#release_message)|Quando substituído em uma classe derivada, libera uma reserva de mensagem anterior.|
|[remove_targets](#remove_targets)|Remove todos os links de destino para este bloco de origem. Isso deve ser chamado a partir do destruidor.|
|[reserve_message](#reserve_message)|Quando substituído em uma classe derivada, o reserva uma mensagem anteriormente oferecida por esse `source_block` objeto.|
|[resume_propagation](#resume_propagation)|Quando substituído em uma classe derivada, retoma a propagação após o lançamento de uma reserva.|
|[sync_send](#sync_send)|O enfileira as mensagens de forma síncrona e inicia uma tarefa de propagação, se isso ainda não tiver sido feito.|
|[unlink_target_notification](#unlink_target_notification)|Um retorno de chamada que notifica que um destino foi desvinculado deste `source_block` objeto.|
|[wait_for_outstanding_async_sends](#wait_for_outstanding_async_sends)|Aguarda a conclusão de todas as propagações assíncronas. Essa espera de rotação específica do propagador é usada em destruidores de blocos de mensagens para garantir que todas as propagações assíncronas tenham tempo para serem concluídas antes de destruir o bloco.|

## <a name="remarks"></a>Comentários

Os blocos de mensagens devem derivar desse bloco para aproveitar o gerenciamento de links e a sincronização fornecidos por essa classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[As](isource-class.md)

`source_block`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept"></a><a name="accept"></a>aceitar

Aceita uma mensagem que foi oferecida por este `source_block` objeto, transferindo a propriedade para o chamador.

```cpp
virtual message<_Target_type>* accept(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto oferecido `message` .

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `accept` método.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) se o parâmetro `_PTarget` é `NULL` .

O `accept` método é chamado por um destino enquanto uma mensagem está sendo oferecida por `ISource` esse bloco. O ponteiro de mensagem retornado pode ser diferente daquele passado para o `propagate` método do `ITarget` bloco, se essa fonte decidir fazer uma cópia da mensagem.

## <a name="accept_message"></a><a name="accept_message"></a>accept_message

Quando substituído em uma classe derivada, o aceita uma mensagem oferecida pela origem. Os blocos de mensagens devem substituir esse método para validar o `_MsgId` e retornar uma mensagem.

```cpp
virtual message<_Target_type>* accept_message(runtime_object_identity _MsgId) = 0;
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
A identidade do objeto de tempo de execução do `message` objeto.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a mensagem da qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

Para transferir a propriedade, o ponteiro de mensagem original deve ser retornado. Para manter a propriedade, uma cópia da carga da mensagem precisa ser feita e retornada.

## <a name="acquire_ref"></a><a name="acquire_ref"></a>acquire_ref

Adquire uma contagem de referência neste `source_block` objeto para evitar a exclusão.

```cpp
virtual void acquire_ref(_Inout_ ITarget<_Target_type> *);
```

### <a name="remarks"></a>Comentários

Esse método é chamado por um `ITarget` objeto que está sendo vinculado a essa origem durante o `link_target` método.

## <a name="async_send"></a><a name="async_send"></a>async_send

Enfileira mensagens de forma assíncrona e inicia uma tarefa de propagação, se isso ainda não tiver sido feito

```cpp
virtual void async_send(_Inout_opt_ message<_Target_type>* _Msg);
```

### <a name="parameters"></a>parâmetros

*_Msg*<br/>
Um ponteiro para um `message` objeto a ser enviado de forma assíncrona.

## <a name="consume"></a><a name="consume"></a>utilização

Consome uma mensagem fornecida anteriormente por esse `source_block` objeto e reservada com êxito pelo destino, transferindo a propriedade para o chamador.

```cpp
virtual message<_Target_type>* consume(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto reservado `message` .

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `consume` método.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) se o parâmetro `_PTarget` é `NULL` .

O método gera uma exceção [bad_target](bad-target-class.md) se o parâmetro `_PTarget` não representar o destino que chamou `reserve` .

O `consume` método é semelhante a `accept` , mas sempre deve ser precedido por uma chamada para `reserve` isso retornado **`true`** .

## <a name="consume_message"></a><a name="consume_message"></a>consume_message

Quando substituído em uma classe derivada, consome uma mensagem que foi reservada anteriormente.

```cpp
virtual message<_Target_type>* consume_message(runtime_object_identity _MsgId) = 0;
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo consumido.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a mensagem da qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

Semelhante a `accept` , mas é sempre precedido por uma chamada para `reserve` .

## <a name="enable_batched_processing"></a><a name="enable_batched_processing"></a>enable_batched_processing

Habilita o processamento em lote para este bloco.

```cpp
void enable_batched_processing();
```

## <a name="initialize_source"></a><a name="initialize_source"></a>initialize_source

Inicializa o `message_propagator` dentro dele `source_block` .

```cpp
void initialize_source(
    _Inout_opt_ Scheduler* _PScheduler = NULL,
    _Inout_opt_ ScheduleGroup* _PScheduleGroup = NULL);
```

### <a name="parameters"></a>parâmetros

*_PScheduler*<br/>
O Agendador a ser usado para agendar tarefas.

*_PScheduleGroup*<br/>
O grupo de agendamento a ser usado para agendar tarefas.

## <a name="link_target"></a><a name="link_target"></a>link_target

Vincula um bloco de destino a este `source_block` objeto.

```cpp
virtual void link_target(_Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para um `ITarget` bloco a ser vinculado a este `source_block` objeto.

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) se o parâmetro `_PTarget` é `NULL` .

## <a name="link_target_notification"></a><a name="link_target_notification"></a>link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a esse `source_block` objeto.

```cpp
virtual void link_target_notification(_Inout_ ITarget<_Target_type> *);
```

## <a name="process_input_messages"></a><a name="process_input_messages"></a>process_input_messages

Processar mensagens de entrada. Isso só é útil para blocos de propagadores, que derivam de source_block

```cpp
virtual void process_input_messages(_Inout_ message<_Target_type>* _PMessage);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem a ser processada.

## <a name="propagate_output_messages"></a><a name="propagate_output_messages"></a>propagate_output_messages

Propagar mensagens para destinos.

```cpp
virtual void propagate_output_messages();
```

## <a name="propagate_to_any_targets"></a><a name="propagate_to_any_targets"></a>propagate_to_any_targets

Quando substituído em uma classe derivada, o propaga a mensagem determinada para qualquer um ou todos os destinos vinculados. Essa é a rotina de propagação principal para blocos de mensagens.

```cpp
virtual void propagate_to_any_targets(_Inout_opt_ message<_Target_type>* _PMessage);
```

### <a name="parameters"></a>parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem a ser propagada.

## <a name="release"></a><a name="release"></a>liberar

Libera uma reserva de mensagem anterior bem-sucedida.

```cpp
virtual void release(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto reservado `message` .

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `release` método.

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) se o parâmetro `_PTarget` é `NULL` .

O método gera uma exceção [bad_target](bad-target-class.md) se o parâmetro `_PTarget` não representar o destino que chamou `reserve` .

## <a name="release_message"></a><a name="release_message"></a>release_message

Quando substituído em uma classe derivada, libera uma reserva de mensagem anterior.

```cpp
virtual void release_message(runtime_object_identity _MsgId) = 0;
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo liberado.

## <a name="release_ref"></a><a name="release_ref"></a>release_ref

Libera uma contagem de referência neste `source_block` objeto.

```cpp
virtual void release_ref(_Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado por um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de origem tem permissão para liberar todos os recursos reservados para o bloco de destino.

## <a name="remove_targets"></a><a name="remove_targets"></a>remove_targets

Remove todos os links de destino para este bloco de origem. Isso deve ser chamado a partir do destruidor.

```cpp
void remove_targets();
```

## <a name="reserve"></a><a name="reserve"></a>reservado

Reserva uma mensagem oferecida anteriormente por este `source_block` objeto.

```cpp
virtual bool reserve(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto oferecido `message` .

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `reserve` método.

### <a name="return-value"></a>Valor retornado

**`true`** se a mensagem tiver sido reservada com êxito, **`false`** caso contrário. As reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceita por outro destino, a origem poderia negar reservas e assim por diante.

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) se o parâmetro `_PTarget` é `NULL` .

Depois de chamar `reserve` , se tiver sucesso, você deverá chamar `consume` ou `release` para obter ou desistir da posse da mensagem, respectivamente.

## <a name="reserve_message"></a><a name="reserve_message"></a>reserve_message

Quando substituído em uma classe derivada, o reserva uma mensagem anteriormente oferecida por esse `source_block` objeto.

```cpp
virtual bool reserve_message(runtime_object_identity _MsgId) = 0;
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo reservado.

### <a name="return-value"></a>Valor retornado

**`true`** se a mensagem tiver sido reservada com êxito, **`false`** caso contrário.

### <a name="remarks"></a>Comentários

After `reserve` é chamado, se ele retornar **`true`** , `consume` ou `release` deve ser chamado para tirar ou liberar a propriedade da mensagem.

## <a name="resume_propagation"></a><a name="resume_propagation"></a>resume_propagation

Quando substituído em uma classe derivada, retoma a propagação após o lançamento de uma reserva.

```cpp
virtual void resume_propagation() = 0;
```

## <a name="source_block"></a><a name="ctor"></a>source_block

Constrói um objeto `source_block`.

```cpp
source_block();
```

## <a name="source_block"></a><a name="dtor"></a>~ source_block

Destrói o `source_block` objeto.

```cpp
virtual ~source_block();
```

## <a name="sync_send"></a><a name="sync_send"></a>sync_send

O enfileira as mensagens de forma síncrona e inicia uma tarefa de propagação, se isso ainda não tiver sido feito.

```cpp
virtual void sync_send(_Inout_opt_ message<_Target_type>* _Msg);
```

### <a name="parameters"></a>parâmetros

*_Msg*<br/>
Um ponteiro para um `message` objeto a ser enviado de forma síncrona.

## <a name="unlink_target"></a><a name="unlink_target"></a>unlink_target

Desvincula um bloco de destino deste `source_block` objeto.

```cpp
virtual void unlink_target(_Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para um `ITarget` bloco para desvincular deste `source_block` objeto.

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) se o parâmetro `_PTarget` é `NULL` .

## <a name="unlink_target_notification"></a><a name="unlink_target_notification"></a>unlink_target_notification

Um retorno de chamada que notifica que um destino foi desvinculado deste `source_block` objeto.

```cpp
virtual void unlink_target_notification(_Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
O `ITarget` bloco que foi desvinculado.

## <a name="unlink_targets"></a><a name="unlink_targets"></a>unlink_targets

Desvincula todos os blocos de destino deste `source_block` objeto.

```cpp
virtual void unlink_targets();
```

## <a name="wait_for_outstanding_async_sends"></a><a name="wait_for_outstanding_async_sends"></a>wait_for_outstanding_async_sends

Aguarda a conclusão de todas as propagações assíncronas. Essa espera de rotação específica do propagador é usada em destruidores de blocos de mensagens para garantir que todas as propagações assíncronas tenham tempo para serem concluídas antes de destruir o bloco.

```cpp
void wait_for_outstanding_async_sends();
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe as](isource-class.md)
