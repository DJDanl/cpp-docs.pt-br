---
title: Enumeração ModuleType | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::ModuleType
dev_langs:
- C++
helpviewer_keywords:
- ModuleType enumeration
ms.assetid: 61a763af-a5a4-451d-8b40-815af507fcde
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d36355c9f64f9f5c827ef8c4d5b3cb6a77d17b65
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="moduletype-enumeration"></a>Enumeração ModuleType
Especifica se um módulo deve dar suporte a um servidor em processo ou fora de processo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
enum ModuleType;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`InProc`|Um servidor em processo.|  
|`OutOfProc`|Um servidor fora do processo.|  
|`DisableCaching`|Desative o mecanismo de cache no módulo.|  
|`InProcDisableCaching`|Combinação de `InProc` e `DisableCaching`.|  
|`OutOfProcDisableCaching`|Combinação de `OutOfProc` e `DisableCaching`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)