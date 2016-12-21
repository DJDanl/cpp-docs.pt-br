---
title: "Classe de CHeapPtrList | Microsoft Docs"
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
  - "ATL::CHeapPtrList"
  - "CHeapPtrList"
  - "ATL.CHeapPtrList"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CHeapPtrList"
ms.assetid: cc70e585-362a-4007-81db-c705eb181226
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CHeapPtrList
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece os métodos úteis quando construir uma lista de ponteiros da heap.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<  
typename E,  
class Allocator = ATL::CCRTAllocator  
>  
class CHeapPtrList : public CAtlList<  
ATL::CHeapPtr< E, Allocator>,  
CHeapPtrElementTraits< E, Allocator>  
>  
```  
  
#### Parâmetros  
 `E`  
 O tipo de objeto para ser armazenado na classe de coleção.  
  
 `Allocator`  
 A classe de alocação de memória para usar.  O padrão é [CCRTAllocator](../../atl/reference/ccrtallocator-class.md).  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHeapPtrList::CHeapPtrList](../Topic/CHeapPtrList::CHeapPtrList.md)|o construtor.|  
  
## Comentários  
 Essa classe fornece um construtor e derivado de [CAtlList](../Topic/CAtlList%20Class.md) métodos e de [CHeapPtrElementTraits](../../atl/reference/cheapptrelementtraits-class.md) para ajudar à criação de um objeto da classe de coleção que armazena ponteiros da heap.  
  
## Hierarquia de herança  
 [CAtlList](../Topic/CAtlList%20Class.md)  
  
 `CHeapPtrList`  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Classe de CAtlList](../Topic/CAtlList%20Class.md)   
 [Classe de CHeapPtr](../../atl/reference/cheapptr-class.md)   
 [Classe de CHeapPtrElementTraits](../../atl/reference/cheapptrelementtraits-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)