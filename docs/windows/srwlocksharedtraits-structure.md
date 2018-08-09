---
title: Estrutura SRWLockSharedTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockSharedTraits
dev_langs:
- C++
helpviewer_keywords:
- SRWLockSharedTraits structure
ms.assetid: 709cb51e-d70c-40b6-bdb4-d8eacf3af495
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: db9a16671be21b2df7a4ce4f9d87a8b66e097e33
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40020142"
---
# <a name="srwlocksharedtraits-structure"></a>Estrutura SRWLockSharedTraits
Descreve características comuns do `SRWLock` classe no modo de bloqueio compartilhado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
struct SRWLockSharedTraits;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`Type`|Sinônimo de um ponteiro para o [SRWLOCK](../windows/srwlock-class.md) classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método SRWLockSharedTraits::GetInvalidValue](../windows/srwlocksharedtraits-getinvalidvalue-method.md)|Recupera uma **SRWLockSharedTraits** objeto sempre é inválido.|  
|[Método SRWLockSharedTraits::Unlock](../windows/srwlocksharedtraits-unlock-method.md)|Libera o controle exclusivo do especificado `SRWLock` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `SRWLockSharedTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers::HandleTraits](../windows/microsoft-wrl-wrappers-handletraits-namespace.md)