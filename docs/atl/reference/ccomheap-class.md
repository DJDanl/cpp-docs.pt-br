---
title: "Classe de CComHeap | Microsoft Docs"
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
  - "CComHeap"
  - "ATL.CComHeap"
  - "ATL::CComHeap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComHeap"
ms.assetid: c74183ce-98ae-46fb-b186-93ea4cf0222b
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComHeap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de alocação de memória COM.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CComHeap : public IAtlMemMgr  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComHeap::Allocate](../Topic/CComHeap::Allocate.md)|Chamar esse método para atribuir um bloco de memória.|  
|[CComHeap::Free](../Topic/CComHeap::Free.md)|Chamar este método para liberar um bloco de memória atribuído pelo gerenciador de memória.|  
|[CComHeap::GetSize](../Topic/CComHeap::GetSize.md)|Chamar esse método para obter o tamanho atribuído de um bloco de memória atribuído pelo gerenciador de memória.|  
|[CComHeap::Reallocate](../Topic/CComHeap::Reallocate.md)|Chamar esse método para realocar a memória alocada pelo gerenciador de memória.|  
  
## Comentários  
 `CComHeap` implementa funções de alocação de memória usando as funções de alocação COM, incluindo [CoTaskMemAlloc](http://msdn.microsoft.com/library/windows/desktop/ms692727), [CoTaskMemFree](http://msdn.microsoft.com/library/windows/desktop/ms680722), [IMalloc::GetSize](http://msdn.microsoft.com/library/windows/desktop/ms691226), e [CoTaskMemRealloc](http://msdn.microsoft.com/library/windows/desktop/ms687280).  A quantidade de memória máximo que pode ser atribuída é igual a **INT\_MAX** \(2147483647\) bytes.  
  
## Exemplo  
 Consulte o exemplo para [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
## Hierarquia de herança  
 `IAtlMemMgr`  
  
 `CComHeap`  
  
## Requisitos  
 **Cabeçalho:** ATLComMem.h  
  
## Consulte também  
 [exemplo de DynamicConsumer](../../top/visual-cpp-samples.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de CWin32Heap](../../atl/reference/cwin32heap-class.md)   
 [Classe de CLocalHeap](../../atl/reference/clocalheap-class.md)   
 [Classe de CGlobalHeap](../../atl/reference/cglobalheap-class.md)   
 [Classe de CCRTHeap](../../atl/reference/ccrtheap-class.md)   
 [Classe de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)