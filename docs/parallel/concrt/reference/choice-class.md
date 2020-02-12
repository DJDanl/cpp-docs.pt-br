---
title: Classe choice
ms.date: 11/04/2016
f1_keywords:
- choice
- AGENTS/concurrency::choice
- AGENTS/concurrency::choice::choice
- AGENTS/concurrency::choice::accept
- AGENTS/concurrency::choice::acquire_ref
- AGENTS/concurrency::choice::consume
- AGENTS/concurrency::choice::has_value
- AGENTS/concurrency::choice::index
- AGENTS/concurrency::choice::link_target
- AGENTS/concurrency::choice::release
- AGENTS/concurrency::choice::release_ref
- AGENTS/concurrency::choice::reserve
- AGENTS/concurrency::choice::unlink_target
- AGENTS/concurrency::choice::unlink_targets
- AGENTS/concurrency::choice::value
helpviewer_keywords:
- choice class
ms.assetid: 4157a539-d5c2-4161-b1ab-536ce2888397
ms.openlocfilehash: 3e718d0d34580d3bf2f13937159e431134631218
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142210"
---
# <a name="choice-class"></a>Classe choice

Um bloco de mensagens `choice` é um bloco de várias origens, de destino único, que representa uma interação de fluxo de controle com um conjunto de fontes. O bloco Choice aguardará que qualquer uma de várias fontes gere uma mensagem e propagará o índice da origem que produziu a mensagem.

## <a name="syntax"></a>Sintaxe

```cpp
template<
    class T
>
class choice: public ISource<size_t>;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um tipo baseado em `tuple`que representa as cargas das fontes de entrada.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`type`|Um alias de tipo para `T`.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[desejada](#ctor)|Sobrecarregado. Constrói um bloco de mensagens `choice`.|
|[~ Destruidor de opção](#dtor)|Destrói o bloco de mensagens `choice`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[aceitar](#accept)|Aceita uma mensagem que foi oferecida por este bloco de `choice`, transferindo a propriedade para o chamador.|
|[acquire_ref](#acquire_ref)|Adquire uma contagem de referência nessa `choice` o bloco de mensagens para evitar a exclusão.|
|[consumir](#consume)|Consome uma mensagem oferecida anteriormente por esse `choice` bloco de mensagens e foi reservada com êxito pelo destino, transferindo a propriedade para o chamador.|
|[has_value](#has_value)|Verifica se este `choice` bloco de mensagens foi inicializado com um valor ainda.|
|[index](#index)|Retorna um índice para o `tuple` que representa o elemento selecionado pelo bloco de mensagens `choice`.|
|[link_target](#link_target)|Vincula um bloco de destino a este `choice` bloco de mensagens.|
|[release](#release)|Libera uma reserva de mensagem anterior bem-sucedida.|
|[release_ref](#release_ref)|Libera uma contagem de referência neste `choice` bloco de mensagens.|
|[reserve](#reserve)|Reserva uma mensagem oferecida anteriormente por este `choice` bloco de mensagens.|
|[unlink_target](#unlink_target)|Desvincula um bloco de destino deste `choice` bloco de mensagens.|
|[unlink_targets](#unlink_targets)|Desvincula todos os destinos desta `choice` bloco de mensagens. (Substitui [as:: unlink_targets](isource-class.md#unlink_targets).)|
|[value](#value)|Obtém a mensagem cujo índice foi selecionado pelo bloco de mensagens `choice`.|

## <a name="remarks"></a>Comentários

O bloco Choice garante que apenas uma das mensagens de entrada seja consumida.

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[As](isource-class.md)

`choice`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="accept"></a>aceitar

Aceita uma mensagem que foi oferecida por este bloco de `choice`, transferindo a propriedade para o chamador.

```cpp
virtual message<size_t>* accept(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto `message` oferecido.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o método de `accept`.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a mensagem da qual o chamador agora tem propriedade.

## <a name="acquire_ref"></a>acquire_ref

Adquire uma contagem de referência nessa `choice` o bloco de mensagens para evitar a exclusão.

```cpp
virtual void acquire_ref(_Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado por um objeto `ITarget` que está sendo vinculado a essa fonte durante o método `link_target`.

## <a name="ctor"></a>desejada

Constrói um bloco de mensagens `choice`.

```cpp
explicit choice(
    T _Tuple);

choice(
    Scheduler& _PScheduler,
    T _Tuple);

choice(
    ScheduleGroup& _PScheduleGroup,
    T _Tuple);

choice(
    choice&& _Choice);
```

### <a name="parameters"></a>Parâmetros

*_Tuple*<br/>
Uma `tuple` de fontes para a escolha.

*_PScheduler*<br/>
O objeto `Scheduler` no qual a tarefa de propagação para o `choice` bloco de mensagens está agendada.

*_PScheduleGroup*<br/>
O objeto `ScheduleGroup` no qual a tarefa de propagação para o `choice` bloco de mensagens está agendada. O objeto de `Scheduler` usado é implícito pelo grupo de agendamento.

*_Choice*<br/>
Um `choice` bloco de mensagens do qual copiar. Observe que o objeto original está órfão, tornando-o um Construtor move.

### <a name="remarks"></a>Comentários

O tempo de execução usará o agendador padrão se você não especificar os parâmetros `_PScheduler` ou `_PScheduleGroup`.

A construção de movimentação não é executada sob um bloqueio, o que significa que cabe ao usuário certificar-se de que não há nenhuma tarefa leve em trânsito no momento da movimentação. Caso contrário, várias corridas podem ocorrer, levando a exceções ou a um estado inconsistente.

## <a name="dtor"></a>~ opção

Destrói o bloco de mensagens `choice`.

```cpp
~choice();
```

## <a name="consume"></a>utilização

Consome uma mensagem oferecida anteriormente por esse `choice` bloco de mensagens e foi reservada com êxito pelo destino, transferindo a propriedade para o chamador.

```cpp
virtual message<size_t>* consume(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto `message` reservado.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o método de `consume`.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto de `message` ao qual o chamador agora tem propriedade.

### <a name="remarks"></a>Comentários

O método `consume` é semelhante a `accept`, mas deve ser sempre precedido por uma chamada para `reserve` que retornou **true**.

## <a name="has_value"></a>has_value

Verifica se este `choice` bloco de mensagens foi inicializado com um valor ainda.

```cpp
bool has_value() const;
```

### <a name="return-value"></a>Valor retornado

**true** se o bloco tiver recebido um valor; caso contrário, **false** .

## <a name="index"></a>index

Retorna um índice para o `tuple` que representa o elemento selecionado pelo bloco de mensagens `choice`.

```cpp
size_t index();
```

### <a name="return-value"></a>Valor retornado

O índice da mensagem.

### <a name="remarks"></a>Comentários

A carga da mensagem pode ser extraída usando o método `get`.

## <a name="link_target"></a>link_target

Vincula um bloco de destino a este `choice` bloco de mensagens.

```cpp
virtual void link_target(_Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para um bloco de `ITarget` para vincular a este `choice` bloco de mensagens.

## <a name="release"></a>liberar

Libera uma reserva de mensagem anterior bem-sucedida.

```cpp
virtual void release(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto de `message` que está sendo liberado.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o método de `release`.

## <a name="release_ref"></a>release_ref

Libera uma contagem de referência neste `choice` bloco de mensagens.

```cpp
virtual void release_ref(_Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado por um objeto `ITarget` que está sendo desvinculado dessa fonte. O bloco de origem tem permissão para liberar todos os recursos reservados para o bloco de destino.

## <a name="reserve"></a>reservado

Reserva uma mensagem oferecida anteriormente por este `choice` bloco de mensagens.

```cpp
virtual bool reserve(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do objeto de `message` que está sendo reservado.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o método de `reserve`.

### <a name="return-value"></a>Valor retornado

**true** se a mensagem tiver sido reservada com êxito; caso contrário, **false** . As reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceita por outro destino, a origem poderia negar reservas e assim por diante.

### <a name="remarks"></a>Comentários

Depois de chamar `reserve`, se tiver sucesso, você deverá chamar `consume` ou `release` para tirar ou desistir da posse da mensagem, respectivamente.

## <a name="unlink_target"></a>unlink_target

Desvincula um bloco de destino deste `choice` bloco de mensagens.

```cpp
virtual void unlink_target(_Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para um bloco de `ITarget` para desvincular deste bloco de mensagens `choice`.

## <a name="unlink_targets"></a>unlink_targets

Desvincula todos os destinos desta `choice` bloco de mensagens.

```cpp
virtual void unlink_targets();
```

### <a name="remarks"></a>Comentários

Esse método não precisa ser chamado do destruidor porque o destruidor para o bloco de `single_assignment` interno desvinculará corretamente.

## <a name="value"></a>valor

Obtém a mensagem cujo índice foi selecionado pelo bloco de mensagens `choice`.

```cpp
template <
    typename _Payload_type
>
_Payload_type const& value();
```

### <a name="parameters"></a>Parâmetros

*_Payload_type*<br/>
O tipo da carga da mensagem.

### <a name="return-value"></a>Valor retornado

A carga da mensagem.

### <a name="remarks"></a>Comentários

Como um `choice` bloco de mensagens pode receber entradas com tipos de carga diferentes, você deve especificar o tipo da carga no ponto de recuperação. Você pode determinar o tipo com base no resultado do método `index`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe join](join-class.md)<br/>
[Classe single_assignment](single-assignment-class.md)
