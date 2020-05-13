---
title: Classe Semaphore
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Semaphore
- corewrappers/Microsoft::WRL::Wrappers::Semaphore::Lock
- corewrappers/Microsoft::WRL::Wrappers::Semaphore::operator=
- corewrappers/Microsoft::WRL::Wrappers::Semaphore::Semaphore
helpviewer_keywords:
- Microsoft::WRL::Wrappers::Semaphore class
- Microsoft::WRL::Wrappers::Semaphore::Lock method
- Microsoft::WRL::Wrappers::Semaphore::operator= operator
- Microsoft::WRL::Wrappers::Semaphore::Semaphore, constructor
ms.assetid: ded53526-17b4-4381-9c60-ea5e77363db6
ms.openlocfilehash: e017b1b6316c4b6d49563d9a543950ab28961d90
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359351"
---
# <a name="semaphore-class"></a>Classe Semaphore

Representa um objeto de sincronização que controla um recurso compartilhado que pode suportar um número limitado de usuários.

## <a name="syntax"></a>Sintaxe

```cpp
class Semaphore : public HandleT<HandleTraits::SemaphoreTraits>;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome       | Descrição
---------- | ------------------------------------------------------
`SyncLock` | Um sinônimo para uma classe que suporta bloqueios síncronos.

### <a name="public-constructors"></a>Construtores públicos

Nome                               | Descrição
---------------------------------- | ----------------------------------------------------
[Semáforo::Semáforo](#semaphore) | Inicia uma nova instância da classe `Semaphore`.

### <a name="public-methods"></a>Métodos públicos

Nome                     | Descrição
------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------
[Semáforo::Travamento](#lock) | Aguarde até que o objeto atual, ou o objeto associado à alça especificada, esteja no estado sinalizado ou o intervalo de tempo de saída especificado tenha transcorrido.

### <a name="public-operators"></a>Operadores públicos

Nome                                     | Descrição
---------------------------------------- | ---------------------------------------------------------------------------------------
[Semáforo::operador=](#operator-assign) | Move a alça especificada de `Semaphore` `Semaphore` um objeto para o objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Semaphore`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers

## <a name="semaphorelock"></a><a name="lock"></a>Semáforo::Travamento

Aguarde até que o `Semaphore` objeto atual, ou o objeto associado à alça especificada, esteja no estado sinalizado ou o intervalo de tempo de saída especificado tenha transcorrido.

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

*milliseconds*<br/>
O intervalo de tempo, em milissegundos. O valor padrão é INFINITE, que aguarda indefinidamente.

*H*<br/>
Uma alça `Semaphore` para um objeto.

### <a name="return-value"></a>Valor retornado

Uma `Details::SyncLockWithStatusT<HandleTraits::SemaphoreTraits>`

## <a name="semaphoreoperator"></a><a name="operator-assign"></a>Semáforo::operador=

Move a alça especificada de `Semaphore` `Semaphore` um objeto para o objeto atual.

```cpp
Semaphore& operator=(
   _Inout_ Semaphore&& h
);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
Referência de valor `Semaphore` a um objeto.

### <a name="return-value"></a>Valor retornado

Uma referência ao `Semaphore` objeto atual.

## <a name="semaphoresemaphore"></a><a name="semaphore"></a>Semáforo::Semáforo

Inicia uma nova instância da classe `Semaphore`.

```cpp
explicit Semaphore(
   HANDLE h
);

WRL_NOTHROW Semaphore(
   _Inout_ Semaphore&& h
);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
Uma alça ou uma referência `Semaphore` de valor a um objeto.
