---
title: 'Método synclockwithstatust:: Islocked | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::IsLocked
dev_langs:
- C++
helpviewer_keywords:
- IsLocked method
ms.assetid: e1b75b7b-c145-471a-aa5d-71abf31f5990
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d70a2c316f9e7994292f3dc29cef5bce993778ad
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42595057"
---
# <a name="synclockwithstatustislocked-method"></a>Método SyncLockWithStatusT::IsLocked

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
bool IsLocked() const;
```

## <a name="remarks"></a>Comentários

Indica se o atual **SyncLockWithStatusT** objeto possui um recurso, ou seja, o **SyncLockWithStatusT** objeto é *bloqueado*.

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o **SyncLockWithStatusT** objeto estiver bloqueada; caso contrário, **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::Details

## <a name="see-also"></a>Consulte também

[Classe SyncLockWithStatusT](../windows/synclockwithstatust-class.md)