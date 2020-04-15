---
title: Classe lock_guard
ms.date: 11/04/2016
f1_keywords:
- mutex/std::lock_guard
- mutex/std::lock_guard::lock_guard
ms.assetid: 57121f0d-9c50-481c-b971-54e64df864e0
ms.openlocfilehash: 989c1e368e95fc0009f0c3f1c71af0bdba20609d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81351712"
---
# <a name="lock_guard-class"></a>Classe lock_guard

Representa um modelo que pode ser instanciado para criar um objeto cujo destruidor desbloqueia um `mutex`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Mutex>
class lock_guard;
```

## <a name="remarks"></a>Comentários

O argumento de modelo `Mutex` deve nomear um *tipo mutex*.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`lock_guard::mutex_type`|Sinônimo para o argumento de modelo `Mutex`.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[lock_guard](#lock_guard)|Constrói um objeto `lock_guard`.|
|[Destruidor lock_guard::~lock_guard](#dtorlock_guard_destructor)|Desbloqueia o `mutex` que foi passado ao construtor.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<mutex>

**Namespace:** std

## <a name="lock_guardlock_guard-constructor"></a><a name="lock_guard"></a>lock_guard:lock_guard Construtor

Constrói um objeto `lock_guard`.

```cpp
explicit lock_guard(mutex_type& Mtx);

lock_guard(mutex_type& Mtx, adopt_lock_t);
```

### <a name="parameters"></a>Parâmetros

*Mtx*\
Um objeto *tipo mutex.*

### <a name="remarks"></a>Comentários

O primeiro construtor constrói um `lock_guard` objeto de tipo e bloqueia *o Mtx*. Se *o Mtx* não for um mutex recursivo, ele deve ser desbloqueado quando este construtor é chamado.

A segunda construtora não bloqueia *a Mtx*. *Mtx* deve estar trancado quando este construtor é chamado. O construtor não lança exceções.

## <a name="lock_guardlock_guard-destructor"></a><a name="dtorlock_guard_destructor"></a>lock_guard::~lock_guard Destructor

Desbloqueia o `mutex` que foi passado ao construtor.

```cpp
~lock_guard() noexcept;
```

### <a name="remarks"></a>Comentários

Se o `mutex` não existir quando o destruidor for executado, o comportamento será indefinido.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<mutex>](../standard-library/mutex.md)
