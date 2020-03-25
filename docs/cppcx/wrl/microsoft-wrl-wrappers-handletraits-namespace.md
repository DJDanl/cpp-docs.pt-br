---
title: Namespace Microsoft::WRL::Wrappers::HandleTraits
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits
helpviewer_keywords:
- HandleTraits namespace
ms.assetid: 2fb5c6d1-bfc2-4e09-91eb-31705064ffb3
ms.openlocfilehash: b19cc426fc7c1b4fc6ec0638730d59998f8c108a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213727"
---
# <a name="microsoftwrlwrappershandletraits-namespace"></a>Namespace Microsoft::WRL::Wrappers::HandleTraits

Descreve as características de tipos de recursos baseados em identificadores comuns.

## <a name="syntax"></a>Sintaxe

```cpp
namespace Microsoft::WRL::Wrappers::HandleTraits;
```

## <a name="members"></a>Membros

### <a name="structures"></a>Estruturas

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Estrutura CriticalSectionTraits](criticalsectiontraits-structure.md)|Especializa um objeto `CriticalSection` para dar suporte a uma seção crítica inválida ou a uma função para liberar uma seção crítica.|
|[Estrutura EventTraits](eventtraits-structure.md)|Define características de um identificador de classe de `Event`.|
|[Estrutura FileHandleTraits](filehandletraits-structure.md)|Define as características de um identificador de arquivo.|
|[Estrutura HANDLENullTraits](handlenulltraits-structure.md)|Define características comuns de um identificador não inicializado.|
|[Estrutura HANDLETraits](handletraits-structure.md)|Define características comuns de um identificador.|
|[Estrutura MutexTraits](mutextraits-structure.md)|Define características comuns da classe [mutex](mutex-class.md) .|
|[Estrutura SemaphoreTraits](semaphoretraits-structure.md)|Define características comuns de um objeto Semaphore.|
|[Estrutura SRWLockExclusiveTraits](srwlockexclusivetraits-structure.md)|Descreve as características comuns da classe `SRWLock` no modo de bloqueio exclusivo.|
|[Estrutura SRWLockSharedTraits](srwlocksharedtraits-structure.md)|Descreve as características comuns da classe `SRWLock` no modo de bloqueio compartilhado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Wrappers](microsoft-wrl-wrappers-namespace.md)
