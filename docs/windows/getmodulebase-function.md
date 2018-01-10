---
title: "Função GetModuleBase | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::GetModuleBase
dev_langs: C++
ms.assetid: 123d3b14-2eaf-4e02-8dcd-b6567917c6a6
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 19f575705b1f8680a68e9100f20be66ca22ec87a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)