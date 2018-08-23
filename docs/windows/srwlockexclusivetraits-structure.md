---
title: Estrutura SRWLockExclusiveTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockExclusiveTraits
dev_langs:
- C++
helpviewer_keywords:
- SRWLockExclusiveTraits structure
ms.assetid: 38a996ef-c2d7-4886-b413-a426ecee8f05
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 542ad92aa636c934e3250817931dd7f31d1fe85b
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42601597"
---
# <a name="srwlockexclusivetraits-structure"></a>Estrutura SRWLockExclusiveTraits

Descreve características comuns do `SRWLock` classe no modo de bloqueio exclusivo.

## <a name="syntax"></a>Sintaxe

```cpp
struct SRWLockExclusiveTraits;
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`Type`|Sinônimo de um ponteiro para o [SRWLOCK](../windows/srwlock-class.md) classe.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Método SRWLockExclusiveTraits::GetInvalidValue](../windows/srwlockexclusivetraits-getinvalidvalue-method.md)|Recupera uma **SRWLockExclusiveTraits** objeto sempre é inválido.|
|[Método SRWLockExclusiveTraits::Unlock](../windows/srwlockexclusivetraits-unlock-method.md)|Libera o controle exclusivo do especificado `SRWLock` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SRWLockExclusiveTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers::HandleTraits](../windows/microsoft-wrl-wrappers-handletraits-namespace.md)