---
title: "Classe de IAtlMemMgr | Microsoft Docs"
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
  - "IAtlMemMgr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de IAtlMemMgr"
  - "memória, gerenciando"
  - "memória, gerenciador de memória"
ms.assetid: 18b2c569-25fe-4464-bdb6-3b1abef7154a
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IAtlMemMgr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa a interface para um gerenciador de memória.  
  
## Sintaxe  
  
```  
  
__interface __declspec( uuid( "654F7EF5-CFDF-4df9-A450-6C6A13C622C0" )) IAtlMemMgr  
  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[Atribua](../Topic/IAtlMemMgr::Allocate.md)|Chamar esse método para atribuir um bloco de memória.|  
|[Livre](../Topic/IAtlMemMgr::Free.md)|Chamar este método para liberar um bloco de memória.|  
|[GetSize](../Topic/IAtlMemMgr::GetSize.md)|Chamar esse método para recuperar o tamanho de um bloco de memória atribuído.|  
|[Realocar](../Topic/IAtlMemMgr::Reallocate.md)|Chamar esse método para realocar um bloco de memória.|  
  
## Comentários  
 Essa interface é implementada por [CComHeap](../../atl/reference/ccomheap-class.md), por [CCRTHeap](../../atl/reference/ccrtheap-class.md), por [CLocalHeap](../../atl/reference/clocalheap-class.md), por [CGlobalHeap](../../atl/reference/cglobalheap-class.md), ou por [CWin32Heap](../../atl/reference/cwin32heap-class.md).  
  
> [!NOTE]
>  O local e as funções da heap globais são mais lentas que outras funções de gerenciamento de memória, e não fornecem tantos recursos.  Portanto, os novos aplicativos devem usar [funções da heap](http://msdn.microsoft.com/library/windows/desktop/aa366711).  Esses estão disponíveis na classe de [CWin32Heap](../../atl/reference/cwin32heap-class.md) .  
  
## Exemplo  
 [!CODE [NVC_ATL_Utilities#94](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#94)]  
  
## Requisitos  
 **Cabeçalho:** atlmem.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)