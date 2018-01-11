---
title: "Enumeração RuntimeClassType | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::RuntimeClassType
dev_langs: C++
helpviewer_keywords: RuntimeClassType enumeration
ms.assetid: d380712d-672e-4ea9-b7c5-cf9fa7dbb770
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 26016e8c95807af76484504c491ca1e6e08f8f96
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="runtimeclasstype-enumeration"></a>Enumeração RuntimeClassType
Especifica o tipo de [RuntimeClass](../windows/runtimeclass-class.md) instância com suporte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
enum RuntimeClassType;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`ClassicCom`|Uma classe de tempo de execução COM clássico.|  
|`Delegate`|Equivalente a **ClassicCom**.|  
|`InhibitFtmBase`|Desabilita `FtmBase` suporte ao `__WRL_CONFIGURATION_LEGACY__` não está definido.|  
|`InhibitWeakReference`|Desabilita o suporte de referência fraca.|  
|`WinRt`|Uma classe de tempo de execução do Windows.|  
|`WinRtClassicComMix`|Uma combinação de `WinRt` e `ClassicCom`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)