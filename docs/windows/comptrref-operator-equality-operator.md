---
title: 'Operador comptrref:: Operator = = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::ComPtrRef::operator==
dev_langs:
- C++
ms.assetid: 95fcf781-b473-4317-88cd-e938778d3c3e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a36e3068bd5211f37e6fe1f0f2a82c923b4511a6
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39650697"
---
# <a name="comptrrefoperator-operator"></a>Operador ComPtrRef::operator==
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
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
  
### <a name="parameters"></a>Parâmetros  
 *a*  
 Uma referência a um **ComPtrRef** objeto.  
  
 *b*  
 Uma referência a outro **ComPtrRef** objeto ou um ponteiro para um tipo anônimo (`void*`).  
  
## <a name="return-value"></a>Valor de retorno  
 A primeira produz do operador **verdadeira** se objeto *um* é igual ao objeto *b*; caso contrário, **false**.  
  
 Os operadores de segundo e terceiro yield **verdadeira** se objeto *um* é igual a **nullptr**; caso contrário, **false**.  
  
 Os quarto e quintas operadores produzem **verdadeira** se objeto *um* é igual ao objeto *b*; caso contrário, **false**.  
  
## <a name="remarks"></a>Comentários  
 Indica se dois **ComPtrRef** objetos são iguais.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)   
 [Classe ComPtrRef](../windows/comptrref-class.md)