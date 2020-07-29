---
title: Classe unique_lock
ms.date: 11/04/2016
f1_keywords:
- mutex/std::unique_lock
ms.assetid: f4ed8ba9-c8af-446f-8ef0-0b356bad14bd
ms.openlocfilehash: 189fd70ce10b6067646553f2b92a8fc09239d054
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212029"
---
# <a name="unique_lock-class"></a>Classe unique_lock

Representa um modelo que pode ser instanciado para criar objetos que gerenciam o bloqueio e o desbloqueio de um `mutex`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Mutex>
class unique_lock;
```

## <a name="remarks"></a>Comentários

O argumento de modelo `Mutex` deve nomear um *tipo mutex*.

Internamente, um `unique_lock` armazena um ponteiro para um `mutex` objeto associado e um **`bool`** que indica se o thread atual é proprietário do `mutex` .

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`mutex_type`|Sinônimo para o argumento de modelo `Mutex`.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[unique_lock](#unique_lock)|Constrói um objeto `unique_lock`.|
|[~ unique_lock destruidor](#dtorunique_lock_destructor)|Libera quaisquer recursos que são usados pelo objeto `unique_lock`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[proprietário](#lock)|Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex` associado.|
|[CLUSA](#mutex)|Recupera o ponteiro armazenado para `mutex` associado.|
|[owns_lock](#owns_lock)|Especifica se o thread de chamada possui o `mutex` associado.|
|[liberar](#release)|Desassocia o `unique_lock` objeto do objeto `mutex` associado.|
|[permuta](#swap)|Alterna o `mutex` associado e status de propriedade com um objeto especificado.|
|[try_lock](#try_lock)|Tenta obter a propriedade do `mutex` associado, sem o bloqueio.|
|[try_lock_for](#try_lock_for)|Tenta obter a propriedade do `mutex` associado, sem o bloqueio.|
|[try_lock_until](#try_lock_until)|Tenta obter a propriedade do `mutex` associado, sem o bloqueio.|
|[automático](#unlock)|Libera a propriedade do `mutex` associado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[booliano de operador](#op_bool)|Especifica se o thread de chamada tem o `mutex` associado.|
|[operador =](#op_eq)|Copia o ponteiro `mutex` armazenado e o status de propriedade associados de um objeto especificado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

*unique_lock*

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<mutex>

**Namespace:** std

## <a name="lock"></a><a name="lock"></a>proprietário

Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex` associado.

```cpp
void lock();
```

### <a name="remarks"></a>Comentários

Se o `mutex` ponteiro armazenado for nulo, esse método lançará um [system_error](../standard-library/system-error-class.md) que tem um código de erro `operation_not_permitted` .

Se o thread de chamada já possui `mutex` associado, esse método lançará um `system_error` que tem um código de erro de `resource_deadlock_would_occur`.

Caso contrário, esse método chama `lock` o associado `mutex` e define o sinalizador de propriedade de thread interno como **`true`** .

## <a name="mutex"></a><a name="mutex"></a>CLUSA

Recupera o ponteiro armazenado para `mutex` associado.

```cpp
mutex_type *mutex() const noexcept;
```

## <a name="operator-bool"></a><a name="op_bool"></a>booliano de operador

Especifica se o thread de chamada tem o mutex associado.

```cpp
explicit operator bool() noexcept
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o thread possuir o mutex; caso contrário **`false`** .

## <a name="operator"></a><a name="op_eq"></a>operador =

Copia o ponteiro `mutex` armazenado e o status de propriedade associados de um objeto especificado.

```cpp
unique_lock& operator=(unique_lock&& Other) noexcept;
```

### <a name="parameters"></a>parâmetros

*Outros*\
Um objeto `unique_lock`.

### <a name="return-value"></a>Valor retornado

`*this`

### <a name="remarks"></a>Comentários

Se o thread de chamada possui o `mutex` previamente associado, antes desse método chamar `unlock` no `mutex`, ele atribui novos valores.

Após a cópia, esse método define *outro* para um estado padrão construído.

## <a name="owns_lock"></a><a name="owns_lock"></a>owns_lock

Especifica se o thread de chamada possui o `mutex` associado.

```cpp
bool owns_lock() const noexcept;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o thread for proprietário de `mutex` ; caso contrário, **`false`** .

## <a name="release"></a><a name="release"></a>liberar

Desassocia o `unique_lock` objeto do objeto `mutex` associado.

```cpp
mutex_type *release() noexcept;
```

### <a name="return-value"></a>Valor retornado

O valor anterior do ponteiro `mutex` armazenado.

### <a name="remarks"></a>Comentários

Esse método define o valor do ponteiro armazenado `mutex` como 0 e define o sinalizador de `mutex` propriedade interna como **`false`** .

## <a name="swap"></a><a name="swap"></a>permuta

Alterna o `mutex` associado e status de propriedade com um objeto especificado.

```cpp
void swap(unique_lock& Other) noexcept;
```

### <a name="parameters"></a>parâmetros

*Outros*\
Um objeto `unique_lock`.

## <a name="try_lock"></a><a name="try_lock"></a>try_lock

Tenta obter a propriedade do `mutex` associado, sem o bloqueio.

```cpp
bool try_lock() noexcept;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o método obtiver a propriedade de `mutex` ; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Se o `mutex` ponteiro armazenado for nulo, o método lançará um [system_error](../standard-library/system-error-class.md) que tem um código de erro `operation_not_permitted` .

Se o thread de chamada já possui o `mutex`, esse método lança um `system_error` que tem um código de erro de `resource_deadlock_would_occur`.

## <a name="try_lock_for"></a><a name="try_lock_for"></a>try_lock_for

Tenta obter a propriedade do `mutex` associado, sem o bloqueio.

```cpp
template <class Rep, class Period>
bool try_lock_for(
    const chrono::duration<Rep, Period>& Rel_time);
```

### <a name="parameters"></a>parâmetros

*Rel_time*\
Um objeto [chrono::duration](../standard-library/duration-class.md) que especifica o tempo máximo que o método tenta obter a propriedade do `mutex`.

### <a name="return-value"></a>Valor retornado

**`true`** Se o método obtiver a propriedade de `mutex` ; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Se o `mutex` ponteiro armazenado for nulo, o método lançará um [system_error](../standard-library/system-error-class.md) que tem um código de erro `operation_not_permitted` .

Se o thread de chamada já possui o `mutex`, esse método lança um `system_error` que tem um código de erro de `resource_deadlock_would_occur`.

## <a name="try_lock_until"></a><a name="try_lock_until"></a>try_lock_until

Tenta obter a propriedade do `mutex` associado, sem o bloqueio.

```cpp
template <class Clock, class Duration>
bool try_lock_until(const chrono::time_point<Clock, Duration>& Abs_time);

bool try_lock_until(const xtime* Abs_time);
```

### <a name="parameters"></a>parâmetros

*Abs_time*\
Um ponto no tempo que especifica o limite após o qual o método não tenta mais obter a propriedade do `mutex`.

### <a name="return-value"></a>Valor retornado

**`true`** Se o método obtiver a propriedade de `mutex` ; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Se o `mutex` ponteiro armazenado for nulo, o método lançará um [system_error](../standard-library/system-error-class.md) que tem um código de erro `operation_not_permitted` .

Se o thread de chamada já possui o `mutex`, esse método lança um `system_error` que tem um código de erro de `resource_deadlock_would_occur`.

## <a name="unique_lock-constructor"></a><a name="unique_lock"></a>Construtor de unique_lock

Constrói um objeto `unique_lock`.

```cpp
unique_lock() noexcept;
unique_lock(unique_lock&& Other) noexcept;
explicit unique_lock(mutex_type& Mtx);

unique_lock(mutex_type& Mtx, adopt_lock_t Adopt);

unique_lock(mutex_type& Mtx, defer_lock_t Defer) noexcept;
unique_lock(mutex_type& Mtx, try_to_lock_t Try);

template <class Rep, class Period>
unique_lock(mutex_type& Mtx,
    const chrono::duration<Rep, Period>
Rel_time);

template <class Clock, class Duration>
unique_lock(mutex_type& Mtx,
    const chrono::time_point<Clock, Duration>
Abs_time);

unique_lock(mutex_type& Mtx,
    const xtime* Abs_time) noexcept;
```

### <a name="parameters"></a>parâmetros

*MTX*\
Um objeto do tipo mutex.

*Rel_time*\
Um objeto [chrono::duration](../standard-library/duration-class.md) que especifica o tempo máximo que o método tenta obter a propriedade do `mutex`.

*Abs_time*\
Um ponto no tempo que especifica o limite após o qual o método não tenta mais obter a propriedade do `mutex`.

*Outros*\
Um objeto `unique_lock`.

### <a name="remarks"></a>Comentários

O primeiro construtor constrói um objeto que tem um valor de ponteiro mutex associado de 0.

O segundo Construtor move o status de mutex associado de *outro*. Após a movimentação, a *outra* não está mais associada a um mutex.

Os construtores restantes armazenam & *MTX* como o `mutex` ponteiro armazenado. Propriedade do `mutex` será determinada pelo segundo argumento, se ele existir.

|||
|-|-|
|`No argument`|Propriedade é obtida chamando o método de `lock` no objeto `mutex` associado.|
|`Adopt`|Propriedade será assumida. `Mtx` deve ser bloqueado quando esse construtor for chamado.|
|`Defer`|O thread de chamada é presumido como não possuindo o objeto `mutex`. `Mtx` não deve ser bloqueado quando esse construtor for chamado.|
|`Try`|Propriedade é obtida chamando `try_lock` no objeto `mutex` associado. O construtor não lança nada.|
|`Rel_time`|Propriedade é determinada pela chamada de `try_lock_for(Rel_time)`.|
|`Abs_time`|Propriedade é determinada pela chamada de `try_lock_until(Abs_time)`.|

## <a name="unique_lock-destructor"></a><a name="dtorunique_lock_destructor"></a> Destruidor ~unique_lock

Libera quaisquer recursos que são usados pelo objeto `unique_lock`.

```cpp
~unique_lock() noexcept;
```

### <a name="remarks"></a>Comentários

Se o thread de chamada possui `mutex` associado, o destruidor libera a propriedade chamando desbloqueio no objeto `mutex`.

## <a name="unlock"></a><a name="unlock"></a>automático

Libera a propriedade do `mutex` associado.

```cpp
void unlock();
```

### <a name="remarks"></a>Comentários

Se o thread de chamada não possui `mutex` associado, esse método lança um [system_error](../standard-library/system-error-class.md) que tem um código de erro de `operation_not_permitted`.

Caso contrário, esse método chama `unlock` o associado `mutex` e define o sinalizador de propriedade de thread interno como **`false`** .

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<mutex>](../standard-library/mutex.md)
