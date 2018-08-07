---
title: Macro InspectableClass | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::InspectableClass
dev_langs:
- C++
ms.assetid: ff390b26-58cc-424f-87ac-1fe3cc692b59
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a02e20f2b87afc312c24683417f808d636c2757f
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39608950"
---
# <a name="inspectableclass-macro"></a>Macro InspectableClass
Define o nível de confiança e o nome de classe do tempo de execução.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
InspectableClass(  
   runtimeClassName,   
   trustLevel)  
```  
  
### <a name="parameters"></a>Parâmetros  
 *runtimeClassName*  
 O nome textual completo da classe de tempo de execução.  
  
 *trustLevel*  
 Um dos [TrustLevel](http://msdn.microsoft.com/library/br224625.aspx) valores enumerados.  
  
## <a name="remarks"></a>Comentários  
 O **InspectableClass** macro pode ser usada somente com tipos de tempo de execução do Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe RuntimeClass](../windows/runtimeclass-class.md)