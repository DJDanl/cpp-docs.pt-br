---
title: Estrutura RuntimeClassBaseT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::RuntimeClassBaseT
dev_langs:
- C++
ms.assetid: a62775fb-3359-4f45-9ff1-c07fa8da464b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4d7113e1c8ca29cf8b6c27efd543dbc3de7810b3
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40011124"
---
# <a name="runtimeclassbaset-structure"></a>Estrutura RuntimeClassBaseT
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <  
   unsigned int RuntimeClassTypeT  
>  
friend struct Details::RuntimeClassBaseT;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *RuntimeClassTypeT*  
 Um campo de sinalizadores que especifica um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) enumeradores.  
  
## <a name="remarks"></a>Comentários  
 Fornece métodos auxiliares para `QueryInterface` operações e ao obter IDs de interface.  
  
## <a name="members"></a>Membros  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `RuntimeClassBaseT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Referência (biblioteca de tempo de execução do Windows)](http://msdn.microsoft.com/00000000-0000-0000-0000-000000000000)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)