---
title: Classe recursive_timed_mutex
ms.date: 11/04/2016
f1_keywords:
- mutex/std::recursive_timed_mutex
- mutex/std::recursive_timed_mutex::recursive_timed_mutex
- mutex/std::recursive_timed_mutex::lock
- mutex/std::recursive_timed_mutex::try_lock
- mutex/std::recursive_timed_mutex::try_lock_for
- mutex/std::recursive_timed_mutex::try_lock_until
- mutex/std::recursive_timed_mutex::unlock
ms.assetid: 59cc2d5c-ed80-45f3-a0a8-05652a8ead7e
helpviewer_keywords:
- std::recursive_timed_mutex [C++]
- std::recursive_timed_mutex [C++], recursive_timed_mutex
- std::recursive_timed_mutex [C++], lock
- std::recursive_timed_mutex [C++], try_lock
- std::recursive_timed_mutex [C++], try_lock_for
- std::recursive_timed_mutex [C++], try_lock_until
- std::recursive_timed_mutex [C++], unlock
ms.openlocfilehash: 15517425f3d81bc3798df2e42f39ac0b0d32ba31
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217591"
---
# <a name="recursive_timed_mutex-class"></a>Classe recursive_timed_mutex

Representa um *tipo de mutex cronometrado*. Objetos desse tipo são usados para impor a exclusão mútua usando o tempo limite de bloqueio dentro de um programa. Ao contrário de objetos do tipo [timed_mutex](../standard-library/timed-mutex-class.md), o efeito de chamar métodos de bloqueio para objetos `recursive_timed_mutex` é bem definido.

## <a name="syntax"></a>Sintaxe

```cpp
class recursive_timed_mutex;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[recursive_timed_mutex](#recursive_timed_mutex)|Constrói um objeto `recursive_timed_mutex` que não está bloqueado.|
|[~ recursive_timed_mutex destruidor](#dtorrecursive_timed_mutex_destructor)|Libera todos os recursos usados pelo objeto `recursive_timed_mutex`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[proprietário](#lock)|Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.|
|[try_lock](#try_lock)|Tenta obter a propriedade do `mutex` sem o bloqueio.|
|[try_lock_for](#try_lock_for)|Tenta obter a propriedade do `mutex` por um intervalo de tempo especificado.|
|[try_lock_until](#try_lock_until)|Tenta obter a propriedade do `mutex` até um tempo especificado.|
|[automático](#unlock)|Libera a propriedade do `mutex`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<mutex>

**Namespace:** std

## <a name="lock"></a><a name="lock"></a>proprietário

Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.

```cpp
void lock();
```

### <a name="remarks"></a>Comentários

Se o thread de chamada já possuir o `mutex`, o método retornará imediatamente e o bloqueio anterior permanece em vigor.

## <a name="recursive_timed_mutex-constructor"></a><a name="recursive_timed_mutex"></a>Construtor de recursive_timed_mutex

Constrói um objeto `recursive_timed_mutex` que não está bloqueado.

```cpp
recursive_timed_mutex();
```

## <a name="recursive_timed_mutex-destructor"></a><a name="dtorrecursive_timed_mutex_destructor"></a>  Destruidor ~recursive_timed_mutex

Libera todos os recursos usados pelo objeto `recursive_timed_mutex`.

```cpp
~recursive_timed_mutex();
```

### <a name="remarks"></a>Comentários

Se o objeto estiver bloqueado quando o destruidor for executado, o comportamento será indefinido.

## <a name="try_lock"></a><a name="try_lock"></a>try_lock

Tenta obter a propriedade do `mutex` sem o bloqueio.

```cpp
bool try_lock() noexcept;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o método tiver obtido com êxito a propriedade do `mutex` ou se o thread de chamada já possuir o `mutex` ; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Se o thread de chamada já possuir o `mutex` , a função retornará imediatamente **`true`** e o bloqueio anterior permanecerá em vigor.

## <a name="try_lock_for"></a><a name="try_lock_for"></a>try_lock_for

Tenta obter a propriedade do `mutex` sem o bloqueio.

```cpp
template <class Rep, class Period>
bool try_lock_for(const chrono::duration<Rep, Period>& Rel_time);
```

### <a name="parameters"></a>parâmetros

*Rel_time*\
Um objeto [chrono::duration](../standard-library/duration-class.md) que especifica o tempo máximo que o método tenta obter a propriedade do `mutex`.

### <a name="return-value"></a>Valor retornado

**`true`** Se o método obtiver a propriedade do `mutex` ou se o thread de chamada já possuir o `mutex` ; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Se o thread de chamada já possuir o `mutex` , o método retornará imediatamente **`true`** e o bloqueio anterior permanecerá em vigor.

## <a name="try_lock_until"></a><a name="try_lock_until"></a>try_lock_until

Tenta obter a propriedade do `mutex` sem o bloqueio.

```cpp
template <class Clock, class Duration>
bool try_lock_for(const chrono::time_point<Clock, Duration>& Abs_time);

bool try_lock_until(const xtime* Abs_time);
```

### <a name="parameters"></a>parâmetros

*Abs_time*\
Um ponto no tempo que especifica o limite após o qual o método não tenta mais obter a propriedade do `mutex`.

### <a name="return-value"></a>Valor retornado

**`true`** Se o método obtiver a propriedade do `mutex` ou se o thread de chamada já possuir o `mutex` ; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Se o thread de chamada já possuir o `mutex` , o método retornará imediatamente **`true`** e o bloqueio anterior permanecerá em vigor.

## <a name="unlock"></a><a name="unlock"></a>automático

Libera a propriedade do `mutex`.

```cpp
void unlock();
```

### <a name="remarks"></a>Comentários

Esse método libera a propriedade do `mutex` somente depois que ele é chamado tantas vezes quanto [lock](#lock), [try_lock](#try_lock), [try_lock_for](#try_lock_for) e [try_lock_until](#try_lock_until) foram chamados com êxito no objeto `recursive_timed_mutex`.

Se o thread de chamada não for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<mutex>](../standard-library/mutex.md)
