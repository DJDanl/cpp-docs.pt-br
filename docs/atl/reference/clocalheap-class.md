---
title: "Classe de CLocalHeap | Microsoft Docs"
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
  - "ATL.CLocalHeap"
  - "ATL::CLocalHeap"
  - "CLocalHeap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CLocalHeap"
ms.assetid: 1ffa87a5-5fc8-4f8d-8809-58e87e963bd2
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CLocalHeap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções local do heap do Win32.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CLocalHeap : public IAtlMemMgr  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CLocalHeap::Allocate](../Topic/CLocalHeap::Allocate.md)|Chamar esse método para atribuir um bloco de memória.|  
|[CLocalHeap::Free](../Topic/CLocalHeap::Free.md)|Chamar este método para liberar um bloco de memória atribuído pelo gerenciador de memória.|  
|[CLocalHeap::GetSize](../Topic/CLocalHeap::GetSize.md)|Chamar esse método para obter o tamanho atribuído de um bloco de memória atribuído pelo gerenciador de memória.|  
|[CLocalHeap::Reallocate](../Topic/CLocalHeap::Reallocate.md)|Chamar esse método para realocar a memória alocada pelo gerenciador de memória.|  
  
## Comentários  
 Funções de alocação de memória implements de`CLocalHeap` que usam o heap local do Win32 funcionam.  
  
> [!NOTE]
>  As funções local da heap são mais lentas do que outras funções de gerenciamento de memória e não fornecem tantos recursos.  Portanto, os novos aplicativos devem usar [funções da heap](http://msdn.microsoft.com/library/windows/desktop/aa366711).  Esses estão disponíveis na classe de [CWin32Heap](../../atl/reference/cwin32heap-class.md) .  
  
## Exemplo  
 Consulte o exemplo para [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
## Hierarquia de herança  
 `IAtlMemMgr`  
  
 `CLocalHeap`  
  
## Requisitos  
 **Cabeçalho:** atlmem.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de CComHeap](../../atl/reference/ccomheap-class.md)   
 [Classe de CWin32Heap](../../atl/reference/cwin32heap-class.md)   
 [Classe de CGlobalHeap](../../atl/reference/cglobalheap-class.md)   
 [Classe de CCRTHeap](../../atl/reference/ccrtheap-class.md)   
 [Classe de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)