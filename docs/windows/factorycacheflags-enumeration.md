---
title: "Enumera&#231;&#227;o FactoryCacheFlags | Microsoft Docs"
ms.custom: ""
ms.date: "12/10/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "module/Microsoft::WRL::FactoryCacheFlags"
dev_langs: 
  - "C++"
ms.assetid: 6f54258f-0144-4264-9608-414e5905f6fb
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Enumera&#231;&#227;o FactoryCacheFlags
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Determina se os objetos de fábrica são armazenados no cache.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
enum FactoryCacheFlags;  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, a política de cache de fábrica é especificada como o [ModuleType](../Topic/ModuleType%20Enumeration.md) parâmetro de modelo ao criar um [módulo](../windows/module-class.md) objeto. Para substituir essa política, especifique um `FactoryCacheFlags` valor quando você cria um objeto de fábrica.  
  
|||  
|-|-|  
|`FactoryCacheDefault`|A política de cache do `Module` objeto é usado.|  
|`FactoryCacheEnabled`|Permite o cache de fábrica independentemente do `ModuleType` parâmetro de modelo que é usado para criar um `Module` objeto.|  
|`FactoryCacheDisabled`|Desabilita o cache de fábrica independentemente do `ModuleType` parâmetro de modelo que é usado para criar um `Module` objeto.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft:: wrl](../windows/microsoft-wrl-namespace.md)