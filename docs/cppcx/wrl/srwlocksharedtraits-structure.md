---
title: Estrutura SRWLockSharedTraits
ms.date: 09/27/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits::GetInvalidValue
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits::Unlock
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits structure
- Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits::GetInvalidValue method
- Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits::Unlock method
ms.assetid: 709cb51e-d70c-40b6-bdb4-d8eacf3af495
ms.openlocfilehash: 0dc43d4b9c16145ed7a5abe03cddb598c59b1e94
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374294"
---
# <a name="srwlocksharedtraits-structure"></a>Estrutura SRWLockSharedTraits

Descreve características comuns `SRWLock` da classe no modo de bloqueio compartilhado.

## <a name="syntax"></a>Sintaxe

```cpp
struct SRWLockSharedTraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | --------------------------------------------------------------------------
`Type` | Sinônimo de ponteiro para a classe [SRWLOCK.](srwlock-class.md)

### <a name="public-methods"></a>Métodos públicos

Nome                                                     | Descrição
-------------------------------------------------------- | -----------------------------------------------------------------
[SRWLockSharedTraits::GetInvalidValue](#getinvalidvalue) | Recupera um `SRWLockSharedTraits` objeto que é sempre inválido.
[SRWLockSharedTraits::Unlock](#unlock)                   | Libera o controle exclusivo `SRWLock` do objeto especificado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SRWLockSharedTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="srwlocksharedtraitsgetinvalidvalue"></a><a name="getinvalidvalue"></a>SRWLockSharedTraits::GetInvalidValue

Recupera um `SRWLockSharedTraits` objeto que é sempre inválido.

```cpp
inline static Type GetInvalidValue();
```

### <a name="return-value"></a>Valor retornado

Uma alça `SRWLockSharedTraits` para um objeto.

## <a name="srwlocksharedtraitsunlock"></a><a name="unlock"></a>SRWLockSharedTraits::Unlock

Libera o controle exclusivo `SRWLock` do objeto especificado.

```cpp
inline static void Unlock(
   _In_ Type srwlock
);
```

### <a name="parameters"></a>Parâmetros

*srwlock*<br/>
Uma alça `SRWLock` para um objeto.
