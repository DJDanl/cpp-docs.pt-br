---
title: "Classe de CDefaultElementTraits | Microsoft Docs"
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
  - "ATL::CDefaultElementTraits<T>"
  - "ATL.CDefaultElementTraits"
  - "ATL::CDefaultElementTraits"
  - "ATL.CDefaultElementTraits<T>"
  - "CDefaultElementTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDefaultElementTraits"
ms.assetid: ac5ee610-7957-4b7c-92b6-38ff72e4118e
caps.latest.revision: 17
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDefaultElementTraits
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos padrão e funções para uma classe de coleção.  
  
## Sintaxe  
  
```  
  
      template<  
   typename T  
>  
class CDefaultElementTraits : public CElementTraitsBase< T >,  
   public CDefaultHashTraits< T >,  
   public CDefaultCompareTraits< T >  
```  
  
#### Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## Comentários  
 Essa classe fornece funções estáticas padrão e os métodos para mover, copiar, comparar, e os elementos picando armazenados em uma classe de objeto de coleção.  Essa classe derivada suas funções e métodos de [CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md), de [CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md), e de [CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md), e é utilizada por [CElementTraits](../../atl/reference/celementtraits-class.md), por [CPrimitiveElementTraits](../../atl/reference/cprimitiveelementtraits-class.md), e por [CHeapPtrElementTraits](../../atl/reference/cheapptrelementtraits-class.md).  
  
 Para obter mais informações, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)