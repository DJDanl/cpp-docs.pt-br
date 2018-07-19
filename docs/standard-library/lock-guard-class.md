---
title: lock_guard Class | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- mutex/std::lock_guard
- mutex/std::lock_guard::lock_guard
dev_langs:
- C++
ms.assetid: 57121f0d-9c50-481c-b971-54e64df864e0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7f53732fee62906da19a5771c8598cce51fc6331
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38953740"
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

**Cabeçalho:** \<mutex >

**Namespace:** std

## <a name="lock_guard"></a>  Construtor lock_guard::lock_guard

Constrói um objeto `lock_guard`.

```cpp
explicit lock_guard(mutex_type& Mtx);

lock_guard(mutex_type& Mtx, adopt_lock_t);
```

### <a name="parameters"></a>Parâmetros

*Mtx* um *tipo mutex* objeto.

### <a name="remarks"></a>Comentários

O primeiro construtor constrói um objeto do tipo `lock_guard` e bloqueios *Mtx*. Se *Mtx* não é um mutex recursivo, ele deve ser desbloqueado quando esse construtor é chamado.

O segundo construtor não bloqueia *Mtx*. *Mtx* deve ser bloqueado quando esse construtor é chamado. O construtor não lança exceções.

## <a name="dtorlock_guard_destructor"></a>  Destruidor lock_guard::~lock_guard

Desbloqueia o `mutex` que foi passado ao construtor.

```cpp
~lock_guard() noexcept;
```

### <a name="remarks"></a>Comentários

Se o `mutex` não existir quando o destruidor for executado, o comportamento será indefinido.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<mutex>](../standard-library/mutex.md)<br/>
