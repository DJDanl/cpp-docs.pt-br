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
ms.openlocfilehash: af567fd333854519df4543ad24084e52cda4d96e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62383271"
---
# <a name="srwlocksharedtraits-structure"></a>Estrutura SRWLockSharedTraits

Descreve características comuns do `SRWLock` classe no modo de bloqueio compartilhado.

## <a name="syntax"></a>Sintaxe

```cpp
struct SRWLockSharedTraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | --------------------------------------------------------------------------
`Type` | Sinônimo de um ponteiro para o [SRWLOCK](srwlock-class.md) classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                                     | Descrição
-------------------------------------------------------- | -----------------------------------------------------------------
[SRWLockSharedTraits::GetInvalidValue](#getinvalidvalue) | Recupera um `SRWLockSharedTraits` objeto sempre é inválido.
[SRWLockSharedTraits::Unlock](#unlock)                   | Libera o controle exclusivo do especificado `SRWLock` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SRWLockSharedTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="getinvalidvalue"></a>SRWLockSharedTraits::GetInvalidValue

Recupera um `SRWLockSharedTraits` objeto sempre é inválido.

```cpp
inline static Type GetInvalidValue();
```

### <a name="return-value"></a>Valor de retorno

Um identificador para um `SRWLockSharedTraits` objeto.

## <a name="unlock"></a>SRWLockSharedTraits::Unlock

Libera o controle exclusivo do especificado `SRWLock` objeto.

```cpp
inline static void Unlock(
   _In_ Type srwlock
);
```

### <a name="parameters"></a>Parâmetros

*srwlock*<br/>
Um identificador para um `SRWLock` objeto.
