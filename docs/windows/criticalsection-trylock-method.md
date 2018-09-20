---
title: 'Método CriticalSection:: Trylock | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection::TryLock
dev_langs:
- C++
helpviewer_keywords:
- TryLock method
ms.assetid: 504bb87c-2cd0-4f54-b458-b3efb9789053
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 44b4e251898ef6386d0642582af2c00881f7a181
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46408577"
---
# <a name="criticalsectiontrylock-method"></a>Método CriticalSection::TryLock

Tenta inserir uma seção crítica sem bloqueio. Se a chamada for bem-sucedida, o thread de chamada se apropria de seção crítica.

## <a name="syntax"></a>Sintaxe

```cpp
SyncLock TryLock();

static SyncLock TryLock(
   _In_ CRITICAL_SECTION* cs
);
```

### <a name="parameters"></a>Parâmetros

*cs*<br/>
Um objeto de seção crítica especificado pelo usuário.

## <a name="return-value"></a>Valor de retorno

Um valor diferente de zero se a seção crítica for inserida com êxito ou o thread atual já possui a seção crítica. Zero se outro thread já possui a seção crítica.

## <a name="remarks"></a>Comentários

A primeira **TryLock** function afeta o objeto atual de seção crítica. A segunda **TryLock** function afeta uma seção crítica especificado pelo usuário.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe CriticalSection](../windows/criticalsection-class.md)