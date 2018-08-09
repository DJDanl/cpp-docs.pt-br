---
title: 'Construtor CriticalSection:: CriticalSection | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection::CriticalSection
dev_langs:
- C++
helpviewer_keywords:
- CriticalSection, constructor
ms.assetid: 930b89be-4d74-46bd-8879-5dd4d15bcbd0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f87f95a0683f6b4440d2be8b770902a7e4ecde59
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39644288"
---
# <a name="criticalsectioncriticalsection-constructor"></a>Construtor CriticalSection::CriticalSection
Inicializa um objeto de sincronização que é semelhante a um objeto de mutex, mas pode ser usado por apenas os threads de um único processo.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
explicit CriticalSection(  
   ULONG spincount = 0  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *spincount*  
 A contagem de rotação para o objeto de seção crítica. O valor padrão é 0.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre as seções críticas e spincounts, consulte o `InitializeCriticalSectionAndSpinCount` funcionar a **sincronização** seção da documentação de API do Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe CriticalSection](../windows/criticalsection-class.md)