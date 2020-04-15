---
title: Classe mutex (biblioteca padrão C++)| Microsoft Docs
ms.date: 11/04/2016
f1_keywords:
- mutex/std::mutex
- mutex/std::mutex::mutex
- mutex/std::mutex::lock
- mutex/std::mutex::native_handle
- mutex/std::mutex::try_lock
- mutex/std::mutex::unlock
ms.assetid: 7999d055-f74f-4303-810f-8d3c9cde2f69
helpviewer_keywords:
- std::mutex [C++]
- std::mutex [C++], mutex
- std::mutex [C++], lock
- std::mutex [C++], native_handle
- std::mutex [C++], try_lock
- std::mutex [C++], unlock
ms.openlocfilehash: 84e6e3a46903a204444df9886556ae2c563304a9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364840"
---
# <a name="mutex-class-c-standard-library"></a>Classe mutex (biblioteca padrão C++)

Representa um *tipo mutex*. Objetos desse tipo podem ser usados para impor a exclusão mútua dentro de um programa.

## <a name="syntax"></a>Sintaxe

```cpp
class mutex;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Mutex](#mutex)|Constrói um objeto `mutex`.|
|[Destruidor mutex::~mutex](#dtormutex_destructor)|Libera todos os recursos que foram usados pelo objeto `mutex`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Bloqueio](#lock)|Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.|
|[native_handle](#native_handle)|Retorna o tipo específico à implementação que representa o identificador mutex.|
|[try_lock](#try_lock)|Tenta obter a propriedade do `mutex` sem o bloqueio.|
|[Desbloquear](#unlock)|Libera a propriedade do `mutex`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<mutex>

**Namespace:** std

## <a name="mutexlock"></a><a name="lock"></a>mutex::bloqueio

Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.

```cpp
void lock();
```

### <a name="remarks"></a>Comentários

Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="mutexmutex-constructor"></a><a name="mutex"></a>mutex::mutex Construtor

Constrói um objeto `mutex` que não está bloqueado.

```cpp
constexpr mutex() noexcept;
```

## <a name="mutexmutex-destructor"></a><a name="dtormutex_destructor"></a>mutex::~mutex Destructor

Libera todos os recursos usados pelo objeto `mutex`.

```cpp
~mutex();
```

### <a name="remarks"></a>Comentários

Se o objeto estiver bloqueado quando o destruidor for executado, o comportamento será indefinido.

## <a name="mutexnative_handle"></a><a name="native_handle"></a>mutex::native_handle

Retorna o tipo específico à implementação que representa o identificador mutex. O identificador mutex pode ser usado de maneiras específicas da implementação.

```cpp
native_handle_type native_handle();
```

### <a name="return-value"></a>Valor retornado

`native_handle_type` é definido como um `Concurrency::critical_section *` que é convertido como `void *`.

## <a name="mutextry_lock"></a><a name="try_lock"></a>mutex::try_lock

Tenta obter a propriedade do `mutex` sem o bloqueio.

```cpp
bool try_lock();
```

### <a name="return-value"></a>Valor retornado

**verdade** se o método obtém `mutex`com sucesso a propriedade do ; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="mutexunlock"></a><a name="unlock"></a>mutex::desbloquear

Libera a propriedade do `mutex`.

```cpp
void unlock();
```

### <a name="remarks"></a>Comentários

Se o thread de chamada não for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<mutex>](../standard-library/mutex.md)
