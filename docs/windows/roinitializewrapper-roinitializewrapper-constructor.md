---
title: 'Construtor roinitializewrapper:: Roinitializewrapper | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::RoInitializeWrapper::RoInitializeWrapper
dev_langs:
- C++
ms.assetid: c6f7fb07-14af-4574-9135-cea164607f30
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 193f0d16b03991e24cb16a90b3310512f6e86054
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39604382"
---
# <a name="roinitializewrapperroinitializewrapper-constructor"></a>Construtor RoInitializeWrapper::RoInitializeWrapper
Inicializa uma nova instância dos **RoInitializeWrapper** classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
RoInitializeWrapper(   RO_INIT_TYPE flags)  
```  
  
### <a name="parameters"></a>Parâmetros  
 *flags*  
 Uma das enumerações RO_INIT_TYPE, que especifica o suporte fornecido pelo tempo de execução do Windows.  
  
## <a name="remarks"></a>Comentários  
 O **RoInitializeWrapper** classe invoca `Windows::Foundation::Initialize(flags)`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HandleT](../windows/handlet-class.md)