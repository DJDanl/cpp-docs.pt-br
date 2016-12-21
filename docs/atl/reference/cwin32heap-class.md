---
title: "Classe de CWin32Heap | Microsoft Docs"
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
  - "ATL::CWin32Heap"
  - "ATL.CWin32Heap"
  - "CWin32Heap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CWin32Heap"
ms.assetid: 69176022-ed98-4e3b-96d8-116b0c58ac95
caps.latest.revision: 19
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWin32Heap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de alocação da heap Win32.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CWin32Heap : public IAtlMemMgr  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWin32Heap::CWin32Heap](../Topic/CWin32Heap::CWin32Heap.md)|o construtor.|  
|[CWin32Heap::~CWin32Heap](../Topic/CWin32Heap::~CWin32Heap.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWin32Heap::Allocate](../Topic/CWin32Heap::Allocate.md)|Atribui um bloco de memória do objeto da heap.|  
|[CWin32Heap::Attach](../Topic/CWin32Heap::Attach.md)|Anexa o objeto da heap um heap existente.|  
|[CWin32Heap::Detach](../Topic/CWin32Heap::Detach.md)|Dispara o objeto do heap de um heap existente.|  
|[CWin32Heap::Free](../Topic/CWin32Heap::Free.md)|Libera a memória alocada anteriormente da heap.|  
|[CWin32Heap::GetSize](../Topic/CWin32Heap::GetSize.md)|Retorna o tamanho de um bloco de memória do objeto atribuído o heap.|  
|[CWin32Heap::Reallocate](../Topic/CWin32Heap::Reallocate.md)|Realoca um bloco de memória do objeto da heap.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWin32Heap::m\_bOwnHeap](../Topic/CWin32Heap::m_bOwnHeap.md)|Um sinalizador usado para determinar a propriedade atual da alça de heap.|  
|[CWin32Heap::m\_hHeap](../Topic/CWin32Heap::m_hHeap.md)|Identificador para o objeto da heap.|  
  
## Comentários  
 Os métodos de alocação de memória implements de`CWin32Heap` que usam funções Win32 o heap de alocação, incluindo [HeapAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366597) e [HeapFree](http://msdn.microsoft.com/library/windows/desktop/aa366701).  Diferentemente de outras classes de heap, `CWin32Heap` requer um identificador válido da heap ser fornecido antes que a memória seja atribuída: outras classes padrão para usar o heap do processo.  O identificador pode ser fornecida para o construtor ou método de [CWin32Heap::Attach](../Topic/CWin32Heap::Attach.md) .  Consulte o método de [CWin32Heap::CWin32Heap](../Topic/CWin32Heap::CWin32Heap.md) para obter mais detalhes.  
  
## Exemplo  
 Consulte o exemplo para [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
## Hierarquia de herança  
 `IAtlMemMgr`  
  
 `CWin32Heap`  
  
## Requisitos  
 **Cabeçalho:** atlmem.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)   
 [Classe de CLocalHeap](../../atl/reference/clocalheap-class.md)   
 [Classe de CGlobalHeap](../../atl/reference/cglobalheap-class.md)   
 [Classe de CCRTHeap](../../atl/reference/ccrtheap-class.md)   
 [Classe de CComHeap](../../atl/reference/ccomheap-class.md)