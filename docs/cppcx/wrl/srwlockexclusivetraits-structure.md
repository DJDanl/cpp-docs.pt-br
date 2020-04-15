---
title: Estrutura SRWLockExclusiveTraits
ms.date: 09/27/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockExclusiveTraits
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockExclusiveTraits::GetInvalidValue
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockExclusiveTraits::Unlock
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HandleTraits::SRWLockExclusiveTraits structure
- Microsoft::WRL::Wrappers::HandleTraits::SRWLockExclusiveTraits::GetInvalidValue method
- Microsoft::WRL::Wrappers::HandleTraits::SRWLockExclusiveTraits::Unlock method
ms.assetid: 38a996ef-c2d7-4886-b413-a426ecee8f05
ms.openlocfilehash: eb7b30915d6061e8470601df33fecec310d1bbca
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374303"
---
# <a name="srwlockexclusivetraits-structure"></a>Estrutura SRWLockExclusiveTraits

Descreve características comuns `SRWLock` da classe no modo de bloqueio exclusivo.

## <a name="syntax"></a>Sintaxe

```cpp
struct SRWLockExclusiveTraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | --------------------------------------------------------------------------
`Type` | Sinônimo de ponteiro para a classe [SRWLOCK.](srwlock-class.md)

### <a name="public-methods"></a>Métodos públicos

Nome                                                        | Descrição
----------------------------------------------------------- | --------------------------------------------------------------------
[SRWLockTraitsexclusive::GetInvalidValue](#getinvalidvalue) | Recupera um `SRWLockExclusiveTraits` objeto que é sempre inválido.
[SRWLockTraitsexclusive::Unlock](#unlock)                   | Libera o controle exclusivo `SRWLock` do objeto especificado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SRWLockExclusiveTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="srwlockexclusivetraitsgetinvalidvalue"></a><a name="getinvalidvalue"></a>SRWLockTraitsexclusive::GetInvalidValue

Recupera um `SRWLockExclusiveTraits` objeto que é sempre inválido.

```cpp
inline static Type GetInvalidValue();
```

### <a name="return-value"></a>Valor retornado

Um objeto `SRWLockExclusiveTraits` vazio.

## <a name="srwlockexclusivetraitsunlock"></a><a name="unlock"></a>SRWLockTraitsexclusive::Unlock

Libera o controle exclusivo `SRWLock` do objeto especificado.

```cpp
inline static void Unlock(
   _In_ Type srwlock
);
```

### <a name="parameters"></a>Parâmetros

*srwlock*<br/>
Manuseie um `SRWLock` objeto.
