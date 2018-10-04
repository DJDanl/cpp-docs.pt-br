---
title: Classe Mutex | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Mutex
- corewrappers/Microsoft::WRL::Wrappers::Mutex::Lock
- corewrappers/Microsoft::WRL::Wrappers::Mutex::Mutex
- corewrappers/Microsoft::WRL::Wrappers::Mutex::operator=
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Wrappers::Mutex class
- Microsoft::WRL::Wrappers::Mutex::Lock method
- Microsoft::WRL::Wrappers::Mutex::Mutex, constructor
- Microsoft::WRL::Wrappers::Mutex::operator= operator
ms.assetid: 682a0963-721c-46a2-8871-000e9997505b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 37aaafa636f43671eb18436a49490caa10cf349f
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48789300"
---
# <a name="mutex-class"></a>Classe Mutex

Representa um objeto de sincronização que controla exclusivamente um recurso compartilhado.

## <a name="syntax"></a>Sintaxe

```cpp
class Mutex : public HandleT<HandleTraits::MutexTraits>;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome       | Descrição
---------- | ------------------------------------------------------
`SyncLock` | Um sinônimo para uma classe que dá suporte a bloqueios síncronos.

### <a name="public-constructor"></a>Construtor público

Nome                   | Descrição
---------------------- | ------------------------------------------------
[Mutex:: mutex](#mutex) | Inicializa uma nova instância da classe `Mutex`.

### <a name="public-members"></a>Membros públicos

Nome                 | Descrição
-------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------
[Mutex:: Lock](#lock) | Aguarda até que o objeto atual, ou o `Mutex` objeto associado ao identificador especificado, versões mutex ou o intervalo de tempo limite especificado tiver decorrido.

### <a name="public-operator"></a>Operador público

Nome                                 | Descrição
------------------------------------ | ---------------------------------------------------------------------------
[Mutex:: Operator =](#operator-assign) | Atribui (se move) especificado `Mutex` o objeto atual `Mutex` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Mutex`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="lock"></a>Mutex:: Lock

Aguarda até que o objeto atual, ou o `Mutex` objeto associado ao identificador especificado, versões mutex ou o intervalo de tempo limite especificado tiver decorrido.

```cpp
SyncLock Lock(
   DWORD milliseconds = INFINITE
);

static SyncLock Lock(
   HANDLE h,
   DWORD milliseconds = INFINITE
);
```

### <a name="parameters"></a>Parâmetros

*milissegundos*<br/>
O intervalo de tempo limite em milissegundos. O valor padrão é infinito, o que espera indefinidamente.

*h*<br/>
O identificador de um `Mutex` objeto.

### <a name="return-value"></a>Valor de retorno

## <a name="mutex"></a>Mutex:: mutex

Inicializa uma nova instância da classe `Mutex`.

```cpp
explicit Mutex(
   HANDLE h
);

Mutex(
   _Inout_ Mutex&& h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Um identificador ou uma referência de rvalue a um identificador para um `Mutex` objeto.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa um `Mutex` objeto do identificador especificado. O segundo construtor inicializa um `Mutex` objeto do identificador especificado e, em seguida, move o propriedade do mutex atual `Mutex` objeto.

## <a name="operator-assign"></a>Mutex:: Operator =

Atribui (se move) especificado `Mutex` o objeto atual `Mutex` objeto.

```cpp
Mutex& operator=(
   _Inout_ Mutex&& h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Uma referência rvalue para um `Mutex` objeto.

### <a name="return-value"></a>Valor de retorno

Uma referência ao atual `Mutex` objeto.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o **mover semântica** seção [Declarador de referência Rvalue: & &](../cpp/rvalue-reference-declarator-amp-amp.md).
