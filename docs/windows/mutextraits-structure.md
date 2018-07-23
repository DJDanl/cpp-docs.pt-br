---
title: Estrutura MutexTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::MutexTraits
dev_langs:
- C++
helpviewer_keywords:
- MutexTraits structure
ms.assetid: 6582df80-b9ba-4892-948f-d572a3b23d54
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0406ec7938a623be7b16e0535e9d2c0c769f8392
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33874584"
---
# <a name="mutextraits-structure"></a>Estrutura MutexTraits
Define as características do [Mutex](../windows/mutex-class1.md) classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct MutexTraits : HANDLENullTraits;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método MutexTraits::Unlock](../windows/mutextraits-unlock-method.md)|Libera o controle exclusivo de um recurso compartilhado.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `HANDLENullTraits`  
  
 `MutexTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers::HandleTraits](../windows/microsoft-wrl-wrappers-handletraits-namespace.md)