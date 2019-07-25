---
title: Classe lock_guard
ms.date: 11/04/2016
f1_keywords:
- mutex/std::lock_guard
- mutex/std::lock_guard::lock_guard
ms.assetid: 57121f0d-9c50-481c-b971-54e64df864e0
ms.openlocfilehash: f59860c3aaa9ef7458fe5e30b85b119dede52c72
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68453850"
---
# <a name="lockguard-class"></a>Classe lock_guard

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

**Cabeçalho:** \<> mutex

**Namespace:** std

## <a name="lock_guard"></a>  Construtor lock_guard::lock_guard

Constrói um objeto `lock_guard`.

```cpp
explicit lock_guard(mutex_type& Mtx);

lock_guard(mutex_type& Mtx, adopt_lock_t);
```

### <a name="parameters"></a>Parâmetros

*MTX*\
Um objeto do *tipo mutex*.

### <a name="remarks"></a>Comentários

O primeiro construtor constrói um objeto do tipo `lock_guard` e bloqueia *MTX*. Se *MTX* não for um mutex recursivo, ele deverá ser desbloqueado quando esse construtor for chamado.

O segundo construtor não bloqueia *MTX*. *MTX* deve ser bloqueado quando este construtor é chamado. O construtor não lança exceções.

## <a name="dtorlock_guard_destructor"></a>  Destruidor lock_guard::~lock_guard

Desbloqueia o `mutex` que foi passado ao construtor.

```cpp
~lock_guard() noexcept;
```

### <a name="remarks"></a>Comentários

Se o `mutex` não existir quando o destruidor for executado, o comportamento será indefinido.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<mutex>](../standard-library/mutex.md)
