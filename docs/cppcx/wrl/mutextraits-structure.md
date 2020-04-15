---
title: Estrutura MutexTraits
ms.date: 09/27/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::MutexTraits
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::MutexTraits::Unlock
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HandleTraits::MutexTraits structure
- Microsoft::WRL::Wrappers::HandleTraits::MutexTraits::Unlock method
ms.assetid: 6582df80-b9ba-4892-948f-d572a3b23d54
ms.openlocfilehash: 6d4ba08ab1884e8584b0e98e931d2d63cdac5aec
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371246"
---
# <a name="mutextraits-structure"></a>Estrutura MutexTraits

Define características comuns da classe [Mutex.](mutex-class.md)

## <a name="syntax"></a>Sintaxe

```cpp
struct MutexTraits : HANDLENullTraits;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

Nome                           | Descrição
------------------------------ | ------------------------------------------------
[MutexTraits::Unlock](#unlock) | Libera o controle exclusivo de um recurso compartilhado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HANDLENullTraits`

`MutexTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="mutextraitsunlock-method"></a><a name="unlock"></a>MutexTraits::Método de desbloqueio

Libera o controle exclusivo de um recurso compartilhado.

```cpp
inline static void Unlock(
   _In_ Type h
);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
Manuseie um objeto mutex.
