---
title: Classe recursive_mutex | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- mutex/std::recursive_mutex
- mutex/std::recursive_mutex::recursive_mutex
- mutex/std::recursive_mutex::lock
- mutex/std::recursive_mutex::try_lock
- mutex/std::recursive_mutex::unlock
dev_langs:
- C++
ms.assetid: eb5ffd1b-7e78-4559-8391-bb220ead42fc
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
helpviewer_keywords:
- std::recursive_mutex [C++]
- std::recursive_mutex [C++], recursive_mutex
- std::recursive_mutex [C++], lock
- std::recursive_mutex [C++], try_lock
- std::recursive_mutex [C++], unlock
ms.workload:
- cplusplus
ms.openlocfilehash: 277577fc8a126a23d9531de2a7c87cdb4b0bc673
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="recursivemutex-class"></a>Classe recursive_mutex

Representa um *tipo mutex*. Em contraste com [mutex](../standard-library/mutex-class-stl.md), o comportamento de chamadas para métodos de bloqueio para objetos que já estão bloqueados é bem definido.

## <a name="syntax"></a>Sintaxe

```cpp
class recursive_mutex;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[recursive_mutex](#recursive_mutex)|Constrói um objeto `recursive_mutex`.|
|[Destruidor ~recursive_mutex](#dtorrecursive_mutex_destructor)|Libera todos os recursos usados pelo objeto `recursive_mutex`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[lock](#lock)|Bloqueia o thread de chamada até que ele tenha obtido a propriedade do mutex.|
|[try_lock](#try_lock)|Tenta obter a propriedade do mutex sem bloquear.|
|[unlock](#unlock)|Libera a propriedade do mutex.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<mutex >

**Namespace:** std

## <a name="lock"></a>  lock

Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.

```cpp
void lock();
```

### <a name="remarks"></a>Comentários

Se o thread de chamada já possuir o `mutex`, o método retornará imediatamente e o bloqueio anterior permanece em vigor.

## <a name="recursive_mutex"></a>  recursive_mutex

Constrói um objeto `recursive_mutex` que não está bloqueado.

```cpp
recursive_mutex();
```

## <a name="dtorrecursive_mutex_destructor"></a>  ~recursive_mutex

Libera todos os recursos que são usados pelo objeto.

```cpp
~recursive_mutex();
```

### <a name="remarks"></a>Comentários

Se o objeto estiver bloqueado quando o destruidor for executado, o comportamento será indefinido.

## <a name="try_lock"></a>  try_lock

Tenta obter a propriedade do `mutex` sem o bloqueio.

```cpp
bool try_lock() noexcept;
```

### <a name="return-value"></a>Valor de retorno

`true` se o método obtiver a propriedade do `mutex` com êxito ou se o thread de chamada já possui o `mutex`; caso contrário, `false`.

### <a name="remarks"></a>Comentários

Se o thread de chamada já possui o `mutex`, a função retorna `true` imediatamente e o bloqueio anterior permanece em vigor.

## <a name="unlock"></a>  unlock

Libera a propriedade do mutex.

```cpp
void unlock();
```

### <a name="remarks"></a>Comentários

Esse método libera a propriedade do `mutex` somente depois que ele é chamado tantas vezes quanto [lock](#lock) e [try_lock](#try_lock) foram chamados com êxito no objeto `recursive_mutex`.

Se o thread de chamada não for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<mutex>](../standard-library/mutex.md)<br/>
