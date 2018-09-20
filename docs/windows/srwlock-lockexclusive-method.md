---
title: 'Método SRWLOCK:: Lockexclusive | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::LockExclusive
dev_langs:
- C++
helpviewer_keywords:
- LockExclusive method
ms.assetid: f361b672-fca6-45cc-a9b4-310cc0d23fdc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b8aa6927acc165870ebb8f2a6128eaabbb1b144c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46413036"
---
# <a name="srwlocklockexclusive-method"></a>Método SRWLock::LockExclusive

Adquire uma **SRWLock** objeto no modo exclusivo.

## <a name="syntax"></a>Sintaxe

```cpp
SyncLockExclusive LockExclusive();

static SyncLockExclusive LockExclusive(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*lock*<br/>
Ponteiro para um **SRWLock** objeto.

## <a name="return-value"></a>Valor de retorno

Uma **SRWLock** objeto no modo exclusivo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe SRWLock](../windows/srwlock-class.md)