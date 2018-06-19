---
title: 'Método: Decrementstrongreference | Microsoft Docs'
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
ms.openlocfilehash: 7d5605670e05f91f9f1293c8bff0f4d74e458d25
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33890330"
---
# <a name="weakreferencedecrementstrongreference-method"></a>Método WeakReference::DecrementStrongReference
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
ULONG DecrementStrongReference();  
```  
  
## <a name="remarks"></a>Comentários  
 Diminui a forte contagem de referência do objeto WeakReference atual.  
  
 Quando a contagem de referência forte se torna zero, a referência forte é definida como `nullptr`.  
  
## <a name="return-value"></a>Valor de retorno  
 A contagem de referência forte diminuído.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
[Classe WeakReference](../windows/weakreference-class1.md)  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)