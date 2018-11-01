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
ms.openlocfilehash: 84bfac08a944928ff91a7734cdbaccbe4d351e16
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50650730"
---
# <a name="mutextraits-structure"></a>Estrutura MutexTraits

Define as características comuns do [Mutex](../windows/mutex-class1.md) classe.

## <a name="syntax"></a>Sintaxe

```cpp
struct MutexTraits : HANDLENullTraits;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

Nome                           | Descrição
------------------------------ | ------------------------------------------------
[Mutextraits:: Unlock](#unlock) | Libera o controle exclusivo de um recurso compartilhado.

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
