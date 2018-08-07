---
title: 'RoInitializeWrapper:: ~ RoInitializeWrapper destruidor | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper::~RoInitializeWrapper
dev_langs:
- C++
ms.assetid: afef4c1f-ffde-4cd2-8654-8de4182eb5f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1c6eaeb044cf3e169bf5927a2fec948cc8d4294c
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39606270"
---
# <a name="roinitializewrapperroinitializewrapper-destructor"></a>Destruidor RoInitializeWrapper::~RoInitializeWrapper
Encerra o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
~RoInitializeWrapper()  
```  
  
## <a name="remarks"></a>Comentários  
 O **RoInitializeWrapper** classe invoca `Windows::Foundation::Uninitialize()`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HandleT](../windows/handlet-class.md)