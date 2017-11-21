---
title: "Método Eventtargetarray: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: event/Microsoft::WRL::Details::EventTargetArray::End
dev_langs: C++
helpviewer_keywords: End method
ms.assetid: 20c491b8-f355-4d8f-ad14-8f46121d9af6
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 95c73ed0784b09f56efe817691ba696736b80f20
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="eventtargetarrayend-method"></a>Método EventTargetArray::End
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
ComPtr<IUnknown>* End();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O endereço do último elemento da matriz interna de manipuladores de eventos.  
  
## <a name="remarks"></a>Comentários  
 Obtém o endereço do último elemento da matriz interna de manipuladores de eventos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe EventTargetArray](../windows/eventtargetarray-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)