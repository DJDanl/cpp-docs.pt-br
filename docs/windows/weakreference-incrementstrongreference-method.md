---
title: "M&#233;todo WeakReference::IncrementStrongReference | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "implements/Microsoft::WRL::Details::WeakReference::IncrementStrongReference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método IncrementStrongReference"
ms.assetid: d0232426-a8cb-48b4-99d4-165de2d66cb9
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo WeakReference::IncrementStrongReference
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura do WRL e não se destina a ser usada diretamente no seu código.  
  
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