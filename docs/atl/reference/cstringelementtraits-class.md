---
title: "Classe de CStringElementTraits | Microsoft Docs"
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
  - "ATL.CStringElementTraits<T>"
  - "ATL::CStringElementTraits<T>"
  - "CStringElementTraits"
  - "ATL.CStringElementTraits"
  - "ATL::CStringElementTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CStringElementTraits"
ms.assetid: 74d7134b-099d-4455-bf91-3e68ccbf95bc
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CStringElementTraits
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece as funções estáticas usadas pelas classes de coleção que armazenam objetos de `CString` .  
  
## Sintaxe  
  
```  
  
      template<  
   typename T   
>  
class CStringElementTraits  
```  
  
#### Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStringElementTraits::INARGTYPE](../Topic/CStringElementTraits::INARGTYPE.md)|O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleção.|  
|[CStringElementTraits::OUTARGTYPE](../Topic/CStringElementTraits::OUTARGTYPE.md)|O tipo de dados a ser usado para recuperar elementos de objeto da classe de coleção.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStringElementTraits::CompareElements](../Topic/CStringElementTraits::CompareElements.md)|\(Static\) Chamar essa função para comparar dois elementos de cadeia de caracteres para igualdade.|  
|[CStringElementTraits::CompareElementsOrdered](../Topic/CStringElementTraits::CompareElementsOrdered.md)|\(Static\) Chamar essa função para comparar dois elementos de cadeia de caracteres.|  
|[CStringElementTraits::CopyElements](../Topic/CStringElementTraits::CopyElements.md)|\(Static\) Chamar essa função para copiar os elementos de `CString` armazenados em um objeto da classe de coleção.|  
|[CStringElementTraits::Hash](../Topic/CStringElementTraits::Hash.md)|\(Static\) Chamar essa função para calcular um valor de hash para o elemento dado de cadeia de caracteres.|  
|[CStringElementTraits::RelocateElements](../Topic/CStringElementTraits::RelocateElements.md)|\(Static\) Chamar essa função para realoque os elementos de `CString` armazenados em um objeto da classe de coleção.|  
  
## Comentários  
 Essa classe fornece funções estáticas para copiar, mover, e comparar cadeias de caracteres e para criar um valor de hash.  Essas funções são úteis quando usar uma classe de coleção para armazenar cadeia de caracteres com dados.  Use [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md) quando as comparações não diferencia maiúsculas de minúsculas são necessárias.  Use [CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md) quando os objetos de cadeia de caracteres devem ser tratados como referências.  
  
 Para obter mais informações, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Requisitos  
 **Cabeçalho:** cstringt.h  
  
## Consulte também  
 [Classe de CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)   
 [Classe de CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)