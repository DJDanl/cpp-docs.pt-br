---
title: Namespace Microsoft::WRL::wrappers::HandleTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits
dev_langs:
- C++
helpviewer_keywords:
- HandleTraits namespace
ms.assetid: 2fb5c6d1-bfc2-4e09-91eb-31705064ffb3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b114d067249e78d7fb935e473cc3cc952c76fe02
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="microsoftwrlwrappershandletraits-namespace"></a>Namespace Microsoft::WRL::Wrappers::HandleTraits
Descreve as características dos tipos comuns de recursos com base no identificador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace Microsoft::WRL::Wrappers::HandleTraits;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="structures"></a>Estruturas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Estrutura CriticalSectionTraits](../windows/criticalsectiontraits-structure.md)|Especializada um `CriticalSection` objeto para dar suporte a uma seção crítica inválida ou uma função para liberar uma seção crítica.|  
|[Estrutura EventTraits](../windows/eventtraits-structure.md)|Define as características de um `Event` identificador de classe.|  
|[Estrutura FileHandleTraits](../windows/filehandletraits-structure.md)|Define as características de um identificador de arquivo.|  
|[Estrutura HANDLENullTraits](../windows/handlenulltraits-structure.md)|Define as características de um identificador não inicializado.|  
|[Estrutura HANDLETraits](../windows/handletraits-structure.md)|Define as características de um identificador.|  
|[Estrutura MutexTraits](../windows/mutextraits-structure.md)|Define as características do [Mutex](../windows/mutex-class1.md) classe.|  
|[Estrutura SemaphoreTraits](../windows/semaphoretraits-structure.md)|Define as características de um objeto de semáforo.|  
|[Estrutura SRWLockExclusiveTraits](../windows/srwlockexclusivetraits-structure.md)|Descreve características comuns do `SRWLock` classe no modo de bloqueio exclusivo.|  
|[Estrutura SRWLockSharedTraits](../windows/srwlocksharedtraits-structure.md)|Descreve características comuns do `SRWLock` classe no modo de bloqueio compartilhado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)