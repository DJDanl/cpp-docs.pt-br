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
ms.openlocfilehash: aa4945bb5f9ef28937487ba504e23c461992b263
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57267011"
---
# <a name="choice-class"></a>Classe choice

Um `choice` bloco de mensagens é um bloco de várias fonte, destino único que representa uma interação de fluxo de controle com um conjunto de fontes. O bloco de opção aguardará para qualquer uma das várias fontes para produzir uma mensagem e propagará o índice da origem que gerou a mensagem.

## <a name="syntax"></a>Sintaxe

```
template<
    class T
>
class choice: public ISource<size_t>;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Um `tuple`-com base em tipo que representa as cargas das fontes de entrada.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`type`|Um alias de tipo para `T`.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Escolha](#ctor)|Sobrecarregado. Constrói um `choice` bloco de mensagem.|
|[~ Destruidor choice](#dtor)|Destrói o `choice` bloco de mensagem.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[accept](#accept)|Aceita uma mensagem que era oferecida por este `choice` bloco, transferindo a propriedade para o chamador.|
|[acquire_ref](#acquire_ref)|Adquire uma contagem de referência sobre isso `choice` bloco de mensagem, para impedir a exclusão.|
|[consume](#consume)|Consome uma mensagem anteriormente oferecida por este `choice` bloco de mensagens e reservada com êxito pelo destino, transferindo a propriedade para o chamador.|
|[has_value](#has_value)|Verifica se este `choice` bloco de mensagens foi inicializado com um valor ainda.|
|[index](#index)|Retorna um índice para o `tuple` que representa o elemento selecionado pelo `choice` bloco de mensagem.|
|[link_target](#link_target)|Isso vincula um bloco de destino `choice` bloco de mensagem.|
|[release](#release)|Libera uma reserva de mensagem bem-sucedida anterior.|
|[release_ref](#release_ref)|Libera uma contagem de referência sobre isso `choice` bloco de mensagem.|
|[reserve](#reserve)|Reserva uma mensagem anteriormente oferecida por este `choice` bloco de mensagem.|
|[unlink_target](#unlink_target)|Desvincula um bloco de destino deste `choice` bloco de mensagem.|
|[unlink_targets](#unlink_targets)|Desvincula todos os destinos neste `choice` bloco de mensagem. (Substitui [ISource:: Unlink_targets](isource-class.md#unlink_targets).)|
|[value](#value)|Obtém a mensagem cujo índice foi selecionado pelo `choice` bloco de mensagem.|

## <a name="remarks"></a>Comentários

O bloco de opção garante que apenas uma das mensagens de entrada é consumida.

Para obter mais informações, consulte [blocos de mensagens assíncronas](../../../parallel/concrt/asynchronous-message-blocks.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[ISource](isource-class.md)

`choice`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

##  <a name="accept"></a> accept

Aceita uma mensagem que era oferecida por este `choice` bloco, transferindo a propriedade para o chamador.

```
virtual message<size_t>* accept(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do que o oferecido `message` objeto.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `accept` método.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a mensagem de que o chamador agora tem a propriedade do.

##  <a name="acquire_ref"></a> acquire_ref

Adquire uma contagem de referência sobre isso `choice` bloco de mensagem, para impedir a exclusão.

```
virtual void acquire_ref(_Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado um `ITarget` objeto que está sendo vinculado a essa fonte durante o `link_target` método.

##  <a name="ctor"></a> Escolha

Constrói um `choice` bloco de mensagem.

```
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
Um `tuple` de fontes para a escolha.

*_PScheduler*<br/>
O `Scheduler` objeto dentro do qual a tarefa de propagação para o `choice` bloco de mensagem está agendado.

*_PScheduleGroup*<br/>
O `ScheduleGroup` objeto dentro do qual a tarefa de propagação para o `choice` bloco de mensagem está agendado. O `Scheduler` objeto usado é inferido pelo grupo agendado.

*_Choice*<br/>
Um `choice` copiar do bloco de mensagem. Observe que o objeto original ficar órfão, fazendo de um construtor de movimentação.

### <a name="remarks"></a>Comentários

O tempo de execução usa o agendador padrão, se você não especificar o `_PScheduler` ou `_PScheduleGroup` parâmetros.

Construção de movimentação não é executada em um bloqueio, o que significa que ele depende do usuário para certificar-se de que não há nenhuma tarefa leve em andamento no momento da movimentação. Caso contrário, corridas inúmeros podem ocorrer, levando a estado inconsistente ou exceções.

##  <a name="dtor"></a> ~choice

Destrói o `choice` bloco de mensagem.

```
~choice();
```

##  <a name="consume"></a> consumir

Consome uma mensagem anteriormente oferecida por este `choice` bloco de mensagens e reservada com êxito pelo destino, transferindo a propriedade para o chamador.

```
virtual message<size_t>* consume(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` de reservado `message` objeto.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `consume` método.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `message` do objeto que o chamador agora tem a propriedade do.

### <a name="remarks"></a>Comentários

O `consume` método é semelhante ao `accept`, mas sempre deve ser precedido por uma chamada para `reserve` que retornado **true**.

##  <a name="has_value"></a> has_value

Verifica se este `choice` bloco de mensagens foi inicializado com um valor ainda.

```
bool has_value() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o bloco tiver recebido um valor **falso** caso contrário.

##  <a name="index"></a> Índice

Retorna um índice para o `tuple` que representa o elemento selecionado pelo `choice` bloco de mensagem.

```
size_t index();
```

### <a name="return-value"></a>Valor de retorno

O índice de mensagem.

### <a name="remarks"></a>Comentários

A carga da mensagem pode ser extraída usando o `get` método.

##  <a name="link_target"></a> link_target

Isso vincula um bloco de destino `choice` bloco de mensagem.

```
virtual void link_target(_Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para um `ITarget` bloco para vincular a este `choice` bloco de mensagem.

##  <a name="release"></a> versão

Libera uma reserva de mensagem bem-sucedida anterior.

```
virtual void release(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo lançada.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `release` método.

##  <a name="release_ref"></a> release_ref

Libera uma contagem de referência sobre isso `choice` bloco de mensagem.

```
virtual void release_ref(_Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando esse método.

### <a name="remarks"></a>Comentários

Esse método é chamado um `ITarget` objeto que está sendo desvinculado dessa fonte. O bloco de origem é permitido para liberar quaisquer recursos reservados para o bloco de destino.

##  <a name="reserve"></a> reservar

Reserva uma mensagem anteriormente oferecida por este `choice` bloco de mensagem.

```
virtual bool reserve(
    runtime_object_identity _MsgId,
    _Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_MsgId*<br/>
O `runtime_object_identity` do `message` do objeto que está sendo reservado.

*_PTarget*<br/>
Um ponteiro para o bloco de destino que está chamando o `reserve` método.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se a mensagem foi reservada com êxito, **falso** caso contrário. As reservas podem falhar por vários motivos, incluindo: a mensagem já foi reservada ou aceito por outro destino, a fonte pode negar reservas e assim por diante.

### <a name="remarks"></a>Comentários

Depois de chamar `reserve`, se tiver êxito, você deve chamar `consume` ou `release` para levar ou desistir posse da mensagem, respectivamente.

##  <a name="unlink_target"></a> unlink_target

Desvincula um bloco de destino deste `choice` bloco de mensagem.

```
virtual void unlink_target(_Inout_ ITarget<size_t>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
Um ponteiro para um `ITarget` bloco desvincular deste `choice` bloco de mensagem.

##  <a name="unlink_targets"></a> unlink_targets

Desvincula todos os destinos neste `choice` bloco de mensagem.

```
virtual void unlink_targets();
```

### <a name="remarks"></a>Comentários

Esse método não precisa ser chamado do destruidor porque o destruidor para interno `single_assignment` bloco desvinculará corretamente.

##  <a name="value"></a> Valor

Obtém a mensagem cujo índice foi selecionado pelo `choice` bloco de mensagem.

```
template <
    typename _Payload_type
>
_Payload_type const& value();
```

### <a name="parameters"></a>Parâmetros

*_Payload_type*<br/>
O tipo de carga da mensagem.

### <a name="return-value"></a>Valor de retorno

A carga da mensagem.

### <a name="remarks"></a>Comentários

Porque um `choice` bloco de mensagem pode levar a entradas com tipos diferentes de carga, você deve especificar o tipo de carga no ponto de recuperação. Você pode determinar o tipo com base no resultado do `index` método.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe join](join-class.md)<br/>
[Classe single_assignment](single-assignment-class.md)
