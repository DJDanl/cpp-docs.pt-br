---
title: "Classe de CStringRefElementTraits | Microsoft Docs"
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
  - "CStringRefElementTraits"
  - "ATL.CStringRefElementTraits"
  - "ATL::CStringRefElementTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CStringRefElementTraits"
ms.assetid: cc15062d-5627-46cc-ac2b-1744afdc2dbd
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CStringRefElementTraits
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece as funções estáticas relacionadas às cadeias de caracteres armazenadas em objetos de classe de coleção.  Os objetos de cadeia de caracteres são tratados como referências.  
  
## Sintaxe  
  
```  
  
      template<   
   typename T  
>  
class CStringRefElementTraits : public CElementTraitsBase< T >  
```  
  
#### Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStringRefElementTraits::CompareElements](../Topic/CStringRefElementTraits::CompareElements.md)|Chamar essa função estática para comparar dois elementos de cadeia de caracteres para igualdade.|  
|[CStringRefElementTraits::CompareElementsOrdered](../Topic/CStringRefElementTraits::CompareElementsOrdered.md)|Chamar essa função estática para comparar dois elementos de cadeia de caracteres.|  
|[CStringRefElementTraits::Hash](../Topic/CStringRefElementTraits::Hash.md)|Chamar essa função estática para calcular um valor de hash para o elemento dado de cadeia de caracteres.|  
  
## Comentários  
 Essa classe fornece funções estáticas para comparar cadeias de caracteres e para criar um valor de hash.  Essas funções são úteis quando usar uma classe de coleção para armazenar cadeia de caracteres com dados.  A o contrário de [CStringElementTraits](../../atl/reference/cstringelementtraits-class.md) e de [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md), `CStringRefElementTraits` faz com que os argumentos de `CString` a serem passados como referências de **const CString&** .  
  
 Para obter mais informações, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Hierarquia de herança  
 [CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)  
  
 `CStringRefElementTraits`  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Classe de CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)