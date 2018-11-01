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
ms.openlocfilehash: 10357bb1cd46a33a8d4090c1ccc30050584d1816
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50517709"
---
# <a name="semaphore-class"></a>Classe Semaphore

Representa um objeto de sincronização que controla um recurso compartilhado que pode dar suporte a um número limitado de usuários.

## <a name="syntax"></a>Sintaxe

```cpp
class Semaphore : public HandleT<HandleTraits::SemaphoreTraits>;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome       | Descrição
---------- | ------------------------------------------------------
`SyncLock` | Um sinônimo para uma classe que dá suporte a bloqueios síncronos.

### <a name="public-constructors"></a>Construtores públicos

Nome                               | Descrição
---------------------------------- | ----------------------------------------------------
[Semaphore:: Semaphore](#semaphore) | Inicializa uma nova instância da classe `Semaphore`.

### <a name="public-methods"></a>Métodos públicos

Nome                     | Descrição
------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------
[Semaphore:: Lock](#lock) | Aguarda até que o objeto atual ou o objeto associado com o identificador especificado, estiver no estado sinalizado ou o intervalo de tempo limite especificado tenha decorrido.

### <a name="public-operators"></a>Operadores públicos

Nome                                     | Descrição
---------------------------------------- | ---------------------------------------------------------------------------------------
[Semaphore:: Operator =](#operator-assign) | Move o identificador especificado de uma `Semaphore` o objeto atual `Semaphore` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Semaphore`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="lock"></a>Semaphore:: Lock

Aguarda até que o objeto atual, ou o `Semaphore` objeto associado ao identificador especificado, estiver no estado sinalizado ou o intervalo de tempo limite especificado tenha decorrido.

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
Um identificador para um `Semaphore` objeto.

### <a name="return-value"></a>Valor de retorno

Um `Details::SyncLockWithStatusT<HandleTraits::SemaphoreTraits>`

## <a name="operator-assign"></a>Semaphore:: Operator =

Move o identificador especificado de uma `Semaphore` o objeto atual `Semaphore` objeto.

```cpp
Semaphore& operator=(
   _Inout_ Semaphore&& h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Referência de Rvalue para um `Semaphore` objeto.

### <a name="return-value"></a>Valor de retorno

Uma referência ao atual `Semaphore` objeto.

## <a name="semaphore"></a>Semaphore:: Semaphore

Inicializa uma nova instância da classe `Semaphore`.

```cpp
explicit Semaphore(
   HANDLE h
);

WRL_NOTHROW Semaphore(
   _Inout_ Semaphore&& h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Um identificador ou uma referência rvalue para um `Semaphore` objeto.
