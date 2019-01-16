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
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335644"
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
[SemaphoreTraits::Unlock](#unlock) | Controle de versões de um recurso compartilhado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HANDLENullTraits`

`SemaphoreTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="unlock"></a>SemaphoreTraits::Unlock

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
