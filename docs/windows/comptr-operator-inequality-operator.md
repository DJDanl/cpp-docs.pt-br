---
title: 'Comptr:: Operator! = operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::operator!=
dev_langs:
- C++
ms.assetid: 63647240-dec7-4eb9-9272-96c07d01493c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2450b5d473d1caadae171516cf337479bfd5d603
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33881875"
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
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft:: wrl](../windows/microsoft-wrl-namespace.md)   
 [Classe ComPtr](../windows/comptr-class.md)