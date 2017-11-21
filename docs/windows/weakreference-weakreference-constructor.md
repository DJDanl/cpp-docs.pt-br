---
title: 'Construtor WeakReference:: WeakReference | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Details::WeakReference::WeakReference
dev_langs: C++
helpviewer_keywords: WeakReference, constructor
ms.assetid: 4959a9d7-78ea-423d-a46b-50d010d29fff
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 3eedb6f083bb9c936eaa34bfcde0463db494c60f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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