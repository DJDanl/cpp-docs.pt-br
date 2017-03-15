---
title: "Namespace Microsoft::WRL::Wrappers::HandleTraits | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "corewrappers/Microsoft::WRL::Wrappers::HandleTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Namespace HandleTraits"
ms.assetid: 2fb5c6d1-bfc2-4e09-91eb-31705064ffb3
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Namespace Microsoft::WRL::Wrappers::HandleTraits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve as características dos tipos comuns de recursos com base no identificador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace Microsoft::WRL::Wrappers::HandleTraits;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="structures"></a>Estruturas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Estrutura CriticalSectionTraits](../windows/criticalsectiontraits-structure.md)|É especialista uma `CriticalSection` objeto oferecer suporte a uma seção crítica inválida ou uma função para liberar uma seção crítica.|  
|[Estrutura EventTraits](../windows/eventtraits-structure.md)|Define as características de um `Event` identificador de classe.|  
|[Estrutura FileHandleTraits](../windows/filehandletraits-structure.md)|Define as características de um identificador de arquivo.|  
|[Estrutura HANDLENullTraits](../windows/handlenulltraits-structure.md)|Define as características de um identificador não inicializado.|  
|[Estrutura HANDLETraits](../windows/handletraits-structure.md)|Define as características de um identificador.|  
|[Estrutura MutexTraits](../windows/mutextraits-structure.md)|Define as características do [Mutex](Mutex%20Class1.md) classe.|  
|[Estrutura SemaphoreTraits](../Topic/SemaphoreTraits%20Structure.md)|Define as características de um objeto de semáforo.|  
|[Estrutura SRWLockExclusiveTraits](../windows/srwlockexclusivetraits-structure.md)|Descreve características comuns da `SRWLock` classe no modo de bloqueio exclusivo.|  
|[Estrutura SRWLockSharedTraits](../windows/srwlocksharedtraits-structure.md)|Descreve características comuns da `SRWLock` classe no modo de bloqueio compartilhado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::wrappers](../Topic/Microsoft::WRL::Wrappers%20Namespace.md)