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
ms.openlocfilehash: 9bc4071e5699610a664cbf01ca3e7d36d7effc5e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62379175"
---
# <a name="mutextraits-structure"></a>Estrutura MutexTraits

Define as características comuns do [Mutex](mutex-class.md) classe.

## <a name="syntax"></a>Sintaxe

```cpp
struct MutexTraits : HANDLENullTraits;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

Nome                           | Descrição
------------------------------ | ------------------------------------------------
[MutexTraits::Unlock](#unlock) | Libera o controle exclusivo de um recurso compartilhado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HANDLENullTraits`

`MutexTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="unlock"></a>Método mutextraits:: Unlock

Libera o controle exclusivo de um recurso compartilhado.

```cpp
inline static void Unlock(
   _In_ Type h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
Identificador para um objeto mutex.
