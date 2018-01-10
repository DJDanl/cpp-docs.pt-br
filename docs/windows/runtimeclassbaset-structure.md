---
title: Estrutura RuntimeClassBaseT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Details::RuntimeClassBaseT
dev_langs: C++
ms.assetid: a62775fb-3359-4f45-9ff1-c07fa8da464b
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8798372b96074cb8424b4e747b188abcaf826849
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="runtimeclassbaset-structure"></a>Estrutura RuntimeClassBaseT
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   unsigned int RuntimeClassTypeT  
>  
friend struct Details::RuntimeClassBaseT;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `RuntimeClassTypeT`  
 Um campo de sinalizadores que especifica um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) enumeradores.  
  
## <a name="remarks"></a>Comentários  
 Fornece métodos auxiliares para `QueryInterface` operações e ao obter IDs de interface.  
  
## <a name="members"></a>Membros  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `RuntimeClassBaseT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Referência (biblioteca de tempo de execução do Windows)](http://msdn.microsoft.com/en-us/00000000-0000-0000-0000-000000000000)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)