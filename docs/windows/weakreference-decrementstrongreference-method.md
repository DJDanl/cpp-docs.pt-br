---
title: "Método: Decrementstrongreference | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Details::WeakReference::DecrementStrongReference
dev_langs: C++
helpviewer_keywords: DecrementStrongReference method
ms.assetid: 97d70d9f-41b8-4f8d-a6fa-4137cc4f9029
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: bda6de03ce17db7ebac751865686c3e74a26d0d8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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