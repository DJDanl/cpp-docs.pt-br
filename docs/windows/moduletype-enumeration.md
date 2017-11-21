---
title: "Enumeração ModuleType | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::ModuleType
dev_langs: C++
helpviewer_keywords: ModuleType enumeration
ms.assetid: 61a763af-a5a4-451d-8b40-815af507fcde
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: a516795124ec3de6bb90102b3ea200d3365f33c4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)