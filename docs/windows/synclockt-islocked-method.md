---
title: 'Método synclockt:: Islocked | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::IsLocked
dev_langs:
- C++
helpviewer_keywords:
- IsLocked method
ms.assetid: a81fea43-f99a-4708-812a-7fd6af500d3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ca4391539e4f6987431e8b9b036053db02218007
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42593049"
---
# <a name="synclocktislocked-method"></a>Método SyncLockT::IsLocked

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
bool IsLocked() const;
```

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o **SyncLockT** objeto estiver bloqueada; caso contrário, **false**.

## <a name="remarks"></a>Comentários

Indica se o atual **SyncLockT** objeto possui um recurso, ou seja, o **SyncLockT** objeto é *bloqueado*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::Details

## <a name="see-also"></a>Consulte também

[Classe SyncLockT](../windows/synclockt-class.md)