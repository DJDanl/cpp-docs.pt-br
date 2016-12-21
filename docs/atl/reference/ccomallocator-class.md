---
title: "Classe de CComAllocator | Microsoft Docs"
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
  - "ATL.CComAllocator"
  - "ATL::CComAllocator"
  - "CComAllocator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComAllocator"
ms.assetid: 0cd706fd-0c7b-42d3-9054-febe2966fc8e
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComAllocator
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para gerenciar a memória usando rotinas de memória COM.  
  
## Sintaxe  
  
```  
  
class CComAllocator  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComAllocator::Allocate](../Topic/CComAllocator::Allocate.md)|Chamar este método estático para alocar memória.|  
|[CComAllocator::Free](../Topic/CComAllocator::Free.md)|Chamar este método estático para liberar a memória alocada.|  
|[CComAllocator::Reallocate](../Topic/CComAllocator::Reallocate.md)|Chamar este método estático para realocar a memória.|  
  
## Comentários  
 Essa classe é usada por [CComHeapPtr](../../atl/reference/ccomheapptr-class.md) para fornecer rotinas de alocação de memória COM.  As contrapartes classe, [CCRTAllocator](../../atl/reference/ccrtallocator-class.md), fornecem os mesmos métodos usando rotinas de CRT.  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Classe de CComHeapPtr](../../atl/reference/ccomheapptr-class.md)   
 [Classe de CCRTAllocator](../../atl/reference/ccrtallocator-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)