---
title: Classe timed_mutex
ms.date: 11/04/2016
f1_keywords:
- mutex/std::timed_mutex
- mutex/std::timed_mutex::timed_mutex
- mutex/std::timed_mutex::lock
- mutex/std::timed_mutex::try_lock
- mutex/std::timed_mutex::try_lock_for
- mutex/std::timed_mutex::try_lock_until
- mutex/std::timed_mutex::unlock
ms.assetid: cd198081-6f38-447a-9dba-e06dfbfafe59
helpviewer_keywords:
- std::timed_mutex [C++]
- std::timed_mutex [C++], timed_mutex
- std::timed_mutex [C++], lock
- std::timed_mutex [C++], try_lock
- std::timed_mutex [C++], try_lock_for
- std::timed_mutex [C++], try_lock_until
- std::timed_mutex [C++], unlock
ms.openlocfilehash: 3329c46f0760a13693507de18a09b974b6b646e2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212092"
---
# <a name="timed_mutex-class"></a>Classe timed_mutex

Representa um *tipo de mutex cronometrado*. Objetos desse tipo são usados para impor a exclusão mútua por meio do bloqueio com tempo limite em um programa.

## <a name="syntax"></a>Sintaxe

```cpp
class timed_mutex;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[timed_mutex](#timed_mutex)|Constrói um objeto `timed_mutex` que não está bloqueado.|
|[Destruidor de timed_mutex:: ~ timed_mutex](#dtortimed_mutex_destructor)|Libera todos os recursos usados pelo objeto `timed_mutex`.|

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

## <a name="timed_mutexlock"></a><a name="lock"></a>timed_mutex:: bloquear

Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.

```cpp
void lock();
```

### <a name="remarks"></a>Comentários

Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="timed_mutextimed_mutex-constructor"></a><a name="timed_mutex"></a>Construtor timed_mutex:: timed_mutex

Constrói um objeto `timed_mutex` que não está bloqueado.

```cpp
timed_mutex();
```

## <a name="timed_mutextimed_mutex-destructor"></a><a name="dtortimed_mutex_destructor"></a>Destruidor de timed_mutex:: ~ timed_mutex

Libera todos os recursos usados pelo objeto `mutex`.

```cpp
~timed_mutex();
```

### <a name="remarks"></a>Comentários

Se o objeto estiver bloqueado quando o destruidor for executado, o comportamento será indefinido.

## <a name="timed_mutextry_lock"></a><a name="try_lock"></a>timed_mutex:: try_lock

Tenta obter a propriedade do `mutex` sem o bloqueio.

```cpp
bool try_lock();
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o método obtiver a propriedade de `mutex` ; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="timed_mutextry_lock_for"></a><a name="try_lock_for"></a>timed_mutex:: try_lock_for

Tenta obter a propriedade do `mutex` sem o bloqueio.

```cpp
template <class Rep, class Period>
bool try_lock_for(const chrono::duration<Rep, Period>& Rel_time);
```

### <a name="parameters"></a>parâmetros

*Rel_time*\
Um objeto [chrono::duration](../standard-library/duration-class.md) que especifica o tempo máximo que o método tenta obter a propriedade do `mutex`.

### <a name="return-value"></a>Valor retornado

**`true`** Se o método obtiver a propriedade de `mutex` ; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="timed_mutextry_lock_until"></a><a name="try_lock_until"></a>timed_mutex:: try_lock_until

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

**`true`** Se o método obtiver a propriedade de `mutex` ; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="timed_mutexunlock"></a><a name="unlock"></a>timed_mutex:: desbloquear

Libera a propriedade do `mutex`.

```cpp
void unlock();
```

### <a name="remarks"></a>Comentários

Se o thread de chamada não for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<mutex>](../standard-library/mutex.md)
