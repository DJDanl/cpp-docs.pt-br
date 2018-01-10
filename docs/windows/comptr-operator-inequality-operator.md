---
title: 'Comptr:: Operator! = operador | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: client/Microsoft::WRL::ComPtr::operator!=
dev_langs: C++
ms.assetid: 63647240-dec7-4eb9-9272-96c07d01493c
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e2610061fcb7266ae5457935d680f7bce82797c6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="comptroperator-operator"></a>Operador ComPtr::operator!=
Indica se dois objetos ComPtr não são iguais.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
bool operator!=(  
   const ComPtr<T>& a,  
   const ComPtr<U>& b  
);  
  
bool operator!=(  
   const ComPtr<T>& a,  
   decltype(__nullptr)  
);  
  
bool operator!=(  
   decltype(__nullptr),  
   const ComPtr<T>& a  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `a`  
 Uma referência a um objeto ComPtr.  
  
 `b`  
 Uma referência a outro objeto ComPtr.  
  
## <a name="return-value"></a>Valor de retorno  
 O primeiro produz operador `true` se objeto `a` não é igual ao objeto `b`; caso contrário, `false`.  
  
 Os operadores de segundo e terceiro yield `true` se objeto `a` não é igual a `nullptr`; caso contrário, `false`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft:: wrl](../windows/microsoft-wrl-namespace.md)   
 [Classe ComPtr](../windows/comptr-class.md)