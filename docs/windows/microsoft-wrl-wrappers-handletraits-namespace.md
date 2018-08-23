---
title: Namespace Microsoft::WRL::wrappers::HandleTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits
dev_langs:
- C++
helpviewer_keywords:
- HandleTraits namespace
ms.assetid: 2fb5c6d1-bfc2-4e09-91eb-31705064ffb3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 683759c3bf0b2152ee6fadbb638cd2398daecccd
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42586123"
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
|[Estrutura CriticalSectionTraits](../windows/criticalsectiontraits-structure.md)|É especialista um `CriticalSection` objeto para dar suporte a uma seção crítica inválida ou uma função para liberar uma seção crítica.|
|[Estrutura EventTraits](../windows/eventtraits-structure.md)|Define as características de um `Event` identificador de classe.|
|[Estrutura FileHandleTraits](../windows/filehandletraits-structure.md)|Define as características de um identificador de arquivo.|
|[Estrutura HANDLENullTraits](../windows/handlenulltraits-structure.md)|Define as características comuns de um identificador não inicializado.|
|[Estrutura HANDLETraits](../windows/handletraits-structure.md)|Define as características comuns de um identificador.|
|[Estrutura MutexTraits](../windows/mutextraits-structure.md)|Define as características comuns do [Mutex](../windows/mutex-class1.md) classe.|
|[Estrutura SemaphoreTraits](../windows/semaphoretraits-structure.md)|Define as características comuns de um objeto de sinal.|
|[Estrutura SRWLockExclusiveTraits](../windows/srwlockexclusivetraits-structure.md)|Descreve características comuns do `SRWLock` classe no modo de bloqueio exclusivo.|
|[Estrutura SRWLockSharedTraits](../windows/srwlocksharedtraits-structure.md)|Descreve características comuns do `SRWLock` classe no modo de bloqueio compartilhado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)