---
title: Estrutura SemaphoreTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SemaphoreTraits
dev_langs:
- C++
helpviewer_keywords:
- SemaphoreTraits structure
ms.assetid: eddb8576-d063-409b-9201-cc87ca5d111e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1c5bdb20a765b56fd90a46389eba2a869890e4fd
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33892599"
---
# <a name="semaphoretraits-structure"></a>Estrutura SemaphoreTraits
Define as características de um objeto de semáforo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct SemaphoreTraits : HANDLENullTraits;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método SemaphoreTraits::Unlock](../windows/semaphoretraits-unlock-method.md)|Controle de versões de um recurso compartilhado.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `HANDLENullTraits`  
  
 `SemaphoreTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers::HandleTraits](../windows/microsoft-wrl-wrappers-handletraits-namespace.md)