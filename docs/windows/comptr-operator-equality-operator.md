---
title: 'Comptr:: Operator = = operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::operator==
dev_langs:
- C++
ms.assetid: 6a26e936-29d4-4b7d-b44a-7c575ad07509
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e68566b5f8fa519a3cfcd5a406cc812edfaf8480
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39648588"
---
# <a name="comptroperator-operator"></a>Operador ComPtr::operator==
Indica se dois **ComPtr** objetos são iguais.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
bool operator==(  
   const ComPtr<T>& a,  
   const ComPtr<U>& b  
);  
  
bool operator==(  
   const ComPtr<T>& a,  
   decltype(__nullptr)  
);  
  
bool operator==(  
   decltype(__nullptr),  
   const ComPtr<T>& a  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *a*  
 Uma referência a um **ComPtr** objeto.  
  
 *b*  
 Uma referência a outro **ComPtr** objeto.  
  
## <a name="return-value"></a>Valor de retorno  
 A primeira produz do operador **verdadeira** se objeto *um* é igual ao objeto *b*; caso contrário, **false**.  
  
 Os operadores de segundo e terceiro yield **verdadeira** se objeto *um* é igual a **nullptr**; caso contrário, **false**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft:: wrl](../windows/microsoft-wrl-namespace.md)   
 [Classe ComPtr](../windows/comptr-class.md)