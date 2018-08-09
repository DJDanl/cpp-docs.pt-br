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
ms.openlocfilehash: c872b311e6fa7aa16d7118a13bc69ef2c7ef9cc4
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39652643"
---
# <a name="weakreferenceweakreference-constructor"></a>Construtor WeakReference::WeakReference
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WeakReference();  
```  
  
## <a name="remarks"></a>Comentários  
 Inicializa uma nova instância dos [classe WeakReference](../windows/weakreference-class1.md).  
  
 O ponteiro de referência forte para o **WeakReference** objeto é inicializado como **nullptr**, e a contagem de referência forte é inicializada como 1.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)