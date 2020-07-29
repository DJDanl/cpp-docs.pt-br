---
title: Classe event
ms.date: 11/04/2016
f1_keywords:
- CONCRT/concurrency::event
- CONCRT/concurrency::event::reset
- CONCRT/concurrency::event::set
- CONCRT/concurrency::event::wait
- CONCRT/concurrency::event::wait_for_multiple
- CONCRT/concurrency::event::timeout_infinite
helpviewer_keywords:
- event class
ms.assetid: fba35a53-6568-4bfa-9aaf-07c0928cf73d
ms.openlocfilehash: 3f2ec71083f7a7905bad5cda014baba914e31e79
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215797"
---
# <a name="event-class"></a>Classe event

Um evento de redefinição manual que reconhece explicitamente o Tempo de Execução de Simultaneidade.

## <a name="syntax"></a>Sintaxe

```cpp
class event;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[~ Destruidor de evento](#dtor)|Destrói um evento.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[reset](#reset)|Redefine o evento para um estado não sinalizado.|
|[set](#set)|Sinaliza o evento.|
|[esperado](#wait)|Aguarda até que o evento se torne sinalizado.|
|[wait_for_multiple](#wait_for_multiple)|Aguarda que vários eventos sejam sinalizados.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[timeout_infinite](#timeout_infinite)|Valor que indica que uma espera nunca deve atingir o tempo limite.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Synchronization data structures](../../../parallel/concrt/synchronization-data-structures.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`event`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="event"></a>Evento <a name="ctor"></a>

Constrói um novo evento.

```cpp
_CRTIMP event();
```

### <a name="remarks"></a>Comentários

## <a name="event"></a><a name="dtor"></a>~ evento

Destrói um evento.

```cpp
~event();
```

### <a name="remarks"></a>Comentários

Espera-se que não haja threads aguardando o evento quando o destruidor for executado. Permitir que o evento seja destruido com threads ainda aguardando isso resulta em um comportamento indefinido.

## <a name="reset"></a><a name="reset"></a>definido

Redefine o evento para um estado não sinalizado.

```cpp
void reset();
```

## <a name="set"></a><a name="set"></a>Definição

Sinaliza o evento.

```cpp
void set();
```

### <a name="remarks"></a>Comentários

Sinalizar o evento pode causar um número arbitrário de contextos aguardando que o evento se torne executável.

## <a name="timeout_infinite"></a><a name="timeout_infinite"></a>timeout_infinite

Valor que indica que uma espera nunca deve atingir o tempo limite.

```cpp
static const unsigned int timeout_infinite = COOPERATIVE_TIMEOUT_INFINITE;
```

## <a name="wait"></a><a name="wait"></a>esperado

Aguarda até que o evento se torne sinalizado.

```cpp
size_t wait(unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```

### <a name="parameters"></a>parâmetros

*_Timeout*<br/>
Indica o número de milissegundos antes da espera expirar. O valor `COOPERATIVE_TIMEOUT_INFINITE` significa que não há nenhum tempo limite.

### <a name="return-value"></a>Valor retornado

Se a espera for satisfeita, o valor `0` será retornado; caso contrário, o valor `COOPERATIVE_WAIT_TIMEOUT` para indicar que a espera atingiu o tempo limite sem que o evento se torne sinalizado.

> [!IMPORTANT]
> Em um aplicativo Plataforma Universal do Windows (UWP), não chame `wait` no thread Asta porque essa chamada pode bloquear o thread atual e pode fazer com que o aplicativo fique sem resposta.

## <a name="wait_for_multiple"></a><a name="wait_for_multiple"></a>wait_for_multiple

Aguarda que vários eventos sejam sinalizados.

```cpp
static size_t __cdecl wait_for_multiple(
    _In_reads_(count) event** _PPEvents,
    size_t count,
    bool _FWaitAll,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```

### <a name="parameters"></a>parâmetros

*_PPEvents*<br/>
Uma matriz de eventos para aguardar. O número de eventos dentro da matriz é indicado pelo `count` parâmetro.

*contagem*<br/>
A contagem de eventos dentro da matriz fornecida no `_PPEvents` parâmetro.

*_FWaitAll*<br/>
Se definido como o valor **`true`** , o parâmetro especifica que todos os eventos dentro da matriz fornecida no `_PPEvents` parâmetro devem ser sinalizados para atender à espera. Se definido como o valor **`false`** , ele especifica que qualquer evento dentro da matriz fornecida no parâmetro que está `_PPEvents` se tornando sinalizado atenderá à espera.

*_Timeout*<br/>
Indica o número de milissegundos antes da espera expirar. O valor `COOPERATIVE_TIMEOUT_INFINITE` significa que não há nenhum tempo limite.

### <a name="return-value"></a>Valor retornado

Se a espera foi satisfeita, o índice na matriz fornecida no `_PPEvents` parâmetro que satisfez a condição de espera; caso contrário, o valor `COOPERATIVE_WAIT_TIMEOUT` para indicar que a espera atingiu o tempo limite sem que a condição esteja satisfeita.

### <a name="remarks"></a>Comentários

Se o parâmetro `_FWaitAll` for definido como o valor **`true`** para indicar que todos os eventos devem ser sinalizados para atender à espera, o índice retornado pela função não terá nenhum significado especial além do fato de não ser o valor `COOPERATIVE_WAIT_TIMEOUT` .

> [!IMPORTANT]
> Em um aplicativo Plataforma Universal do Windows (UWP), não chame `wait_for_multiple` no thread Asta porque essa chamada pode bloquear o thread atual e pode fazer com que o aplicativo fique sem resposta.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
