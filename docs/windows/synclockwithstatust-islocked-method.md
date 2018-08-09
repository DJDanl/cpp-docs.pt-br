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
ms.openlocfilehash: 80c744431fe7df32be705fcf91eef0a8691b8fa4
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40015792"
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