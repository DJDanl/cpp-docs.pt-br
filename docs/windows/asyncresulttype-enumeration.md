---
title: "Enumeração AsyncResultType | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: async/Microsoft::WRL::AsyncResultType
dev_langs: C++
helpviewer_keywords: AsyncResultType enumeration
ms.assetid: 4195d234-3f3f-4363-9118-6ad2a7551cf2
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b654a4f27ca78cda680a7ceb69f0c6e2ea0db9a4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="asyncresulttype-enumeration"></a>Enumeração AsyncResultType
Especifica o tipo de resultado retornado pelo método GetResults().  
  
## <a name="syntax"></a>Sintaxe  
  
```  
enum AsyncResultType;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="values"></a>Valores  
  
|Nome|Descrição|  
|----------|-----------------|  
|`MultipleResults`|Um conjunto de vários resultados, que são apresentadas progressivamente entre o estado inicial e antes de Close () é chamado.|  
|`SingleResult`|Um único resultado, que é apresentado após o evento de conclusão.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)