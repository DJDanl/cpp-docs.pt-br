---
title: Estrutura SRWLockSharedTraits | Microsoft Docs
ms.custom: ''
ms.date: 09/27/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits::GetInvalidValue
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits::Unlock
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits structure
- Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits::GetInvalidValue method
- Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits::Unlock method
ms.assetid: 709cb51e-d70c-40b6-bdb4-d8eacf3af495
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5cfebfd1a6ccb1f243b534c9693a4402de574f17
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48233664"
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
`Type` | Sinônimo de um ponteiro para o [SRWLOCK](../windows/srwlock-class.md) classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                                     | Descrição
-------------------------------------------------------- | -----------------------------------------------------------------
[Srwlocksharedtraits:: Getinvalidvalue](#getinvalidvalue) | Recupera um `SRWLockSharedTraits` objeto sempre é inválido.
[Srwlocksharedtraits:: Unlock](#unlock)                   | Libera o controle exclusivo do especificado `SRWLock` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SRWLockSharedTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="getinvalidvalue"></a>Srwlocksharedtraits:: Getinvalidvalue

Recupera um `SRWLockSharedTraits` objeto sempre é inválido.

```cpp
inline static Type GetInvalidValue();
```

### <a name="return-value"></a>Valor de retorno

Um identificador para um `SRWLockSharedTraits` objeto.

## <a name="unlock"></a>Srwlocksharedtraits:: Unlock

Libera o controle exclusivo do especificado `SRWLock` objeto.

```cpp
inline static void Unlock(
   _In_ Type srwlock
);
```

### <a name="parameters"></a>Parâmetros

*SRWLOCK*<br/>
Um identificador para um `SRWLock` objeto.
