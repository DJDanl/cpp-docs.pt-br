---
title: Estrutura CriticalSectionTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::CriticalSectionTraits
dev_langs:
- C++
helpviewer_keywords:
- CriticalSectionTraits structure
ms.assetid: c515a1b5-4eb0-40bc-9035-c4d9352c9de7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8b10d130190308520771e37e97d34238f75670ad
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39466677"
---
# <a name="criticalsectiontraits-structure"></a>Estrutura CriticalSectionTraits
É o especialista de um objeto de seção crítica para dar suporte a uma seção crítica inválida ou uma função para liberar uma seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CriticalSectionTraits;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`Type`|Um **typedef** que define um ponteiro para uma seção crítica. `Type` é definido como `typedef CRITICAL_SECTION* Type;`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método CriticalSectionTraits::GetInvalidValue](../windows/criticalsectiontraits-getinvalidvalue-method.md)|É especialista um `CriticalSection` modelo para que o modelo sempre é inválido.|  
|[Método CriticalSectionTraits::Unlock](../windows/criticalsectiontraits-unlock-method.md)|É especialista um `CriticalSection` modelo para que ele dá suporte a liberar propriedade do objeto especificado de seção crítica.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CriticalSectionTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers::HandleTraits](../windows/microsoft-wrl-wrappers-handletraits-namespace.md)