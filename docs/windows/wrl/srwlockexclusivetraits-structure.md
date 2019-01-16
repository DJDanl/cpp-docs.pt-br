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
ms.openlocfilehash: 25249b8823b8c182133e85aa4cd07d38f5874cf2
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335642"
---
# <a name="srwlockexclusivetraits-structure"></a>Estrutura SRWLockExclusiveTraits

Descreve características comuns do `SRWLock` classe no modo de bloqueio exclusivo.

## <a name="syntax"></a>Sintaxe

```cpp
struct SRWLockExclusiveTraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome   | Descrição
------ | --------------------------------------------------------------------------
`Type` | Sinônimo de um ponteiro para o [SRWLOCK](srwlock-class.md) classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                                        | Descrição
----------------------------------------------------------- | --------------------------------------------------------------------
[SRWLockExclusiveTraits::GetInvalidValue](#getinvalidvalue) | Recupera um `SRWLockExclusiveTraits` objeto sempre é inválido.
[SRWLockExclusiveTraits::Unlock](#unlock)                   | Libera o controle exclusivo do especificado `SRWLock` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SRWLockExclusiveTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="getinvalidvalue"></a>SRWLockExclusiveTraits::GetInvalidValue

Recupera um `SRWLockExclusiveTraits` objeto sempre é inválido.

```cpp
inline static Type GetInvalidValue();
```

### <a name="return-value"></a>Valor de retorno

Um objeto `SRWLockExclusiveTraits` vazio.

## <a name="unlock"></a>SRWLockExclusiveTraits::Unlock

Libera o controle exclusivo do especificado `SRWLock` objeto.

```cpp
inline static void Unlock(
   _In_ Type srwlock
);
```

### <a name="parameters"></a>Parâmetros

*srwlock*<br/>
Identificador para um `SRWLock` objeto.
