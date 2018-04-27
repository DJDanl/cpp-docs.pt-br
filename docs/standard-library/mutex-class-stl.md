---
title: Classe mutex (biblioteca padrão C++)| Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- mutex/std::mutex
- mutex/std::mutex::mutex
- mutex/std::mutex::lock
- mutex/std::mutex::native_handle
- mutex/std::mutex::try_lock
- mutex/std::mutex::unlock
dev_langs:
- C++
ms.assetid: 7999d055-f74f-4303-810f-8d3c9cde2f69
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
helpviewer_keywords:
- std::mutex [C++]
- std::mutex [C++], mutex
- std::mutex [C++], lock
- std::mutex [C++], native_handle
- std::mutex [C++], try_lock
- std::mutex [C++], unlock
ms.workload:
- cplusplus
ms.openlocfilehash: 88502d595b9686876705a82b6d2f93e7dea8c946
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="mutex-class-c-standard-library"></a>Classe mutex (biblioteca padrão C++)

Representa um *tipo mutex*. Objetos desse tipo podem ser usados para impor a exclusão mútua dentro de um programa.

## <a name="syntax"></a>Sintaxe

```cpp
class mutex;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[mutex](#mutex)|Constrói um objeto `mutex`.|
|[Destruidor mutex::~mutex](#dtormutex_destructor)|Libera todos os recursos que foram usados pelo objeto `mutex`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[lock](#lock)|Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.|
|[native_handle](#native_handle)|Retorna o tipo específico à implementação que representa o identificador mutex.|
|[try_lock](#try_lock)|Tenta obter a propriedade do `mutex` sem o bloqueio.|
|[unlock](#unlock)|Libera a propriedade do `mutex`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<mutex >

**Namespace:** std

## <a name="lock"></a>  mutex::lock

Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.

```cpp
void lock();
```

### <a name="remarks"></a>Comentários

Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="mutex"></a>  Construtor mutex::mutex

Constrói um objeto `mutex` que não está bloqueado.

```cpp
constexpr mutex() noexcept;
```

## <a name="dtormutex_destructor"></a>  Destruidor mutex::~mutex

Libera todos os recursos usados pelo objeto `mutex`.

```cpp
~mutex();
```

### <a name="remarks"></a>Comentários

Se o objeto estiver bloqueado quando o destruidor for executado, o comportamento será indefinido.

## <a name="native_handle"></a>  mutex::native_handle

Retorna o tipo específico à implementação que representa o identificador mutex. O identificador mutex pode ser usado de maneiras específicas da implementação.

```cpp
native_handle_type native_handle();
```

### <a name="return-value"></a>Valor de retorno

`native_handle_type` é definido como um `Concurrency::critical_section *` que é convertido como `void *`.

## <a name="try_lock"></a>  mutex::try_lock

Tenta obter a propriedade do `mutex` sem o bloqueio.

```cpp
bool try_lock();
```

### <a name="return-value"></a>Valor de retorno

`true` se o método obtiver a propriedade do `mutex` com êxito; caso contrário, `false`.

### <a name="remarks"></a>Comentários

Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="unlock"></a>  mutex::unlock

Libera a propriedade do `mutex`.

```cpp
void unlock();
```

### <a name="remarks"></a>Comentários

Se o thread de chamada não for o proprietário do `mutex`, o comportamento será indefinido.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<mutex>](../standard-library/mutex.md)<br/>
