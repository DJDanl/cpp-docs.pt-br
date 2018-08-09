---
title: 'Método WeakReference:: Incrementstrongreference | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::WeakReference::IncrementStrongReference
dev_langs:
- C++
helpviewer_keywords:
- IncrementStrongReference method
ms.assetid: d0232426-a8cb-48b4-99d4-165de2d66cb9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f564f5d6197a640ef311cda8b2133ed583eec91e
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39642688"
---
# <a name="weakreferenceincrementstrongreference-method"></a>Método WeakReference::IncrementStrongReference
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
ULONG IncrementStrongReference();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 A contagem de referência forte incrementado.  
  
## <a name="remarks"></a>Comentários  
 Incrementa a contagem de referência forte do atual **WeakReference** objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe WeakReference](../windows/weakreference-class1.md)  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)