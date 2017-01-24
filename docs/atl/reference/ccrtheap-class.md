---
title: "Classe de CCRTHeap | Microsoft Docs"
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
  - "ATL::CCRTHeap"
  - "ATL.CCRTHeap"
  - "CCRTHeap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CCRTHeap"
ms.assetid: 321bd6c5-1856-4ff7-8590-95044a1209f7
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CCRTHeap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções do heap de CRT.  
  
## Sintaxe  
  
```  
  
class CCRTHeap : public IAtlMemMgr  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCRTHeap::Allocate](../Topic/CCRTHeap::Allocate.md)|Chamar esse método para atribuir um bloco de memória.|  
|[CCRTHeap::Free](../Topic/CCRTHeap::Free.md)|Chamar este método para liberar um bloco de memória atribuído pelo gerenciador de memória.|  
|[CCRTHeap::GetSize](../Topic/CCRTHeap::GetSize.md)|Chamar esse método para obter o tamanho atribuído de um bloco de memória atribuído pelo gerenciador de memória.|  
|[CCRTHeap::Reallocate](../Topic/CCRTHeap::Reallocate.md)|Chamar esse método para realocar a memória alocada pelo gerenciador de memória.|  
  
## Comentários  
 Funções de alocação de memória implements de`CCRTHeap` que usam o CRT heap, incluindo as funções [malloc](../../c-runtime-library/reference/malloc.md), [livre](../../c-runtime-library/reference/free.md), [realloc](../../c-runtime-library/reference/realloc.md), e [\_msize](../Topic/_msize.md).  
  
## Exemplo  
 Consulte o exemplo para [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
## Hierarquia de herança  
 `IAtlMemMgr`  
  
 `CCRTHeap`  
  
## Requisitos  
 **Cabeçalho:** atlmem.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de CComHeap](../../atl/reference/ccomheap-class.md)   
 [Classe de CWin32Heap](../../atl/reference/cwin32heap-class.md)   
 [Classe de CLocalHeap](../../atl/reference/clocalheap-class.md)   
 [Classe de CGlobalHeap](../../atl/reference/cglobalheap-class.md)   
 [Classe de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)