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
ms.openlocfilehash: 04f09f98148a54ac87add3d52bcba1cffa0c1c14
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40016415"
---
# <a name="weakreferenceweakreference-constructor"></a>Construtor WeakReference::WeakReference
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
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