---
title: "Classe de CCRTAllocator | Microsoft Docs"
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
  - "CCRTAllocator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CCRTAllocator"
ms.assetid: 3e1b8cb0-859a-41ab-8e93-6f0b5ceca49d
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CCRTAllocator
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para gerenciar a memória usando rotinas de memória de CRT.  
  
## Sintaxe  
  
```  
  
class ATL::CCRTAllocator  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCRTAllocator::Allocate](../Topic/CCRTAllocator::Allocate.md)|\(Static\) Chamar esse método para alocar memória.|  
|[CCRTAllocator::Free](../Topic/CCRTAllocator::Free.md)|\(Static\) Chamar este método para liberar memória.|  
|[CCRTAllocator::Reallocate](../Topic/CCRTAllocator::Reallocate.md)|\(Static\) Chamar esse método para realocar a memória.|  
  
## Comentários  
 Essa classe é usada por [CHeapPtr](../../atl/reference/cheapptr-class.md) para fornecer rotinas de alocação de memória de CRT.  As contrapartes classe, [CComAllocator](../../atl/reference/ccomallocator-class.md), fornecem os mesmos métodos usando rotinas COM.  
  
## Requisitos  
 **Cabeçalho:** atlcore.h  
  
## Consulte também  
 [Classe de CHeapPtr](../../atl/reference/cheapptr-class.md)   
 [Classe de CComAllocator](../../atl/reference/ccomallocator-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)