---
title: Classe de semáforo | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Semaphore
- corewrappers/Microsoft::WRL::Wrappers::Semaphore::Lock
- corewrappers/Microsoft::WRL::Wrappers::Semaphore::operator=
- corewrappers/Microsoft::WRL::Wrappers::Semaphore::Semaphore
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Wrappers::Semaphore class
- Microsoft::WRL::Wrappers::Semaphore::Lock method
- Microsoft::WRL::Wrappers::Semaphore::operator= operator
- Microsoft::WRL::Wrappers::Semaphore::Semaphore, constructor
ms.assetid: ded53526-17b4-4381-9c60-ea5e77363db6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 78fa5b68bcb55f7d062c1732ab6c30fbe84c22d8
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48789209"
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
