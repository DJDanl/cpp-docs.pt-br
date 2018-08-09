---
title: 'Método WeakReference:: Decrementstrongreference | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::WeakReference::DecrementStrongReference
dev_langs:
- C++
helpviewer_keywords:
- DecrementStrongReference method
ms.assetid: 97d70d9f-41b8-4f8d-a6fa-4137cc4f9029
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5c7e2161c5451fe82e12918f00e8cb2cde37d336
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39642309"
---
# <a name="weakreferencedecrementstrongreference-method"></a>Método WeakReference::DecrementStrongReference
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
ULONG DecrementStrongReference();  
```  
  
## <a name="remarks"></a>Comentários  
 Diminui a contagem de referência forte do atual **WeakReference** objeto.  
  
 Quando a contagem de referência forte se torna zero, a referência forte é definida como **nullptr**.  
  
## <a name="return-value"></a>Valor de retorno  
 A contagem de referência forte decrementado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe WeakReference](../windows/weakreference-class1.md)  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)