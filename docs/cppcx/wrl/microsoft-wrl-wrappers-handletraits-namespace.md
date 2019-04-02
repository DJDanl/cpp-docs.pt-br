---
title: Namespace Microsoft::WRL::Wrappers::HandleTraits
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits
helpviewer_keywords:
- HandleTraits namespace
ms.assetid: 2fb5c6d1-bfc2-4e09-91eb-31705064ffb3
ms.openlocfilehash: 55e1dfea2d4075a5a37b9654a70e9ce74383ea53
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783909"
---
# <a name="microsoftwrlwrappershandletraits-namespace"></a>Namespace Microsoft::WRL::Wrappers::HandleTraits

Descreve as características dos tipos comuns de recursos com base no identificador.

## <a name="syntax"></a>Sintaxe

```cpp
namespace Microsoft::WRL::Wrappers::HandleTraits;
```

## <a name="members"></a>Membros

### <a name="structures"></a>Estruturas

|Nome|Descrição|
|----------|-----------------|
|[Estrutura CriticalSectionTraits](criticalsectiontraits-structure.md)|É especialista um `CriticalSection` objeto para dar suporte a uma seção crítica inválida ou uma função para liberar uma seção crítica.|
|[Estrutura EventTraits](eventtraits-structure.md)|Define as características de um `Event` identificador de classe.|
|[Estrutura FileHandleTraits](filehandletraits-structure.md)|Define as características de um identificador de arquivo.|
|[Estrutura HANDLENullTraits](handlenulltraits-structure.md)|Define as características comuns de um identificador não inicializado.|
|[Estrutura HANDLETraits](handletraits-structure.md)|Define as características comuns de um identificador.|
|[Estrutura MutexTraits](mutextraits-structure.md)|Define as características comuns do [Mutex](mutex-class.md) classe.|
|[Estrutura SemaphoreTraits](semaphoretraits-structure.md)|Define as características comuns de um objeto de sinal.|
|[Estrutura SRWLockExclusiveTraits](srwlockexclusivetraits-structure.md)|Descreve características comuns do `SRWLock` classe no modo de bloqueio exclusivo.|
|[Estrutura SRWLockSharedTraits](srwlocksharedtraits-structure.md)|Descreve características comuns do `SRWLock` classe no modo de bloqueio compartilhado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers](microsoft-wrl-wrappers-namespace.md)