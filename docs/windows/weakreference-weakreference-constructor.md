---
title: 'Construtor WeakReference:: WeakReference | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::WeakReference::WeakReference
dev_langs:
- C++
helpviewer_keywords:
- WeakReference, constructor
ms.assetid: 4959a9d7-78ea-423d-a46b-50d010d29fff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8e60b23a0c63ce1415765dd1f94863540849f975
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33891055"
---
# <a name="weakreferenceweakreference-constructor"></a>Construtor WeakReference::WeakReference
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WeakReference();  
```  
  
## <a name="remarks"></a>Comentários  
 Inicializa uma nova instância do [classe WeakReference](../windows/weakreference-class1.md).  
  
 O ponteiro de referência forte para o objeto WeakReference foi inicializado para `nullptr`, e a contagem de referência forte é inicializada como 1.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
    
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)