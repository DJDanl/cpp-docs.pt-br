---
title: "Método: Incrementstrongreference | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Details::WeakReference::IncrementStrongReference
dev_langs: C++
helpviewer_keywords: IncrementStrongReference method
ms.assetid: d0232426-a8cb-48b4-99d4-165de2d66cb9
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 355f1c07d8185c83fd92fa76810ef57547ebd599
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="weakreferenceincrementstrongreference-method"></a>Método WeakReference::IncrementStrongReference
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
ULONG IncrementStrongReference();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 A contagem de referência forte incrementado.  
  
## <a name="remarks"></a>Comentários  
 Incrementa a contagem de referência forte do objeto WeakReference atual.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
[Classe WeakReference](../windows/weakreference-class1.md)  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)