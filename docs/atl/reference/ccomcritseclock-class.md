---
title: "Classe de CComCritSecLock | Microsoft Docs"
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
  - "ATL::CComCritSecLock"
  - "ATL.CComCritSecLock<TLock>"
  - "ATL::CComCritSecLock<TLock>"
  - "ATL.CComCritSecLock"
  - "CComCritSecLock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComCritSecLock"
ms.assetid: 223152a1-86c3-4ef9-89a7-f455fe791b0e
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComCritSecLock
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para bloquear e desbloquear um objeto de seção crítica.  
  
## Sintaxe  
  
```  
  
      template<  
   class TLock  
> class CComCritSecLock  
```  
  
#### Parâmetros  
 *TLock*  
 o objeto a ser bloqueado e desbloqueado.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComCritSecLock::CComCritSecLock](../Topic/CComCritSecLock::CComCritSecLock.md)|o construtor.|  
|[CComCritSecLock::~CComCritSecLock](../Topic/CComCritSecLock::~CComCritSecLock.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComCritSecLock::Lock](../Topic/CComCritSecLock::Lock.md)|Chamar esse método para bloquear o objeto da seção crítica.|  
|[CComCritSecLock::Unlock](../Topic/CComCritSecLock::Unlock.md)|Chamar esse método para desbloquear o objeto da seção crítica.|  
  
## Comentários  
 Use esta classe para bloquear e desbloquear objetos de uma maneira mais segura do que com [classe de CComCriticalSection](../Topic/CComCriticalSection%20Class.md) ou [classe de CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md).  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Classe de CComCriticalSection](../Topic/CComCriticalSection%20Class.md)   
 [Classe de CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md)