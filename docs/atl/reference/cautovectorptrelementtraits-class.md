---
title: "Classe de CAutoVectorPtrElementTraits | Microsoft Docs"
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
  - "ATL::CAutoVectorPtrElementTraits<T>"
  - "ATL.CAutoVectorPtrElementTraits"
  - "ATL.CAutoVectorPtrElementTraits<T>"
  - "ATL::CAutoVectorPtrElementTraits"
  - "CAutoVectorPtrElementTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAutoVectorPtrElementTraits"
ms.assetid: 16b81a56-55fb-46ca-b376-66a1884231a6
caps.latest.revision: 19
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAutoVectorPtrElementTraits
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos estáticos, funções, e typedefs úteis para criar coleções de ponteiros inteligentes que usam o vetor novo e os operadores de exclusão.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<  
typename T  
>  
class CAutoVectorPtrElementTraits : public CDefaultElementTraits<  
ATL::CAutoVectorPtr< T>  
>  
```  
  
#### Parâmetros  
 `T`  
 O tipo ponteiro.  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoVectorPtrElementTraits::INARGTYPE](../Topic/CAutoVectorPtrElementTraits::INARGTYPE.md)|O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleção.|  
|[CAutoVectorPtrElementTraits::OUTARGTYPE](../Topic/CAutoVectorPtrElementTraits::OUTARGTYPE.md)|O tipo de dados a ser usado para recuperar elementos de objeto da classe de coleção.|  
  
## Comentários  
 Essa classe fornece métodos estáticos, funções, e typedefs para ajudar à criação de objetos de classe de coleção que contêm ponteiros inteligentes.  A o contrário de [CAutoPtrElementTraits](../Topic/CAutoPtrElementTraits%20Class.md), essa classe usa o vetor novo os operadores e delete.  
  
## Hierarquia de herança  
 [CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)  
  
 [CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md)  
  
 [CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)  
  
 [CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)  
  
 `CAutoVectorPtrElementTraits`  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Classe de CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)   
 [Classe de CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)