---
title: "Classe de CAutoPtrList | Microsoft Docs"
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
  - "ATL::CAutoPtrList"
  - "CAutoPtrList"
  - "ATL.CAutoPtrList"
  - "ATL::CAutoPtrList<E>"
  - "ATL.CAutoPtrList<E>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAutoPtrList"
ms.assetid: 11de4aca-28b0-4ff2-a74a-cb602312ffbd
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAutoPtrList
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece os métodos úteis quando construir uma lista de ponteiros inteligentes.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<  
typename E  
>  
class CAutoPtrList : public CAtlList<  
ATL::CAutoPtr< E>,  
CAutoPtrElementTraits< E>  
>  
```  
  
#### Parâmetros  
 `E`  
 O tipo ponteiro.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoPtrList::CAutoPtrList](../Topic/CAutoPtrList::CAutoPtrList.md)|o construtor.|  
  
## Comentários  
 Essa classe fornece um construtor e derivado de [CAtlList](../Topic/CAtlList%20Class.md) métodos e de [CAutoPtrElementTraits](../Topic/CAutoPtrElementTraits%20Class.md) para ajudar à criação de um objeto de lista que armazena ponteiros inteligentes.  A classe [CAutoPtrArray](../../atl/reference/cautoptrarray-class.md) fornece uma função semelhante para um objeto de matriz.  
  
 Para obter mais informações, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Hierarquia de herança  
 [CAtlList](../Topic/CAtlList%20Class.md)  
  
 `CAutoPtrList`  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Classe de CAtlList](../Topic/CAtlList%20Class.md)   
 [Classe de CAutoPtrElementTraits](../Topic/CAutoPtrElementTraits%20Class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)