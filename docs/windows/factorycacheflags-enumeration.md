---
title: "Enumeração FactoryCacheFlags | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::FactoryCacheFlags
dev_langs: C++
ms.assetid: 6f54258f-0144-4264-9608-414e5905f6fb
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 41b31ccede1cca717418c9f489ab7de67d313319
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="factorycacheflags-enumeration"></a>Enumeração FactoryCacheFlags
Determina se os objetos de fábrica são armazenados em cache.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
enum FactoryCacheFlags;  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, a fábrica de política de cache é especificada como o [ModuleType](../windows/moduletype-enumeration.md) parâmetro de modelo ao criar um [módulo](../windows/module-class.md) objeto. Para substituir essa política, especifique um `FactoryCacheFlags` valor quando você cria um objeto de fábrica.  
  
|||  
|-|-|  
|`FactoryCacheDefault`|A política de cache do `Module` objeto é usado.|  
|`FactoryCacheEnabled`|Habilita o cache de fábrica independentemente do `ModuleType` parâmetro de modelo que é usado para criar um `Module` objeto.|  
|`FactoryCacheDisabled`|Desabilita o cache de fábrica independentemente do `ModuleType` parâmetro de modelo que é usado para criar um `Module` objeto.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)