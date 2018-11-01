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
ms.openlocfilehash: 609c7d78bdf2f16be4d82add454ef9546ea22588
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50468686"
---
# <a name="sourceblock-class"></a>Classe source_block

O `source_block` classe é uma classe base abstrata para blocos de código-fonte. A classe fornece funcionalidade de gerenciamento de link básico como verificações de erro bem tão comuns.

## <a name="syntax"></a>Sintaxe

```
template<class _TargetLinkRegistry, class _MessageProcessorType = ordered_message_processor<typename _TargetLinkRegistry::type::type>>
class source_block : public ISource<typename _TargetLinkRegistry::type::type>;
```

#### <a name="parameters"></a>Parâmetros

*_TargetLinkRegistry*<br/>
Registro de link a ser usado para manter os links de destino.

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
|[accept](#accept)|Aceita uma mensagem que era oferecida por este `source_block` objeto, transferindo a propriedade para o chamador.|
|[acquire_ref](#acquire_ref)|Adquire uma contagem de referência sobre isso `source_block` objeto, para impedir a exclusão.|
|[consume](#consume)|Consome uma mensagem anteriormente oferecida por este `source_block` do objeto e reservada com êxito pelo destino, transferindo a propriedade para o chamador.|
|[link_target](#link_target)|Isso vincula um bloco de destino `source_block` objeto.|
|[release](#release)|Libera uma reserva de mensagem bem-sucedida anterior.|
|[release_ref](#release_ref)|Libera uma contagem de referência sobre isso `source_block` objeto.|
|[reserve](#reserve)|Reserva uma mensagem anteriormente oferecida por este `source_block` objeto.|
|[unlink_target](#unlink_target)|Desvincula um bloco de destino deste `source_block` objeto.|
|[unlink_targets](#unlink_targets)|Desvincula todos os blocos de destino deste `source_block` objeto. (Substitui [ISource:: Unlink_targets](isource-class.md#unlink_targets).)|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Quando substituído em uma classe derivada, aceita uma mensagem oferecida pela origem. Blocos de mensagem devem substituir este método para validar o `_MsgId` e retornar uma mensagem.|
|[async_send](#async_send)|Enfileira mensagens de forma assíncrona e inicia uma tarefa de propagação, se isso não já foi feito|
|[consume_message](#consume_message)|Quando substituído em uma classe derivada, consome uma mensagem que foi reservada anteriormente.|
|[enable_batched_processing](#enable_batched_processing)|Habilita em lote de processamento para esse bloco.|
|[initialize_source](#initialize_source)|Inicializa o `message_propagator` dentro desse `source_block`.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `source_block` objeto.|
|[process_input_messages](#process_input_messages)|Processar mensagens de entrada. Isso só é útil para blocos de propagador, que derivam de source_block|
|[propagate_output_messages](#propagate_output_messages)|Propaga mensagens para destinos.|
|[propagate_to_any_targets](#propagate_to_any_targets)|Quando substituído em uma classe derivada, propaga a mensagem fornecida para qualquer ou todos os destinos vinculados. Isso é a rotina de propagação principal para blocos de mensagem.|
|[release_message](#release_message)|Quando substituído em uma classe derivada, libera uma reserva de mensagem anterior.|
|[remove_targets](#remove_targets)|Remove todos os links de destino para este bloco de código-fonte. Isso deve ser chamado de destruidor.|
|[reserve_message](#reserve_message)|Quando substituído em uma classe derivada, reserva uma mensagem anteriormente oferecida por este `source_block` objeto.|
|[resume_propagation](#resume_propagation)|Quando substituído em uma classe derivada, retoma a propagação depois de uma reserva foi liberada.|
|[sync_send](#sync_send)|Forma síncrona Enfileira mensagens e inicia uma tarefa de propagação, se isso não já foi feito.|
|[unlink_target_notification](#unlink_target_notification)|Um retorno de chamada que notifica que um destino foi desvinculado disso `source_block` objeto.|
|[wait_for_outstanding_async_sends](#wait_for_outstanding_async_sends)|Aguarda até que todas as propagações assíncronas concluir. Essa espera de rotação de propagador específico é usada em destruidores de blocos de mensagem para certificar-se de que todas as propagações assíncronas tem tempo para concluir antes de destruir o bloco.|

## <a name="remarks"></a>Comentários

Blocos de mensagens devem derivar desse bloco para aproveitar o gerenciamento de link e a sincronização fornecida por esta classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[ISource](isource-class.md)

`source_block`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

##  <a name="accept"></a> Aceitar

Aceita uma mensagem que era oferecida por este `source_block` objeto, transferindo a propriedade para o chamador.

```
virtual message<_Target_type>* accept(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do que o oferecido `message` objeto.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `accept` método.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.

### <a name="remarks"></a>Comentários

O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_PTarget` é `NULL`.

O `accept` método é chamado por um destino, enquanto uma mensagem está sendo oferecida por este `ISource` bloco. O ponteiro de mensagem retornado pode ser diferente do passado para o `propagate` método da `ITarget` bloquear, se essa fonte decide fazer uma cópia da mensagem.

##  <a name="accept_message"></a> accept_message

Quando substituído em uma classe derivada, aceita uma mensagem oferecida pela origem. Blocos de mensagem devem substituir este método para validar o `_MsgId` e retornar uma mensagem.

```
virtual message<_Target_type>* accept_message(runtime_object_identity _MsgId) = 0;
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
A identidade do objeto de tempo de execução do `message` objeto.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a mensagem de que o chamador agora tem a propriedade do.

### <a name="remarks"></a>Comentários

Para transferir a propriedade, o ponteiro original da mensagem deve ser retornado. Para manter a propriedade, uma cópia do conteúdo da mensagem precisa ser feita e retornado.

##  <a name="acquire_ref"></a> acquire_ref

Adquire uma contagem de referência sobre isso `source_block` objeto, para impedir a exclusão.

```
virtual void acquire_ref(_Inout_ ITarget<_Target_type> *);
```

### <a name="remarks"></a>Comentários

Esse método é chamado um `ITarget` objeto que está sendo vinculado a essa fonte durante o `link_target` método.

##  <a name="async_send"></a> async_send

Enfileira mensagens de forma assíncrona e inicia uma tarefa de propagação, se isso não já foi feito

```
virtual void async_send(_Inout_opt_ message<_Target_type>* _Msg);
```

### <a name="parameters"></a>Parâmetros

*_Msg*<br/>
Um ponteiro para um `message` objeto a ser enviado de forma assíncrona.

##  <a name="consume"></a> consumir

Consome uma mensagem anteriormente oferecida por este `source_block` do objeto e reservada com êxito pelo destino, transferindo a propriedade para o chamador.

```
virtual message<_Target_type>* consume(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` de reservado `message` objeto.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `consume` método.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.

### <a name="remarks"></a>Comentários

O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_PTarget` é `NULL`.

O método lança um [bad_target](bad-target-class.md) exceção se o parâmetro `_PTarget` não representa o destino de chamada `reserve`.

O `consume` método é semelhante ao `accept`, mas sempre deve ser precedido por uma chamada para `reserve` que retornado **true**.

##  <a name="consume_message"></a> consume_message

Quando substituído em uma classe derivada, consome uma mensagem que foi reservada anteriormente.

```
virtual message<_Target_type>* consume_message(runtime_object_identity _MsgId) = 0;
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo consumido.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a mensagem de que o chamador agora tem a propriedade do.

### <a name="remarks"></a>Comentários

Semelhante ao `accept`, mas sempre é precedido por uma chamada para `reserve`.

##  <a name="enable_batched_processing"></a> enable_batched_processing

Habilita em lote de processamento para esse bloco.

```
void enable_batched_processing();
```

##  <a name="initialize_source"></a> initialize_source

Inicializa o `message_propagator` dentro desse `source_block`.

```
void initialize_source(
    _Inout_opt_ Scheduler* _PScheduler = NULL,
    _Inout_opt_ ScheduleGroup* _PScheduleGroup = NULL);
```

### <a name="parameters"></a>Parâmetros

*_PScheduler*<br/>
O Agendador a ser usado para o agendamento de tarefas.

*_PScheduleGroup*<br/>
O grupo de programação a ser usado para o agendamento de tarefas.

##  <a name="link_target"></a> link_target

Isso vincula um bloco de destino `source_block` objeto.

```
virtual void link_target(_Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para um `ITarget` bloco para vincular a este `source_block` objeto.

### <a name="remarks"></a>Comentários

O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_PTarget` é `NULL`.

##  <a name="link_target_notification"></a> link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a este `source_block` objeto.

```
virtual void link_target_notification(_Inout_ ITarget<_Target_type> *);
```

##  <a name="process_input_messages"></a> process_input_messages

Processar mensagens de entrada. Isso só é útil para blocos de propagador, que derivam de source_block

```
virtual void process_input_messages(_Inout_ message<_Target_type>* _PMessage);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem que deve ser processado.

##  <a name="propagate_output_messages"></a> propagate_output_messages

Propaga mensagens para destinos.

```
virtual void propagate_output_messages();
```

##  <a name="propagate_to_any_targets"></a> propagate_to_any_targets

Quando substituído em uma classe derivada, propaga a mensagem fornecida para qualquer ou todos os destinos vinculados. Isso é a rotina de propagação principal para blocos de mensagem.

```
virtual void propagate_to_any_targets(_Inout_opt_ message<_Target_type>* _PMessage);
```

### <a name="parameters"></a>Parâmetros

*_PMessage*<br/>
Um ponteiro para a mensagem que deve ser propagada.

##  <a name="release"></a> versão

Libera uma reserva de mensagem bem-sucedida anterior.

```
virtual void release(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` de reservado `message` objeto.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `release` método.

### <a name="remarks"></a>Comentários

O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_PTarget` é `NULL`.

O método lança um [bad_target](bad-target-class.md) exceção se o parâmetro `_PTarget` não representa o destino de chamada `reserve`.

##  <a name="release_message"></a> release_message

Quando substituído em uma classe derivada, libera uma reserva de mensagem anterior.

```
virtual void release_message(runtime_object_identity _MsgId) = 0;
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo lançada.

##  <a name="release_ref"></a> release_ref

Libera uma contagem de referência sobre isso `source_block` objeto.

```
virtual void release_ref(_Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de origem é permitido para liberar quaisquer recursos reservados para o bloco de destino.

##  <a name="remove_targets"></a> remove_targets

Remove todos os links de destino para este bloco de código-fonte. Isso deve ser chamado de destruidor.

```
void remove_targets();
```

##  <a name="reserve"></a> reservar

Reserva uma mensagem anteriormente oferecida por este `source_block` objeto.

```
virtual bool reserve(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do que o oferecido `message` objeto.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `reserve` método.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se a mensagem foi reservada com êxito, **falso** caso contrário. As reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceito por outro destino, a fonte pode negar reservas e assim por diante.

### <a name="remarks"></a>Comentários

O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_PTarget` é `NULL`.

Depois de chamar `reserve`, se tiver êxito, você deve chamar `consume` ou `release` para levar ou desistir posse da mensagem, respectivamente.

##  <a name="reserve_message"></a> reserve_message

Quando substituído em uma classe derivada, reserva uma mensagem anteriormente oferecida por este `source_block` objeto.

```
virtual bool reserve_message(runtime_object_identity _MsgId) = 0;
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo reservado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se a mensagem foi reservada com êxito, **falso** caso contrário.

### <a name="remarks"></a>Comentários

Após `reserve` é chamado, se ele retorna **verdadeiro**, ambos `consume` ou `release` deve ser chamado para executar ou liberar a propriedade da mensagem.

##  <a name="resume_propagation"></a> resume_propagation

Quando substituído em uma classe derivada, retoma a propagação depois de uma reserva foi liberada.

```
virtual void resume_propagation() = 0;
```

##  <a name="ctor"></a> source_block

Constrói um objeto `source_block`.

```
source_block();
```

##  <a name="dtor"></a> ~ source_block

Destrói o `source_block` objeto.

```
virtual ~source_block();
```

##  <a name="sync_send"></a> sync_send

Forma síncrona Enfileira mensagens e inicia uma tarefa de propagação, se isso não já foi feito.

```
virtual void sync_send(_Inout_opt_ message<_Target_type>* _Msg);
```

### <a name="parameters"></a>Parâmetros

*_Msg*<br/>
Um ponteiro para um `message` objeto a ser enviado de forma síncrona.

##  <a name="unlink_target"></a> unlink_target

Desvincula um bloco de destino deste `source_block` objeto.

```
virtual void unlink_target(_Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para um `ITarget` bloco desvincular deste `source_block` objeto.

### <a name="remarks"></a>Comentários

O método lança um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção se o parâmetro `_PTarget` é `NULL`.

##  <a name="unlink_target_notification"></a> unlink_target_notification

Um retorno de chamada que notifica que um destino foi desvinculado disso `source_block` objeto.

```
virtual void unlink_target_notification(_Inout_ ITarget<_Target_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
O `ITarget` bloco que foi desvinculado.

##  <a name="unlink_targets"></a> unlink_targets

Desvincula todos os blocos de destino deste `source_block` objeto.

```
virtual void unlink_targets();
```

##  <a name="wait_for_outstanding_async_sends"></a> wait_for_outstanding_async_sends

Aguarda até que todas as propagações assíncronas concluir. Essa espera de rotação de propagador específico é usada em destruidores de blocos de mensagem para certificar-se de que todas as propagações assíncronas tem tempo para concluir antes de destruir o bloco.

```
void wait_for_outstanding_async_sends();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe ISource](isource-class.md)
