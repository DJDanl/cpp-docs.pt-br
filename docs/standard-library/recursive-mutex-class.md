---
title: Classe recursive_mutex
ms.date: 11/04/2016
f1_keywords:
- mutex/std::recursive_mutex
- mutex/std::recursive_mutex::recursive_mutex
- mutex/std::recursive_mutex::lock
- mutex/std::recursive_mutex::try_lock
- mutex/std::recursive_mutex::unlock
ms.assetid: eb5ffd1b-7e78-4559-8391-bb220ead42fc
helpviewer_keywords:
- std::recursive_mutex [C++]
- std::recursive_mutex [C++], recursive_mutex
- std::recursive_mutex [C++], lock
- std::recursive_mutex [C++], try_lock
- std::recursive_mutex [C++], unlock
ms.openlocfilehash: 8455548997c4ccf1b950e26e01df67306554b945
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217604"
---
# <a name="recursive_mutex-class"></a>Classe recursive_mutex

Representa um *tipo mutex*. Em contraste com [mutex](../standard-library/mutex-class-stl.md), o comportamento de chamadas para métodos de bloqueio para objetos que já estão bloqueados é bem definido.

## <a name="syntax"></a>Sintaxe

```cpp
class recursive_mutex;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[recursive_mutex](#recursive_mutex)|Constrói um objeto `recursive_mutex`.|
|[Destruidor ~recursive_mutex](#dtorrecursive_mutex_destructor)|Libera todos os recursos usados pelo objeto `recursive_mutex`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[proprietário](#lock)|Bloqueia o thread de chamada até que ele tenha obtido a propriedade do mutex.|
|[try_lock](#try_lock)|Tenta obter a propriedade do mutex sem bloquear.|
|[automático](#unlock)|Libera a propriedade do mutex.|

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

## <a name="recursive_mutex"></a><a name="recursive_mutex"></a>recursive_mutex

Constrói um objeto `recursive_mutex` que não está bloqueado.

```cpp
recursive_mutex();
```

## <a name="recursive_mutex"></a><a name="dtorrecursive_mutex_destructor"></a>  ~recursive_mutex

Libera todos os recursos que são usados pelo objeto.

```cpp
~recursive_mutex();
```

### <a name="remarks"></a>Comentários

Se o objeto estiver bloqueado quando o destruidor for executado, o comportamento será indefinido.

## <a name="try_lock"></a><a name="try_lock"></a>try_lock

Tenta obter a propriedade do `mutex` sem o bloqueio.

```cpp
bool try_lock() noexcept;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o método obtiver com êxito a propriedade do `mutex` ou se o thread de chamada já possuir o `mutex**; otherwise, **false` .

### <a name="remarks"></a>Comentários

Se o thread de chamada já possuir o `mutex` , a função retornará imediatamente **`true`** e o bloqueio anterior permanecerá em vigor.

## <a name="unlock"></a><a name="unlock"></a>automático

Libera a propriedade do mutex.

```cpp
void unlock();
```

### <a name="remarks"></a>Comentários

Esse método libera a propriedade do `mutex` somente depois que ele é chamado tantas vezes quanto [lock](#lock) e [try_lock](#try_lock) foram chamados com êxito no objeto `recursive_mutex`.

Se o thread de chamada não for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<mutex>](../standard-library/mutex.md)
