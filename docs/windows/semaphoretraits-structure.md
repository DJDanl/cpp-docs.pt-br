---
title: Estrutura SemaphoreTraits
ms.date: 09/27/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SemaphoreTraits
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SemaphoreTraits::Unlock
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HandleTraits::SemaphoreTraits structure
- Microsoft::WRL::Wrappers::HandleTraits::SemaphoreTraits::Unlock method
ms.assetid: eddb8576-d063-409b-9201-cc87ca5d111e
ms.openlocfilehash: e7bd2e5d0993c8e4be7223d98ffb1dbec14cbb74
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50502930"
---
# <a name="semaphoretraits-structure"></a>Estrutura SemaphoreTraits

Define as características comuns de um `Semaphore` objeto.

## <a name="syntax"></a>Sintaxe

```cpp
struct SemaphoreTraits : HANDLENullTraits;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

Nome                               | Descrição
---------------------------------- | --------------------------------------
[Semaphoretraits:: Unlock](#unlock) | Controle de versões de um recurso compartilhado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HANDLENullTraits`

`SemaphoreTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="unlock"></a>Semaphoretraits:: Unlock

Controle de versões de um recurso compartilhado.

```cpp
inline static void Unlock(
   _In_ Type h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Identificador para um `Semaphore` objeto.

### <a name="remarks"></a>Comentários

Se não for bem-sucedida, a operação de desbloqueio `Unlock()` emite um erro que indica a causa da falha.
