---
title: "Classe de CGlobalHeap | Microsoft Docs"
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
  - "ATL.CGlobalHeap"
  - "ATL::CGlobalHeap"
  - "CGlobalHeap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CGlobalHeap"
ms.assetid: e348d838-3aa7-4bee-a1b3-cd000c99f834
caps.latest.revision: 19
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CGlobalHeap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções globais do heap do Win32.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CGlobalHeap : public IAtlMemMgr  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CGlobalHeap::Allocate](../Topic/CGlobalHeap::Allocate.md)|Chamar esse método para atribuir um bloco de memória.|  
|[CGlobalHeap::Free](../Topic/CGlobalHeap::Free.md)|Chamar este método para liberar um bloco de memória atribuído pelo gerenciador de memória.|  
|[CGlobalHeap::GetSize](../Topic/CGlobalHeap::GetSize.md)|Chamar esse método para obter o tamanho atribuído de um bloco de memória atribuído pelo gerenciador de memória.|  
|[CGlobalHeap::Reallocate](../Topic/CGlobalHeap::Reallocate.md)|Chamar esse método para realocar a memória alocada pelo gerenciador de memória.|  
  
## Comentários  
 `CGlobalHeap` implementa funções de alocação de memória usando as funções globais do heap do Win32.  
  
> [!NOTE]
>  As funções da heap globais são mais lentas do que outras funções de gerenciamento de memória e não fornecem tantos recursos.  Portanto, os novos aplicativos devem usar [funções da heap](http://msdn.microsoft.com/library/windows/desktop/aa366711).  Esses estão disponíveis na classe de [CWin32Heap](../../atl/reference/cwin32heap-class.md) .  As funções globais são usadas por ainda DDE as funções da área de transferência.  
  
## Exemplo  
 Consulte o exemplo para [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
## Hierarquia de herança  
 `IAtlMemMgr`  
  
 `CGlobalHeap`  
  
## Requisitos  
 **Cabeçalho:** atlmem.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de CComHeap](../../atl/reference/ccomheap-class.md)   
 [Classe de CWin32Heap](../../atl/reference/cwin32heap-class.md)   
 [Classe de CLocalHeap](../../atl/reference/clocalheap-class.md)   
 [Classe de CCRTHeap](../../atl/reference/ccrtheap-class.md)   
 [Classe de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)