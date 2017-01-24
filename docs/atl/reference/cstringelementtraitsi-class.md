---
title: "Classe de CStringElementTraitsI | Microsoft Docs"
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
  - "ATL::CStringElementTraitsI"
  - "CStringElementTraitsI"
  - "ATL.CStringElementTraitsI"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CStringElementTraitsI"
ms.assetid: c23f92b1-91e5-400f-96ed-258b02622b7a
caps.latest.revision: 18
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CStringElementTraitsI
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece as funções estáticas relacionadas às cadeias de caracteres armazenadas em objetos de classe de coleção.  É semelhante a [CStringElementTraits](../../atl/reference/cstringelementtraits-class.md), mas realiza comparações não diferencia maiúsculas de minúsculas.  
  
## Sintaxe  
  
```  
  
      template<  
   typename T,  
   class CharTraits = CDefaultCharTraits< T::XCHAR >  
>  
class CStringElementTraitsI : public CElementTraitsBase< T >  
```  
  
#### Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStringElementTraitsI::INARGTYPE](../Topic/CStringElementTraitsI::INARGTYPE.md)|O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleção.|  
|[CStringElementTraitsI::OUTARGTYPE](../Topic/CStringElementTraitsI::OUTARGTYPE.md)|O tipo de dados a ser usado para recuperar elementos de objeto da classe de coleção.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStringElementTraitsI::CompareElements](../Topic/CStringElementTraitsI::CompareElements.md)|Chamar essa função estática para comparar dois elementos de cadeia de caracteres para igualdade, ignorando diferenças no caso de.|  
|[CStringElementTraitsI::CompareElementsOrdered](../Topic/CStringElementTraitsI::CompareElementsOrdered.md)|Chamar essa função estática para comparar dois elementos de cadeia de caracteres, ignorando diferenças no caso de.|  
|[CStringElementTraitsI::Hash](../Topic/CStringElementTraitsI::Hash.md)|Chamar essa função estática para calcular um valor de hash para o elemento dado de cadeia de caracteres.|  
  
## Comentários  
 Essa classe fornece funções estáticas para comparar cadeias de caracteres e para criar um valor de hash.  Essas funções são úteis quando usar uma classe de coleção para armazenar cadeia de caracteres com dados.  Use [CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md) quando os objetos de cadeia de caracteres são ser tratado como com referências.  
  
 Para obter mais informações, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Hierarquia de herança  
 [CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)  
  
 `CStringElementTraitsI`  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Classe de CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de CStringElementTraits](../../atl/reference/cstringelementtraits-class.md)