---
title: "Classe de CComFakeCriticalSection | Microsoft Docs"
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
  - "ATL.CComFakeCriticalSection"
  - "CComFakeCriticalSection"
  - "ATL::CComFakeCriticalSection"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComFakeCriticalSection"
ms.assetid: a4811b97-96bb-493b-ab9f-62822aeddb10
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComFakeCriticalSection
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece os mesmos métodos que [CComCriticalSection](../Topic/CComCriticalSection%20Class.md) mas não fornece uma seção crítica.  
  
## Sintaxe  
  
```  
  
class CComFakeCriticalSection  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComFakeCriticalSection::Init](../Topic/CComFakeCriticalSection::Init.md)|Não fará nada pois não há nenhuma seção crítica.|  
|[CComFakeCriticalSection::Lock](../Topic/CComFakeCriticalSection::Lock.md)|Não fará nada pois não há nenhuma seção crítica.|  
|[CComFakeCriticalSection::Term](../Topic/CComFakeCriticalSection::Term.md)|Não fará nada pois não há nenhuma seção crítica.|  
|[CComFakeCriticalSection::Unlock](../Topic/CComFakeCriticalSection::Unlock.md)|Não fará nada pois não há nenhuma seção crítica.|  
  
## Comentários  
 `CComFakeCriticalSection` espelha os métodos localizados em [CComCriticalSection](../Topic/CComCriticalSection%20Class.md).  Em o entanto, `CComFakeCriticalSection` não fornece uma seção crítica; portanto, seus métodos não fazem nada.  
  
 Normalmente, você usa `CComFakeCriticalSection` com um nome de `typedef` , `AutoCriticalSection` ou `CriticalSection`.  A o usar [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) , ou [CComMultiThreadModelNoCS](../Topic/CComMultiThreadModelNoCS%20Class.md)referência ambos esses nomes `CComFakeCriticalSection`de `typedef` .  Ao usar [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md), referenciam [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md) e `CComCriticalSection`, respectivamente.  
  
## Requisitos  
 **Cabeçalho:** atlcore.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)