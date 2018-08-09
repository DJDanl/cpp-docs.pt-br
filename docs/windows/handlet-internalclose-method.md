---
title: 'Método handlet:: Internalclose | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleT::InternalClose
dev_langs:
- C++
helpviewer_keywords:
- InternalClose method
ms.assetid: fe693c02-aa1f-4e00-8bdd-a0d7d736da0b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2190a8e85f81062cc1167aa844fccf4afc819bc9
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39648796"
---
# <a name="handletinternalclose-method"></a>Método HandleT::InternalClose
Fecha o atual **HandleT** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
virtual bool InternalClose();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 **Verdadeiro** se o atual **HandleT** fechado com êxito; caso contrário, **false**.  
  
## <a name="remarks"></a>Comentários  
 **InternalClose()** está **protegidos**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HandleT](../windows/handlet-class.md)