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
ms.openlocfilehash: d86c80d169cb6d9794f163290c30bf1b2563588b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="criticalsectioncriticalsection-constructor"></a>Construtor CriticalSection::CriticalSection
Inicializa um objeto de sincronização que é semelhante a um objeto mutex, mas pode ser usado por apenas os segmentos de um único processo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
explicit CriticalSection(  
   ULONG spincount = 0  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `spincount`  
 A contagem de rotação para o objeto de seção crítica. O valor padrão é 0.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre seções críticas e spincounts, consulte o **InitializeCriticalSectionAndSpinCount** função na seção de sincronização da documentação do API do Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe CriticalSection](../windows/criticalsection-class.md)
