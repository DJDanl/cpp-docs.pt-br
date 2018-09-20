---
title: 'Método CriticalSection:: Lock | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection::Lock
dev_langs:
- C++
helpviewer_keywords:
- Lock method
ms.assetid: 37cb184c-e13c-49ef-b6a0-13908a956414
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f13af220107ba8d5bc5c26c65c2034f125a39454
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46382447"
---
# <a name="criticalsectionlock-method"></a>Método CriticalSection::Lock

Aguarda até que propriedade do objeto especificado de seção crítica. A função retorna quando o thread de chamada é concedido a propriedade.

## <a name="syntax"></a>Sintaxe

```cpp
SyncLock Lock();

   static SyncLock Lock(
   _In_ CRITICAL_SECTION* cs
);
```

### <a name="parameters"></a>Parâmetros

*cs*<br/>
Um objeto de seção crítica especificado pelo usuário.

## <a name="return-value"></a>Valor de retorno

Um objeto de bloqueio que pode ser usado para desbloquear a seção crítica atual.

## <a name="remarks"></a>Comentários

A primeira **bloqueio** function afeta o objeto atual de seção crítica. A segunda **bloqueio** function afeta uma seção crítica especificado pelo usuário.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe CriticalSection](../windows/criticalsection-class.md)