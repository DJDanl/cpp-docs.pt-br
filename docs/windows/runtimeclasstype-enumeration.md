---
title: Enumeração RuntimeClassType | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClassType
dev_langs:
- C++
helpviewer_keywords:
- RuntimeClassType enumeration
ms.assetid: d380712d-672e-4ea9-b7c5-cf9fa7dbb770
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 43ab0a738af4c6bc92d42c0884827b574946d2ea
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33892397"
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
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)