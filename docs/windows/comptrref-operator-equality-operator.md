---
title: 'Comptrref:: Operator = = operador | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: client/Microsoft::WRL::Details::ComPtrRef::operator==
dev_langs: C++
ms.assetid: 95fcf781-b473-4317-88cd-e938778d3c3e
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: cc55ab734229cc256f47185349ce79049d05723b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="comptrrefoperator-operator"></a>Operador ComPtrRef::operator==
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
bool operator==(  
   const Details::ComPtrRef<ComPtr<T>>& a,  
   const Details::ComPtrRef<ComPtr<U>>& b  
);  
  
bool operator==(  
   const Details::ComPtrRef<ComPtr<T>>& a,  
   decltype(__nullptr)  
);  
  
bool operator==(  
   decltype(__nullptr),  
   const Details::ComPtrRef<ComPtr<T>>& a  
);  
  
bool operator==(  
   const Details::ComPtrRef<ComPtr<T>>& a,  
   void* b  
);  
  
bool operator==(  
   void* b,  
   const Details::ComPtrRef<ComPtr<T>>& a  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `a`  
 Uma referência a um objeto ComPtrRef.  
  
 `b`  
 Uma referência a outro objeto ComPtrRef ou um ponteiro para um tipo anônimo (`void*`).  
  
## <a name="return-value"></a>Valor de retorno  
 O primeiro produz operador `true` se objeto `a` é igual ao objeto `b`; caso contrário, `false`.  
  
 Os operadores de segundo e terceiro yield `true` se objeto `a` é igual a `nullptr`; caso contrário, `false`.  
  
 Os quarto e quinto operadores geram `true` se objeto `a` é igual ao objeto `b`; caso contrário, `false`.  
  
## <a name="remarks"></a>Comentários  
 Indica se dois objetos ComPtrRef são iguais.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)   
 [Classe ComPtrRef](../windows/comptrref-class.md)