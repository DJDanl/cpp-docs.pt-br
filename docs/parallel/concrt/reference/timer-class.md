---
title: Classe timer
ms.date: 11/04/2016
f1_keywords:
- timer
- AGENTS/concurrency::timer
- AGENTS/concurrency::timer::timer
- AGENTS/concurrency::timer::pause
- AGENTS/concurrency::timer::start
- AGENTS/concurrency::timer::stop
- AGENTS/concurrency::timer::accept_message
- AGENTS/concurrency::timer::consume_message
- AGENTS/concurrency::timer::link_target_notification
- AGENTS/concurrency::timer::propagate_to_any_targets
- AGENTS/concurrency::timer::release_message
- AGENTS/concurrency::timer::reserve_message
- AGENTS/concurrency::timer::resume_propagation
helpviewer_keywords:
- timer class
ms.assetid: 4f4dea51-de9f-40f9-93f5-dd724c567b49
ms.openlocfilehash: 026aef03bb813585decb206c1691835330a4dd05
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224936"
---
# <a name="timer-class"></a>Classe timer

Um `timer` bloco de mensagens é um único destino `source_block` capaz de enviar uma mensagem para seu destino após um período de tempo especificado ter decorrido ou em intervalos específicos.

## <a name="syntax"></a>Sintaxe

```cpp
template<class T>
class timer : public Concurrency::details::_Timer, public source_block<single_link_registry<ITarget<T>>>;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de carga das mensagens de saída deste bloco.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[tempo](#ctor)|Sobrecarregado. Constrói um `timer` bloco de mensagens que irá disparar uma determinada mensagem após um intervalo especificado.|
|[~ Destruidor de temporizador](#dtor)|Destrói um `timer` bloco de mensagens.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[pause](#pause)|Interrompe o `timer` bloco de mensagens. Se for um bloco de `timer` mensagens repetidas, ele poderá ser reiniciado com uma `start()` chamada subsequente. Para temporizadores não repetitivos, isso tem o mesmo efeito que uma `stop` chamada.|
|[start](#start)|Inicia o `timer` bloco de mensagens. O número especificado de milissegundos após isso ser chamado, o valor especificado será propagado downstream como um `message` .|
|[stop](#stop)|Interrompe o `timer` bloco de mensagens.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[accept_message](#accept_message)|Aceita uma mensagem que foi oferecida por este `timer` bloco de mensagens, transferindo a propriedade para o chamador.|
|[consume_message](#consume_message)|Consome uma mensagem fornecida anteriormente pelo `timer` e reservada pelo destino, transferindo a propriedade para o chamador.|
|[link_target_notification](#link_target_notification)|Um retorno de chamada que notifica que um novo destino foi vinculado a este `timer` bloco de mensagens.|
|[propagate_to_any_targets](#propagate_to_any_targets)|Tenta oferecer a mensagem produzida pelo `timer` bloco para todos os destinos vinculados.|
|[release_message](#release_message)|Libera uma reserva de mensagem anterior. (Substitui [source_block:: release_message](source-block-class.md#release_message).)|
|[reserve_message](#reserve_message)|Reserva uma mensagem oferecida anteriormente por este `timer` bloco de mensagens. (Substitui [source_block:: reserve_message](source-block-class.md#reserve_message).)|
|[resume_propagation](#resume_propagation)|Retoma a propagação após a liberação de uma reserva. (Substitui [source_block:: resume_propagation](source-block-class.md#resume_propagation).)|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[As](isource-class.md)

[source_block](source-block-class.md)

`timer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept_message"></a><a name="accept_message"></a>accept_message

Aceita uma mensagem que foi oferecida por este `timer` bloco de mensagens, transferindo a propriedade para o chamador.

```cpp
virtual message<T>* accept_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto oferecido `message` .

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

## <a name="consume_message"></a><a name="consume_message"></a>consume_message

Consome uma mensagem fornecida anteriormente pelo `timer` e reservada pelo destino, transferindo a propriedade para o chamador.

```cpp
virtual message<T>* consume_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo consumido.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `message` objeto do qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

Semelhante a `accept` , mas é sempre precedido por uma chamada para `reserve` .

## <a name="link_target_notification"></a><a name="link_target_notification"></a>link_target_notification

Um retorno de chamada que notifica que um novo destino foi vinculado a este `timer` bloco de mensagens.

```cpp
virtual void link_target_notification(_Inout_ ITarget<T>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
Um ponteiro para o destino vinculado recentemente.

## <a name="pause"></a><a name="pause"></a>temporariamente

Interrompe o `timer` bloco de mensagens. Se for um bloco de `timer` mensagens repetidas, ele poderá ser reiniciado com uma `start()` chamada subsequente. Para temporizadores não repetitivos, isso tem o mesmo efeito que uma `stop` chamada.

```cpp
void pause();
```

## <a name="propagate_to_any_targets"></a><a name="propagate_to_any_targets"></a>propagate_to_any_targets

Tenta oferecer a mensagem produzida pelo `timer` bloco para todos os destinos vinculados.

```cpp
virtual void propagate_to_any_targets(_Inout_opt_ message<T> *);
```

## <a name="release_message"></a><a name="release_message"></a>release_message

Libera uma reserva de mensagem anterior.

```cpp
virtual void release_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo liberado.

## <a name="reserve_message"></a><a name="reserve_message"></a>reserve_message

Reserva uma mensagem oferecida anteriormente por este `timer` bloco de mensagens.

```cpp
virtual bool reserve_message(runtime_object_identity _MsgId);
```

### <a name="parameters"></a>parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` objeto que está sendo reservado.

### <a name="return-value"></a>Valor retornado

**`true`** se a mensagem tiver sido reservada com êxito, **`false`** caso contrário.

### <a name="remarks"></a>Comentários

After `reserve` é chamado, se ele retornar **`true`** , `consume` ou `release` deve ser chamado para tirar ou liberar a propriedade da mensagem.

## <a name="resume_propagation"></a><a name="resume_propagation"></a>resume_propagation

Retoma a propagação após a liberação de uma reserva.

```cpp
virtual void resume_propagation();
```

## <a name="start"></a><a name="start"></a>Comece

Inicia o `timer` bloco de mensagens. O número especificado de milissegundos após isso ser chamado, o valor especificado será propagado downstream como um `message` .

```cpp
void start();
```

## <a name="stop"></a><a name="stop"></a>deixar

Interrompe o `timer` bloco de mensagens.

```cpp
void stop();
```

## <a name="timer"></a><a name="ctor"></a>tempo

Constrói um `timer` bloco de mensagens que irá disparar uma determinada mensagem após um intervalo especificado.

```cpp
timer(
    unsigned int _Ms,
    T const& value,
    ITarget<T>* _PTarget = NULL,
    bool _Repeating = false);

timer(
    Scheduler& _Scheduler,
    unsigned int _Ms,
    T const& value,
    _Inout_opt_ ITarget<T>* _PTarget = NULL,
    bool _Repeating = false);

timer(
    ScheduleGroup& _ScheduleGroup,
    unsigned int _Ms,
    T const& value,
    _Inout_opt_ ITarget<T>* _PTarget = NULL,
    bool _Repeating = false);
```

### <a name="parameters"></a>parâmetros

*_Ms*<br/>
O número de milissegundos que devem decorrer após a chamada para iniciar a mensagem especificada a ser propagada downstream.

*value*<br/>
O valor que será propagado downstream quando o timer decorrer.

*_PTarget*<br/>
O destino para o qual o temporizador propagará sua mensagem.

*_Repeating*<br/>
Se for true, indica que o temporizador será acionado periodicamente a cada `_Ms` milissegundos.

*_Scheduler*<br/>
O `Scheduler` objeto no qual a tarefa de propagação para o `timer` bloco de mensagens está agendada está agendada.

*_ScheduleGroup*<br/>
O `ScheduleGroup` objeto no qual a tarefa de propagação para o `timer` bloco de mensagens está agendada. O `Scheduler` objeto usado é implícito pelo grupo de agendamento.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os `_Scheduler` `_ScheduleGroup` parâmetros ou.

## <a name="timer"></a><a name="dtor"></a>~ temporizador

Destrói um `timer` bloco de mensagens.

```cpp
~timer();
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
