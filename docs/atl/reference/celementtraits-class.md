---
title: "Classe de CElementTraits | Microsoft Docs"
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
  - "ATL.CElementTraits<T>"
  - "ATL::CElementTraits"
  - "ATL.CElementTraits"
  - "ATL::CElementTraits<T>"
  - "CElementTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CElementTraits"
ms.assetid: 496528e5-7f80-4b45-be0c-6f646feb43c5
caps.latest.revision: 17
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CElementTraits
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é usada por classes de coleção para fornecer métodos e funções para mover, copiar, comparação, e operações picando.  
  
## Sintaxe  
  
```  
  
      template<  
   typename T  
>  
class CElementTraits : public CDefaultElementTraits< T >  
```  
  
#### Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## Comentários  
 Essa classe fornece funções estáticas padrão e os métodos para mover, copiar, comparar, e os elementos picando armazenados em uma classe de objeto de coleção.  `CElementTraits` é especificado como o provedor padrão de essas operações as classes [CAtlArray](../../atl/reference/catlarray-class.md), [CAtlList](../Topic/CAtlList%20Class.md), [CRBMap](../../atl/reference/crbmap-class.md), [CRBMultiMap](../../atl/reference/crbmultimap-class.md), e [CRBTree](../../atl/reference/crbtree-class.md)de coleção.  
  
 As implementações padrão bastarão para tipos de dados simples, mas se as classes de coleção são usadas para armazenar os objetos mais complexos, funções e métodos devem ser substituídos pelas implementações fornecida pelo usuário.  
  
 Para obter mais informações, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Classe de CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)