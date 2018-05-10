---
title: Enumeração FactoryCacheFlags | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::FactoryCacheFlags
dev_langs:
- C++
ms.assetid: 6f54258f-0144-4264-9608-414e5905f6fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5ba3d9b75ff72399e1b9a027c937c24bba4a6c37
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
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
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)