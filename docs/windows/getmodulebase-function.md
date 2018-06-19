---
title: Função GetModuleBase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::GetModuleBase
dev_langs:
- C++
ms.assetid: 123d3b14-2eaf-4e02-8dcd-b6567917c6a6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 25e4bb6db6114f7d64522dfe145d51ffaabd476a
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33874201"
---
# <a name="getmodulebase-function"></a>Função GetModuleBase
Recupera um [ModuleBase](../windows/modulebase-class.md) ponteiro que permite para incrementar e decrementar a contagem de referência de um [RuntimeClass](../windows/runtimeclass-class.md) objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
inline Details::ModuleBase* GetModuleBase() throw()  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `ModuleBase` objeto.  
  
## <a name="remarks"></a>Comentários  
 Essa função é usada internamente para incrementar e decrementar contagens de referência de objeto.  
  
 Você pode usar essa função para controlar as contagens de referência chamando [: Incrementobjectcount](../windows/modulebase-incrementobjectcount-method.md) e [: Decrementobjectcount](../windows/modulebase-decrementobjectcount-method.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)