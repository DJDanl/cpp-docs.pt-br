---
title: Classe Event | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- event
- CONCRT/concurrency::event
- CONCRT/concurrency::event::reset
- CONCRT/concurrency::event::set
- CONCRT/concurrency::event::wait
- CONCRT/concurrency::event::wait_for_multiple
- CONCRT/concurrency::event::timeout_infinite
dev_langs:
- C++
helpviewer_keywords:
- event class
ms.assetid: fba35a53-6568-4bfa-9aaf-07c0928cf73d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 74e871255e3308450764e8f65cdb6acebe79df38
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46437736"
---
# <a name="event-class"></a>Classe event

Um evento de redefinição manual que esteja explicitamente ciente do tempo de execução de simultaneidade.

## <a name="syntax"></a>Sintaxe

```
class event;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[~ evento destruidor](#dtor)|Destrói um evento.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[reset](#reset)|Redefine o evento para um estado não sinalizado.|
|[set](#set)|Sinaliza o evento.|
|[wait](#wait)|Aguarda até que o evento seja sinalizado.|
|[wait_for_multiple](#wait_for_multiple)|Aguarda vários eventos sejam sinalizados.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[timeout_infinite](#timeout_infinite)|Valor que indica que uma espera nunca deve atingir o tempo limite.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [estruturas de dados de sincronização](../../../parallel/concrt/synchronization-data-structures.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`event`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> Evento

Constrói um novo evento.

```
_CRTIMP event();
```

### <a name="remarks"></a>Comentários

##  <a name="dtor"></a> ~ eventos

Destrói um evento.

```
~event();
```

### <a name="remarks"></a>Comentários

Espera-se que não há nenhum segmento esperando pelo evento quando o destruidor for executado. Permitir que o evento destruidor com threads continue aguardando nele resulta em um comportamento indefinido.

##  <a name="reset"></a> Redefinir

Redefine o evento para um estado não sinalizado.

```
void reset();
```

##  <a name="set"></a> Definir

Sinaliza o evento.

```
void set();
```

### <a name="remarks"></a>Comentários

Sinalizar o evento pode causar um número arbitrário de contextos de aguardar o evento se torne executável.

##  <a name="timeout_infinite"></a> timeout_infinite

Valor que indica que uma espera nunca deve atingir o tempo limite.

```
static const unsigned int timeout_infinite = COOPERATIVE_TIMEOUT_INFINITE;
```

##  <a name="wait"></a> Aguarde

Aguarda até que o evento seja sinalizado.

```
size_t wait(unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```

### <a name="parameters"></a>Parâmetros

*Tempo limite*<br/>
Indica o número de milissegundos antes que o tempo limite expirar. O valor `COOPERATIVE_TIMEOUT_INFINITE` significa que não há nenhum tempo limite.

### <a name="return-value"></a>Valor de retorno

Se a espera foi satisfazida, o valor `0` será retornado; caso contrário, o valor `COOPERATIVE_WAIT_TIMEOUT` para indicar que a espera atingiu o tempo limite sem que o evento fosse assinado.

> [!IMPORTANT]
>  Em um aplicativo de plataforma Universal do Windows (UWP), não chame `wait` no thread de ASTA porque essa chamada pode bloquear o thread atual e pode fazer com que o aplicativo pare de responder.

##  <a name="wait_for_multiple"></a> wait_for_multiple

Aguarda vários eventos sejam sinalizados.

```
static size_t __cdecl wait_for_multiple(
    _In_reads_(count) event** _PPEvents,
    size_t count,
    bool _FWaitAll,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```

### <a name="parameters"></a>Parâmetros

*_PPEvents*<br/>
Uma matriz de eventos a espera. O número de eventos dentro da matriz é indicado pelo `count` parâmetro.

*count*<br/>
A contagem de eventos dentro da matriz fornecida no `_PPEvents` parâmetro.

*_FWaitAll*<br/>
Se definido como o valor `true`, o parâmetro especifica que todos os eventos dentro da matriz fornecida no `_PPEvents` parâmetro deve ser assinado para satisfazer a espera. Se definido como o valor `false`, ele especifica que qualquer evento dentro da matriz fornecida no `_PPEvents` parâmetro que for assinado satisfará a espera.

*Tempo limite*<br/>
Indica o número de milissegundos antes que o tempo limite expirar. O valor `COOPERATIVE_TIMEOUT_INFINITE` significa que não há nenhum tempo limite.

### <a name="return-value"></a>Valor de retorno

Se a espera foi satisfazida, o índice dentro da matriz fornecida na `_PPEvents` parâmetro que satisfeito a condição de espera; caso contrário, o valor `COOPERATIVE_WAIT_TIMEOUT` para indicar que a espera atingiu o tempo limite sem condição ser atendida.

### <a name="remarks"></a>Comentários

Se o parâmetro `_FWaitAll` é definido como o valor `true` para indicar que todos os eventos devem ser assinados para satisfazer a espera, o índice retornado pela função leva nenhum significado especial além do fato de que não é o valor `COOPERATIVE_WAIT_TIMEOUT`.

> [!IMPORTANT]
>  Em um aplicativo de plataforma Universal do Windows (UWP), não chame `wait_for_multiple` no thread de ASTA porque essa chamada pode bloquear o thread atual e pode fazer com que o aplicativo pare de responder.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
